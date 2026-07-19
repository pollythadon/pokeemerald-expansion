# 1 "data/maps/DesertUnderpass/scripts.pory"
DesertUnderpass_MapScripts::
# 2 "data/maps/DesertUnderpass/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DesertUnderpass_OnTransition
# 3 "data/maps/DesertUnderpass/scripts.pory"
	.byte 0
# 4 "data/maps/DesertUnderpass/scripts.pory"

# 5 "data/maps/DesertUnderpass/scripts.pory"
DesertUnderpass_OnTransition:
# 6 "data/maps/DesertUnderpass/scripts.pory"
	setflag FLAG_LANDMARK_DESERT_UNDERPASS
# 7 "data/maps/DesertUnderpass/scripts.pory"
	end
# 8 "data/maps/DesertUnderpass/scripts.pory"

# 9 "data/maps/DesertUnderpass/scripts.pory"
DesertUnderpass_EventScript_Fossil::
# 10 "data/maps/DesertUnderpass/scripts.pory"
	lock
# 11 "data/maps/DesertUnderpass/scripts.pory"
	faceplayer
# 12 "data/maps/DesertUnderpass/scripts.pory"
	goto_if_set FLAG_CHOSE_ROOT_FOSSIL, DesertUnderpass_EventScript_GiveClawFossil
# 13 "data/maps/DesertUnderpass/scripts.pory"
	goto_if_set FLAG_CHOSE_CLAW_FOSSIL, DesertUnderpass_EventScript_GiveRootFossil
# 14 "data/maps/DesertUnderpass/scripts.pory"
	release
# 15 "data/maps/DesertUnderpass/scripts.pory"
	end
# 16 "data/maps/DesertUnderpass/scripts.pory"

# 17 "data/maps/DesertUnderpass/scripts.pory"
DesertUnderpass_EventScript_GiveClawFossil::
# 18 "data/maps/DesertUnderpass/scripts.pory"
	giveitem ITEM_CLAW_FOSSIL
# 19 "data/maps/DesertUnderpass/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 20 "data/maps/DesertUnderpass/scripts.pory"
	removeobject LOCALID_UNDERPASS_FOSSIL
# 21 "data/maps/DesertUnderpass/scripts.pory"
	release
# 22 "data/maps/DesertUnderpass/scripts.pory"
	end
# 23 "data/maps/DesertUnderpass/scripts.pory"

# 24 "data/maps/DesertUnderpass/scripts.pory"
DesertUnderpass_EventScript_GiveRootFossil::
# 25 "data/maps/DesertUnderpass/scripts.pory"
	giveitem ITEM_ROOT_FOSSIL
# 26 "data/maps/DesertUnderpass/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 27 "data/maps/DesertUnderpass/scripts.pory"
	removeobject LOCALID_UNDERPASS_FOSSIL
# 28 "data/maps/DesertUnderpass/scripts.pory"
	release
# 29 "data/maps/DesertUnderpass/scripts.pory"
	end
# 30 "data/maps/DesertUnderpass/scripts.pory"

# 31 "data/maps/DesertUnderpass/scripts.pory"
@ Unused
# 32 "data/maps/DesertUnderpass/scripts.pory"
DesertUnderpass_Text_FoundRootFossil::
# 33 "data/maps/DesertUnderpass/scripts.pory"
	.string "{PLAYER} found the ROOT FOSSIL.$"
# 34 "data/maps/DesertUnderpass/scripts.pory"

# 35 "data/maps/DesertUnderpass/scripts.pory"
@ Unused
# 36 "data/maps/DesertUnderpass/scripts.pory"
DesertUnderpass_Text_FoundClawFossil::
# 37 "data/maps/DesertUnderpass/scripts.pory"
	.string "{PLAYER} found the CLAW FOSSIL.$"

DesertUnderpass_EventScript_Regigigas::
# 42 "data/maps/DesertUnderpass/scripts.pory"
	lockall
# 43 "data/maps/DesertUnderpass/scripts.pory"
	faceplayer
# 47 "data/maps/DesertUnderpass/scripts.pory"
	goto_if_set FLAG_LEGENDARY_BTL, DesertUnderpass_EventScript_Regigigas_2
# 55 "data/maps/DesertUnderpass/scripts.pory"
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_REGIROCK
# 56 "data/maps/DesertUnderpass/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq DesertUnderpass_EventScript_Regigigas_5
DesertUnderpass_EventScript_Regigigas_4:
# 59 "data/maps/DesertUnderpass/scripts.pory"
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_REGICE
# 60 "data/maps/DesertUnderpass/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq DesertUnderpass_EventScript_Regigigas_8
DesertUnderpass_EventScript_Regigigas_7:
# 63 "data/maps/DesertUnderpass/scripts.pory"
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_REGISTEEL
# 64 "data/maps/DesertUnderpass/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq DesertUnderpass_EventScript_Regigigas_11
DesertUnderpass_EventScript_Regigigas_10:
# 70 "data/maps/DesertUnderpass/scripts.pory"
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_REGIGIGAS
# 71 "data/maps/DesertUnderpass/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq DesertUnderpass_EventScript_Regigigas_14
DesertUnderpass_EventScript_Regigigas_13:
	checkpartymon SPECIES_REGIROCK
