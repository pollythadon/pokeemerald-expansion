# 1 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_MapScripts::
# 2 "data/maps/LilycoveCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
# 3 "data/maps/LilycoveCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
# 4 "data/maps/LilycoveCity/scripts.pory"
	.byte 0
# 5 "data/maps/LilycoveCity/scripts.pory"

# 6 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_OnTransition:
# 7 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_VISITED_LILYCOVE_CITY
# 8 "data/maps/LilycoveCity/scripts.pory"
	setvar VAR_CONTEST_HALL_STATE, 0
# 9 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
# 10 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
# 11 "data/maps/LilycoveCity/scripts.pory"
	call Common_EventScript_SetupRivalGfxId
# 12 "data/maps/LilycoveCity/scripts.pory"
	end
# 13 "data/maps/LilycoveCity/scripts.pory"

# 14 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_OnLoad:
# 15 "data/maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
# 16 "data/maps/LilycoveCity/scripts.pory"
	end
# 17 "data/maps/LilycoveCity/scripts.pory"

# 18 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_SetWailmerMetatiles::
# 19 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
# 20 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
# 21 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
# 22 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
# 23 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
# 24 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
# 25 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
# 26 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
# 27 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
# 28 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
# 29 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
# 30 "data/maps/LilycoveCity/scripts.pory"
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
# 31 "data/maps/LilycoveCity/scripts.pory"
	return
# 32 "data/maps/LilycoveCity/scripts.pory"

# 33 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BerryGentleman::
# 34 "data/maps/LilycoveCity/scripts.pory"
	lock
# 35 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 36 "data/maps/LilycoveCity/scripts.pory"
	dotimebasedevents
# 37 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
# 38 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
# 39 "data/maps/LilycoveCity/scripts.pory"
	giverandomberry BERRY_ID_CHERI, BERRY_ID_SITRUS
# 40 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 41 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
# 42 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
# 43 "data/maps/LilycoveCity/scripts.pory"
	release
# 44 "data/maps/LilycoveCity/scripts.pory"
	end
# 45 "data/maps/LilycoveCity/scripts.pory"

# 46 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ReceivedBerry::
# 47 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
# 48 "data/maps/LilycoveCity/scripts.pory"
	release
# 49 "data/maps/LilycoveCity/scripts.pory"
	end
# 50 "data/maps/LilycoveCity/scripts.pory"

# 51 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man3::
# 52 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
# 53 "data/maps/LilycoveCity/scripts.pory"
	end
# 54 "data/maps/LilycoveCity/scripts.pory"

# 55 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Girl::
# 56 "data/maps/LilycoveCity/scripts.pory"
	lock
# 57 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 58 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
# 59 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
# 60 "data/maps/LilycoveCity/scripts.pory"
	release
# 61 "data/maps/LilycoveCity/scripts.pory"
	end
# 62 "data/maps/LilycoveCity/scripts.pory"

# 63 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_GirlAquaGone::
# 64 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
# 65 "data/maps/LilycoveCity/scripts.pory"
	release
# 66 "data/maps/LilycoveCity/scripts.pory"
	end
# 67 "data/maps/LilycoveCity/scripts.pory"

# 68 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_RichBoy::
# 69 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
# 70 "data/maps/LilycoveCity/scripts.pory"
	end
# 71 "data/maps/LilycoveCity/scripts.pory"

# 72 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor2::
# 73 "data/maps/LilycoveCity/scripts.pory"
	lock
# 74 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 75 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
# 76 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
# 77 "data/maps/LilycoveCity/scripts.pory"
	release
# 78 "data/maps/LilycoveCity/scripts.pory"
	end
# 79 "data/maps/LilycoveCity/scripts.pory"

# 80 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor2AquaGone::
# 81 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
# 82 "data/maps/LilycoveCity/scripts.pory"
	release
# 83 "data/maps/LilycoveCity/scripts.pory"
	end
# 84 "data/maps/LilycoveCity/scripts.pory"

# 85 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman2::
# 86 "data/maps/LilycoveCity/scripts.pory"
	lock
# 87 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 88 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
# 89 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
# 90 "data/maps/LilycoveCity/scripts.pory"
	release
# 91 "data/maps/LilycoveCity/scripts.pory"
	end
# 92 "data/maps/LilycoveCity/scripts.pory"

# 93 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman2AquaGone::
# 94 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
# 95 "data/maps/LilycoveCity/scripts.pory"
	release
# 96 "data/maps/LilycoveCity/scripts.pory"
	end
# 97 "data/maps/LilycoveCity/scripts.pory"

# 98 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man2::
# 99 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
# 100 "data/maps/LilycoveCity/scripts.pory"
	end
# 101 "data/maps/LilycoveCity/scripts.pory"

# 102 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM1::
# 103 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
# 104 "data/maps/LilycoveCity/scripts.pory"
	end
# 105 "data/maps/LilycoveCity/scripts.pory"

# 106 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertF::
# 107 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
# 108 "data/maps/LilycoveCity/scripts.pory"
	end
# 109 "data/maps/LilycoveCity/scripts.pory"

# 110 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM2::
# 111 "data/maps/LilycoveCity/scripts.pory"
	lock
# 112 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 113 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
# 114 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
# 115 "data/maps/LilycoveCity/scripts.pory"
	release
# 116 "data/maps/LilycoveCity/scripts.pory"
	end
# 117 "data/maps/LilycoveCity/scripts.pory"

# 118 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ExpertM2AquaGone::
# 119 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
# 120 "data/maps/LilycoveCity/scripts.pory"
	release
# 121 "data/maps/LilycoveCity/scripts.pory"
	end
# 122 "data/maps/LilycoveCity/scripts.pory"

# 123 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Sailor1::
# 124 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
# 125 "data/maps/LilycoveCity/scripts.pory"
	end
# 126 "data/maps/LilycoveCity/scripts.pory"

# 127 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_FatMan::
# 128 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
# 129 "data/maps/LilycoveCity/scripts.pory"
	end
# 130 "data/maps/LilycoveCity/scripts.pory"

# 131 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Man1::
# 132 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 133 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
# 134 "data/maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_LILYCOVE_MAN_1, Common_Movement_FaceOriginalDirection
# 135 "data/maps/LilycoveCity/scripts.pory"
	end
# 136 "data/maps/LilycoveCity/scripts.pory"

# 137 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Woman1::
# 138 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 139 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
# 140 "data/maps/LilycoveCity/scripts.pory"
	applymovement LOCALID_LILYCOVE_WOMAN_1, Common_Movement_FaceOriginalDirection
