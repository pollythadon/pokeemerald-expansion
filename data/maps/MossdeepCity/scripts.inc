# 1 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_MapScripts::
# 2 "data/maps/MossdeepCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
# 3 "data/maps/MossdeepCity/scripts.pory"
	.byte 0
# 4 "data/maps/MossdeepCity/scripts.pory"

# 5 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_OnTransition:
# 6 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
# 7 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
# 8 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
# 9 "data/maps/MossdeepCity/scripts.pory"
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
# 10 "data/maps/MossdeepCity/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call RoamingLegendQuests_EventScript_SyncNpcVisibility
# 11 "data/maps/MossdeepCity/scripts.pory"
	end
# 12 "data/maps/MossdeepCity/scripts.pory"

# 13 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_PokefanF::
# 14 "data/maps/MossdeepCity/scripts.pory"
	lock
# 15 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 16 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
# 17 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
# 18 "data/maps/MossdeepCity/scripts.pory"
	release
# 19 "data/maps/MossdeepCity/scripts.pory"
	end
# 20 "data/maps/MossdeepCity/scripts.pory"

# 21 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_PokefanFMagmaGone::
# 22 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
# 23 "data/maps/MossdeepCity/scripts.pory"
	release
# 24 "data/maps/MossdeepCity/scripts.pory"
	end
# 25 "data/maps/MossdeepCity/scripts.pory"

# 26 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Sailor::
# 27 "data/maps/MossdeepCity/scripts.pory"
	lock
# 28 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 29 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
# 30 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
# 31 "data/maps/MossdeepCity/scripts.pory"
	release
# 32 "data/maps/MossdeepCity/scripts.pory"
	end
# 33 "data/maps/MossdeepCity/scripts.pory"

# 34 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_SailorMagmaGone::
# 35 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
# 36 "data/maps/MossdeepCity/scripts.pory"
	release
# 37 "data/maps/MossdeepCity/scripts.pory"
	end
# 38 "data/maps/MossdeepCity/scripts.pory"

# 39 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_NinjaBoy::
# 40 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
# 41 "data/maps/MossdeepCity/scripts.pory"
	end
# 42 "data/maps/MossdeepCity/scripts.pory"

# 43 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ExpertM::
# 44 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
# 45 "data/maps/MossdeepCity/scripts.pory"
	end
# 46 "data/maps/MossdeepCity/scripts.pory"

# 47 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Girl::
# 48 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
# 49 "data/maps/MossdeepCity/scripts.pory"
	end
# 50 "data/maps/MossdeepCity/scripts.pory"

# 51 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Woman::
# 52 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
# 53 "data/maps/MossdeepCity/scripts.pory"
	end
# 54 "data/maps/MossdeepCity/scripts.pory"

# 55 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_WhiteRock::
# 56 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
# 57 "data/maps/MossdeepCity/scripts.pory"
	end
# 58 "data/maps/MossdeepCity/scripts.pory"

# 59 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_GymSign::
# 60 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
# 61 "data/maps/MossdeepCity/scripts.pory"
	end
# 62 "data/maps/MossdeepCity/scripts.pory"

# 63 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_CitySign::
# 64 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
# 65 "data/maps/MossdeepCity/scripts.pory"
	end
# 66 "data/maps/MossdeepCity/scripts.pory"

# 67 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_SpaceCenterSign::
# 68 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
# 69 "data/maps/MossdeepCity/scripts.pory"
	end
# 70 "data/maps/MossdeepCity/scripts.pory"

# 71 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_VisitedMossdeep::
# 72 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_VISITED_MOSSDEEP_CITY
# 73 "data/maps/MossdeepCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 74 "data/maps/MossdeepCity/scripts.pory"
	end
# 75 "data/maps/MossdeepCity/scripts.pory"

# 76 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
# 77 "data/maps/MossdeepCity/scripts.pory"
	lockall
# 78 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
# 79 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 80 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
# 81 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
# 82 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
# 83 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
# 84 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 85 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
# 86 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
# 87 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
# 88 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
# 89 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
# 90 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 91 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_MOSSDEEP_MAXIE
# 92 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_MOSSDEEP_GRUNT_1
# 93 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_MOSSDEEP_GRUNT_2
# 94 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_MOSSDEEP_GRUNT_3
# 95 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_MOSSDEEP_GRUNT_4
# 96 "data/maps/MossdeepCity/scripts.pory"
	delay 30
