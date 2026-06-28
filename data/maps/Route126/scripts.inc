# 1 "data/maps/Route126/scripts.pory"
Route126_MapScripts::
# 2 "data/maps/Route126/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route126_OnTransition
# 3 "data/maps/Route126/scripts.pory"
	.byte 0
# 4 "data/maps/Route126/scripts.pory"

# 5 "data/maps/Route126/scripts.pory"
Route126_OnTransition:
# 6 "data/maps/Route126/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 7 "data/maps/Route126/scripts.pory"
	end
# 8 "data/maps/Route126/scripts.pory"

# 9 "data/maps/Route126/scripts.pory"
Route126_EventScript_Barry::
# 10 "data/maps/Route126/scripts.pory"
	trainerbattle_single TRAINER_BARRY, Route126_Text_BarryIntro, Route126_Text_BarryDefeat
# 11 "data/maps/Route126/scripts.pory"
	msgbox Route126_Text_BarryPostBattle, MSGBOX_AUTOCLOSE
# 12 "data/maps/Route126/scripts.pory"
	end
# 13 "data/maps/Route126/scripts.pory"

# 14 "data/maps/Route126/scripts.pory"
Route126_EventScript_Dean::
# 15 "data/maps/Route126/scripts.pory"
	trainerbattle_single TRAINER_DEAN, Route126_Text_DeanIntro, Route126_Text_DeanDefeat
# 16 "data/maps/Route126/scripts.pory"
	msgbox Route126_Text_DeanPostBattle, MSGBOX_AUTOCLOSE
# 17 "data/maps/Route126/scripts.pory"
	end
# 18 "data/maps/Route126/scripts.pory"

# 19 "data/maps/Route126/scripts.pory"
Route126_EventScript_Nikki::
# 20 "data/maps/Route126/scripts.pory"
	trainerbattle_single TRAINER_NIKKI, Route126_Text_NikkiIntro, Route126_Text_NikkiDefeat
# 21 "data/maps/Route126/scripts.pory"
	msgbox Route126_Text_NikkiPostBattle, MSGBOX_AUTOCLOSE
# 22 "data/maps/Route126/scripts.pory"
	end
# 23 "data/maps/Route126/scripts.pory"

# 24 "data/maps/Route126/scripts.pory"
Route126_EventScript_Brenda::
# 25 "data/maps/Route126/scripts.pory"
	trainerbattle_single TRAINER_BRENDA, Route126_Text_BrendaIntro, Route126_Text_BrendaDefeat
# 26 "data/maps/Route126/scripts.pory"
	msgbox Route126_Text_BrendaPostBattle, MSGBOX_AUTOCLOSE
# 27 "data/maps/Route126/scripts.pory"
	end
# 28 "data/maps/Route126/scripts.pory"

# 29 "data/maps/Route126/scripts.pory"
Route126_EventScript_Leonardo::
# 30 "data/maps/Route126/scripts.pory"
	trainerbattle_single TRAINER_LEONARDO, Route126_Text_LeonardoIntro, Route126_Text_LeonardoDefeat
# 31 "data/maps/Route126/scripts.pory"
	msgbox Route126_Text_LeonardoPostBattle, MSGBOX_AUTOCLOSE
# 32 "data/maps/Route126/scripts.pory"
	end
# 33 "data/maps/Route126/scripts.pory"

# 34 "data/maps/Route126/scripts.pory"
Route126_EventScript_Isobel::
# 35 "data/maps/Route126/scripts.pory"
	trainerbattle_single TRAINER_ISOBEL, Route126_Text_IsobelIntro, Route126_Text_IsobelDefeat
# 36 "data/maps/Route126/scripts.pory"
	msgbox Route126_Text_IsobelPostBattle, MSGBOX_AUTOCLOSE
# 37 "data/maps/Route126/scripts.pory"
	end
# 38 "data/maps/Route126/scripts.pory"

# 39 "data/maps/Route126/scripts.pory"
Route126_EventScript_Sienna::
# 40 "data/maps/Route126/scripts.pory"
	trainerbattle_single TRAINER_SIENNA, Route126_Text_SiennaIntro, Route126_Text_SiennaDefeat
# 41 "data/maps/Route126/scripts.pory"
	msgbox Route126_Text_SiennaPostBattle, MSGBOX_AUTOCLOSE
# 42 "data/maps/Route126/scripts.pory"
	end
# 43 "data/maps/Route126/scripts.pory"

# 44 "data/maps/Route126/scripts.pory"
Route126_EventScript_Pablo::
# 45 "data/maps/Route126/scripts.pory"
	trainerbattle_single TRAINER_PABLO_1, Route126_Text_PabloIntro, Route126_Text_PabloDefeat, Route126_EventScript_RegisterPablo
# 46 "data/maps/Route126/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 47 "data/maps/Route126/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, Route126_EventScript_RematchPablo
# 48 "data/maps/Route126/scripts.pory"
	msgbox Route126_Text_PabloPostBattle, MSGBOX_DEFAULT
