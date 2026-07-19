# 1 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_MapScripts::
# 2 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_CozmosHouse_OnTransition
	.byte 0

FallarborTown_CozmosHouse_OnTransition:
	call RoamingLegendQuests_EventScript_SyncNpcVisibility
	end
# 3 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 4 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_ProfCozmo::
# 5 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	lock
# 6 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	faceplayer
# 7 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_GaveMeteorite
# 8 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	checkitem ITEM_METEORITE
# 9 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite
# 10 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
# 11 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 12 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 13 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 14 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_PlayerHasMeteorite::
# 15 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	call_if_unset FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_NoticeMeteorite
# 16 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	call_if_set FLAG_TEMP_2, FallarborTown_CozmosHouse_EventScript_AskForMeteorite
# 17 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_eq VAR_RESULT, NO, FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite
# 18 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_PleaseUseThisTM, MSGBOX_DEFAULT
# 19 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	giveitem ITEM_TM_RETURN
# 20 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 21 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	setvar VAR_0x8004, ITEM_METEORITE
# 22 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	call Common_EventScript_PlayerHandedOverTheItem
# 23 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	setflag FLAG_RECEIVED_TM_RETURN
# 24 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
# 25 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 26 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 27 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 28 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_NoticeMeteorite::
# 29 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow, MSGBOX_DEFAULT
# 30 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt, MSGBOX_YESNO
# 31 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	return
# 32 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 33 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_AskForMeteorite::
# 34 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_MayIHaveMeteorite, MSGBOX_YESNO
# 35 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	return
# 36 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 37 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_DeclineGiveMeteorite::
# 38 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	setflag FLAG_TEMP_2
# 39 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_CrushedWithDisappointment, MSGBOX_DEFAULT
# 40 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 41 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 42 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 43 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_GaveMeteorite::
# 44 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch, MSGBOX_DEFAULT
# 45 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 46 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 47 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 48 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_CozmosWife::
# 49 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	lock
# 50 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	faceplayer
# 51 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_set FLAG_RECEIVED_TM_RETURN, FallarborTown_CozmosHouse_EventScript_CozmoIsHappy
# 52 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_CozmosHouse_EventScript_CozmoIsSad
# 53 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls, MSGBOX_DEFAULT
# 54 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 55 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 56 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 57 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_CozmoIsSad::
# 58 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_FeelSorryForCozmo, MSGBOX_DEFAULT
# 59 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 60 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 61 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 62 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_EventScript_CozmoIsHappy::
# 63 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox FallarborTown_CozmosHouse_Text_CozmoIsSoHappy, MSGBOX_DEFAULT
# 64 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	release
# 65 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	end
# 66 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 67 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_MeteoriteWillNeverBeMineNow:
# 68 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "PROF. COZMO: Oh…\n"
# 69 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "I never should have let myself be\l"
# 70 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "conned into telling TEAM MAGMA where\l"
# 71 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "you can find METEORITES…\p"
# 72 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "That METEORITE from METEOR FALLS…\n"
# 73 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "It's never going to be mine now…$"
# 74 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 75 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_IsThatMeteoriteMayIHaveIt:
# 76 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Oh!\n"
# 77 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Hah?\p"
# 78 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "That item…\p"
# 79 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Could it be?\p"
# 80 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Is it the METEORITE that TEAM MAGMA\n"
# 81 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "took from METEOR FALLS?\p"
# 82 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Please, may I have it?\p"
# 83 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "I'm not asking for it for free.\n"
# 84 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "How about in exchange for this TM?$"
# 85 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 86 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_PleaseUseThisTM:
# 87 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "PROF. COZMO: This TM, it represents\n"
# 88 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "my feeling of gratitude.\l"
# 89 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Please use it!$"
# 90 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 91 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_ReallyGoingToHelpMyResearch:
# 92 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "PROF. COZMO: Oh, I can't believe it.\n"
# 93 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "This is really, really great!\p"
# 94 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "This is really going to help my research!$"
# 95 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 96 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_CrushedWithDisappointment:
# 97 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "PROF. COZMO: Oh, but…\n"
# 98 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "I'm crushed with disappointment…$"
# 99 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 100 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_MayIHaveMeteorite:
# 101 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "PROF. COZMO: Please, may I have that\n"
# 102 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "METEORITE?\p"
# 103 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "I'm not asking for it for free.\n"
# 104 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "How about in exchange for this TM?$"
# 105 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 106 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_CozmoWentToMeteorFalls:
# 107 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "PROF. COZMO went off to METEOR FALLS\n"
# 108 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "on ROUTE 114 with some people from\l"
# 109 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "TEAM MAGMA.$"
# 110 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 111 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_FeelSorryForCozmo:
# 112 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Poor PROF. COZMO…\n"
# 113 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "He's so depressed… I feel sorry for him.$"
# 114 "data/maps/FallarborTown_CozmosHouse/scripts.pory"

# 115 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
FallarborTown_CozmosHouse_Text_CozmoIsSoHappy:
# 116 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Look at PROF. COZMO…\n"
# 117 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "He's so happy! I think it's cute.$"

PALKIA_quest_starter::
# 122 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	lockall
# 123 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	faceplayer
	checkitem ITEM_LUSTROUS_ORB
# 0 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne PALKIA_quest_starter_2
# 129 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox PALKIA_quest_starter_Text_1
# 131 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox PALKIA_quest_starter_Text_2, MSGBOX_YESNO
# 133 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	switch VAR_RESULT
# 134 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	case YES, PALKIA_quest_starter_6
# 139 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	case NO, PALKIA_quest_starter_7
PALKIA_quest_starter_4:
# 142 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	releaseall
	end

PALKIA_quest_starter_2:
# 125 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox PALKIA_quest_starter_Text_0
# 126 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	releaseall
	end

PALKIA_quest_starter_6:
# 135 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	giveitem ITEM_LUSTROUS_ORB
# 136 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	startquest QUEST_PALKIA
# 137 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	clearflag FLAG_PALKIA_BATTLE
# 138 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox PALKIA_quest_starter_Text_3
	goto PALKIA_quest_starter_4

PALKIA_quest_starter_7:
# 140 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	msgbox PALKIA_quest_starter_Text_4
	goto PALKIA_quest_starter_4


PALKIA_quest_starter_Text_0:
# 125 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Mind the distance between things. It's\n"
	.string "only a suggestion, really.$"

PALKIA_quest_starter_Text_1:
# 129 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Look up. The space between the stars...\n"
	.string "who do you think keeps them from\l"
	.string "falling into one another?\p"
	.string "There is a creature that holds the very\n"
	.string "boundaries of the world apart,\l"
	.string "pearl-bright, with wings like torn sky.$"

PALKIA_quest_starter_Text_2:
# 131 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "This Pearl Orb folds the air around it.\n"
	.string "Take it where the horizon bends wrong...\p"
	.string "and you may meet the one that draws\n"
	.string "the lines reality dares not cross.$"

PALKIA_quest_starter_Text_3:
# 138 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Here and there, near and far... It\n"
	.string "decides which is which. Go carefully.$"

PALKIA_quest_starter_Text_4:
# 140 "data/maps/FallarborTown_CozmosHouse/scripts.pory"
	.string "Keep your distance, then. It's safer.$"