# 97 "data/maps/MossdeepCity/scripts.pory"
	setvar VAR_MOSSDEEP_CITY_STATE, 2
# 98 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
# 99 "data/maps/MossdeepCity/scripts.pory"
	releaseall
# 100 "data/maps/MossdeepCity/scripts.pory"
	end
# 101 "data/maps/MossdeepCity/scripts.pory"

# 102 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_MaxieGestureToSpaceCenter:
# 103 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 104 "data/maps/MossdeepCity/scripts.pory"
	face_right
# 105 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 106 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 107 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 108 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 109 "data/maps/MossdeepCity/scripts.pory"
	face_left
# 110 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 111 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 112 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 113 "data/maps/MossdeepCity/scripts.pory"

# 114 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_GruntFaceSpaceCenter:
# 115 "data/maps/MossdeepCity/scripts.pory"
	face_right
# 116 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 117 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 118 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 119 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 120 "data/maps/MossdeepCity/scripts.pory"

# 121 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_MaxieEnterSpaceCenter:
# 122 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 123 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 124 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 125 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 126 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 127 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 128 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 129 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 130 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 131 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 132 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 133 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 134 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 135 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 136 "data/maps/MossdeepCity/scripts.pory"

# 137 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt1EnterSpaceCenter:
# 138 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 139 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 140 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 141 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 142 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 143 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 144 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 145 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 146 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 147 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 148 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 149 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 150 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 151 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 152 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 153 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 154 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 155 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 156 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 157 "data/maps/MossdeepCity/scripts.pory"

# 158 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt2EnterSpaceCenter:
# 159 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 160 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 161 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 162 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 163 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 164 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 165 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 166 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 167 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 168 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 169 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 170 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 171 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 172 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 173 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 174 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 175 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 176 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 177 "data/maps/MossdeepCity/scripts.pory"

# 178 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt3EnterSpaceCenter:
# 179 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 180 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 181 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 182 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 183 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 184 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 185 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 186 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 187 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 188 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 189 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 190 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 191 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 192 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 193 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 194 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 195 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 196 "data/maps/MossdeepCity/scripts.pory"

# 197 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_Grunt4EnterSpaceCenter:
# 198 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 199 "data/maps/MossdeepCity/scripts.pory"
	delay_8
# 200 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 201 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 202 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 203 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 204 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 205 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 206 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 207 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 208 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 209 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 210 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 211 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 212 "data/maps/MossdeepCity/scripts.pory"
	walk_right
# 213 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 214 "data/maps/MossdeepCity/scripts.pory"

# 215 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Man::
# 216 "data/maps/MossdeepCity/scripts.pory"
	lock
# 217 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 218 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
# 219 "data/maps/MossdeepCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 220 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 221 "data/maps/MossdeepCity/scripts.pory"
	release
# 222 "data/maps/MossdeepCity/scripts.pory"
	end
# 223 "data/maps/MossdeepCity/scripts.pory"

# 224 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_KingsRockBoy::
# 225 "data/maps/MossdeepCity/scripts.pory"
	lock
# 226 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 227 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
# 228 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
# 229 "data/maps/MossdeepCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
# 230 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
# 231 "data/maps/MossdeepCity/scripts.pory"
	giveitem ITEM_KINGS_ROCK
# 232 "data/maps/MossdeepCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 233 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_RECEIVED_KINGS_ROCK
# 234 "data/maps/MossdeepCity/scripts.pory"
	release
# 235 "data/maps/MossdeepCity/scripts.pory"
	end
# 236 "data/maps/MossdeepCity/scripts.pory"

# 237 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ReceivedKingsRock::
# 238 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
# 239 "data/maps/MossdeepCity/scripts.pory"
	release
# 240 "data/maps/MossdeepCity/scripts.pory"
	end
# 241 "data/maps/MossdeepCity/scripts.pory"

# 242 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_DeclineKingsRock::
# 243 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
# 244 "data/maps/MossdeepCity/scripts.pory"
	release
# 245 "data/maps/MossdeepCity/scripts.pory"
	end
# 246 "data/maps/MossdeepCity/scripts.pory"

# 247 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_BlackBelt::
# 248 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
# 249 "data/maps/MossdeepCity/scripts.pory"
	end
# 250 "data/maps/MossdeepCity/scripts.pory"

# 251 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_Scott::
# 252 "data/maps/MossdeepCity/scripts.pory"
	lock
