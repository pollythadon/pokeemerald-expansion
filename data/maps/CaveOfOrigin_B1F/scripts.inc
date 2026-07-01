# 1 "data/maps/CaveOfOrigin_B1F/scripts.pory"

# 2 "data/maps/CaveOfOrigin_B1F/scripts.pory"
CaveOfOrigin_B1F_MapScripts::
# 3 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.byte 0
# 4 "data/maps/CaveOfOrigin_B1F/scripts.pory"

# 5 "data/maps/CaveOfOrigin_B1F/scripts.pory"
CaveOfOrigin_B1F_EventScript_Wallace::
# 6 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	lock
# 7 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	faceplayer
# 8 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
# 9 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	closemessage
# 10 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_WalkInPlaceFasterUp
# 11 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	waitmovement 0
# 12 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	delay 60
# 13 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	playse SE_PIN
# 14 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_ExclamationMark
# 15 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	waitmovement 0
# 16 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_Delay48
# 17 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	waitmovement 0
# 18 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	delay 30
# 19 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_FacePlayer
# 20 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	waitmovement 0
# 21 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
# 22 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	waitmessage
# 23 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza
# 24 "data/maps/CaveOfOrigin_B1F/scripts.pory"

# 25 "data/maps/CaveOfOrigin_B1F/scripts.pory"
CaveOfOrigin_B1F_EventScript_WheresRayquaza::
# 26 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
# 27 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	switch VAR_RESULT
# 28 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
# 29 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
# 30 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
# 31 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
# 32 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	goto CaveOfOrigin_B1F_EventScript_DontRemember
# 33 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	end
# 34 "data/maps/CaveOfOrigin_B1F/scripts.pory"

# 35 "data/maps/CaveOfOrigin_B1F/scripts.pory"
CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
# 36 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
# 37 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	waitmessage
# 38 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza
# 39 "data/maps/CaveOfOrigin_B1F/scripts.pory"

# 40 "data/maps/CaveOfOrigin_B1F/scripts.pory"
CaveOfOrigin_B1F_EventScript_AtMtPyre::
# 41 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
# 42 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	waitmessage
# 43 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza
# 44 "data/maps/CaveOfOrigin_B1F/scripts.pory"

# 45 "data/maps/CaveOfOrigin_B1F/scripts.pory"
CaveOfOrigin_B1F_EventScript_DontRemember::
# 46 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
# 47 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	waitmessage
# 48 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza
# 49 "data/maps/CaveOfOrigin_B1F/scripts.pory"

# 50 "data/maps/CaveOfOrigin_B1F/scripts.pory"
CaveOfOrigin_B1F_EventScript_AtSkyPillar::
# 51 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
# 52 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	closemessage
# 53 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	playse SE_EXIT
# 54 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 4
# 55 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
# 56 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
# 57 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	removeobject LOCALID_CAVE_OF_ORIGIN_WALLACE
# 58 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
# 59 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 60 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	release
# 61 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	end
# 62 "data/maps/CaveOfOrigin_B1F/scripts.pory"

# 63 "data/maps/CaveOfOrigin_B1F/scripts.pory"
CaveOfOrigin_B1F_Text_WallaceStory:
# 64 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "Ah, so you are {PLAYER}{KUN}?\n"
# 65 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "I've heard tales of your exploits.\p"
# 66 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "My name is WALLACE.\p"
# 67 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "I was once the GYM LEADER of\n"
# 68 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "SOOTOPOLIS, but something came up.\p"
# 69 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "So now, I've entrusted my mentor JUAN\n"
# 70 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "with the GYM's operation.\p"
# 71 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "… … … … … …\n"
# 72 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "… … … … … …\p"
# 73 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "GROUDON and KYOGRE, the two POKéMON\n"
# 74 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "wreaking havoc here, are considered\l"
# 75 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "to be super-ancient POKéMON.\p"
# 76 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "But there aren't just two super-\n"
# 77 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "ancient POKéMON.\p"
# 78 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "There is one more somewhere.\p"
# 79 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "Somewhere, there is a super-\n"
# 80 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "ancient POKéMON named RAYQUAZA.\p"
# 81 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "It's said that it was RAYQUAZA that\n"
# 82 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "becalmed the two combatants in\l"
# 83 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "the distant past.\p"
# 84 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "But even I have no clue as to\n"
# 85 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "RAYQUAZA's whereabouts…$"
# 86 "data/maps/CaveOfOrigin_B1F/scripts.pory"

# 87 "data/maps/CaveOfOrigin_B1F/scripts.pory"
CaveOfOrigin_B1F_Text_WhereIsRayquaza:
# 88 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "WALLACE: {PLAYER}{KUN}, do you perhaps\n"
# 89 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "know where RAYQUAZA is now?\p"
# 90 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "If you do, please tell me.$"
# 91 "data/maps/CaveOfOrigin_B1F/scripts.pory"

# 92 "data/maps/CaveOfOrigin_B1F/scripts.pory"
CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
# 93 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "WALLACE: The CAVE OF ORIGIN?\p"
# 94 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "But that's right here!\n"
# 95 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "I need you to do better than that!\p"
# 96 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "Please, I need you to think about\n"
# 97 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "where RAYQUAZA might be right now.$"
# 98 "data/maps/CaveOfOrigin_B1F/scripts.pory"

# 99 "data/maps/CaveOfOrigin_B1F/scripts.pory"
CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
# 100 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "WALLACE: MT. PYRE?\p"
# 101 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "But when I met the old lady there\n"
# 102 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "earlier, she made no mention of it.\p"
# 103 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "I very much doubt that the old lady\n"
# 104 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "would try to hide something from me…\p"
# 105 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "{PLAYER}{KUN}, could you think about this\n"
# 106 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "more carefully for me?$"
# 107 "data/maps/CaveOfOrigin_B1F/scripts.pory"

