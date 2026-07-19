CharacterQuest_EventScript_Wally::
# 6 "data/scripts/character_quests.pory"
	goto_if_set FLAG_LEGENDARY_BTL, CharacterQuest_EventScript_Wally_2
CharacterQuest_EventScript_Wally_1:
# 9 "data/scripts/character_quests.pory"
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_WALLY
# 10 "data/scripts/character_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CharacterQuest_EventScript_Wally_5
CharacterQuest_EventScript_Wally_4:
# 13 "data/scripts/character_quests.pory"
	lock
# 14 "data/scripts/character_quests.pory"
	faceplayer
# 15 "data/scripts/character_quests.pory"
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_WALLY
# 16 "data/scripts/character_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CharacterQuest_EventScript_Wally_8
# 21 "data/scripts/character_quests.pory"
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_WALLY
# 22 "data/scripts/character_quests.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CharacterQuest_EventScript_Wally_11
	checkpartymon SPECIES_RALTS
# 0 "data/scripts/character_quests.pory"
	compare VAR_RESULT, 0
	goto_if_eq CharacterQuest_EventScript_Wally_14
# 36 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Wally_Text_6
# 37 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Wally_Text_7
# 38 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Wally_Text_8
# 39 "data/scripts/character_quests.pory"
	completequest QUEST_WALLY
# 40 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Wally_2:
# 7 "data/scripts/character_quests.pory"
	goto VerdanturfTown_WandasHouse_EventScript_Wally
	goto CharacterQuest_EventScript_Wally_1

CharacterQuest_EventScript_Wally_5:
# 11 "data/scripts/character_quests.pory"
	goto VerdanturfTown_WandasHouse_EventScript_Wally
	goto CharacterQuest_EventScript_Wally_4

CharacterQuest_EventScript_Wally_8:
# 17 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Wally_Text_0
# 18 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Wally_11:
# 23 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Wally_Text_1
# 24 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Wally_Text_2
# 25 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Wally_Text_3
# 26 "data/scripts/character_quests.pory"
	startquest QUEST_WALLY
# 27 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Wally_Text_4
# 28 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Wally_14:
# 32 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Wally_Text_5
# 33 "data/scripts/character_quests.pory"
	release
	end


CharacterQuest_EventScript_Steven::
# 45 "data/scripts/character_quests.pory"
	goto_if_set FLAG_LEGENDARY_BTL, CharacterQuest_EventScript_Steven_2
CharacterQuest_EventScript_Steven_1:
# 48 "data/scripts/character_quests.pory"
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_STEVEN
# 49 "data/scripts/character_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CharacterQuest_EventScript_Steven_5
CharacterQuest_EventScript_Steven_4:
# 52 "data/scripts/character_quests.pory"
	lock
# 53 "data/scripts/character_quests.pory"
	faceplayer
# 54 "data/scripts/character_quests.pory"
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_STEVEN
# 55 "data/scripts/character_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CharacterQuest_EventScript_Steven_8
# 60 "data/scripts/character_quests.pory"
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_STEVEN
# 61 "data/scripts/character_quests.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CharacterQuest_EventScript_Steven_11
	checkpartymon SPECIES_ANORITH
# 0 "data/scripts/character_quests.pory"
	compare VAR_RESULT, 0
	goto_if_eq CharacterQuest_EventScript_Steven_15
CharacterQuest_EventScript_Steven_13:
# 75 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Steven_Text_6
# 76 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Steven_Text_7
# 77 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Steven_Text_8
# 78 "data/scripts/character_quests.pory"
	completequest QUEST_STEVEN
# 79 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Steven_2:
# 46 "data/scripts/character_quests.pory"
	goto MossdeepCity_StevensHouse_EventScript_Steven
	goto CharacterQuest_EventScript_Steven_1

CharacterQuest_EventScript_Steven_5:
# 50 "data/scripts/character_quests.pory"
	goto MossdeepCity_StevensHouse_EventScript_Steven
	goto CharacterQuest_EventScript_Steven_4

CharacterQuest_EventScript_Steven_8:
# 56 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Steven_Text_0
# 57 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Steven_11:
# 62 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Steven_Text_1
# 63 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Steven_Text_2
# 64 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Steven_Text_3
# 65 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Steven_Text_4
# 66 "data/scripts/character_quests.pory"
	startquest QUEST_STEVEN
# 67 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Steven_14:
# 71 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Steven_Text_5
# 72 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Steven_15:
	checkpartymon SPECIES_LILEEP
# 0 "data/scripts/character_quests.pory"
	compare VAR_RESULT, 0
	goto_if_eq CharacterQuest_EventScript_Steven_14
	goto CharacterQuest_EventScript_Steven_13


CharacterQuest_EventScript_Roxanne::
# 84 "data/scripts/character_quests.pory"
	goto_if_set FLAG_LEGENDARY_BTL, CharacterQuest_EventScript_Roxanne_2
CharacterQuest_EventScript_Roxanne_1:
# 87 "data/scripts/character_quests.pory"
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ROXANNE
# 88 "data/scripts/character_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CharacterQuest_EventScript_Roxanne_5
CharacterQuest_EventScript_Roxanne_4:
# 91 "data/scripts/character_quests.pory"
	lock
# 92 "data/scripts/character_quests.pory"
	faceplayer
# 93 "data/scripts/character_quests.pory"
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_ROXANNE
# 94 "data/scripts/character_quests.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CharacterQuest_EventScript_Roxanne_8
	checkpartymon SPECIES_RELICANTH
# 0 "data/scripts/character_quests.pory"
	compare VAR_RESULT, 0
	goto_if_eq CharacterQuest_EventScript_Roxanne_11
# 107 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Roxanne_Text_4
# 108 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Roxanne_Text_5
# 109 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Roxanne_Text_6
# 110 "data/scripts/character_quests.pory"
	setvar VAR_GIFT_EGG_SPECIES, SPECIES_TYRUNT
# 111 "data/scripts/character_quests.pory"
	setvar VAR_GIFT_EGG_SHINY, FALSE
# 112 "data/scripts/character_quests.pory"
	setvar VAR_GIFT_EGG_MOVE1, MOVE_NONE
# 113 "data/scripts/character_quests.pory"
	setvar VAR_GIFT_EGG_MOVE2, MOVE_NONE
# 114 "data/scripts/character_quests.pory"
	setvar VAR_GIFT_EGG_MOVE3, MOVE_NONE
# 115 "data/scripts/character_quests.pory"
	setvar VAR_GIFT_EGG_MOVE4, MOVE_NONE
# 116 "data/scripts/character_quests.pory"
	special GiveCustomEgg
# 117 "data/scripts/character_quests.pory"
	switch VAR_RESULT
# 118 "data/scripts/character_quests.pory"
	case MON_CANT_GIVE, CharacterQuest_EventScript_Roxanne_15