# 141 "data/maps/LilycoveCity/scripts.pory"
	end
# 142 "data/maps/LilycoveCity/scripts.pory"

# 143 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_CitySign::
# 144 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
# 145 "data/maps/LilycoveCity/scripts.pory"
	end
# 146 "data/maps/LilycoveCity/scripts.pory"

# 147 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_ContestHallSign::
# 148 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
# 149 "data/maps/LilycoveCity/scripts.pory"
	end
# 150 "data/maps/LilycoveCity/scripts.pory"

# 151 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MotelSign::
# 152 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
# 153 "data/maps/LilycoveCity/scripts.pory"
	end
# 154 "data/maps/LilycoveCity/scripts.pory"

# 155 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MuseumSign::
# 156 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 157 "data/maps/LilycoveCity/scripts.pory"
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
# 158 "data/maps/LilycoveCity/scripts.pory"
	switch VAR_0x8004
# 159 "data/maps/LilycoveCity/scripts.pory"
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
# 160 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
# 161 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 162 "data/maps/LilycoveCity/scripts.pory"
	end
# 163 "data/maps/LilycoveCity/scripts.pory"

# 164 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MuseumSignNoPaintings::
# 165 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
# 166 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 167 "data/maps/LilycoveCity/scripts.pory"
	end
# 168 "data/maps/LilycoveCity/scripts.pory"

# 169 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HarborSign::
# 170 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 171 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
# 172 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
# 173 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 174 "data/maps/LilycoveCity/scripts.pory"
	end
# 175 "data/maps/LilycoveCity/scripts.pory"

# 176 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HarborSignFerryReady::
# 177 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
# 178 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 179 "data/maps/LilycoveCity/scripts.pory"
	end
# 180 "data/maps/LilycoveCity/scripts.pory"

# 181 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_TrainerFanClubSign::
# 182 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
# 183 "data/maps/LilycoveCity/scripts.pory"
	end
# 184 "data/maps/LilycoveCity/scripts.pory"

# 185 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DepartmentStoreSign::
# 186 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
# 187 "data/maps/LilycoveCity/scripts.pory"
	end
# 188 "data/maps/LilycoveCity/scripts.pory"

# 189 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MoveDeletersHouseSign::
# 190 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
# 191 "data/maps/LilycoveCity/scripts.pory"
	end
# 192 "data/maps/LilycoveCity/scripts.pory"

# 193 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_WailmerTrainerGrunt::
# 194 "data/maps/LilycoveCity/scripts.pory"
	lockall
# 195 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
# 196 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
# 197 "data/maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
# 198 "data/maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 199 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
# 200 "data/maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
# 201 "data/maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 202 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_MET_WAILMER_TRAINER
# 203 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 204 "data/maps/LilycoveCity/scripts.pory"
	end
# 205 "data/maps/LilycoveCity/scripts.pory"

# 206 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MetWailmerTrainer::
# 207 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
# 208 "data/maps/LilycoveCity/scripts.pory"
	releaseall
# 209 "data/maps/LilycoveCity/scripts.pory"
	end
# 210 "data/maps/LilycoveCity/scripts.pory"

# 211 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt1::
# 212 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
# 213 "data/maps/LilycoveCity/scripts.pory"
	end
# 214 "data/maps/LilycoveCity/scripts.pory"

# 215 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt2::
# 216 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
# 217 "data/maps/LilycoveCity/scripts.pory"
	end
# 218 "data/maps/LilycoveCity/scripts.pory"

# 219 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt3::
# 220 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
# 221 "data/maps/LilycoveCity/scripts.pory"
	end
# 222 "data/maps/LilycoveCity/scripts.pory"

# 223 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_AquaGrunt4::
# 224 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
# 225 "data/maps/LilycoveCity/scripts.pory"
	end
# 226 "data/maps/LilycoveCity/scripts.pory"

# 227 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Rival::
# 228 "data/maps/LilycoveCity/scripts.pory"
	lock
# 229 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 230 "data/maps/LilycoveCity/scripts.pory"
	checkplayergender
# 231 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
# 232 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
# 233 "data/maps/LilycoveCity/scripts.pory"
	end
# 234 "data/maps/LilycoveCity/scripts.pory"

# 235 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_May::
# 236 "data/maps/LilycoveCity/scripts.pory"
	playbgm MUS_ENCOUNTER_MAY, TRUE
# 237 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
# 238 "data/maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
# 239 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
# 240 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
# 241 "data/maps/LilycoveCity/scripts.pory"
	switch VAR_STARTER_MON
# 242 "data/maps/LilycoveCity/scripts.pory"
	case 0, LilycoveCity_EventScript_BattleMayTreecko
# 243 "data/maps/LilycoveCity/scripts.pory"
	case 1, LilycoveCity_EventScript_BattleMayTorchic
# 244 "data/maps/LilycoveCity/scripts.pory"
	case 2, LilycoveCity_EventScript_BattleMayMudkip
# 245 "data/maps/LilycoveCity/scripts.pory"
	end
# 246 "data/maps/LilycoveCity/scripts.pory"

# 247 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayAskToBattleAgain::
# 248 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
# 249 "data/maps/LilycoveCity/scripts.pory"
	return
# 250 "data/maps/LilycoveCity/scripts.pory"

# 251 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayAskToBattle::
# 252 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
# 253 "data/maps/LilycoveCity/scripts.pory"
	return
# 254 "data/maps/LilycoveCity/scripts.pory"

# 255 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DeclineMayBattle::
# 256 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
# 257 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
# 258 "data/maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 259 "data/maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 260 "data/maps/LilycoveCity/scripts.pory"
	release
# 261 "data/maps/LilycoveCity/scripts.pory"
	end
# 262 "data/maps/LilycoveCity/scripts.pory"

# 263 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_Brendan::
# 264 "data/maps/LilycoveCity/scripts.pory"
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
# 265 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
# 266 "data/maps/LilycoveCity/scripts.pory"
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
# 267 "data/maps/LilycoveCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
# 268 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
# 269 "data/maps/LilycoveCity/scripts.pory"
	switch VAR_STARTER_MON
# 270 "data/maps/LilycoveCity/scripts.pory"
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
# 271 "data/maps/LilycoveCity/scripts.pory"
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
# 272 "data/maps/LilycoveCity/scripts.pory"
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
# 273 "data/maps/LilycoveCity/scripts.pory"
	end
