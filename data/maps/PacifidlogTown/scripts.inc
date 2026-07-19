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
	call RoamingLegendQuests_EventScript_SyncNpcVisibility
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

EventScript_SAIL2LEGENDS::
# 64 "data/maps/PacifidlogTown/scripts.pory"
	lock
# 65 "data/maps/PacifidlogTown/scripts.pory"
	faceplayer
# 68 "data/maps/PacifidlogTown/scripts.pory"
	goto_if_set FLAG_JIRACHI_GIFT, EventScript_SAIL2LEGENDS_2
	checkitem ITEM_GRACIDEA
# 0 "data/maps/PacifidlogTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne EventScript_SAIL2LEGENDS_5
# 109 "data/maps/PacifidlogTown/scripts.pory"
	msgbox EventScript_SAIL2LEGENDS_Text_5
# 111 "data/maps/PacifidlogTown/scripts.pory"
	release
	end

EventScript_SAIL2LEGENDS_2:
	checkitem ITEM_GRACIDEA
# 0 "data/maps/PacifidlogTown/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne EventScript_SAIL2LEGENDS_8
# 87 "data/maps/PacifidlogTown/scripts.pory"
	msgbox EventScript_SAIL2LEGENDS_Text_3, MSGBOX_YESNO
# 89 "data/maps/PacifidlogTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_SAIL2LEGENDS_14
EventScript_SAIL2LEGENDS_13:
# 92 "data/maps/PacifidlogTown/scripts.pory"
	msgbox EventScript_SAIL2LEGENDS_Text_2
# 93 "data/maps/PacifidlogTown/scripts.pory"
	release
	end

EventScript_SAIL2LEGENDS_5:
# 98 "data/maps/PacifidlogTown/scripts.pory"
	msgbox EventScript_SAIL2LEGENDS_Text_4, MSGBOX_YESNO
# 101 "data/maps/PacifidlogTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_SAIL2LEGENDS_11
EventScript_SAIL2LEGENDS_10:
# 104 "data/maps/PacifidlogTown/scripts.pory"
	msgbox EventScript_SAIL2LEGENDS_Text_2
# 105 "data/maps/PacifidlogTown/scripts.pory"
	release
	end

EventScript_SAIL2LEGENDS_8:
# 71 "data/maps/PacifidlogTown/scripts.pory"
	msgbox EventScript_SAIL2LEGENDS_Text_0, MSGBOX_YESNO
# 74 "data/maps/PacifidlogTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_SAIL2LEGENDS_17
EventScript_SAIL2LEGENDS_16:
# 77 "data/maps/PacifidlogTown/scripts.pory"
	msgbox EventScript_SAIL2LEGENDS_Text_1, MSGBOX_YESNO
# 79 "data/maps/PacifidlogTown/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq EventScript_SAIL2LEGENDS_20
EventScript_SAIL2LEGENDS_19:
# 82 "data/maps/PacifidlogTown/scripts.pory"
	msgbox EventScript_SAIL2LEGENDS_Text_2
# 83 "data/maps/PacifidlogTown/scripts.pory"
	release
	end

EventScript_SAIL2LEGENDS_11:
# 102 "data/maps/PacifidlogTown/scripts.pory"
	goto EventScript_SailToFlowerParadise
	goto EventScript_SAIL2LEGENDS_10

EventScript_SAIL2LEGENDS_14:
# 90 "data/maps/PacifidlogTown/scripts.pory"
	goto EventScript_SailToStarIsland
	goto EventScript_SAIL2LEGENDS_13

EventScript_SAIL2LEGENDS_17:
# 75 "data/maps/PacifidlogTown/scripts.pory"
	goto EventScript_SailToStarIsland
	goto EventScript_SAIL2LEGENDS_16

EventScript_SAIL2LEGENDS_20:
# 80 "data/maps/PacifidlogTown/scripts.pory"
	goto EventScript_SailToFlowerParadise
	goto EventScript_SAIL2LEGENDS_19


EventScript_SailToStarIsland::
# 122 "data/maps/PacifidlogTown/scripts.pory"
	msgbox EventScript_SailToStarIsland_Text_0
# 123 "data/maps/PacifidlogTown/scripts.pory"
	call EventScript_PacifidlogSailAway
# 124 "data/maps/PacifidlogTown/scripts.pory"
	warp MAP_STAR_ISLAND, 15, 34
# 125 "data/maps/PacifidlogTown/scripts.pory"
	waitstate
# 126 "data/maps/PacifidlogTown/scripts.pory"
	release
	end


EventScript_SailToFlowerParadise::
# 131 "data/maps/PacifidlogTown/scripts.pory"
	msgbox EventScript_SailToFlowerParadise_Text_0
