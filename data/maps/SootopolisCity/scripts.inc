# 1 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_MapScripts::
# 2 "data/maps/SootopolisCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_OnLoad
# 3 "data/maps/SootopolisCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_OnTransition
# 4 "data/maps/SootopolisCity/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_OnResume
# 5 "data/maps/SootopolisCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_OnFrame
# 6 "data/maps/SootopolisCity/scripts.pory"
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SootopolisCity_OnWarp
# 7 "data/maps/SootopolisCity/scripts.pory"
	.byte 0
# 8 "data/maps/SootopolisCity/scripts.pory"

# 9 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_OnLoad:
# 10 "data/maps/SootopolisCity/scripts.pory"
	call_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_LockGymDoor
# 11 "data/maps/SootopolisCity/scripts.pory"
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_EventScript_LegendariesNotArrived
# 12 "data/maps/SootopolisCity/scripts.pory"
	call_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_LockHouseDoors
# 13 "data/maps/SootopolisCity/scripts.pory"
	end
# 14 "data/maps/SootopolisCity/scripts.pory"

# 15 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LegendariesNotArrived::
# 16 "data/maps/SootopolisCity/scripts.pory"
	end
# 17 "data/maps/SootopolisCity/scripts.pory"

# 18 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LockHouseDoors::
# 19 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 9, 6, METATILE_Sootopolis_Door_Closed, TRUE
# 20 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 9, 17, METATILE_Sootopolis_Door_Closed, TRUE
# 21 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 9, 26, METATILE_Sootopolis_Door_Closed, TRUE
# 22 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 44, 17, METATILE_Sootopolis_Door_Closed, TRUE
# 23 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 8, 35, METATILE_Sootopolis_Door_Closed, TRUE
# 24 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 53, 28, METATILE_Sootopolis_Door_Closed, TRUE
# 25 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 45, 6, METATILE_Sootopolis_Door_Closed, TRUE
# 26 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 48, 25, METATILE_Sootopolis_Door_Closed, TRUE
# 27 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 51, 36, METATILE_Sootopolis_Door_Closed, TRUE
# 28 "data/maps/SootopolisCity/scripts.pory"
	return
# 29 "data/maps/SootopolisCity/scripts.pory"

# 30 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LockGymDoor::
# 31 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 31, 32, METATILE_Sootopolis_GymDoor_Closed, TRUE
# 32 "data/maps/SootopolisCity/scripts.pory"
	return
# 33 "data/maps/SootopolisCity/scripts.pory"

# 34 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_OnTransition:
# 35 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_VISITED_SOOTOPOLIS_CITY
# 36 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_HideMapNamePopup
# 37 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_HideMapNamePopup
# 38 "data/maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetWeather
# 39 "data/maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetLayout
# 40 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_SetBattleSpectators
# 41 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_SetBattleSpectators
# 42 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_SetBattleSpectators
# 43 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_SetBattleSpectators
# 44 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_SetBattleSpectators
# 45 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos
# 46 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos
# 47 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_SetExitCaveOfOriginObjPos
# 48 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_SetOutsideGymObjPos
# 49 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_SetExpertBlockCaveEntrance
# 50 "data/maps/SootopolisCity/scripts.pory"
	end
# 51 "data/maps/SootopolisCity/scripts.pory"

# 52 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_HideMapNamePopup::
# 53 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_HIDE_MAP_NAME_POPUP
# 54 "data/maps/SootopolisCity/scripts.pory"
	return
# 55 "data/maps/SootopolisCity/scripts.pory"

# 56 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetBattleSpectators::
# 57 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_KIRI, 13, 48
# 58 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_BOY_1, 46, 32
# 59 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_NINJA_BOY, 48, 41
# 60 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_WOMAN_1, 45, 43
# 61 "data/maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_KIRI, MOVEMENT_TYPE_FACE_UP
# 62 "data/maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_SOOTOPOLIS_BOY_1, MOVEMENT_TYPE_FACE_LEFT
# 63 "data/maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_SOOTOPOLIS_NINJA_BOY, MOVEMENT_TYPE_FACE_LEFT
# 64 "data/maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_SOOTOPOLIS_WOMAN_1, MOVEMENT_TYPE_FACE_LEFT
# 65 "data/maps/SootopolisCity/scripts.pory"
	return
# 66 "data/maps/SootopolisCity/scripts.pory"

# 67 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetLayout::
# 68 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0, SootopolisCity_EventScript_SetNormalLayout
# 69 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_SetNormalLayout
# 70 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_SetLegendariesLayout
# 71 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_SetLegendariesLayout
# 72 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_SetLegendariesLayout
# 73 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_SetLegendariesLayout
# 74 "data/maps/SootopolisCity/scripts.pory"
	goto_if_le VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_SetLegendariesLayout
# 75 "data/maps/SootopolisCity/scripts.pory"
	return
# 76 "data/maps/SootopolisCity/scripts.pory"

# 77 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetNormalLayout::
# 78 "data/maps/SootopolisCity/scripts.pory"
	return
# 79 "data/maps/SootopolisCity/scripts.pory"

# 80 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetLegendariesLayout::
# 81 "data/maps/SootopolisCity/scripts.pory"
	setmaplayoutindex LAYOUT_SOOTOPOLIS_CITY_LEGENDS_BATTLE
# 82 "data/maps/SootopolisCity/scripts.pory"
	return
# 83 "data/maps/SootopolisCity/scripts.pory"

# 84 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetWeather::
# 85 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 0, SootopolisCity_EventScript_SetNormalWeather
# 86 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_SetNormalWeather
# 87 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_SetDownpour
# 88 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_SetDownpour
# 89 "data/maps/SootopolisCity/scripts.pory"
	goto_if_le VAR_SKY_PILLAR_STATE, 1, Common_EventScript_SetAbnormalWeather
# 90 "data/maps/SootopolisCity/scripts.pory"
	return
# 91 "data/maps/SootopolisCity/scripts.pory"

# 92 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetNormalWeather::
# 93 "data/maps/SootopolisCity/scripts.pory"
	return
# 94 "data/maps/SootopolisCity/scripts.pory"

# 95 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetDownpour::
# 96 "data/maps/SootopolisCity/scripts.pory"
	setweather WEATHER_DOWNPOUR
# 97 "data/maps/SootopolisCity/scripts.pory"
	return
# 98 "data/maps/SootopolisCity/scripts.pory"

# 99 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_CheckSetEnterCaveOfOriginObjPos::
# 100 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN, SootopolisCity_EventScript_SetEnterCaveOfOriginObjPos
# 101 "data/maps/SootopolisCity/scripts.pory"
	return
# 102 "data/maps/SootopolisCity/scripts.pory"

# 103 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetEnterCaveOfOriginObjPos::
# 104 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_EXPERT, 30, 18
# 105 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_STEVEN, 32, 18
# 106 "data/maps/SootopolisCity/scripts.pory"
	return
# 107 "data/maps/SootopolisCity/scripts.pory"

# 108 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetExitCaveOfOriginObjPos::
# 109 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_EXPERT, 30, 18
# 110 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_WALLACE, 31, 18
# 111 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_STEVEN, 32, 18
# 112 "data/maps/SootopolisCity/scripts.pory"
	end
# 113 "data/maps/SootopolisCity/scripts.pory"

# 114 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetOutsideGymObjPos::
# 115 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_EXPERT, 31, 18
# 116 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_STEVEN, 29, 33
# 117 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_MAXIE, 33, 35
# 118 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_ARCHIE, 34, 35
# 119 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_WALLACE_STATE, 0, SootopolisCity_EventScript_SetWallaceMiddle
# 120 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_WALLACE_STATE, 1, SootopolisCity_EventScript_SetWallaceRight
# 121 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SOOTOPOLIS_WALLACE_STATE, 2, SootopolisCity_EventScript_SetWallaceLeft
# 122 "data/maps/SootopolisCity/scripts.pory"
	return
# 123 "data/maps/SootopolisCity/scripts.pory"

# 124 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetWallaceMiddle::
# 125 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_WALLACE, 31, 33
# 126 "data/maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_SOOTOPOLIS_WALLACE, MOVEMENT_TYPE_FACE_DOWN
# 127 "data/maps/SootopolisCity/scripts.pory"
	return
# 128 "data/maps/SootopolisCity/scripts.pory"

# 129 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetWallaceRight::
# 130 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_WALLACE, 32, 33
# 131 "data/maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_SOOTOPOLIS_WALLACE, MOVEMENT_TYPE_FACE_DOWN
# 132 "data/maps/SootopolisCity/scripts.pory"
	return
# 133 "data/maps/SootopolisCity/scripts.pory"

# 134 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetWallaceLeft::
# 135 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_WALLACE, 30, 33
# 136 "data/maps/SootopolisCity/scripts.pory"
	setobjectmovementtype LOCALID_SOOTOPOLIS_WALLACE, MOVEMENT_TYPE_FACE_DOWN
# 137 "data/maps/SootopolisCity/scripts.pory"
	return
# 138 "data/maps/SootopolisCity/scripts.pory"

# 139 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetExpertBlockCaveEntrance::
# 140 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_EXPERT, 31, 18
# 141 "data/maps/SootopolisCity/scripts.pory"
	return
# 142 "data/maps/SootopolisCity/scripts.pory"

# 143 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_OnWarp:
# 144 "data/maps/SootopolisCity/scripts.pory"
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_PlayerFaceLegendaries
# 145 "data/maps/SootopolisCity/scripts.pory"
	.2byte 0
# 146 "data/maps/SootopolisCity/scripts.pory"

# 147 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_PlayerFaceLegendaries::
# 148 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_PlayerFaceLegendaries1
# 149 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SKY_PILLAR_STATE, 2, SootopolisCity_EventScript_PlayerFaceLegendaries2
# 150 "data/maps/SootopolisCity/scripts.pory"
	end
# 151 "data/maps/SootopolisCity/scripts.pory"

# 152 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_PlayerFaceLegendaries1::
# 153 "data/maps/SootopolisCity/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 154 "data/maps/SootopolisCity/scripts.pory"
	return
# 155 "data/maps/SootopolisCity/scripts.pory"

# 156 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_PlayerFaceLegendaries2::
# 157 "data/maps/SootopolisCity/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 158 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SKY_PILLAR_STATE, 3
# 159 "data/maps/SootopolisCity/scripts.pory"
	return
# 160 "data/maps/SootopolisCity/scripts.pory"

# 161 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_OnResume:
# 162 "data/maps/SootopolisCity/scripts.pory"
	setdivewarp MAP_UNDERWATER_SOOTOPOLIS_CITY, 9, 6
# 163 "data/maps/SootopolisCity/scripts.pory"
	end
