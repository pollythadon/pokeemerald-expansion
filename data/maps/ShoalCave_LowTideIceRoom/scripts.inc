ShoalCave_LowTideIceRoom_MapScripts::
# 7 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ShoalCave_LowTideIceRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

ShoalCave_LowTideIceRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION:
# 8 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	goto_if_set FLAG_KYUREM_CAUGHT, ShoalCave_LowTideIceRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
# 11 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_KYUREM
# 12 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ShoalCave_LowTideIceRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
# 16 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	setflag FLAG_HIDE_KYUREM
	return

ShoalCave_LowTideIceRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
# 9 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	setflag FLAG_HIDE_KYUREM
	return

ShoalCave_LowTideIceRoom_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
# 13 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	clearflag FLAG_HIDE_KYUREM
# 14 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	setvar VAR_TEMP_1, 1
	return


ShoalCave_LowTideIceRoom_EventScript_Kyurem::
# 23 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	lockall
# 24 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	setvar VAR_TEMP_1, 0
# 25 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
# 26 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	waitmovement 0
# 27 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	delay 20
# 28 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	playmoncry SPECIES_KYUREM, CRY_MODE_ENCOUNTER
# 29 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	delay 40
# 30 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	waitmoncry
# 31 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_SHOAL_ICE_KYUREM
# 32 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	setwildbattle SPECIES_KYUREM, 80
# 33 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 34 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	waitstate
# 35 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 36 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq ShoalCave_LowTideIceRoom_EventScript_Kyurem_2
# 39 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	call ShoalCave_LowTideIceRoom_EventScript_KyuremNotCaught
ShoalCave_LowTideIceRoom_EventScript_Kyurem_1:
# 41 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	releaseall
	end

ShoalCave_LowTideIceRoom_EventScript_Kyurem_2:
# 37 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	call ShoalCave_LowTideIceRoom_EventScript_KyuremCaught
	goto ShoalCave_LowTideIceRoom_EventScript_Kyurem_1


ShoalCave_LowTideIceRoom_EventScript_KyuremCaught::
# 46 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	setflag FLAG_KYUREM_CAUGHT
# 47 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	setflag FLAG_HIDE_KYUREM
# 48 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	removeobject LOCALID_SHOAL_ICE_KYUREM
# 49 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	completequest QUEST_KYUREM
# 50 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	msgbox ShoalCave_LowTideIceRoom_EventScript_KyuremCaught_Text_0
	return


ShoalCave_LowTideIceRoom_EventScript_KyuremNotCaught::
# 56 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	playmoncry SPECIES_KYUREM, CRY_MODE_ENCOUNTER
# 57 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	delay 20
# 58 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 59 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	hideobjectat LOCALID_SHOAL_ICE_KYUREM, MAP_SHOAL_CAVE_LOW_TIDE_ICE_ROOM
# 60 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 61 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	msgbox ShoalCave_LowTideIceRoom_EventScript_KyuremNotCaught_Text_0
	return


ShoalCave_LowTideIceRoom_EventScript_KyuremCaught_Text_0:
# 50 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	.string "The ice room falls silent. Kyurem, the\n"
	.string "hollow husk of the original dragon, is\l"
	.string "yours now. The legend is whole.$"

ShoalCave_LowTideIceRoom_EventScript_KyuremNotCaught_Text_0:
# 61 "data/maps/ShoalCave_LowTideIceRoom/scripts.pory"
	.string "Kyurem sinks into a shroud of frost and\n"
	.string "is gone... for now. Return when you are\l"
	.string "ready to catch it.$"
