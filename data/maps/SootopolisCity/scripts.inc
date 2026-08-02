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
	call_if_eq VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_SetExpertBesideCaveEntrance
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
@ Post-game (state 6): stand the Expert to the side of the Cave of Origin mouth
# 140 "data/maps/SootopolisCity/scripts.pory"
@ instead of on the approach tile (31, 18), so the entrance stays walkable. The
# 141 "data/maps/SootopolisCity/scripts.pory"
@ cave holds a post-game legendary battle (Dialga in B1F); parking him on the
# 142 "data/maps/SootopolisCity/scripts.pory"
@ path used to seal it off for good. (30, 18) is the same spot he steps aside to
# 143 "data/maps/SootopolisCity/scripts.pory"
@ during Steven's guide cutscene, so it's a known-clear tile beside the mouth.
# 144 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetExpertBesideCaveEntrance::
# 145 "data/maps/SootopolisCity/scripts.pory"
	setobjectxyperm LOCALID_SOOTOPOLIS_EXPERT, 30, 18
# 146 "data/maps/SootopolisCity/scripts.pory"
	return
# 147 "data/maps/SootopolisCity/scripts.pory"

# 148 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_OnWarp:
# 149 "data/maps/SootopolisCity/scripts.pory"
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_PlayerFaceLegendaries
# 150 "data/maps/SootopolisCity/scripts.pory"
	.2byte 0
# 151 "data/maps/SootopolisCity/scripts.pory"

# 152 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_PlayerFaceLegendaries::
# 153 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_PlayerFaceLegendaries1
# 154 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_SKY_PILLAR_STATE, 2, SootopolisCity_EventScript_PlayerFaceLegendaries2
# 155 "data/maps/SootopolisCity/scripts.pory"
	end
# 156 "data/maps/SootopolisCity/scripts.pory"

# 157 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_PlayerFaceLegendaries1::
# 158 "data/maps/SootopolisCity/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 159 "data/maps/SootopolisCity/scripts.pory"
	return
# 160 "data/maps/SootopolisCity/scripts.pory"

# 161 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_PlayerFaceLegendaries2::
# 162 "data/maps/SootopolisCity/scripts.pory"
	turnobject LOCALID_PLAYER, DIR_NORTH
# 163 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SKY_PILLAR_STATE, 3
# 164 "data/maps/SootopolisCity/scripts.pory"
	return
# 165 "data/maps/SootopolisCity/scripts.pory"

# 166 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_OnResume:
# 167 "data/maps/SootopolisCity/scripts.pory"
	setdivewarp MAP_UNDERWATER_SOOTOPOLIS_CITY, 9, 6
# 168 "data/maps/SootopolisCity/scripts.pory"
	end
# 169 "data/maps/SootopolisCity/scripts.pory"

# 170 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_OnFrame:
# 171 "data/maps/SootopolisCity/scripts.pory"
	map_script_2 VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_StartLegendariesScene
# 172 "data/maps/SootopolisCity/scripts.pory"
	map_script_2 VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_StartRayquazaScene
# 173 "data/maps/SootopolisCity/scripts.pory"
	.2byte 0
# 174 "data/maps/SootopolisCity/scripts.pory"

# 175 "data/maps/SootopolisCity/scripts.pory"
@ If not at PokeCenter, assumed to have arrived via Dive
# 176 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartLegendariesScene::
# 177 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 178 "data/maps/SootopolisCity/scripts.pory"
	special StorePlayerCoordsInVars
# 179 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ne VAR_0x8004, 43, SootopolisCity_EventScript_LegendariesSceneFromDive
# 180 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ne VAR_0x8005, 32, SootopolisCity_EventScript_LegendariesSceneFromDive
# 181 "data/maps/SootopolisCity/scripts.pory"
	goto SootopolisCity_EventScript_LegendariesSceneFromPokeCenter
# 182 "data/maps/SootopolisCity/scripts.pory"
	end
# 183 "data/maps/SootopolisCity/scripts.pory"

# 184 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LegendariesSceneFromPokeCenter::
# 185 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 186 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 187 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromPokeCenter
# 188 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 189 "data/maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 190 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 191 "data/maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 192 "data/maps/SootopolisCity/scripts.pory"
	setweather WEATHER_ABNORMAL
# 193 "data/maps/SootopolisCity/scripts.pory"
	doweather
# 194 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, FALSE @ Just do Groudon/Kyogre fight scene
# 195 "data/maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 196 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, Common_Movement_WalkInPlaceFasterLeft
# 197 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, Common_Movement_WalkInPlaceFasterRight
# 198 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 199 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 200 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 201 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
# 202 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 203 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
# 204 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 205 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 206 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 207 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 208 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 209 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 210 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 211 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 212 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 213 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 214 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 215 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
# 216 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreDefend
# 217 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonAttack
# 218 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 219 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 220 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 221 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 222 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 223 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 224 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 225 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 226 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 227 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 228 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 229 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
# 230 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 231 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
# 232 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 233 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 234 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 235 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 236 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 237 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 238 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 239 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 240 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 241 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 242 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 243 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreIdle
# 244 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonIdle
# 245 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanBackToPokeCenter
# 246 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 247 "data/maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 248 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_CITY_STATE, 2
# 249 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 250 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 251 "data/maps/SootopolisCity/scripts.pory"
	end
# 252 "data/maps/SootopolisCity/scripts.pory"

# 253 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanToActionFromPokeCenter:
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
	walk_slow_diag_southwest
# 262 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 263 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 264 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 265 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 266 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 267 "data/maps/SootopolisCity/scripts.pory"

# 268 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanBackToPokeCenter:
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
	walk_slow_diag_northeast
# 277 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 278 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 279 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 280 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 281 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 282 "data/maps/SootopolisCity/scripts.pory"

# 283 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_LegendariesSceneFromDive::
# 284 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 285 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 286 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromDive
# 287 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 288 "data/maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 289 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 290 "data/maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 291 "data/maps/SootopolisCity/scripts.pory"
	setweather WEATHER_ABNORMAL
# 292 "data/maps/SootopolisCity/scripts.pory"
	doweather
# 293 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, FALSE @ Just do Groudon/Kyogre fight scene
# 294 "data/maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 295 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, Common_Movement_WalkInPlaceFasterLeft
# 296 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, Common_Movement_WalkInPlaceFasterRight
# 297 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 298 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 299 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 300 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
# 301 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 302 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
# 303 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 304 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 305 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 306 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 307 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 308 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 309 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 310 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 311 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 312 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 313 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 314 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
# 315 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreDefend
# 316 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonAttack
# 317 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 318 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 319 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 320 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 321 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 322 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 323 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 324 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 325 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 326 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 327 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 328 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
# 329 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreAttack
# 330 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonDefend
# 331 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 332 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 333 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 334 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 335 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 336 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 337 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 338 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreMoveBack
# 339 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonMoveBack
# 340 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 341 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 342 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_KYOGRE, SootopolisCity_Movement_KyogreIdle
# 343 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GROUDON, SootopolisCity_Movement_GroudonIdle
# 344 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanBackToDive
# 345 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 346 "data/maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 347 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_CITY_STATE, 2
# 348 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 349 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 350 "data/maps/SootopolisCity/scripts.pory"
	end
# 351 "data/maps/SootopolisCity/scripts.pory"

# 352 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanToActionFromDive:
# 353 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 354 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 355 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 356 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 357 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 358 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 359 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 360 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 361 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 362 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 363 "data/maps/SootopolisCity/scripts.pory"

# 364 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanBackToDive:
# 365 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 366 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 367 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 368 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 369 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 370 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 371 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 372 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 373 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 374 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 375 "data/maps/SootopolisCity/scripts.pory"

# 376 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreAttack:
# 377 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 378 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 379 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 380 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 381 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 382 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 383 "data/maps/SootopolisCity/scripts.pory"
	init_affine_anim
# 384 "data/maps/SootopolisCity/scripts.pory"
	walk_left_affine
# 385 "data/maps/SootopolisCity/scripts.pory"
	clear_affine_anim
# 386 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 387 "data/maps/SootopolisCity/scripts.pory"

# 388 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreDefend:
# 389 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 390 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 391 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 392 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 393 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 394 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 395 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 396 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 397 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 398 "data/maps/SootopolisCity/scripts.pory"
	init_affine_anim
# 399 "data/maps/SootopolisCity/scripts.pory"
	walk_left_affine
# 400 "data/maps/SootopolisCity/scripts.pory"
	clear_affine_anim
# 401 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 402 "data/maps/SootopolisCity/scripts.pory"

# 403 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreMoveBack:
# 404 "data/maps/SootopolisCity/scripts.pory"
	lock_facing_direction
# 405 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 406 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 407 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 408 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 409 "data/maps/SootopolisCity/scripts.pory"
	unlock_facing_direction
# 410 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 411 "data/maps/SootopolisCity/scripts.pory"

# 412 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_KyogreIdle:
# 413 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 414 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 415 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 416 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 417 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 418 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_left
# 419 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 420 "data/maps/SootopolisCity/scripts.pory"

# 421 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonAttack:
# 422 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 423 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 424 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 425 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 426 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 427 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 428 "data/maps/SootopolisCity/scripts.pory"
	walk_fast_right
# 429 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 430 "data/maps/SootopolisCity/scripts.pory"

# 431 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonDefend:
# 432 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 433 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 434 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 435 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 436 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 437 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 438 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 439 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 440 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 441 "data/maps/SootopolisCity/scripts.pory"
	walk_fast_right
# 442 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 443 "data/maps/SootopolisCity/scripts.pory"

# 444 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonMoveBack:
# 445 "data/maps/SootopolisCity/scripts.pory"
	lock_facing_direction
# 446 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 447 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 448 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 449 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 450 "data/maps/SootopolisCity/scripts.pory"
	unlock_facing_direction
# 451 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 452 "data/maps/SootopolisCity/scripts.pory"

# 453 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_GroudonIdle:
# 454 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 455 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 456 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 457 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 458 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 459 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_slow_right
# 460 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 461 "data/maps/SootopolisCity/scripts.pory"

