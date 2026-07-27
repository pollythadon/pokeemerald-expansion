# 6 "data/scripts/rotom_quest.pory"
RotomQuest_Movement_PlayerStepBack:
# 7 "data/scripts/rotom_quest.pory"
	lock_facing_direction
# 8 "data/scripts/rotom_quest.pory"
	walk_down
# 9 "data/scripts/rotom_quest.pory"
	unlock_facing_direction
	step_end

# 12 "data/scripts/rotom_quest.pory"
RotomQuest_Movement_RotomJumpOut:
# 13 "data/scripts/rotom_quest.pory"
	jump_down
# 14 "data/scripts/rotom_quest.pory"
	walk_in_place_down
	step_end

RotomQuest_EventScript_MomCall::
# 28 "data/scripts/rotom_quest.pory"
	lockall
# 29 "data/scripts/rotom_quest.pory"
	pokenavcall RotomQuest_Text_MomCall
# 30 "data/scripts/rotom_quest.pory"
	waitmessage
# 31 "data/scripts/rotom_quest.pory"
	setflag FLAG_MOM_ROTOM_QUEST_AVAILABLE
# 32 "data/scripts/rotom_quest.pory"
	releaseall
	end


RotomQuest_EventScript_Mom::
# 39 "data/scripts/rotom_quest.pory"
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_ROTOM
# 40 "data/scripts/rotom_quest.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RotomQuest_EventScript_Mom_2
# 53 "data/scripts/rotom_quest.pory"
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_ROTOM
# 54 "data/scripts/rotom_quest.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RotomQuest_EventScript_Mom_5
# 61 "data/scripts/rotom_quest.pory"
	goto_if_set FLAG_MOM_ROTOM_QUEST_AVAILABLE, RotomQuest_EventScript_Mom_11
RotomQuest_EventScript_Mom_10:
# 72 "data/scripts/rotom_quest.pory"
	goto PlayersHouse_1F_EventScript_Mom
	return

RotomQuest_EventScript_Mom_2:
# 41 "data/scripts/rotom_quest.pory"
	lock
# 42 "data/scripts/rotom_quest.pory"
	faceplayer
# 43 "data/scripts/rotom_quest.pory"
	goto_if_set FLAG_ROTOM_CAUGHT_FROM_TV, RotomQuest_EventScript_Mom_8
# 49 "data/scripts/rotom_quest.pory"
	msgbox RotomQuest_EventScript_Mom_Text_1
# 50 "data/scripts/rotom_quest.pory"
	release
	end

RotomQuest_EventScript_Mom_5:
# 55 "data/scripts/rotom_quest.pory"
	lock
# 56 "data/scripts/rotom_quest.pory"
	faceplayer
# 57 "data/scripts/rotom_quest.pory"
	msgbox RotomQuest_EventScript_Mom_Text_2
# 58 "data/scripts/rotom_quest.pory"
	release
	end

RotomQuest_EventScript_Mom_8:
# 44 "data/scripts/rotom_quest.pory"
	msgbox RotomQuest_EventScript_Mom_Text_0
# 45 "data/scripts/rotom_quest.pory"
	completequest QUEST_ROTOM
# 46 "data/scripts/rotom_quest.pory"
	release
	end

RotomQuest_EventScript_Mom_11:
# 62 "data/scripts/rotom_quest.pory"
	questmenu QUEST_MENU_CHECK_UNLOCKED, QUEST_ROTOM
# 63 "data/scripts/rotom_quest.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RotomQuest_EventScript_Mom_13
	goto RotomQuest_EventScript_Mom_10

RotomQuest_EventScript_Mom_13:
# 64 "data/scripts/rotom_quest.pory"
	lock
# 65 "data/scripts/rotom_quest.pory"
	faceplayer
# 66 "data/scripts/rotom_quest.pory"
	msgbox RotomQuest_EventScript_Mom_Text_3
# 67 "data/scripts/rotom_quest.pory"
	startquest QUEST_ROTOM
# 68 "data/scripts/rotom_quest.pory"
	release
	end


RotomQuest_EventScript_RotomTVCutscene::
# 77 "data/scripts/rotom_quest.pory"
	lockall
# 78 "data/scripts/rotom_quest.pory"
	goto_if_set FLAG_ROTOM_CAUGHT_FROM_TV, RotomQuest_EventScript_RotomTVCutscene_2
RotomQuest_EventScript_RotomTVCutscene_1:
# 81 "data/scripts/rotom_quest.pory"
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_ROTOM
# 82 "data/scripts/rotom_quest.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RotomQuest_EventScript_RotomTVCutscene_5
RotomQuest_EventScript_RotomTVCutscene_4:
# 85 "data/scripts/rotom_quest.pory"
	hidefollower 1
# 86 "data/scripts/rotom_quest.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 87 "data/scripts/rotom_quest.pory"
	delay 30
# 88 "data/scripts/rotom_quest.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 89 "data/scripts/rotom_quest.pory"
	applymovement LOCALID_PLAYER, RotomQuest_Movement_PlayerStepBack
# 90 "data/scripts/rotom_quest.pory"
	waitmovement 0
# 91 "data/scripts/rotom_quest.pory"
	fadescreenswapbuffers FADE_TO_WHITE
# 92 "data/scripts/rotom_quest.pory"
	delay 20
# 93 "data/scripts/rotom_quest.pory"
	clearflag FLAG_HIDE_PLAYERS_HOUSE_ROTOM