# 49 "data/maps/Route126/scripts.pory"
	release
# 50 "data/maps/Route126/scripts.pory"
	end
# 51 "data/maps/Route126/scripts.pory"

# 52 "data/maps/Route126/scripts.pory"
Route126_EventScript_RegisterPablo::
# 53 "data/maps/Route126/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 54 "data/maps/Route126/scripts.pory"
	waitmovement 0
# 55 "data/maps/Route126/scripts.pory"
	msgbox Route126_Text_PabloRegister, MSGBOX_DEFAULT
# 56 "data/maps/Route126/scripts.pory"
	register_matchcall TRAINER_PABLO_1
# 57 "data/maps/Route126/scripts.pory"
	release
# 58 "data/maps/Route126/scripts.pory"
	end
# 59 "data/maps/Route126/scripts.pory"

# 60 "data/maps/Route126/scripts.pory"
Route126_EventScript_RematchPablo::
# 61 "data/maps/Route126/scripts.pory"
	trainerbattle_rematch TRAINER_PABLO_1, Route126_Text_PabloRematchIntro, Route126_Text_PabloRematchDefeat
# 62 "data/maps/Route126/scripts.pory"
	msgbox Route126_Text_PabloPostRematch, MSGBOX_AUTOCLOSE
# 63 "data/maps/Route126/scripts.pory"
	end

Legendary_EventScript_CRESSELIA::
# 68 "data/maps/Route126/scripts.pory"
	lockall
	checkitem ITEM_DREAD_PLATE
# 0 "data/maps/Route126/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Legendary_EventScript_CRESSELIA_2
Legendary_EventScript_CRESSELIA_1:
# 108 "data/maps/Route126/scripts.pory"
	msgbox Legendary_EventScript_CRESSELIA_Text_5
# 109 "data/maps/Route126/scripts.pory"
	release
	end

Legendary_EventScript_CRESSELIA_2:
# 70 "data/maps/Route126/scripts.pory"
	msgbox Legendary_EventScript_CRESSELIA_Text_0
# 71 "data/maps/Route126/scripts.pory"
	msgbox Legendary_EventScript_CRESSELIA_Text_1, MSGBOX_YESNO
# 72 "data/maps/Route126/scripts.pory"
	switch VAR_RESULT
# 73 "data/maps/Route126/scripts.pory"
	case YES, Legendary_EventScript_CRESSELIA_5
# 102 "data/maps/Route126/scripts.pory"
	case NO, Legendary_EventScript_CRESSELIA_6
	goto Legendary_EventScript_CRESSELIA_1

Legendary_EventScript_CRESSELIA_5:
# 74 "data/maps/Route126/scripts.pory"
	clearflag FLAG_CRESSELIA_BATTLE
# 75 "data/maps/Route126/scripts.pory"
	addobject 10
# 76 "data/maps/Route126/scripts.pory"
	msgbox Legendary_EventScript_CRESSELIA_Text_2, MSGBOX_AUTOCLOSE
# 77 "data/maps/Route126/scripts.pory"
	playmoncry SPECIES_CRESSELIA, CRY_MODE_ENCOUNTER
# 78 "data/maps/Route126/scripts.pory"
	fadescreenswapbuffers FADE_TO_WHITE
# 79 "data/maps/Route126/scripts.pory"
	delay 30
# 80 "data/maps/Route126/scripts.pory"
	fadescreenswapbuffers FADE_FROM_WHITE
# 81 "data/maps/Route126/scripts.pory"
	applymovement 10, CRESSELIA_Descend
# 82 "data/maps/Route126/scripts.pory"
	waitmovement 0
# 83 "data/maps/Route126/scripts.pory"
	msgbox Legendary_EventScript_CRESSELIA_Text_3, MSGBOX_AUTOCLOSE
# 84 "data/maps/Route126/scripts.pory"
	playmoncry SPECIES_CRESSELIA, CRY_MODE_ENCOUNTER
# 85 "data/maps/Route126/scripts.pory"
	delay 40
# 86 "data/maps/Route126/scripts.pory"
	waitmoncry
# 87 "data/maps/Route126/scripts.pory"
	setwildbattle SPECIES_CRESSELIA, 70
# 88 "data/maps/Route126/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 89 "data/maps/Route126/scripts.pory"
	waitstate
# 90 "data/maps/Route126/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 91 "data/maps/Route126/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Legendary_EventScript_CRESSELIA_8
# 93 "data/maps/Route126/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Legendary_EventScript_CRESSELIA_9
# 95 "data/maps/Route126/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Legendary_EventScript_CRESSELIA_10
# 97 "data/maps/Route126/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Legendary_EventScript_CRESSELIA_11
Legendary_EventScript_CRESSELIA_7:
# 100 "data/maps/Route126/scripts.pory"
	releaseall
	end

Legendary_EventScript_CRESSELIA_6:
# 103 "data/maps/Route126/scripts.pory"
	msgbox Legendary_EventScript_CRESSELIA_Text_4
