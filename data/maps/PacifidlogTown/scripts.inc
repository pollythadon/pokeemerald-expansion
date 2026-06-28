# 1 "data/maps/PacifidlogTown/scripts.pory"

# 2 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_MapScripts::
# 3 "data/maps/PacifidlogTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
# 4 "data/maps/PacifidlogTown/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
# 5 "data/maps/PacifidlogTown/scripts.pory"
	.byte 0
# 6 "data/maps/PacifidlogTown/scripts.pory"

# 7 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_OnTransition:
# 8 "data/maps/PacifidlogTown/scripts.pory"
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
# 9 "data/maps/PacifidlogTown/scripts.pory"
	end
# 10 "data/maps/PacifidlogTown/scripts.pory"

# 11 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_OnResume:
# 12 "data/maps/PacifidlogTown/scripts.pory"
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
# 13 "data/maps/PacifidlogTown/scripts.pory"
	end
# 14 "data/maps/PacifidlogTown/scripts.pory"

# 15 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_NinjaBoy::
# 16 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
# 17 "data/maps/PacifidlogTown/scripts.pory"
	end
# 18 "data/maps/PacifidlogTown/scripts.pory"

# 19 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_Girl::
# 20 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
# 21 "data/maps/PacifidlogTown/scripts.pory"
	end
# 22 "data/maps/PacifidlogTown/scripts.pory"

# 23 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_Fisherman::
# 24 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
# 25 "data/maps/PacifidlogTown/scripts.pory"
	end
# 26 "data/maps/PacifidlogTown/scripts.pory"

# 27 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_EventScript_TownSign::
# 28 "data/maps/PacifidlogTown/scripts.pory"
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
# 29 "data/maps/PacifidlogTown/scripts.pory"
	end
# 30 "data/maps/PacifidlogTown/scripts.pory"

# 31 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_FastRunningCurrent:
# 32 "data/maps/PacifidlogTown/scripts.pory"
	.string "The sea between PACIFIDLOG and\n"
# 33 "data/maps/PacifidlogTown/scripts.pory"
	.string "SLATEPORT has a fast-running tide.\p"
# 34 "data/maps/PacifidlogTown/scripts.pory"
	.string "If you decide to SURF, you could end\n"
# 35 "data/maps/PacifidlogTown/scripts.pory"
	.string "up swept away somewhere else.$"
# 36 "data/maps/PacifidlogTown/scripts.pory"

# 37 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_NeatHousesOnWater:
# 38 "data/maps/PacifidlogTown/scripts.pory"
	.string "See, isn't it neat?\n"
# 39 "data/maps/PacifidlogTown/scripts.pory"
	.string "These houses are on water!\p"
# 40 "data/maps/PacifidlogTown/scripts.pory"
	.string "I was born here!$"
# 41 "data/maps/PacifidlogTown/scripts.pory"

# 42 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_SkyPillarTooScary:
# 43 "data/maps/PacifidlogTown/scripts.pory"
	.string "The SKY PILLAR?\p"
# 44 "data/maps/PacifidlogTown/scripts.pory"
	.string "…Oh, you must mean that tall, tall\n"
# 45 "data/maps/PacifidlogTown/scripts.pory"
	.string "tower a little further out.\p"
# 46 "data/maps/PacifidlogTown/scripts.pory"
	.string "If you asked me, I wouldn't climb it.\n"
# 47 "data/maps/PacifidlogTown/scripts.pory"
	.string "It's too scary to get up that high.\p"
# 48 "data/maps/PacifidlogTown/scripts.pory"
	.string "Life at sea level in PACIFIDLOG,\n"
# 49 "data/maps/PacifidlogTown/scripts.pory"
	.string "that suits me fine.$"
# 50 "data/maps/PacifidlogTown/scripts.pory"

# 51 "data/maps/PacifidlogTown/scripts.pory"
PacifidlogTown_Text_TownSign:
# 52 "data/maps/PacifidlogTown/scripts.pory"
	.string "PACIFIDLOG TOWN\p"
# 53 "data/maps/PacifidlogTown/scripts.pory"
	.string "“Where the morning sun smiles upon\n"
# 54 "data/maps/PacifidlogTown/scripts.pory"
	.string "the waters.”$"

EventScript_WARP_STAR_ISLAND::
# 60 "data/maps/PacifidlogTown/scripts.pory"
	lock
# 61 "data/maps/PacifidlogTown/scripts.pory"
	faceplayer
# 62 "data/maps/PacifidlogTown/scripts.pory"
	goto_if_set FLAG_JIRACHI_GIFT, EventScript_WARP_STAR_ISLAND_2
# 68 "data/maps/PacifidlogTown/scripts.pory"
	msgbox EventScript_WARP_STAR_ISLAND_Text_1, MSGBOX_YESNO
# 70 "data/maps/PacifidlogTown/scripts.pory"
	switch VAR_RESULT
# 71 "data/maps/PacifidlogTown/scripts.pory"
	case YES, EventScript_WARP_STAR_ISLAND_6
# 80 "data/maps/PacifidlogTown/scripts.pory"
	case NO, EventScript_WARP_STAR_ISLAND_7
EventScript_WARP_STAR_ISLAND_4:
# 83 "data/maps/PacifidlogTown/scripts.pory"
	release
	end

EventScript_WARP_STAR_ISLAND_2:
# 63 "data/maps/PacifidlogTown/scripts.pory"
	msgbox EventScript_WARP_STAR_ISLAND_Text_0
# 65 "data/maps/PacifidlogTown/scripts.pory"
	release
	end

EventScript_WARP_STAR_ISLAND_6:
# 72 "data/maps/PacifidlogTown/scripts.pory"
	msgbox EventScript_WARP_STAR_ISLAND_Text_2
# 73 "data/maps/PacifidlogTown/scripts.pory"
	closemessage
# 74 "data/maps/PacifidlogTown/scripts.pory"
	fadescreen FADE_TO_BLACK
# 75 "data/maps/PacifidlogTown/scripts.pory"
	playse SE_SHIP
# 76 "data/maps/PacifidlogTown/scripts.pory"
	delay 60
# 78 "data/maps/PacifidlogTown/scripts.pory"
	warp MAP_STAR_ISLAND, 15, 34
# 79 "data/maps/PacifidlogTown/scripts.pory"
	waitstate
	goto EventScript_WARP_STAR_ISLAND_4

EventScript_WARP_STAR_ISLAND_7:
# 81 "data/maps/PacifidlogTown/scripts.pory"
	msgbox EventScript_WARP_STAR_ISLAND_Text_3
	goto EventScript_WARP_STAR_ISLAND_4


EventScript_WARP_STAR_ISLAND_Text_0:
# 63 "data/maps/PacifidlogTown/scripts.pory"
	.string "Ahoy. I only sail to charted waters,\n"
	.string "friend.\n"
	.string "That map of yours leads nowhere yet.$"

EventScript_WARP_STAR_ISLAND_Text_1:
# 68 "data/maps/PacifidlogTown/scripts.pory"
	.string "That map... That sketch... aye, I know\n"
	.string "those waters. They say wishes come\l"
	.string "true out there.\p"
	.string "Set sail for the island?$"

EventScript_WARP_STAR_ISLAND_Text_2:
# 72 "data/maps/PacifidlogTown/scripts.pory"
	.string "Then hold on tight. The stars'll guide us\n"
	.string "in.$"

EventScript_WARP_STAR_ISLAND_Text_3:
# 81 "data/maps/PacifidlogTown/scripts.pory"
	.string "Change your mind and the tide'll still be\n"
	.string "here.$"