# 120 "data/scripts/character_quests.pory"
	case MON_GIVEN_TO_PC, CharacterQuest_EventScript_Roxanne_16
# 125 "data/scripts/character_quests.pory"
	playfanfare MUS_OBTAIN_ITEM
# 126 "data/scripts/character_quests.pory"
	waitfanfare
# 127 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Roxanne_Text_8
CharacterQuest_EventScript_Roxanne_13:
# 129 "data/scripts/character_quests.pory"
	completequest QUEST_ROXANNE
# 130 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Roxanne_2:
# 85 "data/scripts/character_quests.pory"
	goto RustboroCity_Gym_EventScript_Roxanne
	goto CharacterQuest_EventScript_Roxanne_1

CharacterQuest_EventScript_Roxanne_5:
# 89 "data/scripts/character_quests.pory"
	goto RustboroCity_Gym_EventScript_Roxanne
	goto CharacterQuest_EventScript_Roxanne_4

CharacterQuest_EventScript_Roxanne_8:
# 95 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Roxanne_Text_0
# 96 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Roxanne_Text_1
# 97 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Roxanne_Text_2
# 98 "data/scripts/character_quests.pory"
	startquest QUEST_ROXANNE
# 99 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Roxanne_11:
# 103 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Roxanne_Text_3
# 104 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Roxanne_15:
# 119 "data/scripts/character_quests.pory"
	goto CharacterQuest_EventScript_NoRoomForEgg
	goto CharacterQuest_EventScript_Roxanne_13

CharacterQuest_EventScript_Roxanne_16:
# 121 "data/scripts/character_quests.pory"
	playfanfare MUS_OBTAIN_ITEM
# 122 "data/scripts/character_quests.pory"
	waitfanfare
# 123 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Roxanne_Text_7
	goto CharacterQuest_EventScript_Roxanne_13


CharacterQuest_EventScript_Brawly::
# 135 "data/scripts/character_quests.pory"
	goto_if_set FLAG_LEGENDARY_BTL, CharacterQuest_EventScript_Brawly_2
CharacterQuest_EventScript_Brawly_1:
# 138 "data/scripts/character_quests.pory"
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BRAWLY
# 139 "data/scripts/character_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CharacterQuest_EventScript_Brawly_5
CharacterQuest_EventScript_Brawly_4:
# 142 "data/scripts/character_quests.pory"
	lock
# 143 "data/scripts/character_quests.pory"
	faceplayer
# 144 "data/scripts/character_quests.pory"
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_BRAWLY
# 145 "data/scripts/character_quests.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CharacterQuest_EventScript_Brawly_8
	checkpartymon SPECIES_MAKUHITA
# 0 "data/scripts/character_quests.pory"
	compare VAR_RESULT, 0
	goto_if_eq CharacterQuest_EventScript_Brawly_11
# 158 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Brawly_Text_4
# 159 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Brawly_Text_5
# 160 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Brawly_Text_6
# 161 "data/scripts/character_quests.pory"
	setvar VAR_GIFT_EGG_SPECIES, SPECIES_RIOLU
# 162 "data/scripts/character_quests.pory"
	setvar VAR_GIFT_EGG_SHINY, FALSE
# 163 "data/scripts/character_quests.pory"
	setvar VAR_GIFT_EGG_MOVE1, MOVE_NONE
# 164 "data/scripts/character_quests.pory"
	setvar VAR_GIFT_EGG_MOVE2, MOVE_NONE
# 165 "data/scripts/character_quests.pory"
	setvar VAR_GIFT_EGG_MOVE3, MOVE_NONE
# 166 "data/scripts/character_quests.pory"
	setvar VAR_GIFT_EGG_MOVE4, MOVE_NONE
# 167 "data/scripts/character_quests.pory"
	special GiveCustomEgg
# 168 "data/scripts/character_quests.pory"
	switch VAR_RESULT
# 169 "data/scripts/character_quests.pory"
	case MON_CANT_GIVE, CharacterQuest_EventScript_Brawly_15
# 171 "data/scripts/character_quests.pory"
	case MON_GIVEN_TO_PC, CharacterQuest_EventScript_Brawly_16
# 176 "data/scripts/character_quests.pory"
	playfanfare MUS_OBTAIN_ITEM
# 177 "data/scripts/character_quests.pory"
	waitfanfare
# 178 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Brawly_Text_8
CharacterQuest_EventScript_Brawly_13:
# 180 "data/scripts/character_quests.pory"
	completequest QUEST_BRAWLY
# 181 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Brawly_2:
# 136 "data/scripts/character_quests.pory"
	goto DewfordTown_Gym_EventScript_Brawly
	goto CharacterQuest_EventScript_Brawly_1

CharacterQuest_EventScript_Brawly_5:
# 140 "data/scripts/character_quests.pory"
	goto DewfordTown_Gym_EventScript_Brawly
	goto CharacterQuest_EventScript_Brawly_4

CharacterQuest_EventScript_Brawly_8:
# 146 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Brawly_Text_0
# 147 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Brawly_Text_1
# 148 "data/scripts/character_quests.pory"
	startquest QUEST_BRAWLY
# 149 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Brawly_Text_2
# 150 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Brawly_11:
# 154 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Brawly_Text_3
# 155 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Brawly_15:
# 170 "data/scripts/character_quests.pory"
	goto CharacterQuest_EventScript_NoRoomForEgg
	goto CharacterQuest_EventScript_Brawly_13

CharacterQuest_EventScript_Brawly_16:
# 172 "data/scripts/character_quests.pory"
	playfanfare MUS_OBTAIN_ITEM
# 173 "data/scripts/character_quests.pory"
	waitfanfare
# 174 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Brawly_Text_7
	goto CharacterQuest_EventScript_Brawly_13


CharacterQuest_EventScript_Wattson::
# 186 "data/scripts/character_quests.pory"
	goto_if_set FLAG_LEGENDARY_BTL, CharacterQuest_EventScript_Wattson_2
CharacterQuest_EventScript_Wattson_1:
# 189 "data/scripts/character_quests.pory"
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_WATTSON
# 190 "data/scripts/character_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CharacterQuest_EventScript_Wattson_5
CharacterQuest_EventScript_Wattson_4:
# 193 "data/scripts/character_quests.pory"
	lock
# 194 "data/scripts/character_quests.pory"
	faceplayer
# 195 "data/scripts/character_quests.pory"
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_WATTSON
# 196 "data/scripts/character_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CharacterQuest_EventScript_Wattson_8
# 201 "data/scripts/character_quests.pory"
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_WATTSON
# 202 "data/scripts/character_quests.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CharacterQuest_EventScript_Wattson_11
	checkpartymon SPECIES_MAGNEMITE
# 0 "data/scripts/character_quests.pory"
	compare VAR_RESULT, 0
	goto_if_eq CharacterQuest_EventScript_Wattson_14
