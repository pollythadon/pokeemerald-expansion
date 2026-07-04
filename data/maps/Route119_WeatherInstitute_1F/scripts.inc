# 1 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_MapScripts::
# 2 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_1F_OnTransition
# 3 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.byte 0
# 4 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 5 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_OnTransition:
# 6 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos
# 7 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 8 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 9 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_SetLittleBoyPos::
# 10 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	setobjectxyperm LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, 0, 5
# 11 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	setobjectmovementtype LOCALID_WEATHER_INSTITUTE_LITTLE_BOY, MOVEMENT_TYPE_FACE_RIGHT
# 12 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	return
# 13 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 14 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_LittleBoy::
# 15 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	lock
# 16 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	faceplayer
# 17 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	special GetPlayerBigGuyGirlString
# 18 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	goto_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere
# 19 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_WowYoureStrong, MSGBOX_DEFAULT
# 20 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	release
# 21 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 22 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 23 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_LittleBoyTeamAquaHere::
# 24 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs, MSGBOX_DEFAULT
# 25 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	release
# 26 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 27 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 28 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_InstituteWorker1::
# 29 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	lock
# 30 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	faceplayer
# 31 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	goto_if_unset FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_1F_EventScript_StudyingRain
# 32 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	setvar VAR_0x8004, 0
# 33 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
# 34 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated
# 35 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_1F_EventScript_StudyingRain  @ Both defeated
# 36 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather, MSGBOX_DEFAULT
# 37 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	release
# 38 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 39 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 40 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_LegendaryDefeated::
# 41 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	addvar VAR_0x8004, 1
# 42 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	return
# 43 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 44 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_StudyingRain::
# 45 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_ProfStudyingRain, MSGBOX_DEFAULT
# 46 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	release
# 47 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 48 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 49 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_InstituteWorker2::
# 50 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo, MSGBOX_NPC
# 51 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 52 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 53 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_Bed::
# 54 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	lockall
# 55 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_TakeRestInBed, MSGBOX_DEFAULT
# 56 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	closemessage
# 57 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	call Common_EventScript_OutOfCenterPartyHeal
# 58 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	releaseall
# 59 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 60 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 61 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_Grunt1::
# 62 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_1, Route119_WeatherInstitute_1F_Text_Grunt1Intro, Route119_WeatherInstitute_1F_Text_Grunt1Defeat
# 63 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 64 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 65 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 66 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_EventScript_Grunt4::
# 67 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_WEATHER_INST_4, Route119_WeatherInstitute_1F_Text_Grunt4Intro, Route119_WeatherInstitute_1F_Text_Grunt4Defeat
# 68 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox Route119_WeatherInstitute_1F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
# 69 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	end
# 70 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 71 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_Grunt1Intro:
# 72 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "The BOSS got interested in\n"
# 73 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "the research they have going here,\l"
# 74 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "so he sent us out.\p"
# 75 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "You quit meddling!$"
# 76 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 77 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_Grunt1Defeat:
# 78 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Blast it…\n"
# 79 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Blasted by a kid…$"
# 80 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 81 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_Grunt1PostBattle:
# 82 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Our BOSS knows everything.\p"
# 83 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "But I'm just a GRUNT. What would I know\n"
# 84 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "about what he's thinking?$"
# 85 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 86 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_Grunt4Intro:
# 87 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Huh?\n"
# 88 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "What's a kid doing here?$"
# 89 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 90 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_Grunt4Defeat:
# 91 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Huh?\n"
# 92 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "I lost?!$"
# 93 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 94 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_Grunt4PostBattle:
# 95 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Oh, no…\n"
# 96 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "I'll catch an earful for losing to a kid…\p"
# 97 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "I should just take a nap in the bed…$"
# 98 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 99 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_EveryoneWentUpstairs:
# 100 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "While I was sleeping, everyone went\n"
# 101 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "upstairs!$"
# 102 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 103 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_WowYoureStrong:
# 104 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Wow, you're really strong!\p"
# 105 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "I wish I could be a POKéMON TRAINER\n"
# 106 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "like you!$"
# 107 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 108 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_ProfStudyingRain:
# 109 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "The PROFESSOR loves rain.\n"
# 110 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "That's a fact.\p"
# 111 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "But if it keeps raining, people will be in\n"
# 112 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "trouble. That's another fact.\p"
# 113 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "And thus, the PROFESSOR is studying\n"
# 114 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "if the rain can be put to good use.$"
# 115 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 116 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_NoticingAbnormalWeather:
# 117 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "On the 2nd floor of the INSTITUTE,\n"
# 118 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "we study the weather patterns over\l"
# 119 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "the HOENN region.\p"
# 120 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "We've been noticing temporary and\n"
# 121 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "isolated cases of droughts and\l"
# 122 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "heavy rain lately…$"
# 123 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 124 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_WhatWereAquasUpTo:
# 125 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Hello!\n"
# 126 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "We've been saved by your actions!\p"
# 127 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "What I don't understand is what on\n"
# 128 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "earth the AQUAS were up to.$"
# 129 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"

