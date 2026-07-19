RoamingLegendQuests_EventScript_SyncNpcVisibility::
# 5 "data/scripts/roaming_legend_quests.pory"
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_LUGIA
# 6 "data/scripts/roaming_legend_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RoamingLegendQuests_EventScript_SyncNpcVisibility_2
# 9 "data/scripts/roaming_legend_quests.pory"
	setflag FLAG_HIDE_ROAMING_LEGEND_QUEST_GIVERS
RoamingLegendQuests_EventScript_SyncNpcVisibility_1:
	return

RoamingLegendQuests_EventScript_SyncNpcVisibility_2:
# 7 "data/scripts/roaming_legend_quests.pory"
	clearflag FLAG_HIDE_ROAMING_LEGEND_QUEST_GIVERS
	goto RoamingLegendQuests_EventScript_SyncNpcVisibility_1


RoamingLegendQuests_EventScript_Articuno::
# 15 "data/scripts/roaming_legend_quests.pory"
	lock
# 16 "data/scripts/roaming_legend_quests.pory"
	faceplayer
# 17 "data/scripts/roaming_legend_quests.pory"
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ARTICUNO
# 18 "data/scripts/roaming_legend_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RoamingLegendQuests_EventScript_Articuno_2
# 23 "data/scripts/roaming_legend_quests.pory"
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_ARTICUNO
# 24 "data/scripts/roaming_legend_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RoamingLegendQuests_EventScript_Articuno_5
# 29 "data/scripts/roaming_legend_quests.pory"
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_ARTICUNO
# 30 "data/scripts/roaming_legend_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RoamingLegendQuests_EventScript_Articuno_8
# 35 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Articuno_Text_3
# 36 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Articuno_Text_4
# 37 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Articuno_Text_5
# 38 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Articuno_Text_6
# 39 "data/scripts/roaming_legend_quests.pory"
	setvar VAR_0x8004, SPECIES_ARTICUNO
# 40 "data/scripts/roaming_legend_quests.pory"
	setvar VAR_0x8005, 60
# 41 "data/scripts/roaming_legend_quests.pory"
	special TryAddRoamerFromScript
# 42 "data/scripts/roaming_legend_quests.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RoamingLegendQuests_EventScript_Articuno_11
RoamingLegendQuests_EventScript_Articuno_10:
# 45 "data/scripts/roaming_legend_quests.pory"
	startquest QUEST_ARTICUNO
# 46 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Articuno_Text_7
# 47 "data/scripts/roaming_legend_quests.pory"
	release
	end

RoamingLegendQuests_EventScript_Articuno_2:
# 19 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Articuno_Text_0
# 20 "data/scripts/roaming_legend_quests.pory"
	release
	end

RoamingLegendQuests_EventScript_Articuno_5:
# 25 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Articuno_Text_1
# 26 "data/scripts/roaming_legend_quests.pory"
	release
	end

RoamingLegendQuests_EventScript_Articuno_8:
# 31 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Articuno_Text_2
# 32 "data/scripts/roaming_legend_quests.pory"
	release
	end

RoamingLegendQuests_EventScript_Articuno_11:
# 43 "data/scripts/roaming_legend_quests.pory"
	goto RoamingLegendQuests_EventScript_NoRoamerRoom
	goto RoamingLegendQuests_EventScript_Articuno_10


RoamingLegendQuests_EventScript_Zapdos::
# 52 "data/scripts/roaming_legend_quests.pory"
	lock
# 53 "data/scripts/roaming_legend_quests.pory"
	faceplayer
# 54 "data/scripts/roaming_legend_quests.pory"
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ZAPDOS
# 55 "data/scripts/roaming_legend_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RoamingLegendQuests_EventScript_Zapdos_2
# 60 "data/scripts/roaming_legend_quests.pory"
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_ZAPDOS
# 61 "data/scripts/roaming_legend_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RoamingLegendQuests_EventScript_Zapdos_5
# 66 "data/scripts/roaming_legend_quests.pory"
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_ZAPDOS
# 67 "data/scripts/roaming_legend_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RoamingLegendQuests_EventScript_Zapdos_8
# 72 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Zapdos_Text_3
# 73 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Zapdos_Text_4
# 74 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Zapdos_Text_5
# 75 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Zapdos_Text_6
# 76 "data/scripts/roaming_legend_quests.pory"
	setvar VAR_0x8004, SPECIES_ZAPDOS
