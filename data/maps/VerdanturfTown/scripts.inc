# 1 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_MapScripts::
# 2 "data/maps/VerdanturfTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
# 3 "data/maps/VerdanturfTown/scripts.pory"
	.byte 0
# 4 "data/maps/VerdanturfTown/scripts.pory"

# 5 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_OnTransition:
# 6 "data/maps/VerdanturfTown/scripts.pory"
	setflag FLAG_VISITED_VERDANTURF_TOWN
# 7 "data/maps/VerdanturfTown/scripts.pory"
	setvar VAR_CONTEST_HALL_STATE, 0
# 8 "data/maps/VerdanturfTown/scripts.pory"
	end
# 9 "data/maps/VerdanturfTown/scripts.pory"

# 10 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_Twin::
# 11 "data/maps/VerdanturfTown/scripts.pory"
	lock
# 12 "data/maps/VerdanturfTown/scripts.pory"
	faceplayer
# 13 "data/maps/VerdanturfTown/scripts.pory"
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
# 14 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
# 15 "data/maps/VerdanturfTown/scripts.pory"
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
# 16 "data/maps/VerdanturfTown/scripts.pory"
	waitmovement 0
# 17 "data/maps/VerdanturfTown/scripts.pory"
	release
# 18 "data/maps/VerdanturfTown/scripts.pory"
	end
# 19 "data/maps/VerdanturfTown/scripts.pory"

# 20 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_TwinTunnelOpen::
# 21 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
# 22 "data/maps/VerdanturfTown/scripts.pory"
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
# 23 "data/maps/VerdanturfTown/scripts.pory"
	waitmovement 0
# 24 "data/maps/VerdanturfTown/scripts.pory"
	release
# 25 "data/maps/VerdanturfTown/scripts.pory"
	end
# 26 "data/maps/VerdanturfTown/scripts.pory"

# 27 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_Man::
# 28 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
# 29 "data/maps/VerdanturfTown/scripts.pory"
	end
# 30 "data/maps/VerdanturfTown/scripts.pory"

# 31 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_Camper::
# 32 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
# 33 "data/maps/VerdanturfTown/scripts.pory"
	end
# 34 "data/maps/VerdanturfTown/scripts.pory"

# 35 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_Boy::
# 36 "data/maps/VerdanturfTown/scripts.pory"
	lock
# 37 "data/maps/VerdanturfTown/scripts.pory"
	faceplayer
# 38 "data/maps/VerdanturfTown/scripts.pory"
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
# 39 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
# 40 "data/maps/VerdanturfTown/scripts.pory"
	release
# 41 "data/maps/VerdanturfTown/scripts.pory"
	end
# 42 "data/maps/VerdanturfTown/scripts.pory"

# 43 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_BoyTunnelOpen::
# 44 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
# 45 "data/maps/VerdanturfTown/scripts.pory"
	release
# 46 "data/maps/VerdanturfTown/scripts.pory"
	end
# 47 "data/maps/VerdanturfTown/scripts.pory"

# 48 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_TownSign::
# 49 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
# 50 "data/maps/VerdanturfTown/scripts.pory"
	end
# 51 "data/maps/VerdanturfTown/scripts.pory"

# 52 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_WandasHouseSign::
# 53 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
# 54 "data/maps/VerdanturfTown/scripts.pory"
	end
# 55 "data/maps/VerdanturfTown/scripts.pory"

# 56 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_BattleTentSign::
# 57 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
# 58 "data/maps/VerdanturfTown/scripts.pory"
	end
# 59 "data/maps/VerdanturfTown/scripts.pory"

# 60 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_EventScript_RusturfTunnelSign::
# 61 "data/maps/VerdanturfTown/scripts.pory"
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
# 62 "data/maps/VerdanturfTown/scripts.pory"
	end
# 63 "data/maps/VerdanturfTown/scripts.pory"

# 64 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_ManTryingToDigTunnel:
# 65 "data/maps/VerdanturfTown/scripts.pory"
	.string "My papa told me.\p"
# 66 "data/maps/VerdanturfTown/scripts.pory"
	.string "He says this tunnel is full of\n"
# 67 "data/maps/VerdanturfTown/scripts.pory"
	.string "timid POKéMON.\p"
# 68 "data/maps/VerdanturfTown/scripts.pory"
	.string "They get all scared of loud noise and\n"
# 69 "data/maps/VerdanturfTown/scripts.pory"
	.string "make a big uproar.\p"
# 70 "data/maps/VerdanturfTown/scripts.pory"
	.string "So they had to stop the big tunnel\n"
# 71 "data/maps/VerdanturfTown/scripts.pory"
	.string "project.\p"
# 72 "data/maps/VerdanturfTown/scripts.pory"
	.string "But there's one man. He's trying to dig\n"
# 73 "data/maps/VerdanturfTown/scripts.pory"
	.string "the tunnel by himself!$"
# 74 "data/maps/VerdanturfTown/scripts.pory"

# 75 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_ManDugTunnelForLove:
# 76 "data/maps/VerdanturfTown/scripts.pory"
	.string "There was a man who dug a tunnel for\n"
