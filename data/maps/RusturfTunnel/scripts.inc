# 1 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_MapScripts::
# 2 "data/maps/RusturfTunnel/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, RusturfTunnel_OnTransition
# 3 "data/maps/RusturfTunnel/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RusturfTunnel_OnFrame
# 4 "data/maps/RusturfTunnel/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, RusturfTunnel_OnResume
# 5 "data/maps/RusturfTunnel/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, RusturfTunnel_OnLoad
# 6 "data/maps/RusturfTunnel/scripts.pory"
	.byte 0
# 7 "data/maps/RusturfTunnel/scripts.pory"

# 8 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_OnFrame:
# 9 "data/maps/RusturfTunnel/scripts.pory"
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 4, RusturfTunnel_EventScript_ClearTunnelScene
# 10 "data/maps/RusturfTunnel/scripts.pory"
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 5, RusturfTunnel_EventScript_ClearTunnelScene
# 11 "data/maps/RusturfTunnel/scripts.pory"
	.2byte 0
# 12 "data/maps/RusturfTunnel/scripts.pory"

# 13 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_OnResume:
# 14 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_ZEKROM_CAVE_STATE, 0, RusturfTunnel_EventScript_CheckHasDnaSplicers
# 15 "data/maps/RusturfTunnel/scripts.pory"
	end
# 16 "data/maps/RusturfTunnel/scripts.pory"

# 17 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_OnLoad:
# 18 "data/maps/RusturfTunnel/scripts.pory"
	call_if_ge VAR_ZEKROM_CAVE_STATE, 2, RusturfTunnel_EventScript_DrawZekromCaveEntrance
# 19 "data/maps/RusturfTunnel/scripts.pory"
	end
# 20 "data/maps/RusturfTunnel/scripts.pory"

# 21 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_OnTransition:
# 22 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_RUSTURF_TUNNEL_STATE, 2, RusturfTunnel_EventScript_SetAquaGruntAndPeekoPos
# 23 "data/maps/RusturfTunnel/scripts.pory"
	end
# 24 "data/maps/RusturfTunnel/scripts.pory"

# 25 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_SetAquaGruntAndPeekoPos::
# 26 "data/maps/RusturfTunnel/scripts.pory"
	setobjectxyperm LOCALID_RUSTURF_TUNNEL_PEEKO, 13, 4
# 27 "data/maps/RusturfTunnel/scripts.pory"
	setobjectxyperm LOCALID_RUSTURF_TUNNEL_GRUNT, 13, 5
# 28 "data/maps/RusturfTunnel/scripts.pory"
	return
# 29 "data/maps/RusturfTunnel/scripts.pory"

# 30 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_Wanda::
# 31 "data/maps/RusturfTunnel/scripts.pory"
	lock
# 32 "data/maps/RusturfTunnel/scripts.pory"
	faceplayer
# 33 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_BoyfriendOnOtherSideOfRock, MSGBOX_DEFAULT
# 34 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 35 "data/maps/RusturfTunnel/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 36 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 37 "data/maps/RusturfTunnel/scripts.pory"
	release
# 38 "data/maps/RusturfTunnel/scripts.pory"
	end
# 39 "data/maps/RusturfTunnel/scripts.pory"

# 40 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandasBoyfriend::
# 41 "data/maps/RusturfTunnel/scripts.pory"
	lock
# 42 "data/maps/RusturfTunnel/scripts.pory"
	faceplayer
# 43 "data/maps/RusturfTunnel/scripts.pory"
	goto_if_set FLAG_TEMP_1, RusturfTunnel_EventScript_AlreadySpokenTo
# 44 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_TEMP_1
# 45 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_WhyCantTheyKeepDigging, MSGBOX_DEFAULT
# 46 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 47 "data/maps/RusturfTunnel/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 48 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 49 "data/maps/RusturfTunnel/scripts.pory"
	release
# 50 "data/maps/RusturfTunnel/scripts.pory"
	end
# 51 "data/maps/RusturfTunnel/scripts.pory"

# 52 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_AlreadySpokenTo::
# 53 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_ToGetToVerdanturf, MSGBOX_DEFAULT
# 54 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 55 "data/maps/RusturfTunnel/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 56 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 57 "data/maps/RusturfTunnel/scripts.pory"
	release
# 58 "data/maps/RusturfTunnel/scripts.pory"
	end