# 77 "data/scripts/roaming_legend_quests.pory"
	setvar VAR_0x8005, 60
# 78 "data/scripts/roaming_legend_quests.pory"
	special TryAddRoamerFromScript
# 79 "data/scripts/roaming_legend_quests.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RoamingLegendQuests_EventScript_Zapdos_11
RoamingLegendQuests_EventScript_Zapdos_10:
# 82 "data/scripts/roaming_legend_quests.pory"
	startquest QUEST_ZAPDOS
# 83 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Zapdos_Text_7
# 84 "data/scripts/roaming_legend_quests.pory"
	release
	end

RoamingLegendQuests_EventScript_Zapdos_2:
# 56 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Zapdos_Text_0
# 57 "data/scripts/roaming_legend_quests.pory"
	release
	end

RoamingLegendQuests_EventScript_Zapdos_5:
# 62 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Zapdos_Text_1
# 63 "data/scripts/roaming_legend_quests.pory"
	release
	end

RoamingLegendQuests_EventScript_Zapdos_8:
# 68 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Zapdos_Text_2
# 69 "data/scripts/roaming_legend_quests.pory"
	release
	end

RoamingLegendQuests_EventScript_Zapdos_11:
# 80 "data/scripts/roaming_legend_quests.pory"
	goto RoamingLegendQuests_EventScript_NoRoamerRoom
	goto RoamingLegendQuests_EventScript_Zapdos_10


RoamingLegendQuests_EventScript_Moltres::
# 89 "data/scripts/roaming_legend_quests.pory"
	lock
# 90 "data/scripts/roaming_legend_quests.pory"
	faceplayer
# 91 "data/scripts/roaming_legend_quests.pory"
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_MOLTRES
# 92 "data/scripts/roaming_legend_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RoamingLegendQuests_EventScript_Moltres_2
# 97 "data/scripts/roaming_legend_quests.pory"
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_MOLTRES
# 98 "data/scripts/roaming_legend_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RoamingLegendQuests_EventScript_Moltres_5
# 103 "data/scripts/roaming_legend_quests.pory"
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_MOLTRES
# 104 "data/scripts/roaming_legend_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RoamingLegendQuests_EventScript_Moltres_8
# 109 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Moltres_Text_3
# 110 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Moltres_Text_4
# 111 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Moltres_Text_5
# 112 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Moltres_Text_6
# 113 "data/scripts/roaming_legend_quests.pory"
	setvar VAR_0x8004, SPECIES_MOLTRES
# 114 "data/scripts/roaming_legend_quests.pory"
	setvar VAR_0x8005, 60
# 115 "data/scripts/roaming_legend_quests.pory"
	special TryAddRoamerFromScript
# 116 "data/scripts/roaming_legend_quests.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RoamingLegendQuests_EventScript_Moltres_11
RoamingLegendQuests_EventScript_Moltres_10:
# 119 "data/scripts/roaming_legend_quests.pory"
	startquest QUEST_MOLTRES
# 120 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Moltres_Text_7
# 121 "data/scripts/roaming_legend_quests.pory"
	release
	end

RoamingLegendQuests_EventScript_Moltres_2:
# 93 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Moltres_Text_0
# 94 "data/scripts/roaming_legend_quests.pory"
	release
	end

RoamingLegendQuests_EventScript_Moltres_5:
# 99 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Moltres_Text_1
# 100 "data/scripts/roaming_legend_quests.pory"
	release
	end

RoamingLegendQuests_EventScript_Moltres_8:
# 105 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Moltres_Text_2
# 106 "data/scripts/roaming_legend_quests.pory"
	release
	end