# 462 "data/maps/SootopolisCity/scripts.pory"
@ If not at PokeCenter, assumed to have arrived via Dive
# 463 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartRayquazaScene::
# 464 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 465 "data/maps/SootopolisCity/scripts.pory"
	special StorePlayerCoordsInVars
# 466 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ne VAR_0x8004, 43, SootopolisCity_EventScript_RayquazaSceneFromDive
# 467 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ne VAR_0x8005, 32, SootopolisCity_EventScript_RayquazaSceneFromDive
# 468 "data/maps/SootopolisCity/scripts.pory"
	goto SootopolisCity_EventScript_RayquazaSceneFromPokeCenter
# 469 "data/maps/SootopolisCity/scripts.pory"
	end
# 470 "data/maps/SootopolisCity/scripts.pory"

# 471 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_RayquazaSceneFromPokeCenter::
# 472 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 473 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 474 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromPokeCenter
# 475 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 476 "data/maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 477 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 478 "data/maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 479 "data/maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetRoughWater
# 480 "data/maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_GROUDON
# 481 "data/maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_KYOGRE
# 482 "data/maps/SootopolisCity/scripts.pory"
	addobject LOCALID_SOOTOPOLIS_RAYQUAZA
# 483 "data/maps/SootopolisCity/scripts.pory"
	hideobjectat LOCALID_SOOTOPOLIS_RAYQUAZA, MAP_SOOTOPOLIS_CITY
# 484 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, TRUE
# 485 "data/maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 486 "data/maps/SootopolisCity/scripts.pory"
	playse SE_THUNDER
# 487 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 488 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanUp
# 489 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 490 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 491 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 492 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 493 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 494 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 495 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 496 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 497 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 498 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 499 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 500 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 501 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 502 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 503 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 504 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 505 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 506 "data/maps/SootopolisCity/scripts.pory"
	waitmoncry
# 507 "data/maps/SootopolisCity/scripts.pory"
	setweather WEATHER_NONE
# 508 "data/maps/SootopolisCity/scripts.pory"
	doweather
# 509 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_RAYQUAZA, SootopolisCity_Movement_RayquazaFlyOff
# 510 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 511 "data/maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_RAYQUAZA
# 512 "data/maps/SootopolisCity/scripts.pory"
	special WaitWeather
# 513 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_SYS_WEATHER_CTRL
# 514 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SKY_PILLAR_STATE, 3
# 515 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
# 516 "data/maps/SootopolisCity/scripts.pory"
	fadenewbgm MUS_SOOTOPOLIS
# 517 "data/maps/SootopolisCity/scripts.pory"
	delay 120
# 518 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 519 "data/maps/SootopolisCity/scripts.pory"
	warpwhitefade MAP_SOOTOPOLIS_CITY, 43, 32
# 520 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 521 "data/maps/SootopolisCity/scripts.pory"
	end
# 522 "data/maps/SootopolisCity/scripts.pory"

# 523 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_RayquazaSceneFromDive::
# 524 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 525 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 526 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanToActionFromDive
# 527 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 528 "data/maps/SootopolisCity/scripts.pory"
	special RemoveCameraObject
# 529 "data/maps/SootopolisCity/scripts.pory"
	delay 60
# 530 "data/maps/SootopolisCity/scripts.pory"
	fadescreenspeed FADE_TO_BLACK, 8
# 531 "data/maps/SootopolisCity/scripts.pory"
	call SootopolisCity_EventScript_SetRoughWater
# 532 "data/maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_GROUDON
# 533 "data/maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_KYOGRE
# 534 "data/maps/SootopolisCity/scripts.pory"
	addobject LOCALID_SOOTOPOLIS_RAYQUAZA
# 535 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, TRUE
# 536 "data/maps/SootopolisCity/scripts.pory"
	special Script_DoRayquazaScene
# 537 "data/maps/SootopolisCity/scripts.pory"
	special SpawnCameraObject
# 538 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_CAMERA, SootopolisCity_Movement_PanUp
# 539 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerApproachLegendaries
# 540 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 541 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 542 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 543 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 544 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 545 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 546 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 3  @ shake delay
# 547 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 548 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 549 "data/maps/SootopolisCity/scripts.pory"
	waitse
# 550 "data/maps/SootopolisCity/scripts.pory"
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
# 551 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 552 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 553 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 554 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 555 "data/maps/SootopolisCity/scripts.pory"
	special ShakeCamera
# 556 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 557 "data/maps/SootopolisCity/scripts.pory"
	waitmoncry
# 558 "data/maps/SootopolisCity/scripts.pory"
	setweather WEATHER_NONE
# 559 "data/maps/SootopolisCity/scripts.pory"
	doweather
# 560 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_RAYQUAZA, SootopolisCity_Movement_RayquazaFlyOff
# 561 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 562 "data/maps/SootopolisCity/scripts.pory"
	removeobject LOCALID_SOOTOPOLIS_RAYQUAZA
# 563 "data/maps/SootopolisCity/scripts.pory"
	special WaitWeather
# 564 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_SYS_WEATHER_CTRL
# 565 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SKY_PILLAR_STATE, 2
# 566 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
# 567 "data/maps/SootopolisCity/scripts.pory"
	fadenewbgm MUS_SURF
# 568 "data/maps/SootopolisCity/scripts.pory"
	delay 120
# 569 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MAP_NAME_POPUP
# 570 "data/maps/SootopolisCity/scripts.pory"
	warpwhitefade MAP_SOOTOPOLIS_CITY, 29, 53
# 571 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 572 "data/maps/SootopolisCity/scripts.pory"
	end
# 573 "data/maps/SootopolisCity/scripts.pory"

# 574 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_SetRoughWater::
# 575 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 27, 43, METATILE_Sootopolis_RoughWater, FALSE
# 576 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 28, 43, METATILE_Sootopolis_RoughWater, FALSE
# 577 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 29, 43, METATILE_Sootopolis_RoughWater, FALSE
# 578 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 30, 43, METATILE_Sootopolis_RoughWater, FALSE
# 579 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 27, 44, METATILE_Sootopolis_RoughWater, FALSE
# 580 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 28, 44, METATILE_Sootopolis_RoughWater, FALSE
# 581 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 29, 44, METATILE_Sootopolis_RoughWater, FALSE
# 582 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 30, 44, METATILE_Sootopolis_RoughWater, FALSE
# 583 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 27, 45, METATILE_Sootopolis_RoughWater, FALSE
# 584 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 28, 45, METATILE_Sootopolis_RoughWater, FALSE
# 585 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 29, 45, METATILE_Sootopolis_RoughWater, FALSE
# 586 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 30, 45, METATILE_Sootopolis_RoughWater, FALSE
# 587 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 32, 43, METATILE_Sootopolis_RoughWater, FALSE
# 588 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 33, 43, METATILE_Sootopolis_RoughWater, FALSE
# 589 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 34, 43, METATILE_Sootopolis_RoughWater, FALSE
# 590 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 35, 43, METATILE_Sootopolis_RoughWater, FALSE
# 591 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 32, 44, METATILE_Sootopolis_RoughWater, FALSE
# 592 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 33, 44, METATILE_Sootopolis_RoughWater, FALSE
# 593 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 34, 44, METATILE_Sootopolis_RoughWater, FALSE
# 594 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 35, 44, METATILE_Sootopolis_RoughWater, FALSE
# 595 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 32, 45, METATILE_Sootopolis_RoughWater, FALSE
# 596 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 33, 45, METATILE_Sootopolis_RoughWater, FALSE
# 597 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 34, 45, METATILE_Sootopolis_RoughWater, FALSE
# 598 "data/maps/SootopolisCity/scripts.pory"
	setmetatile 35, 45, METATILE_Sootopolis_RoughWater, FALSE
# 599 "data/maps/SootopolisCity/scripts.pory"
	return
# 600 "data/maps/SootopolisCity/scripts.pory"

# 601 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_RayquazaFlyOff:
# 602 "data/maps/SootopolisCity/scripts.pory"
	walk_fast_up
# 603 "data/maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 604 "data/maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 605 "data/maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 606 "data/maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 607 "data/maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 608 "data/maps/SootopolisCity/scripts.pory"
	walk_faster_up
# 609 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 610 "data/maps/SootopolisCity/scripts.pory"

# 611 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PanUp:
# 612 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 613 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 614 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 615 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 616 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 617 "data/maps/SootopolisCity/scripts.pory"

# 618 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerApproachLegendaries:
# 619 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 620 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 621 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 622 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 623 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 624 "data/maps/SootopolisCity/scripts.pory"

# 625 "data/maps/SootopolisCity/scripts.pory"
@ Unused
# 626 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerApproachLegendariesDown:
# 627 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 628 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 629 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 630 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 631 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 632 "data/maps/SootopolisCity/scripts.pory"

# 633 "data/maps/SootopolisCity/scripts.pory"
@ Unused
# 634 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_UnusedPanUp:
# 635 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 636 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 637 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 638 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 639 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 640 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 641 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 642 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_northeast
# 643 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 644 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 645 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 646 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 647 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 648 "data/maps/SootopolisCity/scripts.pory"

# 649 "data/maps/SootopolisCity/scripts.pory"
@ Unused
# 650 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_UnusedPanBack:
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
	walk_down
# 658 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 659 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 660 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 661 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 662 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 663 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_diag_southwest
# 664 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 665 "data/maps/SootopolisCity/scripts.pory"

# 666 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_CaveOfOriginExpert::
# 667 "data/maps/SootopolisCity/scripts.pory"
	lock
# 668 "data/maps/SootopolisCity/scripts.pory"
	faceplayer
# 669 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_ExpertPostLegendaries
# 670 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ExpertLegendaries
# 671 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_ExpertLeadToCave
# 672 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CaveOfOriginPleaseLeave, MSGBOX_DEFAULT
# 673 "data/maps/SootopolisCity/scripts.pory"
	release
# 674 "data/maps/SootopolisCity/scripts.pory"
	end
# 675 "data/maps/SootopolisCity/scripts.pory"

# 676 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ExpertLeadToCave::
# 677 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_LeadSuperiorTrainerToCave, MSGBOX_DEFAULT
# 678 "data/maps/SootopolisCity/scripts.pory"
	release
