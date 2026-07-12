# 1 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_MapScripts::
# 2 "data/maps/LavaridgeTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
# 3 "data/maps/LavaridgeTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
# 4 "data/maps/LavaridgeTown/scripts.pory"
	.byte 0
# 5 "data/maps/LavaridgeTown/scripts.pory"

# 6 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_OnTransition:
# 7 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_VISITED_LAVARIDGE_TOWN
# 8 "data/maps/LavaridgeTown/scripts.pory"
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
# 9 "data/maps/LavaridgeTown/scripts.pory"
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
# 10 "data/maps/LavaridgeTown/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 11 "data/maps/LavaridgeTown/scripts.pory"
	call Common_EventScript_SetupRivalOnBikeGfxId
# 12 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
# 13 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
# 14 "data/maps/LavaridgeTown/scripts.pory"
	end
# 15 "data/maps/LavaridgeTown/scripts.pory"

# 16 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
# 17 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
# 18 "data/maps/LavaridgeTown/scripts.pory"
	return
# 19 "data/maps/LavaridgeTown/scripts.pory"

# 20 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_CheckSetRivalPos::
# 21 "data/maps/LavaridgeTown/scripts.pory"
	getplayerxy VAR_0x8004, VAR_0x8005
# 22 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_0x8004, 9, LavaridgeTown_EventScript_SetRivalPos
# 23 "data/maps/LavaridgeTown/scripts.pory"
	return
# 24 "data/maps/LavaridgeTown/scripts.pory"

# 25 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_SetRivalPos::
# 26 "data/maps/LavaridgeTown/scripts.pory"
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL, 11, 9
# 27 "data/maps/LavaridgeTown/scripts.pory"
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL_ON_BIKE, 9, 8
# 28 "data/maps/LavaridgeTown/scripts.pory"
	setobjectmovementtype LOCALID_LAVARIDGE_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
# 29 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
# 30 "data/maps/LavaridgeTown/scripts.pory"
	return
# 31 "data/maps/LavaridgeTown/scripts.pory"

# 32 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ShowMtChimneyTrainers::
# 33 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
# 34 "data/maps/LavaridgeTown/scripts.pory"
	return
# 35 "data/maps/LavaridgeTown/scripts.pory"

# 36 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HideMapNamePopup::
# 37 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 38 "data/maps/LavaridgeTown/scripts.pory"
	return
# 39 "data/maps/LavaridgeTown/scripts.pory"

# 40 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_OnFrame:
# 41 "data/maps/LavaridgeTown/scripts.pory"
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
# 42 "data/maps/LavaridgeTown/scripts.pory"
	.2byte 0
# 43 "data/maps/LavaridgeTown/scripts.pory"

# 44 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalGiveGoGoggles::
# 45 "data/maps/LavaridgeTown/scripts.pory"
	lockall
# 46 "data/maps/LavaridgeTown/scripts.pory"
	getplayerxy VAR_0x8008, VAR_0x8009
# 47 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
# 48 "data/maps/LavaridgeTown/scripts.pory"
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
# 49 "data/maps/LavaridgeTown/scripts.pory"
	delay 20
# 50 "data/maps/LavaridgeTown/scripts.pory"
	checkplayergender
# 51 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
# 52 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
# 53 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
# 54 "data/maps/LavaridgeTown/scripts.pory"
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
# 55 "data/maps/LavaridgeTown/scripts.pory"
	checkplayergender
# 56 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
# 57 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
# 58 "data/maps/LavaridgeTown/scripts.pory"
	end
# 59 "data/maps/LavaridgeTown/scripts.pory"

# 60 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_MayGiveGoGoggles::
# 61 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
# 62 "data/maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_GO_GOGGLES
# 63 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_GO_GOGGLES
# 64 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
# 65 "data/maps/LavaridgeTown/scripts.pory"
	goto LavaridgeTown_EventScript_RivalExit
# 66 "data/maps/LavaridgeTown/scripts.pory"
	end
# 67 "data/maps/LavaridgeTown/scripts.pory"

