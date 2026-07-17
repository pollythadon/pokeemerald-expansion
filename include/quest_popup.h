#ifndef GUARD_QUEST_POPUP_H
#define GUARD_QUEST_POPUP_H

// Drops an achievement-style banner down from the top of the overworld screen
// announcing that the given quest has been completed. Non-blocking: it waits
// until the field is idle (no script/message box) before sliding in.
void ShowQuestCompletePopup(u16 questId);
void HideQuestCompletePopup(void);
void QuestPopup_KickQueue(void);
bool8 IsQuestCompletePopupActive(void);

#endif // GUARD_QUEST_POPUP_H