RoamingLegendQuests_EventScript_Moltres_11:
# 117 "data/scripts/roaming_legend_quests.pory"
	goto RoamingLegendQuests_EventScript_NoRoamerRoom
	goto RoamingLegendQuests_EventScript_Moltres_10


RoamingLegendQuests_EventScript_Raikou::
# 126 "data/scripts/roaming_legend_quests.pory"
	lock
# 127 "data/scripts/roaming_legend_quests.pory"
	faceplayer
# 128 "data/scripts/roaming_legend_quests.pory"
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_RAIKOU
# 129 "data/scripts/roaming_legend_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RoamingLegendQuests_EventScript_Raikou_2
# 134 "data/scripts/roaming_legend_quests.pory"
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_RAIKOU
# 135 "data/scripts/roaming_legend_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RoamingLegendQuests_EventScript_Raikou_5
# 140 "data/scripts/roaming_legend_quests.pory"
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_RAIKOU
# 141 "data/scripts/roaming_legend_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RoamingLegendQuests_EventScript_Raikou_8
# 146 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Raikou_Text_3
# 147 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Raikou_Text_4
# 148 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Raikou_Text_5
# 149 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Raikou_Text_6
# 150 "data/scripts/roaming_legend_quests.pory"
	setvar VAR_0x8004, SPECIES_RAIKOU
# 151 "data/scripts/roaming_legend_quests.pory"
	setvar VAR_0x8005, 60
# 152 "data/scripts/roaming_legend_quests.pory"
	special TryAddRoamerFromScript
# 153 "data/scripts/roaming_legend_quests.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RoamingLegendQuests_EventScript_Raikou_11
RoamingLegendQuests_EventScript_Raikou_10:
# 156 "data/scripts/roaming_legend_quests.pory"
	startquest QUEST_RAIKOU
# 157 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Raikou_Text_7
# 158 "data/scripts/roaming_legend_quests.pory"
	release
	end

RoamingLegendQuests_EventScript_Raikou_2:
# 130 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Raikou_Text_0
# 131 "data/scripts/roaming_legend_quests.pory"
	release
	end

RoamingLegendQuests_EventScript_Raikou_5:
# 136 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Raikou_Text_1
# 137 "data/scripts/roaming_legend_quests.pory"
	release
	end

RoamingLegendQuests_EventScript_Raikou_8:
# 142 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Raikou_Text_2
# 143 "data/scripts/roaming_legend_quests.pory"
	release
	end

RoamingLegendQuests_EventScript_Raikou_11:
# 154 "data/scripts/roaming_legend_quests.pory"
	goto RoamingLegendQuests_EventScript_NoRoamerRoom
	goto RoamingLegendQuests_EventScript_Raikou_10


RoamingLegendQuests_EventScript_Entei::
# 163 "data/scripts/roaming_legend_quests.pory"
	lock
# 164 "data/scripts/roaming_legend_quests.pory"
	faceplayer
# 165 "data/scripts/roaming_legend_quests.pory"
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ENTEI
# 166 "data/scripts/roaming_legend_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RoamingLegendQuests_EventScript_Entei_2
# 171 "data/scripts/roaming_legend_quests.pory"
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_ENTEI
# 172 "data/scripts/roaming_legend_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RoamingLegendQuests_EventScript_Entei_5
# 177 "data/scripts/roaming_legend_quests.pory"
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_ENTEI
# 178 "data/scripts/roaming_legend_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RoamingLegendQuests_EventScript_Entei_8
# 183 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Entei_Text_3
# 184 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Entei_Text_4
# 185 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Entei_Text_5
# 186 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Entei_Text_6
# 187 "data/scripts/roaming_legend_quests.pory"
	setvar VAR_0x8004, SPECIES_ENTEI
# 188 "data/scripts/roaming_legend_quests.pory"
	setvar VAR_0x8005, 60
# 189 "data/scripts/roaming_legend_quests.pory"
	special TryAddRoamerFromScript