# 679 "data/maps/SootopolisCity/scripts.pory"
	end
# 680 "data/maps/SootopolisCity/scripts.pory"

# 681 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ExpertPostLegendaries::
# 682 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CaveOfOriginSleepsToo, MSGBOX_DEFAULT
# 683 "data/maps/SootopolisCity/scripts.pory"
	release
# 684 "data/maps/SootopolisCity/scripts.pory"
	end
# 685 "data/maps/SootopolisCity/scripts.pory"

# 686 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ExpertLegendaries::
# 687 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_AwakenedPokemonClash, MSGBOX_DEFAULT
# 688 "data/maps/SootopolisCity/scripts.pory"
	release
# 689 "data/maps/SootopolisCity/scripts.pory"
	end
# 690 "data/maps/SootopolisCity/scripts.pory"

# 691 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Kiri::
# 692 "data/maps/SootopolisCity/scripts.pory"
	lock
# 693 "data/maps/SootopolisCity/scripts.pory"
	faceplayer
# 694 "data/maps/SootopolisCity/scripts.pory"
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_KiriGiveBerry
# 695 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_KiriGiveBerry
# 696 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_KiriRayquaza
# 697 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_BigPokemonFighting, MSGBOX_DEFAULT
# 698 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 699 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_KIRI, Common_Movement_FaceOriginalDirection
# 700 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 701 "data/maps/SootopolisCity/scripts.pory"
	release
# 702 "data/maps/SootopolisCity/scripts.pory"
	end
# 703 "data/maps/SootopolisCity/scripts.pory"

# 704 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriRayquaza::
# 705 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_PrettyMonCameFromSky, MSGBOX_DEFAULT
# 706 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 707 "data/maps/SootopolisCity/scripts.pory"
	release
# 708 "data/maps/SootopolisCity/scripts.pory"
	end
# 709 "data/maps/SootopolisCity/scripts.pory"

# 710 "data/maps/SootopolisCity/scripts.pory"
@ Gives 2 berries daily. First ranges from BERRY_ID_POMEG to BERRY_ID_NOMEL, second is always Figy or Iapapa
# 711 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriGiveBerry::
# 712 "data/maps/SootopolisCity/scripts.pory"
	dotimebasedevents
# 713 "data/maps/SootopolisCity/scripts.pory"
	special GetPlayerBigGuyGirlString
# 714 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY, SootopolisCity_EventScript_KiriReceivedBerry
# 715 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NameIsKiriHaveOneOfThese, MSGBOX_DEFAULT
# 716 "data/maps/SootopolisCity/scripts.pory"
	giverandomberry BERRY_ID_POMEG, BERRY_ID_NOMEL
# 717 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 718 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY
# 719 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GiveYouThisBerryToo, MSGBOX_DEFAULT
# 720 "data/maps/SootopolisCity/scripts.pory"
	random 2
# 721 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, 0, SootopolisCity_EventScript_GiveFigyBerry
# 722 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, 1, SootopolisCity_EventScript_GiveIapapaBerry
# 723 "data/maps/SootopolisCity/scripts.pory"
	end
# 724 "data/maps/SootopolisCity/scripts.pory"

# 725 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GiveFigyBerry::
# 726 "data/maps/SootopolisCity/scripts.pory"
	giveitem ITEM_FIGY_BERRY
# 727 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 728 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
# 729 "data/maps/SootopolisCity/scripts.pory"
	release
# 730 "data/maps/SootopolisCity/scripts.pory"
	end
# 731 "data/maps/SootopolisCity/scripts.pory"

# 732 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GiveIapapaBerry::
# 733 "data/maps/SootopolisCity/scripts.pory"
	giveitem ITEM_IAPAPA_BERRY
# 734 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 735 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhatKindOfWishInYourName, MSGBOX_DEFAULT
# 736 "data/maps/SootopolisCity/scripts.pory"
	release
# 737 "data/maps/SootopolisCity/scripts.pory"
	end
# 738 "data/maps/SootopolisCity/scripts.pory"

# 739 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriReceivedBerry::
# 740 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_LikeSeasonBornIn, MSGBOX_YESNO
# 741 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, SootopolisCity_EventScript_KiriLikeSeasonBornIn
# 742 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_OhDoesntMatter, MSGBOX_DEFAULT
# 743 "data/maps/SootopolisCity/scripts.pory"
	release
# 744 "data/maps/SootopolisCity/scripts.pory"
	end
# 745 "data/maps/SootopolisCity/scripts.pory"

# 746 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_KiriLikeSeasonBornIn::
# 747 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThenILoveAutumn, MSGBOX_DEFAULT
# 748 "data/maps/SootopolisCity/scripts.pory"
	release
# 749 "data/maps/SootopolisCity/scripts.pory"
	end
# 750 "data/maps/SootopolisCity/scripts.pory"

# 751 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman2::
# 752 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 753 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_WOMAN_2, Common_Movement_FacePlayer
# 754 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 755 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Woman2Rayquaza
# 756 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WeatherWentWild, MSGBOX_DEFAULT
# 757 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 758 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_WOMAN_2, Common_Movement_FaceOriginalDirection
# 759 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 760 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 761 "data/maps/SootopolisCity/scripts.pory"
	end
# 762 "data/maps/SootopolisCity/scripts.pory"

# 763 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman2Rayquaza::
# 764 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_YouBroughtFlyingMon, MSGBOX_DEFAULT
# 765 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 766 "data/maps/SootopolisCity/scripts.pory"
	end
# 767 "data/maps/SootopolisCity/scripts.pory"

# 768 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Man::
# 769 "data/maps/SootopolisCity/scripts.pory"
	lock
# 770 "data/maps/SootopolisCity/scripts.pory"
	faceplayer
# 771 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_ManPostLegendaries
# 772 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NoOrdinaryTourist, MSGBOX_DEFAULT
# 773 "data/maps/SootopolisCity/scripts.pory"
	release
# 774 "data/maps/SootopolisCity/scripts.pory"
	end
# 775 "data/maps/SootopolisCity/scripts.pory"

# 776 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ManPostLegendaries::
# 777 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CityRegainedCalm, MSGBOX_DEFAULT
# 778 "data/maps/SootopolisCity/scripts.pory"
	release
# 779 "data/maps/SootopolisCity/scripts.pory"
	end
# 780 "data/maps/SootopolisCity/scripts.pory"

# 781 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1::
# 782 "data/maps/SootopolisCity/scripts.pory"
	lock
# 783 "data/maps/SootopolisCity/scripts.pory"
	faceplayer
# 784 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_Woman1PostLegendaries
# 785 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Woman1Rayquaza
# 786 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_Woman1Legendaries
# 787 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SootopolisSkyBeautiful, MSGBOX_DEFAULT
# 788 "data/maps/SootopolisCity/scripts.pory"
	release
# 789 "data/maps/SootopolisCity/scripts.pory"
	end
# 790 "data/maps/SootopolisCity/scripts.pory"

# 791 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1Legendaries::
# 792 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GiganticPokemonFight, MSGBOX_DEFAULT
# 793 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 794 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_WOMAN_1, Common_Movement_FaceOriginalDirection
# 795 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 796 "data/maps/SootopolisCity/scripts.pory"
	release
# 797 "data/maps/SootopolisCity/scripts.pory"
	end
# 798 "data/maps/SootopolisCity/scripts.pory"

# 799 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1PostLegendaries::
# 800 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NightSkyFavoriteScenery, MSGBOX_DEFAULT
# 801 "data/maps/SootopolisCity/scripts.pory"
	release
# 802 "data/maps/SootopolisCity/scripts.pory"
	end
# 803 "data/maps/SootopolisCity/scripts.pory"

# 804 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Woman1Rayquaza::
# 805 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_FearedWorstWhenPokemonFlewDown, MSGBOX_DEFAULT
# 806 "data/maps/SootopolisCity/scripts.pory"
	release
# 807 "data/maps/SootopolisCity/scripts.pory"
	end
# 808 "data/maps/SootopolisCity/scripts.pory"

# 809 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_NinjaBoy::
# 810 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 811 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_NINJA_BOY, Common_Movement_FacePlayer
# 812 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 813 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_NinjaBoyRayquaza
# 814 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_NinjaBoyNormal
# 815 "data/maps/SootopolisCity/scripts.pory"
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_NinjaBoyNormal
# 816 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThisIsWicked, MSGBOX_DEFAULT
# 817 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 818 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_NINJA_BOY, Common_Movement_FaceOriginalDirection
# 819 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 820 "data/maps/SootopolisCity/scripts.pory"
	release
# 821 "data/maps/SootopolisCity/scripts.pory"
	end
# 822 "data/maps/SootopolisCity/scripts.pory"

# 823 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_NinjaBoyNormal::
# 824 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WonderWhatWorldIsLike, MSGBOX_DEFAULT
# 825 "data/maps/SootopolisCity/scripts.pory"
	release
# 826 "data/maps/SootopolisCity/scripts.pory"
	end
# 827 "data/maps/SootopolisCity/scripts.pory"

# 828 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_NinjaBoyRayquaza::
# 829 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThatWasWicked, MSGBOX_DEFAULT
# 830 "data/maps/SootopolisCity/scripts.pory"
	release
# 831 "data/maps/SootopolisCity/scripts.pory"
	end
# 832 "data/maps/SootopolisCity/scripts.pory"

# 833 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1::
# 834 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 835 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BOY_1, Common_Movement_FacePlayer
# 836 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 837 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Boy1Rayquaza
# 838 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, SootopolisCity_EventScript_Boy1GameClear
# 839 "data/maps/SootopolisCity/scripts.pory"
	goto_if_ge VAR_SOOTOPOLIS_CITY_STATE, 6, SootopolisCity_EventScript_Boy1Normal
# 840 "data/maps/SootopolisCity/scripts.pory"
	goto_if_le VAR_SOOTOPOLIS_CITY_STATE, 1, SootopolisCity_EventScript_Boy1Normal
# 841 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GiantPokemonSuddenlyAppeared, MSGBOX_DEFAULT
# 842 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 843 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BOY_1, Common_Movement_FaceOriginalDirection
# 844 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 845 "data/maps/SootopolisCity/scripts.pory"
	release
