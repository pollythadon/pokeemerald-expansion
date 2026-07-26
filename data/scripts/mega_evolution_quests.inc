MegaEvolutionQuest_EventScript_StevenIntro::
# 4 "data/scripts/mega_evolution_quests.pory"
	goto_if_set FLAG_STARTED_MEGA_RING_QUEST, MegaEvolutionQuest_EventScript_StevenIntro_2
# 8 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_StevenIntro_Text_0
# 9 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_StevenIntro_Text_1
# 10 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_StevenIntro_Text_2
# 11 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_StevenIntro_Text_3
# 12 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_StevenIntro_Text_4
# 13 "data/scripts/mega_evolution_quests.pory"
	setflag FLAG_STARTED_MEGA_RING_QUEST
# 14 "data/scripts/mega_evolution_quests.pory"
	startquest QUEST_MEGA_RING
# 15 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_StevenIntro_Text_5
	return

MegaEvolutionQuest_EventScript_StevenIntro_2:
	return


MegaEvolutionQuest_MapScript_GraniteCave::
# 20 "data/scripts/mega_evolution_quests.pory"
	goto_if_unset FLAG_DELIVERED_STEVEN_LETTER, MegaEvolutionQuest_MapScript_GraniteCave_2
# 25 "data/scripts/mega_evolution_quests.pory"
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_MEGA_RING
# 26 "data/scripts/mega_evolution_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MegaEvolutionQuest_MapScript_GraniteCave_5
# 29 "data/scripts/mega_evolution_quests.pory"
	setflag FLAG_HIDE_GRANITE_CAVE_STEVEN
MegaEvolutionQuest_MapScript_GraniteCave_4:
	end

MegaEvolutionQuest_MapScript_GraniteCave_2:
# 21 "data/scripts/mega_evolution_quests.pory"
	clearflag FLAG_HIDE_GRANITE_CAVE_STEVEN
	end

MegaEvolutionQuest_MapScript_GraniteCave_5:
# 27 "data/scripts/mega_evolution_quests.pory"
	clearflag FLAG_HIDE_GRANITE_CAVE_STEVEN
	goto MegaEvolutionQuest_MapScript_GraniteCave_4


MegaEvolutionQuest_EventScript_GraniteCaveSteven::
# 35 "data/scripts/mega_evolution_quests.pory"
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_MEGA_RING
# 36 "data/scripts/mega_evolution_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MegaEvolutionQuest_EventScript_GraniteCaveSteven_2
MegaEvolutionQuest_EventScript_GraniteCaveSteven_1:
# 40 "data/scripts/mega_evolution_quests.pory"
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_MEGA_RING
# 41 "data/scripts/mega_evolution_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MegaEvolutionQuest_EventScript_GraniteCaveSteven_5
# 49 "data/scripts/mega_evolution_quests.pory"
	goto GraniteCave_StevensRoom_EventScript_Steven
	return

MegaEvolutionQuest_EventScript_GraniteCaveSteven_2:
# 37 "data/scripts/mega_evolution_quests.pory"
	goto MegaEvolutionQuest_EventScript_StevenTest
	goto MegaEvolutionQuest_EventScript_GraniteCaveSteven_1

MegaEvolutionQuest_EventScript_GraniteCaveSteven_5:
# 42 "data/scripts/mega_evolution_quests.pory"
	lock
# 43 "data/scripts/mega_evolution_quests.pory"
	faceplayer
# 44 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_GraniteCaveSteven_Text_0
# 45 "data/scripts/mega_evolution_quests.pory"
	release
	end


MegaEvolutionQuest_EventScript_StevenTest::
# 53 "data/scripts/mega_evolution_quests.pory"
	lock
# 54 "data/scripts/mega_evolution_quests.pory"
	faceplayer
# 55 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_StevenTest_Text_0
# 56 "data/scripts/mega_evolution_quests.pory"
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
# 57 "data/scripts/mega_evolution_quests.pory"
	compare VAR_RESULT, FRIENDSHIP_200_TO_254
	goto_if_eq MegaEvolutionQuest_EventScript_StevenTest_2
MegaEvolutionQuest_EventScript_StevenTest_1:
# 60 "data/scripts/mega_evolution_quests.pory"
	compare VAR_RESULT, FRIENDSHIP_MAX
	goto_if_eq MegaEvolutionQuest_EventScript_StevenTest_5