# 190 "data/scripts/roaming_legend_quests.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RoamingLegendQuests_EventScript_Entei_11
RoamingLegendQuests_EventScript_Entei_10:
# 193 "data/scripts/roaming_legend_quests.pory"
	startquest QUEST_ENTEI
# 194 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Entei_Text_7
# 195 "data/scripts/roaming_legend_quests.pory"
	release
	end

RoamingLegendQuests_EventScript_Entei_2:
# 167 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Entei_Text_0
# 168 "data/scripts/roaming_legend_quests.pory"
	release
	end

RoamingLegendQuests_EventScript_Entei_5:
# 173 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Entei_Text_1
# 174 "data/scripts/roaming_legend_quests.pory"
	release
	end

RoamingLegendQuests_EventScript_Entei_8:
# 179 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Entei_Text_2
# 180 "data/scripts/roaming_legend_quests.pory"
	release
	end

RoamingLegendQuests_EventScript_Entei_11:
# 191 "data/scripts/roaming_legend_quests.pory"
	goto RoamingLegendQuests_EventScript_NoRoamerRoom
	goto RoamingLegendQuests_EventScript_Entei_10


RoamingLegendQuests_EventScript_Suicune::
# 200 "data/scripts/roaming_legend_quests.pory"
	lock
# 201 "data/scripts/roaming_legend_quests.pory"
	faceplayer
# 202 "data/scripts/roaming_legend_quests.pory"
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_SUICUNE
# 203 "data/scripts/roaming_legend_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RoamingLegendQuests_EventScript_Suicune_2
# 208 "data/scripts/roaming_legend_quests.pory"
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_SUICUNE
# 209 "data/scripts/roaming_legend_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RoamingLegendQuests_EventScript_Suicune_5
# 214 "data/scripts/roaming_legend_quests.pory"
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_SUICUNE
# 215 "data/scripts/roaming_legend_quests.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RoamingLegendQuests_EventScript_Suicune_8
# 220 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Suicune_Text_3
# 221 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Suicune_Text_4
# 222 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Suicune_Text_5
# 223 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Suicune_Text_6
# 224 "data/scripts/roaming_legend_quests.pory"
	setvar VAR_0x8004, SPECIES_SUICUNE
# 225 "data/scripts/roaming_legend_quests.pory"
	setvar VAR_0x8005, 60
# 226 "data/scripts/roaming_legend_quests.pory"
	special TryAddRoamerFromScript
# 227 "data/scripts/roaming_legend_quests.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq RoamingLegendQuests_EventScript_Suicune_11
RoamingLegendQuests_EventScript_Suicune_10:
# 230 "data/scripts/roaming_legend_quests.pory"
	startquest QUEST_SUICUNE
# 231 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Suicune_Text_7
# 232 "data/scripts/roaming_legend_quests.pory"
	release
	end

RoamingLegendQuests_EventScript_Suicune_2:
# 204 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Suicune_Text_0
# 205 "data/scripts/roaming_legend_quests.pory"
	release
	end

RoamingLegendQuests_EventScript_Suicune_5:
# 210 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Suicune_Text_1
# 211 "data/scripts/roaming_legend_quests.pory"
	release
	end

RoamingLegendQuests_EventScript_Suicune_8:
# 216 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_Suicune_Text_2
# 217 "data/scripts/roaming_legend_quests.pory"
	release
	end

RoamingLegendQuests_EventScript_Suicune_11:
# 228 "data/scripts/roaming_legend_quests.pory"
	goto RoamingLegendQuests_EventScript_NoRoamerRoom
	goto RoamingLegendQuests_EventScript_Suicune_10


RoamingLegendQuests_EventScript_NoRoamerRoom::
# 237 "data/scripts/roaming_legend_quests.pory"
	msgbox RoamingLegendQuests_EventScript_NoRoamerRoom_Text_0
# 238 "data/scripts/roaming_legend_quests.pory"
	release
	end


