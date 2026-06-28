# 1 "data/maps/GraniteCave_B2F/scripts.pory"
GraniteCave_B2F_MapScripts::
# 2 "data/maps/GraniteCave_B2F/scripts.pory"
	.byte 0

Legendary_EventScript_DARKRAI::
# 7 "data/maps/GraniteCave_B2F/scripts.pory"
	lockall
	checkitem ITEM_DARKRANITE
# 0 "data/maps/GraniteCave_B2F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Legendary_EventScript_DARKRAI_2
Legendary_EventScript_DARKRAI_1:
# 47 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox Legendary_EventScript_DARKRAI_Text_5
# 48 "data/maps/GraniteCave_B2F/scripts.pory"
	release
	end

Legendary_EventScript_DARKRAI_2:
# 9 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox Legendary_EventScript_DARKRAI_Text_0
# 10 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox Legendary_EventScript_DARKRAI_Text_1, MSGBOX_YESNO
# 11 "data/maps/GraniteCave_B2F/scripts.pory"
	switch VAR_RESULT
# 12 "data/maps/GraniteCave_B2F/scripts.pory"
	case YES, Legendary_EventScript_DARKRAI_5
# 41 "data/maps/GraniteCave_B2F/scripts.pory"
	case NO, Legendary_EventScript_DARKRAI_6
	goto Legendary_EventScript_DARKRAI_1

Legendary_EventScript_DARKRAI_5:
# 13 "data/maps/GraniteCave_B2F/scripts.pory"
	clearflag FLAG_DARKRAI_BATTLE
# 14 "data/maps/GraniteCave_B2F/scripts.pory"
	addobject 10
# 15 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox Legendary_EventScript_DARKRAI_Text_2, MSGBOX_AUTOCLOSE
# 16 "data/maps/GraniteCave_B2F/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 17 "data/maps/GraniteCave_B2F/scripts.pory"
	delay 50
# 18 "data/maps/GraniteCave_B2F/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 19 "data/maps/GraniteCave_B2F/scripts.pory"
	playmoncry SPECIES_DARKRAI, CRY_MODE_ENCOUNTER
# 20 "data/maps/GraniteCave_B2F/scripts.pory"
	applymovement 10, DARKRAI_Descend
# 21 "data/maps/GraniteCave_B2F/scripts.pory"
	waitmovement 0
# 22 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox Legendary_EventScript_DARKRAI_Text_3, MSGBOX_AUTOCLOSE
# 23 "data/maps/GraniteCave_B2F/scripts.pory"
	playmoncry SPECIES_DARKRAI, CRY_MODE_ENCOUNTER
# 24 "data/maps/GraniteCave_B2F/scripts.pory"
	delay 40
# 25 "data/maps/GraniteCave_B2F/scripts.pory"
	waitmoncry
# 26 "data/maps/GraniteCave_B2F/scripts.pory"
	setwildbattle SPECIES_DARKRAI, 70
# 27 "data/maps/GraniteCave_B2F/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 28 "data/maps/GraniteCave_B2F/scripts.pory"
	waitstate
# 29 "data/maps/GraniteCave_B2F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 30 "data/maps/GraniteCave_B2F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Legendary_EventScript_DARKRAI_8
# 32 "data/maps/GraniteCave_B2F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Legendary_EventScript_DARKRAI_9
# 34 "data/maps/GraniteCave_B2F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Legendary_EventScript_DARKRAI_10
# 36 "data/maps/GraniteCave_B2F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Legendary_EventScript_DARKRAI_11
Legendary_EventScript_DARKRAI_7:
# 39 "data/maps/GraniteCave_B2F/scripts.pory"
	releaseall
	end

Legendary_EventScript_DARKRAI_6:
# 42 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox Legendary_EventScript_DARKRAI_Text_4
# 43 "data/maps/GraniteCave_B2F/scripts.pory"
	release
	end

Legendary_EventScript_DARKRAI_8:
# 31 "data/maps/GraniteCave_B2F/scripts.pory"
	call DARKRAICaught
	goto Legendary_EventScript_DARKRAI_7

Legendary_EventScript_DARKRAI_9:
# 33 "data/maps/GraniteCave_B2F/scripts.pory"
	call DARKRAIWon
	goto Legendary_EventScript_DARKRAI_7

Legendary_EventScript_DARKRAI_10:
# 35 "data/maps/GraniteCave_B2F/scripts.pory"
	call DARKRAIRanAway
	goto Legendary_EventScript_DARKRAI_7

Legendary_EventScript_DARKRAI_11:
# 37 "data/maps/GraniteCave_B2F/scripts.pory"
	call DARKRAIRanAway
	goto Legendary_EventScript_DARKRAI_7