# 59 "data/maps/RusturfTunnel/scripts.pory"

# 60 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_ClearTunnelScene::
# 61 "data/maps/RusturfTunnel/scripts.pory"
	lockall
# 62 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_FaceWandasBoyfriend1
# 63 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_FaceWandasBoyfriend2
# 64 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_FaceWandasBoyfriend3
# 65 "data/maps/RusturfTunnel/scripts.pory"
	call RusturfTunnel_EventScript_WandasBoyfriendNotice
# 66 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_YouShatteredBoulderTakeHM, MSGBOX_DEFAULT
# 67 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer
# 68 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer
# 69 "data/maps/RusturfTunnel/scripts.pory"
	giveitem ITEM_HM_STRENGTH
# 70 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_RECEIVED_HM_STRENGTH
# 71 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_ExplainStrength, MSGBOX_DEFAULT
# 72 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 73 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_BoyfriendApproachWanda1
# 74 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_BoyfriendApproachWanda2
# 75 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_BoyfriendApproachWanda3
# 76 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_WandaReunion, MSGBOX_DEFAULT
# 77 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 78 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, RusturfTunnel_EventScript_WandaAndBoyfriendExit1
# 79 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, RusturfTunnel_EventScript_WandaAndBoyfriendExit
# 80 "data/maps/RusturfTunnel/scripts.pory"
	call_if_eq VAR_TEMP_1, 3, RusturfTunnel_EventScript_WandaAndBoyfriendExit
# 81 "data/maps/RusturfTunnel/scripts.pory"
	call RusturfTunnel_EventScript_SetRusturfTunnelOpen
# 82 "data/maps/RusturfTunnel/scripts.pory"
	releaseall
# 83 "data/maps/RusturfTunnel/scripts.pory"
	end
# 84 "data/maps/RusturfTunnel/scripts.pory"

# 85 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_BoyfriendApproachWanda1::
# 86 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend1
# 87 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda1
# 88 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 89 "data/maps/RusturfTunnel/scripts.pory"
	return
# 90 "data/maps/RusturfTunnel/scripts.pory"

# 91 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_BoyfriendApproachWanda2::
# 92 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend
# 93 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda
# 94 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 95 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDA, Common_Movement_WalkInPlaceFasterDown
# 96 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 97 "data/maps/RusturfTunnel/scripts.pory"
	return
# 98 "data/maps/RusturfTunnel/scripts.pory"

# 99 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_BoyfriendApproachWanda3::
# 100 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend
# 101 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda
# 102 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 103 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDA, Common_Movement_WalkInPlaceFasterDown
# 104 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 105 "data/maps/RusturfTunnel/scripts.pory"
	return
# 106 "data/maps/RusturfTunnel/scripts.pory"

# 107 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_FaceWandasBoyfriend1::
# 108 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, Common_Movement_WalkInPlaceFasterUp
# 109 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 110 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 111 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 112 "data/maps/RusturfTunnel/scripts.pory"
	return
# 113 "data/maps/RusturfTunnel/scripts.pory"

# 114 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_FaceWandasBoyfriend2::
# 115 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_BoyfriendFaceRight
# 116 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 117 "data/maps/RusturfTunnel/scripts.pory"
	return
# 118 "data/maps/RusturfTunnel/scripts.pory"

# 119 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_FaceWandasBoyfriend3::
# 120 "data/maps/RusturfTunnel/scripts.pory"
	return
# 121 "data/maps/RusturfTunnel/scripts.pory"

# 122 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer::
# 123 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 124 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendApproachPlayer
# 125 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 126 "data/maps/RusturfTunnel/scripts.pory"
	return
# 127 "data/maps/RusturfTunnel/scripts.pory"

# 128 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandaAndBoyfriendExit1::
# 129 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDA, RusturfTunnel_Movement_WandaExit1
# 130 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendExit1
# 131 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 132 "data/maps/RusturfTunnel/scripts.pory"
	return
# 133 "data/maps/RusturfTunnel/scripts.pory"

# 134 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandaAndBoyfriendExit::
# 135 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerWatchWandaExit
# 136 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDA, RusturfTunnel_Movement_WandaExit
# 137 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendExit
# 138 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 139 "data/maps/RusturfTunnel/scripts.pory"
	return
# 140 "data/maps/RusturfTunnel/scripts.pory"