# 133 "data/maps/PacifidlogTown/scripts.pory"
	call EventScript_PacifidlogSailAway
# 134 "data/maps/PacifidlogTown/scripts.pory"
	warp MAP_FLOWER_PARADISE, 18, 74
# 135 "data/maps/PacifidlogTown/scripts.pory"
	waitstate
# 136 "data/maps/PacifidlogTown/scripts.pory"
	release
	end


EventScript_PacifidlogSailAway::
# 147 "data/maps/PacifidlogTown/scripts.pory"
	closemessage
# 151 "data/maps/PacifidlogTown/scripts.pory"
	hidefollower 1
# 153 "data/maps/PacifidlogTown/scripts.pory"
	applymovement LOCALID_PLAYER, Movement_PacifidlogPlayerBoard
# 154 "data/maps/PacifidlogTown/scripts.pory"
	waitmovement 0
# 155 "data/maps/PacifidlogTown/scripts.pory"
	hideobjectat LOCALID_PLAYER, MAP_PACIFIDLOG_TOWN
# 160 "data/maps/PacifidlogTown/scripts.pory"
	applymovement 4, Movement_PacifidlogSailorFollow
# 161 "data/maps/PacifidlogTown/scripts.pory"
	waitmovement 0
# 162 "data/maps/PacifidlogTown/scripts.pory"
	hideobjectat 4, MAP_PACIFIDLOG_TOWN
# 164 "data/maps/PacifidlogTown/scripts.pory"
	playse SE_SHIP
# 165 "data/maps/PacifidlogTown/scripts.pory"
	applymovement 5, Movement_PacifidlogBoatDepart
# 166 "data/maps/PacifidlogTown/scripts.pory"
	delay 30
# 167 "data/maps/PacifidlogTown/scripts.pory"
	fadescreen FADE_TO_BLACK
# 168 "data/maps/PacifidlogTown/scripts.pory"
	waitmovement 0
# 169 "data/maps/PacifidlogTown/scripts.pory"
	hideobjectat 5, MAP_PACIFIDLOG_TOWN
	return


# 175 "data/maps/PacifidlogTown/scripts.pory"
Movement_PacifidlogPlayerBoard:
# 176 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 177 "data/maps/PacifidlogTown/scripts.pory"
	set_invisible
	step_end

# 181 "data/maps/PacifidlogTown/scripts.pory"
Movement_PacifidlogSailorFollow:
# 182 "data/maps/PacifidlogTown/scripts.pory"
	walk_down
# 183 "data/maps/PacifidlogTown/scripts.pory"
	delay_16
	step_end

# 187 "data/maps/PacifidlogTown/scripts.pory"
Movement_PacifidlogBoatDepart:
# 188 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 189 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
# 190 "data/maps/PacifidlogTown/scripts.pory"
	walk_left
	step_end

EventScript_SAIL2LEGENDS_Text_0:
# 71 "data/maps/PacifidlogTown/scripts.pory"
	.string "Ahoy! I can chart a course for two\n"
	.string "hidden\n"
	.string "waters this day.\p"
	.string "Set sail for the star-blessed island?$"

EventScript_SAIL2LEGENDS_Text_1:
# 77 "data/maps/PacifidlogTown/scripts.pory"
	.string "Then shall I steer for the isle of\n"
	.string "endless\n"
	.string "flowers instead?$"

EventScript_SAIL2LEGENDS_Text_2:
# 82 "data/maps/PacifidlogTown/scripts.pory"
	.string "Change your mind and the tide'll still be\n"
	.string "here.$"

EventScript_SAIL2LEGENDS_Text_3:
# 87 "data/maps/PacifidlogTown/scripts.pory"
	.string "That map... That sketch... aye, I know\n"
	.string "those waters. They say wishes come\l"
	.string "true out there.\p"
	.string "Set sail for the island?$"

EventScript_SAIL2LEGENDS_Text_4:
# 98 "data/maps/PacifidlogTown/scripts.pory"
	.string "That flower you're carrying… it only\n"
	.string "blooms in one faraway place.\p"
	.string "Shall I take you to the isle of endless\n"
	.string "flowers?$"

EventScript_SAIL2LEGENDS_Text_5:
# 109 "data/maps/PacifidlogTown/scripts.pory"
	.string "Ahoy. I only sail to charted waters,\n"
	.string "friend.\n"
	.string "You've nowhere to go just yet.$"

EventScript_SailToStarIsland_Text_0:
# 122 "data/maps/PacifidlogTown/scripts.pory"
	.string "Then hold on tight. The stars'll guide us\n"
	.string "in.$"

EventScript_SailToFlowerParadise_Text_0:
# 131 "data/maps/PacifidlogTown/scripts.pory"
	.string "Then hold on tight. We'll follow the\n"
	.string "petals on the wind.$"
