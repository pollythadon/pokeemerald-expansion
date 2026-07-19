#include "global.h"
#include "strings.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item.h"
#include "item_icon.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "international_string_util.h"
#include "list_menu.h"
#include "item_use.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "money.h"
#include "pokedex.h"
#include "palette.h"
#include "party_menu.h"
#include "pokemon.h"
#include "pokemon_storage_system.h"
#include "scanline_effect.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "quests.h"
#include "quest_popup.h"
#include "overworld.h"
#include "event_data.h"
#include "constants/items.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "constants/event_objects.h"
#include "event_object_movement.h"
#include "pokemon_icon.h"

#include "random.h"
#include "complex_quests.h"
#include "quest_placeholder_strings.h"
#include "quest_data.h"
#include "field_effect.h"
#include "field_effect_helpers.h"
#include "trainer_see.h"
#include "constants/field_effects.h"
#include "constants/trainer_types.h"

#define tPageItems      data[4]
#define tItemPcParam    data[6]
#define QUEST_SAVE_DATA_MAGIC 0x51554553
#define QUEST_NAME_BUFFER_SIZE 64
#define QUEST_ICON_SPRITE_SLOTS 2
#define QUEST_CATEGORY_ICON_TAG_BASE 120

#define QUEST_MENU_PAGE_HUB  0
#define QUEST_MENU_PAGE_LIST 1

#define QUEST_HUB_CARD_FIRST_WINDOW 3
#define QUEST_HUB_DESC_FIRST_WINDOW 6
#define QUEST_HUB_DESC_BUFFER_COUNT 2
#define QUEST_HUB_LAST_WINDOW       (QUEST_HUB_DESC_FIRST_WINDOW + QUEST_HUB_DESC_BUFFER_COUNT - 1)
#define QUEST_HUB_CARD_TOP          4
#define QUEST_HUB_CARD_SELECTED_TOP 3
#define QUEST_HUB_ICON_Y            76
#define QUEST_HUB_ICON_SELECTED_Y   68
#define QUEST_HUB_BG_PANEL_TILE     383

#define QUEST_WINDOW_COLOR_PANEL          10
#define QUEST_WINDOW_COLOR_PANEL_SELECTED 11
#define QUEST_WINDOW_COLOR_BORDER         12
#define QUEST_WINDOW_COLOR_ACCENT         13

struct QuestMenuResources
{
	MainCallback savedCallback;
	u8 moveModeOrigPos;
	u8 spriteIconSlot;
	u8 spriteIconTypes[QUEST_ICON_SPRITE_SLOTS];
	u16 oldPaletteTag;
	u8 maxShowed;
	u8 nItems;
	u8 scrollIndicatorArrowPairId;
	s16 data[3];
	u8 filterMode;
	u8 parentQuest;
	u8 menuPage;
	u8 category;
	u8 hubDescSlot;
	u8 categorySpriteIds[QUEST_CATEGORY_COUNT];
	bool8 hubGraphicsReady;
	bool8 restoreCursor;
};

struct QuestMenuStaticResources
{
	MainCallback savedCallback;
	u16 scroll;
	u16 row;
	u8 initialized;
	u16 storedScrollOffset;
	u16 storedRowPosition;
};

// RAM
EWRAM_DATA static struct QuestMenuResources *sStateDataPtr = NULL;
EWRAM_DATA static u8 *sBg1TilemapBuffer = NULL;
EWRAM_DATA static struct ListMenuItem *sListMenuItems = NULL;
EWRAM_DATA static struct QuestMenuStaticResources sListMenuState = {0};
EWRAM_DATA static u8 sItemMenuIconSpriteIds[12] = {0};        // from pokefirered src/item_menu_icons.c
EWRAM_DATA static void *questNamePointer = NULL;
EWRAM_DATA static u8 **questNameArray = NULL;

// This File's Functions
void QuestMenu_Init(u8 a0, MainCallback callback);
static void MainCB(void);
static void VBlankCB(void);
static void RunSetup(void);

static bool8 SetupGraphics(void);
static bool8 LoadGraphics(void);
static void QuestMenu_InitWindows(void);
static bool8 InitBackgrounds(void);
static void Task_CategoryMain(u8 taskId);
static void ShowCategoryHub(void);
static void DrawCategoryHub(void);
static void DrawCategoryHubBackground(void);
static void UpdateCategoryHubSelection(void);
static void DrawCategoryCard(u8 category);
static void DrawCategoryDescription(u8 category, u8 slot);
static void CreateCategorySprites(void);
static void DestroyCategorySprites(void);
static void SetCategorySpritesVisible(bool8 visible);
static void OpenCategoryList(u8 taskId);
static void Task_OpenCategoryListFadeOut(u8 taskId);
static void Task_OpenCategoryListFadeIn(u8 taskId);
static void ReturnToCategoryHub(u8 taskId);
static void ClearQuestDetailsWindow(void);
static void InitItems(void);
static bool8 AllocateResourcesForListMenu(void);
static bool8 AllocateMemoryForArray(void);
static void QuestMenu_ValidateSaveData(void);
static bool8 QuestMenu_IsQuestIdValid(u8 quest);
static bool8 QuestMenu_IsSubquestIdValid(u8 quest, u8 childQuest);
static u8 *QuestNameBufferCopy(u8 bufferId, const u8 *src);
static u8 *QuestNameBufferAppend(u8 bufferId, const u8 *src);
static void PlaceTopMenuScrollIndicatorArrows(void);
static void SetInitializedFlag(u8 a0);

static u8 GetCursorPosition(void);
static void SaveScrollAndRow(s16 *data);

static void ClearModeOnStartup(void);
static u8 ManageMode(u8 action);
static u8 ToggleAlphaMode(u8 mode);
static u8 ToggleSubquestMode(u8 mode);
static u8 IncrementMode(u8 mode);
static bool8 IsSubquestMode(void);
static bool8 IsNotFilteredMode(void);
static bool8 IsAlphaMode(void);

static void BuildMenuTemplate(void);
static u8 GetModeAndGenerateList();
static u8 CountNumberListRows();
static u8 *DefineQuestOrder();
static u8 GenerateSubquestList();
static u8 GenerateList(bool8 isFiltered);
static bool8 QuestMenu_IsQuestAvailable(u8 questId);
static bool8 QuestMenu_IsQuestInCurrentCategory(u8 questId);
static u8 CountAvailableQuests(void);
static u8 CountAvailableQuestsInCategory(u8 category);
static u8 CountCompletedQuestsInCategory(u8 category);
static void QuestMenu_TryAdvanceConditionalQuests(void);
static void TryClaimQuestReward(u8 taskId, u8 questId);
static void QuestMenu_PrintRewardMessage(u8 questId);
static void Task_WaitForRewardAck(u8 taskId);
static void AssignCancelNameAndId(u8 numRow);

static u8 CountUnlockedQuests(void);
static u8 CountInactiveQuests(void);
static u8 CountActiveQuests(void);
static u8 CountRewardQuests(void);
static u8 CountCompletedQuests(void);
static u8 CountFavoriteQuests(void);

static void PopulateEmptyRow(u8 countQuest);
static void PrependQuestNumber(u8 countQuest);
static void SetFavoriteQuest(u8 countQuest);
static void PopulateQuestName(u8 countQuest);
static void PopulateSubquestName(u8 parentQuest, u8 countQuest);
static void PopulateListRowNameAndId(u8 row, u8 countQuest);
static bool8 DoesQuestHaveChildrenAndNotInactive(u16 itemId);
static void AddSubQuestButton(u8 countQuest);

static void QuestMenu_AddTextPrinterParameterized(u8 windowId, u8 fontId,
            const u8 *str, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, u8 speed,
            u8 colorIdx);

static void MoveCursorFunc(s32 itemIndex, bool8 onInit,
                           struct ListMenu *list);
static void PlayCursorSound(bool8 firstRun);
static void PrintDetailsForCancel();
static void GenerateAndPrintQuestDetails(s32 questId);
static void GenerateQuestLocation(s32 questId);
static void PrintQuestLocation(s32 questId);
static void GenerateQuestFlavorText(s32 questId);
static void UpdateQuestFlavorText(s32 questId);
static void PrintQuestFlavorText(s32 questId);
static const u8 *GetQuestDesc(s32 questId);
static const u8 *GetQuestLocation(s32 questId);

static bool8 IsQuestUnlocked(s32 questId);
static bool8 IsQuestActiveState(s32 questId);
static bool8 IsQuestInactiveState(s32 questId);
static bool8 IsQuestRewardState(s32 questId);
static bool8 IsQuestCompletedState(s32 questId);
static bool8 IsSubquestCompletedState(s32 questId);

static void DetermineSpriteType(s32 questId);
static void QuestMenu_CreateSprite(u16 itemId, u8 idx, u8 spriteType);
static void ResetSpriteState(void);
static void QuestMenu_DestroySprite(u8 idx);
static u32 GetQuestSprite(s32 questId);
static u32 GetQuestSpriteType(s32 questId);

static void GenerateStateAndPrint(u8 windowId, u32 itemId, u8 y);
static u8 GenerateSubquestState(u8 questId);
static u8 GenerateQuestState(u8 questId);
static void PrintQuestState(u8 windowId, u8 y, u8 colorIndex);

static void GenerateAndPrintHeader(void);
static void GenerateDenominatorNumQuests(void);
static void GenerateNumeratorNumQuests(void);
static void GenerateMenuContext(void);
static void PrintNumQuests(void);
static void PrintMenuContext(void);
static void PrintTypeFilterButton(void);

static void Task_Main(u8 taskId);
static void ManageFavorites(u8 index);
static void Task_QuestMenuCleanUp(u8 taskId);
static void RestoreSavedScrollAndRow(s16 *data);
static void ResetCursorToTop(s16 *data);
static void QuestMenu_RemoveScrollIndicatorArrowPair(void);
static void EnterSubquestModeAndCleanUp(u8 taskId, s16 *data, s32 input);
static void ChangeModeAndCleanUp(u8 taskId);
static void ToggleAlphaModeAndCleanUp(u8 taskId);
static void ToggleFavoriteAndCleanUp(u8 taskId, u8 selectedQuestId);
static bool8 CheckSelectedIsCancel(u8 selectedQuestId);
static void ReturnFromSubquestAndCleanUp(u8 taskId);

static void SetGpuRegBaseForFade(void);
static void InitFadeVariables(u8 taskId, u8 blendWeight, u8 frameDelay,
                              u8 frameTimerBase, u8 delta);
static void PrepareFadeOut(u8 taskId);
static bool8 HandleFadeOut(u8 taskId);
static void PrepareFadeIn(u8 taskId);
static bool8 HandleFadeIn(u8 taskId);
static void Task_FadeOut(u8 taskId);
static void Task_FadeIn(u8 taskId);

static void Task_QuestMenuWaitFadeAndBail(u8 taskId);
static void FadeAndBail(void);
static void FreeResources(void);
static void TurnOffQuestMenu(u8 taskId);
static void Task_QuestMenuTurnOff1(u8 taskId);
static void Task_QuestMenuTurnOff2(u8 taskId);

// Tiles, palettes and tilemaps for the Quest Menu
static const u32 sQuestMenuTiles[] =
        INCBIN_U32("graphics/quest_menu/menu.4bpp.lz");
static const u16 sQuestMenuBgPals[] =
        INCBIN_U16("graphics/quest_menu/menu.gbapal");
static const u32 sQuestMenuTilemap[] =
        INCBIN_U32("graphics/quest_menu/menu.bin.lz");

// A single solid BG1 tile replaces the busy list artwork while the category
// hub is open. The cards and text stay on BG0 above this quiet charcoal canvas.
static const u32 sQuestHubBgTile[] =
{
	0xBBBBBBBB, 0xBBBBBBBB, 0xBBBBBBBB, 0xBBBBBBBB,
	0xBBBBBBBB, 0xBBBBBBBB, 0xBBBBBBBB, 0xBBBBBBBB,
};

//Strings used for the Quest Menu
static const u8 sText_Empty[] = _("");
static const u8 sText_AllHeader[] = _("All");
static const u8 sText_InactiveHeader[] = _("Inactive");
static const u8 sText_ActiveHeader[] = _("Active");
static const u8 sText_RewardHeader[] = _("Rewards");
static const u8 sText_CompletedHeader[] = _("Completed");
static const u8 sText_QuestNumberDisplay[] =
      _("{STR_VAR_1}/{STR_VAR_2}");
static const u8 sText_Unk[] = _("??????");
static const u8 sText_Active[] = _("Active");
static const u8 sText_Reward[] = _("Reward");
static const u8 sText_Complete[] = _("Done");
static const u8 sText_ShowLocation[] =
      _("Location: {STR_VAR_2}");
static const u8 sText_ReturnRecieveReward[] =
      _("Press {A_BUTTON} to claim\nyour reward!");
static const u8 sText_RewardGotItem[] =
      _("You received\n{STR_VAR_1} {STR_VAR_2}!");
static const u8 sText_RewardGotMoney[] =
      _("You received\n¥{STR_VAR_3}!");
static const u8 sText_RewardGotBoth[] =
      _("Got {STR_VAR_1} {STR_VAR_2}\nand ¥{STR_VAR_3}!");
static const u8 sText_SubQuestButton[] = _(" {A_BUTTON}");
static const u8 sText_Type[] = _("{R_BUTTON}Type");
static const u8 sText_Caught[] = _("Caught");
static const u8 sText_Found[] = _("Found");
static const u8 sText_Read[] = _("Read");
static const u8 sText_Back[] = _("Back");
static const u8 sText_DotSpace[] = _(". ");
static const u8 sText_NoQuests[] = _("No missions yet.");
static const u8 sText_NoQuestsHint[] =
      _("New missions will appear here\nas your adventure unfolds.");
static const u8 sText_ColorGreen[] = _("{COLOR}{GREEN}");
static const u8 sText_AZ[] = _(" A-Z");
static const u8 sText_QuestLog[] = _("QUEST LOG");
static const u8 sText_ChooseCategory[] = _("CHOOSE A CATEGORY");
static const u8 sText_Quests[] = _("QUESTS");
static const u8 sText_HeaderDivider[] = _(" / ");
static const u8 sText_CategoryProgress[] = _("{STR_VAR_1}/{STR_VAR_2} complete");
static const u8 sText_NoCategoryQuests[] = _("No quests yet");

static const u8 sText_StoryCard[] = _("STORY");
static const u8 sText_PokemonCard[] = _("POKéMON");
static const u8 sText_SideCard[] = _("SIDE");
static const u8 sText_StoryCategory[] = _("Story Quests");
static const u8 sText_PokemonCategory[] = _("Pokémon Quests");
static const u8 sText_SideCategory[] = _("Side Quests");
static const u8 sText_StoryCategoryDesc[] =
      _("Follow Hoenn's journey, earn\nbadges, and become Champion.");
static const u8 sText_PokemonCategoryDesc[] =
      _("Track rare Pokémon sightings\nand legendary encounters.");
static const u8 sText_SideCategoryDesc[] =
      _("Tackle optional requests,\ncollection goals, and local tales.");

static const u8 *const sQuestCategoryCardNames[QUEST_CATEGORY_COUNT] =
{
	sText_StoryCard,
	sText_PokemonCard,
	sText_SideCard,
};

static const u8 *const sQuestCategoryNames[QUEST_CATEGORY_COUNT] =
{
	sText_StoryCategory,
	sText_PokemonCategory,
	sText_SideCategory,
};

static const u8 *const sQuestCategoryDescriptions[QUEST_CATEGORY_COUNT] =
{
	sText_StoryCategoryDesc,
	sText_PokemonCategoryDesc,
	sText_SideCategoryDesc,
};

static const u16 sQuestCategoryIconItems[QUEST_CATEGORY_COUNT] =
{
	ITEM_TOWN_MAP,
	ITEM_POKE_BALL,
	ITEM_VS_SEEKER,
};

///////////////////////////////////////////////////////////////////////////////
//////////////////////BEGIN SUBQUEST CUSTOMIZATION/////////////////////////////

//Declaration of subquest structures. Edits to subquests are made here.
#define sub_quest(i, n, d, m, s, st, t) {.id = i, .name = n, .desc = d, .map = m, .sprite = s, .spritetype = st, .type = t}
static const struct SubQuest sSubQuests1[QUEST_1_SUB_COUNT] =
{
	sub_quest(
	      0,
	      gText_SubQuest1_Name1,
	      gText_SubQuest1_Desc1,
	      gText_SideQuestMap1,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      1,
	      gText_SubQuest1_Name2,
	      gText_SubQuest1_Desc2,
	      gText_SideQuestMap2,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      2,
	      gText_SubQuest1_Name3,
	      gText_SubQuest1_Desc3,
	      gText_SideQuestMap3,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      3,
	      gText_SubQuest1_Name4,
	      gText_SubQuest1_Desc4,
	      gText_SideQuestMap4,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      4,
	      gText_SubQuest1_Name5,
	      gText_SubQuest1_Desc5,
	      gText_SideQuestMap5,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      5,
	      gText_SubQuest1_Name6,
	      gText_SubQuest1_Desc6,
	      gText_SideQuestMap6,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      6,
	      gText_SubQuest1_Name7,
	      gText_SubQuest1_Desc7,
	      gText_SideQuestMap7,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      7,
	      gText_SubQuest1_Name8,
	      gText_SubQuest1_Desc8,
	      gText_SideQuestMap8,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      8,
	      gText_SubQuest1_Name9,
	      gText_SubQuest1_Desc9,
	      gText_SideQuestMap9,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      9,
	      gText_SubQuest1_Name10,
	      gText_SubQuest1_Desc10,
	      gText_SideQuestMap10,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),
};

