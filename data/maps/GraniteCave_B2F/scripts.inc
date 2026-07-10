# 1 "data/maps/GraniteCave_B2F/scripts.pory"
GraniteCave_B2F_MapScripts::
# 2 "data/maps/GraniteCave_B2F/scripts.pory"
	.byte 0

Legendary_EventScript_DARKRAI::
# 7 "data/maps/GraniteCave_B2F/scripts.pory"
	lockall
# 8 "data/maps/GraniteCave_B2F/scripts.pory"
	goto_if_set FLAG_DARKRAI_DFTD, Legendary_EventScript_DARKRAI_2
	checkitem ITEM_DARKRANITE
# 0 "data/maps/GraniteCave_B2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Legendary_EventScript_DARKRAI_5
Legendary_EventScript_DARKRAI_4:
# 52 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox Legendary_EventScript_DARKRAI_Text_6
# 53 "data/maps/GraniteCave_B2F/scripts.pory"
	releaseall
	end

Legendary_EventScript_DARKRAI_2:
# 9 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox Legendary_EventScript_DARKRAI_Text_0
# 10 "data/maps/GraniteCave_B2F/scripts.pory"
	releaseall
	end

Legendary_EventScript_DARKRAI_5:
# 14 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox Legendary_EventScript_DARKRAI_Text_1
# 15 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox Legendary_EventScript_DARKRAI_Text_2, MSGBOX_YESNO
# 16 "data/maps/GraniteCave_B2F/scripts.pory"
	switch VAR_RESULT
# 17 "data/maps/GraniteCave_B2F/scripts.pory"
	case YES, Legendary_EventScript_DARKRAI_8
# 46 "data/maps/GraniteCave_B2F/scripts.pory"
	case NO, Legendary_EventScript_DARKRAI_9
	goto Legendary_EventScript_DARKRAI_4

Legendary_EventScript_DARKRAI_8:
# 18 "data/maps/GraniteCave_B2F/scripts.pory"
	clearflag FLAG_DARKRAI_BATTLE
# 19 "data/maps/GraniteCave_B2F/scripts.pory"
	addobject 10
# 20 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox Legendary_EventScript_DARKRAI_Text_3, MSGBOX_AUTOCLOSE
# 21 "data/maps/GraniteCave_B2F/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 22 "data/maps/GraniteCave_B2F/scripts.pory"
	delay 50
# 23 "data/maps/GraniteCave_B2F/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 24 "data/maps/GraniteCave_B2F/scripts.pory"
	playmoncry SPECIES_DARKRAI, CRY_MODE_ENCOUNTER
# 25 "data/maps/GraniteCave_B2F/scripts.pory"
	applymovement 10, DARKRAI_Descend
# 26 "data/maps/GraniteCave_B2F/scripts.pory"
	waitmovement 0
# 27 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox Legendary_EventScript_DARKRAI_Text_4, MSGBOX_AUTOCLOSE
# 28 "data/maps/GraniteCave_B2F/scripts.pory"
	playmoncry SPECIES_DARKRAI, CRY_MODE_ENCOUNTER
# 29 "data/maps/GraniteCave_B2F/scripts.pory"
	delay 40
# 30 "data/maps/GraniteCave_B2F/scripts.pory"
	waitmoncry
# 31 "data/maps/GraniteCave_B2F/scripts.pory"
	setwildbattle SPECIES_DARKRAI, 70
# 32 "data/maps/GraniteCave_B2F/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 33 "data/maps/GraniteCave_B2F/scripts.pory"
	waitstate
# 34 "data/maps/GraniteCave_B2F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 35 "data/maps/GraniteCave_B2F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Legendary_EventScript_DARKRAI_11
# 37 "data/maps/GraniteCave_B2F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Legendary_EventScript_DARKRAI_12
# 39 "data/maps/GraniteCave_B2F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Legendary_EventScript_DARKRAI_13
# 41 "data/maps/GraniteCave_B2F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Legendary_EventScript_DARKRAI_14
Legendary_EventScript_DARKRAI_10:
# 44 "data/maps/GraniteCave_B2F/scripts.pory"
	releaseall
	end

Legendary_EventScript_DARKRAI_9:
# 47 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox Legendary_EventScript_DARKRAI_Text_5
# 48 "data/maps/GraniteCave_B2F/scripts.pory"
	releaseall
	end

Legendary_EventScript_DARKRAI_11:
# 36 "data/maps/GraniteCave_B2F/scripts.pory"
	call DARKRAICaught
	goto Legendary_EventScript_DARKRAI_10

Legendary_EventScript_DARKRAI_12:
# 38 "data/maps/GraniteCave_B2F/scripts.pory"
	call DARKRAIWon
	goto Legendary_EventScript_DARKRAI_10

Legendary_EventScript_DARKRAI_13:
# 40 "data/maps/GraniteCave_B2F/scripts.pory"
	call DARKRAIRanAway
	goto Legendary_EventScript_DARKRAI_10

Legendary_EventScript_DARKRAI_14:
# 42 "data/maps/GraniteCave_B2F/scripts.pory"
	call DARKRAIRanAway
	goto Legendary_EventScript_DARKRAI_10