# 141 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_WandasBoyfriendNotice::
# 142 "data/maps/RusturfTunnel/scripts.pory"
	playse SE_PIN
# 143 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, Common_Movement_ExclamationMark
# 144 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 145 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_WANDAS_BF, Common_Movement_Delay48
# 146 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 147 "data/maps/RusturfTunnel/scripts.pory"
	return
# 148 "data/maps/RusturfTunnel/scripts.pory"

# 149 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandaExit1:
# 150 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 151 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 152 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 153 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 154 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 155 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 156 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 157 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 158 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 159 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 160 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 161 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 162 "data/maps/RusturfTunnel/scripts.pory"

# 163 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandaExit:
# 164 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 165 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 166 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 167 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 168 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 169 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 170 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 171 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 172 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 173 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 174 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 175 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 176 "data/maps/RusturfTunnel/scripts.pory"

# 177 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchWandaExit:
# 178 "data/maps/RusturfTunnel/scripts.pory"
	delay_8
# 179 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_up
# 180 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 181 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 182 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 183 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 184 "data/maps/RusturfTunnel/scripts.pory"

# 185 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_Unused1:
# 186 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 187 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 188 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 189 "data/maps/RusturfTunnel/scripts.pory"

# 190 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_Unused2:
# 191 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 192 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_up
# 193 "data/maps/RusturfTunnel/scripts.pory"
	delay_8
# 194 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 195 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 196 "data/maps/RusturfTunnel/scripts.pory"

# 197 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_Unused3:
# 198 "data/maps/RusturfTunnel/scripts.pory"
	walk_up
# 199 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_down
# 200 "data/maps/RusturfTunnel/scripts.pory"
	delay_8
# 201 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 202 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 203 "data/maps/RusturfTunnel/scripts.pory"

# 204 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchBoyfriend1:
# 205 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 206 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 207 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 208 "data/maps/RusturfTunnel/scripts.pory"

# 209 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchBoyfriend:
# 210 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 211 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_left
# 212 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 213 "data/maps/RusturfTunnel/scripts.pory"

# 214 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BoyfriendFaceRight:
# 215 "data/maps/RusturfTunnel/scripts.pory"
	walk_up
# 216 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_right
# 217 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 218 "data/maps/RusturfTunnel/scripts.pory"

# 219 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandasBoyfriendExit1:
# 220 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 221 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 222 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 223 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 224 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 225 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 226 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 227 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 228 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 229 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 230 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 231 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 232 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 233 "data/maps/RusturfTunnel/scripts.pory"

# 234 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandasBoyfriendExit:
# 235 "data/maps/RusturfTunnel/scripts.pory"
	walk_up
# 236 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 237 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 238 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 239 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 240 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 241 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 242 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 243 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 244 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 245 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 246 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 247 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 248 "data/maps/RusturfTunnel/scripts.pory"

# 249 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_WandasBoyfriendApproachPlayer:
# 250 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 251 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 252 "data/maps/RusturfTunnel/scripts.pory"

# 253 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BoyfriendApproachWanda1:
# 254 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_up
# 255 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_up
# 256 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_up
# 257 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_right
# 258 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 259 "data/maps/RusturfTunnel/scripts.pory"

# 260 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BoyfriendApproachWanda:
# 261 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_right
# 262 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_fast_right
# 263 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_right
# 264 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_up
# 265 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 266 "data/maps/RusturfTunnel/scripts.pory"

# 267 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_TunnelBlockagePos1::
# 268 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_TEMP_1, 1
# 269 "data/maps/RusturfTunnel/scripts.pory"
	end
# 270 "data/maps/RusturfTunnel/scripts.pory"

# 271 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_TunnelBlockagePos2::
# 272 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_TEMP_1, 2
# 273 "data/maps/RusturfTunnel/scripts.pory"
	end
# 274 "data/maps/RusturfTunnel/scripts.pory"

# 275 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_TunnelBlockagePos3::
# 276 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_TEMP_1, 3
# 277 "data/maps/RusturfTunnel/scripts.pory"
	end
# 278 "data/maps/RusturfTunnel/scripts.pory"

# 279 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_AquaGruntBackUp::
# 280 "data/maps/RusturfTunnel/scripts.pory"
	lockall