# 164 "data/maps/SootopolisCity/scripts.pory"

# 165 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_OnFrame:
# 166 "data/maps/SootopolisCity/scripts.pory"
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_StartLegendariesScene
# 167 "data/maps/SootopolisCity/scripts.pory"
	map_script_2 VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_StartRayquazaScene
# 168 "data/maps/SootopolisCity/scripts.pory"
	.2byte 0
# 169 "data/maps/SootopolisCity/scripts.pory"

# 170 "data/maps/SootopolisCity/scripts.pory"
@ If not at PokeCenter, assumed to have arrived via Dive
# 171 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartLegendariesScene::
# 172 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 173 "data/maps/SootopolisCity/scripts.pory"
	special StorePlayerCoordsInVars
# 174 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ne VAR_0x8004, 43, SootopolisCity_EventScript_LegendariesSceneFromDive
# 175 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ne VAR_0x8005, 32, SootopolisCity_EventScript_LegendariesSceneFromDive
# 176 "data/maps/SootopolisCity/scripts.pory"
	goto SootopolisCity_EventScript_LegendariesSceneFromPokeCenter
# 177 "data/maps/SootopolisCity/scripts.pory"
	end
# 178 "data/maps/SootopolisCity/scripts.pory"

# 179 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LegendariesSceneFromPokeCenter::
# 180 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 181 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 182 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromPokeCenter
# 183 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 184 "data/maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 185 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 186 "data/maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 187 "data/maps/SootopolisCity/scripts.pory"
	setweather WEATHER_ABNORMAL
# 188 "data/maps/SootopolisCity/scripts.pory"
	doweather
# 189 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, FALSE @ Just do Groudon/Kyogre fight scene
# 190 "data/maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 191 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, Common_Movement_WalkInPlaceFasterLeft
# 192 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, Common_Movement_WalkInPlaceFasterRight
# 193 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 194 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 195 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 196 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
# 197 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 198 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
# 199 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 200 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 201 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 202 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 203 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 204 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 205 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 206 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 207 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 208 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 209 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 210 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
# 211 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreDefend
# 212 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonAttack
# 213 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 214 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 215 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 216 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 217 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 218 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 219 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 220 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 221 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 222 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 223 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 224 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
# 225 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 226 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
# 227 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 228 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 229 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 230 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 231 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 232 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 233 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 234 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 235 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 236 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 237 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 238 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreIdle
# 239 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonIdle
# 240 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanBackToPokeCenter
# 241 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 242 "data/maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 243 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_CITY_STATE, 2
# 244 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 245 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 246 "data/maps/SootopolisCity/scripts.pory"
	end
# 247 "data/maps/SootopolisCity/scripts.pory"

# 248 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanToActionFromPokeCenter:
# 249 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 250 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 251 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 252 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 253 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 254 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 255 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 256 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 257 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 258 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 259 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 260 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 261 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 262 "data/maps/SootopolisCity/scripts.pory"

# 263 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanBackToPokeCenter:
# 264 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 265 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 266 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 267 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 268 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 269 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 270 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 271 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 272 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 273 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 274 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 275 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 276 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 277 "data/maps/SootopolisCity/scripts.pory"

# 278 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LegendariesSceneFromDive::
# 279 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 280 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 281 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromDive
# 282 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 283 "data/maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 284 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 285 "data/maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 286 "data/maps/SootopolisCity/scripts.pory"
	setweather WEATHER_ABNORMAL
# 287 "data/maps/SootopolisCity/scripts.pory"
	doweather
# 288 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, FALSE @ Just do Groudon/Kyogre fight scene
# 289 "data/maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 290 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, Common_Movement_WalkInPlaceFasterLeft
# 291 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, Common_Movement_WalkInPlaceFasterRight
# 292 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 293 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 294 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 295 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
# 296 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 297 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
# 298 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 299 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 300 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 301 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 302 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 303 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 304 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 305 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 306 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 307 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 308 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 309 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
# 310 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreDefend
# 311 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonAttack
# 312 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 313 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 314 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 315 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 316 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 317 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 318 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 319 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 320 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 321 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 322 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 323 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
# 324 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 325 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
# 326 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 327 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 328 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 329 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 330 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 331 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 332 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 333 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 334 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 335 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 336 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 337 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreIdle
# 338 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonIdle
# 339 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanBackToDive
# 340 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 341 "data/maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 342 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_CITY_STATE, 2
# 343 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 344 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 345 "data/maps/SootopolisCity/scripts.pory"
	end
# 346 "data/maps/SootopolisCity/scripts.pory"

# 347 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanToActionFromDive:
# 348 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 349 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 350 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 351 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 352 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 353 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 354 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 355 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 356 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 357 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 358 "data/maps/SootopolisCity/scripts.pory"

# 359 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanBackToDive:
# 360 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 361 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 362 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 363 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 364 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 365 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 366 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 367 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 368 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 369 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 370 "data/maps/SootopolisCity/scripts.pory"

# 371 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreAttack:
# 372 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 373 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 374 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 375 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 376 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 377 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 378 "data/maps/SootopolisCity/scripts.pory"
	init_affine_anim
# 379 "data/maps/SootopolisCity/scripts.pory"
	walk_left_affine
# 380 "data/maps/SootopolisCity/scripts.pory"
	clear_affine_anim
# 381 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 382 "data/maps/SootopolisCity/scripts.pory"

# 383 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreDefend:
# 384 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 385 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 386 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 387 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 388 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 389 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 390 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 391 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 392 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 393 "data/maps/SootopolisCity/scripts.pory"
	init_affine_anim
# 394 "data/maps/SootopolisCity/scripts.pory"
	walk_left_affine
# 395 "data/maps/SootopolisCity/scripts.pory"
	clear_affine_anim
# 396 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 397 "data/maps/SootopolisCity/scripts.pory"

# 398 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreMoveBack:
# 399 "data/maps/SootopolisCity/scripts.pory"
	lock_facing_direction
# 400 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 401 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 402 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 403 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 404 "data/maps/SootopolisCity/scripts.pory"
	unlock_facing_direction
# 405 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 406 "data/maps/SootopolisCity/scripts.pory"

# 407 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreIdle:
# 408 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 409 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 410 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 411 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 412 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 413 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 414 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 415 "data/maps/SootopolisCity/scripts.pory"

# 416 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonAttack:
# 417 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 418 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 419 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 420 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 421 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 422 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 423 "data/maps/SootopolisCity/scripts.pory"
	walk_fast_right
# 424 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 425 "data/maps/SootopolisCity/scripts.pory"

# 426 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonDefend:
# 427 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 428 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 429 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 430 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 431 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 432 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 433 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 434 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 435 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 436 "data/maps/SootopolisCity/scripts.pory"
	walk_fast_right
# 437 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 438 "data/maps/SootopolisCity/scripts.pory"

# 439 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonMoveBack:
# 440 "data/maps/SootopolisCity/scripts.pory"
	lock_facing_direction
# 441 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 442 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 443 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 444 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 445 "data/maps/SootopolisCity/scripts.pory"
	unlock_facing_direction
# 446 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 447 "data/maps/SootopolisCity/scripts.pory"

# 448 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonIdle:
# 449 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 450 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 451 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 452 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 453 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 454 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 455 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 456 "data/maps/SootopolisCity/scripts.pory"

# 457 "data/maps/SootopolisCity/scripts.pory"
@ If not at PokeCenter, assumed to have arrived via Dive
# 458 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartRayquazaScene::
# 459 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 460 "data/maps/SootopolisCity/scripts.pory"
	special StorePlayerCoordsInVars
# 461 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ne VAR_0x8004, 43, SootopolisCity_EventScript_RayquazaSceneFromDive
# 462 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ne VAR_0x8005, 32, SootopolisCity_EventScript_RayquazaSceneFromDive
# 463 "data/maps/SootopolisCity/scripts.pory"
	goto SootopolisCity_EventScript_RayquazaSceneFromPokeCenter
# 464 "data/maps/SootopolisCity/scripts.pory"
	end
# 465 "data/maps/SootopolisCity/scripts.pory"

# 466 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_RayquazaSceneFromPokeCenter::
# 467 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 468 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 469 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromPokeCenter
# 470 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 471 "data/maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 472 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 473 "data/maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 474 "data/maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetRoughWater
# 475 "data/maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_GROUDON
# 476 "data/maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_KYOGRE
# 477 "data/maps/SootopolisCity/scripts.pory"
	addobject LOCALID_SOOTOPOLIS_RAYQUAZA
# 478 "data/maps/SootopolisCity/scripts.pory"
	hideobjectat LOCALID_SOOTOPOLIS_RAYQUAZA, MAP_SOOTOPOLIS_CITY
# 479 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, TRUE
# 480 "data/maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 481 "data/maps/SootopolisCity/scripts.pory"
	playse SE_THUNDER
# 482 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 483 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanUp
# 484 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 485 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 486 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 487 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 488 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 489 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 490 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 491 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 492 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 493 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 494 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 495 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 496 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 497 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 498 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 499 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 500 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 501 "data/maps/SootopolisCity/scripts.pory"
	waitmoncry
# 502 "data/maps/SootopolisCity/scripts.pory"
	setweather WEATHER_NONE
# 503 "data/maps/SootopolisCity/scripts.pory"
	doweather
# 504 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_RAYQUAZA, SootopolisCity_Movement_RayquazaFlyOff
# 505 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 506 "data/maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_RAYQUAZA
# 507 "data/maps/SootopolisCity/scripts.pory"
	special WaitWeather
# 508 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_SYS_WEATHER_CTRL
# 509 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SKY_PILLAR_STATE, 3
# 510 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
# 511 "data/maps/SootopolisCity/scripts.pory"
	fadenewbgm MUS_SOOTOPOLIS
# 512 "data/maps/SootopolisCity/scripts.pory"
	delay 120
# 513 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 514 "data/maps/SootopolisCity/scripts.pory"
	warpwhitefade MAP_SOOTOPOLIS_CITY, 43, 32
# 515 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 516 "data/maps/SootopolisCity/scripts.pory"
	end
# 517 "data/maps/SootopolisCity/scripts.pory"

# 518 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_RayquazaSceneFromDive::
# 519 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 520 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 521 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromDive
# 522 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 523 "data/maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 524 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 525 "data/maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 526 "data/maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetRoughWater
# 527 "data/maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_GROUDON
# 528 "data/maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_KYOGRE
# 529 "data/maps/SootopolisCity/scripts.pory"
	addobject LOCALID_SOOTOPOLIS_RAYQUAZA
