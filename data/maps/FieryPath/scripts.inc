# 1 "data/maps/FieryPath/scripts.pory"
FieryPath_MapScripts::
# 2 "data/maps/FieryPath/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FieryPath_OnTransition
# 3 "data/maps/FieryPath/scripts.pory"
	.byte 0
# 4 "data/maps/FieryPath/scripts.pory"

# 5 "data/maps/FieryPath/scripts.pory"
FieryPath_OnTransition:
# 6 "data/maps/FieryPath/scripts.pory"
	call_if_unset FLAG_LANDMARK_FIERY_PATH, FieryPath_EventScript_MoveScottToFallarbor
# 7 "data/maps/FieryPath/scripts.pory"
	setflag FLAG_LANDMARK_FIERY_PATH
# 8 "data/maps/FieryPath/scripts.pory"
	end
# 9 "data/maps/FieryPath/scripts.pory"

# 10 "data/maps/FieryPath/scripts.pory"
FieryPath_EventScript_MoveScottToFallarbor::
# 11 "data/maps/FieryPath/scripts.pory"
	setflag FLAG_HIDE_VERDANTURF_TOWN_SCOTT
# 12 "data/maps/FieryPath/scripts.pory"
	clearflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
# 13 "data/maps/FieryPath/scripts.pory"
	return

HEATRAN_quest_starter::
# 18 "data/maps/FieryPath/scripts.pory"
	lockall
# 19 "data/maps/FieryPath/scripts.pory"
	faceplayer
# 20 "data/maps/FieryPath/scripts.pory"
	goto_if_set FLAG_HEATRAN_GIFT, HEATRAN_quest_starter_2
# 25 "data/maps/FieryPath/scripts.pory"
	msgbox HEATRAN_quest_starter_Text_1
# 28 "data/maps/FieryPath/scripts.pory"
	msgbox HEATRAN_quest_starter_Text_2, MSGBOX_YESNO
# 30 "data/maps/FieryPath/scripts.pory"
	switch VAR_RESULT
# 31 "data/maps/FieryPath/scripts.pory"
	case YES, HEATRAN_quest_starter_6
# 38 "data/maps/FieryPath/scripts.pory"
	case NO, HEATRAN_quest_starter_7
HEATRAN_quest_starter_4:
# 41 "data/maps/FieryPath/scripts.pory"
	release
	end

HEATRAN_quest_starter_2:
# 21 "data/maps/FieryPath/scripts.pory"
	msgbox HEATRAN_quest_starter_Text_0
# 22 "data/maps/FieryPath/scripts.pory"
	release
	end

HEATRAN_quest_starter_6:
# 32 "data/maps/FieryPath/scripts.pory"
	setflag FLAG_HEATRAN_GIFT
# 33 "data/maps/FieryPath/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 34 "data/maps/FieryPath/scripts.pory"
	giveitem ITEM_HEATRANITE
# 35 "data/maps/FieryPath/scripts.pory"
	startquest QUEST_HEATRAN
# 36 "data/maps/FieryPath/scripts.pory"
	waitfanfare
# 37 "data/maps/FieryPath/scripts.pory"
	msgbox HEATRAN_quest_starter_Text_3
	goto HEATRAN_quest_starter_4

HEATRAN_quest_starter_7:
# 39 "data/maps/FieryPath/scripts.pory"
	msgbox HEATRAN_quest_starter_Text_4
	goto HEATRAN_quest_starter_4


HEATRAN_quest_starter_Text_0:
# 21 "data/maps/FieryPath/scripts.pory"
	.string "The mountain's still restless. That old\n"
	.string "boulder up on Jagged Pass -- it knows\l"
	.string "the Heatranite's near.$"

HEATRAN_quest_starter_Text_1:
# 25 "data/maps/FieryPath/scripts.pory"
	.string "You feel it too, don't you? The whole\n"
	.string "Fiery Path has been trembling for\l"
	.string "weeks.\p"
	.string "I've measured every tremor. They all\n"
	.string "point the same way... up, toward Jagged\l"
	.string "Pass.\p"
	.string "Something's sleeping in the magma under\n"
	.string "this mountain. Something old.$"

HEATRAN_quest_starter_Text_2:
# 28 "data/maps/FieryPath/scripts.pory"
	.string "This stone came up with the last\n"
	.string "eruption. A Heatranite, if the legends\l"
	.string "are true.\p"
	.string "Take it to the Jagged Pass. Where the\n"
	.string "rock trembles hardest, a door will open.\l"
	.string "Meet what's behind it.$"

HEATRAN_quest_starter_Text_3:
# 37 "data/maps/FieryPath/scripts.pory"
	.string "Climb the pass while you carry it. The\n"
	.string "mountain will show you the way.$"

HEATRAN_quest_starter_Text_4:
# 39 "data/maps/FieryPath/scripts.pory"
	.string "Hold onto that thought. The mountain\n"
	.string "isn't going anywhere -- neither is what\l"
	.string "sleeps beneath it.$"