static const struct SubQuest sSubQuests2[QUEST_2_SUB_COUNT] =
{
	sub_quest(
	      10,
	      gText_SubQuest2_Name1,
	      gText_SubQuest2_Desc1,
	      gText_SideQuestMap1,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      11,
	      gText_SubQuest2_Name2,
	      gText_SubQuest2_Desc2,
	      gText_SideQuestMap2,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      12,
	      gText_SubQuest2_Name3,
	      gText_SubQuest2_Desc3,
	      gText_SideQuestMap3,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      13,
	      gText_SubQuest2_Name4,
	      gText_SubQuest2_Desc4,
	      gText_SideQuestMap4,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      14,
	      gText_SubQuest2_Name5,
	      gText_SubQuest2_Desc5,
	      gText_SideQuestMap5,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      15,
	      gText_SubQuest2_Name6,
	      gText_SubQuest2_Desc6,
	      gText_SideQuestMap6,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      16,
	      gText_SubQuest2_Name7,
	      gText_SubQuest2_Desc7,
	      gText_SideQuestMap7,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      17,
	      gText_SubQuest2_Name8,
	      gText_SubQuest2_Desc8,
	      gText_SideQuestMap8,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      18,
	      gText_SubQuest2_Name9,
	      gText_SubQuest2_Desc9,
	      gText_SideQuestMap9,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      19,
	      gText_SubQuest2_Name10,
	      gText_SubQuest2_Desc10,
	      gText_SideQuestMap10,
	      SPECIES_HO_OH,
	      PKMN,
	      sText_Caught

	),

	sub_quest(
	      20,
	      gText_SubQuest2_Name11,
	      gText_SubQuest2_Desc11,
	      gText_SideQuestMap11,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      21,
	      gText_SubQuest2_Name12,
	      gText_SubQuest2_Desc12,
	      gText_SideQuestMap12,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      22,
	      gText_SubQuest2_Name13,
	      gText_SubQuest2_Desc13,
	      gText_SideQuestMap13,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      23,
	      gText_SubQuest2_Name14,
	      gText_SubQuest2_Desc14,
	      gText_SideQuestMap14,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      24,
	      gText_SubQuest2_Name15,
	      gText_SubQuest2_Desc15,
	      gText_SideQuestMap15,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      25,
	      gText_SubQuest2_Name16,
	      gText_SubQuest2_Desc16,
	      gText_SideQuestMap16,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      26,
	      gText_SubQuest2_Name17,
	      gText_SubQuest2_Desc17,
	      gText_SideQuestMap17,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      27,
	      gText_SubQuest2_Name18,
	      gText_SubQuest2_Desc18,
	      gText_SideQuestMap18,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      28,
	      gText_SubQuest2_Name19,
	      gText_SubQuest2_Desc19,
	      gText_SideQuestMap19,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

	sub_quest(
	      29,
	      gText_SubQuest2_Name20,
	      gText_SubQuest2_Desc20,
	      gText_SideQuestMap20,
	      OBJ_EVENT_GFX_WALLY,
	      OBJECT,
	      sText_Found
	),

};

////////////////////////END SUBQUEST CUSTOMIZATION/////////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
////////////////////////BEGIN QUEST CUSTOMIZATION//////////////////////////////

//Declaration of side quest structures. Edits to quests are made here.
static const struct SideQuest sSideQuests[QUEST_COUNT] =
{
	[QUEST_MEWTWO] =
	{
		.name = sQuestName_Mewtwo,
		.category = QUEST_CATEGORY_POKEMON,
		.startmap = sQuestStartMap_Mewtwo,
		.startdesc = sQuestStart_Mewtwo,
		.desc = {sQuestDesc_Mewtwo},
		.donedesc = sQuestDone_Mewtwo,
		.map = {sQuestMap_Mewtwo},
		.sprite = {SPECIES_MEWTWO},
		.spritetype = {PKMN},
		.subquests = NULL,
		.numSubquests = 0,
		.questVariable = 0,
		.availType = QUEST_AVAIL_POSTGAME,
	},
	[QUEST_DIALGA] =
	{
		.name = sQuestName_Dialga,
		.category = QUEST_CATEGORY_POKEMON,
		.startmap = sQuestStartMap_Dialga,
		.startdesc = sQuestStart_Dialga,
		.desc = {sQuestDesc_Dialga},
		.donedesc = sQuestDone_Dialga,
		.map = {sQuestMap_Dialga},
		.sprite = {SPECIES_DIALGA},
		.spritetype = {PKMN},
		.subquests = NULL,
		.numSubquests = 0,
		.questVariable = 0,
		.availType = QUEST_AVAIL_POSTGAME,
	},
	[QUEST_PALKIA] =
	{
		.name = sQuestName_Palkia,
		.category = QUEST_CATEGORY_POKEMON,
		.startmap = sQuestStartMap_Palkia,
		.startdesc = sQuestStart_Palkia,
		.desc = {sQuestDesc_Palkia},
		.donedesc = sQuestDone_Palkia,
		.map = {sQuestMap_Palkia},
		.sprite = {SPECIES_PALKIA},
		.spritetype = {PKMN},
		.subquests = NULL,
		.numSubquests = 0,
		.questVariable = 0,
		.availType = QUEST_AVAIL_POSTGAME,
	},
	[QUEST_GIRATINA] =
	{
		.name = sQuestName_Giratina,
		.category = QUEST_CATEGORY_POKEMON,
		.startmap = sQuestStartMap_Giratina,
		.startdesc = sQuestStart_Giratina,
		.desc = {sQuestDesc_Giratina},
		.donedesc = sQuestDone_Giratina,
		.map = {sQuestMap_Giratina},
		.sprite = {SPECIES_GIRATINA},
		.spritetype = {PKMN},
		.subquests = NULL,
		.numSubquests = 0,
		.questVariable = 0,
		.availType = QUEST_AVAIL_POSTGAME,
	},
	[QUEST_ARCEUS] =
	{
		.name = sQuestName_Arceus,
		.category = QUEST_CATEGORY_POKEMON,
		.startmap = sQuestStartMap_Arceus,
		.startdesc = sQuestStart_Arceus,
		.desc = {sQuestDesc_Arceus},
		.donedesc = sQuestDone_Arceus,
		.map = {sQuestMap_Arceus},
		.sprite = {SPECIES_ARCEUS},
		.spritetype = {PKMN},
		.subquests = NULL,
		.numSubquests = 0,
		.questVariable = 0,
		.availType = QUEST_AVAIL_POSTGAME,
	},
	[QUEST_JIRACHI] =
	{
		.name = sQuestName_Jirachi,
		.category = QUEST_CATEGORY_POKEMON,
		.startmap = sQuestStartMap_Jirachi,
		.startdesc = sQuestStart_Jirachi,
		.desc = {sQuestDesc_Jirachi_0, sQuestDesc_Jirachi_1},
		.donedesc = sQuestDone_Jirachi,
		.map = {sQuestMap_Jirachi_0, sQuestMap_Jirachi_1},
		.sprite = {SPECIES_JIRACHI, SPECIES_JIRACHI},
		.spritetype = {PKMN, PKMN},
		.subquests = NULL,
		.numSubquests = 0,
		.questVariable = VAR_UNUSED_0x404E, // repurposed unused var
		.availType = QUEST_AVAIL_POSTGAME,
	},
	[QUEST_CELEBI] =
	{
		.name = sQuestName_Celebi,
		.category = QUEST_CATEGORY_POKEMON,
		.startmap = sQuestStartMap_Celebi,
		.startdesc = sQuestStart_Celebi,
		.desc = {sQuestDesc_Celebi},
		.donedesc = sQuestDone_Celebi,
		.map = {sQuestMap_Celebi},
		.sprite = {SPECIES_CELEBI},
		.spritetype = {PKMN},
		.subquests = NULL,
		.numSubquests = 0,
		.questVariable = 0,
		.availType = QUEST_AVAIL_POSTGAME,
	},
	[QUEST_DARKRAI] =
	{
		.name = sQuestName_Darkrai,
		.category = QUEST_CATEGORY_POKEMON,
		.startmap = sQuestStartMap_Darkrai,
		.startdesc = sQuestStart_Darkrai,
		.desc = {sQuestDesc_Darkrai},
		.donedesc = sQuestDone_Darkrai,
		.map = {sQuestMap_Darkrai},
		.sprite = {SPECIES_DARKRAI},
		.spritetype = {PKMN},
		.subquests = NULL,
		.numSubquests = 0,
		.questVariable = 0,
		.availType = QUEST_AVAIL_POSTGAME,
	},
	[QUEST_CRESSELIA] =
	{
		.name = sQuestName_Cresselia,
		.category = QUEST_CATEGORY_POKEMON,
		.startmap = sQuestStartMap_Cresselia,
		.startdesc = sQuestStart_Cresselia,
		.desc = {sQuestDesc_Cresselia},
		.donedesc = sQuestDone_Cresselia,
		.map = {sQuestMap_Cresselia},
		.sprite = {SPECIES_CRESSELIA},
		.spritetype = {PKMN},
		.subquests = NULL,
		.numSubquests = 0,
		.questVariable = 0,
		.availType = QUEST_AVAIL_POSTGAME,
	},
	[QUEST_SHAYMIN] =
	{
		.name = sQuestName_Shaymin,
		.category = QUEST_CATEGORY_POKEMON,
		.startmap = sQuestStartMap_Shaymin,
		.startdesc = sQuestStart_Shaymin,
		.desc = {sQuestDesc_Shaymin},
		.donedesc = sQuestDone_Shaymin,
		.map = {sQuestMap_Shaymin},
		.sprite = {SPECIES_SHAYMIN},
		.spritetype = {PKMN},
		.subquests = NULL,
		.numSubquests = 0,
		.questVariable = 0,
		.availType = QUEST_AVAIL_POSTGAME,
	},
	[QUEST_MEW] =
	{
		.name = sQuestName_Mew,
		.category = QUEST_CATEGORY_POKEMON,
		.startmap = sQuestStartMap_Mew,
		.startdesc = sQuestStart_Mew,
		.desc = {sQuestDesc_Mew},
		.donedesc = sQuestDone_Mew,
		.map = {sQuestMap_Mew},
		.sprite = {SPECIES_MEW},
		.spritetype = {PKMN},
		.availType = QUEST_AVAIL_POSTGAME,
	},
	[QUEST_LUGIA] =
	{
		.name = sQuestName_Lugia,
		.category = QUEST_CATEGORY_POKEMON,
		.startmap = sQuestStartMap_Lugia,
		.startdesc = sQuestStart_Lugia,
		.desc = {sQuestDesc_Lugia},
		.donedesc = sQuestDone_Lugia,
		.map = {sQuestMap_Lugia},
		.sprite = {SPECIES_LUGIA},
		.spritetype = {PKMN},
		.availType = QUEST_AVAIL_POSTGAME,
	},
	[QUEST_DEOXYS] =
	{
		.name = sQuestName_Deoxys,
		.category = QUEST_CATEGORY_POKEMON,
		.startmap = sQuestStartMap_Deoxys,
		.startdesc = sQuestStart_Deoxys,
		.desc = {sQuestDesc_Deoxys},
		.donedesc = sQuestDone_Deoxys,
		.map = {sQuestMap_Deoxys},
		.sprite = {SPECIES_DEOXYS},
		.spritetype = {PKMN},
		.availType = QUEST_AVAIL_POSTGAME,
	},
	[QUEST_BADGE_1] =
	{
		.name = sQuestName_Badge1,
		.category = QUEST_CATEGORY_STORY,
		.startmap = sQuestMap_Badge1,
		.startdesc = sQuestDesc_Badge1,
		.desc = {sQuestDesc_Badge1},
		.donedesc = sQuestDone_Badge1,
		.map = {sQuestMap_Badge1},
		.sprite = {0},           // Stone Badge
		.spritetype = {BADGE},
		.availType = QUEST_AVAIL_FLAG_SET,
		.availFlag = FLAG_NORMAN_MENTIONED_ROXANNE,
		.rewardItem = ITEM_GREAT_BALL,
		.rewardQty = 10,
	},
	[QUEST_BADGE_2] =
	{
		.name = sQuestName_Badge2,
		.category = QUEST_CATEGORY_STORY,
		.startmap = sQuestMap_Badge2,
		.startdesc = sQuestDesc_Badge2,
		.desc = {sQuestDesc_Badge2},
		.donedesc = sQuestDone_Badge2,
		.map = {sQuestMap_Badge2},
		.sprite = {1},           // Knuckle Badge
		.spritetype = {BADGE},
		.availType = QUEST_AVAIL_FLAG_SET,
		.availFlag = FLAG_BADGE01_GET,
		.rewardItem = ITEM_HYPER_POTION,
		.rewardQty = 5,
	},
	[QUEST_BADGE_3] =
	{
		.name = sQuestName_Badge3,
		.category = QUEST_CATEGORY_STORY,
		.startmap = sQuestMap_Badge3,
		.startdesc = sQuestDesc_Badge3,
		.desc = {sQuestDesc_Badge3},
		.donedesc = sQuestDone_Badge3,
		.map = {sQuestMap_Badge3},
		.sprite = {2},           // Dynamo Badge
		.spritetype = {BADGE},
		.availType = QUEST_AVAIL_FLAG_SET,
		.availFlag = FLAG_BADGE02_GET,
		.rewardItem = ITEM_ULTRA_BALL,
		.rewardQty = 10,
	},
	[QUEST_BADGE_4] =
	{
		.name = sQuestName_Badge4,
		.category = QUEST_CATEGORY_STORY,
		.startmap = sQuestMap_Badge4,
		.startdesc = sQuestDesc_Badge4,
		.desc = {sQuestDesc_Badge4},
		.donedesc = sQuestDone_Badge4,
		.map = {sQuestMap_Badge4},
		.sprite = {3},           // Heat Badge
		.spritetype = {BADGE},
		.availType = QUEST_AVAIL_FLAG_SET,
		.availFlag = FLAG_BADGE03_GET,
		.rewardItem = ITEM_RARE_CANDY,
		.rewardQty = 5,
	},
	[QUEST_BADGE_5] =
	{
		.name = sQuestName_Badge5,
		.category = QUEST_CATEGORY_STORY,
		.startmap = sQuestMap_Badge5,
		.startdesc = sQuestDesc_Badge5,
		.desc = {sQuestDesc_Badge5},
		.donedesc = sQuestDone_Badge5,
		.map = {sQuestMap_Badge5},
		.sprite = {4},           // Balance Badge
		.spritetype = {BADGE},
		.availType = QUEST_AVAIL_FLAG_SET,
		.availFlag = FLAG_BADGE04_GET,
		.rewardItem = ITEM_PP_UP,
		.rewardQty = 3,
	},
	[QUEST_BADGE_6] =
	{
		.name = sQuestName_Badge6,
		.category = QUEST_CATEGORY_STORY,
		.startmap = sQuestMap_Badge6,
		.startdesc = sQuestDesc_Badge6,
		.desc = {sQuestDesc_Badge6},
		.donedesc = sQuestDone_Badge6,
		.map = {sQuestMap_Badge6},
		.sprite = {5},           // Feather Badge
		.spritetype = {BADGE},
		.availType = QUEST_AVAIL_FLAG_SET,
		.availFlag = FLAG_BADGE05_GET,
		.rewardItem = ITEM_MAX_REVIVE,
		.rewardQty = 5,
	},
	[QUEST_BADGE_7] =
	{
		.name = sQuestName_Badge7,
		.category = QUEST_CATEGORY_STORY,
		.startmap = sQuestMap_Badge7,
		.startdesc = sQuestDesc_Badge7,
		.desc = {sQuestDesc_Badge7},
		.donedesc = sQuestDone_Badge7,
		.map = {sQuestMap_Badge7},
		.sprite = {6},           // Mind Badge
		.spritetype = {BADGE},
		.availType = QUEST_AVAIL_FLAG_SET,
		.availFlag = FLAG_BADGE06_GET,
		.rewardItem = ITEM_ABILITY_CAPSULE,
		.rewardQty = 1,
	},
	[QUEST_BADGE_8] =
	{
		.name = sQuestName_Badge8,
		.category = QUEST_CATEGORY_STORY,
		.startmap = sQuestMap_Badge8,
		.startdesc = sQuestDesc_Badge8,
		.desc = {sQuestDesc_Badge8},
		.donedesc = sQuestDone_Badge8,
		.map = {sQuestMap_Badge8},
		.sprite = {7},           // Rain Badge
		.spritetype = {BADGE},
		.availType = QUEST_AVAIL_FLAG_SET,
		.availFlag = FLAG_BADGE07_GET,
		.rewardItem = ITEM_PP_MAX,
		.rewardQty = 1,
	},
	[QUEST_CHAMPION] =
	{
		.name = sQuestName_Champion,
		.category = QUEST_CATEGORY_STORY,
		.startmap = sQuestMap_Champion,
		.startdesc = sQuestDesc_Champion,
		.desc = {sQuestDesc_Champion},
		.donedesc = sQuestDone_Champion,
		.map = {sQuestMap_Champion},
		.sprite = {ITEM_MASTER_BALL},
		.spritetype = {ITEM},
		.availType = QUEST_AVAIL_FLAG_SET,
		.availFlag = FLAG_BADGE08_GET,
		.rewardItem = ITEM_MASTER_BALL,
		.rewardQty = 1,
		.rewardMoney = 200000,
	},
	[QUEST_DEXNAV] =
	{
		.name = sQuestName_DexNav,
		.category = QUEST_CATEGORY_SIDE,
		.startmap = sQuestStartMap_DexNav,
		.startdesc = sQuestStart_DexNav,
		.desc = {sQuestDesc_DexNav},
		.donedesc = sQuestDone_DexNav,
		.map = {sQuestMap_DexNav},
		.sprite = {ITEM_POKE_BALL},
		.spritetype = {ITEM},
		.availType = QUEST_AVAIL_FLAG_SET,
		.availFlag = FLAG_SYS_POKEDEX_GET,
	},
	[QUEST_POKEDEX] =
	{
		.name = sQuestName_Pokedex,
		.category = QUEST_CATEGORY_STORY,
		.startmap = sQuestMap_Pokedex,
		.startdesc = sQuestDesc_Pokedex,
		.desc = {sQuestDesc_Pokedex},
		.donedesc = sQuestDone_Pokedex,
		.map = {sQuestMap_Pokedex},
		.sprite = {ITEM_MASTER_BALL},
		.spritetype = {ITEM},
		.availType = QUEST_AVAIL_FLAG_SET,
		.availFlag = FLAG_SYS_POKEDEX_GET,
		.rewardItem = ITEM_MASTER_BALL,
		.rewardQty = 1,
	},
	[QUEST_CATCH_50] =
	{
		.name = sQuestName_Catch50,
		.category = QUEST_CATEGORY_SIDE,
		.startmap = sQuestMap_Catch,
		.startdesc = sQuestDesc_Catch50,
		.desc = {sQuestDesc_Catch50},
		.donedesc = sQuestDone_Catch50,
		.map = {sQuestMap_Catch},
		.sprite = {ITEM_ULTRA_BALL},
		.spritetype = {ITEM},
		.availType = QUEST_AVAIL_FLAG_SET,
		.availFlag = FLAG_SYS_POKEDEX_GET,
		.rewardItem = ITEM_ULTRA_BALL,
		.rewardQty = 10,
	},
	[QUEST_CATCH_100] =
	{
		.name = sQuestName_Catch100,
		.category = QUEST_CATEGORY_SIDE,
		.startmap = sQuestMap_Catch,
		.startdesc = sQuestDesc_Catch100,
		.desc = {sQuestDesc_Catch100},
		.donedesc = sQuestDone_Catch100,
		.map = {sQuestMap_Catch},
		.sprite = {ITEM_PP_MAX},
		.spritetype = {ITEM},
		.availType = QUEST_AVAIL_FLAG_SET,
		.availFlag = FLAG_SYS_POKEDEX_GET,
		.rewardItem = ITEM_PP_MAX,
		.rewardQty = 1,
	},
	[QUEST_CATCH_300] =
	{
		.name = sQuestName_Catch300,
		.category = QUEST_CATEGORY_SIDE,
		.startmap = sQuestMap_Catch,
		.startdesc = sQuestDesc_Catch300,
		.desc = {sQuestDesc_Catch300},
		.donedesc = sQuestDone_Catch300,
		.map = {sQuestMap_Catch},
		.sprite = {ITEM_ABILITY_CAPSULE},
		.spritetype = {ITEM},
		.availType = QUEST_AVAIL_FLAG_SET,
		.availFlag = FLAG_SYS_POKEDEX_GET,
		.rewardItem = ITEM_ABILITY_CAPSULE,
		.rewardQty = 1,
	},
	[QUEST_CATCH_500] =
	{
		.name = sQuestName_Catch500,
		.category = QUEST_CATEGORY_SIDE,
		.startmap = sQuestMap_Catch,
		.startdesc = sQuestDesc_Catch500,
		.desc = {sQuestDesc_Catch500},
		.donedesc = sQuestDone_Catch500,
		.map = {sQuestMap_Catch},
		.sprite = {ITEM_BOTTLE_CAP},
		.spritetype = {ITEM},
		.availType = QUEST_AVAIL_FLAG_SET,
		.availFlag = FLAG_SYS_POKEDEX_GET,
		.rewardItem = ITEM_BOTTLE_CAP,
		.rewardQty = 3,
	},
	[QUEST_CATCH_800] =
	{
		.name = sQuestName_Catch800,
		.category = QUEST_CATEGORY_SIDE,
		.startmap = sQuestMap_Catch,
		.startdesc = sQuestDesc_Catch800,
		.desc = {sQuestDesc_Catch800},
		.donedesc = sQuestDone_Catch800,
		.map = {sQuestMap_Catch},
		.sprite = {ITEM_MASTER_BALL},
		.spritetype = {ITEM},
		.availType = QUEST_AVAIL_FLAG_SET,
		.availFlag = FLAG_SYS_POKEDEX_GET,
		.rewardItem = ITEM_MASTER_BALL,
		.rewardQty = 1,
	},
	[QUEST_INTRO] =
	{
		.name = sQuestName_Intro,
		.category = QUEST_CATEGORY_STORY,
		.startmap = sQuestMap_Intro,
		.startdesc = sQuestDesc_Intro,
		.desc = {sQuestDesc_Intro},
		.donedesc = sQuestDone_Intro,
		.map = {sQuestMap_Intro},
		.sprite = {ITEM_POKE_BALL},
		.spritetype = {ITEM},
		.availType = QUEST_AVAIL_ALWAYS,
		.rewardItem = ITEM_POKE_BALL,
		.rewardQty = 10,
	},
	[QUEST_SHINY_PICHU_EGG] =
	{
		.name = sQuestName_ShinyPichuEgg,
		.category = QUEST_CATEGORY_SIDE,
		.startmap = sQuestStartMap_ShinyPichuEgg,
		.startdesc = sQuestStart_ShinyPichuEgg,
		.desc = {sQuestDesc_ShinyPichuEgg},
		.donedesc = sQuestDone_ShinyPichuEgg,
		.map = {sQuestMap_ShinyPichuEgg},
		.sprite = {SPECIES_EGG},
		.spritetype = {PKMN},
		.subquests = NULL,
		.numSubquests = 0,
		.questVariable = 0,
		.availType = QUEST_AVAIL_POSTGAME,
		.rewardItem = ITEM_LIGHT_BALL,
		.rewardQty = 1,
	},
	[QUEST_HEATRAN] =
	{
		.name = sQuestName_Heatran,
		.category = QUEST_CATEGORY_POKEMON,
		.startmap = sQuestStartMap_Heatran,
		.startdesc = sQuestStart_Heatran,
		.desc = {sQuestDesc_Heatran},
		.donedesc = sQuestDone_Heatran,
		.map = {sQuestMap_Heatran},
		.sprite = {SPECIES_HEATRAN},
		.spritetype = {PKMN},
		.subquests = NULL,
		.numSubquests = 0,
		.questVariable = 0,
		.availType = QUEST_AVAIL_POSTGAME,
	},
	[QUEST_REGIGIGAS] =
	{
		.name = sQuestName_Regigigas,
		.category = QUEST_CATEGORY_POKEMON,
		.startmap = sQuestStartMap_Regigigas,
		.startdesc = sQuestStart_Regigigas,
		.desc = {sQuestDesc_Regigigas},
		.donedesc = sQuestDone_Regigigas,
		.map = {sQuestMap_Regigigas},
		.sprite = {SPECIES_REGIGIGAS},
		.spritetype = {PKMN},
		.subquests = NULL,
		.numSubquests = 0,
		.questVariable = 0,
		.availType = QUEST_AVAIL_POSTGAME,
	},
};
////////////////////////END QUEST CUSTOMIZATION////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//BG layer defintions
static const struct BgTemplate sQuestMenuBgTemplates[2] =
{
	{
		//All text and content is loaded to this window
		.bg = 0,
		.charBaseIndex = 0,
		.mapBaseIndex = 31,
		.priority = 1
	},
	{
		///Backgrounds and UI elements are loaded to this window
		.bg = 1,
		.charBaseIndex = 3,
		.mapBaseIndex = 30,
		.priority = 2
	}
};

//Window definitions
static const struct WindowTemplate sQuestMenuHeaderWindowTemplates[] =
{
	{
		//0: Content window
		.bg = 0,
		.tilemapLeft = 0,
		.tilemapTop = 2,
		.width = 30,
		.height = 8,
		.paletteNum = 15,
		.baseBlock = 1
	},
	{
		//1: Footer window
		.bg = 0,
		.tilemapLeft = 0,
		.tilemapTop = 12,
		.width = 30,
		.height = 8,
		.paletteNum = 15,
		.baseBlock = 241
	},
	{
		// 2: Header window
		.bg = 0,
		.tilemapLeft = 0,
		.tilemapTop = 0,
		.width = 30,
		.height = 2,
		.paletteNum = 15,
		.baseBlock = 481
	},
	{
		// 3: Story category card
		.bg = 0,
		.tilemapLeft = 1,
		.tilemapTop = QUEST_HUB_CARD_TOP,
		.width = 8,
		.height = 7,
		.paletteNum = 15,
		.baseBlock = 541
	},
	{
		// 4: Pokémon category card
		.bg = 0,
		.tilemapLeft = 11,
		.tilemapTop = QUEST_HUB_CARD_TOP,
		.width = 8,
		.height = 7,
		.paletteNum = 15,
		.baseBlock = 597
	},
	{
		// 5: Side category card
		.bg = 0,
		.tilemapLeft = 21,
		.tilemapTop = QUEST_HUB_CARD_TOP,
		.width = 8,
		.height = 7,
		.paletteNum = 15,
		.baseBlock = 653
	},
	{
		// 6: Category description front buffer
		.bg = 0,
		.tilemapLeft = 2,
		.tilemapTop = 13,
		.width = 25,
		.height = 6,
		.paletteNum = 15,
		.baseBlock = 709
	},
	{
		// 7: Category description back buffer
		.bg = 0,
		.tilemapLeft = 2,
		.tilemapTop = 13,
		.width = 25,
		.height = 6,
		.paletteNum = 15,
		.baseBlock = 859
	},
	DUMMY_WIN_TEMPLATE
};

// Dedicated dark text/window palette. Slots 10-13 are used as the dashboard's
// panel, elevated panel, border, and gold focus colors respectively.
static const u16 sQuestMenuWindowPal[16] =
{
	[TEXT_COLOR_TRANSPARENT] = RGB(0, 0, 0),
	[TEXT_COLOR_WHITE] = RGB(31, 31, 31),
	[TEXT_COLOR_DARK_GRAY] = RGB(19, 21, 25),
	[TEXT_COLOR_LIGHT_GRAY] = RGB(10, 12, 16),
	[TEXT_COLOR_RED] = RGB(31, 9, 7),
	[TEXT_COLOR_LIGHT_RED] = RGB(31, 23, 9),
	[TEXT_COLOR_GREEN] = RGB(8, 26, 14),
	[TEXT_COLOR_LIGHT_GREEN] = RGB(15, 31, 20),
	[TEXT_COLOR_BLUE] = RGB(8, 18, 31),
	[TEXT_COLOR_LIGHT_BLUE] = RGB(16, 25, 31),
	[QUEST_WINDOW_COLOR_PANEL] = RGB(4, 6, 9),
	[QUEST_WINDOW_COLOR_PANEL_SELECTED] = RGB(2, 3, 5),
	[QUEST_WINDOW_COLOR_BORDER] = RGB(7, 9, 13),
	[QUEST_WINDOW_COLOR_ACCENT] = RGB(30, 21, 7),
	[14] = RGB(22, 23, 25),
	[15] = RGB(0, 0, 0),
};

// Cards use the same pixel data in both states. Switching only their tilemap
// palette gives the selected card its gold border and elevated slate fill,
// avoiding visible tile uploads during navigation.
static const u16 sQuestMenuSelectedCardPal[16] =
{
	[TEXT_COLOR_TRANSPARENT] = RGB(0, 0, 0),
	[TEXT_COLOR_WHITE] = RGB(31, 23, 9),
	[TEXT_COLOR_DARK_GRAY] = RGB(19, 21, 25),
	[TEXT_COLOR_LIGHT_GRAY] = RGB(10, 12, 16),
	[TEXT_COLOR_RED] = RGB(31, 9, 7),
	[TEXT_COLOR_LIGHT_RED] = RGB(31, 23, 9),
	[TEXT_COLOR_GREEN] = RGB(8, 26, 14),
	[TEXT_COLOR_LIGHT_GREEN] = RGB(15, 31, 20),
	[TEXT_COLOR_BLUE] = RGB(8, 18, 31),
	[TEXT_COLOR_LIGHT_BLUE] = RGB(16, 25, 31),
	[QUEST_WINDOW_COLOR_PANEL] = RGB(7, 10, 14),
	[QUEST_WINDOW_COLOR_PANEL_SELECTED] = RGB(2, 3, 5),
	[QUEST_WINDOW_COLOR_BORDER] = RGB(30, 21, 7),
	[QUEST_WINDOW_COLOR_ACCENT] = RGB(30, 21, 7),
	[14] = RGB(22, 23, 25),
	[15] = RGB(0, 0, 0),
};

//Font color combinations for printed text
static const u8 sQuestMenuWindowFontColors[][4] =
{
	{
		//Header of Quest Menu
		TEXT_COLOR_TRANSPARENT,
		TEXT_COLOR_DARK_GRAY,
		TEXT_COLOR_TRANSPARENT
	},
	{
		//Reward state progress indicator
		TEXT_COLOR_TRANSPARENT,
		TEXT_COLOR_RED,
		TEXT_COLOR_TRANSPARENT
	},
	{
		//Done state progress indicator
		TEXT_COLOR_TRANSPARENT,
		TEXT_COLOR_GREEN,
		TEXT_COLOR_TRANSPARENT
	},
	{
		//Active state progress indicator
		TEXT_COLOR_TRANSPARENT,
		TEXT_COLOR_BLUE,
		TEXT_COLOR_TRANSPARENT
	},
	{
		//Footer flavor text
		TEXT_COLOR_TRANSPARENT,
		TEXT_COLOR_WHITE,
		TEXT_COLOR_TRANSPARENT
	},
	{
		//Selected category card / gold accent text
		TEXT_COLOR_TRANSPARENT,
		TEXT_COLOR_LIGHT_RED,
		TEXT_COLOR_TRANSPARENT
	},
	{
		//Muted dashboard helper text
		TEXT_COLOR_TRANSPARENT,
		TEXT_COLOR_LIGHT_GRAY,
		TEXT_COLOR_TRANSPARENT
	},
};

//Functions begin here

//ported from firered by ghoulslash
void QuestMenu_Init(u8 a0, MainCallback callback)
{
	u8 i;

	if (a0 >= 2)
	{
		SetMainCallback2(callback);
		return;
	}

	// Refresh count/dex goals so any newly-met ones show "Reward Available".
	QuestMenu_TryAdvanceConditionalQuests();

	if ((sStateDataPtr = Alloc(sizeof(struct QuestMenuResources))) == NULL)
	{
		SetMainCallback2(callback);
		return;
	}

	if (a0 != 1)
	{
		sListMenuState.savedCallback = callback;
		sListMenuState.scroll = sListMenuState.row = 0;
	}

	sStateDataPtr->moveModeOrigPos = 0xFF;
	sStateDataPtr->spriteIconSlot = 0;
	sStateDataPtr->scrollIndicatorArrowPairId = 0xFF;
	sStateDataPtr->savedCallback = 0;
	sStateDataPtr->oldPaletteTag = 0;
	sStateDataPtr->filterMode = SORT_DEFAULT;
	sStateDataPtr->parentQuest = 0;
	sStateDataPtr->menuPage = QUEST_MENU_PAGE_HUB;
	sStateDataPtr->category = QUEST_CATEGORY_STORY;
	sStateDataPtr->hubDescSlot = 0;
	sStateDataPtr->hubGraphicsReady = FALSE;
	sStateDataPtr->restoreCursor = FALSE;
	for (i = 0; i < 3; i++)
	{
		sStateDataPtr->data[i] = 0;
	}
	for (i = 0; i < QUEST_CATEGORY_COUNT; i++)
	{
		sStateDataPtr->categorySpriteIds[i] = 0xFF;
	}

	SetMainCallback2(RunSetup);
}

static void MainCB(void)
{
	RunTasks();
	AnimateSprites();
	BuildOamBuffer();
	DoScheduledBgTilemapCopiesToVram();
	UpdatePaletteFade();
}

static void VBlankCB(void)
{
	LoadOam();
	ProcessSpriteCopyRequests();
	TransferPlttBuffer();
}

static void RunSetup(void)
{
	while (1)
	{
		if (SetupGraphics() == TRUE)
		{
			break;
		}
	}
}

static bool8 SetupGraphics(void)
{
	switch (gMain.state)
	{
		case 0:
			SetVBlankHBlankCallbacksToNull();
			ClearScheduledBgCopiesToVram();
			gMain.state++;
			break;
		case 1:
			ScanlineEffect_Stop();
			gMain.state++;
			break;
		case 2:
			FreeAllSpritePalettes();
			gMain.state++;
			break;
		case 3:
			ResetPaletteFade();
			gMain.state++;
			break;
		case 4:
			ResetSpriteData();
			gMain.state++;
			break;
		case 5:
			ResetSpriteState();
			gMain.state++;
			break;
		case 6:
			ResetTasks();
			gMain.state++;
			break;
		case 7:
			if (InitBackgrounds())
			{
				sStateDataPtr->data[0] = 0;
				gMain.state++;
			}
			else
			{
				FadeAndBail();
				return TRUE;
			}
			break;
		case 8:
			if (LoadGraphics() == TRUE)
			{
				gMain.state++;
			}
			break;
		case 9:
			QuestMenu_InitWindows();
			gMain.state++;
			break;
		case 10:
			ClearModeOnStartup();
			sListMenuState.scroll = 0;
			sListMenuState.row = 0;
			gMain.state++;
			break;
		case 11:
			gMain.state++;
			break;
		case 12:
			if (AllocateMemoryForArray())
			{
				gMain.state++;
			}
			else
			{
				FadeAndBail();
				return TRUE;
			}
			break;
		case 13:
			CreateCategorySprites();
			ShowCategoryHub();
			gMain.state++;
			break;
		case 14:
			gMain.state++;
			break;
		case 15:
			CreateTask(Task_CategoryMain, 0);
			gMain.state++;
			break;
		case 16:
			gMain.state++;
			break;
		case 17:
			gMain.state++;
			break;
		case 18:
			if (sListMenuState.initialized == 1)
			{
				BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
			}
			gMain.state++;
			break;
		case 19:
			if (sListMenuState.initialized == 1)
			{
				BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
			}
			else
			{

				BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
				SetInitializedFlag(1);
			}
			gMain.state++;
			break;
		default:
			SetVBlankCallback(VBlankCB);
			SetMainCallback2(MainCB);
			return TRUE;
	}
	return FALSE;
}

static bool8 LoadGraphics(void)
{
	switch (sStateDataPtr->data[0])
	{
		case 0:
			ResetTempTileDataBuffers();
			DecompressAndCopyTileDataToVram(1, sQuestMenuTiles, 0, 0, 0);
			sStateDataPtr->data[0]++;
			break;
		case 1:
			if (FreeTempTileDataBuffersIfPossible() != TRUE)
			{
				DecompressDataWithHeaderWram(sQuestMenuTilemap, sBg1TilemapBuffer);
				sStateDataPtr->data[0]++;
			}
			break;
		case 2:
			LoadBgTiles(1, sQuestHubBgTile, sizeof(sQuestHubBgTile),
			            QUEST_HUB_BG_PANEL_TILE);
			LoadPalette(sQuestMenuBgPals, BG_PLTT_ID(0), sizeof(sQuestMenuBgPals));
			LoadPalette(sQuestMenuSelectedCardPal, BG_PLTT_ID(14),
			            sizeof(sQuestMenuSelectedCardPal));
			LoadPalette(sQuestMenuWindowPal, BG_PLTT_ID(15), sizeof(sQuestMenuWindowPal));
			sStateDataPtr->data[0]++;
			break;
		case 3:
			sStateDataPtr->data[0]++;
			break;
		default:
			sStateDataPtr->data[0] = 0;
			return TRUE;
	}
	return FALSE;
}

static void QuestMenu_InitWindows(void)
{
	u8 i;

	InitWindows(sQuestMenuHeaderWindowTemplates);
	DeactivateAllTextPrinters();

	for (i = 0; i < ARRAY_COUNT(sQuestMenuHeaderWindowTemplates) - 1; i++)
	{
		FillWindowPixelBuffer(i, 0x00);
		ClearWindowTilemap(i);
	}

	ScheduleBgCopyTilemapToVram(0);
}

static bool8 InitBackgrounds(void)
{
	ResetAllBgsCoordinates();
	sBg1TilemapBuffer = Alloc(0x800);
	if (sBg1TilemapBuffer == NULL)
	{
		return FALSE;
	}

	memset(sBg1TilemapBuffer, 0, 0x800);
	ResetBgsAndClearDma3BusyFlags(0);
	InitBgsFromTemplates(0, sQuestMenuBgTemplates,
	                     NELEMS(sQuestMenuBgTemplates));
	SetBgTilemapBuffer(1, sBg1TilemapBuffer);
	ScheduleBgCopyTilemapToVram(1);
	SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
	SetGpuReg(REG_OFFSET_BLDCNT, 0);
	ShowBg(0);
	ShowBg(1);
	return TRUE;
}

static void Task_CategoryMain(u8 taskId)
{
	u8 oldCategory;

	if (gPaletteFade.active)
		return;

	oldCategory = sStateDataPtr->category;
	if (JOY_REPEAT(DPAD_LEFT))
	{
		if (sStateDataPtr->category == QUEST_CATEGORY_STORY)
			sStateDataPtr->category = QUEST_CATEGORY_SIDE;
		else
			sStateDataPtr->category--;
	}
	else if (JOY_REPEAT(DPAD_RIGHT))
	{
		sStateDataPtr->category++;
		if (sStateDataPtr->category >= QUEST_CATEGORY_COUNT)
			sStateDataPtr->category = QUEST_CATEGORY_STORY;
	}

	if (oldCategory != sStateDataPtr->category)
	{
		PlaySE(SE_RG_BAG_CURSOR);
		sStateDataPtr->hubDescSlot ^= 1;
		DrawCategoryDescription(sStateDataPtr->category,
		                        sStateDataPtr->hubDescSlot);
		UpdateCategoryHubSelection();
	}

	if (JOY_NEW(A_BUTTON))
	{
		PlaySE(SE_SELECT);
		// A short accelerated fade makes the dashboard resolve into the selected
		// list as one intentional transition, while B-to-hub remains immediate.
		BeginNormalPaletteFade(0xFFFFFFFF, -1, 0, 16, RGB_BLACK);
		gTasks[taskId].func = Task_OpenCategoryListFadeOut;
	}
	else if (JOY_NEW(B_BUTTON))
	{
		PlaySE(SE_SELECT);
		TurnOffQuestMenu(taskId);
	}
}

static void ShowCategoryHub(void)
{
	ClearWindowTilemap(0);
	ClearWindowTilemap(1);
	sStateDataPtr->menuPage = QUEST_MENU_PAGE_HUB;
	sStateDataPtr->filterMode = SORT_DEFAULT;
	sListMenuState.scroll = 0;
	sListMenuState.row = 0;
	SetCategorySpritesVisible(TRUE);
	DrawCategoryHub();
}

static void DrawCategoryHub(void)
{
	u8 x;
	u8 category;

	DrawCategoryHubBackground();

	// The hub owns its header pixels, so none of the list screen's gold rule can
	// show through beneath it.
	FillWindowPixelBuffer(2, PIXEL_FILL(QUEST_WINDOW_COLOR_PANEL));
	PutWindowTilemap(2);
	QuestMenu_AddTextPrinterParameterized(2, 0, sText_QuestLog, 8, 1,
	                                      0, 1, 0, 5);
	x = 232 - GetStringWidth(0, sText_ChooseCategory, 0);
	QuestMenu_AddTextPrinterParameterized(2, 0, sText_ChooseCategory, x, 1,
	                                      0, 1, 0, 6);
	CopyWindowToVram(2, COPYWIN_GFX);

	// These tiles live above the list windows' VRAM range. Once uploaded they
	// survive category-list visits, making B-to-hub a lightweight tilemap swap.
	if (!sStateDataPtr->hubGraphicsReady)
	{
		for (category = 0; category < QUEST_CATEGORY_COUNT; category++)
			DrawCategoryCard(category);
		sStateDataPtr->hubDescSlot = 0;
		DrawCategoryDescription(sStateDataPtr->category,
		                        sStateDataPtr->hubDescSlot);
		sStateDataPtr->hubGraphicsReady = TRUE;
	}

	UpdateCategoryHubSelection();
}

static void DrawCategoryHubBackground(void)
{
	FillBgTilemapBufferRect(1, QUEST_HUB_BG_PANEL_TILE,
	                        0, 2, 30, 18, 15);
	ScheduleBgCopyTilemapToVram(1);
}

static void UpdateCategoryHubSelection(void)
{
	u8 category;
	u8 windowId;
	u8 spriteId;
	bool8 selected;

	// Compose the complete next layout in the BG0 tilemap buffer, then submit a
	// single VBlank copy. There is never a frame where a card has been erased but
	// its replacement has not arrived yet.
	FillBgTilemapBufferRect(0, 0, 0, 2, 30, 10, 0);
	for (category = 0; category < QUEST_CATEGORY_COUNT; category++)
	{
		windowId = QUEST_HUB_CARD_FIRST_WINDOW + category;
		selected = category == sStateDataPtr->category;
		SetWindowAttribute(windowId, WINDOW_TILEMAP_TOP,
		                   selected ? QUEST_HUB_CARD_SELECTED_TOP
		                            : QUEST_HUB_CARD_TOP);
		SetWindowAttribute(windowId, WINDOW_PALETTE_NUM,
		                   selected ? 14 : 15);
		PutWindowTilemap(windowId);

		// Cards move by one tile, so their icons move by the same eight pixels in
		// the same update. No independent easing or visual separation.
		spriteId = sStateDataPtr->categorySpriteIds[category];
		if (spriteId < MAX_SPRITES)
			gSprites[spriteId].y2 = selected ? QUEST_HUB_ICON_SELECTED_Y
			                                  : QUEST_HUB_ICON_Y;
	}
	PutWindowTilemap(QUEST_HUB_DESC_FIRST_WINDOW
	                 + sStateDataPtr->hubDescSlot);
	ScheduleBgCopyTilemapToVram(0);
}

static void DrawCategoryCard(u8 category)
{
	u8 windowId = QUEST_HUB_CARD_FIRST_WINDOW + category;
	u8 x;

	FillWindowPixelBuffer(windowId, PIXEL_FILL(QUEST_WINDOW_COLOR_BORDER));
	FillWindowPixelRect(windowId, PIXEL_FILL(QUEST_WINDOW_COLOR_PANEL),
	                    2, 2, 60, 52);

	x = GetStringCenterAlignXOffset(2, sQuestCategoryCardNames[category], 64);
	QuestMenu_AddTextPrinterParameterized(windowId, 2,
	                                      sQuestCategoryCardNames[category],
	                                      x, 5, 0, 0, 0, 4);
	x = GetStringCenterAlignXOffset(2, sText_Quests, 64);
	QuestMenu_AddTextPrinterParameterized(windowId, 2, sText_Quests,
	                                      x, 17, 0, 0, 0, 4);
	CopyWindowToVram(windowId, COPYWIN_GFX);
}

static void DrawCategoryDescription(u8 category, u8 slot)
{
	u8 windowId = QUEST_HUB_DESC_FIRST_WINDOW + slot;
	u8 completed = CountCompletedQuestsInCategory(category);
	u8 available = CountAvailableQuestsInCategory(category);
	const u8 *progressText;
	u8 x;

	FillWindowPixelBuffer(windowId,
	                      PIXEL_FILL(QUEST_WINDOW_COLOR_BORDER));
	FillWindowPixelRect(windowId,
	                    PIXEL_FILL(QUEST_WINDOW_COLOR_PANEL), 2, 2, 196, 44);

	QuestMenu_AddTextPrinterParameterized(windowId, 0,
	                                      sQuestCategoryNames[category],
	                                      8, 3, 0, 1, 0, 5);
	if (available == 0)
	{
		progressText = sText_NoCategoryQuests;
	}
	else
	{
		ConvertIntToDecimalStringN(gStringVar1, completed,
		                           STR_CONV_MODE_LEFT_ALIGN, 2);
		ConvertIntToDecimalStringN(gStringVar2, available,
		                           STR_CONV_MODE_LEFT_ALIGN, 2);
		StringExpandPlaceholders(gStringVar4, sText_CategoryProgress);
		progressText = gStringVar4;
	}
	x = 192 - GetStringWidth(0, progressText, 0);
	QuestMenu_AddTextPrinterParameterized(windowId, 0,
	                                      progressText, x, 3, 0, 1, 0, 6);
	QuestMenu_AddTextPrinterParameterized(windowId, 2,
	                                      sQuestCategoryDescriptions[category],
	                                      8, 18, 0, 0, 0, 4);
	CopyWindowToVram(windowId, COPYWIN_GFX);
}

static void CreateCategorySprites(void)
{
	u8 category;
	u8 spriteId;

	for (category = 0; category < QUEST_CATEGORY_COUNT; category++)
	{
		spriteId = AddItemIconSprite(QUEST_CATEGORY_ICON_TAG_BASE + category,
		                             QUEST_CATEGORY_ICON_TAG_BASE + category,
		                             sQuestCategoryIconItems[category]);
		if (spriteId < MAX_SPRITES)
		{
			sStateDataPtr->categorySpriteIds[category] = spriteId;
			gSprites[spriteId].x2 = 40 + category * 80;
			gSprites[spriteId].y2 = category == sStateDataPtr->category
			                         ? QUEST_HUB_ICON_SELECTED_Y
			                         : QUEST_HUB_ICON_Y;
			gSprites[spriteId].oam.priority = 0;
		}
	}
}

static void DestroyCategorySprites(void)
{
	u8 category;
	u8 spriteId;

	if (sStateDataPtr == NULL)
		return;

	for (category = 0; category < QUEST_CATEGORY_COUNT; category++)
	{
		spriteId = sStateDataPtr->categorySpriteIds[category];
		if (spriteId < MAX_SPRITES)
		{
			DestroySprite(&gSprites[spriteId]);
			FreeSpriteTilesByTag(QUEST_CATEGORY_ICON_TAG_BASE + category);
			FreeSpritePaletteByTag(QUEST_CATEGORY_ICON_TAG_BASE + category);
			sStateDataPtr->categorySpriteIds[category] = 0xFF;
		}
	}
}

static void SetCategorySpritesVisible(bool8 visible)
{
	u8 category;
	u8 spriteId;

	for (category = 0; category < QUEST_CATEGORY_COUNT; category++)
	{
		spriteId = sStateDataPtr->categorySpriteIds[category];
		if (spriteId < MAX_SPRITES)
			gSprites[spriteId].invisible = !visible;
	}
}

static void OpenCategoryList(u8 taskId)
{
	s16 *data = gTasks[taskId].data;
	u8 windowId;

	for (windowId = QUEST_HUB_CARD_FIRST_WINDOW;
	     windowId <= QUEST_HUB_LAST_WINDOW; windowId++)
		ClearWindowTilemap(windowId);
	SetCategorySpritesVisible(FALSE);
	DecompressDataWithHeaderWram(sQuestMenuTilemap, sBg1TilemapBuffer);
	ScheduleBgCopyTilemapToVram(1);

	for (windowId = 0; windowId < QUEST_HUB_CARD_FIRST_WINDOW; windowId++)
	{
		if (windowId == 1)
			ClearQuestDetailsWindow();
		else
			FillWindowPixelBuffer(windowId, 0);
		PutWindowTilemap(windowId);
		CopyWindowToVram(windowId, COPYWIN_FULL);
	}

	sStateDataPtr->menuPage = QUEST_MENU_PAGE_LIST;
	sStateDataPtr->filterMode = SORT_DEFAULT;
	sStateDataPtr->restoreCursor = FALSE;
	sListMenuState.scroll = 0;
	sListMenuState.row = 0;
	InitItems();

	if (!AllocateResourcesForListMenu())
	{
		PlaySE(SE_BOO);
		ShowCategoryHub();
		gTasks[taskId].func = Task_CategoryMain;
		return;
	}

	BuildMenuTemplate();
	GenerateAndPrintHeader();
	data[0] = ListMenuInit(&gMultiuseListMenuTemplate, 0, 0);
	PlaceTopMenuScrollIndicatorArrows();
	ScheduleBgCopyTilemapToVram(0);
	gTasks[taskId].func = Task_Main;
}

static void Task_OpenCategoryListFadeOut(u8 taskId)
{
	if (gPaletteFade.active)
		return;

	// Rebuild while the screen is fully dark, so no intermediate list or footer
	// tiles are exposed to the player.
	OpenCategoryList(taskId);
	BeginNormalPaletteFade(0xFFFFFFFF, -1, 16, 0, RGB_BLACK);
	gTasks[taskId].func = Task_OpenCategoryListFadeIn;
}

static void Task_OpenCategoryListFadeIn(u8 taskId)
{
	if (gPaletteFade.active)
		return;

	if (sStateDataPtr->menuPage == QUEST_MENU_PAGE_LIST)
		gTasks[taskId].func = Task_Main;
	else
		gTasks[taskId].func = Task_CategoryMain;
}

static void ReturnToCategoryHub(u8 taskId)
{
	s16 *data = gTasks[taskId].data;
	u8 windowId;

	QuestMenu_RemoveScrollIndicatorArrowPair();
	DestroyListMenuTask(data[0], &sListMenuState.scroll, &sListMenuState.row);
	if (sListMenuItems != NULL)
	{
		Free(sListMenuItems);
		sListMenuItems = NULL;
	}
	QuestMenu_DestroySprite(0);
	QuestMenu_DestroySprite(1);

	for (windowId = 0; windowId < QUEST_HUB_CARD_FIRST_WINDOW; windowId++)
		ClearWindowTilemap(windowId);

	ShowCategoryHub();
	gTasks[taskId].func = Task_CategoryMain;
}

static void InitItems(void)
{
	sStateDataPtr->nItems = (CountNumberListRows()) - 1;

	sStateDataPtr->maxShowed = sStateDataPtr->nItems + 1 <= 4 ?
	                           sStateDataPtr->nItems + 1 : 4;
}

static bool8 AllocateResourcesForListMenu(void)
{
	sListMenuItems = Alloc(sizeof(*sListMenuItems) * CountNumberListRows());
	return sListMenuItems != NULL;
}

static bool8 AllocateMemoryForArray(void)
{
	u8 i;
	u8 allocateRows = QUEST_ARRAY_COUNT + 1;

	questNameArray = AllocZeroed(sizeof(*questNameArray) * allocateRows);
	if (questNameArray == NULL)
		return FALSE;

	for (i = 0; i < allocateRows; i++)
	{
		questNameArray[i] = Alloc(QUEST_NAME_BUFFER_SIZE);
		if (questNameArray[i] == NULL)
			return FALSE;
		questNameArray[i][0] = EOS;
	}

	return TRUE;
}

static void PlaceTopMenuScrollIndicatorArrows(void)
{
	u8 listSize = CountNumberListRows();

	if (listSize < sStateDataPtr->maxShowed)
	{
		listSize = sStateDataPtr->maxShowed;
	}

	sStateDataPtr->scrollIndicatorArrowPairId =
	      AddScrollIndicatorArrowPairParameterized(2, 94, 8, 90,
	                  (listSize - sStateDataPtr->maxShowed), 110, 110, &sListMenuState.scroll);
}

static void SetInitializedFlag(u8 a0)
{
	sListMenuState.initialized = a0;
}

static u8 GetCursorPosition(void)
{
	return sListMenuState.scroll + sListMenuState.row;
}

static void SaveScrollAndRow(s16 *data)
{
	ListMenuGetScrollAndRow(data[0], &sListMenuState.storedScrollOffset,
	                        &sListMenuState.storedRowPosition);
}


void ClearModeOnStartup(void)
{
	sStateDataPtr->filterMode = 0;
}

static u8 ManageMode(u8 action)
{
	u8 mode = sStateDataPtr->filterMode;

	switch (action)
	{
		case SUB:
			mode = ToggleSubquestMode(mode);
			break;

		case ALPHA:
			mode = ToggleAlphaMode(mode);
			sStateDataPtr->restoreCursor = FALSE;
			break;

		default:
			mode = IncrementMode(mode);
			sStateDataPtr->restoreCursor = FALSE;
			break;
	}
	return mode;
}

u8 ToggleSubquestMode(u8 mode)
{
	if (IsSubquestMode())
	{
		mode -= SORT_SUBQUEST;
		sStateDataPtr->restoreCursor = TRUE;
	}
	else
	{
		mode += SORT_SUBQUEST;
		sStateDataPtr->restoreCursor = FALSE;
	}

	return mode;
}

u8 ToggleAlphaMode(u8 mode)
{
	if (IsAlphaMode())
	{
		mode -= SORT_DEFAULT_AZ;
	}
	else
	{
		mode += SORT_DEFAULT_AZ;
	}

	return mode;
}

u8 IncrementMode(u8 mode)
{
	if (mode % 10 == SORT_DONE)
	{
		mode -= SORT_DONE;
	}
	else
	{
		mode++;
	}

	return mode;
}

static bool8 IsSubquestMode(void)
{
	if (sStateDataPtr->filterMode > SORT_DONE_AZ)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

static bool8 IsNotFilteredMode(void)
{
	u8 mode = sStateDataPtr->filterMode % 10;

	if (mode == FLAG_GET_UNLOCKED)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

static bool8 IsAlphaMode(void)
{
	if (sStateDataPtr->filterMode < SORT_SUBQUEST
	            && sStateDataPtr->filterMode > SORT_DONE)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

static void BuildMenuTemplate(void)
{
	u8 lastRow = GetModeAndGenerateList();

	AssignCancelNameAndId(lastRow);

	gMultiuseListMenuTemplate.totalItems = CountNumberListRows();
	gMultiuseListMenuTemplate.items = sListMenuItems;
	gMultiuseListMenuTemplate.windowId = 0;
	gMultiuseListMenuTemplate.header_X = 0;
	gMultiuseListMenuTemplate.cursor_X = 15;
	gMultiuseListMenuTemplate.item_X = 23;
	gMultiuseListMenuTemplate.lettersSpacing = 1;
	gMultiuseListMenuTemplate.itemVerticalPadding = 2;
	gMultiuseListMenuTemplate.upText_Y = 2;
	gMultiuseListMenuTemplate.maxShowed = sStateDataPtr->maxShowed;
	gMultiuseListMenuTemplate.fontId = 2;
	gMultiuseListMenuTemplate.cursorPal = 2;
	gMultiuseListMenuTemplate.fillValue = 0;
	gMultiuseListMenuTemplate.cursorShadowPal = 0;
	gMultiuseListMenuTemplate.moveCursorFunc = MoveCursorFunc;
	gMultiuseListMenuTemplate.itemPrintFunc = GenerateStateAndPrint;
	gMultiuseListMenuTemplate.scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD;
	gMultiuseListMenuTemplate.cursorKind = 0;
}

u8 GetModeAndGenerateList()
{
	if (IsSubquestMode())
	{
		return GenerateSubquestList();
	}
	else
	{
		return GenerateList(!IsNotFilteredMode());
	}
}

static u8 CountNumberListRows()
{
	u8 mode = sStateDataPtr->filterMode % 10;

	if (IsSubquestMode())
	{
		return sSideQuests[sStateDataPtr->parentQuest].numSubquests + 1;
	}

	switch (mode)
	{
		case SORT_DEFAULT:
			return CountAvailableQuests() + 1;
		case SORT_INACTIVE:
			return CountInactiveQuests() + 1;
		case SORT_ACTIVE:
			return CountActiveQuests() + 1;
		case SORT_REWARD:
			return CountRewardQuests() + 1;
		case SORT_DONE:
			return CountCompletedQuests() + 1;
	}
	
	return 1;
}

u8 *DefineQuestOrder()
{
	static u8 sortedList[QUEST_COUNT];
	u8 a, c, d;
	u8 placeholderVariable;

	for (a = 0; a < QUEST_COUNT; a++)
	{
		sortedList[a] = a;
	}

	if (IsAlphaMode())
	{
		for (c = 0; c < QUEST_COUNT; c++)
		{
			for (d = c + 1; d < QUEST_COUNT; d++)
			{
				if (StringCompare(sSideQuests[sortedList[c]].name,
				                  sSideQuests[sortedList[d]].name) > 0)
				{
					placeholderVariable = sortedList[c];
					sortedList[c] = sortedList[d];
					sortedList[d] = placeholderVariable;
				}
			}
		}
	}

	return sortedList;
}

u8 GenerateSubquestList()
{
	u8 parentQuest = sStateDataPtr->parentQuest;
	u8 lastRow = 0, numRow = 0, countQuest = 0;

	for (numRow = 0; numRow < sSideQuests[parentQuest].numSubquests; numRow++)
	{
		PrependQuestNumber(countQuest);
		PopulateSubquestName(parentQuest, countQuest);
		PopulateListRowNameAndId(numRow, countQuest);

		countQuest++;
		lastRow = numRow + 1;
	}
	return lastRow;
}

// Each quest decides for itself when it appears in the menu. FLAG_LEGENDARY_BTL
// is set at new game and cleared on becoming Champion (the same flag that unhides
// every legendary quest-giver NPC), so a cleared flag means "post-game is live."
bool8 QuestMenu_IsQuestAvailable(u8 questId)
{
	switch (sSideQuests[questId].availType)
	{
		case QUEST_AVAIL_FLAG_SET:
			return FlagGet(sSideQuests[questId].availFlag);
		case QUEST_AVAIL_POSTGAME:
			return !FlagGet(FLAG_LEGENDARY_BTL);
		case QUEST_AVAIL_ALWAYS:
		default:
			return TRUE;
	}
}

static bool8 QuestMenu_IsQuestInCurrentCategory(u8 questId)
{
	return sSideQuests[questId].category == sStateDataPtr->category;
}

u8 GenerateList(bool8 isFiltered)
{
	u8 mode = sStateDataPtr-> filterMode % 10;
	u8 numRow = 0, offset = 0, newRow = 0, countQuest = 0,
	   selectedQuestId = 0;
	u8 *sortedQuestList;

	sortedQuestList = DefineQuestOrder();

	for (countQuest = 0; countQuest < QUEST_COUNT; countQuest++)
	{
		selectedQuestId = *(sortedQuestList + countQuest);

		if (!QuestMenu_IsQuestAvailable(selectedQuestId))
		{
			continue;
		}
		if (!QuestMenu_IsQuestInCurrentCategory(selectedQuestId))
		{
			continue;
		}

		if (isFiltered && !QuestMenu_GetSetQuestState(selectedQuestId, mode))
		{
			continue;
		}

		PopulateEmptyRow(selectedQuestId);

		if (QuestMenu_GetSetQuestState(selectedQuestId, FLAG_GET_FAVORITE))
		{
			SetFavoriteQuest(selectedQuestId);
			newRow = numRow;
			numRow++;
		}
		else
		{
			newRow = CountFavoriteQuests() + offset;
			offset++;
		}

		PopulateQuestName(selectedQuestId);
		PopulateListRowNameAndId(newRow, selectedQuestId);
	}
	return numRow + offset;
}

static void AssignCancelNameAndId(u8 numRow)
{
	if (IsSubquestMode())
	{
		sListMenuItems[numRow].name = sText_Back;
	}
	else if (CountAvailableQuests() == 0)
	{
		// Nothing is available yet; label the sole row so the menu explains
		// itself instead of just showing "Close".
		sListMenuItems[numRow].name = sText_NoQuests;
	}
	else
	{
		sListMenuItems[numRow].name = sText_Back;
	}

	sListMenuItems[numRow].id = LIST_CANCEL;
}

static bool8 QuestMenu_IsQuestIdValid(u8 quest)
{
	return quest < QUEST_COUNT;
}

static bool8 QuestMenu_IsSubquestIdValid(u8 quest, u8 childQuest)
{
	if (!QuestMenu_IsQuestIdValid(quest)
	 || sSideQuests[quest].subquests == NULL
	 || childQuest >= sSideQuests[quest].numSubquests)
		return FALSE;

	return sSideQuests[quest].subquests[childQuest].id < SUB_QUEST_COUNT;
}

static void QuestMenu_ValidateSaveData(void)
{
	if (gSaveBlock3Ptr->questDataMagic != QUEST_SAVE_DATA_MAGIC)
		QuestMenu_ResetMenuSaveData();
}

u8 QuestMenu_GetSetSubquestState(u8 quest, u8 caseId, u8 childQuest)
{
	QuestMenu_ValidateSaveData();
	if (!QuestMenu_IsSubquestIdValid(quest, childQuest))
		return FALSE;

	u8 uniqueId = sSideQuests[quest].subquests[childQuest].id;
	u8  index = uniqueId / 8; //8 bits per byte
	u8	bit = uniqueId % 8;
	u8	mask = 1 << bit;

	switch (caseId)
	{
		case FLAG_GET_COMPLETED:
			return gSaveBlock3Ptr->subQuests[index] & mask;
		case FLAG_SET_COMPLETED:
			gSaveBlock3Ptr->subQuests[index] |= mask;
			return 1;
	}

	return FALSE;
}

u8 QuestMenu_GetSetQuestState(u8 quest, u8 caseId)
{
	QuestMenu_ValidateSaveData();
	if (!QuestMenu_IsQuestIdValid(quest))
		return FALSE;

	u8 index = quest * 5 / 8;
	u8 bit = quest * 5 % 8;
	u8 mask = 0, index2 = 0, bit2 = 0, index3 = 0, bit3 = 0, mask2 = 0,
	   mask3 = 0;

	// 0 : locked
	// 1 : actived
	// 2 : rewarded
	// 3 : completed
	// 4 : favorited

	switch (caseId)
	{
		case FLAG_GET_UNLOCKED:
		case FLAG_SET_UNLOCKED:
			break;
		case FLAG_GET_INACTIVE:
		case FLAG_GET_ACTIVE:
		case FLAG_SET_ACTIVE:
		case FLAG_REMOVE_ACTIVE:
			bit += 1;
			break;
		case FLAG_GET_REWARD:
		case FLAG_SET_REWARD:
		case FLAG_REMOVE_REWARD:
			bit += 2;
			break;
		case FLAG_GET_COMPLETED:
		case FLAG_SET_COMPLETED:
			bit += 3;
			break;
		case FLAG_GET_FAVORITE:
		case FLAG_SET_FAVORITE:
		case FLAG_REMOVE_FAVORITE:
			bit += 4;
			break;
	}
	if (bit >= 8)
	{
		index += 1;
		bit %= 8;
	}
	mask = 1 << bit;

	switch (caseId)
	{
		case FLAG_GET_UNLOCKED:
			return gSaveBlock3Ptr->questData[index] & mask;
		case FLAG_SET_UNLOCKED:
			gSaveBlock3Ptr->questData[index] |= mask;
			return 1;
		case FLAG_GET_INACTIVE:
			bit2 = bit + 1;
			bit3 = bit + 2;
			index2 = index;
			index3 = index;

			if (bit2 >= 8)
			{
				index2 += 1;
				bit2 %= 8;
			}
			if (bit3 >= 8)
			{
				index3 += 1;
				bit3 %= 8;
			}

			mask2 = 1 << bit2;
			mask3 = 1 << bit3;
			return QuestMenu_GetSetQuestState(quest, FLAG_GET_UNLOCKED) && \
			       !(gSaveBlock3Ptr->questData[index] & mask) && \
			       !(gSaveBlock3Ptr->questData[index2] & mask2) && \
			       !(gSaveBlock3Ptr->questData[index3] & mask3);
		case FLAG_GET_ACTIVE:
			return gSaveBlock3Ptr->questData[index] & mask;
		case FLAG_SET_ACTIVE:
			gSaveBlock3Ptr->questData[index] |= mask;
			return 1;
		case FLAG_REMOVE_ACTIVE:
			gSaveBlock3Ptr->questData[index] &= ~mask;
			return 1;
		case FLAG_GET_REWARD:
			return gSaveBlock3Ptr->questData[index] & mask;
		case FLAG_SET_REWARD:
			gSaveBlock3Ptr->questData[index] |= mask;
			return 1;
		case FLAG_REMOVE_REWARD:
			gSaveBlock3Ptr->questData[index] &= ~mask;
			return 1;
		case FLAG_GET_COMPLETED:
			return gSaveBlock3Ptr->questData[index] & mask;
		case FLAG_SET_COMPLETED:
			gSaveBlock3Ptr->questData[index] |= mask;
			return 1;
		case FLAG_GET_FAVORITE:
			return gSaveBlock3Ptr->questData[index] & mask;
		case FLAG_SET_FAVORITE:
			gSaveBlock3Ptr->questData[index] |= mask;
			return 1;
		case FLAG_REMOVE_FAVORITE:
			gSaveBlock3Ptr->questData[index] &= ~mask;
			return 1;
	}
	return FALSE;
}

// Counts quests currently visible in the menu (used for the "x/y" header total
// and the default list length). Only available quests are ever shown or counted.
static u8 CountAvailableQuestsInCategory(u8 category)
{
	u8 q = 0, i = 0;

	for (i = 0; i < QUEST_COUNT; i++)
	{
		if (sSideQuests[i].category == category
		    && QuestMenu_IsQuestAvailable(i))
		{
			q++;
		}
	}
	return q;
}

u8 CountAvailableQuests(void)
{
	return CountAvailableQuestsInCategory(sStateDataPtr->category);
}

u8 CountUnlockedQuests(void)
{
	u8 q = 0, i = 0;

	for (i = 0; i < QUEST_COUNT; i++)
	{
		if (QuestMenu_IsQuestInCurrentCategory(i)
		    && QuestMenu_IsQuestAvailable(i)
		    && QuestMenu_GetSetQuestState(i, FLAG_GET_UNLOCKED))
		{
			q++;
		}
	}
	return q;
}

u8 CountInactiveQuests(void)
{
	u8 q = 0, i = 0;

	// An untouched quest reads as "inactive" (all bits clear), so restrict the
	// count to quests that are actually revealed in the menu.
	for (i = 0; i < QUEST_COUNT; i++)
	{
		if (QuestMenu_IsQuestInCurrentCategory(i)
		    && QuestMenu_IsQuestAvailable(i)
		    && QuestMenu_GetSetQuestState(i, FLAG_GET_INACTIVE))
		{
			q++;
		}
	}
	return q;
}

u8 CountActiveQuests(void)
{
	u8 q = 0, i = 0;

	for (i = 0; i < QUEST_COUNT; i++)
	{
		if (QuestMenu_IsQuestInCurrentCategory(i)
		    && QuestMenu_IsQuestAvailable(i)
		    && QuestMenu_GetSetQuestState(i, FLAG_GET_ACTIVE))
		{
			q++;
		}
	}
	return q;
}

u8 CountRewardQuests(void)
{
	u8 q = 0, i = 0;

	for (i = 0; i < QUEST_COUNT; i++)
	{
		if (QuestMenu_IsQuestInCurrentCategory(i)
		    && QuestMenu_IsQuestAvailable(i)
		    && QuestMenu_GetSetQuestState(i, FLAG_GET_REWARD))
		{
			q++;
		}
	}
	return q;
}

u8 CountCompletedQuests(void)
{
	u8 q = 0, i = 0;

	u8 parentQuest = sStateDataPtr->parentQuest;

	if (IsSubquestMode())
	{
		for (i = 0; i < sSideQuests[parentQuest].numSubquests; i++)
		{
			if (QuestMenu_GetSetSubquestState(parentQuest, FLAG_GET_COMPLETED, i))
			{
				q++;
			}
		}
	}
	else
	{
		for (i = 0; i < QUEST_COUNT; i++)
		{
			if (QuestMenu_IsQuestInCurrentCategory(i)
			    && QuestMenu_IsQuestAvailable(i)
			    && QuestMenu_GetSetQuestState(i, FLAG_GET_COMPLETED))
			{
				q++;
			}
		}
	}

	return q;
}

static u8 CountCompletedQuestsInCategory(u8 category)
{
	u8 q = 0;
	u8 i;

	for (i = 0; i < QUEST_COUNT; i++)
	{
		if (sSideQuests[i].category == category
		    && QuestMenu_IsQuestAvailable(i)
		    && QuestMenu_GetSetQuestState(i, FLAG_GET_COMPLETED))
		{
			q++;
		}
	}
	return q;
}

u8 CountFavoriteQuests(void)
{
	u8 q = 0, i = 0, x = 0;
	u8 mode = sStateDataPtr->filterMode % 10;

	for (i = 0; i < QUEST_COUNT; i++)
	{
		if (QuestMenu_IsQuestInCurrentCategory(i)
		    && QuestMenu_IsQuestAvailable(i)
		    && QuestMenu_GetSetQuestState(i, FLAG_GET_FAVORITE))
		{
			if (QuestMenu_GetSetQuestState(i, mode))
			{
				x++;
			}
			q++;
		}
	}

	if (IsNotFilteredMode())
	{
		return q;
	}
	else
	{
		return x;
	}

}

void PopulateEmptyRow(u8 countQuest)
{
	questNamePointer = QuestNameBufferCopy(countQuest, sText_Empty);
}

static u8 *QuestNameBufferCopy(u8 bufferId, const u8 *src)
{
	u8 *dst = questNameArray[bufferId];
	u32 length = min(StringLength(src), QUEST_NAME_BUFFER_SIZE - 1);

	memcpy(dst, src, length);
	dst[length] = EOS;
	return &dst[length];
}

static u8 *QuestNameBufferAppend(u8 bufferId, const u8 *src)
{
	u8 *dst = questNameArray[bufferId];
	u32 used = min(StringLength(dst), QUEST_NAME_BUFFER_SIZE - 1);
	u32 length = min(StringLength(src), QUEST_NAME_BUFFER_SIZE - 1 - used);

	memcpy(&dst[used], src, length);
	dst[used + length] = EOS;
	return &dst[used + length];
}

void PrependQuestNumber(u8 countQuest)
{
	questNamePointer = ConvertIntToDecimalStringN(questNameArray[countQuest],
	                   countQuest + 1, STR_CONV_MODE_LEFT_ALIGN, 2);
	questNamePointer = QuestNameBufferAppend(countQuest, sText_DotSpace);
}

void SetFavoriteQuest(u8 countQuest)
{
	questNamePointer = QuestNameBufferAppend(countQuest, sText_ColorGreen);
}

void PopulateQuestName(u8 countQuest)
{
	// Always show the quest's name, even before it has been accepted.
	questNamePointer = QuestNameBufferAppend(countQuest,
	                                sSideQuests[countQuest].name);
	if (QuestMenu_GetSetQuestState(countQuest, FLAG_GET_UNLOCKED))
	{
		AddSubQuestButton(countQuest);
	}
}

void PopulateSubquestName(u8 parentQuest, u8 countQuest)
{
	if (IsSubquestCompletedState(countQuest))
	{
		questNamePointer = QuestNameBufferAppend(countQuest,
		                                sSideQuests[parentQuest].subquests[countQuest].name);
	}
	else
	{
		questNamePointer = QuestNameBufferAppend(countQuest, sText_Unk);
	}
}

void PopulateListRowNameAndId(u8 row, u8 countQuest)
{
	sListMenuItems[row].name = questNameArray[countQuest];
	sListMenuItems[row].id = countQuest;
}

static bool8 DoesQuestHaveChildrenAndNotInactive(u16 itemId)
{
	if (sSideQuests[itemId].numSubquests != 0
	            && QuestMenu_GetSetQuestState(itemId, FLAG_GET_UNLOCKED)
	            && !QuestMenu_GetSetQuestState(itemId, FLAG_GET_INACTIVE))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void AddSubQuestButton(u8 countQuest)
{
	if (DoesQuestHaveChildrenAndNotInactive(countQuest))
	{
		questNamePointer = QuestNameBufferAppend(countQuest, sText_SubQuestButton);
	}

}
static void QuestMenu_AddTextPrinterParameterized(u8 windowId, u8 fontId,
            const u8 *str, u8 x, u8 y,
            u8 letterSpacing, u8 lineSpacing, u8 speed, u8 colorIdx)
{
	AddTextPrinterParameterized4(windowId, fontId, x, y, letterSpacing,
	                             lineSpacing,
	                             sQuestMenuWindowFontColors[colorIdx], speed, str);
}

static void MoveCursorFunc(s32 questId, bool8 onInit,
                           struct ListMenu *list)
{
	PlayCursorSound(onInit);

	if (sStateDataPtr->moveModeOrigPos == 0xFF)
	{
		QuestMenu_DestroySprite(sStateDataPtr->spriteIconSlot ^ 1);
		sStateDataPtr->spriteIconSlot ^= 1;

		if (questId == LIST_CANCEL)
		{
			PrintDetailsForCancel();
		}
		else
		{
			GenerateAndPrintQuestDetails(questId);
			DetermineSpriteType(questId);
		}
	}
}

static void PlayCursorSound(bool8 firstRun)
{
	if (firstRun == FALSE)
	{
		PlaySE(SE_RG_BAG_CURSOR);
	}
}

static void ClearQuestDetailsWindow(void)
{
	// An opaque, uniform footer lets the quest icon sit directly beside the
	// description instead of exposing the old black icon-box artwork on BG1.
	FillWindowPixelBuffer(1,
	                      PIXEL_FILL(QUEST_WINDOW_COLOR_PANEL_SELECTED));
}

static void PrintDetailsForCancel()
{
	// On the empty pre-Champion list, spell out when missions unlock.
	const u8 *detail = (!IsSubquestMode() && CountAvailableQuests() == 0)
	                   ? sText_NoQuestsHint : sText_Empty;

	ClearQuestDetailsWindow();

	QuestMenu_AddTextPrinterParameterized(1, 2, sText_Empty, 2, 3, 2, 0, 0,
	                                      0);
	QuestMenu_AddTextPrinterParameterized(1, 2, detail, 40, 19, 5, 0, 0,
	                                      0);

	QuestMenu_CreateSprite(-1, sStateDataPtr->spriteIconSlot, ITEM);
}

void GenerateAndPrintQuestDetails(s32 questId)
{
	GenerateQuestLocation(questId);
	PrintQuestLocation(questId);
	GenerateQuestFlavorText(questId);
	PrintQuestFlavorText(questId);
}
// The Jirachi quest normally opens by sending the player to Lilycove for the Old
// Sea Map -- but that map is shared with the Mew quest, so if the player already
// holds it, skip Lilycove and show the real next step (the Mossdeep girl).
static bool8 QuestMenu_JirachiHasMapShortcut(s32 questId)
{
	return questId == QUEST_JIRACHI
	    && !QuestMenu_GetSetQuestState(questId, FLAG_GET_UNLOCKED)
	    && CheckBagHasItem(ITEM_OLD_SEA_MAP, 1);
}

void GenerateQuestLocation(s32 questId)
{
	if (!IsSubquestMode())
	{
		// Before the quest is accepted, point at the giver's town; afterwards,
		// point at wherever the current active stage sends the player next.
		if (QuestMenu_GetSetQuestState(questId, FLAG_GET_UNLOCKED)
		    || QuestMenu_JirachiHasMapShortcut(questId))
			StringCopy(gStringVar2, GetQuestLocation(questId));
		else
			StringCopy(gStringVar2, sSideQuests[questId].startmap);
	}
	else
	{
		StringCopy(gStringVar2,
		           sSideQuests[sStateDataPtr->parentQuest].subquests[questId].map);
	}

	StringExpandPlaceholders(gStringVar4, sText_ShowLocation);
}
void PrintQuestLocation(s32 questId)
{
	ClearQuestDetailsWindow();
	QuestMenu_AddTextPrinterParameterized(1, 2, gStringVar4, 2, 3, 2, 0, 0,
	                                      4);
}
void GenerateQuestFlavorText(s32 questId)
{
	if (IsSubquestMode() == FALSE)
	{
		if (IsQuestInactiveState(questId) == TRUE)
		{
			if (QuestMenu_JirachiHasMapShortcut(questId))
				StringCopy(gStringVar1, GetQuestDesc(questId));
			else
				StringCopy(gStringVar1, sSideQuests[questId].startdesc);
		}
		if (IsQuestActiveState(questId) == TRUE)
		{
			UpdateQuestFlavorText(questId);
		}
		if (IsQuestRewardState(questId) == TRUE)
		{
			StringCopy(gStringVar1, sText_ReturnRecieveReward);
		}
		if (IsQuestCompletedState(questId) == TRUE)
		{
			StringCopy(gStringVar1, sSideQuests[questId].donedesc);
		}
	}
	else
	{
		if (IsSubquestCompletedState(questId) == TRUE)
		{
			StringCopy(gStringVar1,
			           sSideQuests[sStateDataPtr->parentQuest].subquests[questId].desc);
		}
		else
		{
			StringCopy(gStringVar1, sText_Empty);
		}
	}

	StringExpandPlaceholders(gStringVar3, gStringVar1);
}
void UpdateQuestFlavorText(s32 questId)
{
	StringExpandPlaceholders(gStringVar1, GetQuestDesc(questId));
}
void PrintQuestFlavorText(s32 questId)
{
	QuestMenu_AddTextPrinterParameterized(1, 2, gStringVar3, 40, 19, 5, 0, 0,
	                                      4);
}

static const u8 *GetQuestLocation(s32 questId)
{
	u32 qvar = VarGet(sSideQuests[questId].questVariable);
	
	if (sSideQuests[questId].map[qvar] == NULL)
		qvar = 0;

	return sSideQuests[questId].map[qvar];
}

static const u8 *GetQuestDesc(s32 questId)
{
	u32 qvar = VarGet(sSideQuests[questId].questVariable);
	
	if (sSideQuests[questId].desc[qvar] == NULL)
		qvar = 0;

	return sSideQuests[questId].desc[qvar];
}


bool8 IsSubquestCompletedState(s32 questId)
{
	if (QuestMenu_GetSetSubquestState(sStateDataPtr->parentQuest,
	                                  FLAG_GET_COMPLETED,
	                                  questId))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
bool8 IsQuestRewardState(s32 questId)
{
	if (QuestMenu_GetSetQuestState(questId, FLAG_GET_REWARD))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

bool8 IsQuestInactiveState(s32 questId)
{
	if (!QuestMenu_GetSetQuestState(questId, FLAG_GET_ACTIVE))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

bool8 IsQuestActiveState(s32 questId)
{
	if (QuestMenu_GetSetQuestState(questId, FLAG_GET_ACTIVE))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

bool8 IsQuestCompletedState(s32 questId)
{
	if (QuestMenu_GetSetQuestState(questId, FLAG_GET_COMPLETED))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

bool8 UNUSED IsQuestUnlocked(s32 questId)
{
	if (QuestMenu_GetSetQuestState(questId, FLAG_GET_UNLOCKED))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void DetermineSpriteType(s32 questId)
{
	u16 spriteId;
	u8 spriteType;

	if (IsSubquestMode() == FALSE)
	{
		spriteId = GetQuestSprite(questId);
		spriteType = GetQuestSpriteType(questId);

		QuestMenu_CreateSprite(spriteId, sStateDataPtr->spriteIconSlot,
		                       spriteType);
	}
	else if (IsSubquestCompletedState(questId) == TRUE)
	{
		spriteId =
		      sSideQuests[sStateDataPtr->parentQuest].subquests[questId].sprite;
		spriteType =
		      sSideQuests[sStateDataPtr->parentQuest].subquests[questId].spritetype;
		QuestMenu_CreateSprite(spriteId, sStateDataPtr->spriteIconSlot,
		                       spriteType);
	}
	else
	{
		QuestMenu_CreateSprite(ITEM_NONE, sStateDataPtr->spriteIconSlot, ITEM);
	}
	QuestMenu_DestroySprite(sStateDataPtr->spriteIconSlot ^ 1);
	sStateDataPtr->spriteIconSlot ^= 1;
}

// Gym-badge icons are pulled from the trainer-card badge sheet (8 badges, each
// 16x16, in Stone..Rain order). "-mwidth 2 -mheight 2" re-orders the tiles so
// each badge's 4 tiles are contiguous, which is what a 16x16 sprite expects.
static const u32 sQuestBadgeTiles[] = INCGFX_U32("graphics/trainer_card/badges.png", ".4bpp", "-mwidth 2 -mheight 2");
// Use the same custom palette the trainer card uses, so the badges match.
static const u16 sQuestBadgePal[]   = INCBIN_U16("graphics/trainer_card/palettes/badges.gbapal");

static const struct OamData sQuestBadgeOam =
{
	.shape = SPRITE_SHAPE(16x16),
	.size = SPRITE_SIZE(16x16),
	.priority = 0,
};

static const struct SpriteTemplate sQuestBadgeSpriteTemplate =
{
	.tileTag = 0,
	.paletteTag = 0,
	.oam = &sQuestBadgeOam,
	.anims = gDummySpriteAnimTable,
	.images = NULL,
	.affineAnims = gDummySpriteAffineAnimTable,
	.callback = SpriteCallbackDummy,
};

// Loads just the selected badge's 4 tiles and spawns a sprite for it.
static u8 AddBadgeIconSprite(u16 tilesTag, u16 paletteTag, u8 badge)
{
	struct SpriteSheet spriteSheet;
	struct SpritePalette spritePalette;
	struct SpriteTemplate spriteTemplate;

	spriteSheet.data = &sQuestBadgeTiles[badge * (0x80 / sizeof(u32))]; // 4 tiles/badge
	spriteSheet.size = 0x80;
	spriteSheet.tag = tilesTag;
	LoadSpriteSheet(&spriteSheet);

	spritePalette.data = sQuestBadgePal;
	spritePalette.tag = paletteTag;
	LoadSpritePalette(&spritePalette);

	spriteTemplate = sQuestBadgeSpriteTemplate;
	spriteTemplate.tileTag = tilesTag;
	spriteTemplate.paletteTag = paletteTag;
	return CreateSprite(&spriteTemplate, 0, 0, 0);
}

static void QuestMenu_CreateSprite(u16 itemId, u8 idx, u8 spriteType)
{
	u8 *ptr = &sItemMenuIconSpriteIds[10];
	u8 spriteId = 0xFF;

	if (ptr[idx] == 0xFF)
	{
		FreeSpriteTilesByTag(102 + idx);
		FreeSpritePaletteByTag(102 + idx);

		switch (spriteType)
		{
			case OBJECT:
				spriteId = CreateObjectGraphicsSprite(itemId, SpriteCallbackDummy, 20,
				                                      132, 0);
				break;
			case ITEM:
				spriteId = AddItemIconSprite(102 + idx, 102 + idx, itemId);
				break;
			case PKMN:
				LoadMonIconPalettes();
				spriteId = CreateMonIcon(itemId, SpriteCallbackDummy, 20, 132, 0, 1);
				break;
			case BADGE:
				spriteId = AddBadgeIconSprite(102 + idx, 102 + idx, itemId);
				break;
			default:
				break;
		}

		if (spriteId < MAX_SPRITES)
		{
			gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;
			ptr[idx] = spriteId;
			sStateDataPtr->spriteIconTypes[idx] = spriteType;

			if (spriteType == ITEM)
			{
				gSprites[spriteId].x2 = 24;
				gSprites[spriteId].y2 = 140;
			}
			else if (spriteType == BADGE)
			{
				// Centre the 16x16 badge on the same point the 32x32 mon icons use,
				// nudged down a touch to sit true-centre in the icon box.
				gSprites[spriteId].x2 = 20;
				gSprites[spriteId].y2 = 135;
			}
		}
	}
}

void ResetSpriteState(void)
{
	u16 i;

	for (i = 0; i < NELEMS(sItemMenuIconSpriteIds); i++)
	{
		sItemMenuIconSpriteIds[i] = 0xFF;
	}

	for (i = 0; i < QUEST_ICON_SPRITE_SLOTS; i++)
	{
		sStateDataPtr->spriteIconTypes[i] = 0;
	}
}

static void QuestMenu_DestroySprite(u8 idx)
{
	u8 *ptr = &sItemMenuIconSpriteIds[10];

	if (ptr[idx] != 0xFF)
	{
		u16 palTag = GetSpritePaletteTagByPaletteNum(
		                   gSprites[ptr[idx]].oam.paletteNum);

		// Mon icons replace Sprite::images with a raw tile-data pointer. The
		// specialized destructor restores valid image metadata before the common
		// sprite cleanup reads it. Using DestroySprite directly corrupts the
		// sprite tile allocator after enough cursor movement.
		if (sStateDataPtr->spriteIconTypes[idx] == PKMN)
		{
			FreeAndDestroyMonIconSprite(&gSprites[ptr[idx]]);
		}
		else
		{
			DestroySprite(&gSprites[ptr[idx]]);
		}

		ptr[idx] = 0xFF;
		sStateDataPtr->spriteIconTypes[idx] = 0;

		if (sStateDataPtr->oldPaletteTag != palTag)
		{
			if (sStateDataPtr->oldPaletteTag != 0)
			{
				FreeSpriteTilesByTag(sStateDataPtr->oldPaletteTag);
				sStateDataPtr->oldPaletteTag = palTag;
			}
		}
	}
}

static u32 GetQuestSprite(s32 questId)
{
	u32 qvar = VarGet(sSideQuests[questId].questVariable);
	
	if (sSideQuests[questId].sprite[qvar] == 0)
		qvar = 0;

	return sSideQuests[questId].sprite[qvar];
}

static u32 GetQuestSpriteType(s32 questId)
{
	u32 qvar = VarGet(sSideQuests[questId].questVariable);
	
	if (sSideQuests[questId].spritetype[qvar] == 0)
		qvar = 0;

	return sSideQuests[questId].spritetype[qvar];
}
static void GenerateStateAndPrint(u8 windowId, u32 questId,
                                  u8 y)
{
	u8 colorIndex;

	if (questId != LIST_CANCEL)
	{
		if (IsSubquestMode())
		{
			colorIndex = GenerateSubquestState(questId);
		}
		else
		{
			colorIndex = GenerateQuestState(questId);
		}

		PrintQuestState(windowId, y, colorIndex);
	}
}

u8 GenerateSubquestState(u8 questId)
{
	u8 parentQuest = sStateDataPtr->parentQuest;

	if (QuestMenu_GetSetSubquestState(parentQuest, FLAG_GET_COMPLETED,
	                                  questId))
	{
		StringCopy(gStringVar4, sSideQuests[parentQuest].subquests[questId].type);
	}
	else
	{
		StringCopy(gStringVar4, sText_Empty);
	}

	return 2;
}

u8 GenerateQuestState(u8 questId)
{
	if (QuestMenu_GetSetQuestState(questId, FLAG_GET_COMPLETED))
	{
		StringCopy(gStringVar4, sText_Complete);
		return 2;
	}
	else if (QuestMenu_GetSetQuestState(questId, FLAG_GET_REWARD))
	{
		StringCopy(gStringVar4, sText_Reward);
		return 1;
	}
	else if (QuestMenu_GetSetQuestState(questId, FLAG_GET_ACTIVE))
	{
		StringCopy(gStringVar4, sText_Active);
		return 3;
	}
	else
	{
		StringCopy(gStringVar4, sText_Empty);
	}

	return 0;
}

void PrintQuestState(u8 windowId, u8 y, u8 colorIndex)
{
	QuestMenu_AddTextPrinterParameterized(windowId, 0, gStringVar4, 200, y, 0,
	                                      0, 0xFF, colorIndex);
}

static void GenerateAndPrintHeader(void)
{
	GenerateDenominatorNumQuests();
	GenerateNumeratorNumQuests();
	GenerateMenuContext();

	PrintNumQuests();
	PrintMenuContext();

	if (!IsSubquestMode())
	{
		PrintTypeFilterButton();
	}
}
static void GenerateDenominatorNumQuests(void)
{
	ConvertIntToDecimalStringN(gStringVar2, CountAvailableQuests(),
	                           STR_CONV_MODE_LEFT_ALIGN, 6);
}

static void GenerateNumeratorNumQuests(void)
{
	u8 mode = sStateDataPtr->filterMode % 10;
	u8 parentQuest = sStateDataPtr->parentQuest;

	switch (mode)
	{
		case SORT_DEFAULT:
			ConvertIntToDecimalStringN(gStringVar1, CountUnlockedQuests(),
			                           STR_CONV_MODE_LEFT_ALIGN,
			                           6);
			break;
		case SORT_INACTIVE:
			ConvertIntToDecimalStringN(gStringVar1, CountInactiveQuests(),
			                           STR_CONV_MODE_LEFT_ALIGN,
			                           6);
			break;
		case SORT_ACTIVE:
			ConvertIntToDecimalStringN(gStringVar1, CountActiveQuests(),
			                           STR_CONV_MODE_LEFT_ALIGN, 6);
			break;
		case SORT_REWARD:
			ConvertIntToDecimalStringN(gStringVar1, CountRewardQuests(),
			                           STR_CONV_MODE_LEFT_ALIGN, 6);
			break;
		case SORT_DONE:
			ConvertIntToDecimalStringN(gStringVar1, CountCompletedQuests(),
			                           STR_CONV_MODE_LEFT_ALIGN,
			                           6);
			break;
	}

	if (IsSubquestMode())
	{
		ConvertIntToDecimalStringN(gStringVar2,
		                           sSideQuests[parentQuest].numSubquests,
		                           STR_CONV_MODE_LEFT_ALIGN, 6);
		ConvertIntToDecimalStringN(gStringVar1, CountCompletedQuests(),
		                           STR_CONV_MODE_LEFT_ALIGN,
		                           6);
	}
}

static void GenerateMenuContext(void)
{
	u8 mode = sStateDataPtr->filterMode % 10;
	u8 parentQuest = sStateDataPtr->parentQuest;

	questNamePointer = QuestNameBufferCopy(QUEST_ARRAY_COUNT,
	                                      sQuestCategoryCardNames[sStateDataPtr->category]);
	questNamePointer = QuestNameBufferAppend(QUEST_ARRAY_COUNT,
	                                        sText_HeaderDivider);

	switch (mode)
	{
		case SORT_DEFAULT:
			questNamePointer = QuestNameBufferAppend(QUEST_ARRAY_COUNT,
			                              sText_AllHeader);
			break;
		case SORT_INACTIVE:
			questNamePointer = QuestNameBufferAppend(QUEST_ARRAY_COUNT,
			                              sText_InactiveHeader);
			break;
		case SORT_ACTIVE:
			questNamePointer = QuestNameBufferAppend(QUEST_ARRAY_COUNT,
			                              sText_ActiveHeader);
			break;
		case SORT_REWARD:
			questNamePointer = QuestNameBufferAppend(QUEST_ARRAY_COUNT,
			                              sText_RewardHeader);
			break;
		case SORT_DONE:
			questNamePointer = QuestNameBufferAppend(QUEST_ARRAY_COUNT,
			                              sText_CompletedHeader);
			break;
	}

	if (IsAlphaMode())
	{
		questNamePointer = QuestNameBufferAppend(QUEST_ARRAY_COUNT,
		                                sText_AZ);
	}
	if (IsSubquestMode())
	{
		questNamePointer = QuestNameBufferCopy(QUEST_ARRAY_COUNT,
		                              sSideQuests[parentQuest].name);

	}
}

static void PrintNumQuests(void)
{
	StringExpandPlaceholders(gStringVar4, sText_QuestNumberDisplay);
	QuestMenu_AddTextPrinterParameterized(2, 0, gStringVar4, 167, 1, 0, 1, 0,
	                                      0);
}
static void PrintMenuContext(void)
{
	QuestMenu_AddTextPrinterParameterized(2, 0,
	                                      questNameArray[QUEST_ARRAY_COUNT], 10, 1, 0, 1, 0, 0);
}
static void PrintTypeFilterButton(void)
{
	QuestMenu_AddTextPrinterParameterized(2, 0, sText_Type, 198, 1,
	                                      0, 1, 0, 0);

}

static void Task_Main(u8 taskId)
{
	s16 *data = gTasks[taskId].data;
	s32 input = ListMenu_ProcessInput(data[0]);

	u8 selectedQuestId = sListMenuItems[GetCursorPosition()].id;

	if (!gPaletteFade.active)
	{
		ListMenuGetScrollAndRow(data[0], &sListMenuState.scroll,
		                        &sListMenuState.row);

		switch (input)
		{
			case LIST_NOTHING_CHOSEN:
				if (JOY_NEW(R_BUTTON))
				{
					ChangeModeAndCleanUp(taskId);
				}
				if (JOY_NEW(START_BUTTON))
				{
					ToggleAlphaModeAndCleanUp(taskId);
				}
				if (JOY_NEW(SELECT_BUTTON))
				{
					ToggleFavoriteAndCleanUp(taskId, selectedQuestId);
				}
				break;

			case LIST_CANCEL:
				if (IsSubquestMode())
				{
					ReturnFromSubquestAndCleanUp(taskId);
				}
				else
				{
					ReturnToCategoryHub(taskId);
				}
				break;

			default:
				if (!IsSubquestMode())
				{
					// A on a quest: claim its reward if one is waiting,
					// otherwise open its subquests (if it has any).
					if (QuestMenu_GetSetQuestState(input, FLAG_GET_REWARD))
						TryClaimQuestReward(taskId, input);
					else
						EnterSubquestModeAndCleanUp(taskId, data, input);
				}
				break;
		}
	}
}

void ManageFavorites(u8 selectedQuestId)
{
	if (QuestMenu_GetSetQuestState(selectedQuestId, FLAG_GET_FAVORITE))
	{
		QuestMenu_GetSetQuestState(selectedQuestId, FLAG_REMOVE_FAVORITE);
	}
	else
	{
		QuestMenu_GetSetQuestState(selectedQuestId, FLAG_SET_FAVORITE);
	}
}

static void Task_QuestMenuCleanUp(u8 taskId)
{
	s16 *data = gTasks[taskId].data;

	QuestMenu_RemoveScrollIndicatorArrowPair();
	DestroyListMenuTask(data[0], &sListMenuState.scroll, &sListMenuState.row);
	if (sListMenuItems != NULL)
	{
		Free(sListMenuItems);
		sListMenuItems = NULL;
	}
	FillWindowPixelBuffer(0, 0);
	ClearQuestDetailsWindow();
	FillWindowPixelBuffer(2, 0);
	PutWindowTilemap(0);
	PutWindowTilemap(1);
	PutWindowTilemap(2);

	InitItems();
	if (!AllocateResourcesForListMenu())
	{
		PlaySE(SE_BOO);
		ShowCategoryHub();
		gTasks[taskId].func = Task_CategoryMain;
		return;
	}
	BuildMenuTemplate();
	GenerateAndPrintHeader();
	PlaceTopMenuScrollIndicatorArrows();

	if (sStateDataPtr->restoreCursor == TRUE)
	{
		RestoreSavedScrollAndRow(data);
	}
	else
	{
		ResetCursorToTop(data);
	}

}

static void RestoreSavedScrollAndRow(s16 *data)
{
	data[0] = ListMenuInit(&gMultiuseListMenuTemplate,
	                       sListMenuState.storedScrollOffset,
	                       sListMenuState.storedRowPosition);
}
static void ResetCursorToTop(s16 *data)
{
	sListMenuState.row = 0;
	sListMenuState.scroll = 0;
	data[0] = ListMenuInit(&gMultiuseListMenuTemplate, sListMenuState.scroll,
	                       sListMenuState.row);
}

static void QuestMenu_RemoveScrollIndicatorArrowPair(void)
{
	if (sStateDataPtr->scrollIndicatorArrowPairId != 0xFF)
	{
		RemoveScrollIndicatorArrowPair(sStateDataPtr->scrollIndicatorArrowPairId);
		sStateDataPtr->scrollIndicatorArrowPairId = 0xFF;
	}
}


// Hands a "Reward Available" quest's item/money to the player and marks it Done.
// Refuses (with a buzzer) if the reward item wouldn't fit in the bag.
static void TryClaimQuestReward(u8 taskId, u8 questId)
{
	u16 item = sSideQuests[questId].rewardItem;
	u8 qty = sSideQuests[questId].rewardQty;
	u32 money = sSideQuests[questId].rewardMoney;

	if (item != ITEM_NONE && qty != 0 && !CheckBagHasSpace(item, qty))
	{
		PlaySE(SE_BOO);
		return;
	}

	if (item != ITEM_NONE && qty != 0)
		AddBagItem(item, qty);
	if (money != 0)
		AddMoney(&gSaveBlock1Ptr->money, money);

	QuestMenu_GetSetQuestState(questId, FLAG_REMOVE_REWARD);
	QuestMenu_GetSetQuestState(questId, FLAG_SET_COMPLETED);

	PlayFanfare(MUS_OBTAIN_ITEM);
	sStateDataPtr->restoreCursor = FALSE;

	// Show the player exactly what they earned, then wait for a button press
	// before rebuilding the list (which happens once the quest moves to Done).
	QuestMenu_PrintRewardMessage(questId);
	gTasks[taskId].func = Task_WaitForRewardAck;
}

// Prints "You received <n> <item>!" (and/or the money) into the detail pane.
static void QuestMenu_PrintRewardMessage(u8 questId)
{
	u16 item = sSideQuests[questId].rewardItem;
	u8 qty = sSideQuests[questId].rewardQty;
	u32 money = sSideQuests[questId].rewardMoney;
	const u8 *message;

	ConvertIntToDecimalStringN(gStringVar1, qty, STR_CONV_MODE_LEFT_ALIGN, 3);
	CopyItemNameHandlePlural(item, gStringVar2, qty);
	ConvertIntToDecimalStringN(gStringVar3, money, STR_CONV_MODE_LEFT_ALIGN, 7);

	if (item != ITEM_NONE && qty != 0 && money != 0)
		message = sText_RewardGotBoth;
	else if (money != 0)
		message = sText_RewardGotMoney;
	else
		message = sText_RewardGotItem;

	StringExpandPlaceholders(gStringVar4, message);

	// Print where the "Press A to claim your reward!" hint sits -- that spot is
	// already laid out to clear the reward icon in the lower-left of the pane.
	ClearQuestDetailsWindow();
	QuestMenu_AddTextPrinterParameterized(1, 2, gStringVar4, 40, 19, 5, 0, 0, 4);
}

// Holds the reward message on screen until the player acknowledges it.
static void Task_WaitForRewardAck(u8 taskId)
{
	if (JOY_NEW(A_BUTTON | B_BUTTON))
	{
		PlaySE(SE_SELECT);
		Task_QuestMenuCleanUp(taskId);
		gTasks[taskId].func = Task_Main;
	}
}

void EnterSubquestModeAndCleanUp(u8 taskId, s16 *data,
                                 s32 input)
{
	if (DoesQuestHaveChildrenAndNotInactive(input))
	{
		PrepareFadeOut(taskId);

		PlaySE(SE_SELECT);
		sStateDataPtr->parentQuest = input;
		sStateDataPtr->filterMode = ManageMode(SUB);
		SaveScrollAndRow(data);
		gTasks[taskId].func = Task_FadeOut;
	}
}
void ChangeModeAndCleanUp(u8 taskId)
{
	if (!IsSubquestMode())
	{
		PlaySE(SE_SELECT);
		sStateDataPtr->filterMode = ManageMode(INCREMENT);
		Task_QuestMenuCleanUp(taskId);
	}
}
void ToggleAlphaModeAndCleanUp(u8 taskId)
{
	if (!IsSubquestMode())
	{
		PlaySE(SE_SELECT);
		sStateDataPtr->filterMode = ManageMode(ALPHA);
		Task_QuestMenuCleanUp(taskId);
	}
}
void ToggleFavoriteAndCleanUp(u8 taskId, u8 selectedQuestId)
{
	if (!IsSubquestMode()
	            && !CheckSelectedIsCancel(selectedQuestId))
	{
		PlaySE(SE_SELECT);
		ManageFavorites(selectedQuestId);
		sStateDataPtr->restoreCursor = FALSE;
		Task_QuestMenuCleanUp(taskId);
	}
}
bool8 CheckSelectedIsCancel(u8 selectedQuestId)
{
	if (selectedQuestId == (0xFF - 1))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
void ReturnFromSubquestAndCleanUp(u8 taskId)
{
	PrepareFadeOut(taskId);

	PlaySE(SE_SELECT);
	sStateDataPtr->filterMode = ManageMode(SUB);
	gTasks[taskId].func = Task_FadeOut;
}

static void SetGpuRegBaseForFade()
{
	//Sets the GPU registers to prepare for a hardware fade
	SetGpuReg(REG_OFFSET_BLDCNT,
	          BLDCNT_TGT1_OBJ | BLDCNT_TGT1_BG0 | BLDCNT_TGT2_BG1 |
	          BLDCNT_EFFECT_BLEND);      //Blend Sprites and BG0 into BG1
	SetGpuReg(REG_OFFSET_BLDY, 0);
}

#define MAX_FADE_INTENSITY 16
#define MIN_FADE_INTENSITY 0

void InitFadeVariables(u8 taskId, u8 blendWeight, u8 frameDelay,
                       u8 frameTimerBase, u8 delta)
{
	gTasks[taskId].data[1] = blendWeight;
	gTasks[taskId].data[2] = frameDelay;
	gTasks[taskId].data[3] = gTasks[taskId].data[frameTimerBase];
	gTasks[taskId].data[4] = delta;
}


static void PrepareFadeOut(u8 taskId)
{
	SetGpuRegBaseForFade();
	SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(MAX_FADE_INTENSITY, 0));
	InitFadeVariables(taskId, MAX_FADE_INTENSITY, 0, 2, 2);
}

static bool8 HandleFadeOut(u8 taskId)
{
	if (gTasks[taskId].data[3]-- != 0)
	{
		return FALSE;
	}

	//Set the timer, decrease the fade weight by the delta, increase the delta by the timer
	gTasks[taskId].data[3] = gTasks[taskId].data[2];
	gTasks[taskId].data[1] -= gTasks[taskId].data[4];
	gTasks[taskId].data[2] += gTasks[taskId].data[3];

	//When blend weight runs out, set final blend and quit
	if (gTasks[taskId].data[1] <= 0)
	{
		SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, gTasks[taskId].data[1]));
		return TRUE;
	}
	//Set intermediate blend state
	SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[1],
	            MAX_FADE_INTENSITY - gTasks[taskId].data[1]));
	return FALSE;
}

static void PrepareFadeIn(u8 taskId)
{
	SetGpuRegBaseForFade();
	SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0,
	            MAX_FADE_INTENSITY));
	InitFadeVariables(taskId, MIN_FADE_INTENSITY, 0, 1, 2);
}

static bool8 HandleFadeIn(u8 taskId)
{
	//Set the timer, ncrease the fade weight by the delta,
	gTasks[taskId].data[3] = gTasks[taskId].data[2];
	gTasks[taskId].data[1] += gTasks[taskId].data[4];

	//When blend weight reaches max, set final blend and quit
	if (gTasks[taskId].data[1] >= MAX_FADE_INTENSITY)
	{
		SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(MAX_FADE_INTENSITY,
		            MIN_FADE_INTENSITY));
		return TRUE;
	}
	//Set intermediate blend state
	SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[1],
	            MAX_FADE_INTENSITY - gTasks[taskId].data[1]));
	return FALSE;
}

static void Task_FadeOut(u8 taskId)
{
	if (HandleFadeOut(taskId))
	{
		PrepareFadeIn(taskId);
		Task_QuestMenuCleanUp(taskId);
		gTasks[taskId].func = Task_FadeIn;
	}
}

static void Task_FadeIn(u8 taskId)
{
	if (HandleFadeIn(taskId))
	{
		gTasks[taskId].func = Task_Main;
	}
}

static void Task_QuestMenuWaitFadeAndBail(u8 taskId)
{
	if (!gPaletteFade.active)
	{
		SetMainCallback2(sListMenuState.savedCallback);
		FreeResources();
		DestroyTask(taskId);
	}
}

static void FadeAndBail(void)
{
	BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
	CreateTask(Task_QuestMenuWaitFadeAndBail, 0);
	SetVBlankCallback(VBlankCB);
	SetMainCallback2(MainCB);
}


#define try_free(ptr) ({        \
		void ** ptr__ = (void **)&(ptr);   \
		if (*ptr__ != NULL)                \
			Free(*ptr__);                  \
	})