DARKRAICaught::
# 53 "data/maps/GraniteCave_B2F/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 54 "data/maps/GraniteCave_B2F/scripts.pory"
	removeobject 10
# 55 "data/maps/GraniteCave_B2F/scripts.pory"
	setflag FLAG_DARKRAI_BATTLE
# 56 "data/maps/GraniteCave_B2F/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 57 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox DARKRAICaught_Text_0
	return


DARKRAIWon::
# 62 "data/maps/GraniteCave_B2F/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 63 "data/maps/GraniteCave_B2F/scripts.pory"
	removeobject 10
# 64 "data/maps/GraniteCave_B2F/scripts.pory"
	setflag FLAG_DARKRAI_BATTLE
# 65 "data/maps/GraniteCave_B2F/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 66 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox DARKRAIWon_Text_0
	return


DARKRAIRanAway::
# 71 "data/maps/GraniteCave_B2F/scripts.pory"
	playmoncry SPECIES_DARKRAI, CRY_MODE_ENCOUNTER
# 72 "data/maps/GraniteCave_B2F/scripts.pory"
	delay 20
# 73 "data/maps/GraniteCave_B2F/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 74 "data/maps/GraniteCave_B2F/scripts.pory"
	removeobject 10
# 75 "data/maps/GraniteCave_B2F/scripts.pory"
	setflag FLAG_DARKRAI_BATTLE
# 76 "data/maps/GraniteCave_B2F/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 77 "data/maps/GraniteCave_B2F/scripts.pory"
	msgbox DARKRAIRanAway_Text_0
	return


# 81 "data/maps/GraniteCave_B2F/scripts.pory"
DARKRAI_Descend:
# 82 "data/maps/GraniteCave_B2F/scripts.pory"
	walk_down
# 82 "data/maps/GraniteCave_B2F/scripts.pory"
	walk_down
# 82 "data/maps/GraniteCave_B2F/scripts.pory"
	walk_down
# 82 "data/maps/GraniteCave_B2F/scripts.pory"
	walk_down
# 82 "data/maps/GraniteCave_B2F/scripts.pory"
	walk_down
# 82 "data/maps/GraniteCave_B2F/scripts.pory"
	walk_down
# 82 "data/maps/GraniteCave_B2F/scripts.pory"
	walk_down
# 82 "data/maps/GraniteCave_B2F/scripts.pory"
	walk_down
# 82 "data/maps/GraniteCave_B2F/scripts.pory"
	walk_down
# 83 "data/maps/GraniteCave_B2F/scripts.pory"
	face_player
# 84 "data/maps/GraniteCave_B2F/scripts.pory"
	walk_up
# 85 "data/maps/GraniteCave_B2F/scripts.pory"
	walk_in_place_faster_up
# 85 "data/maps/GraniteCave_B2F/scripts.pory"
	walk_in_place_faster_up
# 86 "data/maps/GraniteCave_B2F/scripts.pory"
	walk_down
# 87 "data/maps/GraniteCave_B2F/scripts.pory"
	delay_16
# 88 "data/maps/GraniteCave_B2F/scripts.pory"
	face_player
	step_end

Legendary_EventScript_DARKRAI_Text_0:
# 9 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "The shadows here are too thick, too\n"
	.string "deep, and your eyelids are suddenly so\l"
	.string "very heavy...$"

Legendary_EventScript_DARKRAI_Text_1:
# 10 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "Hold up the Darkranite and let yourself\n"
	.string "drift?$"

Legendary_EventScript_DARKRAI_Text_2:
# 15 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "You feel sleep dragging at you. The\n"
	.string "edges of the world go soft and dark.$"

Legendary_EventScript_DARKRAI_Text_3:
# 22 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "It peels itself out of your own shadow,\n"
	.string "a sorrow with a single blue eye.$"

Legendary_EventScript_DARKRAI_Text_4:
# 42 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "You blink the drowsiness away. Not\n"
	.string "tonight.$"

Legendary_EventScript_DARKRAI_Text_5:
# 47 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "The dark here feels almost... sad. Like\n"
	.string "something is hiding in it, hoping and\l"
	.string "dreading to be found.$"

DARKRAICaught_Text_0:
# 57 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "For the first time, it didn't have to slip\n"
	.string "away into the dark alone. It almost\l"
	.string "looks... relieved.$"

DARKRAIWon_Text_0:
# 66 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "You wake on the cold ground. No\n"
	.string "nightmare came. Maybe it just wanted\l"
	.string "someone to stay until the dream was\l"
	.string "over.$"

DARKRAIRanAway_Text_0:
# 77 "data/maps/GraniteCave_B2F/scripts.pory"
	.string "It melts back into the shadows, alone\n"
	.string "again. You wish, oddly, that it had\l"
	.string "stayed.$"