# 530 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, TRUE
# 531 "data/maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 532 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 533 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanUp
# 534 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerApproachLegendaries
# 535 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 536 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 537 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 538 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 539 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 540 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 541 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 542 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 543 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 544 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 545 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 546 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 547 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 548 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 549 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 550 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 551 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 552 "data/maps/SootopolisCity/scripts.pory"
	waitmoncry
# 553 "data/maps/SootopolisCity/scripts.pory"
	setweather WEATHER_NONE
# 554 "data/maps/SootopolisCity/scripts.pory"
	doweather
# 555 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_RAYQUAZA, SootopolisCity_Movement_RayquazaFlyOff
# 556 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 557 "data/maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_RAYQUAZA
# 558 "data/maps/SootopolisCity/scripts.pory"
	special WaitWeather
# 559 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_SYS_WEATHER_CTRL
# 560 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SKY_PILLAR_STATE, 2
# 561 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
# 562 "data/maps/SootopolisCity/scripts.pory"
	fadenewbgm MUS_SURF
# 563 "data/maps/SootopolisCity/scripts.pory"
	delay 120
# 564 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 565 "data/maps/SootopolisCity/scripts.pory"
	warpwhitefade MAP_SOOTOPOLIS_CITY, 29, 53
# 566 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 567 "data/maps/SootopolisCity/scripts.pory"
	end
# 568 "data/maps/SootopolisCity/scripts.pory"

# 569 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetRoughWater::
# 570 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 27, 43, METATILE_Sootopolis_RoughWater, FALSE
# 571 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 28, 43, METATILE_Sootopolis_RoughWater, FALSE
# 572 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 29, 43, METATILE_Sootopolis_RoughWater, FALSE
# 573 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 30, 43, METATILE_Sootopolis_RoughWater, FALSE
# 574 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 27, 44, METATILE_Sootopolis_RoughWater, FALSE
# 575 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 28, 44, METATILE_Sootopolis_RoughWater, FALSE
# 576 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 29, 44, METATILE_Sootopolis_RoughWater, FALSE
# 577 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 30, 44, METATILE_Sootopolis_RoughWater, FALSE
# 578 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 27, 45, METATILE_Sootopolis_RoughWater, FALSE
# 579 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 28, 45, METATILE_Sootopolis_RoughWater, FALSE
# 580 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 29, 45, METATILE_Sootopolis_RoughWater, FALSE
# 581 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 30, 45, METATILE_Sootopolis_RoughWater, FALSE
# 582 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 32, 43, METATILE_Sootopolis_RoughWater, FALSE
# 583 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 33, 43, METATILE_Sootopolis_RoughWater, FALSE
# 584 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 34, 43, METATILE_Sootopolis_RoughWater, FALSE
# 585 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 35, 43, METATILE_Sootopolis_RoughWater, FALSE
# 586 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 32, 44, METATILE_Sootopolis_RoughWater, FALSE
# 587 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 33, 44, METATILE_Sootopolis_RoughWater, FALSE
# 588 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 34, 44, METATILE_Sootopolis_RoughWater, FALSE
# 589 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 35, 44, METATILE_Sootopolis_RoughWater, FALSE
# 590 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 32, 45, METATILE_Sootopolis_RoughWater, FALSE
# 591 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 33, 45, METATILE_Sootopolis_RoughWater, FALSE
# 592 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 34, 45, METATILE_Sootopolis_RoughWater, FALSE
# 593 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 35, 45, METATILE_Sootopolis_RoughWater, FALSE
# 594 "data/maps/SootopolisCity/scripts.pory"
	return
# 595 "data/maps/SootopolisCity/scripts.pory"

# 596 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_RayquazaFlyOff:
# 597 "data/maps/SootopolisCity/scripts.pory"
	walk_fast_up
# 598 "data/maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 599 "data/maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 600 "data/maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 601 "data/maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 602 "data/maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 603 "data/maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 604 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 605 "data/maps/SootopolisCity/scripts.pory"

# 606 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanUp:
# 607 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 608 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 609 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 610 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 611 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 612 "data/maps/SootopolisCity/scripts.pory"

# 613 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerApproachLegendaries:
# 614 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 615 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 616 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 617 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 618 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 619 "data/maps/SootopolisCity/scripts.pory"

# 620 "data/maps/SootopolisCity/scripts.pory"
@ Unused
# 621 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerApproachLegendariesDown:
# 622 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 623 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 624 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 625 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 626 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 627 "data/maps/SootopolisCity/scripts.pory"

# 628 "data/maps/SootopolisCity/scripts.pory"
@ Unused
# 629 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_UnusedPanUp:
# 630 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 631 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 632 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 633 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 634 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 635 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 636 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 637 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 638 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 639 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 640 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 641 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 642 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 643 "data/maps/SootopolisCity/scripts.pory"

# 644 "data/maps/SootopolisCity/scripts.pory"
@ Unused
# 645 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_UnusedPanBack:
# 646 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 647 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 648 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 649 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 650 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 651 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 652 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 653 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 654 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 655 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 656 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 657 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 658 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 659 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 660 "data/maps/SootopolisCity/scripts.pory"

# 661 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_CaveOfOriginExpert::
# 662 "data/maps/SootopolisCity/scripts.pory"
	lock
# 663 "data/maps/SootopolisCity/scripts.pory"
	faceplayer
# 664 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_ExpertPostLegendaries
# 665 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ExpertLegendaries
# 666 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_ExpertLeadToCave
# 667 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CaveOfOriginPleaseLeave, MSGBOX_DEFAULT
# 668 "data/maps/SootopolisCity/scripts.pory"
	release
# 669 "data/maps/SootopolisCity/scripts.pory"
	end
# 670 "data/maps/SootopolisCity/scripts.pory"

# 671 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ExpertLeadToCave::
# 672 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_LeadSuperiorTrainerToCave, MSGBOX_DEFAULT
# 673 "data/maps/SootopolisCity/scripts.pory"
	release
# 674 "data/maps/SootopolisCity/scripts.pory"
	end
# 675 "data/maps/SootopolisCity/scripts.pory"

# 676 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ExpertPostLegendaries::
# 677 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CaveOfOriginSleepsToo, MSGBOX_DEFAULT
# 678 "data/maps/SootopolisCity/scripts.pory"
	release
# 679 "data/maps/SootopolisCity/scripts.pory"
	end
# 680 "data/maps/SootopolisCity/scripts.pory"

# 681 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ExpertLegendaries::
# 682 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_AwakenedPokemonClash, MSGBOX_DEFAULT
# 683 "data/maps/SootopolisCity/scripts.pory"
	release
# 684 "data/maps/SootopolisCity/scripts.pory"
	end
# 685 "data/maps/SootopolisCity/scripts.pory"

# 686 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Kiri::
# 687 "data/maps/SootopolisCity/scripts.pory"
	lock
# 688 "data/maps/SootopolisCity/scripts.pory"
	faceplayer
# 689 "data/maps/SootopolisCity/scripts.pory"
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_KiriGiveBerry
# 690 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_KiriGiveBerry
# 691 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_KiriRayquaza
# 692 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_BigPokemonFighting, MSGBOX_DEFAULT
# 693 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 694 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KIRI, Common_Movement_FaceOriginalDirection
# 695 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 696 "data/maps/SootopolisCity/scripts.pory"
	release
# 697 "data/maps/SootopolisCity/scripts.pory"
	end
# 698 "data/maps/SootopolisCity/scripts.pory"

# 699 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriRayquaza::
# 700 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_PrettyMonCameFromSky, MSGBOX_DEFAULT
# 701 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 702 "data/maps/SootopolisCity/scripts.pory"
	release
# 703 "data/maps/SootopolisCity/scripts.pory"
	end
# 704 "data/maps/SootopolisCity/scripts.pory"

# 705 "data/maps/SootopolisCity/scripts.pory"
@ Gives 2 berries daily. First ranges from BERRY_ID_POMEG to BERRY_ID_NOMEL, second is always Figy or Iapapa
# 706 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriGiveBerry::
# 707 "data/maps/SootopolisCity/scripts.pory"
	dotimebasedevents
# 708 "data/maps/SootopolisCity/scripts.pory"
	special GetPlayerBigGuyGirlString
# 709 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY, SootopolisCity_EventScript_KiriReceivedBerry
# 710 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NameIsKiriHaveOneOfThese, MSGBOX_DEFAULT
# 711 "data/maps/SootopolisCity/scripts.pory"
	giverandomberry BERRY_ID_POMEG, BERRY_ID_NOMEL
# 712 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 713 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY
# 714 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GiveYouThisBerryToo, MSGBOX_DEFAULT
# 715 "data/maps/SootopolisCity/scripts.pory"
	random 2
# 716 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SootopolisCity_EventScript_GiveFigyBerry
# 717 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SootopolisCity_EventScript_GiveIapapaBerry
# 718 "data/maps/SootopolisCity/scripts.pory"
	end
# 719 "data/maps/SootopolisCity/scripts.pory"

# 720 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GiveFigyBerry::
# 721 "data/maps/SootopolisCity/scripts.pory"
	giveitem ITEM_FIGY_BERRY
# 722 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 723 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
# 724 "data/maps/SootopolisCity/scripts.pory"
	release
# 725 "data/maps/SootopolisCity/scripts.pory"
	end
# 726 "data/maps/SootopolisCity/scripts.pory"

# 727 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GiveIapapaBerry::
# 728 "data/maps/SootopolisCity/scripts.pory"
	giveitem ITEM_IAPAPA_BERRY
# 729 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 730 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
# 731 "data/maps/SootopolisCity/scripts.pory"
	release
# 732 "data/maps/SootopolisCity/scripts.pory"
	end
# 733 "data/maps/SootopolisCity/scripts.pory"

# 734 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriReceivedBerry::
# 735 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_LikeSeasonBornIn, MSGBOX_YESNO
# 736 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SootopolisCity_EventScript_KiriLikeSeasonBornIn
# 737 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_OhDoesntMatter, MSGBOX_DEFAULT
# 738 "data/maps/SootopolisCity/scripts.pory"
	release
# 739 "data/maps/SootopolisCity/scripts.pory"
	end
# 740 "data/maps/SootopolisCity/scripts.pory"

# 741 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriLikeSeasonBornIn::
# 742 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThenILoveAutumn, MSGBOX_DEFAULT
# 743 "data/maps/SootopolisCity/scripts.pory"
	release
# 744 "data/maps/SootopolisCity/scripts.pory"
	end
# 745 "data/maps/SootopolisCity/scripts.pory"

# 746 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman2::
# 747 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 748 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_WOMAN_2, Common_Movement_FacePlayer
# 749 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 750 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Woman2Rayquaza
# 751 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WeatherWentWild, MSGBOX_DEFAULT
# 752 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 753 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_WOMAN_2, Common_Movement_FaceOriginalDirection
# 754 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 755 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 756 "data/maps/SootopolisCity/scripts.pory"
	end