static void FreeResources(void)
{
	int i;

	if (sStateDataPtr != NULL)
	{
		QuestMenu_DestroySprite(0);
		QuestMenu_DestroySprite(1);
		DestroyCategorySprites();
	}

	if (questNameArray != NULL)
	{
		for (i = QUEST_ARRAY_COUNT; i > -1; i--)
		{
			try_free(questNameArray[i]);
			questNameArray[i] = NULL;
		}
	}

	try_free(questNameArray);
	questNameArray = NULL;
	try_free(sStateDataPtr);
	sStateDataPtr = NULL;
	try_free(sBg1TilemapBuffer);
	sBg1TilemapBuffer = NULL;
	try_free(sListMenuItems);
	sListMenuItems = NULL;
	questNamePointer = NULL;
	FreeAllWindowBuffers();
}

void TurnOffQuestMenu(u8 taskId)
{
	SetInitializedFlag(0);
	gTasks[taskId].func = Task_QuestMenuTurnOff1;
}
static void Task_QuestMenuTurnOff1(u8 taskId)
{
	BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
	gTasks[taskId].func = Task_QuestMenuTurnOff2;
}

static void Task_QuestMenuTurnOff2(u8 taskId)
{
	s16 *data = gTasks[taskId].data;

	if (!gPaletteFade.active)
	{
		if (sStateDataPtr->menuPage == QUEST_MENU_PAGE_LIST
		    && sListMenuItems != NULL)
		{
			DestroyListMenuTask(data[0], &sListMenuState.scroll,
			                    &sListMenuState.row);
		}
		if (sStateDataPtr->savedCallback != NULL)
		{
			SetMainCallback2(sStateDataPtr->savedCallback);
		}
		else
		{
			SetMainCallback2(sListMenuState.savedCallback);
		}

		QuestMenu_RemoveScrollIndicatorArrowPair();
		FreeResources();
		DestroyTask(taskId);
	}
}