MegaEvolutionQuest_EventScript_StevenTest_4:
# 64 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_StevenTest_Text_1
# 65 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_StevenTest_Text_2
# 66 "data/scripts/mega_evolution_quests.pory"
	release
	end

MegaEvolutionQuest_EventScript_StevenTest_2:
# 58 "data/scripts/mega_evolution_quests.pory"
	goto MegaEvolutionQuest_EventScript_StevenTestPassed
	goto MegaEvolutionQuest_EventScript_StevenTest_1

MegaEvolutionQuest_EventScript_StevenTest_5:
# 61 "data/scripts/mega_evolution_quests.pory"
	goto MegaEvolutionQuest_EventScript_StevenTestPassed
	goto MegaEvolutionQuest_EventScript_StevenTest_4


MegaEvolutionQuest_EventScript_StevenTestPassed::
# 71 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_StevenTestPassed_Text_0
# 72 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_StevenTestPassed_Text_1
	checkitem ITEM_MEGA_RING
# 0 "data/scripts/mega_evolution_quests.pory"
	compare VAR_RESULT, 0
	goto_if_eq MegaEvolutionQuest_EventScript_StevenTestPassed_2
MegaEvolutionQuest_EventScript_StevenTestPassed_1:
# 81 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_StevenTestPassed_Text_3
# 82 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_StevenTestPassed_Text_4
# 83 "data/scripts/mega_evolution_quests.pory"
	completequest QUEST_MEGA_RING
# 84 "data/scripts/mega_evolution_quests.pory"
	release
	end

MegaEvolutionQuest_EventScript_StevenTestPassed_2:
# 74 "data/scripts/mega_evolution_quests.pory"
	giveitem ITEM_MEGA_RING
# 75 "data/scripts/mega_evolution_quests.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MegaEvolutionQuest_EventScript_StevenTestPassed_4
	goto MegaEvolutionQuest_EventScript_StevenTestPassed_1

MegaEvolutionQuest_EventScript_StevenTestPassed_4:
# 76 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_StevenTestPassed_Text_2
# 77 "data/scripts/mega_evolution_quests.pory"
	release
	end


MegaEvolutionQuest_EventScript_EggExpert::
# 89 "data/scripts/mega_evolution_quests.pory"
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_MEGA_RING
# 90 "data/scripts/mega_evolution_quests.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MegaEvolutionQuest_EventScript_EggExpert_2
# 98 "data/scripts/mega_evolution_quests.pory"
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_MEGA_EGG
# 99 "data/scripts/mega_evolution_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq MegaEvolutionQuest_EventScript_EggExpert_5
# 107 "data/scripts/mega_evolution_quests.pory"
	lock
# 108 "data/scripts/mega_evolution_quests.pory"
	faceplayer
# 109 "data/scripts/mega_evolution_quests.pory"
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_MEGA_EGG
# 110 "data/scripts/mega_evolution_quests.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MegaEvolutionQuest_EventScript_EggExpert_8
MegaEvolutionQuest_EventScript_EggExpert_7:
# 118 "data/scripts/mega_evolution_quests.pory"
	switch VAR_MEGA_EGG_CHOICE
# 119 "data/scripts/mega_evolution_quests.pory"
	case 1, MegaEvolutionQuest_EventScript_EggExpert_12
# 121 "data/scripts/mega_evolution_quests.pory"
	case 2, MegaEvolutionQuest_EventScript_EggExpert_13
# 123 "data/scripts/mega_evolution_quests.pory"
	case 3, MegaEvolutionQuest_EventScript_EggExpert_14
MegaEvolutionQuest_EventScript_EggExpert_10:
# 127 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_EggExpert_Text_6
# 128 "data/scripts/mega_evolution_quests.pory"
	multichoice 17, 0, MULTI_MEGA_EGG_CHOICE, FALSE
# 129 "data/scripts/mega_evolution_quests.pory"
	switch VAR_RESULT
# 130 "data/scripts/mega_evolution_quests.pory"
	case 0, MegaEvolutionQuest_EventScript_EggExpert_17
# 132 "data/scripts/mega_evolution_quests.pory"
	case 1, MegaEvolutionQuest_EventScript_EggExpert_18
# 134 "data/scripts/mega_evolution_quests.pory"
	case 2, MegaEvolutionQuest_EventScript_EggExpert_19
MegaEvolutionQuest_EventScript_EggExpert_15:
# 138 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_EggExpert_Text_7
# 139 "data/scripts/mega_evolution_quests.pory"
	release
	end