# 0 "data/maps/DesertUnderpass/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DesertUnderpass_EventScript_Regigigas_17
	checkpartymon SPECIES_REGICE
# 0 "data/maps/DesertUnderpass/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DesertUnderpass_EventScript_Regigigas_17
	checkpartymon SPECIES_REGISTEEL
# 0 "data/maps/DesertUnderpass/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_eq DesertUnderpass_EventScript_Regigigas_17
# 82 "data/maps/DesertUnderpass/scripts.pory"
	msgbox DesertUnderpass_EventScript_Regigigas_Text_2, MSGBOX_AUTOCLOSE
# 83 "data/maps/DesertUnderpass/scripts.pory"
	closemessage
# 84 "data/maps/DesertUnderpass/scripts.pory"
	playse SE_TRUCK_MOVE
# 85 "data/maps/DesertUnderpass/scripts.pory"
	special DoSealedChamberShakingEffect_Short
# 86 "data/maps/DesertUnderpass/scripts.pory"
	applymovement LOCALID_REGIGIGAS, DesertUnderpass_Movement_RegigigasAwakens
# 87 "data/maps/DesertUnderpass/scripts.pory"
	waitmovement 0
# 88 "data/maps/DesertUnderpass/scripts.pory"
	playmoncry SPECIES_REGIGIGAS, CRY_MODE_ENCOUNTER
# 89 "data/maps/DesertUnderpass/scripts.pory"
	delay 40
# 90 "data/maps/DesertUnderpass/scripts.pory"
	waitmoncry
# 91 "data/maps/DesertUnderpass/scripts.pory"
	msgbox DesertUnderpass_EventScript_Regigigas_Text_3, MSGBOX_AUTOCLOSE
# 92 "data/maps/DesertUnderpass/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_REGIGIGAS
# 93 "data/maps/DesertUnderpass/scripts.pory"
	setwildbattle SPECIES_REGIGIGAS, 80
# 94 "data/maps/DesertUnderpass/scripts.pory"
	special StartRegiBattle
# 95 "data/maps/DesertUnderpass/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 96 "data/maps/DesertUnderpass/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq DesertUnderpass_EventScript_Regigigas_24
# 96 "data/maps/DesertUnderpass/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq DesertUnderpass_EventScript_Regigigas_24
# 99 "data/maps/DesertUnderpass/scripts.pory"
	call DesertUnderpass_EventScript_RegigigasEscaped
DesertUnderpass_EventScript_Regigigas_23:
# 101 "data/maps/DesertUnderpass/scripts.pory"
	releaseall
	end

DesertUnderpass_EventScript_Regigigas_2:
# 48 "data/maps/DesertUnderpass/scripts.pory"
	msgbox DesertUnderpass_EventScript_Regigigas_Text_0
# 49 "data/maps/DesertUnderpass/scripts.pory"
	releaseall
	end

DesertUnderpass_EventScript_Regigigas_5:
# 57 "data/maps/DesertUnderpass/scripts.pory"
	goto DesertUnderpass_EventScript_RegigigasSealsIntact
	goto DesertUnderpass_EventScript_Regigigas_4

DesertUnderpass_EventScript_Regigigas_8:
# 61 "data/maps/DesertUnderpass/scripts.pory"
	goto DesertUnderpass_EventScript_RegigigasSealsIntact
	goto DesertUnderpass_EventScript_Regigigas_7

DesertUnderpass_EventScript_Regigigas_11:
# 65 "data/maps/DesertUnderpass/scripts.pory"
	goto DesertUnderpass_EventScript_RegigigasSealsIntact
	goto DesertUnderpass_EventScript_Regigigas_10

DesertUnderpass_EventScript_Regigigas_14:
# 72 "data/maps/DesertUnderpass/scripts.pory"
	startquest QUEST_REGIGIGAS
	goto DesertUnderpass_EventScript_Regigigas_13

DesertUnderpass_EventScript_Regigigas_17:
# 76 "data/maps/DesertUnderpass/scripts.pory"
	msgbox DesertUnderpass_EventScript_Regigigas_Text_1
# 78 "data/maps/DesertUnderpass/scripts.pory"
	releaseall
	end