void Task_QuestMenu_OpenFromStartMenu(u8 taskId)
{
	s16 *data = gTasks[taskId].data;
	if (!gPaletteFade.active)
	{
		CleanupOverworldWindowsAndTilemaps();
		QuestMenu_Init(tItemPcParam, CB2_ReturnToFieldWithOpenMenu);
		DestroyTask(taskId);
	}
}

void QuestMenu_CopyQuestName(u8 *dst, u8 questId)
{
	if (!QuestMenu_IsQuestIdValid(questId))
	{
		dst[0] = EOS;
		return;
	}

	StringCopy(dst, sSideQuests[questId].name);
}

void QuestMenu_CopySubquestName(u8 *dst, u8 parentId, u8 childId)
{
	if (!QuestMenu_IsSubquestIdValid(parentId, childId))
	{
		dst[0] = EOS;
		return;
	}

	StringCopy(dst, sSideQuests[parentId].subquests[childId].name);
}

void QuestMenu_ResetMenuSaveData(void)
{
	memset(gSaveBlock3Ptr->questData, 0, sizeof(gSaveBlock3Ptr->questData));
	memset(gSaveBlock3Ptr->subQuests, 0, sizeof(gSaveBlock3Ptr->subQuests));
	gSaveBlock3Ptr->questDataMagic = QUEST_SAVE_DATA_MAGIC;
}

