# 1 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_MapScripts::
# 2 "data/maps/SootopolisCity_House2/scripts.pory"
	.byte 0
# 3 "data/maps/SootopolisCity_House2/scripts.pory"

# 4 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_EventScript_ExpertF::
# 5 "data/maps/SootopolisCity_House2/scripts.pory"
	lock
# 6 "data/maps/SootopolisCity_House2/scripts.pory"
	faceplayer
# 7 "data/maps/SootopolisCity_House2/scripts.pory"
	msgbox SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs, MSGBOX_YESNO
# 8 "data/maps/SootopolisCity_House2/scripts.pory"
	call_if_eq VAR_RESULT, YES, SootopolisCity_House2_EventScript_KnowAboutOrbs
# 9 "data/maps/SootopolisCity_House2/scripts.pory"
	call_if_eq VAR_RESULT, NO, SootopolisCity_House2_EventScript_DontKnowAboutOrbs
# 10 "data/maps/SootopolisCity_House2/scripts.pory"
	release
# 11 "data/maps/SootopolisCity_House2/scripts.pory"
	end
# 12 "data/maps/SootopolisCity_House2/scripts.pory"

# 13 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_EventScript_KnowAboutOrbs::
# 14 "data/maps/SootopolisCity_House2/scripts.pory"
	msgbox SootopolisCity_House2_Text_YesTwoOrbsSideBySide, MSGBOX_DEFAULT
# 15 "data/maps/SootopolisCity_House2/scripts.pory"
	return
# 16 "data/maps/SootopolisCity_House2/scripts.pory"

# 17 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_EventScript_DontKnowAboutOrbs::
# 18 "data/maps/SootopolisCity_House2/scripts.pory"
	msgbox SootopolisCity_House2_Text_OughtToVisitAndSee, MSGBOX_DEFAULT
# 19 "data/maps/SootopolisCity_House2/scripts.pory"
	return
# 20 "data/maps/SootopolisCity_House2/scripts.pory"

# 21 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs:
# 22 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "MT. PYRE…\p"
# 23 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "At its peak are two orbs placed side\n"
# 24 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "by side. Did you know?$"
# 25 "data/maps/SootopolisCity_House2/scripts.pory"

# 26 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_Text_YesTwoOrbsSideBySide:
# 27 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "Yes, two orbs side by side…\p"
# 28 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "The sight of them together…\n"
# 29 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "It is somehow soothing…$"
# 30 "data/maps/SootopolisCity_House2/scripts.pory"

# 31 "data/maps/SootopolisCity_House2/scripts.pory"
SootopolisCity_House2_Text_OughtToVisitAndSee:
# 32 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "Is that so?\n"
# 33 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "Perhaps you ought to visit and see…$"

ARCEUS_quest_starter::
# 38 "data/maps/SootopolisCity_House2/scripts.pory"
	lockall
# 39 "data/maps/SootopolisCity_House2/scripts.pory"
	faceplayer
# 40 "data/maps/SootopolisCity_House2/scripts.pory"
	goto_if_set FLAG_ARCEUS_ROCKET_UNLOCKED, ARCEUS_quest_starter_2
	checkpartymon SPECIES_DIALGA
# 0 "data/maps/SootopolisCity_House2/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne ARCEUS_quest_starter_8
ARCEUS_quest_starter_6:
# 51 "data/maps/SootopolisCity_House2/scripts.pory"
	msgbox ARCEUS_quest_starter_Text_2
ARCEUS_quest_starter_4:
# 54 "data/maps/SootopolisCity_House2/scripts.pory"
	releaseall
	end

ARCEUS_quest_starter_2:
# 41 "data/maps/SootopolisCity_House2/scripts.pory"
	msgbox ARCEUS_quest_starter_Text_0
# 42 "data/maps/SootopolisCity_House2/scripts.pory"
	releaseall
	end

ARCEUS_quest_starter_5:
# 46 "data/maps/SootopolisCity_House2/scripts.pory"
	playse SE_PIN
# 47 "data/maps/SootopolisCity_House2/scripts.pory"
	setflag FLAG_ARCEUS_ROCKET_UNLOCKED
# 48 "data/maps/SootopolisCity_House2/scripts.pory"
	msgbox ARCEUS_quest_starter_Text_1
	goto ARCEUS_quest_starter_4

ARCEUS_quest_starter_7:
	checkpartymon SPECIES_GIRATINA
# 0 "data/maps/SootopolisCity_House2/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne ARCEUS_quest_starter_5
	goto ARCEUS_quest_starter_6

ARCEUS_quest_starter_8:
	checkpartymon SPECIES_PALKIA
# 0 "data/maps/SootopolisCity_House2/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne ARCEUS_quest_starter_7
	goto ARCEUS_quest_starter_6


ARCEUS_quest_starter_Text_0:
# 41 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "The rocket is fuelled and waiting. The\n"
	.string "heavens are yours to reach.$"

ARCEUS_quest_starter_Text_1:
# 48 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "...Time. Space. Antimatter. All three\n"
	.string "answer to you.\p"
	.string "Then it's true, you're ready. The rocket\n"
	.string "is yours. Ride it to the meteor beyond\l"
	.string "the sky, and meet your Maker.$"

ARCEUS_quest_starter_Text_2:
# 51 "data/maps/SootopolisCity_House2/scripts.pory"
	.string "They say three beasts created the\n"
	.string "three pillars of reality, one for time,\l"
	.string "one for space, one for the void\l"
	.string "between.\p"
	.string "Bring all three before me at once, and\n"
	.string "I'll know you're ready to meet the One\l"
	.string "that made them.$"