# 281 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
# 282 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_ComeAndGetSome, MSGBOX_DEFAULT
# 283 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 284 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_GRUNT, RusturfTunnel_Movement_GruntAndPeekoBackUp
# 285 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_PEEKO, RusturfTunnel_Movement_GruntAndPeekoBackUp
# 286 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 287 "data/maps/RusturfTunnel/scripts.pory"
	copyobjectxytoperm LOCALID_RUSTURF_TUNNEL_GRUNT
# 288 "data/maps/RusturfTunnel/scripts.pory"
	copyobjectxytoperm LOCALID_RUSTURF_TUNNEL_PEEKO
# 289 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_RUSTURF_TUNNEL_STATE, 3
# 290 "data/maps/RusturfTunnel/scripts.pory"
	releaseall
# 291 "data/maps/RusturfTunnel/scripts.pory"
	end
# 292 "data/maps/RusturfTunnel/scripts.pory"

# 293 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_GruntAndPeekoBackUp:
# 294 "data/maps/RusturfTunnel/scripts.pory"
	lock_facing_direction
# 295 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 296 "data/maps/RusturfTunnel/scripts.pory"
	unlock_facing_direction
# 297 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 298 "data/maps/RusturfTunnel/scripts.pory"

# 299 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_Peeko::
# 300 "data/maps/RusturfTunnel/scripts.pory"
	lock
# 301 "data/maps/RusturfTunnel/scripts.pory"
	faceplayer
# 302 "data/maps/RusturfTunnel/scripts.pory"
	waitse
# 303 "data/maps/RusturfTunnel/scripts.pory"
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
# 304 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_Peeko, MSGBOX_DEFAULT
# 305 "data/maps/RusturfTunnel/scripts.pory"
	waitmoncry
# 306 "data/maps/RusturfTunnel/scripts.pory"
	release
# 307 "data/maps/RusturfTunnel/scripts.pory"
	end
# 308 "data/maps/RusturfTunnel/scripts.pory"

# 309 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_Grunt::
# 310 "data/maps/RusturfTunnel/scripts.pory"
	lock
# 311 "data/maps/RusturfTunnel/scripts.pory"
	faceplayer
# 312 "data/maps/RusturfTunnel/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 313 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_GruntIntro, MSGBOX_DEFAULT
# 314 "data/maps/RusturfTunnel/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_RUSTURF_TUNNEL, RusturfTunnel_Text_GruntDefeat
# 315 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_GruntTakePackage, MSGBOX_DEFAULT
# 316 "data/maps/RusturfTunnel/scripts.pory"
	giveitem ITEM_DEVON_PARTS
# 317 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 318 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PushPlayerAsideForGrunt
# 319 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_GRUNT, RusturfTunnel_Movement_GruntEscape
# 320 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 321 "data/maps/RusturfTunnel/scripts.pory"
	removeobject LOCALID_RUSTURF_TUNNEL_GRUNT
# 322 "data/maps/RusturfTunnel/scripts.pory"
	delay 50
# 323 "data/maps/RusturfTunnel/scripts.pory"
	addobject LOCALID_RUSTURF_TUNNEL_BRINEY
# 324 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_BRINEY, RusturfTunnel_Movement_BrineyApproachPeeko1
# 325 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 326 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerMoveAsideForBriney
# 327 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_BRINEY, RusturfTunnel_Movement_BrineyApproachPeeko2
# 328 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 329 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_PeekoGladToSeeYouSafe, MSGBOX_DEFAULT
# 330 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_BRINEY, Common_Movement_FacePlayer
# 331 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 332 "data/maps/RusturfTunnel/scripts.pory"
	message RusturfTunnel_Text_ThankYouLetsGoHomePeeko
# 333 "data/maps/RusturfTunnel/scripts.pory"
	waitmessage
# 334 "data/maps/RusturfTunnel/scripts.pory"
	waitse
# 335 "data/maps/RusturfTunnel/scripts.pory"
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
# 336 "data/maps/RusturfTunnel/scripts.pory"
	waitbuttonpress
# 337 "data/maps/RusturfTunnel/scripts.pory"
	waitmoncry
# 338 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 339 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_PLAYER, RusturfTunnel_Movement_PlayerWatchBrineyExit
# 340 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_BRINEY, RusturfTunnel_Movement_BrineyExit
# 341 "data/maps/RusturfTunnel/scripts.pory"
	applymovement LOCALID_RUSTURF_TUNNEL_PEEKO, RusturfTunnel_Movement_PeekoExit