# 846 "data/maps/SootopolisCity/scripts.pory"
	end
# 847 "data/maps/SootopolisCity/scripts.pory"

# 848 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1Rayquaza::
# 849 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhatIsThatGreenPokemon, MSGBOX_DEFAULT
# 850 "data/maps/SootopolisCity/scripts.pory"
	release
# 851 "data/maps/SootopolisCity/scripts.pory"
	end
# 852 "data/maps/SootopolisCity/scripts.pory"

# 853 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1GameClear::
# 854 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_WhereDidLegendariesGo, MSGBOX_DEFAULT
# 855 "data/maps/SootopolisCity/scripts.pory"
	release
# 856 "data/maps/SootopolisCity/scripts.pory"
	end
# 857 "data/maps/SootopolisCity/scripts.pory"

# 858 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy1Normal::
# 859 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_PhysicallyFitLivingHere, MSGBOX_DEFAULT
# 860 "data/maps/SootopolisCity/scripts.pory"
	release
# 861 "data/maps/SootopolisCity/scripts.pory"
	end
# 862 "data/maps/SootopolisCity/scripts.pory"

# 863 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GymSign::
# 864 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GymSign, MSGBOX_SIGN
# 865 "data/maps/SootopolisCity/scripts.pory"
	end
# 866 "data/maps/SootopolisCity/scripts.pory"

# 867 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_CitySign::
# 868 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_CitySign, MSGBOX_SIGN
# 869 "data/maps/SootopolisCity/scripts.pory"
	end
# 870 "data/maps/SootopolisCity/scripts.pory"

# 871 "data/maps/SootopolisCity/scripts.pory"
EventScript_ClosedSootopolisDoor::
# 872 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DoorIsClosed, MSGBOX_SIGN
# 873 "data/maps/SootopolisCity/scripts.pory"
	end
# 874 "data/maps/SootopolisCity/scripts.pory"

# 875 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Steven::
# 876 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 877 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_STEVEN, Common_Movement_FacePlayer
# 878 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 879 "data/maps/SootopolisCity/scripts.pory"
	call_if_unset FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN, SootopolisCity_EventScript_StevenLeadPlayerCaveOfOrigin
# 880 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 2, SootopolisCity_EventScript_StevenHelpWallace
# 881 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 3, SootopolisCity_EventScript_StevenHelpedWallace
# 882 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_StevenHelpedWallace
# 883 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_StevenMaxieArchieLeft
# 884 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SoThatsRayquaza, MSGBOX_DEFAULT
# 885 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 886 "data/maps/SootopolisCity/scripts.pory"
	end
# 887 "data/maps/SootopolisCity/scripts.pory"

# 888 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenHelpWallace::
# 889 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_KnowWhatsNeededToHelpHim, MSGBOX_DEFAULT
# 890 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 891 "data/maps/SootopolisCity/scripts.pory"
	end
# 892 "data/maps/SootopolisCity/scripts.pory"

# 893 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenMaxieArchieLeft::
# 894 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_MaxieArchieLeft, MSGBOX_DEFAULT
# 895 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 896 "data/maps/SootopolisCity/scripts.pory"
	end
# 897 "data/maps/SootopolisCity/scripts.pory"

# 898 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenHelpedWallace::
# 899 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_NeverBeenToSkyPillar, MSGBOX_DEFAULT
# 900 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 901 "data/maps/SootopolisCity/scripts.pory"
	end
# 902 "data/maps/SootopolisCity/scripts.pory"

# 903 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StevenLeadPlayerCaveOfOrigin::
# 904 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_InvolvedWithCrisisComeWithMe, MSGBOX_DEFAULT
# 905 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 906 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, SootopolisCity_EventScript_StartWalkToCaveOfOriginWest
# 907 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, SootopolisCity_EventScript_StartWalkToCaveOfOriginNorth
# 908 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DoesThisMakeYourFearPokemon, MSGBOX_DEFAULT
# 909 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 910 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenWalkToCaveOfOrigin
# 911 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerWalkToCaveOfOrigin
# 912 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 913 "data/maps/SootopolisCity/scripts.pory"
	delay 120
# 914 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_EXPERT, SootopolisCity_Movement_ExpertMoveAside
# 915 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 916 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenArriveCaveEntrance
# 917 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerArriveCaveEntrance
# 918 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 919 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_HereWereAreHelpWallace, MSGBOX_DEFAULT
# 920 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 921 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN
# 922 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerEnterCaveOfOrigin
# 923 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 924 "data/maps/SootopolisCity/scripts.pory"
	warp MAP_CAVE_OF_ORIGIN_ENTRANCE, 9, 20
# 925 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 926 "data/maps/SootopolisCity/scripts.pory"
	end
# 927 "data/maps/SootopolisCity/scripts.pory"

# 928 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartWalkToCaveOfOriginWest::
# 929 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin
# 930 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginWest
# 931 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 932 "data/maps/SootopolisCity/scripts.pory"
	return
# 933 "data/maps/SootopolisCity/scripts.pory"

# 934 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_StartWalkToCaveOfOriginNorth::
# 935 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_STEVEN, SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin
# 936 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_PLAYER, SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginNorth
# 937 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 938 "data/maps/SootopolisCity/scripts.pory"
	return
# 939 "data/maps/SootopolisCity/scripts.pory"

# 940 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_StevenStartWalkToCaveOfOrigin:
# 941 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 942 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 943 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 944 "data/maps/SootopolisCity/scripts.pory"
	walk_right
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
	walk_up
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
	walk_up
# 958 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 959 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 960 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 961 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 962 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 963 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 964 "data/maps/SootopolisCity/scripts.pory"
	walk_left
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
	walk_up
# 972 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 973 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 974 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 975 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 976 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_down
# 977 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 978 "data/maps/SootopolisCity/scripts.pory"

# 979 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginWest:
# 980 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 981 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 982 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 983 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 984 "data/maps/SootopolisCity/scripts.pory"
	walk_right
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
	walk_up
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
	walk_up
# 998 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 999 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1000 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1001 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1002 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1003 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1004 "data/maps/SootopolisCity/scripts.pory"
	walk_left
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
	walk_up
# 1011 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1012 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1013 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1014 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1015 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1016 "data/maps/SootopolisCity/scripts.pory"

# 1017 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerStartWalkToCaveOfOriginNorth:
# 1018 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1019 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1020 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1021 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1022 "data/maps/SootopolisCity/scripts.pory"
	walk_right
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
	walk_up
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
	walk_up
# 1036 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1037 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1038 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1039 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1040 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1041 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1042 "data/maps/SootopolisCity/scripts.pory"
	walk_left
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
	walk_up
# 1049 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1050 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1051 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1052 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1053 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1054 "data/maps/SootopolisCity/scripts.pory"

# 1055 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_StevenWalkToCaveOfOrigin:
# 1056 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1057 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1058 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1059 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1060 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1061 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1062 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1063 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1064 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1065 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1066 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1067 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1068 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1069 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1070 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1071 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1072 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1073 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1074 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1075 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1076 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1077 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1078 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1079 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1080 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1081 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1082 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1083 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1084 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1085 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1086 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1087 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1088 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1089 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1090 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1091 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1092 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1093 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1094 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1095 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1096 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1097 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1098 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1099 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1100 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1101 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1102 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1103 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1104 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1105 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1106 "data/maps/SootopolisCity/scripts.pory"
	delay_4
# 1107 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_left
# 1108 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 1109 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 1110 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1111 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1112 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1113 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1114 "data/maps/SootopolisCity/scripts.pory"

# 1115 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerWalkToCaveOfOrigin:
# 1116 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1117 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1118 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1119 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1120 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1121 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1122 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1123 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1124 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1125 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1126 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1127 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1128 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1129 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1130 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1131 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1132 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1133 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1134 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1135 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1136 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1137 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1138 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1139 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1140 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1141 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1142 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1143 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1144 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1145 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1146 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1147 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1148 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1149 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1150 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1151 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1152 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1153 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1154 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1155 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1156 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1157 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1158 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1159 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1160 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1161 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1162 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1163 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1164 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1165 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1166 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1167 "data/maps/SootopolisCity/scripts.pory"

# 1168 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_ExpertMoveAside:
# 1169 "data/maps/SootopolisCity/scripts.pory"
	walk_slow_left
# 1170 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_right
# 1171 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1172 "data/maps/SootopolisCity/scripts.pory"

# 1173 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_StevenArriveCaveEntrance:
# 1174 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1175 "data/maps/SootopolisCity/scripts.pory"
	walk_down
# 1176 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1177 "data/maps/SootopolisCity/scripts.pory"
	delay_8
# 1178 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1179 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1180 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1181 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1182 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1183 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_left
# 1184 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1185 "data/maps/SootopolisCity/scripts.pory"

# 1186 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerArriveCaveEntrance:
# 1187 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 1188 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 1189 "data/maps/SootopolisCity/scripts.pory"
	delay_16
# 1190 "data/maps/SootopolisCity/scripts.pory"
	delay_8
# 1191 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1192 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1193 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1194 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1195 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1196 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_right
# 1197 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1198 "data/maps/SootopolisCity/scripts.pory"

# 1199 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_PlayerEnterCaveOfOrigin:
# 1200 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1201 "data/maps/SootopolisCity/scripts.pory"
	walk_up
# 1202 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1203 "data/maps/SootopolisCity/scripts.pory"

# 1204 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy2::
# 1205 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 1206 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BOY_2, Common_Movement_FacePlayer
# 1207 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1208 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_Boy2Rayquaza
# 1209 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_TwoPokemonArentAngry, MSGBOX_DEFAULT
# 1210 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1211 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BOY_2, Common_Movement_FaceOriginalDirection
# 1212 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1213 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1214 "data/maps/SootopolisCity/scripts.pory"
	end
# 1215 "data/maps/SootopolisCity/scripts.pory"

# 1216 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Boy2Rayquaza::
# 1217 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_FlyingMonStoppedRampage, MSGBOX_DEFAULT
# 1218 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1219 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1220 "data/maps/SootopolisCity/scripts.pory"
	end