# 215 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Wattson_Text_5
# 216 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Wattson_Text_6
# 217 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Wattson_Text_7
# 218 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Wattson_Text_8
# 219 "data/scripts/character_quests.pory"
	completequest QUEST_WATTSON
# 220 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Wattson_2:
# 187 "data/scripts/character_quests.pory"
	goto MauvilleCity_Gym_EventScript_Wattson
	goto CharacterQuest_EventScript_Wattson_1

CharacterQuest_EventScript_Wattson_5:
# 191 "data/scripts/character_quests.pory"
	goto MauvilleCity_Gym_EventScript_Wattson
	goto CharacterQuest_EventScript_Wattson_4

CharacterQuest_EventScript_Wattson_8:
# 197 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Wattson_Text_0
# 198 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Wattson_11:
# 203 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Wattson_Text_1
# 204 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Wattson_Text_2
# 205 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Wattson_Text_3
# 206 "data/scripts/character_quests.pory"
	startquest QUEST_WATTSON
# 207 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Wattson_14:
# 211 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Wattson_Text_4
# 212 "data/scripts/character_quests.pory"
	release
	end


CharacterQuest_EventScript_Flannery::
# 225 "data/scripts/character_quests.pory"
	goto_if_set FLAG_LEGENDARY_BTL, CharacterQuest_EventScript_Flannery_2
CharacterQuest_EventScript_Flannery_1:
# 228 "data/scripts/character_quests.pory"
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_FLANNERY
# 229 "data/scripts/character_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CharacterQuest_EventScript_Flannery_5
CharacterQuest_EventScript_Flannery_4:
# 232 "data/scripts/character_quests.pory"
	lock
# 233 "data/scripts/character_quests.pory"
	faceplayer
# 234 "data/scripts/character_quests.pory"
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_FLANNERY
# 235 "data/scripts/character_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CharacterQuest_EventScript_Flannery_8
# 240 "data/scripts/character_quests.pory"
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_FLANNERY
# 241 "data/scripts/character_quests.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CharacterQuest_EventScript_Flannery_11
	checkitem ITEM_ICE_HEAL
# 0 "data/scripts/character_quests.pory"
	compare VAR_RESULT, 0
	goto_if_eq CharacterQuest_EventScript_Flannery_14
# 254 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Flannery_Text_5
# 255 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Flannery_Text_6
# 256 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Flannery_Text_7
# 257 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Flannery_Text_8
# 258 "data/scripts/character_quests.pory"
	completequest QUEST_FLANNERY
# 259 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Flannery_2:
# 226 "data/scripts/character_quests.pory"
	goto LavaridgeTown_Gym_1F_EventScript_Flannery
	goto CharacterQuest_EventScript_Flannery_1

CharacterQuest_EventScript_Flannery_5:
# 230 "data/scripts/character_quests.pory"
	goto LavaridgeTown_Gym_1F_EventScript_Flannery
	goto CharacterQuest_EventScript_Flannery_4

CharacterQuest_EventScript_Flannery_8:
# 236 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Flannery_Text_0
# 237 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Flannery_11:
# 242 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Flannery_Text_1
# 243 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Flannery_Text_2
# 244 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Flannery_Text_3
# 245 "data/scripts/character_quests.pory"
	startquest QUEST_FLANNERY
# 246 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Flannery_14:
# 250 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Flannery_Text_4
# 251 "data/scripts/character_quests.pory"
	release
	end


CharacterQuest_EventScript_Norman::
# 264 "data/scripts/character_quests.pory"
	goto_if_set FLAG_LEGENDARY_BTL, CharacterQuest_EventScript_Norman_2
CharacterQuest_EventScript_Norman_1:
# 267 "data/scripts/character_quests.pory"
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_NORMAN
# 268 "data/scripts/character_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CharacterQuest_EventScript_Norman_5
CharacterQuest_EventScript_Norman_4:
# 271 "data/scripts/character_quests.pory"
	lock
# 272 "data/scripts/character_quests.pory"
	faceplayer
# 273 "data/scripts/character_quests.pory"
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_NORMAN
# 274 "data/scripts/character_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CharacterQuest_EventScript_Norman_8
# 279 "data/scripts/character_quests.pory"
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_NORMAN
# 280 "data/scripts/character_quests.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CharacterQuest_EventScript_Norman_11
	checkpartymon SPECIES_SLAKOTH
# 0 "data/scripts/character_quests.pory"
	compare VAR_RESULT, 0
	goto_if_eq CharacterQuest_EventScript_Norman_14
# 294 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Norman_Text_6
# 295 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Norman_Text_7
# 296 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Norman_Text_8
# 297 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Norman_Text_9
# 298 "data/scripts/character_quests.pory"
	completequest QUEST_NORMAN
# 299 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Norman_2:
# 265 "data/scripts/character_quests.pory"
	goto PetalburgCity_Gym_EventScript_Norman
	goto CharacterQuest_EventScript_Norman_1

CharacterQuest_EventScript_Norman_5:
# 269 "data/scripts/character_quests.pory"
	goto PetalburgCity_Gym_EventScript_Norman
	goto CharacterQuest_EventScript_Norman_4

CharacterQuest_EventScript_Norman_8:
# 275 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Norman_Text_0
# 276 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Norman_11:
# 281 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Norman_Text_1
# 282 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Norman_Text_2
# 283 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Norman_Text_3
# 284 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Norman_Text_4
# 285 "data/scripts/character_quests.pory"
	startquest QUEST_NORMAN
# 286 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Norman_14:
# 290 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Norman_Text_5
# 291 "data/scripts/character_quests.pory"
	release
	end


CharacterQuest_EventScript_Winona::
# 304 "data/scripts/character_quests.pory"
	goto_if_set FLAG_LEGENDARY_BTL, CharacterQuest_EventScript_Winona_2
CharacterQuest_EventScript_Winona_1:
# 307 "data/scripts/character_quests.pory"
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_WINONA
# 308 "data/scripts/character_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CharacterQuest_EventScript_Winona_5
CharacterQuest_EventScript_Winona_4:
# 311 "data/scripts/character_quests.pory"
	lock
# 312 "data/scripts/character_quests.pory"
	faceplayer
# 313 "data/scripts/character_quests.pory"
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_WINONA
# 314 "data/scripts/character_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CharacterQuest_EventScript_Winona_8
# 319 "data/scripts/character_quests.pory"
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_WINONA
# 320 "data/scripts/character_quests.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CharacterQuest_EventScript_Winona_11
	checkpartymon SPECIES_SWABLU
# 0 "data/scripts/character_quests.pory"
	compare VAR_RESULT, 0
	goto_if_eq CharacterQuest_EventScript_Winona_14
# 333 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Winona_Text_5
# 334 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Winona_Text_6
# 335 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Winona_Text_7
# 336 "data/scripts/character_quests.pory"
	completequest QUEST_WINONA