# 274 "data/maps/LilycoveCity/scripts.pory"

# 275 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanAskToBattleAgain::
# 276 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
# 277 "data/maps/LilycoveCity/scripts.pory"
	return
# 278 "data/maps/LilycoveCity/scripts.pory"

# 279 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanAskToBattle::
# 280 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
# 281 "data/maps/LilycoveCity/scripts.pory"
	return
# 282 "data/maps/LilycoveCity/scripts.pory"

# 283 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DeclineBrendanBattle::
# 284 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
# 285 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
# 286 "data/maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 287 "data/maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 288 "data/maps/LilycoveCity/scripts.pory"
	release
# 289 "data/maps/LilycoveCity/scripts.pory"
	end
# 290 "data/maps/LilycoveCity/scripts.pory"

# 291 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayTreecko::
# 292 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
# 293 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 294 "data/maps/LilycoveCity/scripts.pory"
	end
# 295 "data/maps/LilycoveCity/scripts.pory"

# 296 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayTorchic::
# 297 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
# 298 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 299 "data/maps/LilycoveCity/scripts.pory"
	end
# 300 "data/maps/LilycoveCity/scripts.pory"

# 301 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleMayMudkip::
# 302 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
# 303 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedMay
# 304 "data/maps/LilycoveCity/scripts.pory"
	end
# 305 "data/maps/LilycoveCity/scripts.pory"

# 306 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanTreecko::
# 307 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
# 308 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 309 "data/maps/LilycoveCity/scripts.pory"
	end
# 310 "data/maps/LilycoveCity/scripts.pory"

# 311 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanTorchic::
# 312 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
# 313 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 314 "data/maps/LilycoveCity/scripts.pory"
	end
# 315 "data/maps/LilycoveCity/scripts.pory"

# 316 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BattleBrendanMudkip::
# 317 "data/maps/LilycoveCity/scripts.pory"
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
# 318 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_DefeatedBrendan
# 319 "data/maps/LilycoveCity/scripts.pory"
	end
# 320 "data/maps/LilycoveCity/scripts.pory"

# 321 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DefeatedMay::
# 322 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
# 323 "data/maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, FALSE
# 324 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
# 325 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
# 326 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
# 327 "data/maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
# 328 "data/maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
# 329 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_RivalFlyAway
# 330 "data/maps/LilycoveCity/scripts.pory"
	end
# 331 "data/maps/LilycoveCity/scripts.pory"

# 332 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_CheckFinalBadge::
# 333 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
# 334 "data/maps/LilycoveCity/scripts.pory"
	return
# 335 "data/maps/LilycoveCity/scripts.pory"

# 336 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_HasFinalBadge::
# 337 "data/maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, TRUE
# 338 "data/maps/LilycoveCity/scripts.pory"
	return
# 339 "data/maps/LilycoveCity/scripts.pory"

# 340 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayCollectBadges::
# 341 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
# 342 "data/maps/LilycoveCity/scripts.pory"
	return
# 343 "data/maps/LilycoveCity/scripts.pory"

# 344 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayPokemonLeague::
# 345 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
# 346 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
# 347 "data/maps/LilycoveCity/scripts.pory"
	return
# 348 "data/maps/LilycoveCity/scripts.pory"

# 349 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_MayBattleFrontier::
# 350 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
# 351 "data/maps/LilycoveCity/scripts.pory"
	return
# 352 "data/maps/LilycoveCity/scripts.pory"

# 353 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DefeatedBrendan::
# 354 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
# 355 "data/maps/LilycoveCity/scripts.pory"
	setvar VAR_RESULT, FALSE
# 356 "data/maps/LilycoveCity/scripts.pory"
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
# 357 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
# 358 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
# 359 "data/maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
# 360 "data/maps/LilycoveCity/scripts.pory"
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
# 361 "data/maps/LilycoveCity/scripts.pory"
	goto LilycoveCity_EventScript_RivalFlyAway
# 362 "data/maps/LilycoveCity/scripts.pory"
	end
# 363 "data/maps/LilycoveCity/scripts.pory"

# 364 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanCollectBadges::
# 365 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
# 366 "data/maps/LilycoveCity/scripts.pory"
	return
# 367 "data/maps/LilycoveCity/scripts.pory"

# 368 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanPokemonLeague::
# 369 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
# 370 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
# 371 "data/maps/LilycoveCity/scripts.pory"
	return
# 372 "data/maps/LilycoveCity/scripts.pory"

# 373 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_BrendanBattleFrontier::
# 374 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
# 375 "data/maps/LilycoveCity/scripts.pory"
	return
# 376 "data/maps/LilycoveCity/scripts.pory"

# 377 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_RivalFlyAway::
# 378 "data/maps/LilycoveCity/scripts.pory"
	closemessage
# 379 "data/maps/LilycoveCity/scripts.pory"
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
# 380 "data/maps/LilycoveCity/scripts.pory"
	waitmovement 0
# 381 "data/maps/LilycoveCity/scripts.pory"
	delay 50
# 382 "data/maps/LilycoveCity/scripts.pory"
	setfieldeffectargument 0, 1
# 383 "data/maps/LilycoveCity/scripts.pory"
	dofieldeffect FLDEFF_NPCFLY_OUT
# 384 "data/maps/LilycoveCity/scripts.pory"
	delay 15
# 385 "data/maps/LilycoveCity/scripts.pory"
	removeobject VAR_LAST_TALKED
# 386 "data/maps/LilycoveCity/scripts.pory"
	waitfieldeffect FLDEFF_NPCFLY_OUT
# 387 "data/maps/LilycoveCity/scripts.pory"
	savebgm MUS_DUMMY
# 388 "data/maps/LilycoveCity/scripts.pory"
	fadedefaultbgm
# 389 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_MET_RIVAL_LILYCOVE
# 390 "data/maps/LilycoveCity/scripts.pory"
	release
# 391 "data/maps/LilycoveCity/scripts.pory"
	end
# 392 "data/maps/LilycoveCity/scripts.pory"

# 393 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_SchoolKidM::
# 394 "data/maps/LilycoveCity/scripts.pory"
	lock
# 395 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 396 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
# 397 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
# 398 "data/maps/LilycoveCity/scripts.pory"
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
# 399 "data/maps/LilycoveCity/scripts.pory"
	release
# 400 "data/maps/LilycoveCity/scripts.pory"
	end
# 401 "data/maps/LilycoveCity/scripts.pory"