# 1221 "data/maps/SootopolisCity/scripts.pory"

# 1222 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_BlackBelt::
# 1223 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 1224 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_BlackBeltRayquaza
# 1225 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GoRedAndBlueMon, MSGBOX_DEFAULT
# 1226 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1227 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BLACK_BELT, Common_Movement_FacePlayer
# 1228 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1229 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DoYouKnowMonNames, MSGBOX_DEFAULT
# 1230 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1231 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BLACK_BELT, Common_Movement_FaceOriginalDirection
# 1232 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1233 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1234 "data/maps/SootopolisCity/scripts.pory"
	end
# 1235 "data/maps/SootopolisCity/scripts.pory"

# 1236 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_BlackBeltRayquaza::
# 1237 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_BLACK_BELT, Common_Movement_FacePlayer
# 1238 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1239 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GreenOneSettlesThings, MSGBOX_DEFAULT
# 1240 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1241 "data/maps/SootopolisCity/scripts.pory"
	end
# 1242 "data/maps/SootopolisCity/scripts.pory"

# 1243 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Girl::
# 1244 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 1245 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GIRL, Common_Movement_FacePlayer
# 1246 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1247 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_GirlRayquaza
# 1248 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SootopolisWillBeWrecked, MSGBOX_DEFAULT
# 1249 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1250 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_GIRL, Common_Movement_FaceOriginalDirection
# 1251 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1252 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1253 "data/maps/SootopolisCity/scripts.pory"
	end
# 1254 "data/maps/SootopolisCity/scripts.pory"

# 1255 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GirlRayquaza::
# 1256 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SootopolisDidntGetWrecked, MSGBOX_DEFAULT
# 1257 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1258 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1259 "data/maps/SootopolisCity/scripts.pory"
	end
# 1260 "data/maps/SootopolisCity/scripts.pory"

# 1261 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Maniac::
# 1262 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 1263 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_MANIAC, Common_Movement_FacePlayer
# 1264 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1265 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ManiacRayquaza
# 1266 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SeeingLegendWithOwnEyes, MSGBOX_DEFAULT
# 1267 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1268 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_MANIAC, Common_Movement_FaceOriginalDirection
# 1269 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1270 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1271 "data/maps/SootopolisCity/scripts.pory"
	end
# 1272 "data/maps/SootopolisCity/scripts.pory"

# 1273 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ManiacRayquaza::
# 1274 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_SawLegendWithOwnEyes, MSGBOX_DEFAULT
# 1275 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1276 "data/maps/SootopolisCity/scripts.pory"
	end
# 1277 "data/maps/SootopolisCity/scripts.pory"

# 1278 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Wallace::
# 1279 "data/maps/SootopolisCity/scripts.pory"
	lock
# 1280 "data/maps/SootopolisCity/scripts.pory"
	faceplayer
# 1281 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 4, SootopolisCity_EventScript_GoToSkyPillar
# 1282 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_HM_WATERFALL, SootopolisCity_EventScript_GoToGym
# 1283 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_GiveWaterfall
# 1284 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_AquaMagmaDidntMeanHarm, MSGBOX_DEFAULT
# 1285 "data/maps/SootopolisCity/scripts.pory"
	release
# 1286 "data/maps/SootopolisCity/scripts.pory"
	end
# 1287 "data/maps/SootopolisCity/scripts.pory"

# 1288 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GiveWaterfall::
# 1289 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ThankYouForHelpAcceptThis, MSGBOX_DEFAULT
# 1290 "data/maps/SootopolisCity/scripts.pory"
	giveitem ITEM_HM_WATERFALL
# 1291 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_RECEIVED_HM_WATERFALL
# 1292 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_ExplainWaterfallGoToGym, MSGBOX_DEFAULT
# 1293 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1294 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, SootopolisCity_EventScript_WallaceMoveFromGym
# 1295 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, SootopolisCity_EventScript_WallaceMoveFromGym
# 1296 "data/maps/SootopolisCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, SootopolisCity_EventScript_WallaceMoveFromGymWest
# 1297 "data/maps/SootopolisCity/scripts.pory"
	release
# 1298 "data/maps/SootopolisCity/scripts.pory"
	end
# 1299 "data/maps/SootopolisCity/scripts.pory"

# 1300 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_WallaceMoveFromGym::
# 1301 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_WALLACE, SootopolisCity_Movement_WallaceMoveFromGym
# 1302 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1303 "data/maps/SootopolisCity/scripts.pory"
	copyobjectxytoperm LOCALID_SOOTOPOLIS_WALLACE
# 1304 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_WALLACE_STATE, 1
# 1305 "data/maps/SootopolisCity/scripts.pory"
	return
# 1306 "data/maps/SootopolisCity/scripts.pory"

# 1307 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_WallaceMoveFromGymWest::
# 1308 "data/maps/SootopolisCity/scripts.pory"
	applymovement LOCALID_SOOTOPOLIS_WALLACE, SootopolisCity_Movement_WallaceMoveFromGymWest
# 1309 "data/maps/SootopolisCity/scripts.pory"
	waitmovement 0
# 1310 "data/maps/SootopolisCity/scripts.pory"
	copyobjectxytoperm LOCALID_SOOTOPOLIS_WALLACE
# 1311 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_SOOTOPOLIS_WALLACE_STATE, 2
# 1312 "data/maps/SootopolisCity/scripts.pory"
	return
# 1313 "data/maps/SootopolisCity/scripts.pory"

# 1314 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GoToSkyPillar::
# 1315 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_HaventYouScaledSkyPillar, MSGBOX_DEFAULT
# 1316 "data/maps/SootopolisCity/scripts.pory"
	release
# 1317 "data/maps/SootopolisCity/scripts.pory"
	end
# 1318 "data/maps/SootopolisCity/scripts.pory"

# 1319 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_GoToGym::
# 1320 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_DazzledByMentor, MSGBOX_DEFAULT
# 1321 "data/maps/SootopolisCity/scripts.pory"
	release
# 1322 "data/maps/SootopolisCity/scripts.pory"
	end
# 1323 "data/maps/SootopolisCity/scripts.pory"

# 1324 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_WallaceMoveFromGym:
# 1325 "data/maps/SootopolisCity/scripts.pory"
	walk_right
# 1326 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_down
# 1327 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1328 "data/maps/SootopolisCity/scripts.pory"

# 1329 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_WallaceMoveFromGymWest:
# 1330 "data/maps/SootopolisCity/scripts.pory"
	walk_left
# 1331 "data/maps/SootopolisCity/scripts.pory"
	walk_in_place_faster_down
# 1332 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1333 "data/maps/SootopolisCity/scripts.pory"

# 1334 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Maxie::
# 1335 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 1336 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_MaxieRayquaza
# 1337 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_GroudonPleaseStop, MSGBOX_DEFAULT
# 1338 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1339 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1340 "data/maps/SootopolisCity/scripts.pory"
	end
# 1341 "data/maps/SootopolisCity/scripts.pory"

# 1342 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_MaxieRayquaza::
# 1343 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_AfterAllOurScheming, MSGBOX_DEFAULT
# 1344 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_MET_MAXIE_SOOTOPOLIS
# 1345 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_MET_ARCHIE_SOOTOPOLIS, SootopolisCity_EventScript_MaxieArchieLeave
# 1346 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1347 "data/maps/SootopolisCity/scripts.pory"
	end
# 1348 "data/maps/SootopolisCity/scripts.pory"

# 1349 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_Archie::
# 1350 "data/maps/SootopolisCity/scripts.pory"
	lockall
# 1351 "data/maps/SootopolisCity/scripts.pory"
	goto_if_eq VAR_SOOTOPOLIS_CITY_STATE, 5, SootopolisCity_EventScript_ArchieRayquaza
# 1352 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_KyogreCalmDown, MSGBOX_DEFAULT
# 1353 "data/maps/SootopolisCity/scripts.pory"
	closemessage
# 1354 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1355 "data/maps/SootopolisCity/scripts.pory"
	end
# 1356 "data/maps/SootopolisCity/scripts.pory"

# 1357 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_ArchieRayquaza::
# 1358 "data/maps/SootopolisCity/scripts.pory"
	msgbox SootopolisCity_Text_TryingMeaninglessToPokemon, MSGBOX_DEFAULT
# 1359 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_MET_ARCHIE_SOOTOPOLIS
# 1360 "data/maps/SootopolisCity/scripts.pory"
	goto_if_set FLAG_MET_MAXIE_SOOTOPOLIS, SootopolisCity_EventScript_MaxieArchieLeave
# 1361 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1362 "data/maps/SootopolisCity/scripts.pory"
	end
# 1363 "data/maps/SootopolisCity/scripts.pory"

# 1364 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_EventScript_MaxieArchieLeave::
# 1365 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
# 1366 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
# 1367 "data/maps/SootopolisCity/scripts.pory"
	setflag FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE
# 1368 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
# 1369 "data/maps/SootopolisCity/scripts.pory"
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
# 1370 "data/maps/SootopolisCity/scripts.pory"
	setvar VAR_MT_PYRE_STATE, 2
# 1371 "data/maps/SootopolisCity/scripts.pory"
	warpsilent MAP_SOOTOPOLIS_CITY, 31, 34
# 1372 "data/maps/SootopolisCity/scripts.pory"
	waitstate
# 1373 "data/maps/SootopolisCity/scripts.pory"
	releaseall
# 1374 "data/maps/SootopolisCity/scripts.pory"
	end
# 1375 "data/maps/SootopolisCity/scripts.pory"

# 1376 "data/maps/SootopolisCity/scripts.pory"
@ Unused
# 1377 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_Levitate::
# 1378 "data/maps/SootopolisCity/scripts.pory"
	levitate
# 1379 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1380 "data/maps/SootopolisCity/scripts.pory"

# 1381 "data/maps/SootopolisCity/scripts.pory"
@ Unused
# 1382 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Movement_DestroyTask::
# 1383 "data/maps/SootopolisCity/scripts.pory"
	destroy_extra_task
# 1384 "data/maps/SootopolisCity/scripts.pory"
	step_end
# 1385 "data/maps/SootopolisCity/scripts.pory"