# 337 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Winona_2:
# 305 "data/scripts/character_quests.pory"
	goto FortreeCity_Gym_EventScript_Winona
	goto CharacterQuest_EventScript_Winona_1

CharacterQuest_EventScript_Winona_5:
# 309 "data/scripts/character_quests.pory"
	goto FortreeCity_Gym_EventScript_Winona
	goto CharacterQuest_EventScript_Winona_4

CharacterQuest_EventScript_Winona_8:
# 315 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Winona_Text_0
# 316 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Winona_11:
# 321 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Winona_Text_1
# 322 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Winona_Text_2
# 323 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Winona_Text_3
# 324 "data/scripts/character_quests.pory"
	startquest QUEST_WINONA
# 325 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Winona_14:
# 329 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Winona_Text_4
# 330 "data/scripts/character_quests.pory"
	release
	end


CharacterQuest_EventScript_TateAndLiza::
# 342 "data/scripts/character_quests.pory"
	goto_if_set FLAG_LEGENDARY_BTL, CharacterQuest_EventScript_TateAndLiza_2
CharacterQuest_EventScript_TateAndLiza_1:
# 345 "data/scripts/character_quests.pory"
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_TATE_AND_LIZA
# 346 "data/scripts/character_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CharacterQuest_EventScript_TateAndLiza_5
CharacterQuest_EventScript_TateAndLiza_4:
# 349 "data/scripts/character_quests.pory"
	lock
# 350 "data/scripts/character_quests.pory"
	faceplayer
# 351 "data/scripts/character_quests.pory"
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_TATE_AND_LIZA
# 352 "data/scripts/character_quests.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CharacterQuest_EventScript_TateAndLiza_8
	checkpartymon SPECIES_SOLROCK
# 0 "data/scripts/character_quests.pory"
	compare VAR_RESULT, 0
	goto_if_eq CharacterQuest_EventScript_TateAndLiza_11
	checkpartymon SPECIES_LUNATONE
# 0 "data/scripts/character_quests.pory"
	compare VAR_RESULT, 0
	goto_if_eq CharacterQuest_EventScript_TateAndLiza_11
# 369 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_TateAndLiza_Text_8
# 370 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_TateAndLiza_Text_9
# 371 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_TateAndLiza_Text_10
# 372 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_TateAndLiza_Text_11
# 373 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_TateAndLiza_Text_12
# 374 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_TateAndLiza_Text_13
# 375 "data/scripts/character_quests.pory"
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_MINIOR
# 376 "data/scripts/character_quests.pory"
	givemon SPECIES_MINIOR, 35
# 377 "data/scripts/character_quests.pory"
	compare VAR_RESULT, MON_CANT_GIVE
	goto_if_eq CharacterQuest_EventScript_TateAndLiza_16
CharacterQuest_EventScript_TateAndLiza_15:
# 380 "data/scripts/character_quests.pory"
	playfanfare MUS_OBTAIN_ITEM
# 381 "data/scripts/character_quests.pory"
	waitfanfare
# 382 "data/scripts/character_quests.pory"
	compare VAR_RESULT, MON_GIVEN_TO_PC
	goto_if_eq CharacterQuest_EventScript_TateAndLiza_19
# 385 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_TateAndLiza_Text_15
CharacterQuest_EventScript_TateAndLiza_18:
# 387 "data/scripts/character_quests.pory"
	completequest QUEST_TATE_AND_LIZA
# 388 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_TateAndLiza_2:
# 343 "data/scripts/character_quests.pory"
	goto MossdeepCity_Gym_EventScript_TateAndLiza
	goto CharacterQuest_EventScript_TateAndLiza_1

CharacterQuest_EventScript_TateAndLiza_5:
# 347 "data/scripts/character_quests.pory"
	goto MossdeepCity_Gym_EventScript_TateAndLiza
	goto CharacterQuest_EventScript_TateAndLiza_4

CharacterQuest_EventScript_TateAndLiza_8:
# 353 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_TateAndLiza_Text_0
# 354 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_TateAndLiza_Text_1
# 355 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_TateAndLiza_Text_2
# 356 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_TateAndLiza_Text_3
# 357 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_TateAndLiza_Text_4
# 358 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_TateAndLiza_Text_5
# 359 "data/scripts/character_quests.pory"
	startquest QUEST_TATE_AND_LIZA
# 360 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_TateAndLiza_11:
# 364 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_TateAndLiza_Text_6
# 365 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_TateAndLiza_Text_7
# 366 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_TateAndLiza_16:
# 378 "data/scripts/character_quests.pory"
	goto CharacterQuest_EventScript_NoRoomForPokemon
	goto CharacterQuest_EventScript_TateAndLiza_15

CharacterQuest_EventScript_TateAndLiza_19:
# 383 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_TateAndLiza_Text_14
	goto CharacterQuest_EventScript_TateAndLiza_18


CharacterQuest_EventScript_Juan::
# 393 "data/scripts/character_quests.pory"
	goto_if_set FLAG_LEGENDARY_BTL, CharacterQuest_EventScript_Juan_2
CharacterQuest_EventScript_Juan_1:
# 396 "data/scripts/character_quests.pory"
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_JUAN
# 397 "data/scripts/character_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq CharacterQuest_EventScript_Juan_5
CharacterQuest_EventScript_Juan_4:
# 400 "data/scripts/character_quests.pory"
	lock
# 401 "data/scripts/character_quests.pory"
	faceplayer
# 402 "data/scripts/character_quests.pory"
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_JUAN
# 403 "data/scripts/character_quests.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq CharacterQuest_EventScript_Juan_8
	checkpartymon SPECIES_FEEBAS
# 0 "data/scripts/character_quests.pory"
	compare VAR_RESULT, 0
	goto_if_eq CharacterQuest_EventScript_Juan_11
# 417 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Juan_Text_5
# 418 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Juan_Text_6
# 419 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Juan_Text_7
# 420 "data/scripts/character_quests.pory"
	setvar VAR_GIFT_EGG_SPECIES, SPECIES_FEEBAS
# 421 "data/scripts/character_quests.pory"
	setvar VAR_GIFT_EGG_SHINY, TRUE
# 422 "data/scripts/character_quests.pory"
	setvar VAR_GIFT_EGG_MOVE1, MOVE_NONE
# 423 "data/scripts/character_quests.pory"
	setvar VAR_GIFT_EGG_MOVE2, MOVE_NONE
# 424 "data/scripts/character_quests.pory"
	setvar VAR_GIFT_EGG_MOVE3, MOVE_NONE
# 425 "data/scripts/character_quests.pory"
	setvar VAR_GIFT_EGG_MOVE4, MOVE_NONE
# 426 "data/scripts/character_quests.pory"
	special GiveCustomEgg
# 427 "data/scripts/character_quests.pory"
	switch VAR_RESULT
