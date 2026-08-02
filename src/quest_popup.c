#include "global.h"
#include "bg.h"
#include "event_data.h"
#include "gpu_regs.h"
#include "main.h"
#include "map_name_popup.h"
#include "menu.h"
#include "quests.h"
#include "quest_popup.h"
#include "script.h"
#include "field_message_box.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "text.h"
#include "window.h"
#include "constants/characters.h"
#include "constants/songs.h"

// An achievement-style banner that drops down from the top of the overworld and
// announces "<icon> Quest Completed!". It reuses the actual Gen-5 map-name pop-up
// frame (see LoadGen5PopupFrameToWindow), rendered taller so the quest icon and
// text sit inside it cleanly. The text/frame live in a BG0 window scrolled on
// with BG0VOFS; the icon is a sprite whose Y is re-synced to the slide.
//
// Every quest routes through QuestMenu_MarkQuestFinished, which queues a banner
// here. Requests are queued rather than dropped so several quests finishing at
// once (e.g. the condition checker catching up) each get announced in turn.

#define QUEST_POPUP_BG            0
#define QUEST_POPUP_LEFT          0
#define QUEST_POPUP_TOP           0    // flush to the top edge, covering the top of the screen
#define QUEST_POPUP_WIDTH         30   // full-width bar, matches the Gen-5 frame
#define QUEST_POPUP_HEIGHT        5    // 40px tall -> fits the 32px icon with padding
#define QUEST_POPUP_PAL           14
#define QUEST_POPUP_BASE_BLOCK    0x107 // shared with the map-name pop-up; the two never run at once

#define QUEST_POPUP_ONSCREEN_Y    0
#define QUEST_POPUP_OFFSCREEN_Y   ((QUEST_POPUP_TOP + QUEST_POPUP_HEIGHT + 1) * 8) // fully above the screen
#define QUEST_POPUP_SLIDE_SPEED   2
#define QUEST_POPUP_HOLD_TIME     140

// Icon/text placement. The frame's slanted edge is on the bottom-right, so the
// icon and text sit on the left where the bar is solid fill.
#define QUEST_POPUP_ICON_X        26
#define QUEST_POPUP_ICON_Y        (QUEST_POPUP_TOP * 8 + 18)
#define QUEST_POPUP_TEXT_X        48
#define QUEST_POPUP_TEXT_Y        12

#define QUEST_POPUP_QUEUE_SIZE    8

enum {
    QSTATE_NEXT,
    QSTATE_WAIT_FIELD,
    QSTATE_SLIDE_IN,
    QSTATE_HOLD,
    QSTATE_SLIDE_OUT,
};

#define tState    data[0]
#define tYOffset  data[1]
#define tTimer    data[2]

static EWRAM_DATA u8 sQuestPopupWindowId = 0;
static EWRAM_DATA u8 sQuestPopupIconSpriteId = 0;
static EWRAM_DATA u16 sQuestPopupQuestId = 0;
static EWRAM_DATA u16 sQuestPopupQueue[QUEST_POPUP_QUEUE_SIZE] = {0};
static EWRAM_DATA u8 sQuestPopupQueueHead = 0;
static EWRAM_DATA u8 sQuestPopupQueueCount = 0;

static void Task_QuestPopup(u8 taskId);
static void QuestPopup_Draw(void);
static void QuestPopup_Teardown(void);

static const u8 sText_QuestCompleted[] = _("Quest Completed!");

static const struct WindowTemplate sQuestPopupWindowTemplate =
{
    .bg = QUEST_POPUP_BG,
    .tilemapLeft = QUEST_POPUP_LEFT,
    .tilemapTop = QUEST_POPUP_TOP,
    .width = QUEST_POPUP_WIDTH,
    .height = QUEST_POPUP_HEIGHT,
    .paletteNum = QUEST_POPUP_PAL,
    .baseBlock = QUEST_POPUP_BASE_BLOCK,
};

// special: kept so a script can raise the banner by hand (VAR_0x8004 = quest id).
void DoQuestCompletePopup(void)
{
    ShowQuestCompletePopup(gSpecialVar_0x8004);
}

