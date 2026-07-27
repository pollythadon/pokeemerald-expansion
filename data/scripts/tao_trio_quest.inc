TaoTrio_EventScript_DnaGiver::
# 8 "data/scripts/tao_trio_quest.pory"
	lock
# 9 "data/scripts/tao_trio_quest.pory"
	faceplayer
# 10 "data/scripts/tao_trio_quest.pory"
	goto_if_set FLAG_DNA_SPLICERS_RECEIVED, TaoTrio_EventScript_DnaGiver_2
# 15 "data/scripts/tao_trio_quest.pory"
	msgbox TaoTrio_EventScript_DnaGiver_Text_1
# 16 "data/scripts/tao_trio_quest.pory"
	msgbox TaoTrio_EventScript_DnaGiver_Text_2
# 17 "data/scripts/tao_trio_quest.pory"
	giveitem ITEM_DNA_SPLICERS
# 18 "data/scripts/tao_trio_quest.pory"
	setflag FLAG_DNA_SPLICERS_RECEIVED
# 19 "data/scripts/tao_trio_quest.pory"
	startquest QUEST_ZEKROM
# 20 "data/scripts/tao_trio_quest.pory"
	startquest QUEST_RESHIRAM
# 21 "data/scripts/tao_trio_quest.pory"
	msgbox TaoTrio_EventScript_DnaGiver_Text_3
# 22 "data/scripts/tao_trio_quest.pory"
	release
	end

TaoTrio_EventScript_DnaGiver_2:
# 11 "data/scripts/tao_trio_quest.pory"
	msgbox TaoTrio_EventScript_DnaGiver_Text_0
# 12 "data/scripts/tao_trio_quest.pory"
	release
	end


TaoTrio_EventScript_TryUnlockKyurem::
# 30 "data/scripts/tao_trio_quest.pory"
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ZEKROM
# 31 "data/scripts/tao_trio_quest.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq TaoTrio_EventScript_TryUnlockKyurem_2
# 34 "data/scripts/tao_trio_quest.pory"
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_RESHIRAM
# 35 "data/scripts/tao_trio_quest.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq TaoTrio_EventScript_TryUnlockKyurem_5
# 38 "data/scripts/tao_trio_quest.pory"
	clearflag FLAG_HIDE_KYUREM
# 39 "data/scripts/tao_trio_quest.pory"
	startquest QUEST_KYUREM
# 40 "data/scripts/tao_trio_quest.pory"
	msgbox TaoTrio_EventScript_TryUnlockKyurem_Text_0
	return

TaoTrio_EventScript_TryUnlockKyurem_2:
	return

TaoTrio_EventScript_TryUnlockKyurem_5:
	return


TaoTrio_EventScript_DnaGiver_Text_0:
# 11 "data/scripts/tao_trio_quest.pory"
	.string "The two dragons still slumber out there.\p"
	.string "Let the DNA Splicers draw them into the\n"
	.string "light -- one at Rusturf Tunnel, one at\l"
	.string "Mt. Chimney.$"

TaoTrio_EventScript_DnaGiver_Text_1:
# 15 "data/scripts/tao_trio_quest.pory"
	.string "Hoenn is alot hotter than Unova!I have\n"
	.string "chased an old legend across the seas...\l"
	.string "two dragons born when one great dragon\l"
	.string "was split in two.$"

TaoTrio_EventScript_DnaGiver_Text_2:
# 16 "data/scripts/tao_trio_quest.pory"
	.string "This is the DNA Splicers. Its power\n"
	.string "resonates with those dragons and will\l"
	.string "lure them out of hiding. Take it.$"

TaoTrio_EventScript_DnaGiver_Text_3:
# 21 "data/scripts/tao_trio_quest.pory"
	.string "One sleeps where the stone is split at\n"
	.string "Rusturf Tunnel; the other where the\l"
	.string "mountain burns at Mt. Chimney.\p"
	.string "Go! and make the legend whole!$"

TaoTrio_EventScript_TryUnlockKyurem_Text_0:
# 40 "data/scripts/tao_trio_quest.pory"
	.string "The DNA Splicers pulse violently!\p"
	.string "With both dragons at your side, a vast,\n"
	.string "frozen presence has stirred deep\l"
	.string "within Shoal Cave...$"