# 402 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_KnowAboutBerryBlender::
# 403 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
# 404 "data/maps/LilycoveCity/scripts.pory"
	return
# 405 "data/maps/LilycoveCity/scripts.pory"

# 406 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_EventScript_DontKnowAboutBerryBlender::
# 407 "data/maps/LilycoveCity/scripts.pory"
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
# 408 "data/maps/LilycoveCity/scripts.pory"
	return
# 409 "data/maps/LilycoveCity/scripts.pory"

# 410 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayShoppingLetsBattle:
# 411 "data/maps/LilycoveCity/scripts.pory"
	.string "MAY: Oh, hey?\n"
# 412 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, are you shopping, too?\p"
# 413 "data/maps/LilycoveCity/scripts.pory"
	.string "I bought a whole bunch of DOLLS and\n"
# 414 "data/maps/LilycoveCity/scripts.pory"
	.string "POSTERS.\p"
# 415 "data/maps/LilycoveCity/scripts.pory"
	.string "Of course, I've also caught a lot of\n"
# 416 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéMON, and I'm raising them\l"
# 417 "data/maps/LilycoveCity/scripts.pory"
	.string "properly, too.\p"
# 418 "data/maps/LilycoveCity/scripts.pory"
	.string "Actually, I'm more worried if you're\n"
# 419 "data/maps/LilycoveCity/scripts.pory"
	.string "raising POKéMON properly, {PLAYER}{KUN}.\p"
# 420 "data/maps/LilycoveCity/scripts.pory"
	.string "I'll battle with you, so you can show\n"
# 421 "data/maps/LilycoveCity/scripts.pory"
	.string "me your POKéMON, {PLAYER}{KUN}.$"
# 422 "data/maps/LilycoveCity/scripts.pory"

# 423 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayNotRaisingPokemon:
# 424 "data/maps/LilycoveCity/scripts.pory"
	.string "MAY: Oh, why? {PLAYER}{KUN}, haven't you\n"
# 425 "data/maps/LilycoveCity/scripts.pory"
	.string "been raising your POKéMON?\p"
# 426 "data/maps/LilycoveCity/scripts.pory"
	.string "That's not a very good showing as a\n"
# 427 "data/maps/LilycoveCity/scripts.pory"
	.string "TRAINER…$"
# 428 "data/maps/LilycoveCity/scripts.pory"

# 429 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayBattleMe:
# 430 "data/maps/LilycoveCity/scripts.pory"
	.string "MAY: Come on, battle with me, so I can\n"
# 431 "data/maps/LilycoveCity/scripts.pory"
	.string "check out your POKéMON!$"
# 432 "data/maps/LilycoveCity/scripts.pory"

# 433 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayWontBeBeaten:
# 434 "data/maps/LilycoveCity/scripts.pory"
	.string "MAY: The POKéMON I raised won't be\n"
# 435 "data/maps/LilycoveCity/scripts.pory"
	.string "beaten by your POKéMON, {PLAYER}{KUN}!$"
# 436 "data/maps/LilycoveCity/scripts.pory"

# 437 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayDefeat:
# 438 "data/maps/LilycoveCity/scripts.pory"
	.string "… … … … … … … …\p"
# 439 "data/maps/LilycoveCity/scripts.pory"
	.string "I remember the battle I had with you,\n"
# 440 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, on ROUTE 103.\p"
# 441 "data/maps/LilycoveCity/scripts.pory"
	.string "That battle helped you become this\n"
# 442 "data/maps/LilycoveCity/scripts.pory"
	.string "strong, {PLAYER}{KUN}, didn't it?$"
# 443 "data/maps/LilycoveCity/scripts.pory"

# 444 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayGoingBackToLittleroot:
# 445 "data/maps/LilycoveCity/scripts.pory"
	.string "MAY: I'm thinking of going back to\n"
# 446 "data/maps/LilycoveCity/scripts.pory"
	.string "LITTLEROOT soon.\p"
# 447 "data/maps/LilycoveCity/scripts.pory"
	.string "I've caught a decent group of POKéMON,\n"
# 448 "data/maps/LilycoveCity/scripts.pory"
	.string "and my POKéDEX is coming along, so\l"
# 449 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm going home to show my dad.$"
# 450 "data/maps/LilycoveCity/scripts.pory"

# 451 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToCollectBadges:
# 452 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 453 "data/maps/LilycoveCity/scripts.pory"
	.string "Collect all the GYM BADGES and take\n"
# 454 "data/maps/LilycoveCity/scripts.pory"
	.string "the POKéMON LEAGUE challenge?\p"
# 455 "data/maps/LilycoveCity/scripts.pory"
	.string "Well, while you're collecting BADGES,\n"
# 456 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, I'm going to work on my\l"
# 457 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéDEX. I'll complete it before you!\p"
# 458 "data/maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 459 "data/maps/LilycoveCity/scripts.pory"

# 460 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToPokemonLeague:
# 461 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 462 "data/maps/LilycoveCity/scripts.pory"
	.string "Are you taking the POKéMON LEAGUE\n"
# 463 "data/maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 464 "data/maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 465 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 466 "data/maps/LilycoveCity/scripts.pory"
	.string "I might've lost to you in battling,\n"
# 467 "data/maps/LilycoveCity/scripts.pory"
	.string "but I'll finish my POKéDEX before you!\p"
# 468 "data/maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 469 "data/maps/LilycoveCity/scripts.pory"

# 470 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MayYouGoingToBattleFrontier:
# 471 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}{KUN}, what are you going to do?\p"
# 472 "data/maps/LilycoveCity/scripts.pory"
	.string "Are you taking the BATTLE FRONTIER\n"
# 473 "data/maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 474 "data/maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 475 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 476 "data/maps/LilycoveCity/scripts.pory"
	.string "I might've lost to you in battling,\n"
# 477 "data/maps/LilycoveCity/scripts.pory"
	.string "but I'll finish my POKéDEX before you!\p"
# 478 "data/maps/LilycoveCity/scripts.pory"
	.string "See you!$"
# 479 "data/maps/LilycoveCity/scripts.pory"

# 480 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanShoppingLetsBattle:
# 481 "data/maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Oh, hey, it's {PLAYER}.\p"
# 482 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm running an errand for my dad.\n"
# 483 "data/maps/LilycoveCity/scripts.pory"
	.string "No, I'm not buying any DOLLS.\p"
# 484 "data/maps/LilycoveCity/scripts.pory"
	.string "Anyways, it's been a while.\p"
