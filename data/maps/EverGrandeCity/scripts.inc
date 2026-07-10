# 1 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_MapScripts::
# 2 "data/maps/EverGrandeCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
# 3 "data/maps/EverGrandeCity/scripts.pory"
	.byte 0
# 4 "data/maps/EverGrandeCity/scripts.pory"

# 5 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_OnTransition:
# 6 "data/maps/EverGrandeCity/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 7 "data/maps/EverGrandeCity/scripts.pory"
	end
# 8 "data/maps/EverGrandeCity/scripts.pory"

# 9 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_VictoryRoadSign::
# 10 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
# 11 "data/maps/EverGrandeCity/scripts.pory"
	end
# 12 "data/maps/EverGrandeCity/scripts.pory"

# 13 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_CitySign::
# 14 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
# 15 "data/maps/EverGrandeCity/scripts.pory"
	end
# 16 "data/maps/EverGrandeCity/scripts.pory"

# 17 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_PokemonLeagueSign::
# 18 "data/maps/EverGrandeCity/scripts.pory"
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
# 19 "data/maps/EverGrandeCity/scripts.pory"
	end
# 20 "data/maps/EverGrandeCity/scripts.pory"

# 21 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_EventScript_SetVisitedEverGrande::
# 22 "data/maps/EverGrandeCity/scripts.pory"
	setflag FLAG_VISITED_EVER_GRANDE_CITY
# 23 "data/maps/EverGrandeCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 24 "data/maps/EverGrandeCity/scripts.pory"
	end
# 25 "data/maps/EverGrandeCity/scripts.pory"

# 26 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_EnteringVictoryRoad:
# 27 "data/maps/EverGrandeCity/scripts.pory"
	.string "ENTERING VICTORY ROAD$"
# 28 "data/maps/EverGrandeCity/scripts.pory"

# 29 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_EnteringPokemonLeague:
# 30 "data/maps/EverGrandeCity/scripts.pory"
	.string "ENTERING POKéMON LEAGUE\n"
# 31 "data/maps/EverGrandeCity/scripts.pory"
	.string "CENTER GATE$"
# 32 "data/maps/EverGrandeCity/scripts.pory"

# 33 "data/maps/EverGrandeCity/scripts.pory"
EverGrandeCity_Text_CitySign:
# 34 "data/maps/EverGrandeCity/scripts.pory"
	.string "EVER GRANDE CITY\p"
# 35 "data/maps/EverGrandeCity/scripts.pory"
	.string "“The paradise of flowers, the sea,\n"
# 36 "data/maps/EverGrandeCity/scripts.pory"
	.string "and POKéMON.”$"

GIRATINA_quest_starter::
# 41 "data/maps/EverGrandeCity/scripts.pory"
	lockall
# 42 "data/maps/EverGrandeCity/scripts.pory"
	faceplayer
	checkitem ITEM_GRISEOUS_CORE
# 0 "data/maps/EverGrandeCity/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne GIRATINA_quest_starter_2
# 58 "data/maps/EverGrandeCity/scripts.pory"
	msgbox GIRATINA_quest_starter_Text_2
# 60 "data/maps/EverGrandeCity/scripts.pory"
	msgbox GIRATINA_quest_starter_Text_3
# 62 "data/maps/EverGrandeCity/scripts.pory"
	releaseall
	end

GIRATINA_quest_starter_2:
# 44 "data/maps/EverGrandeCity/scripts.pory"
	msgbox GIRATINA_quest_starter_Text_0, MSGBOX_YESNO
# 45 "data/maps/EverGrandeCity/scripts.pory"
	switch VAR_RESULT
# 46 "data/maps/EverGrandeCity/scripts.pory"
	case YES, GIRATINA_quest_starter_6
# 52 "data/maps/EverGrandeCity/scripts.pory"
	case NO, GIRATINA_quest_starter_7
GIRATINA_quest_starter_4:
# 55 "data/maps/EverGrandeCity/scripts.pory"
	releaseall
	end

GIRATINA_quest_starter_6:
# 47 "data/maps/EverGrandeCity/scripts.pory"
	fadescreen FADE_TO_BLACK