// Starts the banner task if any completions are still queued. Called both when a
// quest finishes and whenever the overworld resumes: the quest menu wipes every
// task when it opens, so a banner queued by the in-menu condition checker has to
// be picked back up once the player is back outside.
void QuestPopup_KickQueue(void)
{
    if (sQuestPopupQueueCount != 0 && !FuncIsActiveTask(Task_QuestPopup))
    {
        u8 taskId = CreateTask(Task_QuestPopup, 90);

        gTasks[taskId].tState = QSTATE_NEXT;
        sQuestPopupWindowId = WINDOW_NONE;
        sQuestPopupIconSpriteId = SPRITE_NONE;
    }
}

void ShowQuestCompletePopup(u16 questId)
{
    if (sQuestPopupQueueCount < QUEST_POPUP_QUEUE_SIZE)
    {
        sQuestPopupQueue[(sQuestPopupQueueHead + sQuestPopupQueueCount) % QUEST_POPUP_QUEUE_SIZE] = questId;
        sQuestPopupQueueCount++;
    }

    QuestPopup_KickQueue();
}

bool8 IsQuestCompletePopupActive(void)
{
    return FuncIsActiveTask(Task_QuestPopup);
}

// Tears the banner down immediately and restores BG0's scroll. Called when the
// start menu opens (which also scrolls BG0), the same way the map-name pop-up is
// hidden, so the banner never fights the menu's graphics.
void HideQuestCompletePopup(void)
{
    u8 taskId = FindTaskIdByFunc(Task_QuestPopup);

    sQuestPopupQueueCount = 0;
    sQuestPopupQueueHead = 0;

    if (taskId != TASK_NONE)
    {
        QuestPopup_Teardown();
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        DestroyTask(taskId);
    }
}

static bool8 QuestPopup_FieldIsIdle(void)
{
    // Wait until the completion cutscene has fully handed control back (and no
    // map-name banner is up), so the banner never scrolls a live message box.
    return IsFieldMessageBoxHidden() && !ArePlayerFieldControlsLocked() && !IsMapNamePopupActive();
}

static void Task_QuestPopup(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    // Once the banner is on screen it owns BG0's vertical scroll. If a script or
    // field message box seizes the overworld while it is up -- e.g. a Repel wears
    // off on the same walk and asks "Use another?" -- that interface draws on the
    // same scrolled BG0, so both come out graphically offset. Get out of its way
    // at once: snap BG0 back and tear the banner down. If it was still sliding in
    // or holding, re-announce this quest once the field is idle again; if it was
    // already sliding away it has been seen, so just move on to the next quest.
    if ((task->tState == QSTATE_SLIDE_IN || task->tState == QSTATE_HOLD || task->tState == QSTATE_SLIDE_OUT)
        && !QuestPopup_FieldIsIdle())
    {
        QuestPopup_Teardown();
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        task->tYOffset = 0;
        task->tState = (task->tState == QSTATE_SLIDE_OUT) ? QSTATE_NEXT : QSTATE_WAIT_FIELD;
        return;
    }

    switch (task->tState)
    {
    case QSTATE_NEXT:
        // The previous banner is gone and its tilemap was cleared a frame ago, so
        // BG0 can safely unscroll now. Then announce the next queued quest, or
        // finish once the queue drains.
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        if (sQuestPopupQueueCount == 0)
        {
            DestroyTask(taskId);
            return;
        }
        sQuestPopupQuestId = sQuestPopupQueue[sQuestPopupQueueHead];
        sQuestPopupQueueHead = (sQuestPopupQueueHead + 1) % QUEST_POPUP_QUEUE_SIZE;
        sQuestPopupQueueCount--;
        task->tYOffset = 0;  // hold BG0 unscrolled while waiting for the field to idle
        task->tState = QSTATE_WAIT_FIELD;
        return;
    case QSTATE_WAIT_FIELD:
        if (QuestPopup_FieldIsIdle())
        {
            QuestPopup_Draw();
            task->tYOffset = QUEST_POPUP_OFFSCREEN_Y;
            SetGpuReg(REG_OFFSET_BG0VOFS, task->tYOffset);
            PlayFanfare(MUS_LEVEL_UP);
            task->tState = QSTATE_SLIDE_IN;
        }
        break;
    case QSTATE_SLIDE_IN:
        task->tYOffset -= QUEST_POPUP_SLIDE_SPEED;
        if (task->tYOffset <= QUEST_POPUP_ONSCREEN_Y)
        {
            task->tYOffset = QUEST_POPUP_ONSCREEN_Y;
            task->tTimer = 0;
            task->tState = QSTATE_HOLD;
        }
        break;
    case QSTATE_HOLD:
        if (++task->tTimer > QUEST_POPUP_HOLD_TIME)
            task->tState = QSTATE_SLIDE_OUT;
        break;
    case QSTATE_SLIDE_OUT:
        task->tYOffset += QUEST_POPUP_SLIDE_SPEED;
        if (task->tYOffset >= QUEST_POPUP_OFFSCREEN_Y)
        {
            // Fully off-screen: tear the window down but keep BG0 scrolled off, so
            // the just-cleared tilemap can't flash at the top for a frame before
            // the clear reaches VRAM. QSTATE_NEXT unscrolls BG0 next frame.
            task->tYOffset = QUEST_POPUP_OFFSCREEN_Y;
            QuestPopup_Teardown();
            task->tState = QSTATE_NEXT;
        }
        break;
    }

    // Scroll the bar and keep the icon glued to it.
    SetGpuReg(REG_OFFSET_BG0VOFS, task->tYOffset);
    if (sQuestPopupIconSpriteId != SPRITE_NONE)
    {
        s16 iconY = QUEST_POPUP_ICON_Y - task->tYOffset;

        gSprites[sQuestPopupIconSpriteId].y = iconY;
        // Hide the icon whenever it would sit off the top of the screen, so its
        // 8-bit OAM Y can never wrap and leave a sliver behind as it slides away.
        gSprites[sQuestPopupIconSpriteId].invisible = (iconY < 0);
    }
}