u32 QuestMenu_GetQuestVariableId(u8 quest)
{
	if (!QuestMenu_IsQuestIdValid(quest))
		return 0;

    return sSideQuests[quest].questVariable;
}

u32 QuestMenu_GetQuestVariable(u8 quest)
{
	u32 variableId;

	if (!QuestMenu_IsQuestIdValid(quest))
		return 0;

	variableId = QuestMenu_GetQuestVariableId(quest);
	if (variableId == 0)
		return 0;

	return VarGet(variableId);
}

// ==================== Rewards & condition-based completion ====================

static bool8 QuestHasReward(u8 questId)
{
	return sSideQuests[questId].rewardItem != ITEM_NONE
	    || sSideQuests[questId].rewardMoney != 0;
}

// Finishes a quest triggered by a script (completequest) or by the condition
// checker. A quest with a pending reward parks in the REWARD state until the
// player claims it from the menu; a quest with no reward completes outright.
void QuestMenu_MarkQuestFinished(u8 questId)
{
	if (QuestMenu_GetSetQuestState(questId, FLAG_GET_COMPLETED)
	    || QuestMenu_GetSetQuestState(questId, FLAG_GET_REWARD))
		return;

	QuestMenu_GetSetQuestState(questId, FLAG_SET_UNLOCKED);
	QuestMenu_GetSetQuestState(questId, FLAG_REMOVE_ACTIVE);

	if (QuestHasReward(questId))
		QuestMenu_GetSetQuestState(questId, FLAG_SET_REWARD);
	else
		QuestMenu_GetSetQuestState(questId, FLAG_SET_COMPLETED);

	// Every quest announces itself with the overworld banner, whatever finished
	// it (script, gym/champion flag, or the condition checker). The banner queues
	// itself and waits for the field to be idle, so completions detected from
	// inside the menu still show once the player is back outside.
	ShowQuestCompletePopup(questId);
}

