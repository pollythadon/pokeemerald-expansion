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
# 48 "data/maps/EverGrandeCity/scripts.pory"
	msgbox GIRATINA_quest_starter_Text_1
# 50 "data/maps/EverGrandeCity/scripts.pory"
	msgbox GIRATINA_quest_starter_Text_2
# 52 "data/maps/EverGrandeCity/scripts.pory"
	release
	end

GIRATINA_quest_starter_2:
# 44 "data/maps/EverGrandeCity/scripts.pory"
	msgbox GIRATINA_quest_starter_Text_0
# 45 "data/maps/EverGrandeCity/scripts.pory"
	release
	end


GIRATINA_quest_starter_Text_0:
# 44 "data/maps/EverGrandeCity/scripts.pory"
	.string "Whatever you saw on the other side...\n"
	.string "It's best to keep it to yourself.$"

GIRATINA_quest_starter_Text_1:
# 48 "data/maps/EverGrandeCity/scripts.pory"
	.string "There's a part of every myth they don't\n"
	.string "tell children. A third sibling. Cast out\l"
	.string "for its violence...\p"
	.string "Sealed away in the world that lies\n"
	.string "behind our own, where rivers fall upward\l"
	.string "and gravity forgets its job.$"

GIRATINA_quest_starter_Text_2:
# 50 "data/maps/EverGrandeCity/scripts.pory"
	.string "The devils core lies here. Perhaps maybe\n"
	.string "a champion can find it.\p"
	.string "If you carry it to a still, lonely spot,\n"
	.string "it will pry open a door that was shut for\l"
	.string "good reason.$"