# 77 "data/maps/VerdanturfTown/scripts.pory"
	.string "a lady he loved.\p"
# 78 "data/maps/VerdanturfTown/scripts.pory"
	.string "I don't really get it, but hey!$"
# 79 "data/maps/VerdanturfTown/scripts.pory"

# 80 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_AirCleanHere:
# 81 "data/maps/VerdanturfTown/scripts.pory"
	.string "The way the winds blow, volcanic ash\n"
# 82 "data/maps/VerdanturfTown/scripts.pory"
	.string "is never blown in this direction.\p"
# 83 "data/maps/VerdanturfTown/scripts.pory"
	.string "The air is clean and delicious here.\n"
# 84 "data/maps/VerdanturfTown/scripts.pory"
	.string "Living here should do wonders for even\l"
# 85 "data/maps/VerdanturfTown/scripts.pory"
	.string "frail and sickly people.$"
# 86 "data/maps/VerdanturfTown/scripts.pory"

# 87 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_MakeBattleTentDebut:
# 88 "data/maps/VerdanturfTown/scripts.pory"
	.string "My POKéMON and I, we've been riding\n"
# 89 "data/maps/VerdanturfTown/scripts.pory"
	.string "a hot winning streak.\p"
# 90 "data/maps/VerdanturfTown/scripts.pory"
	.string "So I decided to make my BATTLE TENT\n"
# 91 "data/maps/VerdanturfTown/scripts.pory"
	.string "debut in this town.$"
# 92 "data/maps/VerdanturfTown/scripts.pory"

# 93 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_GuyTryingToBustThroughCave:
# 94 "data/maps/VerdanturfTown/scripts.pory"
	.string "Did you see the cave next to the\n"
# 95 "data/maps/VerdanturfTown/scripts.pory"
	.string "POKéMON MART?\p"
# 96 "data/maps/VerdanturfTown/scripts.pory"
	.string "There's a guy in there who's trying to\n"
# 97 "data/maps/VerdanturfTown/scripts.pory"
	.string "bust up boulders so he can bust out\l"
# 98 "data/maps/VerdanturfTown/scripts.pory"
	.string "through to the other side.\p"
# 99 "data/maps/VerdanturfTown/scripts.pory"
	.string "It'd be great if we could go through…\n"
# 100 "data/maps/VerdanturfTown/scripts.pory"
	.string "It'll make it easy to visit RUSTBORO.$"
# 101 "data/maps/VerdanturfTown/scripts.pory"

# 102 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_EasyToGetToRustboroNow:
# 103 "data/maps/VerdanturfTown/scripts.pory"
	.string "That cave next to the POKéMON MART\n"
# 104 "data/maps/VerdanturfTown/scripts.pory"
	.string "is now a tunnel to the other side.\p"
# 105 "data/maps/VerdanturfTown/scripts.pory"
	.string "It's great--it's easy to go shop for\n"
# 106 "data/maps/VerdanturfTown/scripts.pory"
	.string "new DEVON products in RUSTBORO now.$"
# 107 "data/maps/VerdanturfTown/scripts.pory"

# 108 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_TownSign:
# 109 "data/maps/VerdanturfTown/scripts.pory"
	.string "VERDANTURF TOWN\p"
# 110 "data/maps/VerdanturfTown/scripts.pory"
	.string "“The windswept highlands with the\n"
# 111 "data/maps/VerdanturfTown/scripts.pory"
	.string "sweet fragrance of grass.”$"
# 112 "data/maps/VerdanturfTown/scripts.pory"

# 113 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_WandasHouse:
# 114 "data/maps/VerdanturfTown/scripts.pory"
	.string "WANDA'S HOUSE$"
# 115 "data/maps/VerdanturfTown/scripts.pory"

# 116 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_BattleTentSign:
# 117 "data/maps/VerdanturfTown/scripts.pory"
	.string "BATTLE TENT VERDANTURF SITE\n"
# 118 "data/maps/VerdanturfTown/scripts.pory"
	.string "“Feast Your Eyes on Battles!”$"
# 119 "data/maps/VerdanturfTown/scripts.pory"

# 120 "data/maps/VerdanturfTown/scripts.pory"
VerdanturfTown_Text_RusturfTunnelSign:
# 121 "data/maps/VerdanturfTown/scripts.pory"
	.string "RUSTURF TUNNEL\n"
# 122 "data/maps/VerdanturfTown/scripts.pory"
	.string "“Linking RUSTBORO and VERDANTURF\p"
# 123 "data/maps/VerdanturfTown/scripts.pory"
	.string "“The tunnel project has been\n"
# 124 "data/maps/VerdanturfTown/scripts.pory"
	.string "canceled.”$"

ShinyPichuEggNPC::
# 129 "data/maps/VerdanturfTown/scripts.pory"
	lock
# 130 "data/maps/VerdanturfTown/scripts.pory"
	faceplayer
# 132 "data/maps/VerdanturfTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_SHINY_PICHU_EGG, ShinyPichuEggNPC_2
# 137 "data/maps/VerdanturfTown/scripts.pory"
	msgbox ShinyPichuEggNPC_Text_1, MSGBOX_YESNO
