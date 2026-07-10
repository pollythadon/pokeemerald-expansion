# 1 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
MeteorFalls_B1F_2R_MapScripts::
# 2 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	.byte 0

Legendary_EventScript_PALKIA::
# 7 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	lockall
# 8 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	goto_if_set FLAG_PALKIA_DFTD, Legendary_EventScript_PALKIA_2
	checkitem ITEM_LUSTROUS_ORB
# 0 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Legendary_EventScript_PALKIA_5
Legendary_EventScript_PALKIA_4:
# 48 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	msgbox Legendary_EventScript_PALKIA_Text_6
# 49 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	releaseall
	end

Legendary_EventScript_PALKIA_2:
# 9 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	msgbox Legendary_EventScript_PALKIA_Text_0
# 10 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	releaseall
	end

Legendary_EventScript_PALKIA_5:
# 14 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	msgbox Legendary_EventScript_PALKIA_Text_1
# 15 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	msgbox Legendary_EventScript_PALKIA_Text_2, MSGBOX_YESNO
# 16 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	switch VAR_RESULT
# 17 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	case YES, Legendary_EventScript_PALKIA_8
# 42 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	case NO, Legendary_EventScript_PALKIA_9
	goto Legendary_EventScript_PALKIA_4

Legendary_EventScript_PALKIA_8:
# 18 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	msgbox Legendary_EventScript_PALKIA_Text_3, MSGBOX_AUTOCLOSE
# 19 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	fadescreenswapbuffers FADE_TO_WHITE
# 20 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	delay 30
# 21 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	fadescreenswapbuffers FADE_FROM_WHITE
# 22 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	playmoncry SPECIES_PALKIA, CRY_MODE_ENCOUNTER
# 23 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	msgbox Legendary_EventScript_PALKIA_Text_4, MSGBOX_AUTOCLOSE
# 24 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	playmoncry SPECIES_PALKIA, CRY_MODE_ENCOUNTER
# 25 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	delay 40
# 26 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	waitmoncry
# 27 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	setwildbattle SPECIES_PALKIA, 80
# 28 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 29 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	waitstate
# 30 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 31 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Legendary_EventScript_PALKIA_11
# 33 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Legendary_EventScript_PALKIA_12
# 35 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Legendary_EventScript_PALKIA_13
# 37 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Legendary_EventScript_PALKIA_14
Legendary_EventScript_PALKIA_10:
# 40 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	releaseall
	end

Legendary_EventScript_PALKIA_9:
# 43 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	msgbox Legendary_EventScript_PALKIA_Text_5
# 44 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	releaseall
	end

Legendary_EventScript_PALKIA_11:
# 32 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	call PALKIAWon_or_Caught
	goto Legendary_EventScript_PALKIA_10

Legendary_EventScript_PALKIA_12:
# 34 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	call PALKIAWon_or_Caught
	goto Legendary_EventScript_PALKIA_10

Legendary_EventScript_PALKIA_13:
# 36 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	call PALKIARanAway
	goto Legendary_EventScript_PALKIA_10

Legendary_EventScript_PALKIA_14:
# 38 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	call PALKIARanAway
	goto Legendary_EventScript_PALKIA_10


PALKIAWon_or_Caught::
# 54 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	fadescreenswapbuffers FADE_TO_WHITE
# 55 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	removeobject 2
# 56 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	setflag FLAG_PALKIA_BATTLE
# 57 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	setflag FLAG_PALKIA_DFTD
# 58 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	completequest QUEST_PALKIA
# 59 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	fadescreenswapbuffers FADE_FROM_WHITE
# 60 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	msgbox PALKIAWon_or_Caught_Text_0
	return


PALKIARanAway::
# 65 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	playmoncry SPECIES_PALKIA, CRY_MODE_ENCOUNTER
# 66 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	delay 20
# 67 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	fadescreenswapbuffers FADE_TO_WHITE
# 68 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	hideobjectat 2, MAP_METEOR_FALLS_B1F_2R
# 69 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	fadescreenswapbuffers FADE_FROM_WHITE
# 70 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	msgbox PALKIARanAway_Text_0
	return


Legendary_EventScript_PALKIA_Text_0:
# 9 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	.string "The gap between space has closed.$"

Legendary_EventScript_PALKIA_Text_1:
# 14 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	.string "The Lustrous Orb hums, and the ground\n"
	.string "seems both an inch and a mile away...$"

Legendary_EventScript_PALKIA_Text_2:
# 15 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	.string "Raise the Orb?$"

Legendary_EventScript_PALKIA_Text_3:
# 18 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	.string "The world folds like wet paper. Up is\n"
	.string "sideways. Far is here.$"

Legendary_EventScript_PALKIA_Text_4:
# 23 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	.string "It's closer than close, and somehow\n"
	.string "still distant.$"

Legendary_EventScript_PALKIA_Text_5:
# 43 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	.string "Better to leave the lines where they\n"
	.string "are.$"

Legendary_EventScript_PALKIA_Text_6:
# 48 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	.string "Something about the distances here\n"
	.string "refuses to stay still...$"

PALKIAWon_or_Caught_Text_0:
# 60 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	.string "The horizon snaps back into place. The\n"
	.string "world feels... measured again.$"

PALKIARanAway_Text_0:
# 70 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	.string "It folded the space between us and was\n"
	.string "simply... elsewhere.$"