RoamingLegendQuests_EventScript_Articuno_Text_0:
# 19 "data/scripts/roaming_legend_quests.pory"
	.string "Winter crossed a tropical sea and found\n"
	.string "a Trainer it would follow.\p"
	.string "Articuno is no tame thing--but when\n"
	.string "the air turns still, I think it is\l"
	.string "listening for you.$"

RoamingLegendQuests_EventScript_Articuno_Text_1:
# 25 "data/scripts/roaming_legend_quests.pory"
	.string "The Glalitite is waiting in your Quest\n"
	.string "Log.\p"
	.string "It formed inside our frost gauge the\n"
	.string "instant Articuno accepted your Poké\l"
	.string "Ball.$"

RoamingLegendQuests_EventScript_Articuno_Text_2:
# 31 "data/scripts/roaming_legend_quests.pory"
	.string "Follow the places where the air turns\n"
	.string "glass-clear and wild Pokémon fall\l"
	.string "silent.\p"
	.string "Your Pokédex can track Articuno's\n"
	.string "changing route. Its wounds will carry\l"
	.string "from one encounter to the next.$"

RoamingLegendQuests_EventScript_Articuno_Text_3:
# 35 "data/scripts/roaming_legend_quests.pory"
	.string "When the guardians of Navel Rock cried\n"
	.string "across the sea, every needle in my polar\l"
	.string "instruments turned toward Hoenn.$"

RoamingLegendQuests_EventScript_Articuno_Text_4:
# 36 "data/scripts/roaming_legend_quests.pory"
	.string "Then came a silence colder than snow.\n"
	.string "Kanto's mountain rescuers know that\l"
	.string "silence: Articuno, the white wing of\l"
	.string "winter.$"

RoamingLegendQuests_EventScript_Articuno_Text_5:
# 37 "data/scripts/roaming_legend_quests.pory"
	.string "Stories say it appears before travelers\n"
	.string "lost on icy peaks. A sweep of its wings\l"
	.string "freezes the moisture in the air, and\l"
	.string "snow falls from a clear sky.$"

RoamingLegendQuests_EventScript_Articuno_Text_6:
# 38 "data/scripts/roaming_legend_quests.pory"
	.string "It has begun circling Hoenn's cold\n"
	.string "fronts. It will not roost for a cage or a\l"
	.string "camera--but it may answer a Champion.$"

RoamingLegendQuests_EventScript_Articuno_Text_7:
# 46 "data/scripts/roaming_legend_quests.pory"
	.string "Articuno is now roaming Hoenn. Track\n"
	.string "the moving habitat in your Pokédex,\l"
	.string "then catch the winter bird.$"

RoamingLegendQuests_EventScript_Zapdos_Text_0:
# 56 "data/scripts/roaming_legend_quests.pory"
	.string "The harbor lamps still flicker when\n"
	.string "Zapdos crosses the mainland.\p"
	.string "Now the pattern bends toward wherever\n"
	.string "you happen to be. Funny thing about\l"
	.string "living thunder--it remembers.$"

RoamingLegendQuests_EventScript_Zapdos_Text_1:
# 62 "data/scripts/roaming_legend_quests.pory"
	.string "The Ampharosite is waiting in your\n"
	.string "Quest Log.\p"
	.string "Its crystal lattice holds the same\n"
	.string "clean frequency I recorded from\l"
	.string "Zapdos's wings.$"

RoamingLegendQuests_EventScript_Zapdos_Text_2:
# 68 "data/scripts/roaming_legend_quests.pory"
	.string "Do not chase the loudest thunder.\n"
	.string "Watch for a storm moving against the\l"
	.string "wind.\p"
	.string "Your Pokédex can track Zapdos's route,\n"
	.string "and every encounter will leave it a\l"
	.string "little easier to catch.$"

RoamingLegendQuests_EventScript_Zapdos_Text_3:
# 72 "data/scripts/roaming_legend_quests.pory"
	.string "I maintain Slateport's lightning rods.\n"
	.string "Yesterday, every rod discharged\l"
	.string "upward--from the harbor into one black\l"
	.string "cloud.$"