# 253 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 254 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
# 255 "data/maps/MossdeepCity/scripts.pory"
	closemessage
# 256 "data/maps/MossdeepCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
# 257 "data/maps/MossdeepCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
# 258 "data/maps/MossdeepCity/scripts.pory"
	addvar VAR_SCOTT_STATE, 1
# 259 "data/maps/MossdeepCity/scripts.pory"
	removeobject LOCALID_MOSSDEEP_SCOTT
# 260 "data/maps/MossdeepCity/scripts.pory"
	release
# 261 "data/maps/MossdeepCity/scripts.pory"
	end
# 262 "data/maps/MossdeepCity/scripts.pory"

# 263 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ScottExitNorth::
# 264 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
# 265 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitNorth
# 266 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 267 "data/maps/MossdeepCity/scripts.pory"
	return
# 268 "data/maps/MossdeepCity/scripts.pory"

# 269 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_EventScript_ScottExitEast::
# 270 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
# 271 "data/maps/MossdeepCity/scripts.pory"
	applymovement LOCALID_MOSSDEEP_SCOTT, MossdeepCity_Movement_ScottExitEast
# 272 "data/maps/MossdeepCity/scripts.pory"
	waitmovement 0
# 273 "data/maps/MossdeepCity/scripts.pory"
	return
# 274 "data/maps/MossdeepCity/scripts.pory"

# 275 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_PlayerWatchScottExit:
# 276 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 277 "data/maps/MossdeepCity/scripts.pory"
	delay_16
# 278 "data/maps/MossdeepCity/scripts.pory"
	walk_in_place_faster_left
# 279 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 280 "data/maps/MossdeepCity/scripts.pory"

# 281 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_ScottExitNorth:
# 282 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 283 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 284 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 285 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 286 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 287 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 288 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 289 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 290 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 291 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 292 "data/maps/MossdeepCity/scripts.pory"

# 293 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Movement_ScottExitEast:
# 294 "data/maps/MossdeepCity/scripts.pory"
	walk_down
# 295 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 296 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 297 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 298 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 299 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 300 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 301 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 302 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 303 "data/maps/MossdeepCity/scripts.pory"
	walk_left
# 304 "data/maps/MossdeepCity/scripts.pory"
	step_end
# 305 "data/maps/MossdeepCity/scripts.pory"

# 306 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_WantKingsRockStevenGaveMe:
# 307 "data/maps/MossdeepCity/scripts.pory"
	.string "I got this from STEVEN, but I don't\n"
# 308 "data/maps/MossdeepCity/scripts.pory"
	.string "know what it's good for.\p"
# 309 "data/maps/MossdeepCity/scripts.pory"
	.string "I think it's called KING'S ROCK.\n"
# 310 "data/maps/MossdeepCity/scripts.pory"
	.string "Do you want it?$"
# 311 "data/maps/MossdeepCity/scripts.pory"

# 312 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_YouCanKeepIt:
# 313 "data/maps/MossdeepCity/scripts.pory"
	.string "Why would you want it?\n"
# 314 "data/maps/MossdeepCity/scripts.pory"
	.string "You're weird.\p"
# 315 "data/maps/MossdeepCity/scripts.pory"
	.string "You can keep it, but keep it a secret\n"
# 316 "data/maps/MossdeepCity/scripts.pory"
	.string "from STEVEN.$"
# 317 "data/maps/MossdeepCity/scripts.pory"

# 318 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_StevensHouseOverThere:
# 319 "data/maps/MossdeepCity/scripts.pory"
	.string "STEVEN's house is right over there!$"
# 320 "data/maps/MossdeepCity/scripts.pory"

# 321 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_WhatToDoWithWeirdRock:
# 322 "data/maps/MossdeepCity/scripts.pory"
	.string "Yeah, you think so, too! What are you\n"
# 323 "data/maps/MossdeepCity/scripts.pory"
	.string "supposed to do with some weird rock?$"
# 324 "data/maps/MossdeepCity/scripts.pory"

# 325 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_WailmerWatching:
# 326 "data/maps/MossdeepCity/scripts.pory"
	.string "Around MOSSDEEP, you can see wild\n"
# 327 "data/maps/MossdeepCity/scripts.pory"
	.string "WAILMER.\p"
# 328 "data/maps/MossdeepCity/scripts.pory"
	.string "It's called, uh…\n"
# 329 "data/maps/MossdeepCity/scripts.pory"
	.string "What was it now…\p"