# 68 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_BrendanGiveGoGoggles::
# 69 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
# 70 "data/maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_GO_GOGGLES
# 71 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_GO_GOGGLES
# 72 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
# 73 "data/maps/LavaridgeTown/scripts.pory"
	goto LavaridgeTown_EventScript_RivalExit
# 74 "data/maps/LavaridgeTown/scripts.pory"
	end
# 75 "data/maps/LavaridgeTown/scripts.pory"

# 76 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit::
# 77 "data/maps/LavaridgeTown/scripts.pory"
	closemessage
# 78 "data/maps/LavaridgeTown/scripts.pory"
	removeobject LOCALID_LAVARIDGE_RIVAL
# 79 "data/maps/LavaridgeTown/scripts.pory"
	addobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
# 80 "data/maps/LavaridgeTown/scripts.pory"
	delay 30
# 81 "data/maps/LavaridgeTown/scripts.pory"
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
# 82 "data/maps/LavaridgeTown/scripts.pory"
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
# 83 "data/maps/LavaridgeTown/scripts.pory"
	removeobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
# 84 "data/maps/LavaridgeTown/scripts.pory"
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
# 85 "data/maps/LavaridgeTown/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 86 "data/maps/LavaridgeTown/scripts.pory"
	savebgm MUS_DUMMY
# 87 "data/maps/LavaridgeTown/scripts.pory"
	fadedefaultbgm
# 88 "data/maps/LavaridgeTown/scripts.pory"
	releaseall
# 89 "data/maps/LavaridgeTown/scripts.pory"
	end
# 90 "data/maps/LavaridgeTown/scripts.pory"

# 91 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_PlayMayMusic::
# 92 "data/maps/LavaridgeTown/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 93 "data/maps/LavaridgeTown/scripts.pory"
	return
# 94 "data/maps/LavaridgeTown/scripts.pory"

# 95 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_PlayBrendanMusic::
# 96 "data/maps/LavaridgeTown/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 97 "data/maps/LavaridgeTown/scripts.pory"
	return
# 98 "data/maps/LavaridgeTown/scripts.pory"

# 99 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalNoticePlayer::
# 100 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterUp
# 101 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 102 "data/maps/LavaridgeTown/scripts.pory"
	playse SE_PIN
# 103 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
# 104 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 105 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
# 106 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 107 "data/maps/LavaridgeTown/scripts.pory"
	return
# 108 "data/maps/LavaridgeTown/scripts.pory"

# 109 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExitHerbShop::
# 110 "data/maps/LavaridgeTown/scripts.pory"
	opendoor 12, 15
# 111 "data/maps/LavaridgeTown/scripts.pory"
	waitdooranim
# 112 "data/maps/LavaridgeTown/scripts.pory"
	addobject LOCALID_LAVARIDGE_RIVAL
# 113 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
# 114 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 115 "data/maps/LavaridgeTown/scripts.pory"
	closedoor 12, 15
# 116 "data/maps/LavaridgeTown/scripts.pory"
	waitdooranim
# 117 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterLeft
# 118 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 119 "data/maps/LavaridgeTown/scripts.pory"
	playse SE_PIN
# 120 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
# 121 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 122 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
# 123 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 124 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 125 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 126 "data/maps/LavaridgeTown/scripts.pory"
	return
# 127 "data/maps/LavaridgeTown/scripts.pory"

# 128 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalApproachPlayer1::
# 129 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
# 130 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 131 "data/maps/LavaridgeTown/scripts.pory"
	return
# 132 "data/maps/LavaridgeTown/scripts.pory"

# 133 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalApproachPlayer2::
# 134 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
# 135 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 136 "data/maps/LavaridgeTown/scripts.pory"
	return
# 137 "data/maps/LavaridgeTown/scripts.pory"

# 138 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit1::
# 139 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
# 140 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
# 141 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 142 "data/maps/LavaridgeTown/scripts.pory"
	return
# 143 "data/maps/LavaridgeTown/scripts.pory"

# 144 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_RivalExit2::
# 145 "data/maps/LavaridgeTown/scripts.pory"
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
# 146 "data/maps/LavaridgeTown/scripts.pory"
	waitmovement 0
# 147 "data/maps/LavaridgeTown/scripts.pory"
	return
