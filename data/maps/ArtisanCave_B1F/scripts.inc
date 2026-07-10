# 1 "data/maps/ArtisanCave_B1F/scripts.pory"
ArtisanCave_B1F_MapScripts::
# 2 "data/maps/ArtisanCave_B1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ArtisanCave_B1F_OnTransition
# 3 "data/maps/ArtisanCave_B1F/scripts.pory"
	.byte 0
# 4 "data/maps/ArtisanCave_B1F/scripts.pory"

# 5 "data/maps/ArtisanCave_B1F/scripts.pory"
ArtisanCave_B1F_OnTransition:
# 6 "data/maps/ArtisanCave_B1F/scripts.pory"
	setflag FLAG_LANDMARK_ARTISAN_CAVE
# 7 "data/maps/ArtisanCave_B1F/scripts.pory"
	end

Legendary_EventScript_MEWTWO::
# 12 "data/maps/ArtisanCave_B1F/scripts.pory"
	lockall
# 13 "data/maps/ArtisanCave_B1F/scripts.pory"
	goto_if_set FLAG_MEWTWO_DFTD, Legendary_EventScript_MEWTWO_2
	checkitem ITEM_MEWTWONITE_X
# 0 "data/maps/ArtisanCave_B1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Legendary_EventScript_MEWTWO_5
	checkitem ITEM_MEWTWONITE_Y
# 0 "data/maps/ArtisanCave_B1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Legendary_EventScript_MEWTWO_5
Legendary_EventScript_MEWTWO_4:
# 52 "data/maps/ArtisanCave_B1F/scripts.pory"
	releaseall
	end

Legendary_EventScript_MEWTWO_2:
# 14 "data/maps/ArtisanCave_B1F/scripts.pory"
	msgbox Legendary_EventScript_MEWTWO_Text_0
# 15 "data/maps/ArtisanCave_B1F/scripts.pory"
	releaseall
	end

Legendary_EventScript_MEWTWO_5:
# 19 "data/maps/ArtisanCave_B1F/scripts.pory"
	msgbox Legendary_EventScript_MEWTWO_Text_1, MSGBOX_YESNO
# 20 "data/maps/ArtisanCave_B1F/scripts.pory"
	switch VAR_RESULT
# 21 "data/maps/ArtisanCave_B1F/scripts.pory"
	case YES, Legendary_EventScript_MEWTWO_10
# 46 "data/maps/ArtisanCave_B1F/scripts.pory"
	case NO, Legendary_EventScript_MEWTWO_11
	goto Legendary_EventScript_MEWTWO_4

Legendary_EventScript_MEWTWO_10:
# 22 "data/maps/ArtisanCave_B1F/scripts.pory"
	msgbox Legendary_EventScript_MEWTWO_Text_2, MSGBOX_AUTOCLOSE
# 23 "data/maps/ArtisanCave_B1F/scripts.pory"
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
# 24 "data/maps/ArtisanCave_B1F/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 25 "data/maps/ArtisanCave_B1F/scripts.pory"
	delay 40
# 26 "data/maps/ArtisanCave_B1F/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 27 "data/maps/ArtisanCave_B1F/scripts.pory"
	msgbox Legendary_EventScript_MEWTWO_Text_3, MSGBOX_AUTOCLOSE
# 28 "data/maps/ArtisanCave_B1F/scripts.pory"
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
# 29 "data/maps/ArtisanCave_B1F/scripts.pory"
	delay 40
# 30 "data/maps/ArtisanCave_B1F/scripts.pory"
	waitmoncry
# 31 "data/maps/ArtisanCave_B1F/scripts.pory"
	setwildbattle SPECIES_MEWTWO, 80
# 32 "data/maps/ArtisanCave_B1F/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 33 "data/maps/ArtisanCave_B1F/scripts.pory"
	waitstate
# 34 "data/maps/ArtisanCave_B1F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 35 "data/maps/ArtisanCave_B1F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Legendary_EventScript_MEWTWO_13
# 37 "data/maps/ArtisanCave_B1F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Legendary_EventScript_MEWTWO_14
# 39 "data/maps/ArtisanCave_B1F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Legendary_EventScript_MEWTWO_15
# 41 "data/maps/ArtisanCave_B1F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Legendary_EventScript_MEWTWO_16
Legendary_EventScript_MEWTWO_12:
# 44 "data/maps/ArtisanCave_B1F/scripts.pory"
	releaseall
	end

