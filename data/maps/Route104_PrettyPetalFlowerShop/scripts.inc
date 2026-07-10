# 1 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_MapScripts::
# 2 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_PrettyPetalFlowerShop_OnTransition
# 3 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.byte 0
# 4 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 5 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_OnTransition:
# 6 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	setflag FLAG_LANDMARK_FLOWER_SHOP
# 7 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_unset FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_PrettyPetalFlowerShop_EventScript_MoveShopOwner
# 8 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_unset FLAG_BADGE03_GET, Route104_PrettyPetalFlowerShop_EventScript_MoveShopOwner
# 9 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	setflag FLAG_TEMP_1
# 10 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 11 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 12 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_MoveShopOwner::
# 13 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	setobjectxyperm LOCALID_FLOWER_SHOP_OWNER, 4, 6
# 14 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 15 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 16 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_ShopOwner::
# 17 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	lock
# 18 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	faceplayer
# 19 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_set FLAG_TEMP_1, Route104_PrettyPetalFlowerShop_EventScript_SellDecorations
# 20 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_ThisIsPrettyPetalFlowerShop, MSGBOX_DEFAULT
# 21 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_set FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_PrettyPetalFlowerShop_EventScript_AlreadyMet
# 22 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	setflag FLAG_MET_PRETTY_PETAL_SHOP_OWNER
# 23 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_IntroLearnAboutBerries, MSGBOX_YESNO
# 24 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	call_if_eq VAR_RESULT, YES, Route104_PrettyPetalFlowerShop_EventScript_ExplainBerries
# 25 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	call_if_eq VAR_RESULT, NO, Route104_PrettyPetalFlowerShop_EventScript_DontExplainBerries
# 26 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 27 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 28 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 29 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_AlreadyMet::
# 30 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_LearnAboutBerries, MSGBOX_YESNO
# 31 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	call_if_eq VAR_RESULT, YES, Route104_PrettyPetalFlowerShop_EventScript_ExplainBerries
# 32 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	call_if_eq VAR_RESULT, NO, Route104_PrettyPetalFlowerShop_EventScript_DontExplainBerries
# 33 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 34 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 35 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 36 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_ExplainBerries::
# 37 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_BerriesExplanation, MSGBOX_DEFAULT
# 38 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	return
# 39 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 40 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_DontExplainBerries::
# 41 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_FlowersBringHappiness, MSGBOX_DEFAULT
# 42 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	return
# 43 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 44 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_SellDecorations::
# 45 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	message gText_PlayerWhatCanIDoForYou
# 46 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	waitmessage
# 47 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	pokemartdecoration2 Route104_PrettyPetalFlowerShop_Pokemart_Plants
# 48 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 49 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 50 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 51 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 52 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.align 2
# 53 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_Pokemart_Plants:
# 54 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.2byte DECOR_RED_PLANT
# 55 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.2byte DECOR_TROPICAL_PLANT
# 56 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.2byte DECOR_PRETTY_FLOWERS
# 57 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.2byte DECOR_COLORFUL_PLANT
# 58 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.2byte DECOR_BIG_PLANT
# 59 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.2byte DECOR_GORGEOUS_PLANT
# 60 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	pokemartlistend
# 61 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 62 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_WailmerPailGirl::
# 63 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	lock
# 64 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	faceplayer
# 65 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_unset FLAG_RECEIVED_WAILMER_PAIL, Route104_PrettyPetalFlowerShop_EventScript_GiveWailmerPail
# 66 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_WailmerPailExplanation, MSGBOX_DEFAULT
# 67 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 68 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 69 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 70 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_GiveWailmerPail::
# 71 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_YouCanHaveThis, MSGBOX_DEFAULT
# 72 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	giveitem ITEM_WAILMER_PAIL
# 73 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 74 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_WailmerPailExplanation, MSGBOX_DEFAULT
# 75 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	setflag FLAG_RECEIVED_WAILMER_PAIL
# 76 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 77 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 78 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 79 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_RandomBerryGirl::
# 80 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	lock
# 81 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	faceplayer
# 82 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	dotimebasedevents
# 83 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_set FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY, Route104_PrettyPetalFlowerShop_EventScript_AlreadyReceivedBerry
# 84 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_ImGrowingFlowers, MSGBOX_DEFAULT
# 85 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	giverandomberry BERRY_ID_CHERI, BERRY_ID_PERSIM
# 86 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
# 87 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	setflag FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY
# 88 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_MachineMixesBerries, MSGBOX_DEFAULT
# 89 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 90 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end
# 91 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"

# 92 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
Route104_PrettyPetalFlowerShop_EventScript_AlreadyReceivedBerry::
# 93 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox Route104_PrettyPetalFlowerShop_Text_MachineMixesBerries, MSGBOX_DEFAULT
# 94 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	release
# 95 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	end

SHAYMIN_quest_starter::
# 99 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	lockall
# 100 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	faceplayer
# 101 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	goto_if_set FLAG_GRACIDEA_GIFT, SHAYMIN_quest_starter_2
# 106 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox SHAYMIN_quest_starter_Text_1, MSGBOX_YESNO
# 109 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	switch VAR_RESULT
# 110 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	case YES, SHAYMIN_quest_starter_6
# 116 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	case NO, SHAYMIN_quest_starter_7
SHAYMIN_quest_starter_4:
# 119 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	releaseall
	end

SHAYMIN_quest_starter_2:
# 102 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox SHAYMIN_quest_starter_Text_0
# 103 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	releaseall
	end

SHAYMIN_quest_starter_6:
# 111 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	playse SE_PIN
# 112 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	setflag FLAG_GRACIDEA_GIFT
# 113 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	giveitem ITEM_GRACIDEA
# 114 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox SHAYMIN_quest_starter_Text_2
	goto SHAYMIN_quest_starter_4

SHAYMIN_quest_starter_7:
# 117 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	msgbox SHAYMIN_quest_starter_Text_3
	goto SHAYMIN_quest_starter_4


SHAYMIN_quest_starter_Text_0:
# 102 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.string "Carry that Gracidea somewhere the air\n"
	.string "is clean and the flowers are thick.\l"
	.string "Kindness given comes back in bloom --\l"
	.string "you'll see.$"

SHAYMIN_quest_starter_Text_1:
# 106 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.string "I've grown this Gracidea for years,\n"
	.string "waiting for the right traveler.\p"
	.string "In full flower, a Gracidea does\n"
	.string "something wonderful, it lets rare shy\l"
	.string "little Pokémon bloom.\p"
	.string "Take it. Find a sailor to take you to a\n"
	.string "place where the air is clean and the\l"
	.string "flowers grow thick, and offer it with a\l"
	.string "grateful heart. Will you?$"

SHAYMIN_quest_starter_Text_2:
# 114 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.string "There. Keep it in bloom, and keep your\n"
	.string "heart the same.\p"
	.string "Gratitude is the only thing that ever\n"
	.string "coaxes it out. Go gently.$"

SHAYMIN_quest_starter_Text_3:
# 117 "data/maps/Route104_PrettyPetalFlowerShop/scripts.pory"
	.string "The flowers will keep. And so will the\n"
	.string "little one hiding in them.$"