# 428 "data/scripts/character_quests.pory"
	case MON_CANT_GIVE, CharacterQuest_EventScript_Juan_15
# 430 "data/scripts/character_quests.pory"
	case MON_GIVEN_TO_PC, CharacterQuest_EventScript_Juan_16
# 435 "data/scripts/character_quests.pory"
	playfanfare MUS_OBTAIN_ITEM
# 436 "data/scripts/character_quests.pory"
	waitfanfare
# 437 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Juan_Text_9
CharacterQuest_EventScript_Juan_13:
# 439 "data/scripts/character_quests.pory"
	completequest QUEST_JUAN
# 440 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Juan_2:
# 394 "data/scripts/character_quests.pory"
	goto SootopolisCity_Gym_1F_EventScript_Juan
	goto CharacterQuest_EventScript_Juan_1

CharacterQuest_EventScript_Juan_5:
# 398 "data/scripts/character_quests.pory"
	goto SootopolisCity_Gym_1F_EventScript_Juan
	goto CharacterQuest_EventScript_Juan_4

CharacterQuest_EventScript_Juan_8:
# 404 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Juan_Text_0
# 405 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Juan_Text_1
# 406 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Juan_Text_2
# 407 "data/scripts/character_quests.pory"
	startquest QUEST_JUAN
# 408 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Juan_Text_3
# 409 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Juan_11:
# 413 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Juan_Text_4
# 414 "data/scripts/character_quests.pory"
	release
	end

CharacterQuest_EventScript_Juan_15:
# 429 "data/scripts/character_quests.pory"
	goto CharacterQuest_EventScript_NoRoomForEgg
	goto CharacterQuest_EventScript_Juan_13

CharacterQuest_EventScript_Juan_16:
# 431 "data/scripts/character_quests.pory"
	playfanfare MUS_OBTAIN_ITEM
# 432 "data/scripts/character_quests.pory"
	waitfanfare
# 433 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_Juan_Text_8
	goto CharacterQuest_EventScript_Juan_13


CharacterQuest_EventScript_NoRoomForEgg::
# 445 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_NoRoomForEgg_Text_0
# 446 "data/scripts/character_quests.pory"
	release
	end


CharacterQuest_EventScript_NoRoomForPokemon::
# 451 "data/scripts/character_quests.pory"
	msgbox CharacterQuest_EventScript_NoRoomForPokemon_Text_0
# 452 "data/scripts/character_quests.pory"
	release
	end


CharacterQuest_EventScript_Wally_Text_0:
# 17 "data/scripts/character_quests.pory"
	.string "The Gardevoirite is waiting in your\n"
	.string "Quest Log.\p"
	.string "I still can't believe I managed that\n"
	.string "whole speech without checking my\l"
	.string "notes!$"

CharacterQuest_EventScript_Wally_Text_1:
# 23 "data/scripts/character_quests.pory"
	.string "Champion {PLAYER}! I practiced this\n"
	.string "speech all morning.\p"
	.string "My uncle says he can now recite it in his\n"
	.string "sleep.$"

CharacterQuest_EventScript_Wally_Text_2:
# 24 "data/scripts/character_quests.pory"
	.string "When I met Ralts, I was afraid one\n"
	.string "breath of tall grass would send me\l"
	.string "straight home.\p"
	.string "Ralts trusted me before I trusted\n"
	.string "myself.$"

CharacterQuest_EventScript_Wally_Text_3:
# 25 "data/scripts/character_quests.pory"
	.string "Would you bring a Ralts to see me? I\n"
	.string "want to learn how to welcome a\l"
	.string "frightened new Trainer the way you\l"
	.string "once welcomed me.$"

CharacterQuest_EventScript_Wally_Text_4:
# 27 "data/scripts/character_quests.pory"
	.string "I'll be here in Verdanturf. And I promise\n"
	.string "not to rehearse at my uncle after\l"
	.string "bedtime.$"

CharacterQuest_EventScript_Wally_Text_5:
# 32 "data/scripts/character_quests.pory"
	.string "Bring a Ralts in your party when you\n"
	.string "find one.\p"
	.string "There is no rush. The best first steps\n"
	.string "happen when both Trainer and Pokémon\l"
	.string "are ready.$"

CharacterQuest_EventScript_Wally_Text_6:
# 36 "data/scripts/character_quests.pory"
	.string "It's looking at me exactly the way mine\n"
	.string "did--quiet, but braver than everyone\l"
	.string "realizes.$"

CharacterQuest_EventScript_Wally_Text_7:
# 37 "data/scripts/character_quests.pory"
	.string "I used to think courage meant never\n"
	.string "feeling weak.\p"
	.string "You taught me it means taking one more\n"
	.string "step while you do.$"

CharacterQuest_EventScript_Wally_Text_8:
# 38 "data/scripts/character_quests.pory"
	.string "I've registered a Gardevoirite in your\n"
	.string "Quest Log.\p"
	.string "My partner does not need a stone to\n"
	.string "prove how far we've come. Let it mark\l"
	.string "how far you helped me go.$"

CharacterQuest_EventScript_Steven_Text_0:
# 56 "data/scripts/character_quests.pory"
	.string "Your Metagrossite is waiting in the\n"
	.string "Quest Log.\p"
	.string "I should return to my lecture. Page\n"
	.string "forty-eight now contains two full lines\l"
	.string "about people.$"

CharacterQuest_EventScript_Steven_Text_1:
# 62 "data/scripts/character_quests.pory"
	.string "Champion. Your timing is impeccable. I\n"
	.string "require assistance with a lecture for\l"
	.string "Devon's young researchers.$"

CharacterQuest_EventScript_Steven_Text_2:
# 63 "data/scripts/character_quests.pory"
	.string "My notes currently contain\n"
	.string "forty-seven pages on mineral lattices\l"
	.string "and one line reading, 'Remember to\l"
	.string "mention people.'$"

CharacterQuest_EventScript_Steven_Text_3:
# 64 "data/scripts/character_quests.pory"
	.string "My father expects me to speak about\n"
	.string "inheriting Devon. I would rather show\l"
	.string "how ancient life became stone--and how\l"
	.string "even stone can change.$"

CharacterQuest_EventScript_Steven_Text_4:
# 65 "data/scripts/character_quests.pory"
	.string "Would you bring me an Anorith or Lileep?\n"
	.string "A living fossil may rescue both the\l"
	.string "lecture and its audience.$"

CharacterQuest_EventScript_Steven_Text_5:
# 71 "data/scripts/character_quests.pory"
	.string "An Anorith or Lileep in your party would\n"
	.string "be ideal.\p"
	.string "Do not worry. I have reduced the\n"
	.string "mineral-lattice section to a brisk\l"
	.string "thirty-nine pages.$"

CharacterQuest_EventScript_Steven_Text_6:
# 75 "data/scripts/character_quests.pory"
	.string "Extraordinary. The shape is ancient,\n"
	.string "yet every movement is an answer to the\l"
	.string "present.$"