# 485 "data/maps/LilycoveCity/scripts.pory"
	.string "Want to have a battle to see who's been\n"
# 486 "data/maps/LilycoveCity/scripts.pory"
	.string "raising POKéMON better?$"
# 487 "data/maps/LilycoveCity/scripts.pory"

# 488 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanNoConfidence:
# 489 "data/maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Oh, what's the matter?\n"
# 490 "data/maps/LilycoveCity/scripts.pory"
	.string "Don't have the confidence?$"
# 491 "data/maps/LilycoveCity/scripts.pory"

# 492 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanBattleMe:
# 493 "data/maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Want to battle to see who's\n"
# 494 "data/maps/LilycoveCity/scripts.pory"
	.string "been raising POKéMON better?$"
# 495 "data/maps/LilycoveCity/scripts.pory"

# 496 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanWontBeBeaten:
# 497 "data/maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: Aww, but you know I'm not\n"
# 498 "data/maps/LilycoveCity/scripts.pory"
	.string "going to lose to no {PLAYER}.$"
# 499 "data/maps/LilycoveCity/scripts.pory"

# 500 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanDefeat:
# 501 "data/maps/LilycoveCity/scripts.pory"
	.string "Humph…\n"
# 502 "data/maps/LilycoveCity/scripts.pory"
	.string "You've done a lot of raising.\p"
# 503 "data/maps/LilycoveCity/scripts.pory"
	.string "That stings a bit--I had a head start\n"
# 504 "data/maps/LilycoveCity/scripts.pory"
	.string "on you as a TRAINER…$"
# 505 "data/maps/LilycoveCity/scripts.pory"

# 506 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanGoingBackToLittleroot:
# 507 "data/maps/LilycoveCity/scripts.pory"
	.string "BRENDAN: I…\n"
# 508 "data/maps/LilycoveCity/scripts.pory"
	.string "I plan on going home to LITTLEROOT.\p"
# 509 "data/maps/LilycoveCity/scripts.pory"
	.string "You know I'm helping out my dad on his\n"
# 510 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéDEX. It's coming together pretty\l"
# 511 "data/maps/LilycoveCity/scripts.pory"
	.string "decently, so I should go show him.$"
# 512 "data/maps/LilycoveCity/scripts.pory"

# 513 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToCollectBadges:
# 514 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 515 "data/maps/LilycoveCity/scripts.pory"
	.string "Collect all the GYM BADGES and take\n"
# 516 "data/maps/LilycoveCity/scripts.pory"
	.string "the POKéMON LEAGUE challenge?\p"
# 517 "data/maps/LilycoveCity/scripts.pory"
	.string "Maybe I'll do that, too…\p"
# 518 "data/maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 519 "data/maps/LilycoveCity/scripts.pory"

# 520 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
# 521 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 522 "data/maps/LilycoveCity/scripts.pory"
	.string "Since you're that strong, are you\n"
# 523 "data/maps/LilycoveCity/scripts.pory"
	.string "taking the POKéMON LEAGUE challenge?\p"
# 524 "data/maps/LilycoveCity/scripts.pory"
	.string "Heh, even me--if I trained my POKéMON\n"
# 525 "data/maps/LilycoveCity/scripts.pory"
	.string "a bit more, I should be stronger than\l"
# 526 "data/maps/LilycoveCity/scripts.pory"
	.string "you, {PLAYER}.\p"
# 527 "data/maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 528 "data/maps/LilycoveCity/scripts.pory"

# 529 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
# 530 "data/maps/LilycoveCity/scripts.pory"
	.string "{PLAYER}, what are you going to do?\p"
# 531 "data/maps/LilycoveCity/scripts.pory"
	.string "Are you taking the BATTLE FRONTIER\n"
# 532 "data/maps/LilycoveCity/scripts.pory"
	.string "challenge?\p"
# 533 "data/maps/LilycoveCity/scripts.pory"
	.string "Or, are you going to complete your\n"
# 534 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéDEX?\p"
# 535 "data/maps/LilycoveCity/scripts.pory"
	.string "Since you're that strong, you should\n"
# 536 "data/maps/LilycoveCity/scripts.pory"
	.string "consider the BATTLE FRONTIER.\p"
# 537 "data/maps/LilycoveCity/scripts.pory"
	.string "Heh, if I train my POKéMON a bit more,\n"
# 538 "data/maps/LilycoveCity/scripts.pory"
	.string "I'll get stronger than you, {PLAYER}.\p"
# 539 "data/maps/LilycoveCity/scripts.pory"
	.string "Maybe I should go to the BATTLE\n"
# 540 "data/maps/LilycoveCity/scripts.pory"
	.string "FRONTIER.\p"
# 541 "data/maps/LilycoveCity/scripts.pory"
	.string "Well, anyway, hang in there!$"
# 542 "data/maps/LilycoveCity/scripts.pory"

# 543 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MovedLootIntoHideoutToday:
# 544 "data/maps/LilycoveCity/scripts.pory"
	.string "Fufufu…\p"
# 545 "data/maps/LilycoveCity/scripts.pory"
	.string "We moved more loot into our secret\n"
# 546 "data/maps/LilycoveCity/scripts.pory"
	.string "HIDEOUT today…\p"
# 547 "data/maps/LilycoveCity/scripts.pory"
	.string "Wh-who are you?!\n"
# 548 "data/maps/LilycoveCity/scripts.pory"
	.string "I was just talking to myself!$"
# 549 "data/maps/LilycoveCity/scripts.pory"

# 550 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ChanceToDoBigThings:
# 551 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm just a GRUNT, so I don't know what\n"
# 552 "data/maps/LilycoveCity/scripts.pory"
	.string "the BOSS is thinking…\p"
# 553 "data/maps/LilycoveCity/scripts.pory"
	.string "But being on TEAM AQUA, I know I'll get\n"
# 554 "data/maps/LilycoveCity/scripts.pory"
	.string "the chance to do big things!\p"
# 555 "data/maps/LilycoveCity/scripts.pory"
	.string "Wh-who are you?!\n"
# 556 "data/maps/LilycoveCity/scripts.pory"
	.string "I was just talking to myself!$"
# 557 "data/maps/LilycoveCity/scripts.pory"

# 558 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DontGoNearCaveInCove:
# 559 "data/maps/LilycoveCity/scripts.pory"
	.string "Hey, you!\p"
# 560 "data/maps/LilycoveCity/scripts.pory"
	.string "Don't go near the cave in the cove!\p"