# 757 "data/maps/SootopolisCity/scripts.pory"

# 758 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman2Rayquaza::
# 759 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_YouBroughtFlyingMon, MSGBOX_DEFAULT
# 760 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 761 "data/maps/SootopolisCity/scripts.pory"
	end
# 762 "data/maps/SootopolisCity/scripts.pory"

# 763 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Man::
# 764 "data/maps/SootopolisCity/scripts.pory"
	lock
# 765 "data/maps/SootopolisCity/scripts.pory"
	faceplayer
# 766 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_ManPostLegendaries
# 767 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NoOrdinaryTourist, MSGBOX_DEFAULT
# 768 "data/maps/SootopolisCity/scripts.pory"
	release
# 769 "data/maps/SootopolisCity/scripts.pory"
	end
# 770 "data/maps/SootopolisCity/scripts.pory"

# 771 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ManPostLegendaries::
# 772 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CityRegainedCalm, MSGBOX_DEFAULT
# 773 "data/maps/SootopolisCity/scripts.pory"
	release
# 774 "data/maps/SootopolisCity/scripts.pory"
	end
# 775 "data/maps/SootopolisCity/scripts.pory"

# 776 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1::
# 777 "data/maps/SootopolisCity/scripts.pory"
	lock
# 778 "data/maps/SootopolisCity/scripts.pory"
	faceplayer
# 779 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_Woman1PostLegendaries
# 780 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Woman1Rayquaza
# 781 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_Woman1Legendaries
# 782 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SootopolisSkyBeautiful, MSGBOX_DEFAULT
# 783 "data/maps/SootopolisCity/scripts.pory"
	release
# 784 "data/maps/SootopolisCity/scripts.pory"
	end
# 785 "data/maps/SootopolisCity/scripts.pory"

# 786 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1Legendaries::
# 787 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GiganticPokemonFight, MSGBOX_DEFAULT
# 788 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 789 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_WOMAN_1, Common_Movement_FaceOriginalDirection
# 790 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 791 "data/maps/SootopolisCity/scripts.pory"
	release
# 792 "data/maps/SootopolisCity/scripts.pory"
	end
# 793 "data/maps/SootopolisCity/scripts.pory"

# 794 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1PostLegendaries::
# 795 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NightSkyFavoriteScenery, MSGBOX_DEFAULT
# 796 "data/maps/SootopolisCity/scripts.pory"
	release
# 797 "data/maps/SootopolisCity/scripts.pory"
	end
# 798 "data/maps/SootopolisCity/scripts.pory"

# 799 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1Rayquaza::
# 800 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_FearedWorstWhenPokemonFlewDown, MSGBOX_DEFAULT
# 801 "data/maps/SootopolisCity/scripts.pory"
	release
# 802 "data/maps/SootopolisCity/scripts.pory"
	end
# 803 "data/maps/SootopolisCity/scripts.pory"

# 804 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_NinjaBoy::
# 805 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 806 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_NINJA_BOY, Common_Movement_FacePlayer
# 807 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 808 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_NinjaBoyRayquaza
# 809 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_NinjaBoyNormal
# 810 "data/maps/SootopolisCity/scripts.pory"
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_NinjaBoyNormal
# 811 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThisIsWicked, MSGBOX_DEFAULT
# 812 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 813 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_NINJA_BOY, Common_Movement_FaceOriginalDirection
# 814 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 815 "data/maps/SootopolisCity/scripts.pory"
	release
# 816 "data/maps/SootopolisCity/scripts.pory"
	end
# 817 "data/maps/SootopolisCity/scripts.pory"

# 818 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_NinjaBoyNormal::
# 819 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WonderWhatWorldIsLike, MSGBOX_DEFAULT
# 820 "data/maps/SootopolisCity/scripts.pory"
	release
# 821 "data/maps/SootopolisCity/scripts.pory"
	end
# 822 "data/maps/SootopolisCity/scripts.pory"

# 823 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_NinjaBoyRayquaza::
# 824 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThatWasWicked, MSGBOX_DEFAULT
# 825 "data/maps/SootopolisCity/scripts.pory"
	release
# 826 "data/maps/SootopolisCity/scripts.pory"
	end
# 827 "data/maps/SootopolisCity/scripts.pory"

# 828 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1::
# 829 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 830 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BOY_1, Common_Movement_FacePlayer
# 831 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 832 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Boy1Rayquaza
# 833 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SootopolisCity_EventScript_Boy1GameClear
# 834 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_Boy1Normal
# 835 "data/maps/SootopolisCity/scripts.pory"
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_Boy1Normal
# 836 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GiantPokemonSuddenlyAppeared, MSGBOX_DEFAULT
# 837 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 838 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BOY_1, Common_Movement_FaceOriginalDirection
# 839 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 840 "data/maps/SootopolisCity/scripts.pory"
	release
# 841 "data/maps/SootopolisCity/scripts.pory"
	end
# 842 "data/maps/SootopolisCity/scripts.pory"

# 843 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1Rayquaza::
# 844 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhatIsThatGreenPokemon, MSGBOX_DEFAULT
# 845 "data/maps/SootopolisCity/scripts.pory"
	release
# 846 "data/maps/SootopolisCity/scripts.pory"
	end
# 847 "data/maps/SootopolisCity/scripts.pory"

# 848 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1GameClear::
# 849 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhereDidLegendariesGo, MSGBOX_DEFAULT
# 850 "data/maps/SootopolisCity/scripts.pory"
	release
# 851 "data/maps/SootopolisCity/scripts.pory"
	end
# 852 "data/maps/SootopolisCity/scripts.pory"

# 853 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1Normal::
# 854 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_PhysicallyFitLivingHere, MSGBOX_DEFAULT
# 855 "data/maps/SootopolisCity/scripts.pory"
	release
# 856 "data/maps/SootopolisCity/scripts.pory"
	end
# 857 "data/maps/SootopolisCity/scripts.pory"

# 858 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GymSign::
# 859 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GymSign, MSGBOX_SIGN
# 860 "data/maps/SootopolisCity/scripts.pory"
	end
# 861 "data/maps/SootopolisCity/scripts.pory"

# 862 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_CitySign::
# 863 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CitySign, MSGBOX_SIGN
# 864 "data/maps/SootopolisCity/scripts.pory"
	end
# 865 "data/maps/SootopolisCity/scripts.pory"

# 866 "data/maps/SootopolisCity/scripts.pory"
EventScript_ClosedSootopolisDoor::
# 867 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DoorIsClosed, MSGBOX_SIGN
# 868 "data/maps/SootopolisCity/scripts.pory"
	end
# 869 "data/maps/SootopolisCity/scripts.pory"

# 870 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Steven::
# 871 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 872 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_STEVEN, Common_Movement_FacePlayer
# 873 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 874 "data/maps/SootopolisCity/scripts.pory"
	call_if_unset FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN, SootopolisCity_EventScript_StevenLeadPlayerCaveOfOrigin
# 875 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_StevenHelpWallace
# 876 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_StevenHelpedWallace
# 877 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_StevenHelpedWallace
# 878 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_StevenMaxieArchieLeft
# 879 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SoThatsRayquaza, MSGBOX_DEFAULT
# 880 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 881 "data/maps/SootopolisCity/scripts.pory"
	end
# 882 "data/maps/SootopolisCity/scripts.pory"

# 883 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenHelpWallace::
# 884 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_KnowWhatsNeededToHelpHim, MSGBOX_DEFAULT
# 885 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 886 "data/maps/SootopolisCity/scripts.pory"
	end
# 887 "data/maps/SootopolisCity/scripts.pory"

# 888 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenMaxieArchieLeft::
# 889 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_MaxieArchieLeft, MSGBOX_DEFAULT
# 890 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 891 "data/maps/SootopolisCity/scripts.pory"
	end
# 892 "data/maps/SootopolisCity/scripts.pory"

# 893 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenHelpedWallace::
# 894 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NeverBeenToSkyPillar, MSGBOX_DEFAULT
# 895 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 896 "data/maps/SootopolisCity/scripts.pory"
	end
# 897 "data/maps/SootopolisCity/scripts.pory"

# 898 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenLeadPlayerCaveOfOrigin::
# 899 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_InvolvedWithCrisisComeWithMe, MSGBOX_DEFAULT
# 900 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 901 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, SootopolisCity_EventScript_StartWalkToCaveOfOriginWest
# 902 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, SootopolisCity_EventScript_StartWalkToCaveOfOriginNorth
# 903 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DoesThisMakeYourFearPokemon, MSGBOX_DEFAULT
# 904 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 905 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenWalkToCaveOfOrigin
# 906 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerWalkToCaveOfOrigin
# 907 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 908 "data/maps/SootopolisCity/scripts.pory"
	delay 120
# 909 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_EXPERT, SootopolisCity_Movement_ExpertMoveAside
# 910 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 911 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenArriveCaveEntrance
# 912 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerArriveCaveEntrance
# 913 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 914 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_HereWereAreHelpWallace, MSGBOX_DEFAULT
# 915 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 916 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN
# 917 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerEnterCaveOfOrigin
# 918 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 919 "data/maps/SootopolisCity/scripts.pory"
	warp MAP_CAVE_OF_ORIGIN_ENTRANCE, 9, 20
# 920 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 921 "data/maps/SootopolisCity/scripts.pory"
	end
# 922 "data/maps/SootopolisCity/scripts.pory"

# 923 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartWalkToCaveOfOriginWest::
# 924 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin
# 925 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginWest
# 926 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 927 "data/maps/SootopolisCity/scripts.pory"
	return
# 928 "data/maps/SootopolisCity/scripts.pory"

# 929 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartWalkToCaveOfOriginNorth::
# 930 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin
# 931 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginNorth
# 932 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 933 "data/maps/SootopolisCity/scripts.pory"
	return
# 934 "data/maps/SootopolisCity/scripts.pory"

# 935 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin:
# 936 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 937 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 938 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 939 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 940 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 941 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 942 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 943 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 944 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 945 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 946 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 947 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 948 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 949 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 950 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 951 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 952 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 953 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 954 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 955 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 956 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 957 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 958 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 959 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 960 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 961 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 962 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 963 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 964 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 965 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 966 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 967 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 968 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 969 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 970 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 971 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_down
# 972 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 973 "data/maps/SootopolisCity/scripts.pory"