CharacterQuest_EventScript_Steven_Text_7:
# 76 "data/scripts/character_quests.pory"
	.string "When I was young, I collected stones\n"
	.string "because they asked nothing of me.\p"
	.string "People--and Pokémon--eventually\n"
	.string "taught me that responsibility can also\l"
	.string "be worth carrying.$"

CharacterQuest_EventScript_Steven_Text_8:
# 77 "data/scripts/character_quests.pory"
	.string "I have placed a Metagrossite in your\n"
	.string "Quest Log.\p"
	.string "Consider it a reminder: strength is not\n"
	.string "the weight we inherit, but what we\l"
	.string "choose to do while carrying it.$"

CharacterQuest_EventScript_Roxanne_Text_0:
# 95 "data/scripts/character_quests.pory"
	.string "Champion {PLAYER}! Excellent timing.\n"
	.string "Tomorrow's lesson is 'Ancient Life.'$"

CharacterQuest_EventScript_Roxanne_Text_1:
# 96 "data/scripts/character_quests.pory"
	.string "My notes are accurate, organized,\n"
	.string "and--according to one\l"
	.string "student--'sleepier than a Geodude.'\p"
	.string "I cannot deduct marks for an accurate\n"
	.string "geological comparison.$"

CharacterQuest_EventScript_Roxanne_Text_2:
# 97 "data/scripts/character_quests.pory"
	.string "Would you show my class a Relicanth? A\n"
	.string "living fossil should make history feel\l"
	.string "alive.$"

CharacterQuest_EventScript_Roxanne_Text_3:
# 103 "data/scripts/character_quests.pory"
	.string "Please bring a Relicanth in your party.\p"
	.string "The fossil record has waited a hundred\n"
	.string "million years. My lesson can wait a\l"
	.string "little longer.$"

CharacterQuest_EventScript_Roxanne_Text_4:
# 107 "data/scripts/character_quests.pory"
	.string "Remarkable! Its scales preserve a\n"
	.string "design unchanged for a hundred million\l"
	.string "years.$"

CharacterQuest_EventScript_Roxanne_Text_5:
# 108 "data/scripts/character_quests.pory"
	.string "Today, history is breathing. Even my\n"
	.string "back-row student has stopped naming\l"
	.string "every rock 'Steve.'$"

CharacterQuest_EventScript_Roxanne_Text_6:
# 109 "data/scripts/character_quests.pory"
	.string "This Egg was donated with a collection\n"
	.string "of ancient specimens. It belongs with a\l"
	.string "Trainer who makes history feel alive.$"

CharacterQuest_EventScript_Roxanne_Text_7:
# 123 "data/scripts/character_quests.pory"
	.string "Your party was full, so the Tyrunt Egg\n"
	.string "was sent to a Box in your PC.$"

CharacterQuest_EventScript_Roxanne_Text_8:
# 127 "data/scripts/character_quests.pory"
	.string "{PLAYER} received a Tyrunt Egg from\n"
	.string "Roxanne!$"

CharacterQuest_EventScript_Brawly_Text_0:
# 146 "data/scripts/character_quests.pory"
	.string "Champion! I'm rebuilding my oldest\n"
	.string "training plan--the one Bruno taught me\l"
	.string "before I understood that 'one more rep'\l"
	.string "can mean forty.$"

CharacterQuest_EventScript_Brawly_Text_1:
# 147 "data/scripts/character_quests.pory"
	.string "Makuhita keeps staring at my\n"
	.string "kelp-protein bars and backing away.\p"
	.string "I need a Makuhita with a Champion's\n"
	.string "judgment to test the routine.$"

CharacterQuest_EventScript_Brawly_Text_2:
# 149 "data/scripts/character_quests.pory"
	.string "Bring one in your party. One clap means\n"
	.string "the workout rules. Two claps means my\l"
	.string "snack finally rules.$"

CharacterQuest_EventScript_Brawly_Text_3:
# 154 "data/scripts/character_quests.pory"
	.string "Bring a Makuhita in your party when\n"
	.string "you're ready.\p"
	.string "The protein bar is getting greener, so\n"
	.string "maybe don't take too long.$"

CharacterQuest_EventScript_Brawly_Text_4:
# 158 "data/scripts/character_quests.pory"
	.string "Okay, little dude. One clap for the\n"
	.string "routine, two for the snack.$"

CharacterQuest_EventScript_Brawly_Text_5:
# 159 "data/scripts/character_quests.pory"
	.string "...That was one clap. Then it slapped the\n"
	.string "snack into the wall.\p"
	.string "Radical feedback.$"

CharacterQuest_EventScript_Brawly_Text_6:
# 160 "data/scripts/character_quests.pory"
	.string "Bruno gave me this Egg after I finally\n"
	.string "learned strength isn't just pushing\l"
	.string "harder. Raise it with balance.$"

CharacterQuest_EventScript_Brawly_Text_7:
# 174 "data/scripts/character_quests.pory"
	.string "Your party was full, so the Riolu Egg\n"
	.string "rode the next wave to a Box in your PC.$"

CharacterQuest_EventScript_Brawly_Text_8:
# 178 "data/scripts/character_quests.pory"
	.string "{PLAYER} received a Riolu Egg from\n"
	.string "Brawly!$"

CharacterQuest_EventScript_Wattson_Text_0:
# 197 "data/scripts/character_quests.pory"
	.string "The Manectite is crackling away in your\n"
	.string "Quest Log!\p"
	.string "Wahahaha! Metaphorically, I hope.$"

CharacterQuest_EventScript_Wattson_Text_1:
# 203 "data/scripts/character_quests.pory"
	.string "Ah, Champion! My first generator has\n"
	.string "stopped laughing with me. A machine\l"
	.string "that old deserves manners!$"

CharacterQuest_EventScript_Wattson_Text_2:
# 204 "data/scripts/character_quests.pory"
	.string "I built it after a blackout frightened\n"
	.string "half of Mauville. The other half was me,\l"
	.string "pretending the sparks were intentional.\l"
	.string "Wahahaha!$"

CharacterQuest_EventScript_Wattson_Text_3:
# 205 "data/scripts/character_quests.pory"
	.string "A Magnemite can bridge its oldest\n"
	.string "circuit safely. Bring one in your party,\l"
	.string "and we may hear the old rattle again.$"

CharacterQuest_EventScript_Wattson_Text_4:
# 211 "data/scripts/character_quests.pory"
	.string "A Magnemite in your party is just the\n"
	.string "living fuse we need.\p"
	.string "The generator and I will keep each\n"
	.string "other entertained until then!$"

CharacterQuest_EventScript_Wattson_Text_5:
# 215 "data/scripts/character_quests.pory"
	.string "Contact! Easy now--one spark, two\n"
	.string "sparks... Wahahaha! Hear that terrible\l"
	.string "rattle?$"