MegaEvolutionQuest_EventScript_EggExpert_2:
# 91 "data/scripts/mega_evolution_quests.pory"
	lock
# 92 "data/scripts/mega_evolution_quests.pory"
	faceplayer
# 93 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_EggExpert_Text_0
# 94 "data/scripts/mega_evolution_quests.pory"
	release
	end

MegaEvolutionQuest_EventScript_EggExpert_5:
# 100 "data/scripts/mega_evolution_quests.pory"
	lock
# 101 "data/scripts/mega_evolution_quests.pory"
	faceplayer
# 102 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_EggExpert_Text_1
# 103 "data/scripts/mega_evolution_quests.pory"
	release
	end

MegaEvolutionQuest_EventScript_EggExpert_8:
# 111 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_EggExpert_Text_2
# 112 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_EggExpert_Text_3
# 113 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_EggExpert_Text_4
# 114 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_EggExpert_Text_5
# 115 "data/scripts/mega_evolution_quests.pory"
	startquest QUEST_MEGA_EGG
	goto MegaEvolutionQuest_EventScript_EggExpert_7

MegaEvolutionQuest_EventScript_EggExpert_12:
# 120 "data/scripts/mega_evolution_quests.pory"
	goto MegaEvolutionQuest_EventScript_GiveChespinEgg
	goto MegaEvolutionQuest_EventScript_EggExpert_10

MegaEvolutionQuest_EventScript_EggExpert_13:
# 122 "data/scripts/mega_evolution_quests.pory"
	goto MegaEvolutionQuest_EventScript_GiveFennekinEgg
	goto MegaEvolutionQuest_EventScript_EggExpert_10

MegaEvolutionQuest_EventScript_EggExpert_14:
# 124 "data/scripts/mega_evolution_quests.pory"
	goto MegaEvolutionQuest_EventScript_GiveFroakieEgg
	goto MegaEvolutionQuest_EventScript_EggExpert_10

MegaEvolutionQuest_EventScript_EggExpert_17:
# 131 "data/scripts/mega_evolution_quests.pory"
	goto MegaEvolutionQuest_EventScript_ChooseChespin
	goto MegaEvolutionQuest_EventScript_EggExpert_15

MegaEvolutionQuest_EventScript_EggExpert_18:
# 133 "data/scripts/mega_evolution_quests.pory"
	goto MegaEvolutionQuest_EventScript_ChooseFennekin
	goto MegaEvolutionQuest_EventScript_EggExpert_15

MegaEvolutionQuest_EventScript_EggExpert_19:
# 135 "data/scripts/mega_evolution_quests.pory"
	goto MegaEvolutionQuest_EventScript_ChooseFroakie
	goto MegaEvolutionQuest_EventScript_EggExpert_15


MegaEvolutionQuest_EventScript_ChooseChespin::
# 144 "data/scripts/mega_evolution_quests.pory"
	giveitem ITEM_CHESNAUGHTITE
# 145 "data/scripts/mega_evolution_quests.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MegaEvolutionQuest_EventScript_ChooseChespin_2
MegaEvolutionQuest_EventScript_ChooseChespin_1:
# 148 "data/scripts/mega_evolution_quests.pory"
	setvar VAR_MEGA_EGG_CHOICE, 1
# 149 "data/scripts/mega_evolution_quests.pory"
	goto MegaEvolutionQuest_EventScript_GiveChespinEgg
	return

MegaEvolutionQuest_EventScript_ChooseChespin_2:
# 146 "data/scripts/mega_evolution_quests.pory"
	goto MegaEvolutionQuest_EventScript_MegaStoneBagFull
	goto MegaEvolutionQuest_EventScript_ChooseChespin_1


MegaEvolutionQuest_EventScript_ChooseFennekin::
# 153 "data/scripts/mega_evolution_quests.pory"
	giveitem ITEM_DELPHOXITE
# 154 "data/scripts/mega_evolution_quests.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MegaEvolutionQuest_EventScript_ChooseFennekin_2
MegaEvolutionQuest_EventScript_ChooseFennekin_1:
# 157 "data/scripts/mega_evolution_quests.pory"
	setvar VAR_MEGA_EGG_CHOICE, 2
# 158 "data/scripts/mega_evolution_quests.pory"
	goto MegaEvolutionQuest_EventScript_GiveFennekinEgg
	return