# 974 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginWest:
# 975 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 976 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 977 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 978 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 979 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 980 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 981 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 982 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 983 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 984 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 985 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 986 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 987 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 988 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 989 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 990 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 991 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 992 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 993 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 994 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 995 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 996 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 997 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 998 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 999 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1000 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1001 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1002 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1003 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1004 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1005 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1006 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1007 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1008 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1009 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1010 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1011 "data/maps/SootopolisCity/scripts.pory"

# 1012 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginNorth:
# 1013 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1014 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1015 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1016 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1017 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1018 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1019 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1020 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1021 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1022 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1023 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1024 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1025 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1026 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1027 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1028 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1029 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1030 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1031 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1032 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1033 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1034 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1035 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1036 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1037 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1038 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1039 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1040 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1041 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1042 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1043 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1044 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1045 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1046 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1047 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1048 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1049 "data/maps/SootopolisCity/scripts.pory"

# 1050 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_StevenWalkToCaveOfOrigin:
# 1051 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1052 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1053 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1054 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1055 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1056 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1057 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1058 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1059 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1060 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1061 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1062 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1063 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1064 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1065 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1066 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1067 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1068 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1069 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1070 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1071 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1072 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1073 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1074 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1075 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1076 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1077 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1078 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1079 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1080 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1081 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1082 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1083 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1084 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1085 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1086 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1087 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1088 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1089 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1090 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1091 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1092 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1093 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1094 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1095 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1096 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1097 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1098 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1099 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1100 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1101 "data/maps/SootopolisCity/scripts.pory"
	delay_4
# 1102 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_left
# 1103 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 1104 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 1105 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1106 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1107 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1108 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1109 "data/maps/SootopolisCity/scripts.pory"

# 1110 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerWalkToCaveOfOrigin:
# 1111 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1112 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1113 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1114 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1115 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1116 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1117 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1118 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1119 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1120 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1121 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1122 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1123 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1124 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1125 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1126 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1127 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1128 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1129 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1130 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1131 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1132 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1133 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1134 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1135 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1136 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1137 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1138 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1139 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1140 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1141 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1142 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1143 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1144 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1145 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1146 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1147 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1148 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1149 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1150 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1151 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1152 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1153 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1154 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1155 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1156 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1157 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1158 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1159 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1160 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1161 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1162 "data/maps/SootopolisCity/scripts.pory"

# 1163 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_ExpertMoveAside:
# 1164 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_left
# 1165 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_right
# 1166 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1167 "data/maps/SootopolisCity/scripts.pory"

# 1168 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_StevenArriveCaveEntrance:
# 1169 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1170 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1171 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1172 "data/maps/SootopolisCity/scripts.pory"
	delay_8
# 1173 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1174 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1175 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1176 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1177 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1178 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_left
# 1179 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1180 "data/maps/SootopolisCity/scripts.pory"

# 1181 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerArriveCaveEntrance:
# 1182 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 1183 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 1184 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 1185 "data/maps/SootopolisCity/scripts.pory"
	delay_8
# 1186 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1187 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1188 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1189 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1190 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1191 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_right
# 1192 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1193 "data/maps/SootopolisCity/scripts.pory"

# 1194 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerEnterCaveOfOrigin:
# 1195 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1196 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1197 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1198 "data/maps/SootopolisCity/scripts.pory"

# 1199 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy2::
# 1200 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 1201 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BOY_2, Common_Movement_FacePlayer
# 1202 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1203 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Boy2Rayquaza
# 1204 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_TwoPokemonArentAngry, MSGBOX_DEFAULT
# 1205 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1206 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BOY_2, Common_Movement_FaceOriginalDirection
# 1207 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1208 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1209 "data/maps/SootopolisCity/scripts.pory"
	end
# 1210 "data/maps/SootopolisCity/scripts.pory"

# 1211 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy2Rayquaza::
# 1212 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_FlyingMonStoppedRampage, MSGBOX_DEFAULT
# 1213 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1214 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1215 "data/maps/SootopolisCity/scripts.pory"
	end
# 1216 "data/maps/SootopolisCity/scripts.pory"

# 1217 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_BlackBelt::
# 1218 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 1219 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_BlackBeltRayquaza
# 1220 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GoRedAndBlueMon, MSGBOX_DEFAULT
# 1221 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1222 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BLACK_BELT, Common_Movement_FacePlayer
# 1223 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1224 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DoYouKnowMonNames, MSGBOX_DEFAULT
# 1225 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1226 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BLACK_BELT, Common_Movement_FaceOriginalDirection
# 1227 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1228 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1229 "data/maps/SootopolisCity/scripts.pory"
	end
# 1230 "data/maps/SootopolisCity/scripts.pory"

# 1231 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_BlackBeltRayquaza::
# 1232 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BLACK_BELT, Common_Movement_FacePlayer
# 1233 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1234 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GreenOneSettlesThings, MSGBOX_DEFAULT
# 1235 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1236 "data/maps/SootopolisCity/scripts.pory"
	end
# 1237 "data/maps/SootopolisCity/scripts.pory"

# 1238 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Girl::
# 1239 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 1240 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GIRL, Common_Movement_FacePlayer
# 1241 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1242 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_GirlRayquaza
# 1243 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SootopolisWillBeWrecked, MSGBOX_DEFAULT
# 1244 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1245 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GIRL, Common_Movement_FaceOriginalDirection
# 1246 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1247 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1248 "data/maps/SootopolisCity/scripts.pory"
	end
# 1249 "data/maps/SootopolisCity/scripts.pory"

# 1250 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GirlRayquaza::
# 1251 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SootopolisDidntGetWrecked, MSGBOX_DEFAULT
# 1252 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1253 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1254 "data/maps/SootopolisCity/scripts.pory"
	end
# 1255 "data/maps/SootopolisCity/scripts.pory"

# 1256 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Maniac::
# 1257 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 1258 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_MANIAC, Common_Movement_FacePlayer
# 1259 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1260 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ManiacRayquaza
# 1261 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SeeingLegendWithOwnEyes, MSGBOX_DEFAULT
# 1262 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1263 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_MANIAC, Common_Movement_FaceOriginalDirection
# 1264 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1265 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1266 "data/maps/SootopolisCity/scripts.pory"
	end
# 1267 "data/maps/SootopolisCity/scripts.pory"

# 1268 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ManiacRayquaza::
# 1269 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SawLegendWithOwnEyes, MSGBOX_DEFAULT
# 1270 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1271 "data/maps/SootopolisCity/scripts.pory"
	end
# 1272 "data/maps/SootopolisCity/scripts.pory"

# 1273 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Wallace::
# 1274 "data/maps/SootopolisCity/scripts.pory"
	lock
# 1275 "data/maps/SootopolisCity/scripts.pory"
	faceplayer
# 1276 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_GoToSkyPillar
# 1277 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_WATERFALL, SootopolisCity_EventScript_GoToGym
# 1278 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_GiveWaterfall
# 1279 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_AquaMagmaDidntMeanHarm, MSGBOX_DEFAULT
# 1280 "data/maps/SootopolisCity/scripts.pory"
	release
# 1281 "data/maps/SootopolisCity/scripts.pory"
	end
# 1282 "data/maps/SootopolisCity/scripts.pory"

# 1283 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GiveWaterfall::
# 1284 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThankYouForHelpAcceptThis, MSGBOX_DEFAULT
# 1285 "data/maps/SootopolisCity/scripts.pory"
	giveitem ITEM_HM_WATERFALL
# 1286 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_RECEIVED_HM_WATERFALL
# 1287 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ExplainWaterfallGoToGym, MSGBOX_DEFAULT
# 1288 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1289 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, SootopolisCity_EventScript_WallaceMoveFromGym
# 1290 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, SootopolisCity_EventScript_WallaceMoveFromGym
# 1291 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, SootopolisCity_EventScript_WallaceMoveFromGymWest
# 1292 "data/maps/SootopolisCity/scripts.pory"
	release
# 1293 "data/maps/SootopolisCity/scripts.pory"
	end
# 1294 "data/maps/SootopolisCity/scripts.pory"

# 1295 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_WallaceMoveFromGym::
# 1296 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_WALLACE, SootopolisCity_Movement_WallaceMoveFromGym
# 1297 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1298 "data/maps/SootopolisCity/scripts.pory"
	copyobjectxytoperm LOCALID_SOOTOPOLIS_WALLACE
# 1299 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_WALLACE_STATE, 1
# 1300 "data/maps/SootopolisCity/scripts.pory"
	return
# 1301 "data/maps/SootopolisCity/scripts.pory"

# 1302 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_WallaceMoveFromGymWest::
# 1303 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_WALLACE, SootopolisCity_Movement_WallaceMoveFromGymWest
# 1304 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1305 "data/maps/SootopolisCity/scripts.pory"
	copyobjectxytoperm LOCALID_SOOTOPOLIS_WALLACE
# 1306 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_WALLACE_STATE, 2
# 1307 "data/maps/SootopolisCity/scripts.pory"
	return
# 1308 "data/maps/SootopolisCity/scripts.pory"

# 1309 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GoToSkyPillar::
# 1310 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_HaventYouScaledSkyPillar, MSGBOX_DEFAULT
# 1311 "data/maps/SootopolisCity/scripts.pory"
	release
# 1312 "data/maps/SootopolisCity/scripts.pory"
	end
# 1313 "data/maps/SootopolisCity/scripts.pory"

# 1314 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GoToGym::
# 1315 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DazzledByMentor, MSGBOX_DEFAULT
# 1316 "data/maps/SootopolisCity/scripts.pory"
	release
# 1317 "data/maps/SootopolisCity/scripts.pory"
	end
# 1318 "data/maps/SootopolisCity/scripts.pory"

# 1319 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_WallaceMoveFromGym:
# 1320 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1321 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_down
# 1322 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1323 "data/maps/SootopolisCity/scripts.pory"

# 1324 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_WallaceMoveFromGymWest:
# 1325 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1326 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_down
# 1327 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1328 "data/maps/SootopolisCity/scripts.pory"

# 1329 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Maxie::
# 1330 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 1331 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_MaxieRayquaza
# 1332 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GroudonPleaseStop, MSGBOX_DEFAULT
# 1333 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1334 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1335 "data/maps/SootopolisCity/scripts.pory"
	end
# 1336 "data/maps/SootopolisCity/scripts.pory"

# 1337 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_MaxieRayquaza::
# 1338 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_AfterAllOurScheming, MSGBOX_DEFAULT
# 1339 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_MET_MAXIE_SOOTOPOLIS
# 1340 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_MET_ARCHIE_SOOTOPOLIS, SootopolisCity_EventScript_MaxieArchieLeave
# 1341 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1342 "data/maps/SootopolisCity/scripts.pory"
	end
# 1343 "data/maps/SootopolisCity/scripts.pory"

