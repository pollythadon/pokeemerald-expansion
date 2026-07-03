# 1 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_MapScripts::
# 2 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.byte 0
# 3 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 4 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_ClerkLeft::
# 5 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	lock
# 6 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	faceplayer
# 7 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	message gText_HowMayIServeYou
# 8 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	waitmessage
# 9 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_Vitamins
# 10 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 11 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	release
# 12 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 13 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 14 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.align 2
# 15 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Pokemart_Vitamins:
# 16 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_PROTEIN
# 17 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_CALCIUM
# 18 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_IRON
# 19 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_ZINC
# 20 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_CARBOS
# 21 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_HP_UP
# 22 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	pokemartlistend
# 23 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 24 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_ClerkRight::
# 25 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	lock
# 26 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	faceplayer
# 27 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	message gText_HowMayIServeYou
# 28 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	waitmessage
# 29 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_StatBoosters
# 30 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 31 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	release
# 32 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 33 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 34 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.align 2
# 35 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Pokemart_StatBoosters:
# 36 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_X_SPEED
# 37 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_X_SP_ATK
# 38 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_X_ATTACK
# 39 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_X_DEFENSE
# 40 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_DIRE_HIT
# 41 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_GUARD_SPEC
# 42 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_X_ACCURACY
# 43 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	pokemartlistend
# 44 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 45 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_TriathleteM::
# 46 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_3F_Text_ItemsBestForTougheningPokemon, MSGBOX_NPC
# 47 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 48 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 49 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_PokefanM::
# 50 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_3F_Text_WantMoreEndurance, MSGBOX_NPC
# 51 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 52 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 53 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_EventScript_Woman::
# 54 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_3F_Text_GaveCarbosToSpeedUpMon, MSGBOX_NPC
# 55 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	end
# 56 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 57 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Text_ItemsBestForTougheningPokemon:
# 58 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "For quickly toughening up POKéMON,\n"
# 59 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "items are the best.\p"
# 60 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "PROTEIN boosts ATTACK,\n"
# 61 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "and CALCIUM raises SP. ATK.$"
# 62 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 63 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Text_WantMoreEndurance:
# 64 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "I want my POKéMON to have more\n"
# 65 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "endurance.\p"
# 66 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "I'm trying to decide whether to raise\n"
# 67 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "DEFENSE with IRON, or SP. DEF with ZINC.$"
# 68 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"

# 69 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
LilycoveCity_DepartmentStore_3F_Text_GaveCarbosToSpeedUpMon:
# 70 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "I gave a CARBOS to my POKéMON,\n"
# 71 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "and its SPEED went up.$"

MintApothecary_Clerk::
# 84 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	lock
# 85 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	faceplayer
# 86 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	message MintApothecary_Clerk_Text_0
# 87 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	waitmessage
# 88 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	pokemart MintApothecary_Items
# 89 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	msgbox MintApothecary_Clerk_Text_1
# 90 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	release
	end


	.align 2
# 94 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
MintApothecary_Items:
# 96 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_LONELY_MINT
# 97 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_BRAVE_MINT
# 98 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_ADAMANT_MINT
# 99 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_NAUGHTY_MINT
# 101 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_BOLD_MINT
# 102 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_RELAXED_MINT
# 103 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_IMPISH_MINT
# 104 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_LAX_MINT
# 106 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_MODEST_MINT
# 107 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_MILD_MINT
# 108 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_QUIET_MINT
# 109 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_RASH_MINT
# 111 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_CALM_MINT
# 112 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_GENTLE_MINT
# 113 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_SASSY_MINT
# 114 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_CAREFUL_MINT
# 116 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_TIMID_MINT
# 117 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_HASTY_MINT
# 118 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_JOLLY_MINT
# 119 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_NAIVE_MINT
# 121 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.2byte ITEM_SERIOUS_MINT
	.2byte ITEM_NONE

MintApothecary_Clerk_Text_0:
# 86 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "Step right up! A pinch of the right Mint,\n"
	.string "and your partner's potential blooms\l"
	.string "anew.$"

MintApothecary_Clerk_Text_1:
# 89 "data/maps/LilycoveCity_DepartmentStore_3F/scripts.pory"
	.string "Mind the dosage. One Mint changes\n"
	.string "everything.$"