# 108 "data/maps/CaveOfOrigin_B1F/scripts.pory"
CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
# 109 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "WALLACE: Huh? You don't remember?\n"
# 110 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "Hmm… That's a problem…\p"
# 111 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "Can't you remember somehow?$"
# 112 "data/maps/CaveOfOrigin_B1F/scripts.pory"

# 113 "data/maps/CaveOfOrigin_B1F/scripts.pory"
CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
# 114 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "WALLACE: The SKY PILLAR?\p"
# 115 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "That's it!\n"
# 116 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "It must be the SKY PILLAR!\p"
# 117 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "{PLAYER}{KUN}, there's not a moment to lose!\n"
# 118 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "We'll head to the SKY PILLAR right away!$"

Legendary_EventScript_DIALGA::
# 124 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	lockall
	checkitem ITEM_ADAMANT_ORB
# 0 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Legendary_EventScript_DIALGA_2
Legendary_EventScript_DIALGA_1:
# 164 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	msgbox Legendary_EventScript_DIALGA_Text_5
# 165 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	release
	end

Legendary_EventScript_DIALGA_2:
# 126 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	msgbox Legendary_EventScript_DIALGA_Text_0
# 127 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	msgbox Legendary_EventScript_DIALGA_Text_1, MSGBOX_YESNO
# 128 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	switch VAR_RESULT
# 129 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	case YES, Legendary_EventScript_DIALGA_5
# 158 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	case NO, Legendary_EventScript_DIALGA_6
	goto Legendary_EventScript_DIALGA_1

Legendary_EventScript_DIALGA_5:
# 130 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	clearflag FLAG_DIALGA_BATTLE
# 131 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	fadescreenswapbuffers FADE_TO_WHITE
# 132 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	delay 40
# 133 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	fadescreenswapbuffers FADE_FROM_WHITE
# 134 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	addobject 3
# 135 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	msgbox Legendary_EventScript_DIALGA_Text_2, MSGBOX_AUTOCLOSE
# 136 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	fadescreenswapbuffers FADE_TO_WHITE
# 137 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	delay 40
# 138 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	fadescreenswapbuffers FADE_FROM_WHITE
# 139 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	msgbox Legendary_EventScript_DIALGA_Text_3, MSGBOX_AUTOCLOSE
# 140 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	playmoncry SPECIES_DIALGA, CRY_MODE_ENCOUNTER
# 141 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	delay 40
# 142 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	waitmoncry
# 143 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	setwildbattle SPECIES_DIALGA, 80
# 144 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 145 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	waitstate
# 146 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 147 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Legendary_EventScript_DIALGA_8
# 149 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Legendary_EventScript_DIALGA_9
# 151 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Legendary_EventScript_DIALGA_10
# 153 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Legendary_EventScript_DIALGA_11
Legendary_EventScript_DIALGA_7:
# 156 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	releaseall
	end

Legendary_EventScript_DIALGA_6:
# 159 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	msgbox Legendary_EventScript_DIALGA_Text_4
# 160 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	release
	end

Legendary_EventScript_DIALGA_8:
# 148 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	call DIALGAWon_or_Caught
	goto Legendary_EventScript_DIALGA_7

Legendary_EventScript_DIALGA_9:
# 150 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	call DIALGAWon_or_Caught
	goto Legendary_EventScript_DIALGA_7

Legendary_EventScript_DIALGA_10:
# 152 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	call DIALGARanAway
	goto Legendary_EventScript_DIALGA_7

Legendary_EventScript_DIALGA_11:
# 154 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	call DIALGARanAway
	goto Legendary_EventScript_DIALGA_7


DIALGAWon_or_Caught::
# 170 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	fadescreenswapbuffers FADE_TO_WHITE
# 171 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	removeobject 3
# 172 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	setflag FLAG_DIALGA_BATTLE
# 173 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	fadescreenswapbuffers FADE_FROM_WHITE
# 174 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	msgbox DIALGAWon_or_Caught_Text_0
	return


DIALGARanAway::
# 179 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	playmoncry SPECIES_DIALGA, CRY_MODE_ENCOUNTER
# 180 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	delay 20
# 181 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	fadescreenswapbuffers FADE_TO_WHITE
# 182 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	removeobject 3
# 183 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	setflag FLAG_DIALGA_BATTLE
# 184 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	fadescreenswapbuffers FADE_FROM_WHITE
# 185 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	msgbox DIALGARanAway_Text_0
	return


Legendary_EventScript_DIALGA_Text_0:
# 126 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "The Adamant Orb is pounding like a\n"
	.string "second heartbeat...$"

Legendary_EventScript_DIALGA_Text_1:
# 127 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "Hold the Orb to the air?$"

Legendary_EventScript_DIALGA_Text_2:
# 135 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "The seconds stop. A clock with no hands\n"
	.string "hangs over everything.$"

Legendary_EventScript_DIALGA_Text_3:
# 139 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "Time itself bows its head to the one who\n"
	.string "rules it.$"

Legendary_EventScript_DIALGA_Text_4:
# 159 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "Not yet. Time will keep.$"

Legendary_EventScript_DIALGA_Text_5:
# 164 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "The air here feels... slow. Like a held\n"
	.string "breath.$"

DIALGAWon_or_Caught_Text_0:
# 174 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "The clock starts again. However much\n"
	.string "time I just lost... I think it was worth\l"
	.string "it.$"

DIALGARanAway_Text_0:
# 185 "data/maps/CaveOfOrigin_B1F/scripts.pory"
	.string "Gone in an instant. To It, my whole life\n"
	.string "is just an instant.$"