# 1344 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Archie::
# 1345 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 1346 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ArchieRayquaza
# 1347 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_KyogreCalmDown, MSGBOX_DEFAULT
# 1348 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1349 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1350 "data/maps/SootopolisCity/scripts.pory"
	end
# 1351 "data/maps/SootopolisCity/scripts.pory"

# 1352 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ArchieRayquaza::
# 1353 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_TryingMeaninglessToPokemon, MSGBOX_DEFAULT
# 1354 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_MET_ARCHIE_SOOTOPOLIS
# 1355 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_MET_MAXIE_SOOTOPOLIS, SootopolisCity_EventScript_MaxieArchieLeave
# 1356 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1357 "data/maps/SootopolisCity/scripts.pory"
	end
# 1358 "data/maps/SootopolisCity/scripts.pory"

# 1359 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_MaxieArchieLeave::
# 1360 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
# 1361 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
# 1362 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE
# 1363 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
# 1364 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
# 1365 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_MT_PYRE_STATE, 2
# 1366 "data/maps/SootopolisCity/scripts.pory"
	warpsilent MAP_SOOTOPOLIS_CITY, 31, 34
# 1367 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 1368 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1369 "data/maps/SootopolisCity/scripts.pory"
	end
# 1370 "data/maps/SootopolisCity/scripts.pory"

# 1371 "data/maps/SootopolisCity/scripts.pory"
@ Unused
# 1372 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_Levitate::
# 1373 "data/maps/SootopolisCity/scripts.pory"
	levitate
# 1374 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1375 "data/maps/SootopolisCity/scripts.pory"

# 1376 "data/maps/SootopolisCity/scripts.pory"
@ Unused
# 1377 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_DestroyTask::
# 1378 "data/maps/SootopolisCity/scripts.pory"
	destroy_extra_task
# 1379 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1380 "data/maps/SootopolisCity/scripts.pory"

# 1381 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GymSign:
# 1382 "data/maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS CITY POKéMON GYM\n"
# 1383 "data/maps/SootopolisCity/scripts.pory"
	.string "LEADER: JUAN\p"
# 1384 "data/maps/SootopolisCity/scripts.pory"
	.string "“The GYM LEADER with the beauty\n"
# 1385 "data/maps/SootopolisCity/scripts.pory"
	.string "of pure water!”$"
# 1386 "data/maps/SootopolisCity/scripts.pory"

# 1387 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CitySign:
# 1388 "data/maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS CITY\p"
# 1389 "data/maps/SootopolisCity/scripts.pory"
	.string "“The mystical city where history\n"
# 1390 "data/maps/SootopolisCity/scripts.pory"
	.string "slumbers.”$"
# 1391 "data/maps/SootopolisCity/scripts.pory"

# 1392 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DoorIsClosed:
# 1393 "data/maps/SootopolisCity/scripts.pory"
	.string "The door is closed.$"
# 1394 "data/maps/SootopolisCity/scripts.pory"

# 1395 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_PhysicallyFitLivingHere:
# 1396 "data/maps/SootopolisCity/scripts.pory"
	.string "Diving in the sea. Climbing up and\n"
# 1397 "data/maps/SootopolisCity/scripts.pory"
	.string "down stairs all the time…\p"
# 1398 "data/maps/SootopolisCity/scripts.pory"
	.string "If you live in this town, you end up\n"
# 1399 "data/maps/SootopolisCity/scripts.pory"
	.string "getting physically fit.$"
# 1400 "data/maps/SootopolisCity/scripts.pory"

# 1401 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GiantPokemonSuddenlyAppeared:
# 1402 "data/maps/SootopolisCity/scripts.pory"
	.string "These giant POKéMON suddenly appeared\n"
# 1403 "data/maps/SootopolisCity/scripts.pory"
	.string "in the middle of the city!\p"
# 1404 "data/maps/SootopolisCity/scripts.pory"
	.string "And, I've never seen them before!\p"
# 1405 "data/maps/SootopolisCity/scripts.pory"
	.string "Why are they smashing into each\n"
# 1406 "data/maps/SootopolisCity/scripts.pory"
	.string "other like that?\p"
# 1407 "data/maps/SootopolisCity/scripts.pory"
	.string "Why can't they be friends, those\n"
# 1408 "data/maps/SootopolisCity/scripts.pory"
	.string "POKéMON?$"
# 1409 "data/maps/SootopolisCity/scripts.pory"

# 1410 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WhatIsThatGreenPokemon:
# 1411 "data/maps/SootopolisCity/scripts.pory"
	.string "What? What? What?\n"
# 1412 "data/maps/SootopolisCity/scripts.pory"
	.string "What is that green POKéMON?!$"
# 1413 "data/maps/SootopolisCity/scripts.pory"

# 1414 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WhereDidLegendariesGo:
# 1415 "data/maps/SootopolisCity/scripts.pory"
	.string "GROUDON and KYOGRE…\n"
# 1416 "data/maps/SootopolisCity/scripts.pory"
	.string "Where did they go?\p"
# 1417 "data/maps/SootopolisCity/scripts.pory"
	.string "Will they cause droughts or downpours\n"
# 1418 "data/maps/SootopolisCity/scripts.pory"
	.string "somewhere else?$"
# 1419 "data/maps/SootopolisCity/scripts.pory"

# 1420 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_TwoPokemonArentAngry:
# 1421 "data/maps/SootopolisCity/scripts.pory"
	.string "I just get this sense somehow that\n"
# 1422 "data/maps/SootopolisCity/scripts.pory"
	.string "the two POKéMON aren't angry.\p"
# 1423 "data/maps/SootopolisCity/scripts.pory"
	.string "I think… They probably can't control\n"
# 1424 "data/maps/SootopolisCity/scripts.pory"
	.string "their own power…$"
# 1425 "data/maps/SootopolisCity/scripts.pory"

# 1426 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_FlyingMonStoppedRampage:
# 1427 "data/maps/SootopolisCity/scripts.pory"
	.string "That flying POKéMON came down from\n"
# 1428 "data/maps/SootopolisCity/scripts.pory"
	.string "the sky and stopped the rampaging\l"
# 1429 "data/maps/SootopolisCity/scripts.pory"
	.string "POKéMON…$"
# 1430 "data/maps/SootopolisCity/scripts.pory"

# 1431 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WonderWhatWorldIsLike:
# 1432 "data/maps/SootopolisCity/scripts.pory"
	.string "I… I've never been out of this city.\p"
# 1433 "data/maps/SootopolisCity/scripts.pory"
	.string "I wonder what the world is like on\n"
# 1434 "data/maps/SootopolisCity/scripts.pory"
	.string "the other side of this round sky?$"
# 1435 "data/maps/SootopolisCity/scripts.pory"

# 1436 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ThisIsWicked:
# 1437 "data/maps/SootopolisCity/scripts.pory"
	.string "Wow!\n"
# 1438 "data/maps/SootopolisCity/scripts.pory"
	.string "This is wicked!$"
# 1439 "data/maps/SootopolisCity/scripts.pory"

# 1440 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ThatWasWicked:
# 1441 "data/maps/SootopolisCity/scripts.pory"
	.string "Wow!\n"
# 1442 "data/maps/SootopolisCity/scripts.pory"
	.string "That was wicked!$"
# 1443 "data/maps/SootopolisCity/scripts.pory"

# 1444 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GoRedAndBlueMon:
# 1445 "data/maps/SootopolisCity/scripts.pory"
	.string "Go for it, red POKéMON!\n"
# 1446 "data/maps/SootopolisCity/scripts.pory"
	.string "Don't back off, blue POKéMON!$"
# 1447 "data/maps/SootopolisCity/scripts.pory"

# 1448 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DoYouKnowMonNames:
# 1449 "data/maps/SootopolisCity/scripts.pory"
	.string "… … … … … …\p"
# 1450 "data/maps/SootopolisCity/scripts.pory"
	.string "Hi, do you know the names of those\n"
# 1451 "data/maps/SootopolisCity/scripts.pory"
	.string "POKéMON fighting over there?$"
# 1452 "data/maps/SootopolisCity/scripts.pory"

# 1453 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GreenOneSettlesThings:
# 1454 "data/maps/SootopolisCity/scripts.pory"
	.string "I was wondering which one would win,\n"
# 1455 "data/maps/SootopolisCity/scripts.pory"
	.string "the red one or the blue one, but, oh no,\l"
# 1456 "data/maps/SootopolisCity/scripts.pory"
	.string "it's the green one that settles things!\p"
# 1457 "data/maps/SootopolisCity/scripts.pory"
	.string "Talk about a huge turn of events!$"
# 1458 "data/maps/SootopolisCity/scripts.pory"

# 1459 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SeeingLegendWithOwnEyes:
# 1460 "data/maps/SootopolisCity/scripts.pory"
	.string "There's an ancient legend that claims\n"
# 1461 "data/maps/SootopolisCity/scripts.pory"
	.string "the land and sea were shaped by\l"
# 1462 "data/maps/SootopolisCity/scripts.pory"
	.string "a colossal battle between POKéMON.\p"
# 1463 "data/maps/SootopolisCity/scripts.pory"
	.string "Well, I'm seeing that happen with\n"
# 1464 "data/maps/SootopolisCity/scripts.pory"
	.string "my very own eyes!\p"
# 1465 "data/maps/SootopolisCity/scripts.pory"
	.string "Whoa! I never expected to be\n"
# 1466 "data/maps/SootopolisCity/scripts.pory"
	.string "witness to something this huge!$"
# 1467 "data/maps/SootopolisCity/scripts.pory"

# 1468 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SawLegendWithOwnEyes:
# 1469 "data/maps/SootopolisCity/scripts.pory"
	.string "There's an ancient legend that claims\n"
# 1470 "data/maps/SootopolisCity/scripts.pory"
	.string "the land and sea were shaped by\l"
# 1471 "data/maps/SootopolisCity/scripts.pory"
	.string "a colossal battle between POKéMON.\p"
# 1472 "data/maps/SootopolisCity/scripts.pory"
	.string "Well, I saw that happen with\n"
# 1473 "data/maps/SootopolisCity/scripts.pory"
	.string "my very own eyes!\p"
# 1474 "data/maps/SootopolisCity/scripts.pory"
	.string "Whoa! I never expected to be\n"
# 1475 "data/maps/SootopolisCity/scripts.pory"
	.string "witness to something this huge!$"
# 1476 "data/maps/SootopolisCity/scripts.pory"

# 1477 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_BigPokemonFighting:
# 1478 "data/maps/SootopolisCity/scripts.pory"
	.string "A big POKéMON is fighting with\n"
# 1479 "data/maps/SootopolisCity/scripts.pory"
	.string "another big POKéMON!\p"