# 330 "data/maps/MossdeepCity/scripts.pory"
	.string "WAI, WAI, WAI…\p"
# 331 "data/maps/MossdeepCity/scripts.pory"
	.string "WAILMER watching!$"
# 332 "data/maps/MossdeepCity/scripts.pory"

# 333 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpaceCenterReceivedLetter:
# 334 "data/maps/MossdeepCity/scripts.pory"
	.string "The island's SPACE CENTER has been\n"
# 335 "data/maps/MossdeepCity/scripts.pory"
	.string "launching huge rockets.\p"
# 336 "data/maps/MossdeepCity/scripts.pory"
	.string "There's been some kind of an uproar\n"
# 337 "data/maps/MossdeepCity/scripts.pory"
	.string "over a letter they received recently.$"
# 338 "data/maps/MossdeepCity/scripts.pory"

# 339 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpaceCenterLaunchingRockets:
# 340 "data/maps/MossdeepCity/scripts.pory"
	.string "The island's SPACE CENTER has been\n"
# 341 "data/maps/MossdeepCity/scripts.pory"
	.string "launching huge rockets.$"
# 342 "data/maps/MossdeepCity/scripts.pory"

# 343 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_MossdeepTargetedByMagma:
# 344 "data/maps/MossdeepCity/scripts.pory"
	.string "I heard from a SAILOR buddy that\n"
# 345 "data/maps/MossdeepCity/scripts.pory"
	.string "TEAM AQUA set up shop in LILYCOVE.\p"
# 346 "data/maps/MossdeepCity/scripts.pory"
	.string "I also heard that someone came along\n"
# 347 "data/maps/MossdeepCity/scripts.pory"
	.string "and wiped the floor with them!\p"
# 348 "data/maps/MossdeepCity/scripts.pory"
	.string "But MOSSDEEP here's been targeted\n"
# 349 "data/maps/MossdeepCity/scripts.pory"
	.string "by that TEAM MAGMA.\p"
# 350 "data/maps/MossdeepCity/scripts.pory"
	.string "If you want to know what they're up to,\n"
# 351 "data/maps/MossdeepCity/scripts.pory"
	.string "go visit the SPACE CENTER.$"
# 352 "data/maps/MossdeepCity/scripts.pory"

# 353 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_FeelReliefOnLand:
# 354 "data/maps/MossdeepCity/scripts.pory"
	.string "I'm a SAILOR, so the sea's obviously\n"
# 355 "data/maps/MossdeepCity/scripts.pory"
	.string "more important to me.\p"
# 356 "data/maps/MossdeepCity/scripts.pory"
	.string "But you know? When I get back on land\n"
# 357 "data/maps/MossdeepCity/scripts.pory"
	.string "after a long voyage, I do feel relief!$"
# 358 "data/maps/MossdeepCity/scripts.pory"

# 359 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
# 360 "data/maps/MossdeepCity/scripts.pory"
	.string "Wouldn't it be nice?\p"
# 361 "data/maps/MossdeepCity/scripts.pory"
	.string "If the whole world was covered in\n"
# 362 "data/maps/MossdeepCity/scripts.pory"
	.string "plants and flowers like this island?$"
# 363 "data/maps/MossdeepCity/scripts.pory"

# 364 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_LifeNeedsSeaToLive:
# 365 "data/maps/MossdeepCity/scripts.pory"
	.string "All life needs the sea to live, even\n"
# 366 "data/maps/MossdeepCity/scripts.pory"
	.string "though it makes its home on the land.\p"
# 367 "data/maps/MossdeepCity/scripts.pory"
	.string "Life, having run its course, becomes\n"
# 368 "data/maps/MossdeepCity/scripts.pory"
	.string "soil and returns to the land.\p"
# 369 "data/maps/MossdeepCity/scripts.pory"
	.string "And the sea is always connected to\n"
# 370 "data/maps/MossdeepCity/scripts.pory"
	.string "the land.\p"
# 371 "data/maps/MossdeepCity/scripts.pory"
	.string "Yes, like the very shoreline here.$"
# 372 "data/maps/MossdeepCity/scripts.pory"

# 373 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SurfExhilarating:
# 374 "data/maps/MossdeepCity/scripts.pory"
	.string "A voyage on a ship is fine.\p"
# 375 "data/maps/MossdeepCity/scripts.pory"
	.string "But crossing the sea with POKéMON\n"