RoamingLegendQuests_EventScript_Zapdos_Text_4:
# 73 "data/scripts/roaming_legend_quests.pory"
	.string "Old Kanto power-station logs describe\n"
	.string "the same impossible current. Zapdos is\l"
	.string "said to live inside thunderclouds and\l"
	.string "grow stronger when lightning strikes it.$"

RoamingLegendQuests_EventScript_Zapdos_Text_5:
# 74 "data/scripts/roaming_legend_quests.pory"
	.string "Its wings do not merely ride a storm.\n"
	.string "Their crackle can summon one. Sailors\l"
	.string "once mistook that jagged silhouette\l"
	.string "for the storm itself.$"

RoamingLegendQuests_EventScript_Zapdos_Text_6:
# 75 "data/scripts/roaming_legend_quests.pory"
	.string "Navel Rock's awakening drew it across\n"
	.string "the ocean. If you are willing, give all\l"
	.string "that wild power a reason to land.$"

RoamingLegendQuests_EventScript_Zapdos_Text_7:
# 83 "data/scripts/roaming_legend_quests.pory"
	.string "Zapdos is now roaming Hoenn. Track the\n"
	.string "moving storm in your Pokédex, then\l"
	.string "catch the thunder bird.$"

RoamingLegendQuests_EventScript_Moltres_Text_0:
# 93 "data/scripts/roaming_legend_quests.pory"
	.string "The crater has settled, yet one golden\n"
	.string "feather still burns without turning to\l"
	.string "ash.\p"
	.string "Moltres brought Hoenn a new\n"
	.string "spring--and chose you to carry its\l"
	.string "first flame.$"

RoamingLegendQuests_EventScript_Moltres_Text_1:
# 99 "data/scripts/roaming_legend_quests.pory"
	.string "The Charizardite Y is waiting in your\n"
	.string "Quest Log.\p"
	.string "It has been warm since the moment\n"
	.string "Moltres entered your Poké Ball.$"

RoamingLegendQuests_EventScript_Moltres_Text_2:
# 105 "data/scripts/roaming_legend_quests.pory"
	.string "Look for ash that rises instead of\n"
	.string "falling and warm rain on a cloudless\l"
	.string "route.\p"
	.string "Your Pokédex can track Moltres's\n"
	.string "flight. It will remember any wounds when\l"
	.string "it escapes.$"

RoamingLegendQuests_EventScript_Moltres_Text_3:
# 109 "data/scripts/roaming_legend_quests.pory"
	.string "Before dawn, a wounded bird plunged\n"
	.string "into Mt. Chimney. I feared the magma had\l"
	.string "taken it--until the whole crater\l"
	.string "opened like a sunrise.$"

RoamingLegendQuests_EventScript_Moltres_Text_4:
# 110 "data/scripts/roaming_legend_quests.pory"
	.string "The oldest fire pilgrimages tell of\n"
	.string "Moltres restoring itself in a volcano's\l"
	.string "molten heart. Every flap scatters\l"
	.string "embers bright enough to turn night red.$"

RoamingLegendQuests_EventScript_Moltres_Text_5:
# 111 "data/scripts/roaming_legend_quests.pory"
	.string "In cold countries, its return is\n"
	.string "celebrated as the promise of spring. It\l"
	.string "does not end winter by force. It\l"
	.string "reminds the world that winter ends.$"

RoamingLegendQuests_EventScript_Moltres_Text_6:
# 112 "data/scripts/roaming_legend_quests.pory"
	.string "Now that living flame is crossing Hoenn.\n"
	.string "Follow it, and prove that even an\l"
	.string "undying fire can choose companionship.$"

RoamingLegendQuests_EventScript_Moltres_Text_7:
# 120 "data/scripts/roaming_legend_quests.pory"
	.string "Moltres is now roaming Hoenn. Track the\n"
	.string "wandering flame in your Pokédex, then\l"
	.string "catch the herald of spring.$"