# 1480 "data/maps/SootopolisCity/scripts.pory"
	.string "Please, someone make them stop!$"
# 1481 "data/maps/SootopolisCity/scripts.pory"

# 1482 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_PrettyMonCameFromSky:
# 1483 "data/maps/SootopolisCity/scripts.pory"
	.string "A pretty POKéMON came down from\n"
# 1484 "data/maps/SootopolisCity/scripts.pory"
	.string "the sky…$"
# 1485 "data/maps/SootopolisCity/scripts.pory"

# 1486 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SootopolisWillBeWrecked:
# 1487 "data/maps/SootopolisCity/scripts.pory"
	.string "Oh, no!\n"
# 1488 "data/maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS CITY will get wrecked!$"
# 1489 "data/maps/SootopolisCity/scripts.pory"

# 1490 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SootopolisDidntGetWrecked:
# 1491 "data/maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS CITY didn't get wrecked!$"
# 1492 "data/maps/SootopolisCity/scripts.pory"

# 1493 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_NoOrdinaryTourist:
# 1494 "data/maps/SootopolisCity/scripts.pory"
	.string "Hm!\n"
# 1495 "data/maps/SootopolisCity/scripts.pory"
	.string "You've come all the way to SOOTOPOLIS?\l"
# 1496 "data/maps/SootopolisCity/scripts.pory"
	.string "You're no ordinary tourist.\p"
# 1497 "data/maps/SootopolisCity/scripts.pory"
	.string "But I suppose that doesn't make you\n"
# 1498 "data/maps/SootopolisCity/scripts.pory"
	.string "an extraordinary tourist, either.$"
# 1499 "data/maps/SootopolisCity/scripts.pory"

# 1500 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CityRegainedCalm:
# 1501 "data/maps/SootopolisCity/scripts.pory"
	.string "The city has regained its calm…$"
# 1502 "data/maps/SootopolisCity/scripts.pory"

# 1503 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CaveOfOriginPleaseLeave:
# 1504 "data/maps/SootopolisCity/scripts.pory"
	.string "Who might you be?\p"
# 1505 "data/maps/SootopolisCity/scripts.pory"
	.string "This is the CAVE OF ORIGIN.\p"
# 1506 "data/maps/SootopolisCity/scripts.pory"
	.string "The spirits of POKéMON, becalmed at\n"
# 1507 "data/maps/SootopolisCity/scripts.pory"
	.string "MT. PYRE, are said to be revived here.\p"
# 1508 "data/maps/SootopolisCity/scripts.pory"
	.string "Please leave.$"
# 1509 "data/maps/SootopolisCity/scripts.pory"

# 1510 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_LeadSuperiorTrainerToCave:
# 1511 "data/maps/SootopolisCity/scripts.pory"
	.string "A person with a strong will and\n"
# 1512 "data/maps/SootopolisCity/scripts.pory"
	.string "superior talent…\p"
# 1513 "data/maps/SootopolisCity/scripts.pory"
	.string "A TRAINER who has knowledge and\n"
# 1514 "data/maps/SootopolisCity/scripts.pory"
	.string "experience of many kinds of POKéMON…\p"
# 1515 "data/maps/SootopolisCity/scripts.pory"
	.string "If such a person were to appear, I was\n"
# 1516 "data/maps/SootopolisCity/scripts.pory"
	.string "instructed by WALLACE to lead that\l"
# 1517 "data/maps/SootopolisCity/scripts.pory"
	.string "TRAINER to this CAVE.$"
# 1518 "data/maps/SootopolisCity/scripts.pory"

# 1519 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_AwakenedPokemonClash:
# 1520 "data/maps/SootopolisCity/scripts.pory"
	.string "Oh, my…\p"
# 1521 "data/maps/SootopolisCity/scripts.pory"
	.string "The clash between the two awakened\n"
# 1522 "data/maps/SootopolisCity/scripts.pory"
	.string "POKéMON was quelled by the awakening\l"
# 1523 "data/maps/SootopolisCity/scripts.pory"
	.string "of a third POKéMON…$"
# 1524 "data/maps/SootopolisCity/scripts.pory"

# 1525 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CaveOfOriginSleepsToo:
# 1526 "data/maps/SootopolisCity/scripts.pory"
	.string "This is the CAVE OF ORIGIN…\p"
# 1527 "data/maps/SootopolisCity/scripts.pory"
	.string "With the passing of the crisis,\n"
# 1528 "data/maps/SootopolisCity/scripts.pory"
	.string "the cave, too, shall sleep…$"
# 1529 "data/maps/SootopolisCity/scripts.pory"

# 1530 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SootopolisSkyBeautiful:
# 1531 "data/maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS sprang up as a town in\n"
# 1532 "data/maps/SootopolisCity/scripts.pory"
	.string "the crater of a volcano.\p"
# 1533 "data/maps/SootopolisCity/scripts.pory"
	.string "If you look up at the sky, the lip of\n"
# 1534 "data/maps/SootopolisCity/scripts.pory"
	.string "the crater is also visible.\l"
# 1535 "data/maps/SootopolisCity/scripts.pory"
	.string "So, all you see is the sky in a circle.\p"
# 1536 "data/maps/SootopolisCity/scripts.pory"
	.string "But that's what makes the sky above\n"
# 1537 "data/maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS the most beautiful.$"
# 1538 "data/maps/SootopolisCity/scripts.pory"

# 1539 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GiganticPokemonFight:
# 1540 "data/maps/SootopolisCity/scripts.pory"
	.string "When two POKéMON that gigantic\n"
# 1541 "data/maps/SootopolisCity/scripts.pory"
	.string "are fighting that savagely, there's\l"
# 1542 "data/maps/SootopolisCity/scripts.pory"
	.string "not much that we can do.$"
# 1543 "data/maps/SootopolisCity/scripts.pory"

# 1544 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_FearedWorstWhenPokemonFlewDown:
# 1545 "data/maps/SootopolisCity/scripts.pory"
	.string "When that third POKéMON flew down,\n"
# 1546 "data/maps/SootopolisCity/scripts.pory"
	.string "I feared the worst.$"
# 1547 "data/maps/SootopolisCity/scripts.pory"

# 1548 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_NightSkyFavoriteScenery:
# 1549 "data/maps/SootopolisCity/scripts.pory"
	.string "A circle of a night sky framed by\n"
# 1550 "data/maps/SootopolisCity/scripts.pory"
	.string "the crater of a volcano…\p"
# 1551 "data/maps/SootopolisCity/scripts.pory"
	.string "And in that ring, stars flicker and\n"
# 1552 "data/maps/SootopolisCity/scripts.pory"
	.string "blink as if they were alive…\l"
# 1553 "data/maps/SootopolisCity/scripts.pory"
	.string "It's my favorite scenery.$"
# 1554 "data/maps/SootopolisCity/scripts.pory"

# 1555 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WeatherWentWild:
# 1556 "data/maps/SootopolisCity/scripts.pory"
	.string "The weather was clear this morning,\n"
# 1557 "data/maps/SootopolisCity/scripts.pory"
	.string "but…\p"
# 1558 "data/maps/SootopolisCity/scripts.pory"
	.string "All of a sudden, dark clouds brewed up,\n"
# 1559 "data/maps/SootopolisCity/scripts.pory"
	.string "rain started falling in sheets, and\l"
# 1560 "data/maps/SootopolisCity/scripts.pory"
	.string "there was thunder and lightning, too.\p"
# 1561 "data/maps/SootopolisCity/scripts.pory"
	.string "The weather just went completely\n"
# 1562 "data/maps/SootopolisCity/scripts.pory"
	.string "wild!\p"
# 1563 "data/maps/SootopolisCity/scripts.pory"
	.string "Is all of this because of those\n"
# 1564 "data/maps/SootopolisCity/scripts.pory"
	.string "POKéMON?$"
# 1565 "data/maps/SootopolisCity/scripts.pory"

# 1566 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_YouBroughtFlyingMon:
# 1567 "data/maps/SootopolisCity/scripts.pory"
	.string "Oh?\p"
# 1568 "data/maps/SootopolisCity/scripts.pory"
	.string "It was you who brought that flying\n"
# 1569 "data/maps/SootopolisCity/scripts.pory"
	.string "POKéMON here?\p"
# 1570 "data/maps/SootopolisCity/scripts.pory"
	.string "Well, aren't you amazing!$"
# 1571 "data/maps/SootopolisCity/scripts.pory"

# 1572 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GroudonPleaseStop:
# 1573 "data/maps/SootopolisCity/scripts.pory"
	.string "MAXIE: G… GROUDON…\n"
# 1574 "data/maps/SootopolisCity/scripts.pory"
	.string "Please! Stop what you're doing!\p"
# 1575 "data/maps/SootopolisCity/scripts.pory"
	.string "I know the extent of your power now!\p"
# 1576 "data/maps/SootopolisCity/scripts.pory"
	.string "If you keep going, all HOENN, not just\n"
# 1577 "data/maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS, will be utterly ruined!$"
# 1578 "data/maps/SootopolisCity/scripts.pory"

# 1579 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_AfterAllOurScheming:
# 1580 "data/maps/SootopolisCity/scripts.pory"
	.string "MAXIE: So the super-ancient POKéMON\n"
# 1581 "data/maps/SootopolisCity/scripts.pory"
	.string "weren't only GROUDON and KYOGRE…\p"
# 1582 "data/maps/SootopolisCity/scripts.pory"
	.string "After all our fruitless scheming and\n"
# 1583 "data/maps/SootopolisCity/scripts.pory"
	.string "frantic efforts, that one POKéMON's\l"
# 1584 "data/maps/SootopolisCity/scripts.pory"
	.string "simple action puts everything right\l"
# 1585 "data/maps/SootopolisCity/scripts.pory"
	.string "again as if nothing had happened…\p"
# 1586 "data/maps/SootopolisCity/scripts.pory"
	.string "Fu…\n"
# 1587 "data/maps/SootopolisCity/scripts.pory"
	.string "Fuhahaha…$"
# 1588 "data/maps/SootopolisCity/scripts.pory"

# 1589 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_KyogreCalmDown:
# 1590 "data/maps/SootopolisCity/scripts.pory"
	.string "ARCHIE: KYOGRE! What's wrong?!\n"
# 1591 "data/maps/SootopolisCity/scripts.pory"
	.string "Look over here! It's the RED ORB!\l"
# 1592 "data/maps/SootopolisCity/scripts.pory"
	.string "Calm down! KYOGRE!\p"
# 1593 "data/maps/SootopolisCity/scripts.pory"
	.string "… … … … … …\n"
# 1594 "data/maps/SootopolisCity/scripts.pory"
	.string "… … … … … …\p"