# 561 "data/maps/LilycoveCity/scripts.pory"
	.string "Why? You don't need a reason why!\n"
# 562 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm an adult, so you just listen to me!$"
# 563 "data/maps/LilycoveCity/scripts.pory"

# 564 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_IfWorldBecomesOurs:
# 565 "data/maps/LilycoveCity/scripts.pory"
	.string "If this whole wide world becomes ours,\n"
# 566 "data/maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA's, it will be a happier\l"
# 567 "data/maps/LilycoveCity/scripts.pory"
	.string "place for POKéMON, too.$"
# 568 "data/maps/LilycoveCity/scripts.pory"

# 569 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_WailmerLeapOutOfWater:
# 570 "data/maps/LilycoveCity/scripts.pory"
	.string "There! WAILMER!\n"
# 571 "data/maps/LilycoveCity/scripts.pory"
	.string "Leap out of the water now!$"
# 572 "data/maps/LilycoveCity/scripts.pory"

# 573 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_GetLostMessingUpTraining:
# 574 "data/maps/LilycoveCity/scripts.pory"
	.string "Hunh? What do you want?\p"
# 575 "data/maps/LilycoveCity/scripts.pory"
	.string "You're messing up our training,\n"
# 576 "data/maps/LilycoveCity/scripts.pory"
	.string "so can you, like, get lost?$"
# 577 "data/maps/LilycoveCity/scripts.pory"

# 578 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ContestHallInTown:
# 579 "data/maps/LilycoveCity/scripts.pory"
	.string "There's a POKéMON CONTEST HALL\n"
# 580 "data/maps/LilycoveCity/scripts.pory"
	.string "right in this here town. \p"
# 581 "data/maps/LilycoveCity/scripts.pory"
	.string "That means well-raised POKéMON will\n"
# 582 "data/maps/LilycoveCity/scripts.pory"
	.string "come from all over the country.\p"
# 583 "data/maps/LilycoveCity/scripts.pory"
	.string "My heart swells with excitement!$"
# 584 "data/maps/LilycoveCity/scripts.pory"

# 585 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_StrangeCaveInCove:
# 586 "data/maps/LilycoveCity/scripts.pory"
	.string "Have you seen that strange cave in\n"
# 587 "data/maps/LilycoveCity/scripts.pory"
	.string "the cove at the edge of town?$"
# 588 "data/maps/LilycoveCity/scripts.pory"

# 589 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_GoingToMoveDeleterForHMs:
# 590 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm going to teach my POKéMON some new\n"
# 591 "data/maps/LilycoveCity/scripts.pory"
	.string "moves for entering a CONTEST.\p"
# 592 "data/maps/LilycoveCity/scripts.pory"
	.string "So, I'm going to see the MOVE DELETER\n"
# 593 "data/maps/LilycoveCity/scripts.pory"
	.string "and make it forget HM moves.$"
# 594 "data/maps/LilycoveCity/scripts.pory"

# 595 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ImFromKanto:
# 596 "data/maps/LilycoveCity/scripts.pory"
	.string "I came from KANTO.\p"
# 597 "data/maps/LilycoveCity/scripts.pory"
	.string "The HOENN region is beautiful with\n"
# 598 "data/maps/LilycoveCity/scripts.pory"
	.string "all its water and verdant nature.\p"
# 599 "data/maps/LilycoveCity/scripts.pory"
	.string "Hunh? Wait a second…\p"
# 600 "data/maps/LilycoveCity/scripts.pory"
	.string "Could there be rare POKéMON that live\n"
# 601 "data/maps/LilycoveCity/scripts.pory"
	.string "only in this area?$"
# 602 "data/maps/LilycoveCity/scripts.pory"

# 603 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
# 604 "data/maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA's been training their\n"
# 605 "data/maps/LilycoveCity/scripts.pory"
	.string "WAILMER in the cove.\p"
# 606 "data/maps/LilycoveCity/scripts.pory"
	.string "We SAILORS can't get our boats out\n"
# 607 "data/maps/LilycoveCity/scripts.pory"
	.string "to sea with them in the way!$"
# 608 "data/maps/LilycoveCity/scripts.pory"

# 609 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SomeonePuntedTeamAquaOut:
# 610 "data/maps/LilycoveCity/scripts.pory"
	.string "Ahoy, did you know?\p"
# 611 "data/maps/LilycoveCity/scripts.pory"
	.string "Someone punted TEAM AQUA out of\n"
# 612 "data/maps/LilycoveCity/scripts.pory"
	.string "the way for us!\p"
# 613 "data/maps/LilycoveCity/scripts.pory"
	.string "That got the WAILMER out of the cove,\n"
# 614 "data/maps/LilycoveCity/scripts.pory"
	.string "so we can get our boats out again.$"
# 615 "data/maps/LilycoveCity/scripts.pory"

# 616 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SomeoneStoleMyPokemon:
# 617 "data/maps/LilycoveCity/scripts.pory"
	.string "I was taking a relaxing snooze at the\n"
# 618 "data/maps/LilycoveCity/scripts.pory"
	.string "seaside inn to the sound of waves…\p"
# 619 "data/maps/LilycoveCity/scripts.pory"
	.string "When someone stole my POKéMON!\p"
# 620 "data/maps/LilycoveCity/scripts.pory"
	.string "Who's the abductor?\n"
# 621 "data/maps/LilycoveCity/scripts.pory"
	.string "TEAM AQUA? Is it TEAM AQUA?$"
# 622 "data/maps/LilycoveCity/scripts.pory"

# 623 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MissingPokemonCameBack:
# 624 "data/maps/LilycoveCity/scripts.pory"
	.string "My missing POKéMON…\n"
# 625 "data/maps/LilycoveCity/scripts.pory"
	.string "It came back without me noticing!$"
# 626 "data/maps/LilycoveCity/scripts.pory"

# 627 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ImArtDealer:
# 628 "data/maps/LilycoveCity/scripts.pory"
	.string "I'm an ART DEALER.\p"
# 629 "data/maps/LilycoveCity/scripts.pory"
	.string "I am a buyer and seller of fine art,\n"
# 630 "data/maps/LilycoveCity/scripts.pory"
	.string "especially paintings.\p"
# 631 "data/maps/LilycoveCity/scripts.pory"
	.string "I've heard that the MUSEUM here has\n"
# 632 "data/maps/LilycoveCity/scripts.pory"
	.string "magnificent works on exhibit…$"
