# 1 "data/maps/OldaleTown_House1/scripts.pory"
OldaleTown_House1_MapScripts::
# 2 "data/maps/OldaleTown_House1/scripts.pory"
	.byte 0
# 3 "data/maps/OldaleTown_House1/scripts.pory"

# 4 "data/maps/OldaleTown_House1/scripts.pory"
OldaleTown_House1_EventScript_Woman::
# 5 "data/maps/OldaleTown_House1/scripts.pory"
	msgbox OldaleTown_House1_Text_LeftPokemonGoesOutFirst, MSGBOX_NPC
# 6 "data/maps/OldaleTown_House1/scripts.pory"
	end
# 7 "data/maps/OldaleTown_House1/scripts.pory"

# 8 "data/maps/OldaleTown_House1/scripts.pory"
OldaleTown_House1_Text_LeftPokemonGoesOutFirst:
# 9 "data/maps/OldaleTown_House1/scripts.pory"
	.string "When a POKéMON battle starts, the one\n"
# 10 "data/maps/OldaleTown_House1/scripts.pory"
	.string "at the left of the list goes out first.\p"
# 11 "data/maps/OldaleTown_House1/scripts.pory"
	.string "So, when you get more POKéMON in your\n"
# 12 "data/maps/OldaleTown_House1/scripts.pory"
	.string "party, try switching around the order\l"
# 13 "data/maps/OldaleTown_House1/scripts.pory"
	.string "of your POKéMON.\p"
# 14 "data/maps/OldaleTown_House1/scripts.pory"
	.string "It could give you an advantage.$"

CELEBIquest_starter::
# 19 "data/maps/OldaleTown_House1/scripts.pory"
	lockall
# 20 "data/maps/OldaleTown_House1/scripts.pory"
	faceplayer
# 21 "data/maps/OldaleTown_House1/scripts.pory"
	goto_if_set FLAG_CELEBI_GIFT, CELEBIquest_starter_2
# 26 "data/maps/OldaleTown_House1/scripts.pory"
	msgbox CELEBIquest_starter_Text_1
# 27 "data/maps/OldaleTown_House1/scripts.pory"
	msgbox CELEBIquest_starter_Text_2, MSGBOX_YESNO
# 29 "data/maps/OldaleTown_House1/scripts.pory"
	switch VAR_RESULT
# 30 "data/maps/OldaleTown_House1/scripts.pory"
	case YES, CELEBIquest_starter_6
# 35 "data/maps/OldaleTown_House1/scripts.pory"
	case NO, CELEBIquest_starter_7
CELEBIquest_starter_4:
# 38 "data/maps/OldaleTown_House1/scripts.pory"
	release
	end

CELEBIquest_starter_2:
# 22 "data/maps/OldaleTown_House1/scripts.pory"
	msgbox CELEBIquest_starter_Text_0
# 23 "data/maps/OldaleTown_House1/scripts.pory"
	release
	end

CELEBIquest_starter_6:
# 31 "data/maps/OldaleTown_House1/scripts.pory"
	setflag FLAG_CELEBI_GIFT
# 32 "data/maps/OldaleTown_House1/scripts.pory"
	setflag FLAG_CELEBI_LADY
# 33 "data/maps/OldaleTown_House1/scripts.pory"
	giveitem ITEM_TEA
# 34 "data/maps/OldaleTown_House1/scripts.pory"
	msgbox CELEBIquest_starter_Text_3
	goto CELEBIquest_starter_4

CELEBIquest_starter_7:
# 36 "data/maps/OldaleTown_House1/scripts.pory"
	msgbox CELEBIquest_starter_Text_4
	goto CELEBIquest_starter_4


CELEBIquest_starter_Text_0:
# 22 "data/maps/OldaleTown_House1/scripts.pory"
	.string "Should've tasted the tea for myself.$"

CELEBIquest_starter_Text_1:
# 26 "data/maps/OldaleTown_House1/scripts.pory"
	.string "Have you heard the voice of the\n"
	.string "forest? An old Johtonian folktale... A\l"
	.string "Pokémon that wanders across time,\l"
	.string "breathing life into the vegetation as\l"
	.string "it flies through forests.$"

CELEBIquest_starter_Text_2:
# 27 "data/maps/OldaleTown_House1/scripts.pory"
	.string "'The Voice' couldn't resist this tea.\n\n"
	.string "Want some?$"

CELEBIquest_starter_Text_3:
# 34 "data/maps/OldaleTown_House1/scripts.pory"
	.string "Sammy also told me this Pokémon has a\n"
	.string "thing for forests. Bye now.$"

CELEBIquest_starter_Text_4:
# 36 "data/maps/OldaleTown_House1/scripts.pory"
	.string "I understand...$"