# 376 "data/maps/MossdeepCity/scripts.pory"
	.string "using SURF…\p"
# 377 "data/maps/MossdeepCity/scripts.pory"
	.string "Now that's an exhilarating trip!\n"
# 378 "data/maps/MossdeepCity/scripts.pory"
	.string "Wouldn't you agree, youngster?$"
# 379 "data/maps/MossdeepCity/scripts.pory"

# 380 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpecialSpaceCenterRock:
# 381 "data/maps/MossdeepCity/scripts.pory"
	.string "This rock has a special meaning to\n"
# 382 "data/maps/MossdeepCity/scripts.pory"
	.string "the people at the SPACE CENTER.\p"
# 383 "data/maps/MossdeepCity/scripts.pory"
	.string "They put it here as their wish for\n"
# 384 "data/maps/MossdeepCity/scripts.pory"
	.string "their rockets to fly safely.\p"
# 385 "data/maps/MossdeepCity/scripts.pory"
	.string "When you make a wish, what do you use?\n"
# 386 "data/maps/MossdeepCity/scripts.pory"
	.string "Do you wish upon a star?\p"
# 387 "data/maps/MossdeepCity/scripts.pory"
	.string "I use a wish tag to make it happen.\n"
# 388 "data/maps/MossdeepCity/scripts.pory"
	.string "That's what I do.$"
# 389 "data/maps/MossdeepCity/scripts.pory"

# 390 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_ItsAWhiteRock:
# 391 "data/maps/MossdeepCity/scripts.pory"
	.string "It's a white rock.$"
# 392 "data/maps/MossdeepCity/scripts.pory"

# 393 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_GymSign:
# 394 "data/maps/MossdeepCity/scripts.pory"
	.string "MOSSDEEP CITY POKéMON GYM\n"
# 395 "data/maps/MossdeepCity/scripts.pory"
	.string "LEADERS: LIZA & TATE\p"
# 396 "data/maps/MossdeepCity/scripts.pory"
	.string "“The mystic combination!”$"
# 397 "data/maps/MossdeepCity/scripts.pory"

# 398 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_CitySign:
# 399 "data/maps/MossdeepCity/scripts.pory"
	.string "MOSSDEEP CITY\n"
# 400 "data/maps/MossdeepCity/scripts.pory"
	.string "“Our slogan: Cherish POKéMON!”$"
# 401 "data/maps/MossdeepCity/scripts.pory"

# 402 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SpaceCenterSign:
# 403 "data/maps/MossdeepCity/scripts.pory"
	.string "MOSSDEEP SPACE CENTER\n"
# 404 "data/maps/MossdeepCity/scripts.pory"
	.string "“The closest place to space.”$"
# 405 "data/maps/MossdeepCity/scripts.pory"

# 406 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_ScottSomethingWrongWithTown:
# 407 "data/maps/MossdeepCity/scripts.pory"
	.string "SCOTT: {PLAYER}{KUN}, feeling good?\n"
# 408 "data/maps/MossdeepCity/scripts.pory"
	.string "I'm doing great!\p"
# 409 "data/maps/MossdeepCity/scripts.pory"
	.string "I'd heard MOSSDEEP's GYM LEADER is\n"
# 410 "data/maps/MossdeepCity/scripts.pory"
	.string "pretty strong, so I decided to come\l"
# 411 "data/maps/MossdeepCity/scripts.pory"
	.string "take a look-see for myself.\p"
# 412 "data/maps/MossdeepCity/scripts.pory"
	.string "But there's something wrong about\n"
# 413 "data/maps/MossdeepCity/scripts.pory"
	.string "this town.\p"
# 414 "data/maps/MossdeepCity/scripts.pory"
	.string "People are going on about a warning\n"
# 415 "data/maps/MossdeepCity/scripts.pory"
	.string "letter and the SPACE CENTER…\p"
# 416 "data/maps/MossdeepCity/scripts.pory"
	.string "I don't think it concerns me in any\n"
# 417 "data/maps/MossdeepCity/scripts.pory"
	.string "way, though.$"
# 418 "data/maps/MossdeepCity/scripts.pory"

# 419 "data/maps/MossdeepCity/scripts.pory"
MossdeepCity_Text_SootopolisNewGymLeader:
# 420 "data/maps/MossdeepCity/scripts.pory"
	.string "Ahh… It feels great letting the waves\n"
# 421 "data/maps/MossdeepCity/scripts.pory"
	.string "wash over my feet…\p"