# 1386 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GymSign:
# 1387 "data/maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS CITY POKéMON GYM\n"
# 1388 "data/maps/SootopolisCity/scripts.pory"
	.string "LEADER: JUAN\p"
# 1389 "data/maps/SootopolisCity/scripts.pory"
	.string "“The GYM LEADER with the beauty\n"
# 1390 "data/maps/SootopolisCity/scripts.pory"
	.string "of pure water!”$"
# 1391 "data/maps/SootopolisCity/scripts.pory"

# 1392 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CitySign:
# 1393 "data/maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS CITY\p"
# 1394 "data/maps/SootopolisCity/scripts.pory"
	.string "“The mystical city where history\n"
# 1395 "data/maps/SootopolisCity/scripts.pory"
	.string "slumbers.”$"
# 1396 "data/maps/SootopolisCity/scripts.pory"

# 1397 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DoorIsClosed:
# 1398 "data/maps/SootopolisCity/scripts.pory"
	.string "The door is closed.$"
# 1399 "data/maps/SootopolisCity/scripts.pory"

# 1400 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_PhysicallyFitLivingHere:
# 1401 "data/maps/SootopolisCity/scripts.pory"
	.string "Diving in the sea. Climbing up and\n"
# 1402 "data/maps/SootopolisCity/scripts.pory"
	.string "down stairs all the time…\p"
# 1403 "data/maps/SootopolisCity/scripts.pory"
	.string "If you live in this town, you end up\n"
# 1404 "data/maps/SootopolisCity/scripts.pory"
	.string "getting physically fit.$"
# 1405 "data/maps/SootopolisCity/scripts.pory"

# 1406 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GiantPokemonSuddenlyAppeared:
# 1407 "data/maps/SootopolisCity/scripts.pory"
	.string "These giant POKéMON suddenly appeared\n"
# 1408 "data/maps/SootopolisCity/scripts.pory"
	.string "in the middle of the city!\p"
# 1409 "data/maps/SootopolisCity/scripts.pory"
	.string "And, I've never seen them before!\p"
# 1410 "data/maps/SootopolisCity/scripts.pory"
	.string "Why are they smashing into each\n"
# 1411 "data/maps/SootopolisCity/scripts.pory"
	.string "other like that?\p"
# 1412 "data/maps/SootopolisCity/scripts.pory"
	.string "Why can't they be friends, those\n"
# 1413 "data/maps/SootopolisCity/scripts.pory"
	.string "POKéMON?$"
# 1414 "data/maps/SootopolisCity/scripts.pory"

# 1415 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WhatIsThatGreenPokemon:
# 1416 "data/maps/SootopolisCity/scripts.pory"
	.string "What? What? What?\n"
# 1417 "data/maps/SootopolisCity/scripts.pory"
	.string "What is that green POKéMON?!$"
# 1418 "data/maps/SootopolisCity/scripts.pory"

# 1419 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WhereDidLegendariesGo:
# 1420 "data/maps/SootopolisCity/scripts.pory"
	.string "GROUDON and KYOGRE…\n"
# 1421 "data/maps/SootopolisCity/scripts.pory"
	.string "Where did they go?\p"
# 1422 "data/maps/SootopolisCity/scripts.pory"
	.string "Will they cause droughts or downpours\n"
# 1423 "data/maps/SootopolisCity/scripts.pory"
	.string "somewhere else?$"
# 1424 "data/maps/SootopolisCity/scripts.pory"

# 1425 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_TwoPokemonArentAngry:
# 1426 "data/maps/SootopolisCity/scripts.pory"
	.string "I just get this sense somehow that\n"
# 1427 "data/maps/SootopolisCity/scripts.pory"
	.string "the two POKéMON aren't angry.\p"
# 1428 "data/maps/SootopolisCity/scripts.pory"
	.string "I think… They probably can't control\n"
# 1429 "data/maps/SootopolisCity/scripts.pory"
	.string "their own power…$"
# 1430 "data/maps/SootopolisCity/scripts.pory"

# 1431 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_FlyingMonStoppedRampage:
# 1432 "data/maps/SootopolisCity/scripts.pory"
	.string "That flying POKéMON came down from\n"
# 1433 "data/maps/SootopolisCity/scripts.pory"
	.string "the sky and stopped the rampaging\l"
# 1434 "data/maps/SootopolisCity/scripts.pory"
	.string "POKéMON…$"
# 1435 "data/maps/SootopolisCity/scripts.pory"

# 1436 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WonderWhatWorldIsLike:
# 1437 "data/maps/SootopolisCity/scripts.pory"
	.string "I… I've never been out of this city.\p"
# 1438 "data/maps/SootopolisCity/scripts.pory"
	.string "I wonder what the world is like on\n"
# 1439 "data/maps/SootopolisCity/scripts.pory"
	.string "the other side of this round sky?$"
# 1440 "data/maps/SootopolisCity/scripts.pory"

# 1441 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ThisIsWicked:
# 1442 "data/maps/SootopolisCity/scripts.pory"
	.string "Wow!\n"
# 1443 "data/maps/SootopolisCity/scripts.pory"
	.string "This is wicked!$"
# 1444 "data/maps/SootopolisCity/scripts.pory"

# 1445 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ThatWasWicked:
# 1446 "data/maps/SootopolisCity/scripts.pory"
	.string "Wow!\n"
# 1447 "data/maps/SootopolisCity/scripts.pory"
	.string "That was wicked!$"
# 1448 "data/maps/SootopolisCity/scripts.pory"

# 1449 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GoRedAndBlueMon:
# 1450 "data/maps/SootopolisCity/scripts.pory"
	.string "Go for it, red POKéMON!\n"
# 1451 "data/maps/SootopolisCity/scripts.pory"
	.string "Don't back off, blue POKéMON!$"
# 1452 "data/maps/SootopolisCity/scripts.pory"

# 1453 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DoYouKnowMonNames:
# 1454 "data/maps/SootopolisCity/scripts.pory"
	.string "… … … … … …\p"
# 1455 "data/maps/SootopolisCity/scripts.pory"
	.string "Hi, do you know the names of those\n"
# 1456 "data/maps/SootopolisCity/scripts.pory"
	.string "POKéMON fighting over there?$"
# 1457 "data/maps/SootopolisCity/scripts.pory"

# 1458 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GreenOneSettlesThings:
# 1459 "data/maps/SootopolisCity/scripts.pory"
	.string "I was wondering which one would win,\n"
# 1460 "data/maps/SootopolisCity/scripts.pory"
	.string "the red one or the blue one, but, oh no,\l"
# 1461 "data/maps/SootopolisCity/scripts.pory"
	.string "it's the green one that settles things!\p"
# 1462 "data/maps/SootopolisCity/scripts.pory"
	.string "Talk about a huge turn of events!$"
# 1463 "data/maps/SootopolisCity/scripts.pory"

# 1464 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SeeingLegendWithOwnEyes:
# 1465 "data/maps/SootopolisCity/scripts.pory"
	.string "There's an ancient legend that claims\n"
# 1466 "data/maps/SootopolisCity/scripts.pory"
	.string "the land and sea were shaped by\l"
# 1467 "data/maps/SootopolisCity/scripts.pory"
	.string "a colossal battle between POKéMON.\p"
# 1468 "data/maps/SootopolisCity/scripts.pory"
	.string "Well, I'm seeing that happen with\n"
# 1469 "data/maps/SootopolisCity/scripts.pory"
	.string "my very own eyes!\p"
# 1470 "data/maps/SootopolisCity/scripts.pory"
	.string "Whoa! I never expected to be\n"
# 1471 "data/maps/SootopolisCity/scripts.pory"
	.string "witness to something this huge!$"
# 1472 "data/maps/SootopolisCity/scripts.pory"

# 1473 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SawLegendWithOwnEyes:
# 1474 "data/maps/SootopolisCity/scripts.pory"
	.string "There's an ancient legend that claims\n"
# 1475 "data/maps/SootopolisCity/scripts.pory"
	.string "the land and sea were shaped by\l"
# 1476 "data/maps/SootopolisCity/scripts.pory"
	.string "a colossal battle between POKéMON.\p"
# 1477 "data/maps/SootopolisCity/scripts.pory"
	.string "Well, I saw that happen with\n"
# 1478 "data/maps/SootopolisCity/scripts.pory"
	.string "my very own eyes!\p"
# 1479 "data/maps/SootopolisCity/scripts.pory"
	.string "Whoa! I never expected to be\n"
# 1480 "data/maps/SootopolisCity/scripts.pory"
	.string "witness to something this huge!$"
# 1481 "data/maps/SootopolisCity/scripts.pory"

# 1482 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_BigPokemonFighting:
# 1483 "data/maps/SootopolisCity/scripts.pory"
	.string "A big POKéMON is fighting with\n"
# 1484 "data/maps/SootopolisCity/scripts.pory"
	.string "another big POKéMON!\p"
# 1485 "data/maps/SootopolisCity/scripts.pory"
	.string "Please, someone make them stop!$"
# 1486 "data/maps/SootopolisCity/scripts.pory"

# 1487 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_PrettyMonCameFromSky:
# 1488 "data/maps/SootopolisCity/scripts.pory"
	.string "A pretty POKéMON came down from\n"
# 1489 "data/maps/SootopolisCity/scripts.pory"
	.string "the sky…$"
# 1490 "data/maps/SootopolisCity/scripts.pory"

# 1491 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SootopolisWillBeWrecked:
# 1492 "data/maps/SootopolisCity/scripts.pory"
	.string "Oh, no!\n"
# 1493 "data/maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS CITY will get wrecked!$"
# 1494 "data/maps/SootopolisCity/scripts.pory"

# 1495 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SootopolisDidntGetWrecked:
# 1496 "data/maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS CITY didn't get wrecked!$"
# 1497 "data/maps/SootopolisCity/scripts.pory"

# 1498 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_NoOrdinaryTourist:
# 1499 "data/maps/SootopolisCity/scripts.pory"
	.string "Hm!\n"
# 1500 "data/maps/SootopolisCity/scripts.pory"
	.string "You've come all the way to SOOTOPOLIS?\l"