MegaEvolutionQuest_EventScript_ChooseFennekin_2:
# 155 "data/scripts/mega_evolution_quests.pory"
	goto MegaEvolutionQuest_EventScript_MegaStoneBagFull
	goto MegaEvolutionQuest_EventScript_ChooseFennekin_1


MegaEvolutionQuest_EventScript_ChooseFroakie::
# 162 "data/scripts/mega_evolution_quests.pory"
	giveitem ITEM_GRENINJITE
# 163 "data/scripts/mega_evolution_quests.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq MegaEvolutionQuest_EventScript_ChooseFroakie_2
MegaEvolutionQuest_EventScript_ChooseFroakie_1:
# 166 "data/scripts/mega_evolution_quests.pory"
	setvar VAR_MEGA_EGG_CHOICE, 3
# 167 "data/scripts/mega_evolution_quests.pory"
	goto MegaEvolutionQuest_EventScript_GiveFroakieEgg
	return

MegaEvolutionQuest_EventScript_ChooseFroakie_2:
# 164 "data/scripts/mega_evolution_quests.pory"
	goto MegaEvolutionQuest_EventScript_MegaStoneBagFull
	goto MegaEvolutionQuest_EventScript_ChooseFroakie_1


MegaEvolutionQuest_EventScript_GiveChespinEgg::
# 171 "data/scripts/mega_evolution_quests.pory"
	setvar VAR_GIFT_EGG_SPECIES, SPECIES_CHESPIN
# 172 "data/scripts/mega_evolution_quests.pory"
	goto MegaEvolutionQuest_EventScript_GiveChosenEgg
	return


MegaEvolutionQuest_EventScript_GiveFennekinEgg::
# 176 "data/scripts/mega_evolution_quests.pory"
	setvar VAR_GIFT_EGG_SPECIES, SPECIES_FENNEKIN
# 177 "data/scripts/mega_evolution_quests.pory"
	goto MegaEvolutionQuest_EventScript_GiveChosenEgg
	return


MegaEvolutionQuest_EventScript_GiveFroakieEgg::
# 181 "data/scripts/mega_evolution_quests.pory"
	setvar VAR_GIFT_EGG_SPECIES, SPECIES_FROAKIE
# 182 "data/scripts/mega_evolution_quests.pory"
	goto MegaEvolutionQuest_EventScript_GiveChosenEgg
	return


MegaEvolutionQuest_EventScript_GiveChosenEgg::
# 186 "data/scripts/mega_evolution_quests.pory"
	setvar VAR_GIFT_EGG_SHINY, TRUE
# 187 "data/scripts/mega_evolution_quests.pory"
	setvar VAR_GIFT_EGG_MOVE1, MOVE_NONE
# 188 "data/scripts/mega_evolution_quests.pory"
	setvar VAR_GIFT_EGG_MOVE2, MOVE_NONE
# 189 "data/scripts/mega_evolution_quests.pory"
	setvar VAR_GIFT_EGG_MOVE3, MOVE_NONE
# 190 "data/scripts/mega_evolution_quests.pory"
	setvar VAR_GIFT_EGG_MOVE4, MOVE_NONE
# 191 "data/scripts/mega_evolution_quests.pory"
	special GiveCustomEgg
# 192 "data/scripts/mega_evolution_quests.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_eq MegaEvolutionQuest_EventScript_GiveChosenEgg_2
# 198 "data/scripts/mega_evolution_quests.pory"
	playfanfare MUS_OBTAIN_ITEM
# 199 "data/scripts/mega_evolution_quests.pory"
	waitfanfare
# 200 "data/scripts/mega_evolution_quests.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq MegaEvolutionQuest_EventScript_GiveChosenEgg_5
# 203 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_GiveChosenEgg_Text_2
MegaEvolutionQuest_EventScript_GiveChosenEgg_4:
# 205 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_GiveChosenEgg_Text_3
# 206 "data/scripts/mega_evolution_quests.pory"
	completequest QUEST_MEGA_EGG
# 207 "data/scripts/mega_evolution_quests.pory"
	release
	end

MegaEvolutionQuest_EventScript_GiveChosenEgg_2:
# 193 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_GiveChosenEgg_Text_0
# 194 "data/scripts/mega_evolution_quests.pory"
	release
	end

MegaEvolutionQuest_EventScript_GiveChosenEgg_5:
# 201 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_GiveChosenEgg_Text_1
	goto MegaEvolutionQuest_EventScript_GiveChosenEgg_4


