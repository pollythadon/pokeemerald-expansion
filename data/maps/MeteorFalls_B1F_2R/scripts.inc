# 1 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
MeteorFalls_B1F_2R_MapScripts::
# 2 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	.byte 0

Legendary_EventScript_PALKIA::
# 7 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	lockall
	checkitem ITEM_LUSTROUS_ORB
# 0 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Legendary_EventScript_PALKIA_2
Legendary_EventScript_PALKIA_1:
# 43 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	msgbox Legendary_EventScript_PALKIA_Text_5
# 44 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	release
	end

Legendary_EventScript_PALKIA_2:
# 9 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	msgbox Legendary_EventScript_PALKIA_Text_0
# 10 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	msgbox Legendary_EventScript_PALKIA_Text_1, MSGBOX_YESNO
# 11 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	switch VAR_RESULT
# 12 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	case YES, Legendary_EventScript_PALKIA_5
# 37 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	case NO, Legendary_EventScript_PALKIA_6
	goto Legendary_EventScript_PALKIA_1

Legendary_EventScript_PALKIA_5:
# 13 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	msgbox Legendary_EventScript_PALKIA_Text_2, MSGBOX_AUTOCLOSE
# 14 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	fadescreenswapbuffers FADE_TO_WHITE
# 15 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	delay 30
# 16 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	fadescreenswapbuffers FADE_FROM_WHITE
# 17 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	playmoncry SPECIES_PALKIA, CRY_MODE_ENCOUNTER
# 18 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	msgbox Legendary_EventScript_PALKIA_Text_3, MSGBOX_AUTOCLOSE
# 19 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	playmoncry SPECIES_PALKIA, CRY_MODE_ENCOUNTER
# 20 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	delay 40
# 21 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	waitmoncry
# 22 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	setwildbattle SPECIES_PALKIA, 80
# 23 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 24 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	waitstate
# 25 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 26 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Legendary_EventScript_PALKIA_8
# 28 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Legendary_EventScript_PALKIA_9
# 30 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Legendary_EventScript_PALKIA_10
# 32 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Legendary_EventScript_PALKIA_11
Legendary_EventScript_PALKIA_7:
# 35 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	releaseall
	end

Legendary_EventScript_PALKIA_6:
# 38 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	msgbox Legendary_EventScript_PALKIA_Text_4
# 39 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	release
	end

Legendary_EventScript_PALKIA_8:
# 27 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	call PALKIAWon_or_Caught
	goto Legendary_EventScript_PALKIA_7

Legendary_EventScript_PALKIA_9:
# 29 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	call PALKIAWon_or_Caught
	goto Legendary_EventScript_PALKIA_7

Legendary_EventScript_PALKIA_10:
# 31 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	call PALKIARanAway
	goto Legendary_EventScript_PALKIA_7

Legendary_EventScript_PALKIA_11:
# 33 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	call PALKIARanAway
	goto Legendary_EventScript_PALKIA_7


PALKIAWon_or_Caught::
# 49 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	fadescreenswapbuffers FADE_TO_WHITE
# 50 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	removeobject 2
# 51 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	setflag FLAG_PALKIA_BATTLE
# 52 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	fadescreenswapbuffers FADE_FROM_WHITE
# 53 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	msgbox PALKIAWon_or_Caught_Text_0
	return


PALKIARanAway::
# 58 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	playmoncry SPECIES_PALKIA, CRY_MODE_ENCOUNTER
# 59 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	delay 20
# 60 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	fadescreenswapbuffers FADE_TO_WHITE
# 61 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	removeobject 2
# 62 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	setflag FLAG_PALKIA_BATTLE
# 63 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	fadescreenswapbuffers FADE_FROM_WHITE
# 64 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	msgbox PALKIARanAway_Text_0
	return


Legendary_EventScript_PALKIA_Text_0:
# 9 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	.string "The Lustrous Orb hums, and the ground\n"
	.string "seems both an inch and a mile away...$"

Legendary_EventScript_PALKIA_Text_1:
# 10 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	.string "Raise the Orb?$"

Legendary_EventScript_PALKIA_Text_2:
# 13 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	.string "The world folds like wet paper. Up is\n"
	.string "sideways. Far is here.$"

Legendary_EventScript_PALKIA_Text_3:
# 18 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	.string "It's closer than close, and somehow\n"
	.string "still distant.$"

Legendary_EventScript_PALKIA_Text_4:
# 38 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	.string "Better to leave the lines where they\n"
	.string "are.$"

Legendary_EventScript_PALKIA_Text_5:
# 43 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	.string "Something about the distances here\n"
	.string "refuses to stay still...$"

PALKIAWon_or_Caught_Text_0:
# 53 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	.string "The horizon snaps back into place. The\n"
	.string "world feels... measured again.$"

PALKIARanAway_Text_0:
# 64 "data/maps/MeteorFalls_B1F_2R/scripts.pory"
	.string "It folded the space between us and was\n"
	.string "simply... elsewhere.$"