# 104 "data/maps/Route126/scripts.pory"
	release
	end

Legendary_EventScript_CRESSELIA_8:
# 92 "data/maps/Route126/scripts.pory"
	call CRESSELIAWon_or_Caught
	goto Legendary_EventScript_CRESSELIA_7

Legendary_EventScript_CRESSELIA_9:
# 94 "data/maps/Route126/scripts.pory"
	call CRESSELIAWon_or_Caught
	goto Legendary_EventScript_CRESSELIA_7

Legendary_EventScript_CRESSELIA_10:
# 96 "data/maps/Route126/scripts.pory"
	call CRESSELIARanAway
	goto Legendary_EventScript_CRESSELIA_7

Legendary_EventScript_CRESSELIA_11:
# 98 "data/maps/Route126/scripts.pory"
	call CRESSELIARanAway
	goto Legendary_EventScript_CRESSELIA_7


CRESSELIAWon_or_Caught::
# 114 "data/maps/Route126/scripts.pory"
	fadescreenswapbuffers FADE_TO_WHITE
# 115 "data/maps/Route126/scripts.pory"
	removeobject 10
# 116 "data/maps/Route126/scripts.pory"
	setflag FLAG_CRESSELIA_BATTLE
# 117 "data/maps/Route126/scripts.pory"
	fadescreenswapbuffers FADE_FROM_WHITE
# 118 "data/maps/Route126/scripts.pory"
	msgbox CRESSELIAWon_or_Caught_Text_0
	return


CRESSELIARanAway::
# 123 "data/maps/Route126/scripts.pory"
	playmoncry SPECIES_CRESSELIA, CRY_MODE_ENCOUNTER
# 124 "data/maps/Route126/scripts.pory"
	delay 20
# 125 "data/maps/Route126/scripts.pory"
	fadescreenswapbuffers FADE_TO_WHITE
# 126 "data/maps/Route126/scripts.pory"
	removeobject 10
# 127 "data/maps/Route126/scripts.pory"
	setflag FLAG_CRESSELIA_BATTLE
# 128 "data/maps/Route126/scripts.pory"
	fadescreenswapbuffers FADE_FROM_WHITE
# 129 "data/maps/Route126/scripts.pory"
	msgbox CRESSELIARanAway_Text_0
	return


# 133 "data/maps/Route126/scripts.pory"
CRESSELIA_Descend:
# 134 "data/maps/Route126/scripts.pory"
	walk_down
# 134 "data/maps/Route126/scripts.pory"
	walk_down
# 134 "data/maps/Route126/scripts.pory"
	walk_down
# 134 "data/maps/Route126/scripts.pory"
	walk_down
# 134 "data/maps/Route126/scripts.pory"
	walk_down
# 134 "data/maps/Route126/scripts.pory"
	walk_down
# 134 "data/maps/Route126/scripts.pory"
	walk_down
# 134 "data/maps/Route126/scripts.pory"
	walk_down
# 134 "data/maps/Route126/scripts.pory"
	walk_down
# 135 "data/maps/Route126/scripts.pory"
	delay_16
# 136 "data/maps/Route126/scripts.pory"
	face_player
	step_end

Legendary_EventScript_CRESSELIA_Text_0:
# 70 "data/maps/Route126/scripts.pory"
	.string "Moonlight pools on the water like\n"
	.string "spilled silver. The Hisuian plate grows\l"
	.string "warm in your hand...$"

Legendary_EventScript_CRESSELIA_Text_1:
# 71 "data/maps/Route126/scripts.pory"
	.string "Hold the plate up to the full moon?$"

Legendary_EventScript_CRESSELIA_Text_2:
# 76 "data/maps/Route126/scripts.pory"
	.string "A single glowing feather drifts down\n"
	.string "from the sky. The air feels lighter,\l"
	.string "kinder, half-asleep.$"

Legendary_EventScript_CRESSELIA_Text_3:
# 83 "data/maps/Route126/scripts.pory"
	.string "She glides down on wings like an aurora\n"
	.string "-- the Lunar Pokemon, born of the\l"
	.string "crescent's mercy.$"

Legendary_EventScript_CRESSELIA_Text_4:
# 103 "data/maps/Route126/scripts.pory"
	.string "The moon will be full again. No need to\n"
	.string "rush.$"

Legendary_EventScript_CRESSELIA_Text_5:
# 108 "data/maps/Route126/scripts.pory"
	.string "The lake is calm and the moon is bright.\n"
	.string "A good place to rest... if only you had\l"
	.string "the right token.$"

CRESSELIAWon_or_Caught_Text_0:
# 118 "data/maps/Route126/scripts.pory"
	.string "A lone Lunar Wing settles on the shore\n"
	.string "where she stood. You feel rested in a\l"
	.string "way sleep never quite manages.$"

CRESSELIARanAway_Text_0:
# 129 "data/maps/Route126/scripts.pory"
	.string "She rises back into the moonlight and\n"
	.string "fades, leaving the night a little\l"
	.string "gentler than she found it.$"