RoamingLegendQuests_EventScript_Raikou_Text_0:
# 130 "data/scripts/roaming_legend_quests.pory"
	.string "Our sensors cannot predict Raikou\n"
	.string "anymore. They predict you--and then\l"
	.string "thunder arrives.\p"
	.string "Perhaps being understood was the one\n"
	.string "race it never expected to lose.$"

RoamingLegendQuests_EventScript_Raikou_Text_1:
# 136 "data/scripts/roaming_legend_quests.pory"
	.string "The Manectite is waiting in your Quest\n"
	.string "Log.\p"
	.string "It hums at the exact frequency of the\n"
	.string "thunder that follows Raikou.$"

RoamingLegendQuests_EventScript_Raikou_Text_2:
# 142 "data/scripts/roaming_legend_quests.pory"
	.string "Raikou carries rain clouds on its back\n"
	.string "and crosses a route faster than our\l"
	.string "instruments can refresh.\p"
	.string "Use your Pokédex to track it. Any\n"
	.string "damage or status will remain when it\l"
	.string "flees.$"

RoamingLegendQuests_EventScript_Raikou_Text_3:
# 146 "data/scripts/roaming_legend_quests.pory"
	.string "Ho-Oh and Lugia's return woke\n"
	.string "something in our storm records:\l"
	.string "thunder with a pulse, racing from route\l"
	.string "to route.$"

RoamingLegendQuests_EventScript_Raikou_Text_4:
# 147 "data/scripts/roaming_legend_quests.pory"
	.string "Ecruteak remembers a tower struck by\n"
	.string "lightning, consumed by fire, then\l"
	.string "silenced by rain. Three Pokémon\l"
	.string "perished there, and Ho-Oh restored\l"
	.string "them.$"

RoamingLegendQuests_EventScript_Raikou_Text_5:
# 148 "data/scripts/roaming_legend_quests.pory"
	.string "Raikou bears the terror of the bolt\n"
	.string "that struck the tower. Its roar crashes\l"
	.string "like thunder, and storm clouds seem to\l"
	.string "ride upon its back.$"

RoamingLegendQuests_EventScript_Raikou_Text_6:
# 149 "data/scripts/roaming_legend_quests.pory"
	.string "It has answered Ho-Oh across the sea.\n"
	.string "No machine can keep pace with it. Maybe\l"
	.string "a Champion can.$"

RoamingLegendQuests_EventScript_Raikou_Text_7:
# 157 "data/scripts/roaming_legend_quests.pory"
	.string "Raikou is now roaming Hoenn. Track the\n"
	.string "thunder's heartbeat in your Pokédex,\l"
	.string "then catch it.$"

RoamingLegendQuests_EventScript_Entei_Text_0:
# 167 "data/scripts/roaming_legend_quests.pory"
	.string "Seismographs still jump when Entei\n"
	.string "barks, but the readings no longer\l"
	.string "resemble an eruption.\p"
	.string "They resemble a greeting--an extremely\n"
	.string "loud one.$"

RoamingLegendQuests_EventScript_Entei_Text_1:
# 173 "data/scripts/roaming_legend_quests.pory"
	.string "The Houndoominite is waiting in your\n"
	.string "Quest Log.\p"
	.string "Cozmo says its inner fire stabilized the\n"
	.string "instant Entei accepted you.$"

RoamingLegendQuests_EventScript_Entei_Text_2:
# 179 "data/scripts/roaming_legend_quests.pory"
	.string "Watch the seismographs, not the crater.\n"
	.string "Entei never remains where the earth\l"
	.string "first answers.\p"
	.string "Track it with your Pokédex. Its injuries\n"
	.string "will persist between encounters.$"

RoamingLegendQuests_EventScript_Entei_Text_3:
# 183 "data/scripts/roaming_legend_quests.pory"
	.string "I came from Ecruteak to compare Mt.\n"
	.string "Chimney's tremors with the oldest\l"
	.string "account in our archives.$"

RoamingLegendQuests_EventScript_Entei_Text_4:
# 184 "data/scripts/roaming_legend_quests.pory"
	.string "Lightning struck a sacred tower. Fire\n"
	.string "took it. Rain ended the blaze. Ho-Oh\l"
	.string "descended afterward and returned\l"
	.string "three lost lives to the world.$"

