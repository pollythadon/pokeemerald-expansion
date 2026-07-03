# 1 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_MapScripts::
# 2 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.byte 0
# 3 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 4 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_EventScript_Cook::
# 5 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_2F_Text_LearnToUseItemsProperly, MSGBOX_NPC
# 6 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	end
# 7 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 8 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_EventScript_PokefanF::
# 9 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_2F_Text_GoodGiftForHusband, MSGBOX_NPC
# 10 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	end
# 11 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 12 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_EventScript_Sailor::
# 13 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	msgbox LilycoveCity_DepartmentStore_2F_Text_StockUpOnItems, MSGBOX_NPC
# 14 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	end
# 15 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 16 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_EventScript_ClerkLeft::
# 17 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	lock
# 18 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	faceplayer
# 19 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	message gText_HowMayIServeYou
# 20 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	waitmessage
# 21 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	pokemart LilycoveCity_DepartmentStore_2F_Pokemart1
# 22 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 23 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	release
# 24 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	end
# 25 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 26 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.align 2
# 27 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_Pokemart1:
# 28 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_POKE_BALL
# 29 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_GREAT_BALL
# 30 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ULTRA_BALL
# 31 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ESCAPE_ROPE
# 32 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_FULL_HEAL
# 33 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ANTIDOTE
# 34 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_PARALYZE_HEAL
# 35 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_BURN_HEAL
# 36 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ICE_HEAL
# 37 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_AWAKENING
# 38 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_FLUFFY_TAIL
# 39 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	pokemartlistend
# 40 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 41 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_EventScript_ClerkRight::
# 42 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	lock
# 43 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	faceplayer
# 44 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	message gText_HowMayIServeYou
# 45 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	waitmessage
# 46 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	pokemart LilycoveCity_DepartmentStore_2F_Pokemart2
# 47 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
# 48 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	release
# 49 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	end
# 50 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 51 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.align 2
# 52 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_Pokemart2:
# 53 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_POTION
# 54 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SUPER_POTION
# 55 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_HYPER_POTION
# 56 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_MAX_POTION
# 57 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_REVIVE
# 58 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_REPEL
# 59 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SUPER_REPEL
# 60 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_MAX_REPEL
# 61 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_WAVE_MAIL
# 62 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_MECH_MAIL
# 63 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	pokemartlistend
# 64 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 65 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_Text_LearnToUseItemsProperly:
# 66 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.string "Learn to use items properly.\n"
# 67 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.string "That's basic, really.$"
# 68 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 69 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_Text_GoodGiftForHusband:
# 70 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.string "My husband is waiting at home.\n"
# 71 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.string "What would make a good gift for him?$"
# 72 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"

# 73 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
LilycoveCity_DepartmentStore_2F_Text_StockUpOnItems:
# 74 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.string "I'm leaving on a long journey soon.\n"
# 75 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.string "I need to stock up on items.$"

PokeBallEmporium_Clerk::
# 89 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	lock
# 90 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	faceplayer
# 91 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	message PokeBallEmporium_Clerk_Text_0
# 92 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	waitmessage
# 93 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	pokemart PokeBallEmporium
# 94 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	msgbox PokeBallEmporium_Clerk_Text_1
# 95 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	release
	end


	.align 2
# 99 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
PokeBallEmporium:
# 101 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_NET_BALL
# 102 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_NEST_BALL
# 103 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_DIVE_BALL
# 104 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_REPEAT_BALL
# 105 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_TIMER_BALL
# 106 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_DUSK_BALL
# 107 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_QUICK_BALL
# 108 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_HEAL_BALL
# 109 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_LUXURY_BALL
# 110 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_PREMIER_BALL
# 112 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_FAST_BALL
# 113 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_FRIEND_BALL
# 114 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_HEAVY_BALL
# 115 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_LEVEL_BALL
# 116 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_LOVE_BALL
# 117 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_LURE_BALL
# 118 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_MOON_BALL
# 119 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SPORT_BALL
# 121 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SAFARI_BALL
# 122 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_PARK_BALL
# 123 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_CHERISH_BALL
# 124 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_DREAM_BALL
# 125 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_BEAST_BALL
# 126 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_MASTER_BALL
	.2byte ITEM_NONE