# 94 "data/scripts/rotom_quest.pory"
	addobject VAR_0x8004
# 95 "data/scripts/rotom_quest.pory"
	fadescreenswapbuffers FADE_FROM_WHITE
# 96 "data/scripts/rotom_quest.pory"
	applymovement VAR_0x8004, RotomQuest_Movement_RotomJumpOut
# 97 "data/scripts/rotom_quest.pory"
	waitmovement 0
# 98 "data/scripts/rotom_quest.pory"
	playmoncry SPECIES_ROTOM, CRY_MODE_ENCOUNTER
# 99 "data/scripts/rotom_quest.pory"
	delay 40
# 100 "data/scripts/rotom_quest.pory"
	waitmoncry
# 101 "data/scripts/rotom_quest.pory"
	setwildbattle SPECIES_ROTOM, 25
# 102 "data/scripts/rotom_quest.pory"
	dowildbattle
# 103 "data/scripts/rotom_quest.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 104 "data/scripts/rotom_quest.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq RotomQuest_EventScript_RotomTVCutscene_8
# 113 "data/scripts/rotom_quest.pory"
	removeobject VAR_0x8004
# 114 "data/scripts/rotom_quest.pory"
	setflag FLAG_HIDE_PLAYERS_HOUSE_ROTOM
# 115 "data/scripts/rotom_quest.pory"
	msgbox RotomQuest_EventScript_RotomTVCutscene_Text_1
# 116 "data/scripts/rotom_quest.pory"
	releaseall
	end

RotomQuest_EventScript_RotomTVCutscene_2:
# 79 "data/scripts/rotom_quest.pory"
	goto RotomQuest_EventScript_TVNothing
	goto RotomQuest_EventScript_RotomTVCutscene_1

RotomQuest_EventScript_RotomTVCutscene_5:
# 83 "data/scripts/rotom_quest.pory"
	goto RotomQuest_EventScript_TVNothing
	goto RotomQuest_EventScript_RotomTVCutscene_4

RotomQuest_EventScript_RotomTVCutscene_8:
# 105 "data/scripts/rotom_quest.pory"
	setflag FLAG_ROTOM_CAUGHT_FROM_TV
# 106 "data/scripts/rotom_quest.pory"
	removeobject VAR_0x8004
# 107 "data/scripts/rotom_quest.pory"
	setflag FLAG_HIDE_PLAYERS_HOUSE_ROTOM
# 108 "data/scripts/rotom_quest.pory"
	msgbox RotomQuest_EventScript_RotomTVCutscene_Text_0
# 109 "data/scripts/rotom_quest.pory"
	releaseall
	end


RotomQuest_EventScript_TVNothing::
# 121 "data/scripts/rotom_quest.pory"
	lockall
# 122 "data/scripts/rotom_quest.pory"
	msgbox RotomQuest_EventScript_TVNothing_Text_0
# 123 "data/scripts/rotom_quest.pory"
	releaseall
	end


RotomQuest_EventScript_Mom_Text_0:
# 44 "data/scripts/rotom_quest.pory"
	.string "MOM: Oh! So THAT'S what was rattling\n"
	.string "around up there--a Rotom!\p"
	.string "And here I was ready to call in a\n"
	.string "ghost exorcist. Ha ha!\p"
	.string "Thank you, {PLAYER}. I've sent a\n"
	.string "little something to your Quest app.$"

RotomQuest_EventScript_Mom_Text_1:
# 49 "data/scripts/rotom_quest.pory"
	.string "MOM: You can still hear it, can't you?\n"
	.string "That awful noise from your room…\p"
	.string "Do have a proper look at that TV\n"
	.string "for me, dear.$"

RotomQuest_EventScript_Mom_Text_2:
# 57 "data/scripts/rotom_quest.pory"
	.string "MOM: Don't forget the little thank-you\n"
	.string "I left in your Quest app!$"

RotomQuest_EventScript_Mom_Text_3:
# 66 "data/scripts/rotom_quest.pory"
	.string "MOM: There you are! Listen…\p"
	.string "That noise is coming from the TV in\n"
	.string "your room. A groaning, buzzing sound.\p"
	.string "I switched it off at the wall and it\n"
	.string "STILL won't stop.\p"
	.string "You don't suppose it's… a g-ghost?\p"
	.string "Oh, would you go up and check? I can't\n"
	.string "bear to look myself.$"

RotomQuest_EventScript_RotomTVCutscene_Text_0:
# 108 "data/scripts/rotom_quest.pory"
	.string "So the 'ghost' was a Rotom living\n"
	.string "inside the TV!\p"
	.string "You'd better go show Mom.$"

RotomQuest_EventScript_RotomTVCutscene_Text_1:
# 115 "data/scripts/rotom_quest.pory"
	.string "The Rotom slipped back into the TV\n"
	.string "with a crackle of static…$"

RotomQuest_EventScript_TVNothing_Text_0:
# 122 "data/scripts/rotom_quest.pory"
	.string "There's nothing but static on the\n"
	.string "screen right now.$"

RotomQuest_Text_MomCall::
# 17 "data/scripts/rotom_quest.pory"
	.string "MOM: {PLAYER}? It's Mom.\p"
	.string "I don't want to worry you, but…\p"
	.string "there's a strange noise coming from\n"
	.string "your room upstairs. It won't stop.\p"
	.string "Would you come home when you get\n"
	.string "the chance, dear?$"