# 148 "data/maps/LavaridgeTown/scripts.pory"

# 149 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExit2:
# 150 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 151 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 152 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 153 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 154 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 155 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 156 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 157 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 158 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 159 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_up
# 160 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 161 "data/maps/LavaridgeTown/scripts.pory"

# 162 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_PlayerWatchRivalExit:
# 163 "data/maps/LavaridgeTown/scripts.pory"
	delay_16
# 164 "data/maps/LavaridgeTown/scripts.pory"
	delay_8
# 165 "data/maps/LavaridgeTown/scripts.pory"
	walk_in_place_faster_right
# 166 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 167 "data/maps/LavaridgeTown/scripts.pory"

# 168 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExit1:
# 169 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_down
# 170 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 171 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 172 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 173 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 174 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 175 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 176 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 177 "data/maps/LavaridgeTown/scripts.pory"
	walk_fast_right
# 178 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 179 "data/maps/LavaridgeTown/scripts.pory"

# 180 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalApproachPlayer2:
# 181 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 182 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 183 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 184 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 185 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 186 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 187 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 188 "data/maps/LavaridgeTown/scripts.pory"

# 189 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalApproachPlayer1:
# 190 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 191 "data/maps/LavaridgeTown/scripts.pory"
	walk_left
# 192 "data/maps/LavaridgeTown/scripts.pory"
	walk_up
# 193 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 194 "data/maps/LavaridgeTown/scripts.pory"

# 195 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Movement_RivalExitHerbShop:
# 196 "data/maps/LavaridgeTown/scripts.pory"
	walk_down
# 197 "data/maps/LavaridgeTown/scripts.pory"
	step_end
# 198 "data/maps/LavaridgeTown/scripts.pory"

# 199 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsTrigger::
# 200 "data/maps/LavaridgeTown/scripts.pory"
	specialvar VAR_RESULT, GetPlayerFacingDirection
# 201 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
# 202 "data/maps/LavaridgeTown/scripts.pory"
	end
# 203 "data/maps/LavaridgeTown/scripts.pory"

# 204 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_EnteredHotSprings::
# 205 "data/maps/LavaridgeTown/scripts.pory"
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
# 206 "data/maps/LavaridgeTown/scripts.pory"
	end
# 207 "data/maps/LavaridgeTown/scripts.pory"

# 208 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ExpertM::
# 209 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
# 210 "data/maps/LavaridgeTown/scripts.pory"
	end
# 211 "data/maps/LavaridgeTown/scripts.pory"

# 212 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_OldMan::
# 213 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
# 214 "data/maps/LavaridgeTown/scripts.pory"
	end
# 215 "data/maps/LavaridgeTown/scripts.pory"

# 216 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_Twin::
# 217 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
# 218 "data/maps/LavaridgeTown/scripts.pory"
	end
# 219 "data/maps/LavaridgeTown/scripts.pory"

# 220 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsOldWoman1::
# 221 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
# 222 "data/maps/LavaridgeTown/scripts.pory"
	end
# 223 "data/maps/LavaridgeTown/scripts.pory"

# 224 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HotSpringsOldWoman2::
# 225 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
# 226 "data/maps/LavaridgeTown/scripts.pory"
	end
# 227 "data/maps/LavaridgeTown/scripts.pory"

# 228 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ExpertF::
# 229 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
# 230 "data/maps/LavaridgeTown/scripts.pory"
	end
# 231 "data/maps/LavaridgeTown/scripts.pory"

# 232 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_EggWoman::
# 233 "data/maps/LavaridgeTown/scripts.pory"
	lock
# 234 "data/maps/LavaridgeTown/scripts.pory"
	faceplayer
# 235 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
# 236 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
# 237 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
# 238 "data/maps/LavaridgeTown/scripts.pory"
	getpartysize
# 239 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
# 240 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
# 241 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
# 242 "data/maps/LavaridgeTown/scripts.pory"
	playfanfare MUS_OBTAIN_ITEM
# 243 "data/maps/LavaridgeTown/scripts.pory"
	message LavaridgeTown_Text_ReceivedTheEgg
# 244 "data/maps/LavaridgeTown/scripts.pory"
	waitfanfare