static void QuestPopup_Draw(void)
{
    u8 text[MAP_POPUP_PREFIX_BUFFER_LENGTH + sizeof(sText_QuestCompleted)];

    sQuestPopupWindowId = AddWindow(&sQuestPopupWindowTemplate);
    if (sQuestPopupWindowId == WINDOW_NONE)
        return;

    // The actual Gen-5 location-banner frame, rendered at the window's height.
    LoadGen5PopupFrameToWindow(sQuestPopupWindowId);

    // Fixed label (transparent bg/accent so it uses the banner's own text color).
    text[0] = EXT_CTRL_CODE_BEGIN;
    text[1] = EXT_CTRL_CODE_BACKGROUND;
    text[2] = TEXT_COLOR_TRANSPARENT;
    text[3] = EXT_CTRL_CODE_BEGIN;
    text[4] = EXT_CTRL_CODE_ACCENT;
    text[5] = TEXT_COLOR_TRANSPARENT;
    StringCopy(&text[MAP_POPUP_PREFIX_BUFFER_LENGTH], sText_QuestCompleted);
    AddTextPrinterParameterized(sQuestPopupWindowId, FONT_SHORT, text, QUEST_POPUP_TEXT_X, QUEST_POPUP_TEXT_Y, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(sQuestPopupWindowId, COPYWIN_FULL);

    // The quest's own icon, whatever kind it is (species, item, badge, object).
    // It starts off-screen (above the bar), so hide it until the slide brings it
    // on screen to avoid a first-frame flash / OAM wrap.
    sQuestPopupIconSpriteId = QuestMenu_CreateQuestIconSprite(sQuestPopupQuestId, QUEST_POPUP_ICON_X,
                                                              QUEST_POPUP_ICON_Y - QUEST_POPUP_OFFSCREEN_Y);
    if (sQuestPopupIconSpriteId != SPRITE_NONE)
        gSprites[sQuestPopupIconSpriteId].invisible = TRUE;
}

static void QuestPopup_Teardown(void)
{
    if (sQuestPopupIconSpriteId != SPRITE_NONE)
    {
        QuestMenu_FreeQuestIconSprite(sQuestPopupQuestId, sQuestPopupIconSpriteId);
        sQuestPopupIconSpriteId = SPRITE_NONE;
    }
    if (sQuestPopupWindowId != WINDOW_NONE)
    {
        FillWindowPixelBuffer(sQuestPopupWindowId, PIXEL_FILL(0));
        ClearWindowTilemap(sQuestPopupWindowId);
        CopyWindowToVram(sQuestPopupWindowId, COPYWIN_FULL);
        RemoveWindow(sQuestPopupWindowId);
        sQuestPopupWindowId = WINDOW_NONE;
    }
}

#undef tState
#undef tYOffset
#undef tTimer
