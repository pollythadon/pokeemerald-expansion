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
# 76 "data/maps/PetalburgCity_House1/scripts.pory"
	msgbox PetalburgCity_House1_EventScript_Scientist_Text_5, MSGBOX_YESNO
# 82 "data/maps/PetalburgCity_House1/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_House1_EventScript_Scientist_5
# 87 "data/maps/PetalburgCity_House1/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 88 "data/maps/PetalburgCity_House1/scripts.pory"
	setflag FLAG_DEXNAV_GET
# 89 "data/maps/PetalburgCity_House1/scripts.pory"
	waitfanfare
# 90 "data/maps/PetalburgCity_House1/scripts.pory"
	msgbox PetalburgCity_House1_EventScript_Scientist_Text_7
# 93 "data/maps/PetalburgCity_House1/scripts.pory"
	completequest QUEST_DEXNAV
# 94 "data/maps/PetalburgCity_House1/scripts.pory"
	release
	end

PetalburgCity_House1_EventScript_Scientist_2:
# 35 "data/maps/PetalburgCity_House1/scripts.pory"
	goto_if_set FLAG_DEXNAV_SHOW_ALL, PetalburgCity_House1_EventScript_Scientist_8
# 43 "data/maps/PetalburgCity_House1/scripts.pory"
	msgbox PetalburgCity_House1_EventScript_Scientist_Text_1, MSGBOX_YESNO
# 50 "data/maps/PetalburgCity_House1/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq PetalburgCity_House1_EventScript_Scientist_11
# 56 "data/maps/PetalburgCity_House1/scripts.pory"
	checkmoney 50000
# 57 "data/maps/PetalburgCity_House1/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq PetalburgCity_House1_EventScript_Scientist_14
# 63 "data/maps/PetalburgCity_House1/scripts.pory"
	showmoneybox 0, 0
# 64 "data/maps/PetalburgCity_House1/scripts.pory"
	removemoney 50000
# 65 "data/maps/PetalburgCity_House1/scripts.pory"
	updatemoneybox
# 66 "data/maps/PetalburgCity_House1/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 67 "data/maps/PetalburgCity_House1/scripts.pory"
	setflag FLAG_DEXNAV_SHOW_ALL
# 68 "data/maps/PetalburgCity_House1/scripts.pory"
	waitfanfare
# 69 "data/maps/PetalburgCity_House1/scripts.pory"
	msgbox PetalburgCity_House1_EventScript_Scientist_Text_4
# 72 "data/maps/PetalburgCity_House1/scripts.pory"
	hidemoneybox
# 73 "data/maps/PetalburgCity_House1/scripts.pory"
	release
	end

PetalburgCity_House1_EventScript_Scientist_5:
# 83 "data/maps/PetalburgCity_House1/scripts.pory"
	msgbox PetalburgCity_House1_EventScript_Scientist_Text_6
# 84 "data/maps/PetalburgCity_House1/scripts.pory"
	release
	end

PetalburgCity_House1_EventScript_Scientist_8:
# 36 "data/maps/PetalburgCity_House1/scripts.pory"
	msgbox PetalburgCity_House1_EventScript_Scientist_Text_0
# 40 "data/maps/PetalburgCity_House1/scripts.pory"
	release
	end

PetalburgCity_House1_EventScript_Scientist_11:
# 51 "data/maps/PetalburgCity_House1/scripts.pory"
	msgbox PetalburgCity_House1_EventScript_Scientist_Text_2
# 53 "data/maps/PetalburgCity_House1/scripts.pory"
	release
	end

PetalburgCity_House1_EventScript_Scientist_14:
# 58 "data/maps/PetalburgCity_House1/scripts.pory"
	msgbox PetalburgCity_House1_EventScript_Scientist_Text_3
# 60 "data/maps/PetalburgCity_House1/scripts.pory"
	release
	end


PetalburgCity_House1_EventScript_Scientist_Text_0:
# 36 "data/maps/PetalburgCity_House1/scripts.pory"
	.string "So, has my DexNav app been pulling its\n"
	.string "weight?\p"
	.string "Sniffing out those sneaky POKéMON\n"
	.string "hiding in the grass has to be paying off\l"
	.string "by now, right?\p"
	.string "Data, data! Tell me it's been useful!$"

PetalburgCity_House1_EventScript_Scientist_Text_1:
# 43 "data/maps/PetalburgCity_House1/scripts.pory"
	.string "Say, I've been tinkering with the\n"
	.string "DexNav some more!\p"
	.string "I can push a premium update that\n"
	.string "reveals EVERY POKéMON living on a\l"
	.string "route… even ones you've never laid eyes\l"
	.string "on.\p"
	.string "The research licensing isn't cheap,\n"
	.string "though.\n"
	.string "I'll need ¥50000 to cover it.\p"
	.string "Shall I install the upgrade?$"

PetalburgCity_House1_EventScript_Scientist_Text_2:
# 51 "data/maps/PetalburgCity_House1/scripts.pory"
	.string "No pressure! The offer stands whenever\n"
	.string "you're ready.$"

PetalburgCity_House1_EventScript_Scientist_Text_3:
# 58 "data/maps/PetalburgCity_House1/scripts.pory"
	.string "Hmm, you're a little short on funds.\n"
	.string "Come back once you've saved up ¥50000!$"

PetalburgCity_House1_EventScript_Scientist_Text_4:
# 69 "data/maps/PetalburgCity_House1/scripts.pory"
	.string "There! The DexNav upgrade is installed.\p"
	.string "Now it'll list every POKéMON on the\n"
	.string "route,\n"
	.string "seen or not. Happy hunting!$"

PetalburgCity_House1_EventScript_Scientist_Text_5:
# 76 "data/maps/PetalburgCity_House1/scripts.pory"
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

PetalburgCity_House1_EventScript_Scientist_Text_6:
# 83 "data/maps/PetalburgCity_House1/scripts.pory"
	.string "No pressure! Swing by whenever you'd\n"
	.string "like it.$"

PetalburgCity_House1_EventScript_Scientist_Text_7:
# 90 "data/maps/PetalburgCity_House1/scripts.pory"
	.string "There! The DexNav is now installed.\p"
	.string "You'll find it inside your ROTOM PHONE.\n"
	.string "Go put it to good use!$"