# 245 "data/maps/LavaridgeTown/scripts.pory"
	giveegg SPECIES_WYNAUT
# 246 "data/maps/LavaridgeTown/scripts.pory"
	release
# 247 "data/maps/LavaridgeTown/scripts.pory"
	end
# 248 "data/maps/LavaridgeTown/scripts.pory"

# 249 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_ReceivedEgg::
# 250 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
# 251 "data/maps/LavaridgeTown/scripts.pory"
	release
# 252 "data/maps/LavaridgeTown/scripts.pory"
	end
# 253 "data/maps/LavaridgeTown/scripts.pory"

# 254 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_NoRoomForEgg::
# 255 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
# 256 "data/maps/LavaridgeTown/scripts.pory"
	release
# 257 "data/maps/LavaridgeTown/scripts.pory"
	end
# 258 "data/maps/LavaridgeTown/scripts.pory"

# 259 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_DeclineEgg::
# 260 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
# 261 "data/maps/LavaridgeTown/scripts.pory"
	release
# 262 "data/maps/LavaridgeTown/scripts.pory"
	end
# 263 "data/maps/LavaridgeTown/scripts.pory"

# 264 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_TownSign::
# 265 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
# 266 "data/maps/LavaridgeTown/scripts.pory"
	end
# 267 "data/maps/LavaridgeTown/scripts.pory"

# 268 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_GymSign::
# 269 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
# 270 "data/maps/LavaridgeTown/scripts.pory"
	end
# 271 "data/maps/LavaridgeTown/scripts.pory"

# 272 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_EventScript_HerbShopSign::
# 273 "data/maps/LavaridgeTown/scripts.pory"
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
# 274 "data/maps/LavaridgeTown/scripts.pory"
	end
# 275 "data/maps/LavaridgeTown/scripts.pory"

# 276 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_MayNiceBadgesTakeThis:
# 277 "data/maps/LavaridgeTown/scripts.pory"
	.string "MAY: {PLAYER}{KUN}! Long time no see!\p"
# 278 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh? While I visited the hot springs,\n"
# 279 "data/maps/LavaridgeTown/scripts.pory"
	.string "you got the LAVARIDGE GYM BADGE.\p"
# 280 "data/maps/LavaridgeTown/scripts.pory"
	.string "You must have collected\n"
# 281 "data/maps/LavaridgeTown/scripts.pory"
	.string "good POKéMON…\l"
# 282 "data/maps/LavaridgeTown/scripts.pory"
	.string "No, I believe you raised some.\p"
# 283 "data/maps/LavaridgeTown/scripts.pory"
	.string "I guess it would be okay for you to\n"
# 284 "data/maps/LavaridgeTown/scripts.pory"
	.string "have this.$"
# 285 "data/maps/LavaridgeTown/scripts.pory"

# 286 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
# 287 "data/maps/LavaridgeTown/scripts.pory"
	.string "MAY: With those GO-GOGGLES, you'll\n"
# 288 "data/maps/LavaridgeTown/scripts.pory"
	.string "have no trouble getting through the\l"
# 289 "data/maps/LavaridgeTown/scripts.pory"
	.string "desert near ROUTE 111.\p"
# 290 "data/maps/LavaridgeTown/scripts.pory"
	.string "But, wow, {PLAYER}{KUN}…\n"
# 291 "data/maps/LavaridgeTown/scripts.pory"
	.string "Challenging GYMS…\p"
# 292 "data/maps/LavaridgeTown/scripts.pory"
	.string "You're trying hard because you don't\n"
# 293 "data/maps/LavaridgeTown/scripts.pory"
	.string "want to lose to me, I bet!\p"
# 294 "data/maps/LavaridgeTown/scripts.pory"
	.string "{PLAYER}{KUN}, I think I should challenge\n"
# 295 "data/maps/LavaridgeTown/scripts.pory"
	.string "your dad in PETALBURG GYM.\p"
# 296 "data/maps/LavaridgeTown/scripts.pory"
	.string "See you again!$"
# 297 "data/maps/LavaridgeTown/scripts.pory"