# 48 "data/maps/EverGrandeCity/scripts.pory"
	delay 60
# 50 "data/maps/EverGrandeCity/scripts.pory"
	warp MAP_DISTORTION_WORLD, 10, 36
# 51 "data/maps/EverGrandeCity/scripts.pory"
	waitstate
	goto GIRATINA_quest_starter_4

GIRATINA_quest_starter_7:
# 53 "data/maps/EverGrandeCity/scripts.pory"
	msgbox GIRATINA_quest_starter_Text_1
	goto GIRATINA_quest_starter_4


GriseousCore_DigUp::
# 67 "data/maps/EverGrandeCity/scripts.pory"
	lockall
# 68 "data/maps/EverGrandeCity/scripts.pory"
	faceplayer
	checkitem ITEM_GRISEOUS_CORE
# 0 "data/maps/EverGrandeCity/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne GriseousCore_DigUp_2
# 73 "data/maps/EverGrandeCity/scripts.pory"
	goto_if_unset FLAG_LEGENDARY_BTL, GriseousCore_DigUp_5
GriseousCore_DigUp_4:
# 85 "data/maps/EverGrandeCity/scripts.pory"
	releaseall
	end

GriseousCore_DigUp_2:
# 70 "data/maps/EverGrandeCity/scripts.pory"
	releaseall
	end

GriseousCore_DigUp_5:
# 74 "data/maps/EverGrandeCity/scripts.pory"
	msgbox GriseousCore_DigUp_Text_0, MSGBOX_YESNO
# 76 "data/maps/EverGrandeCity/scripts.pory"
	switch VAR_RESULT
# 77 "data/maps/EverGrandeCity/scripts.pory"
	case YES, GriseousCore_DigUp_8
# 81 "data/maps/EverGrandeCity/scripts.pory"
	case NO, GriseousCore_DigUp_9
	goto GriseousCore_DigUp_4

GriseousCore_DigUp_8:
# 78 "data/maps/EverGrandeCity/scripts.pory"
	giveitem ITEM_GRISEOUS_CORE
# 79 "data/maps/EverGrandeCity/scripts.pory"
	startquest QUEST_GIRATINA
# 80 "data/maps/EverGrandeCity/scripts.pory"
	msgbox GriseousCore_DigUp_Text_1
	goto GriseousCore_DigUp_4

GriseousCore_DigUp_9:
# 82 "data/maps/EverGrandeCity/scripts.pory"
	msgbox GriseousCore_DigUp_Text_2
	goto GriseousCore_DigUp_4


GIRATINA_quest_starter_Text_0:
# 44 "data/maps/EverGrandeCity/scripts.pory"
	.string "There's a tear in reality, poke it?$"

GIRATINA_quest_starter_Text_1:
# 53 "data/maps/EverGrandeCity/scripts.pory"
	.string "Not very wise.$"

GIRATINA_quest_starter_Text_2:
# 58 "data/maps/EverGrandeCity/scripts.pory"
	.string "There's a part of every myth they don't\n"
	.string "tell children. A third sibling. Cast out\l"
	.string "for its violence...\p"
	.string "Sealed away in the world that lies\n"
	.string "behind our own, where rivers fall upward\l"
	.string "and gravity forgets its job.$"

GIRATINA_quest_starter_Text_3:
# 60 "data/maps/EverGrandeCity/scripts.pory"
	.string "The devils core lies here. Perhaps maybe\n"
	.string "a champion can find it.\p"
	.string "If you carry it to a still, lonely spot,\n"
	.string "it will pry open a door that was shut for\l"
	.string "good reason.$"

GriseousCore_DigUp_Text_0:
# 74 "data/maps/EverGrandeCity/scripts.pory"
	.string "There's something poking out of the\n"
	.string "ground.\p"
	.string "Would you like to dig it up?$"

GriseousCore_DigUp_Text_1:
# 80 "data/maps/EverGrandeCity/scripts.pory"
	.string "What!? The writing on the sign changed!$"

GriseousCore_DigUp_Text_2:
# 82 "data/maps/EverGrandeCity/scripts.pory"
	.string "It's best I mind my business$"