CharacterQuest_EventScript_Wattson_Text_6:
# 216 "data/scripts/character_quests.pory"
	.string "That sound once meant the city had\n"
	.string "light again. I was young, terrified, and\l"
	.string "laughing so nobody else would know.$"

CharacterQuest_EventScript_Wattson_Text_7:
# 217 "data/scripts/character_quests.pory"
	.string "You and Magnemite have earned this\n"
	.string "Manectite. It is registered in your\l"
	.string "Quest Log--along with my professional\l"
	.string "promise to retire this generator.$"

CharacterQuest_EventScript_Wattson_Text_8:
# 218 "data/scripts/character_quests.pory"
	.string "...My personal promise is less\n"
	.string "professional.$"

CharacterQuest_EventScript_Flannery_Text_0:
# 236 "data/scripts/character_quests.pory"
	.string "The Cameruptite is waiting in your\n"
	.string "Quest Log.\p"
	.string "That delivery was calm, clear, and only a\n"
	.string "little fiery. I'm improving!$"

CharacterQuest_EventScript_Flannery_Text_1:
# 242 "data/scripts/character_quests.pory"
	.string "Welcome, challenger! I am the scorching\n"
	.string "heir to--\p"
	.string "No. That still sounds like Granddad\n"
	.string "wearing my jacket.$"

CharacterQuest_EventScript_Flannery_Text_2:
# 243 "data/scripts/character_quests.pory"
	.string "My grandfather never forgot a safety\n"
	.string "check. I forgot three while practicing\l"
	.string "that entrance.$"

CharacterQuest_EventScript_Flannery_Text_3:
# 244 "data/scripts/character_quests.pory"
	.string "Could you bring me an Ice Heal? We will\n"
	.string "run the Gym's emergency drill, and I will\l"
	.string "try giving orders in my own voice.$"

CharacterQuest_EventScript_Flannery_Text_4:
# 250 "data/scripts/character_quests.pory"
	.string "Bring an Ice Heal for the emergency\n"
	.string "drill.\p"
	.string "Not because anything is on fire! It is a\n"
	.string "drill. A very warm, completely controlled\l"
	.string "drill.$"

CharacterQuest_EventScript_Flannery_Text_5:
# 254 "data/scripts/character_quests.pory"
	.string "Valve closed! Sand ready! Ice Heal...\n"
	.string "held dramatically overhead!$"

CharacterQuest_EventScript_Flannery_Text_6:
# 255 "data/scripts/character_quests.pory"
	.string "No smoke. No panic. And I didn't borrow\n"
	.string "Granddad's voice.$"

CharacterQuest_EventScript_Flannery_Text_7:
# 256 "data/scripts/character_quests.pory"
	.string "Being his granddaughter opened this\n"
	.string "Gym's door. Becoming Flannery is what\l"
	.string "keeps me standing here.$"

CharacterQuest_EventScript_Flannery_Text_8:
# 257 "data/scripts/character_quests.pory"
	.string "I've registered a Cameruptite in your\n"
	.string "Quest Log. Keep your Ice Heal--you are\l"
	.string "apparently the responsible one here.$"

CharacterQuest_EventScript_Norman_Text_0:
# 275 "data/scripts/character_quests.pory"
	.string "The Ability Patch is waiting in your\n"
	.string "Quest Log.\p"
	.string "Your mother has informed me that\n"
	.string "checking the log does not count as\l"
	.string "training.$"

CharacterQuest_EventScript_Norman_Text_1:
# 281 "data/scripts/character_quests.pory"
	.string "Champion. I have a problem no training\n"
	.string "schedule has solved.$"

CharacterQuest_EventScript_Norman_Text_2:
# 282 "data/scripts/character_quests.pory"
	.string "Your mother invited me to dinner. I said,\n"
	.string "'After one more set.' She said that was\l"
	.string "the same answer I gave in Johto, before\l"
	.string "we moved.$"

CharacterQuest_EventScript_Norman_Text_3:
# 283 "data/scripts/character_quests.pory"
	.string "I spent years proving I could support\n"
	.string "this family, and too many evenings not\l"
	.string "being part of it.$"

CharacterQuest_EventScript_Norman_Text_4:
# 284 "data/scripts/character_quests.pory"
	.string "Bring me a Slakoth. I need instruction\n"
	.string "from an expert in doing absolutely\l"
	.string "nothing.$"

CharacterQuest_EventScript_Norman_Text_5:
# 290 "data/scripts/character_quests.pory"
	.string "Bring a Slakoth in your party.\p"
	.string "I attempted to rest alone. I\n"
	.string "reorganized the Gym's training schedule\l"
	.string "in under six minutes.$"

CharacterQuest_EventScript_Norman_Text_6:
# 294 "data/scripts/character_quests.pory"
	.string "It has done nothing for a full minute.$"

CharacterQuest_EventScript_Norman_Text_7:
# 295 "data/scripts/character_quests.pory"
	.string "...That is surprisingly difficult to\n"
	.string "watch without assigning it drills.$"

CharacterQuest_EventScript_Norman_Text_8:
# 296 "data/scripts/character_quests.pory"
	.string "All right. I will close the Gym early.\n"
	.string "Dinner, no notes, no sets, and no\l"
	.string "evaluating the table's balance.$"

CharacterQuest_EventScript_Norman_Text_9:
# 297 "data/scripts/character_quests.pory"
	.string "This Ability Patch was meant for\n"
	.string "optimizing a team. Today, let it reward a\l"
	.string "better kind of change. It is in your\l"
	.string "Quest Log.$"

CharacterQuest_EventScript_Winona_Text_0:
# 315 "data/scripts/character_quests.pory"
	.string "The Altarianite awaits in your Quest\n"
	.string "Log.\p"
	.string "Take it when you are ready. The sky\n"
	.string "never resents a careful beginning.$"

CharacterQuest_EventScript_Winona_Text_1:
# 321 "data/scripts/character_quests.pory"
	.string "Champion, do you know my first memory\n"
	.string "of Fortree's bridges? I was underneath\l"
	.string "one, refusing to climb.$"

CharacterQuest_EventScript_Winona_Text_2:
# 322 "data/scripts/character_quests.pory"
	.string "People assume I loved heights from\n"
	.string "birth. I learned the sky slowly, beside a\l"
	.string "Swablu that trusted the wind before I\l"
	.string "did.$"

CharacterQuest_EventScript_Winona_Text_3:
# 323 "data/scripts/character_quests.pory"
	.string "Bring a Swablu in your party. I would\n"
	.string "like to pass that first lesson forward.$"

CharacterQuest_EventScript_Winona_Text_4:
# 329 "data/scripts/character_quests.pory"
	.string "Bring a Swablu in your party.\p"
	.string "Do not hurry it into the air. Trust grows\n"
	.string "best when it is invited, not commanded.$"