# 298 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
# 299 "data/maps/LavaridgeTown/scripts.pory"
	.string "BRENDAN: {PLAYER}, hey, it's been a while.\n"
# 300 "data/maps/LavaridgeTown/scripts.pory"
	.string "How's it going?\p"
# 301 "data/maps/LavaridgeTown/scripts.pory"
	.string "Hmm…\n"
# 302 "data/maps/LavaridgeTown/scripts.pory"
	.string "That's a decent collection of BADGES.\p"
# 303 "data/maps/LavaridgeTown/scripts.pory"
	.string "All right, then.\n"
# 304 "data/maps/LavaridgeTown/scripts.pory"
	.string "You may as well have this.$"
# 305 "data/maps/LavaridgeTown/scripts.pory"

# 306 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
# 307 "data/maps/LavaridgeTown/scripts.pory"
	.string "BRENDAN: Keep those with you if you're\n"
# 308 "data/maps/LavaridgeTown/scripts.pory"
	.string "planning on going into that desert near\l"
# 309 "data/maps/LavaridgeTown/scripts.pory"
	.string "ROUTE 111.\p"
# 310 "data/maps/LavaridgeTown/scripts.pory"
	.string "There should be some POKéMON that\n"
# 311 "data/maps/LavaridgeTown/scripts.pory"
	.string "are exclusively desert-dwellers.\l"
# 312 "data/maps/LavaridgeTown/scripts.pory"
	.string "You might look around for those.\p"
# 313 "data/maps/LavaridgeTown/scripts.pory"
	.string "As for me…\n"
# 314 "data/maps/LavaridgeTown/scripts.pory"
	.string "I'm considering challenging NORMAN,\l"
# 315 "data/maps/LavaridgeTown/scripts.pory"
	.string "the GYM LEADER of PETALBURG.\p"
# 316 "data/maps/LavaridgeTown/scripts.pory"
	.string "Unlike you, {PLAYER}, your dad looks like\n"
# 317 "data/maps/LavaridgeTown/scripts.pory"
	.string "he really is tough.\p"
# 318 "data/maps/LavaridgeTown/scripts.pory"
	.string "See you around!$"
# 319 "data/maps/LavaridgeTown/scripts.pory"

# 320 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HaveEggWillYouTakeIt:
# 321 "data/maps/LavaridgeTown/scripts.pory"
	.string "I have here an EGG.\p"
# 322 "data/maps/LavaridgeTown/scripts.pory"
	.string "I'd hoped to hatch it by covering it in\n"
# 323 "data/maps/LavaridgeTown/scripts.pory"
	.string "hot sand by the hot springs.\l"
# 324 "data/maps/LavaridgeTown/scripts.pory"
	.string "But that doesn't seem to be enough…\p"
# 325 "data/maps/LavaridgeTown/scripts.pory"
	.string "I've heard it would be best if it were\n"
# 326 "data/maps/LavaridgeTown/scripts.pory"
	.string "kept together with POKéMON and\l"
# 327 "data/maps/LavaridgeTown/scripts.pory"
	.string "carried about.\p"
# 328 "data/maps/LavaridgeTown/scripts.pory"
	.string "You are a TRAINER, yes?\n"
# 329 "data/maps/LavaridgeTown/scripts.pory"
	.string "And your POKéMON radiate vitality.\p"
# 330 "data/maps/LavaridgeTown/scripts.pory"
	.string "So, what say you?\n"
# 331 "data/maps/LavaridgeTown/scripts.pory"
	.string "Will you take this EGG to hatch?$"
# 332 "data/maps/LavaridgeTown/scripts.pory"

# 333 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
# 334 "data/maps/LavaridgeTown/scripts.pory"
	.string "Good! I hope you'll walk plenty with\n"
# 335 "data/maps/LavaridgeTown/scripts.pory"
	.string "this here EGG!$"
# 336 "data/maps/LavaridgeTown/scripts.pory"

# 337 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_ReceivedTheEgg:
# 338 "data/maps/LavaridgeTown/scripts.pory"
	.string "{PLAYER} received the EGG.$"
# 339 "data/maps/LavaridgeTown/scripts.pory"