# 342 "data/maps/RusturfTunnel/scripts.pory"
	waitmovement 0
# 343 "data/maps/RusturfTunnel/scripts.pory"
	removeobject LOCALID_RUSTURF_TUNNEL_BRINEY
# 344 "data/maps/RusturfTunnel/scripts.pory"
	removeobject LOCALID_RUSTURF_TUNNEL_PEEKO
# 345 "data/maps/RusturfTunnel/scripts.pory"
	clearflag FLAG_DEVON_GOODS_STOLEN
# 346 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_RECOVERED_DEVON_GOODS
# 347 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_RUSTBORO_CITY_STATE, 4
# 348 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_BRINEY_HOUSE_STATE, 1
# 349 "data/maps/RusturfTunnel/scripts.pory"
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
# 350 "data/maps/RusturfTunnel/scripts.pory"
	release
# 351 "data/maps/RusturfTunnel/scripts.pory"
	end
# 352 "data/maps/RusturfTunnel/scripts.pory"

# 353 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PushPlayerAsideForGrunt:
# 354 "data/maps/RusturfTunnel/scripts.pory"
	face_down
# 355 "data/maps/RusturfTunnel/scripts.pory"
	lock_facing_direction
# 356 "data/maps/RusturfTunnel/scripts.pory"
	walk_up
# 357 "data/maps/RusturfTunnel/scripts.pory"
	unlock_facing_direction
# 358 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_left
# 359 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 360 "data/maps/RusturfTunnel/scripts.pory"

# 361 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerMoveAsideForBriney:
# 362 "data/maps/RusturfTunnel/scripts.pory"
	walk_down
# 363 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_up
# 364 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 365 "data/maps/RusturfTunnel/scripts.pory"

# 366 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_GruntEscape:
# 367 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 368 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 369 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 370 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 371 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 372 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 373 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 374 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 375 "data/maps/RusturfTunnel/scripts.pory"
	walk_fast_left
# 376 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 377 "data/maps/RusturfTunnel/scripts.pory"

# 378 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BrineyApproachPeeko1:
# 379 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 380 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 381 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 382 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 383 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 384 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 385 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 386 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 387 "data/maps/RusturfTunnel/scripts.pory"

# 388 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BrineyExit:
# 389 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 390 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 391 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 392 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 393 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 394 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 395 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 396 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 397 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 398 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 399 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 400 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 401 "data/maps/RusturfTunnel/scripts.pory"

# 402 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PlayerWatchBrineyExit:
# 403 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 404 "data/maps/RusturfTunnel/scripts.pory"
	delay_8
# 405 "data/maps/RusturfTunnel/scripts.pory"
	delay_4
# 406 "data/maps/RusturfTunnel/scripts.pory"
	walk_in_place_faster_left
# 407 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 408 "data/maps/RusturfTunnel/scripts.pory"

# 409 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_BrineyApproachPeeko2:
# 410 "data/maps/RusturfTunnel/scripts.pory"
	delay_16
# 411 "data/maps/RusturfTunnel/scripts.pory"
	walk_right
# 412 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 413 "data/maps/RusturfTunnel/scripts.pory"

# 414 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Movement_PeekoExit:
# 415 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 416 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 417 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 418 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 419 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 420 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 421 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 422 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 423 "data/maps/RusturfTunnel/scripts.pory"
	walk_left
# 424 "data/maps/RusturfTunnel/scripts.pory"
	step_end
# 425 "data/maps/RusturfTunnel/scripts.pory"

# 426 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_EventScript_Mike::
# 427 "data/maps/RusturfTunnel/scripts.pory"
	trainerbattle_single TRAINER_MIKE_2, RusturfTunnel_Text_MikeIntro, RusturfTunnel_Text_MikeDefeat
# 428 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_Text_MikePostBattle, MSGBOX_AUTOCLOSE
# 429 "data/maps/RusturfTunnel/scripts.pory"
	end
# 430 "data/maps/RusturfTunnel/scripts.pory"

# 431 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ComeAndGetSome:
# 432 "data/maps/RusturfTunnel/scripts.pory"
	.string "What, are you coming?\n"
# 433 "data/maps/RusturfTunnel/scripts.pory"
	.string "Come and get some, then!$"
# 434 "data/maps/RusturfTunnel/scripts.pory"

# 435 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_Peeko:
# 436 "data/maps/RusturfTunnel/scripts.pory"
	.string "PEEKO: Pii pihyoh!$"