DesertUnderpass_EventScript_Regigigas_24:
# 97 "data/maps/DesertUnderpass/scripts.pory"
	call DesertUnderpass_EventScript_RegigigasDefeated
	goto DesertUnderpass_EventScript_Regigigas_23


DesertUnderpass_EventScript_RegigigasSealsIntact::
# 106 "data/maps/DesertUnderpass/scripts.pory"
	msgbox DesertUnderpass_EventScript_RegigigasSealsIntact_Text_0
# 108 "data/maps/DesertUnderpass/scripts.pory"
	releaseall
	end


DesertUnderpass_EventScript_RegigigasDefeated::
# 113 "data/maps/DesertUnderpass/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 114 "data/maps/DesertUnderpass/scripts.pory"
	removeobject LOCALID_REGIGIGAS
# 115 "data/maps/DesertUnderpass/scripts.pory"
	setflag FLAG_REGIGIGAS_BATTLE
# 116 "data/maps/DesertUnderpass/scripts.pory"
	setflag FLAG_REGIGIGAS_DFTD
# 117 "data/maps/DesertUnderpass/scripts.pory"
	completequest QUEST_REGIGIGAS
# 118 "data/maps/DesertUnderpass/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 119 "data/maps/DesertUnderpass/scripts.pory"
	msgbox DesertUnderpass_EventScript_RegigigasDefeated_Text_0
	return


DesertUnderpass_EventScript_RegigigasEscaped::
# 124 "data/maps/DesertUnderpass/scripts.pory"
	playmoncry SPECIES_REGIGIGAS, CRY_MODE_ENCOUNTER
# 125 "data/maps/DesertUnderpass/scripts.pory"
	delay 20
# 126 "data/maps/DesertUnderpass/scripts.pory"
	msgbox DesertUnderpass_EventScript_RegigigasEscaped_Text_0
	return


# 130 "data/maps/DesertUnderpass/scripts.pory"
DesertUnderpass_Movement_RegigigasAwakens:
# 131 "data/maps/DesertUnderpass/scripts.pory"
	walk_in_place_faster_down
# 131 "data/maps/DesertUnderpass/scripts.pory"
	walk_in_place_faster_down
# 131 "data/maps/DesertUnderpass/scripts.pory"
	walk_in_place_faster_down
# 131 "data/maps/DesertUnderpass/scripts.pory"
	walk_in_place_faster_down
# 132 "data/maps/DesertUnderpass/scripts.pory"
	jump_in_place_down
# 133 "data/maps/DesertUnderpass/scripts.pory"
	walk_in_place_faster_down
# 133 "data/maps/DesertUnderpass/scripts.pory"
	walk_in_place_faster_down
# 134 "data/maps/DesertUnderpass/scripts.pory"
	face_player
	step_end

DesertUnderpass_EventScript_Regigigas_Text_0:
# 48 "data/maps/DesertUnderpass/scripts.pory"
	.string "A colossal stone statue towers over\n"
	.string "you. Its body is cold and perfectly\l"
	.string "still.$"

DesertUnderpass_EventScript_Regigigas_Text_1:
# 76 "data/maps/DesertUnderpass/scripts.pory"
	.string "Three patterns are carved into the\n"
	.string "statue's base. They resemble Regirock,\l"
	.string "Regice, and Registeel.\p"
	.string "The ancient titan may awaken if all\n"
	.string "three stand before it together.$"

DesertUnderpass_EventScript_Regigigas_Text_2:
# 82 "data/maps/DesertUnderpass/scripts.pory"
	.string "The three titans resonate as one. Deep\n"
	.string "within the statue, something begins to\l"
	.string "move...$"

DesertUnderpass_EventScript_Regigigas_Text_3:
# 91 "data/maps/DesertUnderpass/scripts.pory"
	.string "REGIGIGAS has awakened!$"

DesertUnderpass_EventScript_RegigigasSealsIntact_Text_0:
# 106 "data/maps/DesertUnderpass/scripts.pory"
	.string "The statue's three carved patterns\n"
	.string "remain dark.\p"
	.string "Somewhere across Hoenn, the ancient\n"
	.string "seals of Regirock, Regice, and Registeel\l"
	.string "remain unbroken.$"

DesertUnderpass_EventScript_RegigigasDefeated_Text_0:
# 119 "data/maps/DesertUnderpass/scripts.pory"
	.string "The ancient titan's footsteps fade,\n"
	.string "and the Desert Underpass falls silent\l"
	.string "once more.$"

DesertUnderpass_EventScript_RegigigasEscaped_Text_0:
# 126 "data/maps/DesertUnderpass/scripts.pory"
	.string "Regigigas grinds to a halt and becomes\n"
	.string "as still as stone once more. Return when\l"
	.string "you are ready.$"