# 340 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_NoRoomForThisEgg:
# 341 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh? You've too many POKéMON.\n"
# 342 "data/maps/LavaridgeTown/scripts.pory"
	.string "There's no room for this EGG…$"
# 343 "data/maps/LavaridgeTown/scripts.pory"

# 344 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_AsYouWishThen:
# 345 "data/maps/LavaridgeTown/scripts.pory"
	.string "As you wish, then…\p"
# 346 "data/maps/LavaridgeTown/scripts.pory"
	.string "If you have a change of heart about\n"
# 347 "data/maps/LavaridgeTown/scripts.pory"
	.string "hatching this EGG, I will be here.$"
# 348 "data/maps/LavaridgeTown/scripts.pory"

# 349 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
# 350 "data/maps/LavaridgeTown/scripts.pory"
	.string "Every so often, an EGG will be found at\n"
# 351 "data/maps/LavaridgeTown/scripts.pory"
	.string "the POKéMON DAY CARE.\p"
# 352 "data/maps/LavaridgeTown/scripts.pory"
	.string "Or at least that's how the rumor goes.$"
# 353 "data/maps/LavaridgeTown/scripts.pory"

# 354 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HotSpringsNeverRunDry:
# 355 "data/maps/LavaridgeTown/scripts.pory"
	.string "We draw as much hot water as we need,\n"
# 356 "data/maps/LavaridgeTown/scripts.pory"
	.string "and yet the hot springs never run dry.\p"
# 357 "data/maps/LavaridgeTown/scripts.pory"
	.string "Isn't it magical?\p"
# 358 "data/maps/LavaridgeTown/scripts.pory"
	.string "These hot springs appear near active\n"
# 359 "data/maps/LavaridgeTown/scripts.pory"
	.string "volcanoes. Veins of water under the\l"
# 360 "data/maps/LavaridgeTown/scripts.pory"
	.string "ground are heated by magma to well up\l"
# 361 "data/maps/LavaridgeTown/scripts.pory"
	.string "as hot springs.$"
# 362 "data/maps/LavaridgeTown/scripts.pory"

# 363 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_PokemonNippedBackside:
# 364 "data/maps/LavaridgeTown/scripts.pory"
	.string "Being buried in this hot sand is…\n"
# 365 "data/maps/LavaridgeTown/scripts.pory"
	.string "Sigh…\p"
# 366 "data/maps/LavaridgeTown/scripts.pory"
	.string "So warm and heavenly…\p"
# 367 "data/maps/LavaridgeTown/scripts.pory"
	.string "Eh? Gyaah! Ouch!\p"
# 368 "data/maps/LavaridgeTown/scripts.pory"
	.string "A POKéMON nipped my backside!$"
# 369 "data/maps/LavaridgeTown/scripts.pory"

# 370 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_OhYouLikeHotSprings:
# 371 "data/maps/LavaridgeTown/scripts.pory"
	.string "Oh, you like hot springs, do you?\p"
# 372 "data/maps/LavaridgeTown/scripts.pory"
	.string "That's surprising for one as young\n"
# 373 "data/maps/LavaridgeTown/scripts.pory"
	.string "as you.$"
# 374 "data/maps/LavaridgeTown/scripts.pory"

# 375 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_BatheInHotSpringsEveryDay:
# 376 "data/maps/LavaridgeTown/scripts.pory"
	.string "I bathe in the hot springs every day.\p"
# 377 "data/maps/LavaridgeTown/scripts.pory"
	.string "I want to become a beautiful and strong\n"
# 378 "data/maps/LavaridgeTown/scripts.pory"
	.string "GYM LEADER like FLANNERY.$"
# 379 "data/maps/LavaridgeTown/scripts.pory"

# 380 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_IfPokemonInHotSprings:
# 381 "data/maps/LavaridgeTown/scripts.pory"
	.string "If people put POKéMON in hot springs,\n"
# 382 "data/maps/LavaridgeTown/scripts.pory"
	.string "it might be seriously strange.\p"
# 383 "data/maps/LavaridgeTown/scripts.pory"
	.string "Why, it might be an electric bath, or\n"
# 384 "data/maps/LavaridgeTown/scripts.pory"
	.string "a bubble bath, or even a lava bath…$"