# 437 "data/maps/RusturfTunnel/scripts.pory"

# 438 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_GruntIntro:
# 439 "data/maps/RusturfTunnel/scripts.pory"
	.string "Grah, keelhaul it all!\p"
# 440 "data/maps/RusturfTunnel/scripts.pory"
	.string "That hostage POKéMON turned out to\n"
# 441 "data/maps/RusturfTunnel/scripts.pory"
	.string "be worthless!\p"
# 442 "data/maps/RusturfTunnel/scripts.pory"
	.string "And to think I made a getaway…\n"
# 443 "data/maps/RusturfTunnel/scripts.pory"
	.string "In this tunnel to nowhere!\p"
# 444 "data/maps/RusturfTunnel/scripts.pory"
	.string "Hey! You!\n"
# 445 "data/maps/RusturfTunnel/scripts.pory"
	.string "So you want to battle me?$"
# 446 "data/maps/RusturfTunnel/scripts.pory"

# 447 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_GruntDefeat:
# 448 "data/maps/RusturfTunnel/scripts.pory"
	.string "Urrrggh! My career in crime comes to\n"
# 449 "data/maps/RusturfTunnel/scripts.pory"
	.string "a dead end!$"
# 450 "data/maps/RusturfTunnel/scripts.pory"

# 451 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_GruntTakePackage:
# 452 "data/maps/RusturfTunnel/scripts.pory"
	.string "This is plain not right…\p"
# 453 "data/maps/RusturfTunnel/scripts.pory"
	.string "The BOSS told me this would be a\n"
# 454 "data/maps/RusturfTunnel/scripts.pory"
	.string "slick-and-easy job to pull.\p"
# 455 "data/maps/RusturfTunnel/scripts.pory"
	.string "All I had to do was steal some package\n"
# 456 "data/maps/RusturfTunnel/scripts.pory"
	.string "from DEVON.\p"
# 457 "data/maps/RusturfTunnel/scripts.pory"
	.string "Tch!\n"
# 458 "data/maps/RusturfTunnel/scripts.pory"
	.string "You want it back that badly, take it!$"
# 459 "data/maps/RusturfTunnel/scripts.pory"

# 460 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_PeekoGladToSeeYouSafe:
# 461 "data/maps/RusturfTunnel/scripts.pory"
	.string "PEEKO!\n"
# 462 "data/maps/RusturfTunnel/scripts.pory"
	.string "Am I glad to see you're safe!$"
# 463 "data/maps/RusturfTunnel/scripts.pory"

# 464 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ThankYouLetsGoHomePeeko:
# 465 "data/maps/RusturfTunnel/scripts.pory"
	.string "PEEKO owes her life to you!\p"
# 466 "data/maps/RusturfTunnel/scripts.pory"
	.string "They call me MR. BRINEY.\n"
# 467 "data/maps/RusturfTunnel/scripts.pory"
	.string "And, you are?\p"
# 468 "data/maps/RusturfTunnel/scripts.pory"
	.string "… … … … … … … …\n"
# 469 "data/maps/RusturfTunnel/scripts.pory"
	.string "… … … … … … … …\p"
# 470 "data/maps/RusturfTunnel/scripts.pory"
	.string "Ah, so you are {PLAYER}{KUN}!\n"
# 471 "data/maps/RusturfTunnel/scripts.pory"
	.string "I sincerely thank you!\p"
# 472 "data/maps/RusturfTunnel/scripts.pory"
	.string "Now, if there's anything that troubles\n"
# 473 "data/maps/RusturfTunnel/scripts.pory"
	.string "you, don't hesitate to tell me!\p"
# 474 "data/maps/RusturfTunnel/scripts.pory"
	.string "You can usually find me in my cottage\n"
# 475 "data/maps/RusturfTunnel/scripts.pory"
	.string "by the sea near PETALBURG WOODS.\p"
# 476 "data/maps/RusturfTunnel/scripts.pory"
	.string "Come, PEEKO, we should make our way\n"
# 477 "data/maps/RusturfTunnel/scripts.pory"
	.string "home.\p"
# 478 "data/maps/RusturfTunnel/scripts.pory"
	.string "PEEKO: Pihyoh!$"
# 479 "data/maps/RusturfTunnel/scripts.pory"

