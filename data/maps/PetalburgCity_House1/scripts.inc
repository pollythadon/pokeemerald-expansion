# 1 "data/maps/PetalburgCity_House1/scripts.pory"
PetalburgCity_House1_MapScripts::
# 2 "data/maps/PetalburgCity_House1/scripts.pory"
	.byte 0
# 3 "data/maps/PetalburgCity_House1/scripts.pory"

# 4 "data/maps/PetalburgCity_House1/scripts.pory"
PetalburgCity_House1_EventScript_Man::
# 5 "data/maps/PetalburgCity_House1/scripts.pory"
	msgbox PetalburgCity_House1_Text_TravelingIsWonderful, MSGBOX_NPC
# 6 "data/maps/PetalburgCity_House1/scripts.pory"
	end
# 7 "data/maps/PetalburgCity_House1/scripts.pory"

# 8 "data/maps/PetalburgCity_House1/scripts.pory"
PetalburgCity_House1_EventScript_Woman::
# 9 "data/maps/PetalburgCity_House1/scripts.pory"
	msgbox PetalburgCity_House1_Text_GoOnAdventure, MSGBOX_NPC
# 10 "data/maps/PetalburgCity_House1/scripts.pory"
	end
# 11 "data/maps/PetalburgCity_House1/scripts.pory"

# 12 "data/maps/PetalburgCity_House1/scripts.pory"
PetalburgCity_House1_Text_TravelingIsWonderful:
# 13 "data/maps/PetalburgCity_House1/scripts.pory"
	.string "Traveling is wonderful!\p"
# 14 "data/maps/PetalburgCity_House1/scripts.pory"
	.string "When I was young, I roamed the seas\n"
# 15 "data/maps/PetalburgCity_House1/scripts.pory"
	.string "and the mountains!$"
# 16 "data/maps/PetalburgCity_House1/scripts.pory"

# 17 "data/maps/PetalburgCity_House1/scripts.pory"
PetalburgCity_House1_Text_GoOnAdventure:
# 18 "data/maps/PetalburgCity_House1/scripts.pory"
	.string "Sigh…\p"
# 19 "data/maps/PetalburgCity_House1/scripts.pory"
	.string "I wish I could go on an adventure\n"
# 20 "data/maps/PetalburgCity_House1/scripts.pory"
	.string "with some POKéMON…\p"
# 21 "data/maps/PetalburgCity_House1/scripts.pory"
	.string "Crawl through some damp grass…\n"
# 22 "data/maps/PetalburgCity_House1/scripts.pory"
	.string "Climb rocky, rugged mountains…\p"
# 23 "data/maps/PetalburgCity_House1/scripts.pory"
	.string "Cross the raging seas…\n"
# 24 "data/maps/PetalburgCity_House1/scripts.pory"
	.string "Wander about in dark caves…\p"
# 25 "data/maps/PetalburgCity_House1/scripts.pory"
	.string "And, sometimes, even get a little\n"
# 26 "data/maps/PetalburgCity_House1/scripts.pory"
	.string "homesick…\p"
# 27 "data/maps/PetalburgCity_House1/scripts.pory"
	.string "It must be fabulous to travel!$"

PetalburgCity_House1_EventScript_Scientist::
# 32 "data/maps/PetalburgCity_House1/scripts.pory"
	lock
# 33 "data/maps/PetalburgCity_House1/scripts.pory"
	faceplayer
# 34 "data/maps/PetalburgCity_House1/scripts.pory"
	goto_if_set FLAG_DEXNAV_GET, PetalburgCity_House1_EventScript_Scientist_2
# 42 "data/maps/PetalburgCity_House1/scripts.pory"
	msgbox PetalburgCity_House1_EventScript_Scientist_Text_1, MSGBOX_YESNO
# 48 "data/maps/PetalburgCity_House1/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_House1_EventScript_Scientist_5
# 53 "data/maps/PetalburgCity_House1/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 54 "data/maps/PetalburgCity_House1/scripts.pory"
	setflag FLAG_DEXNAV_GET
# 55 "data/maps/PetalburgCity_House1/scripts.pory"
	waitfanfare
# 56 "data/maps/PetalburgCity_House1/scripts.pory"
	msgbox PetalburgCity_House1_EventScript_Scientist_Text_3
# 59 "data/maps/PetalburgCity_House1/scripts.pory"
	release
	end

PetalburgCity_House1_EventScript_Scientist_2:
# 35 "data/maps/PetalburgCity_House1/scripts.pory"
	msgbox PetalburgCity_House1_EventScript_Scientist_Text_0
# 39 "data/maps/PetalburgCity_House1/scripts.pory"
	release
	end

PetalburgCity_House1_EventScript_Scientist_5:
# 49 "data/maps/PetalburgCity_House1/scripts.pory"
	msgbox PetalburgCity_House1_EventScript_Scientist_Text_2
# 50 "data/maps/PetalburgCity_House1/scripts.pory"
	release
	end


PetalburgCity_House1_EventScript_Scientist_Text_0:
# 35 "data/maps/PetalburgCity_House1/scripts.pory"
	.string "So, has my DexNav app been pulling its\n"
	.string "weight?\p"
	.string "Sniffing out those sneaky POKéMON\n"
	.string "hiding in the\l"
	.string "grass has to be paying off by now,\l"
	.string "right?\p"
	.string "Data, data! Tell me it's been useful!$"

PetalburgCity_House1_EventScript_Scientist_Text_1:
# 42 "data/maps/PetalburgCity_House1/scripts.pory"
	.string "Oho! A fellow traveler with a ROTOM\n"
	.string "PHONE!\p"
	.string "I've just finished coding a brand-new\n"
	.string "app for it.\n"
	.string "I call it the DexNav!\p"
	.string "It scans the area for POKéMON lurking\n"
	.string "nearby, so you'll never walk past a rare\l"
	.string "one again.\p"
	.string "Want me to install it onto your ROTOM\n"
	.string "PHONE?$"

PetalburgCity_House1_EventScript_Scientist_Text_2:
# 49 "data/maps/PetalburgCity_House1/scripts.pory"
	.string "No pressure! Swing by whenever you'd\n"
	.string "like it.$"

PetalburgCity_House1_EventScript_Scientist_Text_3:
# 56 "data/maps/PetalburgCity_House1/scripts.pory"
	.string "There! The DexNav is now installed.\p"
	.string "You'll find it inside your ROTOM PHONE.\n"
	.string "Go put it to good use!$"