# 130 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
Route119_WeatherInstitute_1F_Text_TakeRestInBed:
# 131 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "There's a bed…\n"
# 132 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Let's take a rest.$"

MEWTWO_quest_starter::
# 137 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	lockall
# 138 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	faceplayer
	checkitem ITEM_MEWTWONITE_X
# 0 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne MEWTWO_quest_starter_2
	checkitem ITEM_MEWTWONITE_Y
# 0 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne MEWTWO_quest_starter_2
# 144 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox MEWTWO_quest_starter_Text_1
# 146 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox MEWTWO_quest_starter_Text_2, MSGBOX_YESNO
# 149 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	switch VAR_RESULT
# 150 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	case YES, MEWTWO_quest_starter_8
# 155 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	case NO, MEWTWO_quest_starter_9
MEWTWO_quest_starter_6:
# 158 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	releaseall
	end

MEWTWO_quest_starter_2:
# 140 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox MEWTWO_quest_starter_Text_0
# 141 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	releaseall
	end

MEWTWO_quest_starter_8:
# 151 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	clearflag FLAG_MEWTWO_BATTLE
# 152 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	giveitem ITEM_MEWTWONITE_X
# 153 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	giveitem ITEM_MEWTWONITE_Y
# 154 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox MEWTWO_quest_starter_Text_3
	goto MEWTWO_quest_starter_6

MEWTWO_quest_starter_9:
# 156 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	msgbox MEWTWO_quest_starter_Text_4
	goto MEWTWO_quest_starter_6


MEWTWO_quest_starter_Text_0:
# 140 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Born of science, just to suffer.$"

MEWTWO_quest_starter_Text_1:
# 144 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "I worked in a laboratory. Before it\n"
	.string "burned. We were told we were making a\l"
	.string "miracle.\p"
	.string "We took a single eyelash of the rarest\n"
	.string "Pokemon alive and we... improved it.\l"
	.string "Spliced it. Caged it. Called it a success.$"

MEWTWO_quest_starter_Text_2:
# 146 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "My superiors called it a failure, but it\n"
	.string "had a soul. And it never forgave us.\p"
	.string "These two stones survived the fire. The\n"
	.string "keys to the power we forced into its\l"
	.string "blood. This 'Pokémon' has a thing for\l"
	.string "mysterious caves. I'm sure you know a\l"
	.string "place.$"

MEWTWO_quest_starter_Text_3:
# 154 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "Don't expect gratitude. It owes us\n"
	.string "nothing. Honestly... Less than nothing.$"

MEWTWO_quest_starter_Text_4:
# 156 "data/maps/Route119_WeatherInstitute_1F/scripts.pory"
	.string "...Maybe that's mercy. For both of you.$"