Legendary_EventScript_MEWTWO_11:
# 47 "data/maps/ArtisanCave_B1F/scripts.pory"
	msgbox Legendary_EventScript_MEWTWO_Text_4
# 48 "data/maps/ArtisanCave_B1F/scripts.pory"
	releaseall
	end

Legendary_EventScript_MEWTWO_13:
# 36 "data/maps/ArtisanCave_B1F/scripts.pory"
	call MEWTWOCaught
	goto Legendary_EventScript_MEWTWO_12

Legendary_EventScript_MEWTWO_14:
# 38 "data/maps/ArtisanCave_B1F/scripts.pory"
	call MEWTWOWon
	goto Legendary_EventScript_MEWTWO_12

Legendary_EventScript_MEWTWO_15:
# 40 "data/maps/ArtisanCave_B1F/scripts.pory"
	call MEWTWORanAway
	goto Legendary_EventScript_MEWTWO_12

Legendary_EventScript_MEWTWO_16:
# 42 "data/maps/ArtisanCave_B1F/scripts.pory"
	call MEWTWORanAway
	goto Legendary_EventScript_MEWTWO_12


MEWTWOCaught::
# 57 "data/maps/ArtisanCave_B1F/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 58 "data/maps/ArtisanCave_B1F/scripts.pory"
	removeobject 2
# 59 "data/maps/ArtisanCave_B1F/scripts.pory"
	setflag FLAG_MEWTWO_BATTLE
# 60 "data/maps/ArtisanCave_B1F/scripts.pory"
	setflag FLAG_MEWTWO_DFTD
# 61 "data/maps/ArtisanCave_B1F/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 62 "data/maps/ArtisanCave_B1F/scripts.pory"
	msgbox MEWTWOCaught_Text_0
	return


MEWTWOWon::
# 67 "data/maps/ArtisanCave_B1F/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 68 "data/maps/ArtisanCave_B1F/scripts.pory"
	removeobject 2
# 69 "data/maps/ArtisanCave_B1F/scripts.pory"
	setflag FLAG_MEWTWO_BATTLE
# 70 "data/maps/ArtisanCave_B1F/scripts.pory"
	setflag FLAG_MEWTWO_DFTD
# 71 "data/maps/ArtisanCave_B1F/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 72 "data/maps/ArtisanCave_B1F/scripts.pory"
	msgbox MEWTWOCaught_Text_0
	return


MEWTWORanAway::
# 77 "data/maps/ArtisanCave_B1F/scripts.pory"
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
# 78 "data/maps/ArtisanCave_B1F/scripts.pory"
	delay 20
# 79 "data/maps/ArtisanCave_B1F/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 80 "data/maps/ArtisanCave_B1F/scripts.pory"
	hideobjectat 2, MAP_ARTISAN_CAVE_B1F
# 81 "data/maps/ArtisanCave_B1F/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 82 "data/maps/ArtisanCave_B1F/scripts.pory"
	msgbox MEWTWORanAway_Text_0
	return


Legendary_EventScript_MEWTWO_Text_0:
# 14 "data/maps/ArtisanCave_B1F/scripts.pory"
	.string "The power that was here is gone.$"

Legendary_EventScript_MEWTWO_Text_1:
# 19 "data/maps/ArtisanCave_B1F/scripts.pory"
	.string "Speak from the heart?$"

Legendary_EventScript_MEWTWO_Text_2:
# 22 "data/maps/ArtisanCave_B1F/scripts.pory"
	.string "Those Words. You remind me of someone I\n"
	.string "once knew.$"

Legendary_EventScript_MEWTWO_Text_3:
# 27 "data/maps/ArtisanCave_B1F/scripts.pory"
	.string "I was made to be a weapon. I decided to\n"
	.string "be free. Show me which of us is\l"
	.string "stronger.$"

Legendary_EventScript_MEWTWO_Text_4:
# 47 "data/maps/ArtisanCave_B1F/scripts.pory"
	.string "Better not to wake what the fire left\n"
	.string "behind.$"

MEWTWOCaught_Text_0:
# 62 "data/maps/ArtisanCave_B1F/scripts.pory"
	.string "I see. I was wrong about you. You are\n"
	.string "not like the others.$"

MEWTWORanAway_Text_0:
# 82 "data/maps/ArtisanCave_B1F/scripts.pory"
	.string "All you humans are the same. I will not\n"
	.string "be caught again.$"