RoamingLegendQuests_EventScript_Entei_Text_5:
# 185 "data/scripts/roaming_legend_quests.pory"
	.string "Entei carries the fire's fury. Legends\n"
	.string "say it is born with a volcano, and that a\l"
	.string "single bark can make another volcano\l"
	.string "erupt.$"

RoamingLegendQuests_EventScript_Entei_Text_6:
# 186 "data/scripts/roaming_legend_quests.pory"
	.string "When Ho-Oh called from Navel Rock, Mt.\n"
	.string "Chimney answered. Entei is running\l"
	.string "now--too powerful to corner, but not\l"
	.string "too proud to test you.$"

RoamingLegendQuests_EventScript_Entei_Text_7:
# 194 "data/scripts/roaming_legend_quests.pory"
	.string "Entei is now roaming Hoenn. Track the\n"
	.string "moving tremors in your Pokédex, then\l"
	.string "catch the volcano beast.$"

RoamingLegendQuests_EventScript_Suicune_Text_0:
# 204 "data/scripts/roaming_legend_quests.pory"
	.string "Where Suicune ran, the sea stayed clear\n"
	.string "for seven mornings.\p"
	.string "The north wind has moved on--yet each\n"
	.string "dawn it circles back toward you.$"

RoamingLegendQuests_EventScript_Suicune_Text_1:
# 210 "data/scripts/roaming_legend_quests.pory"
	.string "The Blastoisinite is waiting in your\n"
	.string "Quest Log.\p"
	.string "It became perfectly clear after\n"
	.string "touching the water Suicune purified.$"

RoamingLegendQuests_EventScript_Suicune_Text_2:
# 216 "data/scripts/roaming_legend_quests.pory"
	.string "Follow clean water where no current\n"
	.string "should have reached. The north wind will\l"
	.string "be just ahead.\p"
	.string "Your Pokédex can track Suicune, and it\n"
	.string "will carry wounds between encounters.$"

RoamingLegendQuests_EventScript_Suicune_Text_3:
# 220 "data/scripts/roaming_legend_quests.pory"
	.string "At sunrise, something ran across the\n"
	.string "ocean without sinking. Beneath each\l"
	.string "step, salt and silt vanished until the\l"
	.string "water shone like glass.$"

RoamingLegendQuests_EventScript_Suicune_Text_4:
# 221 "data/scripts/roaming_legend_quests.pory"
	.string "Johto calls Suicune the north wind\n"
	.string "reborn. It crosses the world searching\l"
	.string "for pure reservoirs--and can cleanse\l"
	.string "fouled water with a touch.$"

RoamingLegendQuests_EventScript_Suicune_Text_5:
# 222 "data/scripts/roaming_legend_quests.pory"
	.string "Ecruteak's legend says rain quenched\n"
	.string "the burning tower before Ho-Oh\l"
	.string "restored the lives lost inside. Suicune\l"
	.string "carries that mercy forward.$"

RoamingLegendQuests_EventScript_Suicune_Text_6:
# 223 "data/scripts/roaming_legend_quests.pory"
	.string "Ho-Oh's cry brought it to Hoenn. It will\n"
	.string "never yield to a trap. Follow the clear\l"
	.string "water, and earn the trust of the aurora\l"
	.string "beast.$"

RoamingLegendQuests_EventScript_Suicune_Text_7:
# 231 "data/scripts/roaming_legend_quests.pory"
	.string "Suicune is now roaming Hoenn. Track the\n"
	.string "north wind in your Pokédex, then catch\l"
	.string "the aurora beast.$"

RoamingLegendQuests_EventScript_NoRoamerRoom_Text_0:
# 237 "data/scripts/roaming_legend_quests.pory"
	.string "Too many legendary Pokémon are already\n"
	.string "roaming Hoenn for this trail to begin\l"
	.string "safely. Catch one, then return.$"