// Catch-count and Pokédex-completion quests have no scripted trigger, so we poll
// their conditions whenever the menu is opened and flip finished ones to REWARD.
static const struct { u8 quest; u16 count; } sCatchGoals[] =
{
	{QUEST_CATCH_50,   50},
	{QUEST_CATCH_100, 100},
	{QUEST_CATCH_300, 300},
	{QUEST_CATCH_500, 500},
	{QUEST_CATCH_800, 800},
};

// TRUE once the player owns a hatched (non-Egg) Pichu in the party or a PC Box.
static bool8 QuestMenu_PlayerHasHatchedPichu(void)
{
	u32 i, box, slot;

	for (i = 0; i < PARTY_SIZE; i++)
	{
		struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][i];
		if (GetMonData(mon, MON_DATA_SPECIES) == SPECIES_PICHU
		    && !GetMonData(mon, MON_DATA_IS_EGG))
			return TRUE;
	}

	for (box = 0; box < TOTAL_BOXES_COUNT; box++)
	{
		for (slot = 0; slot < IN_BOX_COUNT; slot++)
		{
			struct BoxPokemon *boxMon = GetBoxedMonPtr(box, slot);
			if (GetBoxMonData(boxMon, MON_DATA_SPECIES) == SPECIES_PICHU
			    && !GetBoxMonData(boxMon, MON_DATA_IS_EGG))
				return TRUE;
		}
	}

	return FALSE;
}