# 480 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_WhyCantTheyKeepDigging:
# 481 "data/maps/RusturfTunnel/scripts.pory"
	.string "… …\p"
# 482 "data/maps/RusturfTunnel/scripts.pory"
	.string "Why can't they keep digging?\n"
# 483 "data/maps/RusturfTunnel/scripts.pory"
	.string "Is the bedrock too hard?\p"
# 484 "data/maps/RusturfTunnel/scripts.pory"
	.string "My beloved awaits me in VERDANTURF\n"
# 485 "data/maps/RusturfTunnel/scripts.pory"
	.string "TOWN just beyond here…\p"
# 486 "data/maps/RusturfTunnel/scripts.pory"
	.string "If RUSTBORO and VERDANTURF were\n"
# 487 "data/maps/RusturfTunnel/scripts.pory"
	.string "joined by this tunnel, I could visit\l"
# 488 "data/maps/RusturfTunnel/scripts.pory"
	.string "her every day…\p"
# 489 "data/maps/RusturfTunnel/scripts.pory"
	.string "But this…\n"
# 490 "data/maps/RusturfTunnel/scripts.pory"
	.string "What am I to do?$"
# 491 "data/maps/RusturfTunnel/scripts.pory"

# 492 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ToGetToVerdanturf:
# 493 "data/maps/RusturfTunnel/scripts.pory"
	.string "To get from RUSTBORO to VERDANTURF,\n"
# 494 "data/maps/RusturfTunnel/scripts.pory"
	.string "you need to go to DEWFORD, then pass\l"
# 495 "data/maps/RusturfTunnel/scripts.pory"
	.string "through SLATEPORT and MAUVILLE…$"
# 496 "data/maps/RusturfTunnel/scripts.pory"

# 497 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_YouShatteredBoulderTakeHM:
# 498 "data/maps/RusturfTunnel/scripts.pory"
	.string "Wow! You shattered that boulder\n"
# 499 "data/maps/RusturfTunnel/scripts.pory"
	.string "blocking the way.\p"
# 500 "data/maps/RusturfTunnel/scripts.pory"
	.string "To show you how much I appreciate it,\n"
# 501 "data/maps/RusturfTunnel/scripts.pory"
	.string "I'd like you to have this HM.$"
# 502 "data/maps/RusturfTunnel/scripts.pory"

# 503 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_ExplainStrength:
# 504 "data/maps/RusturfTunnel/scripts.pory"
	.string "That HM contains STRENGTH.\p"
# 505 "data/maps/RusturfTunnel/scripts.pory"
	.string "If a muscular POKéMON were to learn\n"
# 506 "data/maps/RusturfTunnel/scripts.pory"
	.string "that, it would be able to move even\l"
# 507 "data/maps/RusturfTunnel/scripts.pory"
	.string "large boulders.$"
# 508 "data/maps/RusturfTunnel/scripts.pory"

# 509 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_WandaReunion:
# 510 "data/maps/RusturfTunnel/scripts.pory"
	.string "WANDA!\n"
# 511 "data/maps/RusturfTunnel/scripts.pory"
	.string "Now I can see you anytime!\p"
# 512 "data/maps/RusturfTunnel/scripts.pory"
	.string "WANDA: That's…wonderful.\p"
# 513 "data/maps/RusturfTunnel/scripts.pory"
	.string "Please, take some rest at my home.$"
# 514 "data/maps/RusturfTunnel/scripts.pory"

# 515 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_BoyfriendOnOtherSideOfRock:
# 516 "data/maps/RusturfTunnel/scripts.pory"
	.string "On the other side of this rock…\n"
# 517 "data/maps/RusturfTunnel/scripts.pory"
	.string "My boyfriend is there.\p"
# 518 "data/maps/RusturfTunnel/scripts.pory"
	.string "He… He's not just digging the tunnel\n"
# 519 "data/maps/RusturfTunnel/scripts.pory"
	.string "to come see me.\p"
# 520 "data/maps/RusturfTunnel/scripts.pory"
	.string "He works his hands raw and rough\n"
# 521 "data/maps/RusturfTunnel/scripts.pory"
	.string "for the benefit of everyone.$"
# 522 "data/maps/RusturfTunnel/scripts.pory"

# 523 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_MikeIntro:
# 524 "data/maps/RusturfTunnel/scripts.pory"
	.string "What do you call a wild man up in the\n"