# 138 "data/maps/VerdanturfTown/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShinyPichuEggNPC_5
# 145 "data/maps/VerdanturfTown/scripts.pory"
	setvar VAR_GIFT_EGG_SPECIES, SPECIES_PICHU
# 146 "data/maps/VerdanturfTown/scripts.pory"
	setvar VAR_GIFT_EGG_SHINY, TRUE
# 147 "data/maps/VerdanturfTown/scripts.pory"
	setvar VAR_GIFT_EGG_MOVE1, MOVE_NONE
# 148 "data/maps/VerdanturfTown/scripts.pory"
	setvar VAR_GIFT_EGG_MOVE2, MOVE_VOLT_TACKLE
# 149 "data/maps/VerdanturfTown/scripts.pory"
	setvar VAR_GIFT_EGG_MOVE3, MOVE_SURF
# 150 "data/maps/VerdanturfTown/scripts.pory"
	setvar VAR_GIFT_EGG_MOVE4, MOVE_FLY
# 151 "data/maps/VerdanturfTown/scripts.pory"
	special GiveCustomEgg
# 152 "data/maps/VerdanturfTown/scripts.pory"
	switch VAR_RESULT
# 154 "data/maps/VerdanturfTown/scripts.pory"
	case MON_CANT_GIVE, ShinyPichuEggNPC_9
# 157 "data/maps/VerdanturfTown/scripts.pory"
	case MON_GIVEN_TO_PC, ShinyPichuEggNPC_10
# 165 "data/maps/VerdanturfTown/scripts.pory"
	setflag FLAG_RECEIVED_SHINY_PICHU_EGG
# 166 "data/maps/VerdanturfTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 167 "data/maps/VerdanturfTown/scripts.pory"
	waitfanfare
# 168 "data/maps/VerdanturfTown/scripts.pory"
	msgbox ShinyPichuEggNPC_Text_5
# 169 "data/maps/VerdanturfTown/scripts.pory"
	startquest QUEST_SHINY_PICHU_EGG
ShinyPichuEggNPC_7:
# 171 "data/maps/VerdanturfTown/scripts.pory"
	release
	end

ShinyPichuEggNPC_2:
# 133 "data/maps/VerdanturfTown/scripts.pory"
	msgbox ShinyPichuEggNPC_Text_0
# 134 "data/maps/VerdanturfTown/scripts.pory"
	release
	end

ShinyPichuEggNPC_5:
# 139 "data/maps/VerdanturfTown/scripts.pory"
	msgbox ShinyPichuEggNPC_Text_2
# 140 "data/maps/VerdanturfTown/scripts.pory"
	release
	end

ShinyPichuEggNPC_9:
# 155 "data/maps/VerdanturfTown/scripts.pory"
	msgbox ShinyPichuEggNPC_Text_3
	goto ShinyPichuEggNPC_7

ShinyPichuEggNPC_10:
# 158 "data/maps/VerdanturfTown/scripts.pory"
	setflag FLAG_RECEIVED_SHINY_PICHU_EGG
# 159 "data/maps/VerdanturfTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 160 "data/maps/VerdanturfTown/scripts.pory"
	waitfanfare
# 161 "data/maps/VerdanturfTown/scripts.pory"
	msgbox ShinyPichuEggNPC_Text_4
# 162 "data/maps/VerdanturfTown/scripts.pory"
	startquest QUEST_SHINY_PICHU_EGG
	goto ShinyPichuEggNPC_7


ShinyPichuEggNPC_Text_0:
# 133 "data/maps/VerdanturfTown/scripts.pory"
	.string "How is that Egg coming along?\p"
	.string "I have a feeling it's going to hatch\n"
	.string "into something truly special.$"

ShinyPichuEggNPC_Text_1:
# 137 "data/maps/VerdanturfTown/scripts.pory"
	.string "Oh! You there! You have a kind face.\p"
	.string "I found this mysterious Egg on my\n"
	.string "travels, but I can't care for it any\l"
	.string "longer.\p"
	.string "Would you look after it for me?$"

ShinyPichuEggNPC_Text_2:
# 139 "data/maps/VerdanturfTown/scripts.pory"
	.string "I understand. I'll keep it safe until\n"
	.string "you're ready for it.$"

ShinyPichuEggNPC_Text_3:
# 155 "data/maps/VerdanturfTown/scripts.pory"
	.string "Hm? You don't have any room for it.\p"
	.string "Come back and see me once you can carry\n"
	.string "it.$"

ShinyPichuEggNPC_Text_4:
# 161 "data/maps/VerdanturfTown/scripts.pory"
	.string "Your party was full, so the Egg was sent\n"
	.string "to a Box in your PC.\p"
	.string "Raise it with love and kindness!$"

ShinyPichuEggNPC_Text_5:
# 168 "data/maps/VerdanturfTown/scripts.pory"
	.string "{PLAYER} received the mysterious Egg!\p"
	.string "Raise it with love and kindness, I have\n"
	.string "a feeling it's special.$"