// Marks any catch-count goal whose threshold the player has now reached. Public
// so it can also be polled the moment the player returns to the overworld (e.g.
// right after catching the milestone Pokémon), not just when the menu is opened.
void QuestMenu_CheckCatchQuests(void)
{
	u16 caught = GetNationalPokedexCount(FLAG_GET_CAUGHT);
	u32 i;

	for (i = 0; i < ARRAY_COUNT(sCatchGoals); i++)
	{
		if (caught >= sCatchGoals[i].count)
			QuestMenu_MarkQuestFinished(sCatchGoals[i].quest);
	}
}

static void QuestMenu_TryAdvanceConditionalQuests(void)
{
	u16 caught = GetNationalPokedexCount(FLAG_GET_CAUGHT);
	u32 i;

	QuestMenu_CheckCatchQuests();

	if (QuestMenu_IsQuestAvailable(QUEST_POKEDEX)
	    && caught >= NATIONAL_DEX_COUNT)
		QuestMenu_MarkQuestFinished(QUEST_POKEDEX);

	// The intro quest wraps up the moment the player receives the Pokédex.
	if (FlagGet(FLAG_SYS_POKEDEX_GET))
		QuestMenu_MarkQuestFinished(QUEST_INTRO);

	// The traveler's Egg quest completes once its Pichu has actually hatched.
	// Guarded on the active state so it only fires after the Egg is accepted.
	if (QuestMenu_GetSetQuestState(QUEST_SHINY_PICHU_EGG, FLAG_GET_ACTIVE)
	    && QuestMenu_PlayerHasHatchedPichu())
		QuestMenu_MarkQuestFinished(QUEST_SHINY_PICHU_EGG);

	// Gym-badge and Champion quests light up as active objectives the moment
	// they become available (the enabling badge/flag is set), without the
	// player having to accept them.
	{
		static const u8 sAutoActiveQuests[] =
		{
			QUEST_BADGE_1, QUEST_BADGE_2, QUEST_BADGE_3, QUEST_BADGE_4,
			QUEST_BADGE_5, QUEST_BADGE_6, QUEST_BADGE_7, QUEST_BADGE_8,
			QUEST_CHAMPION,
		};

		for (i = 0; i < ARRAY_COUNT(sAutoActiveQuests); i++)
		{
			u8 quest = sAutoActiveQuests[i];

			if (QuestMenu_IsQuestAvailable(quest)
			    && !QuestMenu_GetSetQuestState(quest, FLAG_GET_COMPLETED)
			    && !QuestMenu_GetSetQuestState(quest, FLAG_GET_REWARD))
			{
				QuestMenu_GetSetQuestState(quest, FLAG_SET_UNLOCKED);
				QuestMenu_GetSetQuestState(quest, FLAG_SET_ACTIVE);
			}
		}
	}
}