# 385 "data/maps/LavaridgeTown/scripts.pory"

# 386 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HotSpringsClaims:
# 387 "data/maps/LavaridgeTown/scripts.pory"
	.string "They're claiming that these hot springs\n"
# 388 "data/maps/LavaridgeTown/scripts.pory"
	.string "are good for calming nervous tension,\l"
# 389 "data/maps/LavaridgeTown/scripts.pory"
	.string "relieving aching muscles, solving\l"
# 390 "data/maps/LavaridgeTown/scripts.pory"
	.string "romantic problems, and attracting\l"
# 391 "data/maps/LavaridgeTown/scripts.pory"
	.string "money…$"
# 392 "data/maps/LavaridgeTown/scripts.pory"

# 393 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_TownSign:
# 394 "data/maps/LavaridgeTown/scripts.pory"
	.string "LAVARIDGE TOWN\p"
# 395 "data/maps/LavaridgeTown/scripts.pory"
	.string "“POKéMON CENTER HOT SPRINGS\n"
# 396 "data/maps/LavaridgeTown/scripts.pory"
	.string "An excellent place for relaxing!”$"
# 397 "data/maps/LavaridgeTown/scripts.pory"

# 398 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_GymSign:
# 399 "data/maps/LavaridgeTown/scripts.pory"
	.string "LAVARIDGE TOWN POKéMON GYM\n"
# 400 "data/maps/LavaridgeTown/scripts.pory"
	.string "LEADER: FLANNERY\l"
# 401 "data/maps/LavaridgeTown/scripts.pory"
	.string "“One with a fiery passion that burns!”$"
# 402 "data/maps/LavaridgeTown/scripts.pory"

# 403 "data/maps/LavaridgeTown/scripts.pory"
LavaridgeTown_Text_HerbShopSign:
# 404 "data/maps/LavaridgeTown/scripts.pory"
	.string "POKéMON HERB SHOP\n"
# 405 "data/maps/LavaridgeTown/scripts.pory"
	.string "“Bitter taste--better cure!”$"

GiftMysticTicketScript::
# 410 "data/maps/LavaridgeTown/scripts.pory"
	lock
# 411 "data/maps/LavaridgeTown/scripts.pory"
	faceplayer
# 412 "data/maps/LavaridgeTown/scripts.pory"
	goto_if_set FLAG_RECEIVED_MYSTIC_TICKET, GiftMysticTicketScript_2
# 417 "data/maps/LavaridgeTown/scripts.pory"
	msgbox GiftMysticTicketScript_Text_1
# 420 "data/maps/LavaridgeTown/scripts.pory"
	giveitem ITEM_MYSTIC_TICKET
# 421 "data/maps/LavaridgeTown/scripts.pory"
	startquest QUEST_LUGIA
# 422 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_RECEIVED_MYSTIC_TICKET
# 423 "data/maps/LavaridgeTown/scripts.pory"
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
# 424 "data/maps/LavaridgeTown/scripts.pory"
	msgbox GiftMysticTicketScript_Text_2
# 427 "data/maps/LavaridgeTown/scripts.pory"
	release
	end

GiftMysticTicketScript_2:
# 413 "data/maps/LavaridgeTown/scripts.pory"
	msgbox GiftMysticTicketScript_Text_0
# 414 "data/maps/LavaridgeTown/scripts.pory"
	release
	end


GiftMysticTicketScript_Text_0:
# 413 "data/maps/LavaridgeTown/scripts.pory"
	.string "What are you waiting for? Go!$"

GiftMysticTicketScript_Text_1:
# 417 "data/maps/LavaridgeTown/scripts.pory"
	.string "Ahoy there, mate.\n"
	.string "I've heard whispers of a sacred isle\l"
	.string "where guardians rest.\l"
	.string "Take this Ticket, it's your key to Navel\l"
	.string "Rock!$"

GiftMysticTicketScript_Text_2:
# 424 "data/maps/LavaridgeTown/scripts.pory"
	.string "Take this ticket to Lilycove's ferry.\n"
	.string "Seek the Guardians of Johto…\p"
	.string "Go now, and may the tides guide you!$"