# 1595 "data/maps/SootopolisCity/scripts.pory"
	.string "It's no good!\n"
# 1596 "data/maps/SootopolisCity/scripts.pory"
	.string "It's not responding at all!$"
# 1597 "data/maps/SootopolisCity/scripts.pory"

# 1598 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_TryingMeaninglessToPokemon:
# 1599 "data/maps/SootopolisCity/scripts.pory"
	.string "ARCHIE: KYOGRE and GROUDON both\n"
# 1600 "data/maps/SootopolisCity/scripts.pory"
	.string "flew off to who knows where.\p"
# 1601 "data/maps/SootopolisCity/scripts.pory"
	.string "The weather in HOENN has returned\n"
# 1602 "data/maps/SootopolisCity/scripts.pory"
	.string "to its normal state…\p"
# 1603 "data/maps/SootopolisCity/scripts.pory"
	.string "Haha…\n"
# 1604 "data/maps/SootopolisCity/scripts.pory"
	.string "Hahaha…\p"
# 1605 "data/maps/SootopolisCity/scripts.pory"
	.string "Maybe what we were trying to do was\n"
# 1606 "data/maps/SootopolisCity/scripts.pory"
	.string "something small, even meaningless,\l"
# 1607 "data/maps/SootopolisCity/scripts.pory"
	.string "to POKéMON…$"
# 1608 "data/maps/SootopolisCity/scripts.pory"

# 1609 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_InvolvedWithCrisisComeWithMe:
# 1610 "data/maps/SootopolisCity/scripts.pory"
	.string "STEVEN: Those POKéMON fighting…\n"
# 1611 "data/maps/SootopolisCity/scripts.pory"
	.string "GROUDON… And KYOGRE…\p"
# 1612 "data/maps/SootopolisCity/scripts.pory"
	.string "The two super-ancient POKéMON\n"
# 1613 "data/maps/SootopolisCity/scripts.pory"
	.string "were awakened from a long sleep…\p"
# 1614 "data/maps/SootopolisCity/scripts.pory"
	.string "And now they are smashing each other\n"
# 1615 "data/maps/SootopolisCity/scripts.pory"
	.string "with their uncontrollable energy…\p"
# 1616 "data/maps/SootopolisCity/scripts.pory"
	.string "…{PLAYER}{KUN}.\p"
# 1617 "data/maps/SootopolisCity/scripts.pory"
	.string "You being here now I'll take to mean\n"
# 1618 "data/maps/SootopolisCity/scripts.pory"
	.string "that you're prepared to become\l"
# 1619 "data/maps/SootopolisCity/scripts.pory"
	.string "involved in this crisis.\p"
# 1620 "data/maps/SootopolisCity/scripts.pory"
	.string "Well, then, there's someone that\n"
# 1621 "data/maps/SootopolisCity/scripts.pory"
	.string "I'd like you to meet.\p"
# 1622 "data/maps/SootopolisCity/scripts.pory"
	.string "Come with me, please.$"
# 1623 "data/maps/SootopolisCity/scripts.pory"

# 1624 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DoesThisMakeYourFearPokemon:
# 1625 "data/maps/SootopolisCity/scripts.pory"
	.string "STEVEN: Listen, {PLAYER}{KUN}.\p"
# 1626 "data/maps/SootopolisCity/scripts.pory"
	.string "Does seeing GROUDON and KYOGRE make\n"
# 1627 "data/maps/SootopolisCity/scripts.pory"
	.string "you think POKéMON are to be feared?\p"
# 1628 "data/maps/SootopolisCity/scripts.pory"
	.string "But that's not true.\n"
# 1629 "data/maps/SootopolisCity/scripts.pory"
	.string "POKéMON are really more…\p"
# 1630 "data/maps/SootopolisCity/scripts.pory"
	.string "…Why am I asking you this?\n"
# 1631 "data/maps/SootopolisCity/scripts.pory"
	.string "You already know.$"
# 1632 "data/maps/SootopolisCity/scripts.pory"

# 1633 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_HereWereAreHelpWallace:
# 1634 "data/maps/SootopolisCity/scripts.pory"
	.string "STEVEN: Okay, here we are!\p"
# 1635 "data/maps/SootopolisCity/scripts.pory"
	.string "Inside here you'll find someone named\n"
# 1636 "data/maps/SootopolisCity/scripts.pory"
	.string "WALLACE.\p"
# 1637 "data/maps/SootopolisCity/scripts.pory"
	.string "I think you have what's needed to\n"
# 1638 "data/maps/SootopolisCity/scripts.pory"
	.string "help him…$"
# 1639 "data/maps/SootopolisCity/scripts.pory"

# 1640 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_KnowWhatsNeededToHelpHim:
# 1641 "data/maps/SootopolisCity/scripts.pory"
	.string "STEVEN: I think you have what's\n"
# 1642 "data/maps/SootopolisCity/scripts.pory"
	.string "needed to help him…$"
# 1643 "data/maps/SootopolisCity/scripts.pory"

# 1644 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_NeverBeenToSkyPillar:
# 1645 "data/maps/SootopolisCity/scripts.pory"
	.string "STEVEN: The SKY PILLAR…\p"
# 1646 "data/maps/SootopolisCity/scripts.pory"
	.string "I've never been there.\n"
# 1647 "data/maps/SootopolisCity/scripts.pory"
	.string "I wonder where it could be?$"
# 1648 "data/maps/SootopolisCity/scripts.pory"

# 1649 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SoThatsRayquaza:
# 1650 "data/maps/SootopolisCity/scripts.pory"
	.string "STEVEN: So that's RAYQUAZA…\p"
# 1651 "data/maps/SootopolisCity/scripts.pory"
	.string "It's incredible how the two rampaging\n"
# 1652 "data/maps/SootopolisCity/scripts.pory"
	.string "POKéMON would flee from it in fear…$"
# 1653 "data/maps/SootopolisCity/scripts.pory"

# 1654 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_MaxieArchieLeft:
# 1655 "data/maps/SootopolisCity/scripts.pory"
	.string "STEVEN: It looks like both MAXIE and\n"
# 1656 "data/maps/SootopolisCity/scripts.pory"
	.string "ARCHIE have gone away somewhere.\p"
# 1657 "data/maps/SootopolisCity/scripts.pory"
	.string "Perhaps they've gone to MT. PYRE to\n"
# 1658 "data/maps/SootopolisCity/scripts.pory"
	.string "return those ORBS…$"
# 1659 "data/maps/SootopolisCity/scripts.pory"

# 1660 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_HaventYouScaledSkyPillar:
# 1661 "data/maps/SootopolisCity/scripts.pory"
	.string "WALLACE: Oh?\n"
# 1662 "data/maps/SootopolisCity/scripts.pory"
	.string "{PLAYER}{KUN}?\p"
# 1663 "data/maps/SootopolisCity/scripts.pory"
	.string "Haven't you scaled the SKY PILLAR\n"
# 1664 "data/maps/SootopolisCity/scripts.pory"
	.string "yet?\p"
# 1665 "data/maps/SootopolisCity/scripts.pory"
	.string "I'm sure that you can make it to\n"
# 1666 "data/maps/SootopolisCity/scripts.pory"
	.string "the top of the SKY PILLAR…$"
# 1667 "data/maps/SootopolisCity/scripts.pory"

# 1668 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_AquaMagmaDidntMeanHarm:
# 1669 "data/maps/SootopolisCity/scripts.pory"
	.string "WALLACE: {PLAYER}{KUN}…\p"
# 1670 "data/maps/SootopolisCity/scripts.pory"
	.string "The leaders of TEAM MAGMA and AQUA,\n"
# 1671 "data/maps/SootopolisCity/scripts.pory"
	.string "I don't think they meant harm.\p"
# 1672 "data/maps/SootopolisCity/scripts.pory"
	.string "It wouldn't hurt to hear what they\n"
# 1673 "data/maps/SootopolisCity/scripts.pory"
	.string "have to say for themselves.$"
# 1674 "data/maps/SootopolisCity/scripts.pory"

# 1675 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ThankYouForHelpAcceptThis:
# 1676 "data/maps/SootopolisCity/scripts.pory"
	.string "WALLACE: {PLAYER}{KUN}…\n"
# 1677 "data/maps/SootopolisCity/scripts.pory"
	.string "My eyes didn't deceive me.\p"
# 1678 "data/maps/SootopolisCity/scripts.pory"
	.string "Thanks to your help, SOOTOPOLIS…\n"
# 1679 "data/maps/SootopolisCity/scripts.pory"
	.string "No, all of HOENN was saved.\p"
# 1680 "data/maps/SootopolisCity/scripts.pory"
	.string "On behalf of the people, I thank you.\p"
# 1681 "data/maps/SootopolisCity/scripts.pory"
	.string "This is a gift from me.\n"
# 1682 "data/maps/SootopolisCity/scripts.pory"
	.string "Please accept it.$"
# 1683 "data/maps/SootopolisCity/scripts.pory"

# 1684 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ExplainWaterfallGoToGym:
# 1685 "data/maps/SootopolisCity/scripts.pory"
	.string "That HIDDEN MACHINE contains\n"
# 1686 "data/maps/SootopolisCity/scripts.pory"
	.string "WATERFALL.\p"
# 1687 "data/maps/SootopolisCity/scripts.pory"
	.string "If you have the RAIN BADGE, a POKéMON\n"
# 1688 "data/maps/SootopolisCity/scripts.pory"
	.string "that has learned that HM move can\l"
# 1689 "data/maps/SootopolisCity/scripts.pory"
	.string "force its way up waterfalls.\p"
# 1690 "data/maps/SootopolisCity/scripts.pory"
	.string "And where does one get the RAIN BADGE?\n"
# 1691 "data/maps/SootopolisCity/scripts.pory"
	.string "You know, don't you?\p"
# 1692 "data/maps/SootopolisCity/scripts.pory"
	.string "That's right! You have to beat\n"
# 1693 "data/maps/SootopolisCity/scripts.pory"
	.string "the SOOTOPOLIS GYM LEADER.\p"
# 1694 "data/maps/SootopolisCity/scripts.pory"
	.string "When you're all set to go, step through\n"
# 1695 "data/maps/SootopolisCity/scripts.pory"
	.string "that door.$"
# 1696 "data/maps/SootopolisCity/scripts.pory"

# 1697 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DazzledByMentor:
# 1698 "data/maps/SootopolisCity/scripts.pory"
	.string "WALLACE: I'm sure that you will be\n"
# 1699 "data/maps/SootopolisCity/scripts.pory"
	.string "dazzled by my mentor's breathtakingly\l"
# 1700 "data/maps/SootopolisCity/scripts.pory"
	.string "elegant battle style.$"