# 633 "data/maps/LilycoveCity/scripts.pory"

# 634 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SeaRemainsForeverYoung:
# 635 "data/maps/LilycoveCity/scripts.pory"
	.string "Even as we grow old and wrinkled,\n"
# 636 "data/maps/LilycoveCity/scripts.pory"
	.string "the sea remains forever young with\l"
# 637 "data/maps/LilycoveCity/scripts.pory"
	.string "the vivid brilliance of life…\p"
# 638 "data/maps/LilycoveCity/scripts.pory"
	.string "Fwohoho fwohohohoho…$"
# 639 "data/maps/LilycoveCity/scripts.pory"

# 640 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
# 641 "data/maps/LilycoveCity/scripts.pory"
	.string "It was sixty years ago that my husband\n"
# 642 "data/maps/LilycoveCity/scripts.pory"
	.string "proposed to me here.\l"
# 643 "data/maps/LilycoveCity/scripts.pory"
	.string "The sea remains as beautiful as ever.\p"
# 644 "data/maps/LilycoveCity/scripts.pory"
	.string "Mufufufu mufufufufufu…$"
# 645 "data/maps/LilycoveCity/scripts.pory"

# 646 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaRenovatedCavern:
# 647 "data/maps/LilycoveCity/scripts.pory"
	.string "Hm, you know of the peculiar cavern\n"
# 648 "data/maps/LilycoveCity/scripts.pory"
	.string "in this cove?\p"
# 649 "data/maps/LilycoveCity/scripts.pory"
	.string "That had been a natural formation,\n"
# 650 "data/maps/LilycoveCity/scripts.pory"
	.string "but then that TEAM AQUA lot came\l"
# 651 "data/maps/LilycoveCity/scripts.pory"
	.string "along and made their renovations.\p"
# 652 "data/maps/LilycoveCity/scripts.pory"
	.string "They call themselves\n"
# 653 "data/maps/LilycoveCity/scripts.pory"
	.string "the “nature-loving TEAM AQUA”!\p"
# 654 "data/maps/LilycoveCity/scripts.pory"
	.string "But what they do and what they say\n"
# 655 "data/maps/LilycoveCity/scripts.pory"
	.string "don't match at all!$"
# 656 "data/maps/LilycoveCity/scripts.pory"

# 657 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TeamAquaLotGoneForGood:
# 658 "data/maps/LilycoveCity/scripts.pory"
	.string "That cave in the cove…\p"
# 659 "data/maps/LilycoveCity/scripts.pory"
	.string "I didn't notice it right away,\n"
# 660 "data/maps/LilycoveCity/scripts.pory"
	.string "but it's completely empty now.\p"
# 661 "data/maps/LilycoveCity/scripts.pory"
	.string "That TEAM AQUA lot, they must\n"
# 662 "data/maps/LilycoveCity/scripts.pory"
	.string "have gone away for good.$"
# 663 "data/maps/LilycoveCity/scripts.pory"

# 664 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_CitySign:
# 665 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY\p"
# 666 "data/maps/LilycoveCity/scripts.pory"
	.string "“Where the land ends and the\n"
# 667 "data/maps/LilycoveCity/scripts.pory"
	.string "sea begins.”$"
# 668 "data/maps/LilycoveCity/scripts.pory"

# 669 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ContestHallSign:
# 670 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéMON CONTEST HALL\n"
# 671 "data/maps/LilycoveCity/scripts.pory"
	.string "“The gathering place for TRAINERS!”$"
# 672 "data/maps/LilycoveCity/scripts.pory"

# 673 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MotelSign:
# 674 "data/maps/LilycoveCity/scripts.pory"
	.string "COVE LILY MOTEL\p"
# 675 "data/maps/LilycoveCity/scripts.pory"
	.string "“Remember us as COVE LILY of\n"
# 676 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE.”$"
# 677 "data/maps/LilycoveCity/scripts.pory"

# 678 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MuseumSign:
# 679 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE MUSEUM\p"
# 680 "data/maps/LilycoveCity/scripts.pory"
	.string "“POKéMON Masterpiece Collection\n"
# 681 "data/maps/LilycoveCity/scripts.pory"
	.string "on exhibit!”$"
# 682 "data/maps/LilycoveCity/scripts.pory"

# 683 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MuseumSignPlayersExhibit:
# 684 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE MUSEUM\p"
# 685 "data/maps/LilycoveCity/scripts.pory"
	.string "“{PLAYER}'s POKéMON Collection\n"
# 686 "data/maps/LilycoveCity/scripts.pory"
	.string "on exhibit!”$"
# 687 "data/maps/LilycoveCity/scripts.pory"

# 688 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HarborSignUnderConstruction:
# 689 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY HARBOR\p"
# 690 "data/maps/LilycoveCity/scripts.pory"
	.string "“The ferry S.S. TIDAL is under\n"
# 691 "data/maps/LilycoveCity/scripts.pory"
	.string "construction in SLATEPORT CITY.\p"
# 692 "data/maps/LilycoveCity/scripts.pory"
	.string "“Service is scheduled to begin\n"
# 693 "data/maps/LilycoveCity/scripts.pory"
	.string "shortly.”$"
# 694 "data/maps/LilycoveCity/scripts.pory"

# 695 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HarborSign:
# 696 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE CITY HARBOR\p"
# 697 "data/maps/LilycoveCity/scripts.pory"
	.string "“Enjoy a delightful cruise on\n"
# 698 "data/maps/LilycoveCity/scripts.pory"
	.string "the ferry S.S. TIDAL.”$"
# 699 "data/maps/LilycoveCity/scripts.pory"

# 700 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_TrainerFanClubSign:
# 701 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéMON TRAINER FAN CLUB\p"
# 702 "data/maps/LilycoveCity/scripts.pory"
	.string "The names of TRAINERS are scribbled\n"
# 703 "data/maps/LilycoveCity/scripts.pory"
	.string "all over the sign…$"
# 704 "data/maps/LilycoveCity/scripts.pory"

# 705 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DepartmentStoreSign:
# 706 "data/maps/LilycoveCity/scripts.pory"
	.string "LILYCOVE DEPARTMENT STORE\p"
# 707 "data/maps/LilycoveCity/scripts.pory"
	.string "“Overflowing with great merchandise\n"
# 708 "data/maps/LilycoveCity/scripts.pory"
	.string "and excitement!\p"
# 709 "data/maps/LilycoveCity/scripts.pory"
	.string "“A great place to find that something\n"