CharacterQuest_EventScript_Winona_Text_5:
# 333 "data/scripts/character_quests.pory"
	.string "See how it leans before the gust? It\n"
	.string "does not conquer the wind. It listens.$"

CharacterQuest_EventScript_Winona_Text_6:
# 334 "data/scripts/character_quests.pory"
	.string "My first Swablu waited three hours on a\n"
	.string "bridge rail. I finally took one step\l"
	.string "because it refused to take another\l"
	.string "without me.$"

CharacterQuest_EventScript_Winona_Text_7:
# 335 "data/scripts/character_quests.pory"
	.string "An Altarianite is waiting in your Quest\n"
	.string "Log.\p"
	.string "May it honor every quiet moment of\n"
	.string "trust before the grand ascent.$"

CharacterQuest_EventScript_TateAndLiza_Text_0:
# 353 "data/scripts/character_quests.pory"
	.string "Champion! We need an impartial mind.$"

CharacterQuest_EventScript_TateAndLiza_Text_1:
# 354 "data/scripts/character_quests.pory"
	.string "One that isn't currently sharing our\n"
	.string "exact irritation.$"

CharacterQuest_EventScript_TateAndLiza_Text_2:
# 355 "data/scripts/character_quests.pory"
	.string "Everyone says we think as one.$"

CharacterQuest_EventScript_TateAndLiza_Text_3:
# 356 "data/scripts/character_quests.pory"
	.string "Which is flattering until your brother\n"
	.string "eats your dessert and says the\l"
	.string "universe did it.$"

CharacterQuest_EventScript_TateAndLiza_Text_4:
# 357 "data/scripts/character_quests.pory"
	.string "That happened once.$"

CharacterQuest_EventScript_TateAndLiza_Text_5:
# 358 "data/scripts/character_quests.pory"
	.string "Bring Solrock and Lunatone together in\n"
	.string "your party. We want to observe harmony\l"
	.string "without sameness.$"

CharacterQuest_EventScript_TateAndLiza_Text_6:
# 364 "data/scripts/character_quests.pory"
	.string "We need both Solrock--$"

CharacterQuest_EventScript_TateAndLiza_Text_7:
# 365 "data/scripts/character_quests.pory"
	.string "--and Lunatone in your party. Yes, we\n"
	.string "heard ourselves do that.$"

CharacterQuest_EventScript_TateAndLiza_Text_8:
# 369 "data/scripts/character_quests.pory"
	.string "Solrock moves first.$"

CharacterQuest_EventScript_TateAndLiza_Text_9:
# 370 "data/scripts/character_quests.pory"
	.string "Lunatone waits, then answers.\n"
	.string "Different choices. Same orbit.$"

CharacterQuest_EventScript_TateAndLiza_Text_10:
# 371 "data/scripts/character_quests.pory"
	.string "So we don't have to stop understanding\n"
	.string "each other.$"

CharacterQuest_EventScript_TateAndLiza_Text_11:
# 372 "data/scripts/character_quests.pory"
	.string "We just have to stop using it as an alibi\n"
	.string "for dessert.$"

CharacterQuest_EventScript_TateAndLiza_Text_12:
# 373 "data/scripts/character_quests.pory"
	.string "During our last telescope watch, this\n"
	.string "Minior fell into the observatory garden.$"

CharacterQuest_EventScript_TateAndLiza_Text_13:
# 374 "data/scripts/character_quests.pory"
	.string "It needs a partner who understands\n"
	.string "that sharing an orbit is not the same as\l"
	.string "losing yourself.$"

CharacterQuest_EventScript_TateAndLiza_Text_14:
# 383 "data/scripts/character_quests.pory"
	.string "Your party was full, so Minior was sent\n"
	.string "to a Box in your PC!$"

CharacterQuest_EventScript_TateAndLiza_Text_15:
# 385 "data/scripts/character_quests.pory"
	.string "{PLAYER} received Minior from Tate and\n"
	.string "Liza!$"

CharacterQuest_EventScript_Juan_Text_0:
# 404 "data/scripts/character_quests.pory"
	.string "Ah, Champion! I am judging a beauty\n"
	.string "exhibition, and Wallace has accused my\l"
	.string "standards of being 'a chandelier with\l"
	.string "opinions.'$"

CharacterQuest_EventScript_Juan_Text_1:
# 405 "data/scripts/character_quests.pory"
	.string "He learned drama from me. Restraint,\n"
	.string "apparently, from someone else.$"

CharacterQuest_EventScript_Juan_Text_2:
# 406 "data/scripts/character_quests.pory"
	.string "Bring me a Feebas. I want the audience\n"
	.string "to recognize beauty before applause\l"
	.string "teaches them where to look.$"

CharacterQuest_EventScript_Juan_Text_3:
# 408 "data/scripts/character_quests.pory"
	.string "Have it in your party. This is not an\n"
	.string "audition--though tasteful lighting\l"
	.string "never hurts.$"

CharacterQuest_EventScript_Juan_Text_4:
# 413 "data/scripts/character_quests.pory"
	.string "Bring a Feebas in your party.\p"
	.string "Beauty is patient, my friend. My\n"
	.string "stagehands are less so, but they will\l"
	.string "learn.$"

CharacterQuest_EventScript_Juan_Text_5:
# 417 "data/scripts/character_quests.pory"
	.string "Observe! Uneven fins, humble scales,\n"
	.string "and a gaze utterly unconcerned with my\l"
	.string "lighting.$"

CharacterQuest_EventScript_Juan_Text_6:
# 418 "data/scripts/character_quests.pory"
	.string "Wallace once brought me a Feebas and\n"
	.string "asked when it would become beautiful. I\l"
	.string "told him the question was already late.$"

CharacterQuest_EventScript_Juan_Text_7:
# 419 "data/scripts/character_quests.pory"
	.string "This Egg is from a Feebas with a rare,\n"
	.string "radiant color. Raise it without ever\l"
	.string "asking it to perform for admiration.$"

CharacterQuest_EventScript_Juan_Text_8:
# 433 "data/scripts/character_quests.pory"
	.string "Your party was full, so the radiant\n"
	.string "Feebas Egg was sent to a Box in your PC.$"

CharacterQuest_EventScript_Juan_Text_9:
# 437 "data/scripts/character_quests.pory"
	.string "{PLAYER} received a radiant Feebas Egg\n"
	.string "from Juan!$"

CharacterQuest_EventScript_NoRoomForEgg_Text_0:
# 445 "data/scripts/character_quests.pory"
	.string "Your party and every PC Box are full.\n"
	.string "Make room for the Egg, then return.$"

CharacterQuest_EventScript_NoRoomForPokemon_Text_0:
# 451 "data/scripts/character_quests.pory"
	.string "Your party and every PC Box are full.\n"
	.string "Make room for the Pokémon, then return.$"