# 422 "data/maps/MossdeepCity/scripts.pory"
	.string "Speaking of the waves, you know that\n"
# 423 "data/maps/MossdeepCity/scripts.pory"
	.string "island city SOOTOPOLIS?\p"
# 424 "data/maps/MossdeepCity/scripts.pory"
	.string "I think the GYM there had a new\n"
# 425 "data/maps/MossdeepCity/scripts.pory"
	.string "LEADER come in.\p"
# 426 "data/maps/MossdeepCity/scripts.pory"
	.string "People tell me the new LEADER once\n"
# 427 "data/maps/MossdeepCity/scripts.pory"
	.string "mentored WALLACE.$"

JIRACHI_quest_starter::
# 432 "data/maps/MossdeepCity/scripts.pory"
	lockall
# 433 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 434 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_JIRACHI_GIFT, JIRACHI_quest_starter_2
# 439 "data/maps/MossdeepCity/scripts.pory"
	msgbox JIRACHI_quest_starter_Text_1
	checkitem ITEM_OLD_SEA_MAP
# 0 "data/maps/MossdeepCity/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne JIRACHI_quest_starter_5
# 451 "data/maps/MossdeepCity/scripts.pory"
	msgbox JIRACHI_quest_starter_Text_5
JIRACHI_quest_starter_4:
# 453 "data/maps/MossdeepCity/scripts.pory"
	releaseall
	end

JIRACHI_quest_starter_2:
# 435 "data/maps/MossdeepCity/scripts.pory"
	msgbox JIRACHI_quest_starter_Text_0
# 436 "data/maps/MossdeepCity/scripts.pory"
	releaseall
	end

JIRACHI_quest_starter_5:
# 441 "data/maps/MossdeepCity/scripts.pory"
	msgbox JIRACHI_quest_starter_Text_2, MSGBOX_YESNO
# 442 "data/maps/MossdeepCity/scripts.pory"
	switch VAR_RESULT
# 443 "data/maps/MossdeepCity/scripts.pory"
	case YES, JIRACHI_quest_starter_9
# 447 "data/maps/MossdeepCity/scripts.pory"
	case NO, JIRACHI_quest_starter_10
	goto JIRACHI_quest_starter_4

JIRACHI_quest_starter_9:
# 444 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_JIRACHI_GIFT
# 445 "data/maps/MossdeepCity/scripts.pory"
	bumpquest QUEST_JIRACHI
# 446 "data/maps/MossdeepCity/scripts.pory"
	msgbox JIRACHI_quest_starter_Text_3
	goto JIRACHI_quest_starter_4

JIRACHI_quest_starter_10:
# 448 "data/maps/MossdeepCity/scripts.pory"
	msgbox JIRACHI_quest_starter_Text_4
	goto JIRACHI_quest_starter_4


MossdeepCity_EventScript_Rocket::
# 458 "data/maps/MossdeepCity/scripts.pory"
	lockall
# 459 "data/maps/MossdeepCity/scripts.pory"
	goto_if_unset FLAG_ARCEUS_ROCKET_UNLOCKED, MossdeepCity_EventScript_Rocket_2
# 464 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_EventScript_Rocket_Text_1, MSGBOX_YESNO
# 465 "data/maps/MossdeepCity/scripts.pory"
	compare VAR_RESULT, YES
	goto_if_eq MossdeepCity_EventScript_Rocket_5
# 475 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_EventScript_Rocket_Text_3
# 476 "data/maps/MossdeepCity/scripts.pory"
	releaseall
	end

MossdeepCity_EventScript_Rocket_2:
# 460 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_EventScript_Rocket_Text_0
# 461 "data/maps/MossdeepCity/scripts.pory"
	releaseall
	end

MossdeepCity_EventScript_Rocket_5:
# 466 "data/maps/MossdeepCity/scripts.pory"
	msgbox MossdeepCity_EventScript_Rocket_Text_2, MSGBOX_AUTOCLOSE
# 467 "data/maps/MossdeepCity/scripts.pory"
	fadescreen FADE_TO_BLACK
# 468 "data/maps/MossdeepCity/scripts.pory"
	playse SE_M_EXPLOSION
# 469 "data/maps/MossdeepCity/scripts.pory"
	delay 60
# 470 "data/maps/MossdeepCity/scripts.pory"
	warp MAP_SPACE_METEOR, 15, 41
# 471 "data/maps/MossdeepCity/scripts.pory"
	waitstate