# 710 "data/maps/LilycoveCity/scripts.pory"
	.string "you need!”$"
# 711 "data/maps/LilycoveCity/scripts.pory"

# 712 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_MoveDeletersHouseSign:
# 713 "data/maps/LilycoveCity/scripts.pory"
	.string "MOVE DELETER'S HOUSE\p"
# 714 "data/maps/LilycoveCity/scripts.pory"
	.string "“Unwanted POKéMON moves deleted.”$"
# 715 "data/maps/LilycoveCity/scripts.pory"

# 716 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_DoYouKnowAboutBerryBlender:
# 717 "data/maps/LilycoveCity/scripts.pory"
	.string "Do you know about the machine\n"
# 718 "data/maps/LilycoveCity/scripts.pory"
	.string "BERRY BLENDER?$"
# 719 "data/maps/LilycoveCity/scripts.pory"

# 720 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_FasterSpinBetterPokeblocks:
# 721 "data/maps/LilycoveCity/scripts.pory"
	.string "People have to work together to get it\n"
# 722 "data/maps/LilycoveCity/scripts.pory"
	.string "to spin faster.\p"
# 723 "data/maps/LilycoveCity/scripts.pory"
	.string "The faster you can make it spin, the\n"
# 724 "data/maps/LilycoveCity/scripts.pory"
	.string "better {POKEBLOCK}S you can get, I've heard.$"
# 725 "data/maps/LilycoveCity/scripts.pory"

# 726 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_ExplainBerryBlender:
# 727 "data/maps/LilycoveCity/scripts.pory"
	.string "It's used for making a kind of candy\n"
# 728 "data/maps/LilycoveCity/scripts.pory"
	.string "called a {POKEBLOCK}.\p"
# 729 "data/maps/LilycoveCity/scripts.pory"
	.string "If you give a good {POKEBLOCK} to a POKéMON,\n"
# 730 "data/maps/LilycoveCity/scripts.pory"
	.string "its condition will improve by a lot.$"
# 731 "data/maps/LilycoveCity/scripts.pory"

# 732 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HeardTowerCalledSkyPillar:
# 733 "data/maps/LilycoveCity/scripts.pory"
	.string "I heard there's a tower somewhere out\n"
# 734 "data/maps/LilycoveCity/scripts.pory"
	.string "on the sea routes.\p"
# 735 "data/maps/LilycoveCity/scripts.pory"
	.string "It's called the SKY PILLAR, I hear.$"
# 736 "data/maps/LilycoveCity/scripts.pory"

# 737 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_SawTallTowerOnRoute131:
# 738 "data/maps/LilycoveCity/scripts.pory"
	.string "I saw this tall tower somewhere\n"
# 739 "data/maps/LilycoveCity/scripts.pory"
	.string "around ROUTE 131.\p"
# 740 "data/maps/LilycoveCity/scripts.pory"
	.string "Could that possibly be…?$"
# 741 "data/maps/LilycoveCity/scripts.pory"

# 742 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_JustArrivedAndSawRarePokemon:
# 743 "data/maps/LilycoveCity/scripts.pory"
	.string "We just arrived here on our\n"
# 744 "data/maps/LilycoveCity/scripts.pory"
	.string "honeymoon vacation.\p"
# 745 "data/maps/LilycoveCity/scripts.pory"
	.string "We happened to see a DRAGON-type\n"
# 746 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéMON flying way up in the sky.\p"
# 747 "data/maps/LilycoveCity/scripts.pory"
	.string "Do cool POKéMON like that live in\n"
# 748 "data/maps/LilycoveCity/scripts.pory"
	.string "the HOENN region?$"
# 749 "data/maps/LilycoveCity/scripts.pory"

# 750 "data/maps/LilycoveCity/scripts.pory"
LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
# 751 "data/maps/LilycoveCity/scripts.pory"
	.string "On our honeymoon, we vowed to see as\n"
# 752 "data/maps/LilycoveCity/scripts.pory"
	.string "many rare POKéMON as we can.\p"
# 753 "data/maps/LilycoveCity/scripts.pory"
	.string "So we were delighted to see a rare\n"
# 754 "data/maps/LilycoveCity/scripts.pory"
	.string "POKéMON as soon as we arrived.\p"
# 755 "data/maps/LilycoveCity/scripts.pory"
	.string "I mean, we are totally happy!$"

GiftOldSeaMapScript::
# 760 "data/maps/LilycoveCity/scripts.pory"
	lock
# 761 "data/maps/LilycoveCity/scripts.pory"
	faceplayer
# 762 "data/maps/LilycoveCity/scripts.pory"
	goto_if_set FLAG_RECEIVED_OLD_SEA_MAP, GiftOldSeaMapScript_2
# 768 "data/maps/LilycoveCity/scripts.pory"
	msgbox GiftOldSeaMapScript_Text_1
# 771 "data/maps/LilycoveCity/scripts.pory"
	giveitem ITEM_OLD_SEA_MAP
# 772 "data/maps/LilycoveCity/scripts.pory"
	startquest QUEST_JIRACHI
# 773 "data/maps/LilycoveCity/scripts.pory"
	startquest QUEST_MEW
# 774 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_RECEIVED_OLD_SEA_MAP
# 775 "data/maps/LilycoveCity/scripts.pory"
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
# 776 "data/maps/LilycoveCity/scripts.pory"
	msgbox GiftOldSeaMapScript_Text_2
# 778 "data/maps/LilycoveCity/scripts.pory"
	release
	end

GiftOldSeaMapScript_2:
# 763 "data/maps/LilycoveCity/scripts.pory"
	msgbox GiftOldSeaMapScript_Text_0
# 765 "data/maps/LilycoveCity/scripts.pory"
	release
	end


GiftOldSeaMapScript_Text_0:
# 763 "data/maps/LilycoveCity/scripts.pory"
	.string "Faraway Island hides secrets beyond\n"
	.string "your wildest dreams.\n"
	.string "I hope you find them.$"

GiftOldSeaMapScript_Text_1:
# 768 "data/maps/LilycoveCity/scripts.pory"
	.string "Hmm.. You seem strong enough.\n"
	.string "I found this map in a bottle washed up\l"
	.string "on the beach.\l"
	.string "This map will surely guide you to an\l"
	.string "island far, far away.$"

GiftOldSeaMapScript_Text_2:
# 776 "data/maps/LilycoveCity/scripts.pory"
	.string "Present this map at the ferry in town.\n"
	.string "I wonder what you'll find.$"