# 1501 "data/maps/SootopolisCity/scripts.pory"
	.string "You're no ordinary tourist.\p"
# 1502 "data/maps/SootopolisCity/scripts.pory"
	.string "But I suppose that doesn't make you\n"
# 1503 "data/maps/SootopolisCity/scripts.pory"
	.string "an extraordinary tourist, either.$"
# 1504 "data/maps/SootopolisCity/scripts.pory"

# 1505 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CityRegainedCalm:
# 1506 "data/maps/SootopolisCity/scripts.pory"
	.string "The city has regained its calm…$"
# 1507 "data/maps/SootopolisCity/scripts.pory"

# 1508 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CaveOfOriginPleaseLeave:
# 1509 "data/maps/SootopolisCity/scripts.pory"
	.string "Who might you be?\p"
# 1510 "data/maps/SootopolisCity/scripts.pory"
	.string "This is the CAVE OF ORIGIN.\p"
# 1511 "data/maps/SootopolisCity/scripts.pory"
	.string "The spirits of POKéMON, becalmed at\n"
# 1512 "data/maps/SootopolisCity/scripts.pory"
	.string "MT. PYRE, are said to be revived here.\p"
# 1513 "data/maps/SootopolisCity/scripts.pory"
	.string "Please leave.$"
# 1514 "data/maps/SootopolisCity/scripts.pory"

# 1515 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_LeadSuperiorTrainerToCave:
# 1516 "data/maps/SootopolisCity/scripts.pory"
	.string "A person with a strong will and\n"
# 1517 "data/maps/SootopolisCity/scripts.pory"
	.string "superior talent…\p"
# 1518 "data/maps/SootopolisCity/scripts.pory"
	.string "A TRAINER who has knowledge and\n"
# 1519 "data/maps/SootopolisCity/scripts.pory"
	.string "experience of many kinds of POKéMON…\p"
# 1520 "data/maps/SootopolisCity/scripts.pory"
	.string "If such a person were to appear, I was\n"
# 1521 "data/maps/SootopolisCity/scripts.pory"
	.string "instructed by WALLACE to lead that\l"
# 1522 "data/maps/SootopolisCity/scripts.pory"
	.string "TRAINER to this CAVE.$"
# 1523 "data/maps/SootopolisCity/scripts.pory"

# 1524 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_AwakenedPokemonClash:
# 1525 "data/maps/SootopolisCity/scripts.pory"
	.string "Oh, my…\p"
# 1526 "data/maps/SootopolisCity/scripts.pory"
	.string "The clash between the two awakened\n"
# 1527 "data/maps/SootopolisCity/scripts.pory"
	.string "POKéMON was quelled by the awakening\l"
# 1528 "data/maps/SootopolisCity/scripts.pory"
	.string "of a third POKéMON…$"
# 1529 "data/maps/SootopolisCity/scripts.pory"

# 1530 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_CaveOfOriginSleepsToo:
# 1531 "data/maps/SootopolisCity/scripts.pory"
	.string "This is the CAVE OF ORIGIN…\p"
# 1532 "data/maps/SootopolisCity/scripts.pory"
	.string "With the passing of the crisis,\n"
# 1533 "data/maps/SootopolisCity/scripts.pory"
	.string "the cave, too, shall sleep…$"
# 1534 "data/maps/SootopolisCity/scripts.pory"

# 1535 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SootopolisSkyBeautiful:
# 1536 "data/maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS sprang up as a town in\n"
# 1537 "data/maps/SootopolisCity/scripts.pory"
	.string "the crater of a volcano.\p"
# 1538 "data/maps/SootopolisCity/scripts.pory"
	.string "If you look up at the sky, the lip of\n"
# 1539 "data/maps/SootopolisCity/scripts.pory"
	.string "the crater is also visible.\l"
# 1540 "data/maps/SootopolisCity/scripts.pory"
	.string "So, all you see is the sky in a circle.\p"
# 1541 "data/maps/SootopolisCity/scripts.pory"
	.string "But that's what makes the sky above\n"
# 1542 "data/maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS the most beautiful.$"
# 1543 "data/maps/SootopolisCity/scripts.pory"

# 1544 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GiganticPokemonFight:
# 1545 "data/maps/SootopolisCity/scripts.pory"
	.string "When two POKéMON that gigantic\n"
# 1546 "data/maps/SootopolisCity/scripts.pory"
	.string "are fighting that savagely, there's\l"
# 1547 "data/maps/SootopolisCity/scripts.pory"
	.string "not much that we can do.$"
# 1548 "data/maps/SootopolisCity/scripts.pory"

# 1549 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_FearedWorstWhenPokemonFlewDown:
# 1550 "data/maps/SootopolisCity/scripts.pory"
	.string "When that third POKéMON flew down,\n"
# 1551 "data/maps/SootopolisCity/scripts.pory"
	.string "I feared the worst.$"
# 1552 "data/maps/SootopolisCity/scripts.pory"

# 1553 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_NightSkyFavoriteScenery:
# 1554 "data/maps/SootopolisCity/scripts.pory"
	.string "A circle of a night sky framed by\n"
# 1555 "data/maps/SootopolisCity/scripts.pory"
	.string "the crater of a volcano…\p"
# 1556 "data/maps/SootopolisCity/scripts.pory"
	.string "And in that ring, stars flicker and\n"
# 1557 "data/maps/SootopolisCity/scripts.pory"
	.string "blink as if they were alive…\l"
# 1558 "data/maps/SootopolisCity/scripts.pory"
	.string "It's my favorite scenery.$"
# 1559 "data/maps/SootopolisCity/scripts.pory"

# 1560 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_WeatherWentWild:
# 1561 "data/maps/SootopolisCity/scripts.pory"
	.string "The weather was clear this morning,\n"
# 1562 "data/maps/SootopolisCity/scripts.pory"
	.string "but…\p"
# 1563 "data/maps/SootopolisCity/scripts.pory"
	.string "All of a sudden, dark clouds brewed up,\n"
# 1564 "data/maps/SootopolisCity/scripts.pory"
	.string "rain started falling in sheets, and\l"
# 1565 "data/maps/SootopolisCity/scripts.pory"
	.string "there was thunder and lightning, too.\p"
# 1566 "data/maps/SootopolisCity/scripts.pory"
	.string "The weather just went completely\n"
# 1567 "data/maps/SootopolisCity/scripts.pory"
	.string "wild!\p"
# 1568 "data/maps/SootopolisCity/scripts.pory"
	.string "Is all of this because of those\n"
# 1569 "data/maps/SootopolisCity/scripts.pory"
	.string "POKéMON?$"
# 1570 "data/maps/SootopolisCity/scripts.pory"

# 1571 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_YouBroughtFlyingMon:
# 1572 "data/maps/SootopolisCity/scripts.pory"
	.string "Oh?\p"
# 1573 "data/maps/SootopolisCity/scripts.pory"
	.string "It was you who brought that flying\n"
# 1574 "data/maps/SootopolisCity/scripts.pory"
	.string "POKéMON here?\p"
# 1575 "data/maps/SootopolisCity/scripts.pory"
	.string "Well, aren't you amazing!$"
# 1576 "data/maps/SootopolisCity/scripts.pory"

# 1577 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_GroudonPleaseStop:
# 1578 "data/maps/SootopolisCity/scripts.pory"
	.string "MAXIE: G… GROUDON…\n"
# 1579 "data/maps/SootopolisCity/scripts.pory"
	.string "Please! Stop what you're doing!\p"
# 1580 "data/maps/SootopolisCity/scripts.pory"
	.string "I know the extent of your power now!\p"
# 1581 "data/maps/SootopolisCity/scripts.pory"
	.string "If you keep going, all HOENN, not just\n"
# 1582 "data/maps/SootopolisCity/scripts.pory"
	.string "SOOTOPOLIS, will be utterly ruined!$"
# 1583 "data/maps/SootopolisCity/scripts.pory"

# 1584 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_AfterAllOurScheming:
# 1585 "data/maps/SootopolisCity/scripts.pory"
	.string "MAXIE: So the super-ancient POKéMON\n"
# 1586 "data/maps/SootopolisCity/scripts.pory"
	.string "weren't only GROUDON and KYOGRE…\p"
# 1587 "data/maps/SootopolisCity/scripts.pory"
	.string "After all our fruitless scheming and\n"
# 1588 "data/maps/SootopolisCity/scripts.pory"
	.string "frantic efforts, that one POKéMON's\l"
# 1589 "data/maps/SootopolisCity/scripts.pory"
	.string "simple action puts everything right\l"
# 1590 "data/maps/SootopolisCity/scripts.pory"
	.string "again as if nothing had happened…\p"
# 1591 "data/maps/SootopolisCity/scripts.pory"
	.string "Fu…\n"
# 1592 "data/maps/SootopolisCity/scripts.pory"
	.string "Fuhahaha…$"
# 1593 "data/maps/SootopolisCity/scripts.pory"

# 1594 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_KyogreCalmDown:
# 1595 "data/maps/SootopolisCity/scripts.pory"
	.string "ARCHIE: KYOGRE! What's wrong?!\n"
# 1596 "data/maps/SootopolisCity/scripts.pory"
	.string "Look over here! It's the RED ORB!\l"
# 1597 "data/maps/SootopolisCity/scripts.pory"
	.string "Calm down! KYOGRE!\p"
# 1598 "data/maps/SootopolisCity/scripts.pory"
	.string "… … … … … …\n"
# 1599 "data/maps/SootopolisCity/scripts.pory"
	.string "… … … … … …\p"
# 1600 "data/maps/SootopolisCity/scripts.pory"
	.string "It's no good!\n"
# 1601 "data/maps/SootopolisCity/scripts.pory"
	.string "It's not responding at all!$"
# 1602 "data/maps/SootopolisCity/scripts.pory"

# 1603 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_TryingMeaninglessToPokemon:
# 1604 "data/maps/SootopolisCity/scripts.pory"
	.string "ARCHIE: KYOGRE and GROUDON both\n"
# 1605 "data/maps/SootopolisCity/scripts.pory"
	.string "flew off to who knows where.\p"
# 1606 "data/maps/SootopolisCity/scripts.pory"
	.string "The weather in HOENN has returned\n"