EvolutionStones_Clerk::
# 144 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	lock
# 145 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	faceplayer
# 146 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	message EvolutionStones_Clerk_Text_0
# 147 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	waitmessage
# 148 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	pokemart EvolutionStones_Items
# 149 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	msgbox EvolutionStones_Clerk_Text_1
# 150 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	release
	end


	.align 2
# 154 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
EvolutionStones_Items:
# 155 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_FIRE_STONE
# 156 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_WATER_STONE
# 157 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_THUNDER_STONE
# 158 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_LEAF_STONE
# 159 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_MOON_STONE
# 160 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SUN_STONE
# 161 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SHINY_STONE
# 162 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_DUSK_STONE
# 163 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_DAWN_STONE
# 164 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ICE_STONE
# 165 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_OVAL_STONE
# 166 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_EVERSTONE
	.2byte ITEM_NONE

EvolutionGear_Clerk::
# 174 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	lock
# 175 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	faceplayer
# 176 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	message EvolutionGear_Clerk_Text_0
# 177 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	waitmessage
# 178 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	pokemart EvolutionGear_Items
# 179 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	msgbox EvolutionGear_Clerk_Text_1
# 180 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	release
	end


	.align 2
# 184 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
EvolutionGear_Items:
# 186 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_LINKING_CORD
# 187 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_KINGS_ROCK
# 188 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_METAL_COAT
# 189 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_DRAGON_SCALE
# 190 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_UP_GRADE
# 191 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_DUBIOUS_DISC
# 192 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_PROTECTOR
# 193 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_ELECTIRIZER
# 194 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_MAGMARIZER
# 195 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_REAPER_CLOTH
# 196 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_PRISM_SCALE
# 197 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_DEEP_SEA_TOOTH
# 198 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_DEEP_SEA_SCALE
# 200 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_RAZOR_CLAW
# 201 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_RAZOR_FANG
# 202 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_WHIPPED_DREAM
# 203 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SACHET
# 205 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_GALARICA_CUFF
# 206 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_GALARICA_WREATH
# 207 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_BLACK_AUGURITE
# 208 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_PEAT_BLOCK
# 209 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SWEET_APPLE
# 210 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_TART_APPLE
# 211 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SYRUPY_APPLE
# 212 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_CRACKED_POT
# 213 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_CHIPPED_POT
# 214 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_AUSPICIOUS_ARMOR
# 215 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_MALICIOUS_ARMOR
# 216 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_GIMMIGHOUL_COIN
# 217 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_LEADERS_CREST
# 218 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SCROLL_OF_DARKNESS
# 219 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_SCROLL_OF_WATERS
# 220 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_MASTERPIECE_TEACUP
# 221 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_UNREMARKABLE_TEACUP
# 222 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.2byte ITEM_METAL_ALLOY
	.2byte ITEM_NONE

PokeBallEmporium_Clerk_Text_0:
# 91 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.string "Welcome to the Poke Ball Emporium! If it\n"
	.string "catches Pokemon, we've got it.$"

PokeBallEmporium_Clerk_Text_1:
# 94 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.string "May your throws always find their mark!$"

EvolutionStones_Clerk_Text_0:
# 146 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.string "Fresh-cut stones, each humming with\n"
	.string "the power to change a Pokemon's form.$"

EvolutionStones_Clerk_Text_1:
# 149 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.string "Choose carefully, a stone's gift is\n"
	.string "forever.$"

EvolutionGear_Clerk_Text_0:
# 176 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.string "Trinkets, scrolls, and oddities -- the\n"
	.string "little nudges some Pokemon need to\l"
	.string "grow.$"

EvolutionGear_Clerk_Text_1:
# 179 "data/maps/LilycoveCity_DepartmentStore_2F/scripts.pory"
	.string "Change is a beautiful thing. Come again!$"