# 472 "data/maps/MossdeepCity/scripts.pory"
	releaseall
	end


GiftAuroraTicketScript::
# 481 "data/maps/MossdeepCity/scripts.pory"
	lock
# 482 "data/maps/MossdeepCity/scripts.pory"
	faceplayer
# 483 "data/maps/MossdeepCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_AURORA_TICKET, GiftAuroraTicketScript_2
# 489 "data/maps/MossdeepCity/scripts.pory"
	msgbox GiftAuroraTicketScript_Text_1
# 492 "data/maps/MossdeepCity/scripts.pory"
	giveitem ITEM_AURORA_TICKET
# 493 "data/maps/MossdeepCity/scripts.pory"
	startquest QUEST_DEOXYS
# 494 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_RECEIVED_AURORA_TICKET
# 495 "data/maps/MossdeepCity/scripts.pory"
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
# 496 "data/maps/MossdeepCity/scripts.pory"
	msgbox GiftAuroraTicketScript_Text_2
# 498 "data/maps/MossdeepCity/scripts.pory"
	release
	end

GiftAuroraTicketScript_2:
# 484 "data/maps/MossdeepCity/scripts.pory"
	msgbox GiftAuroraTicketScript_Text_0
# 486 "data/maps/MossdeepCity/scripts.pory"
	release
	end


JIRACHI_quest_starter_Text_0:
# 435 "data/maps/MossdeepCity/scripts.pory"
	.string "Have you made a wish yet?$"

JIRACHI_quest_starter_Text_1:
# 439 "data/maps/MossdeepCity/scripts.pory"
	.string "Have you ever made a wish? Like one you\n"
	.string "really wanted to come true? I know a\l"
	.string "place where any wish you make comes\l"
	.string "true, supposedly it's all thanks to 'The\l"
	.string "Wishmaker'.$"

JIRACHI_quest_starter_Text_2:
# 441 "data/maps/MossdeepCity/scripts.pory"
	.string "That Old Sea Map! Let me see it!\p"
	.string "Let the stranger draw on the map?$"

JIRACHI_quest_starter_Text_3:
# 446 "data/maps/MossdeepCity/scripts.pory"
	.string "Go to Pacifidlog Town. A sailor there\n"
	.string "will take you to where all wishes come\l"
	.string "true!$"

JIRACHI_quest_starter_Text_4:
# 448 "data/maps/MossdeepCity/scripts.pory"
	.string "You don't know what you're missing out\n"
	.string "on.$"

JIRACHI_quest_starter_Text_5:
# 451 "data/maps/MossdeepCity/scripts.pory"
	.string "But you'll need an Old Sea Map to find\n"
	.string "your way there. Track one down, then\l"
	.string "come back and show me. I'll point you\l"
	.string "the right way.$"

MossdeepCity_EventScript_Rocket_Text_0:
# 460 "data/maps/MossdeepCity/scripts.pory"
	.string "A sealed launch rocket. Its systems are\n"
	.string "dark, there's no way to board it yet.$"

MossdeepCity_EventScript_Rocket_Text_1:
# 464 "data/maps/MossdeepCity/scripts.pory"
	.string "The rocket is primed for launch.\n"
	.string "Board it and fly to the Space Meteor?$"

MossdeepCity_EventScript_Rocket_Text_2:
# 466 "data/maps/MossdeepCity/scripts.pory"
	.string "You strap in. The countdown begins...$"

MossdeepCity_EventScript_Rocket_Text_3:
# 475 "data/maps/MossdeepCity/scripts.pory"
	.string "Maybe another day, then.$"

GiftAuroraTicketScript_Text_0:
# 484 "data/maps/MossdeepCity/scripts.pory"
	.string "The Aurora Ticket is yours already!\n"
	.string "Birth Island calls those it senses want\l"
	.string "to dance with the stars!$"

GiftAuroraTicketScript_Text_1:
# 489 "data/maps/MossdeepCity/scripts.pory"
	.string "Y'know.. being a man of science,\n"
	.string "you're naturally skeptical of the\l"
	.string "supernatural.\l"
	.string "Go to this island. See what I saw.\l"
	.string "Become a believer.$"

GiftAuroraTicketScript_Text_2:
# 496 "data/maps/MossdeepCity/scripts.pory"
	.string "Board the ferry at Lilycove City.\n"
	.string "Our eyes can't lie to us... Right?$"