# 525 "data/maps/RusturfTunnel/scripts.pory"
	.string "mountains? A mountain man, right?\p"
# 526 "data/maps/RusturfTunnel/scripts.pory"
	.string "So why don't they call a POKéMON in\n"
# 527 "data/maps/RusturfTunnel/scripts.pory"
	.string "the mountains a mountain POKéMON?$"
# 528 "data/maps/RusturfTunnel/scripts.pory"

# 529 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_MikeDefeat:
# 530 "data/maps/RusturfTunnel/scripts.pory"
	.string "My POKéMON…\n"
# 531 "data/maps/RusturfTunnel/scripts.pory"
	.string "Ran out of power…$"
# 532 "data/maps/RusturfTunnel/scripts.pory"

# 533 "data/maps/RusturfTunnel/scripts.pory"
RusturfTunnel_Text_MikePostBattle:
# 534 "data/maps/RusturfTunnel/scripts.pory"
	.string "They halted development here to\n"
# 535 "data/maps/RusturfTunnel/scripts.pory"
	.string "protect POKéMON, right?\l"
# 536 "data/maps/RusturfTunnel/scripts.pory"
	.string "There's a feel-good story!$"

RusturfTunnel_EventScript_CheckHasDnaSplicers::
# 547 "data/maps/RusturfTunnel/scripts.pory"
	checkitem ITEM_DNA_SPLICERS
# 548 "data/maps/RusturfTunnel/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq RusturfTunnel_EventScript_CheckHasDnaSplicers_2
RusturfTunnel_EventScript_CheckHasDnaSplicers_1:
	return

RusturfTunnel_EventScript_CheckHasDnaSplicers_2:
# 549 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_ZEKROM_CAVE_STATE, 1
	goto RusturfTunnel_EventScript_CheckHasDnaSplicers_1


RusturfTunnel_EventScript_DrawZekromCaveEntrance::
# 557 "data/maps/RusturfTunnel/scripts.pory"
	setmetatile 12, 2, 0x20B, TRUE
# 558 "data/maps/RusturfTunnel/scripts.pory"
	setmetatile 13, 2, 0x20C, TRUE
# 559 "data/maps/RusturfTunnel/scripts.pory"
	setmetatile 14, 2, 0x20D, TRUE
# 560 "data/maps/RusturfTunnel/scripts.pory"
	setmetatile 12, 3, 0x213, TRUE
# 561 "data/maps/RusturfTunnel/scripts.pory"
	setmetatile 13, 3, 0x214, FALSE
# 562 "data/maps/RusturfTunnel/scripts.pory"
	setmetatile 14, 3, 0x215, TRUE
	return


RusturfTunnel_EventScript_RevealZekromCave::
# 567 "data/maps/RusturfTunnel/scripts.pory"
	lockall
# 568 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_0x8004, 1
# 569 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_0x8005, 1
# 570 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_0x8006, 8
# 571 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_0x8007, 5
# 572 "data/maps/RusturfTunnel/scripts.pory"
	special ShakeCamera
# 573 "data/maps/RusturfTunnel/scripts.pory"
	waitstate
# 574 "data/maps/RusturfTunnel/scripts.pory"
	msgbox RusturfTunnel_EventScript_RevealZekromCave_Text_0, MSGBOX_DEFAULT
# 575 "data/maps/RusturfTunnel/scripts.pory"
	closemessage
# 576 "data/maps/RusturfTunnel/scripts.pory"
	playse SE_EFFECTIVE
# 577 "data/maps/RusturfTunnel/scripts.pory"
	call RusturfTunnel_EventScript_DrawZekromCaveEntrance
# 578 "data/maps/RusturfTunnel/scripts.pory"
	special DrawWholeMapView
# 579 "data/maps/RusturfTunnel/scripts.pory"
	delay 30
# 580 "data/maps/RusturfTunnel/scripts.pory"
	setvar VAR_ZEKROM_CAVE_STATE, 2
# 581 "data/maps/RusturfTunnel/scripts.pory"
	waitse
# 582 "data/maps/RusturfTunnel/scripts.pory"
	releaseall
	end


RusturfTunnel_EventScript_RevealZekromCave_Text_0:
# 574 "data/maps/RusturfTunnel/scripts.pory"
	.string "The DNA Splicers pulse in your bag --\n"
	.string "and with a grinding roar the tunnel wall\l"
	.string "splits open!$"