MegaEvolutionQuest_EventScript_MegaStoneBagFull::
# 212 "data/scripts/mega_evolution_quests.pory"
	msgbox MegaEvolutionQuest_EventScript_MegaStoneBagFull_Text_0
# 213 "data/scripts/mega_evolution_quests.pory"
	release
	end


MegaEvolutionQuest_EventScript_StevenIntro_Text_0:
# 8 "data/scripts/mega_evolution_quests.pory"
	.string "Before I go, may I ask you one more\n"
	.string "question?\p"
	.string "Have you ever heard of Mega Evolution?$"

MegaEvolutionQuest_EventScript_StevenIntro_Text_1:
# 9 "data/scripts/mega_evolution_quests.pory"
	.string "In Kalos, that name describes a\n"
	.string "transformation beyond ordinary\l"
	.string "Evolution. It temporarily reveals power\l"
	.string "hidden within certain Pokémon.$"

MegaEvolutionQuest_EventScript_StevenIntro_Text_2:
# 10 "data/scripts/mega_evolution_quests.pory"
	.string "A Key Stone carried by a Trainer must\n"
	.string "resonate with the matching Mega Stone\l"
	.string "held by the Pokémon.\p"
	.string "The stones are only a bridge. A strong\n"
	.string "bond is what lets them answer each\l"
	.string "other.$"

MegaEvolutionQuest_EventScript_StevenIntro_Text_3:
# 11 "data/scripts/mega_evolution_quests.pory"
	.string "I get the feeling you may be worthy of\n"
	.string "carrying a Mega Ring.\p"
	.string "A feeling is not proof, though, and raw\n"
	.string "strength would prove the wrong thing.$"

MegaEvolutionQuest_EventScript_StevenIntro_Text_4:
# 12 "data/scripts/mega_evolution_quests.pory"
	.string "Show me a Pokémon that chooses to\n"
	.string "trust you. Put a deeply trusted partner\l"
	.string "at the head of your party, then meet me\l"
	.string "in the chamber where we first met.$"

MegaEvolutionQuest_EventScript_StevenIntro_Text_5:
# 15 "data/scripts/mega_evolution_quests.pory"
	.string "There is no deadline. A true bond is\n"
	.string "worth recognizing, not rushing.$"

MegaEvolutionQuest_EventScript_GraniteCaveSteven_Text_0:
# 44 "data/scripts/mega_evolution_quests.pory"
	.string "That Mega Ring suits you. Remember: the\n"
	.string "stone does not command your partner.\l"
	.string "It lets your bond be heard.$"

MegaEvolutionQuest_EventScript_StevenTest_Text_0:
# 55 "data/scripts/mega_evolution_quests.pory"
	.string "You returned... and you brought a\n"
	.string "partner whose answer matters more than\l"
	.string "yours. Let me see.$"

MegaEvolutionQuest_EventScript_StevenTest_Text_1:
# 64 "data/scripts/mega_evolution_quests.pory"
	.string "There is trust here, but the resonance\n"
	.string "is still faint. Travel together. Battle\l"
	.string "together. Care for this Pokémon when\l"
	.string "there is nothing to gain.$"

MegaEvolutionQuest_EventScript_StevenTest_Text_2:
# 65 "data/scripts/mega_evolution_quests.pory"
	.string "When it is truly happy simply to stand\n"
	.string "beside you, bring it back at the head of\l"
	.string "your party.$"

MegaEvolutionQuest_EventScript_StevenTestPassed_Text_0:
# 71 "data/scripts/mega_evolution_quests.pory"
	.string "There it is. Not obedience--choice.\n"
	.string "Your Pokémon watches you because it\l"
	.string "wants to know what the two of you will\l"
	.string "do together.$"

MegaEvolutionQuest_EventScript_StevenTestPassed_Text_1:
# 72 "data/scripts/mega_evolution_quests.pory"
	.string "That is the bond Mega Evolution asks\n"
	.string "for. I would be proud to entrust this to\l"
	.string "you.$"

MegaEvolutionQuest_EventScript_StevenTestPassed_Text_2:
# 76 "data/scripts/mega_evolution_quests.pory"
	.string "Your Bag is full. Make room for the Mega\n"
	.string "Ring, then speak with me again. Your\l"
	.string "proof will not expire.$"