// Called from new_game.c: wipe quest save data and light up the goals that are
// live from the very first step (badge 1, the catch-count goals, the intro).
void QuestMenu_InitNewGameQuests(void)
{
	static const u8 sNewGameActiveQuests[] =
	{
		QUEST_INTRO,
		QUEST_CATCH_50, QUEST_CATCH_100, QUEST_CATCH_300,
		QUEST_CATCH_500, QUEST_CATCH_800,
	};
	u32 i;

	QuestMenu_ResetMenuSaveData();

	for (i = 0; i < ARRAY_COUNT(sNewGameActiveQuests); i++)
	{
		QuestMenu_GetSetQuestState(sNewGameActiveQuests[i], FLAG_SET_UNLOCKED);
		QuestMenu_GetSetQuestState(sNewGameActiveQuests[i], FLAG_SET_ACTIVE);
	}
}

// ==================== Overworld quest-giver icons (ported from Starbound) ====================

static bool32 ObjectEventAlreadyHasQuest(bool32 hasQuestIcon)
{
	if (!FieldEffectActiveListContains(FLDEFF_QUEST_ICON))
		return FALSE;

	return hasQuestIcon;
}

static void SetQuestIconOnObject(struct ObjectEvent *objectEvent)
{
	objectEvent->hasQuestIcon = TRUE;
}

static void SpawnQuestIconForObject(struct ObjectEvent *objectEvent, u32 objectEventId)
{
	SetQuestIconOnObject(objectEvent);
	StartFieldEffectForObjectEvent(FLDEFF_QUEST_ICON, objectEvent);
}

void ResetQuestIconOnObject(struct ObjectEvent *objectEvent)
{
	objectEvent->hasQuestIcon = FALSE;
}

void HandleQuestIconForSingleObjectEvent(struct ObjectEvent *objectEvent, u32 objectEventId)
{
	u32 localId = objectEvent->localId;
	u32 mapNum = objectEvent->mapNum;
	u32 mapGroup = objectEvent->mapGroup;
	u32 questId;
	const struct ObjectEventTemplate *obj;

	// Never attempt to put a quest icon on the player
	if (objectEvent->movementType == MOVEMENT_TYPE_PLAYER)
		return;

	obj = GetObjectEventTemplateByLocalIdAndMap(localId, mapNum, mapGroup);
	if (obj == NULL)
		return;

	if (obj->trainerType != TRAINER_TYPE_QUEST_GIVER)
		return;

	questId = obj->questId;
	if (questId == QUEST_NONE)
		return;

	// No marker until the quest is actually available in the menu.
	if (!QuestMenu_IsQuestAvailable(questId))
		return;

	// Only unaccepted quests get a marker. Once the quest is unlocked (accepted),
	// simply don't spawn one on this map load; a marker that's already onscreen is
	// cleared live by the icon's own callback (SpriteCB_QuestIcon), which stops the
	// icon sprite -- never the NPC sprite.
	if (QuestMenu_GetSetQuestState(questId, FLAG_GET_UNLOCKED))
		return;

	// Already has icon? Do nothing
	if (ObjectEventAlreadyHasQuest(objectEvent->hasQuestIcon))
		return;

	// Add icon to NPCs who have quests
	if (!objectEvent->hasQuestIcon && !FieldEffectActiveListContains(FLDEFF_QUEST_ICON))
		SpawnQuestIconForObject(objectEvent, objectEventId);
}

void RefreshQuestIcons(void)
{
	u8 i;
	for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
	{
		if (gObjectEvents[i].active)
			HandleQuestIconForSingleObjectEvent(&gObjectEvents[i], i);
	}
}

// Accessors used by the quest-completion popup (src/quest_popup.c).
u16 QuestMenu_GetQuestIconSprite(u8 questId)
{
	if (!QuestMenu_IsQuestIdValid(questId))
		return 0;
	return GetQuestSprite(questId);
}

u8 QuestMenu_GetQuestIconType(u8 questId)
{
	if (!QuestMenu_IsQuestIdValid(questId))
		return 0;
	return GetQuestSpriteType(questId);
}

// Builds a quest's icon sprite at (x, y) for the completion banner. Lives here
// because the per-type icon builders (badge icons especially) are local to this
// file. Handles every sprite type a quest can use, so all quests get an icon.
#define QUEST_POPUP_ICON_TAG 0x2790

u8 QuestMenu_CreateQuestIconSprite(u8 questId, s16 x, s16 y)
{
	u16 sprite;
	u8 spriteType;
	u8 spriteId = SPRITE_NONE;

	if (!QuestMenu_IsQuestIdValid(questId))
		return SPRITE_NONE;

	sprite = GetQuestSprite(questId);
	spriteType = GetQuestSpriteType(questId);

	FreeSpriteTilesByTag(QUEST_POPUP_ICON_TAG);
	FreeSpritePaletteByTag(QUEST_POPUP_ICON_TAG);

	switch (spriteType)
	{
		case PKMN:
			LoadMonIconPalettes();
			spriteId = CreateMonIcon(sprite, SpriteCallbackDummy, x, y, 0, 0);
			break;
		case ITEM:
			spriteId = AddItemIconSprite(QUEST_POPUP_ICON_TAG, QUEST_POPUP_ICON_TAG, sprite);
			break;
		case BADGE:
			spriteId = AddBadgeIconSprite(QUEST_POPUP_ICON_TAG, QUEST_POPUP_ICON_TAG, sprite);
			break;
		case OBJECT:
			spriteId = CreateObjectGraphicsSprite(sprite, SpriteCallbackDummy, x, y, 0);
			break;
		default:
			return SPRITE_NONE;
	}

	if (spriteId >= MAX_SPRITES)
		return SPRITE_NONE;

	gSprites[spriteId].x = x;
	gSprites[spriteId].y = y;
	gSprites[spriteId].oam.priority = 0;
	return spriteId;
}

void QuestMenu_FreeQuestIconSprite(u8 questId, u8 spriteId)
{
	if (spriteId >= MAX_SPRITES)
		return;

	if (QuestMenu_IsQuestIdValid(questId) && GetQuestSpriteType(questId) == PKMN)
	{
		FreeAndDestroyMonIconSprite(&gSprites[spriteId]);
		FreeMonIconPalettes();
	}
	else
	{
		DestroySprite(&gSprites[spriteId]);
		FreeSpriteTilesByTag(QUEST_POPUP_ICON_TAG);
		FreeSpritePaletteByTag(QUEST_POPUP_ICON_TAG);
	}
}