# 1607 "data/maps/SootopolisCity/scripts.pory"
	.string "to its normal state…\p"
# 1608 "data/maps/SootopolisCity/scripts.pory"
	.string "Haha…\n"
# 1609 "data/maps/SootopolisCity/scripts.pory"
	.string "Hahaha…\p"
# 1610 "data/maps/SootopolisCity/scripts.pory"
	.string "Maybe what we were trying to do was\n"
# 1611 "data/maps/SootopolisCity/scripts.pory"
	.string "something small, even meaningless,\l"
# 1612 "data/maps/SootopolisCity/scripts.pory"
	.string "to POKéMON…$"
# 1613 "data/maps/SootopolisCity/scripts.pory"

# 1614 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_InvolvedWithCrisisComeWithMe:
# 1615 "data/maps/SootopolisCity/scripts.pory"
	.string "STEVEN: Those POKéMON fighting…\n"
# 1616 "data/maps/SootopolisCity/scripts.pory"
	.string "GROUDON… And KYOGRE…\p"
# 1617 "data/maps/SootopolisCity/scripts.pory"
	.string "The two super-ancient POKéMON\n"
# 1618 "data/maps/SootopolisCity/scripts.pory"
	.string "were awakened from a long sleep…\p"
# 1619 "data/maps/SootopolisCity/scripts.pory"
	.string "And now they are smashing each other\n"
# 1620 "data/maps/SootopolisCity/scripts.pory"
	.string "with their uncontrollable energy…\p"
# 1621 "data/maps/SootopolisCity/scripts.pory"
	.string "…{PLAYER}{KUN}.\p"
# 1622 "data/maps/SootopolisCity/scripts.pory"
	.string "You being here now I'll take to mean\n"
# 1623 "data/maps/SootopolisCity/scripts.pory"
	.string "that you're prepared to become\l"
# 1624 "data/maps/SootopolisCity/scripts.pory"
	.string "involved in this crisis.\p"
# 1625 "data/maps/SootopolisCity/scripts.pory"
	.string "Well, then, there's someone that\n"
# 1626 "data/maps/SootopolisCity/scripts.pory"
	.string "I'd like you to meet.\p"
# 1627 "data/maps/SootopolisCity/scripts.pory"
	.string "Come with me, please.$"
# 1628 "data/maps/SootopolisCity/scripts.pory"

# 1629 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DoesThisMakeYourFearPokemon:
# 1630 "data/maps/SootopolisCity/scripts.pory"
	.string "STEVEN: Listen, {PLAYER}{KUN}.\p"
# 1631 "data/maps/SootopolisCity/scripts.pory"
	.string "Does seeing GROUDON and KYOGRE make\n"
# 1632 "data/maps/SootopolisCity/scripts.pory"
	.string "you think POKéMON are to be feared?\p"
# 1633 "data/maps/SootopolisCity/scripts.pory"
	.string "But that's not true.\n"
# 1634 "data/maps/SootopolisCity/scripts.pory"
	.string "POKéMON are really more…\p"
# 1635 "data/maps/SootopolisCity/scripts.pory"
	.string "…Why am I asking you this?\n"
# 1636 "data/maps/SootopolisCity/scripts.pory"
	.string "You already know.$"
# 1637 "data/maps/SootopolisCity/scripts.pory"

# 1638 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_HereWereAreHelpWallace:
# 1639 "data/maps/SootopolisCity/scripts.pory"
	.string "STEVEN: Okay, here we are!\p"
# 1640 "data/maps/SootopolisCity/scripts.pory"
	.string "Inside here you'll find someone named\n"
# 1641 "data/maps/SootopolisCity/scripts.pory"
	.string "WALLACE.\p"
# 1642 "data/maps/SootopolisCity/scripts.pory"
	.string "I think you have what's needed to\n"
# 1643 "data/maps/SootopolisCity/scripts.pory"
	.string "help him…$"
# 1644 "data/maps/SootopolisCity/scripts.pory"

# 1645 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_KnowWhatsNeededToHelpHim:
# 1646 "data/maps/SootopolisCity/scripts.pory"
	.string "STEVEN: I think you have what's\n"
# 1647 "data/maps/SootopolisCity/scripts.pory"
	.string "needed to help him…$"
# 1648 "data/maps/SootopolisCity/scripts.pory"

# 1649 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_NeverBeenToSkyPillar:
# 1650 "data/maps/SootopolisCity/scripts.pory"
	.string "STEVEN: The SKY PILLAR…\p"
# 1651 "data/maps/SootopolisCity/scripts.pory"
	.string "I've never been there.\n"
# 1652 "data/maps/SootopolisCity/scripts.pory"
	.string "I wonder where it could be?$"
# 1653 "data/maps/SootopolisCity/scripts.pory"

# 1654 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_SoThatsRayquaza:
# 1655 "data/maps/SootopolisCity/scripts.pory"
	.string "STEVEN: So that's RAYQUAZA…\p"
# 1656 "data/maps/SootopolisCity/scripts.pory"
	.string "It's incredible how the two rampaging\n"
# 1657 "data/maps/SootopolisCity/scripts.pory"
	.string "POKéMON would flee from it in fear…$"
# 1658 "data/maps/SootopolisCity/scripts.pory"

# 1659 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_MaxieArchieLeft:
# 1660 "data/maps/SootopolisCity/scripts.pory"
	.string "STEVEN: It looks like both MAXIE and\n"
# 1661 "data/maps/SootopolisCity/scripts.pory"
	.string "ARCHIE have gone away somewhere.\p"
# 1662 "data/maps/SootopolisCity/scripts.pory"
	.string "Perhaps they've gone to MT. PYRE to\n"
# 1663 "data/maps/SootopolisCity/scripts.pory"
	.string "return those ORBS…$"
# 1664 "data/maps/SootopolisCity/scripts.pory"

# 1665 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_HaventYouScaledSkyPillar:
# 1666 "data/maps/SootopolisCity/scripts.pory"
	.string "WALLACE: Oh?\n"
# 1667 "data/maps/SootopolisCity/scripts.pory"
	.string "{PLAYER}{KUN}?\p"
# 1668 "data/maps/SootopolisCity/scripts.pory"
	.string "Haven't you scaled the SKY PILLAR\n"
# 1669 "data/maps/SootopolisCity/scripts.pory"
	.string "yet?\p"
# 1670 "data/maps/SootopolisCity/scripts.pory"
	.string "I'm sure that you can make it to\n"
# 1671 "data/maps/SootopolisCity/scripts.pory"
	.string "the top of the SKY PILLAR…$"
# 1672 "data/maps/SootopolisCity/scripts.pory"

# 1673 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_AquaMagmaDidntMeanHarm:
# 1674 "data/maps/SootopolisCity/scripts.pory"
	.string "WALLACE: {PLAYER}{KUN}…\p"
# 1675 "data/maps/SootopolisCity/scripts.pory"
	.string "The leaders of TEAM MAGMA and AQUA,\n"
# 1676 "data/maps/SootopolisCity/scripts.pory"
	.string "I don't think they meant harm.\p"
# 1677 "data/maps/SootopolisCity/scripts.pory"
	.string "It wouldn't hurt to hear what they\n"
# 1678 "data/maps/SootopolisCity/scripts.pory"
	.string "have to say for themselves.$"
# 1679 "data/maps/SootopolisCity/scripts.pory"

# 1680 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ThankYouForHelpAcceptThis:
# 1681 "data/maps/SootopolisCity/scripts.pory"
	.string "WALLACE: {PLAYER}{KUN}…\n"
# 1682 "data/maps/SootopolisCity/scripts.pory"
	.string "My eyes didn't deceive me.\p"
# 1683 "data/maps/SootopolisCity/scripts.pory"
	.string "Thanks to your help, SOOTOPOLIS…\n"
# 1684 "data/maps/SootopolisCity/scripts.pory"
	.string "No, all of HOENN was saved.\p"
# 1685 "data/maps/SootopolisCity/scripts.pory"
	.string "On behalf of the people, I thank you.\p"
# 1686 "data/maps/SootopolisCity/scripts.pory"
	.string "This is a gift from me.\n"
# 1687 "data/maps/SootopolisCity/scripts.pory"
	.string "Please accept it.$"
# 1688 "data/maps/SootopolisCity/scripts.pory"

# 1689 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_ExplainWaterfallGoToGym:
# 1690 "data/maps/SootopolisCity/scripts.pory"
	.string "That HIDDEN MACHINE contains\n"
# 1691 "data/maps/SootopolisCity/scripts.pory"
	.string "WATERFALL.\p"
# 1692 "data/maps/SootopolisCity/scripts.pory"
	.string "If you have the RAIN BADGE, a POKéMON\n"
# 1693 "data/maps/SootopolisCity/scripts.pory"
	.string "that has learned that HM move can\l"
# 1694 "data/maps/SootopolisCity/scripts.pory"
	.string "force its way up waterfalls.\p"
# 1695 "data/maps/SootopolisCity/scripts.pory"
	.string "And where does one get the RAIN BADGE?\n"
# 1696 "data/maps/SootopolisCity/scripts.pory"
	.string "You know, don't you?\p"
# 1697 "data/maps/SootopolisCity/scripts.pory"
	.string "That's right! You have to beat\n"
# 1698 "data/maps/SootopolisCity/scripts.pory"
	.string "the SOOTOPOLIS GYM LEADER.\p"
# 1699 "data/maps/SootopolisCity/scripts.pory"
	.string "When you're all set to go, step through\n"
# 1700 "data/maps/SootopolisCity/scripts.pory"
	.string "that door.$"
# 1701 "data/maps/SootopolisCity/scripts.pory"

# 1702 "data/maps/SootopolisCity/scripts.pory"
SootopolisCity_Text_DazzledByMentor:
# 1703 "data/maps/SootopolisCity/scripts.pory"
	.string "WALLACE: I'm sure that you will be\n"
# 1704 "data/maps/SootopolisCity/scripts.pory"
	.string "dazzled by my mentor's breathtakingly\l"
# 1705 "data/maps/SootopolisCity/scripts.pory"
	.string "elegant battle style.$"