MegaEvolutionQuest_EventScript_StevenTestPassed_Text_3:
# 81 "data/scripts/mega_evolution_quests.pory"
	.string "A Key Stone is set into that ring. Give a\n"
	.string "compatible partner its Mega Stone, then\l"
	.string "press START before choosing its move in\l"
	.string "battle.$"

MegaEvolutionQuest_EventScript_StevenTestPassed_Text_4:
# 82 "data/scripts/mega_evolution_quests.pory"
	.string "Mega Evolution is temporary. The\n"
	.string "responsibility behind it is not.$"

MegaEvolutionQuest_EventScript_EggExpert_Text_0:
# 93 "data/scripts/mega_evolution_quests.pory"
	.string "Verdanturf's gentle air is perfect for\n"
	.string "studying friendship. Some discoveries\l"
	.string "need quieter instruments than a\l"
	.string "laboratory.$"

MegaEvolutionQuest_EventScript_EggExpert_Text_1:
# 102 "data/scripts/mega_evolution_quests.pory"
	.string "Raise that little one patiently. A Mega\n"
	.string "Stone may open the door, but only your\l"
	.string "shared journey can decide what passes\l"
	.string "through it.$"

MegaEvolutionQuest_EventScript_EggExpert_Text_2:
# 111 "data/scripts/mega_evolution_quests.pory"
	.string "That Mega Ring... Steven found the\n"
	.string "Trainer he was looking for after all.$"

MegaEvolutionQuest_EventScript_EggExpert_Text_3:
# 112 "data/scripts/mega_evolution_quests.pory"
	.string "I once assisted Professor Sycamore in\n"
	.string "Kalos. He studies Mega Evolution, but\l"
	.string "his finest lesson began with a choice\l"
	.string "of partners, not a lecture.$"

MegaEvolutionQuest_EventScript_EggExpert_Text_4:
# 113 "data/scripts/mega_evolution_quests.pory"
	.string "Chespin, Fennekin, and Froakie can each\n"
	.string "grow into a Pokémon capable of Mega\l"
	.string "Evolution. I brought one Egg from each\l"
	.string "species to Hoenn.$"

MegaEvolutionQuest_EventScript_EggExpert_Text_5:
# 114 "data/scripts/mega_evolution_quests.pory"
	.string "Their rare coloration will make them\n"
	.string "shine when they hatch, but color is not\l"
	.string "what awakens their hidden power. The\l"
	.string "bond comes first.$"

MegaEvolutionQuest_EventScript_EggExpert_Text_6:
# 127 "data/scripts/mega_evolution_quests.pory"
	.string "Chespin becomes the stalwart Mega\n"
	.string "Chesnaught; Fennekin, the clever Mega\l"
	.string "Delphox; and Froakie, the swift Mega\l"
	.string "Greninja.\p"
	.string "Each Egg comes with its matching Mega\n"
	.string "Stone. Which partner calls to you?$"

MegaEvolutionQuest_EventScript_EggExpert_Text_7:
# 138 "data/scripts/mega_evolution_quests.pory"
	.string "A lifelong partnership deserves a\n"
	.string "considered answer. Return whenever you\l"
	.string "are ready to choose.$"

MegaEvolutionQuest_EventScript_GiveChosenEgg_Text_0:
# 193 "data/scripts/mega_evolution_quests.pory"
	.string "Your party and every PC Box are full. I\n"
	.string "will keep the Egg safe; make room, then\l"
	.string "return.$"

MegaEvolutionQuest_EventScript_GiveChosenEgg_Text_1:
# 201 "data/scripts/mega_evolution_quests.pory"
	.string "Your party was full, so the shining Egg\n"
	.string "was sent to a Box in your PC.$"

MegaEvolutionQuest_EventScript_GiveChosenEgg_Text_2:
# 203 "data/scripts/mega_evolution_quests.pory"
	.string "{PLAYER} received the shining Egg!$"

MegaEvolutionQuest_EventScript_GiveChosenEgg_Text_3:
# 205 "data/scripts/mega_evolution_quests.pory"
	.string "The matching Mega Stone is yours as\n"
	.string "well. Raise your new partner with\l"
	.string "patience, and let the ring answer when\l"
	.string "both of you are ready.$"

MegaEvolutionQuest_EventScript_MegaStoneBagFull_Text_0:
# 212 "data/scripts/mega_evolution_quests.pory"
	.string "Your Bag has no room for the Mega\n"
	.string "Stone. Make space, then return; I will\l"
	.string "keep all three Eggs safe.$"