DARKRAICaught::
# 58 "data/maps/GraniteCave_B2F/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 59 "data/maps/GraniteCave_B2F/scripts.pory"
	removeobject 10
# 60 "data/maps/GraniteCave_B2F/scripts.pory"
	setflag FLAG_DARKRAI_BATTLE
# 61 "data/maps/GraniteCave_B2F/scripts.pory"
	setflag FLAG_DARKRAI_DFTD
# 62 "data/maps/GraniteCave_B2F/scripts.pory"
	completequest QUEST_DARKRAI
# 63 "data/maps/GraniteCave_B2F/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 64 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox DARKRAICaught_Text_0
	return


DARKRAIWon::
# 69 "data/maps/GraniteCave_B2F/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 70 "data/maps/GraniteCave_B2F/scripts.pory"
	removeobject 10
# 71 "data/maps/GraniteCave_B2F/scripts.pory"
	setflag FLAG_DARKRAI_BATTLE
# 72 "data/maps/GraniteCave_B2F/scripts.pory"
	setflag FLAG_DARKRAI_DFTD
# 73 "data/maps/GraniteCave_B2F/scripts.pory"
	completequest QUEST_DARKRAI
# 74 "data/maps/GraniteCave_B2F/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 75 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox DARKRAIWon_Text_0
	return


DARKRAIRanAway::
# 80 "data/maps/GraniteCave_B2F/scripts.pory"
	playmoncry SPECIES_DARKRAI, CRY_MODE_ENCOUNTER
# 81 "data/maps/GraniteCave_B2F/scripts.pory"
	delay 20
# 82 "data/maps/GraniteCave_B2F/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 83 "data/maps/GraniteCave_B2F/scripts.pory"
	hideobjectat 10, MAP_GRANITE_CAVE_B2F
# 84 "data/maps/GraniteCave_B2F/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 85 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox DARKRAIRanAway_Text_0
	return


# 89 "data/maps/GraniteCave_B2F/scripts.pory"
DARKRAI_Descend:
# 90 "data/maps/GraniteCave_B2F/scripts.pory"
	walk_down
# 90 "data/maps/GraniteCave_B2F/scripts.pory"
	walk_down
# 90 "data/maps/GraniteCave_B2F/scripts.pory"
	walk_down
# 90 "data/maps/GraniteCave_B2F/scripts.pory"
	walk_down
# 90 "data/maps/GraniteCave_B2F/scripts.pory"
	walk_down
# 90 "data/maps/GraniteCave_B2F/scripts.pory"
	walk_down
# 90 "data/maps/GraniteCave_B2F/scripts.pory"
	walk_down
# 90 "data/maps/GraniteCave_B2F/scripts.pory"
	walk_down
# 90 "data/maps/GraniteCave_B2F/scripts.pory"
	walk_down
# 91 "data/maps/GraniteCave_B2F/scripts.pory"
	face_player
# 92 "data/maps/GraniteCave_B2F/scripts.pory"
	walk_up
# 93 "data/maps/GraniteCave_B2F/scripts.pory"
	walk_in_place_faster_up
# 93 "data/maps/GraniteCave_B2F/scripts.pory"
	walk_in_place_faster_up
# 94 "data/maps/GraniteCave_B2F/scripts.pory"
	walk_down
# 95 "data/maps/GraniteCave_B2F/scripts.pory"
	delay_16
# 96 "data/maps/GraniteCave_B2F/scripts.pory"
	face_player
	step_end

Legendary_EventScript_DARKRAI_Text_0:
# 9 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "Your nightmares are quiet now. The\n"
	.string "shadows here feel empty, like something\l"
	.string "is missing.$"

Legendary_EventScript_DARKRAI_Text_1:
# 14 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "The shadows here are too thick, too\n"
	.string "deep, and your eyelids are suddenly so\l"
	.string "very heavy...$"

Legendary_EventScript_DARKRAI_Text_2:
# 15 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "Hold up the Darkranite and let yourself\n"
	.string "drift?$"

Legendary_EventScript_DARKRAI_Text_3:
# 20 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "You feel sleep dragging at you. The\n"
	.string "edges of the world go soft and dark.$"

Legendary_EventScript_DARKRAI_Text_4:
# 27 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "It peels itself out of your own shadow,\n"
	.string "a sorrow with a single blue eye.$"

Legendary_EventScript_DARKRAI_Text_5:
# 47 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "You blink the drowsiness away. Not\n"
	.string "tonight.$"

Legendary_EventScript_DARKRAI_Text_6:
# 52 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "The dark here feels almost... sad. Like\n"
	.string "something is hiding in it, hoping and\l"
	.string "dreading to be found.$"

DARKRAICaught_Text_0:
# 64 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "For the first time, it didn't have to slip\n"
	.string "away into the dark alone. It almost\l"
	.string "looks... relieved.$"

DARKRAIWon_Text_0:
# 75 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "You wake on the cold ground. No\n"
	.string "nightmare came. Maybe it just wanted\l"
	.string "someone to stay until the dream was\l"
	.string "over.$"

DARKRAIRanAway_Text_0:
# 85 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "It melts back into the shadows, alone\n"
	.string "again. You wish, oddly, that it had\l"
	.string "stayed.$"
