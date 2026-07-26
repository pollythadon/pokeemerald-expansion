# 1 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_MapScripts::
# 2 "data/maps/PetalburgWoods/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgWoods_OnTransition
# 3 "data/maps/PetalburgWoods/scripts.pory"
	.byte 0
# 4 "data/maps/PetalburgWoods/scripts.pory"

# 5 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_OnTransition:
# 6 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_BUDEW_ACCEPTED, PetalburgWoods_EventScript_TransitionDone
# 7 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_BUDEW_HIDE
# 8 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TransitionDone:
# 9 "data/maps/PetalburgWoods/scripts.pory"
	end
# 10 "data/maps/PetalburgWoods/scripts.pory"

# 11 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherLeft::
# 12 "data/maps/PetalburgWoods/scripts.pory"
	lockall
# 13 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherIntro
# 14 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
# 15 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 16 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
# 17 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 18 "data/maps/PetalburgWoods/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 19 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
# 20 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 21 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
# 22 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 23 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
# 24 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 25 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 26 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 27 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
# 28 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 29 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
# 30 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 31 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
# 32 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 33 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
# 34 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 35 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
# 36 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
# 37 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
# 38 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 39 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
# 40 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
# 41 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
# 42 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 43 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
# 44 "data/maps/PetalburgWoods/scripts.pory"
	end
# 45 "data/maps/PetalburgWoods/scripts.pory"

# 46 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherRight::
# 47 "data/maps/PetalburgWoods/scripts.pory"
	lockall
# 48 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherIntro
# 49 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
# 50 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 51 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 52 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 53 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
# 54 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 55 "data/maps/PetalburgWoods/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 56 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
# 57 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 58 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
# 59 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 60 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
# 61 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 62 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 63 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 64 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
# 65 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 66 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
# 67 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 68 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
# 69 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 70 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 71 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
# 72 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
# 73 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
# 74 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 75 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
# 76 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
# 77 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
# 78 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 79 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
# 80 "data/maps/PetalburgWoods/scripts.pory"
	end
# 81 "data/maps/PetalburgWoods/scripts.pory"

# 82 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherIntro::
# 83 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
# 84 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 85 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
# 86 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 87 "data/maps/PetalburgWoods/scripts.pory"
	return
# 88 "data/maps/PetalburgWoods/scripts.pory"

# 89 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherPostBattle::
# 90 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
# 91 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 92 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaRunAway
# 93 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 94 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_PETALBURG_WOODS_GRUNT
# 95 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 96 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 97 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
# 98 "data/maps/PetalburgWoods/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 99 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
# 100 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_DevonResearcherFinish
# 101 "data/maps/PetalburgWoods/scripts.pory"
	end
# 102 "data/maps/PetalburgWoods/scripts.pory"

# 103 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_BagFull::
# 104 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
# 105 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_DevonResearcherFinish
# 106 "data/maps/PetalburgWoods/scripts.pory"
	end
# 107 "data/maps/PetalburgWoods/scripts.pory"

# 108 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherFinish::
# 109 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
# 110 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
# 111 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 112 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
# 113 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 114 "data/maps/PetalburgWoods/scripts.pory"
	return
# 115 "data/maps/PetalburgWoods/scripts.pory"

# 116 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RemoveDevonResearcher::
# 117 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE
# 118 "data/maps/PetalburgWoods/scripts.pory"
	setvar VAR_PETALBURG_WOODS_STATE, 1
# 119 "data/maps/PetalburgWoods/scripts.pory"
	releaseall
# 120 "data/maps/PetalburgWoods/scripts.pory"
	end
# 121 "data/maps/PetalburgWoods/scripts.pory"

# 122 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherLookAround:
# 123 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 124 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 125 "data/maps/PetalburgWoods/scripts.pory"
	delay_4
# 126 "data/maps/PetalburgWoods/scripts.pory"
	face_right
# 127 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 128 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 129 "data/maps/PetalburgWoods/scripts.pory"
	face_left
# 130 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 131 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 132 "data/maps/PetalburgWoods/scripts.pory"
	face_down
# 133 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 134 "data/maps/PetalburgWoods/scripts.pory"
	face_right
# 135 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 136 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 137 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 138 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 139 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 140 "data/maps/PetalburgWoods/scripts.pory"

# 141 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherExitLeft:
# 142 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 143 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 144 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 145 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 146 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 147 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 148 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 149 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 150 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 151 "data/maps/PetalburgWoods/scripts.pory"

# 152 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
# 153 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 154 "data/maps/PetalburgWoods/scripts.pory"
	face_player
# 155 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 156 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 157 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 158 "data/maps/PetalburgWoods/scripts.pory"

# 159 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
# 160 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 161 "data/maps/PetalburgWoods/scripts.pory"
	face_player
# 162 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 163 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 164 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 165 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_right
# 166 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 167 "data/maps/PetalburgWoods/scripts.pory"

# 168 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherExitRight:
# 169 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_left
# 170 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 171 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 172 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 173 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 174 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 175 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 176 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 177 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 178 "data/maps/PetalburgWoods/scripts.pory"

# 179 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_WatchResearcherLeave:
# 180 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 181 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 182 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
# 183 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 184 "data/maps/PetalburgWoods/scripts.pory"

# 185 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
# 186 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 187 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 188 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 189 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_left
# 190 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
# 191 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 192 "data/maps/PetalburgWoods/scripts.pory"

# 193 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
# 194 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 195 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 196 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
# 197 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 198 "data/maps/PetalburgWoods/scripts.pory"

# 199 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherStartExit:
# 200 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
# 201 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 202 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 203 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 204 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 205 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 206 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 207 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 208 "data/maps/PetalburgWoods/scripts.pory"

# 209 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachResearcherLeft:
# 210 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 211 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 212 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 213 "data/maps/PetalburgWoods/scripts.pory"

# 214 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaBackOff:
# 215 "data/maps/PetalburgWoods/scripts.pory"
	lock_facing_direction
# 216 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 217 "data/maps/PetalburgWoods/scripts.pory"
	unlock_facing_direction
# 218 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 219 "data/maps/PetalburgWoods/scripts.pory"

# 220 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaRunAway:
# 221 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 222 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 223 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 224 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 225 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 226 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 227 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 228 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 229 "data/maps/PetalburgWoods/scripts.pory"

# 230 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachResearcherRight:
# 231 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 232 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 233 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 234 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 235 "data/maps/PetalburgWoods/scripts.pory"

# 236 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaEntrance:
# 237 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 238 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 239 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 240 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 241 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 242 "data/maps/PetalburgWoods/scripts.pory"

# 243 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachPlayer:
# 244 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 245 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 246 "data/maps/PetalburgWoods/scripts.pory"

# 247 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Boy1::
# 248 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
# 249 "data/maps/PetalburgWoods/scripts.pory"
	end
# 250 "data/maps/PetalburgWoods/scripts.pory"

# 251 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Boy2::
# 252 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
# 253 "data/maps/PetalburgWoods/scripts.pory"
	end
# 254 "data/maps/PetalburgWoods/scripts.pory"

# 255 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Girl::
# 256 "data/maps/PetalburgWoods/scripts.pory"
	lock
# 257 "data/maps/PetalburgWoods/scripts.pory"
	faceplayer
# 258 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
# 259 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
# 260 "data/maps/PetalburgWoods/scripts.pory"
	giveitem ITEM_MIRACLE_SEED
# 261 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 262 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_RECEIVED_MIRACLE_SEED
# 263 "data/maps/PetalburgWoods/scripts.pory"
	release
# 264 "data/maps/PetalburgWoods/scripts.pory"
	end
# 265 "data/maps/PetalburgWoods/scripts.pory"

# 266 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_ExplainMiracleSeed::
# 267 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
# 268 "data/maps/PetalburgWoods/scripts.pory"
	release
# 269 "data/maps/PetalburgWoods/scripts.pory"
	end
# 270 "data/maps/PetalburgWoods/scripts.pory"

# 271 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Sign1::
# 272 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
# 273 "data/maps/PetalburgWoods/scripts.pory"
	end
# 274 "data/maps/PetalburgWoods/scripts.pory"

# 275 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Sign2::
# 276 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
# 277 "data/maps/PetalburgWoods/scripts.pory"
	end
# 278 "data/maps/PetalburgWoods/scripts.pory"

# 279 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Lyle::
# 280 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
# 281 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
# 282 "data/maps/PetalburgWoods/scripts.pory"
	end
# 283 "data/maps/PetalburgWoods/scripts.pory"

# 284 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_James::
# 285 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
# 286 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 287 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
# 288 "data/maps/PetalburgWoods/scripts.pory"
	setvar VAR_0x8004, TRAINER_JAMES_1
# 289 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 290 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
# 291 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
# 292 "data/maps/PetalburgWoods/scripts.pory"
	release
# 293 "data/maps/PetalburgWoods/scripts.pory"
	end
# 294 "data/maps/PetalburgWoods/scripts.pory"

# 295 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TryRegisterJames::
# 296 "data/maps/PetalburgWoods/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 297 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 298 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
# 299 "data/maps/PetalburgWoods/scripts.pory"
	release
# 300 "data/maps/PetalburgWoods/scripts.pory"
	end
# 301 "data/maps/PetalburgWoods/scripts.pory"

# 302 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RegisterJames::
# 303 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
# 304 "data/maps/PetalburgWoods/scripts.pory"
	register_matchcall TRAINER_JAMES_1
# 305 "data/maps/PetalburgWoods/scripts.pory"
	release
# 306 "data/maps/PetalburgWoods/scripts.pory"
	end
# 307 "data/maps/PetalburgWoods/scripts.pory"

# 308 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TryRegisterJames2::
# 309 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
# 310 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
# 311 "data/maps/PetalburgWoods/scripts.pory"
	release
# 312 "data/maps/PetalburgWoods/scripts.pory"
	end
# 313 "data/maps/PetalburgWoods/scripts.pory"

# 314 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RegisterJames2::
# 315 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
# 316 "data/maps/PetalburgWoods/scripts.pory"
	register_matchcall TRAINER_JAMES_1
# 317 "data/maps/PetalburgWoods/scripts.pory"
	release
# 318 "data/maps/PetalburgWoods/scripts.pory"
	end
# 319 "data/maps/PetalburgWoods/scripts.pory"

# 320 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_JamesRematch::
# 321 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
# 322 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
# 323 "data/maps/PetalburgWoods/scripts.pory"
	end
# 324 "data/maps/PetalburgWoods/scripts.pory"

# 325 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_NotAOneToBeFound:
# 326 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hmmm…\n"
# 327 "data/maps/PetalburgWoods/scripts.pory"
	.string "Not a one to be found…$"
# 328 "data/maps/PetalburgWoods/scripts.pory"

# 329 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HaveYouSeenShroomish:
# 330 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hello, have you seen any POKéMON\n"
# 331 "data/maps/PetalburgWoods/scripts.pory"
	.string "called SHROOMISH around here?\p"
# 332 "data/maps/PetalburgWoods/scripts.pory"
	.string "I really love that POKéMON.$"
# 333 "data/maps/PetalburgWoods/scripts.pory"

# 334 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWasGoingToAmbushYou:
# 335 "data/maps/PetalburgWoods/scripts.pory"
	.string "I was going to ambush you, but you\n"
# 336 "data/maps/PetalburgWoods/scripts.pory"
	.string "had to dawdle in PETALBURG WOODS\l"
# 337 "data/maps/PetalburgWoods/scripts.pory"
	.string "forever, didn't you?\p"
# 338 "data/maps/PetalburgWoods/scripts.pory"
	.string "I got sick of waiting, so here I am!$"
# 339 "data/maps/PetalburgWoods/scripts.pory"

# 340 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HandOverThosePapers:
# 341 "data/maps/PetalburgWoods/scripts.pory"
	.string "You! DEVON RESEARCHER!\p"
# 342 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hand over those papers!$"
# 343 "data/maps/PetalburgWoods/scripts.pory"

# 344 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YouHaveToHelpMe:
# 345 "data/maps/PetalburgWoods/scripts.pory"
	.string "Aiyeeeh!\p"
# 346 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're a POKéMON TRAINER, aren't you?\n"
# 347 "data/maps/PetalburgWoods/scripts.pory"
	.string "You've got to help me, please!$"
# 348 "data/maps/PetalburgWoods/scripts.pory"

# 349 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_NoOneCrossesTeamAqua:
# 350 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hunh? What do you think you're doing?\n"
# 351 "data/maps/PetalburgWoods/scripts.pory"
	.string "What, you're going to protect him?\p"
# 352 "data/maps/PetalburgWoods/scripts.pory"
	.string "No one who crosses TEAM AQUA\n"
# 353 "data/maps/PetalburgWoods/scripts.pory"
	.string "gets any mercy, not even a kid!\p"
# 354 "data/maps/PetalburgWoods/scripts.pory"
	.string "Come on and battle me!$"
# 355 "data/maps/PetalburgWoods/scripts.pory"

# 356 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YoureKiddingMe:
# 357 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're kidding me! You're tough!$"
# 358 "data/maps/PetalburgWoods/scripts.pory"

# 359 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YouveGotSomeNerve:
# 360 "data/maps/PetalburgWoods/scripts.pory"
	.string "Grrr… You've got some nerve\n"
# 361 "data/maps/PetalburgWoods/scripts.pory"
	.string "meddling with TEAM AQUA!\l"
# 362 "data/maps/PetalburgWoods/scripts.pory"
	.string "Come on and battle me again!\p"
# 363 "data/maps/PetalburgWoods/scripts.pory"
	.string "I wish I could say that, but I'm out of\n"
# 364 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON…\p"
# 365 "data/maps/PetalburgWoods/scripts.pory"
	.string "And, hey, we of TEAM AQUA are also\n"
# 366 "data/maps/PetalburgWoods/scripts.pory"
	.string "after something in RUSTBORO.\p"
# 367 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'll let you go today!$"
# 368 "data/maps/PetalburgWoods/scripts.pory"

# 369 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ThatWasAwfullyClose:
# 370 "data/maps/PetalburgWoods/scripts.pory"
	.string "Whew…\n"
# 371 "data/maps/PetalburgWoods/scripts.pory"
	.string "That was awfully close!\p"
# 372 "data/maps/PetalburgWoods/scripts.pory"
	.string "Thanks to you, he didn't rob me of\n"
# 373 "data/maps/PetalburgWoods/scripts.pory"
	.string "these important papers.\p"
# 374 "data/maps/PetalburgWoods/scripts.pory"
	.string "I know, I'll give you a GREAT BALL as\n"
# 375 "data/maps/PetalburgWoods/scripts.pory"
	.string "my thanks!$"
# 376 "data/maps/PetalburgWoods/scripts.pory"

# 377 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
# 378 "data/maps/PetalburgWoods/scripts.pory"
	.string "Didn't that TEAM AQUA thug say\n"
# 379 "data/maps/PetalburgWoods/scripts.pory"
	.string "they were after something in\l"
# 380 "data/maps/PetalburgWoods/scripts.pory"
	.string "RUSTBORO, too?$"
# 381 "data/maps/PetalburgWoods/scripts.pory"

# 382 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ICantBeWastingTime:
# 383 "data/maps/PetalburgWoods/scripts.pory"
	.string "Uh-oh! It's a crisis!\n"
# 384 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be wasting time!$"
# 385 "data/maps/PetalburgWoods/scripts.pory"

# 386 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YoureLoadedWithItems:
# 387 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're loaded with items.\n"
# 388 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't give you this GREAT BALL.$"
# 389 "data/maps/PetalburgWoods/scripts.pory"

# 390 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_GoBugPokemonTeam:
# 391 "data/maps/PetalburgWoods/scripts.pory"
	.string "I caught a whole bunch of POKéMON!\p"
# 392 "data/maps/PetalburgWoods/scripts.pory"
	.string "Go, go, go!\n"
# 393 "data/maps/PetalburgWoods/scripts.pory"
	.string "My BUG POKéMON team!$"
# 394 "data/maps/PetalburgWoods/scripts.pory"

# 395 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ICouldntWin:
# 396 "data/maps/PetalburgWoods/scripts.pory"
	.string "I have all these POKéMON,\n"
# 397 "data/maps/PetalburgWoods/scripts.pory"
	.string "but I couldn't win…$"
# 398 "data/maps/PetalburgWoods/scripts.pory"

# 399 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ImOutOfPokeBalls:
# 400 "data/maps/PetalburgWoods/scripts.pory"
	.string "I caught a bunch of POKéMON.\n"
# 401 "data/maps/PetalburgWoods/scripts.pory"
	.string "Now I'm out of POKé BALLS.$"
# 402 "data/maps/PetalburgWoods/scripts.pory"

# 403 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
# 404 "data/maps/PetalburgWoods/scripts.pory"
	.string "If you take BUG POKéMON to school,\n"
# 405 "data/maps/PetalburgWoods/scripts.pory"
	.string "you get to be instantly popular!$"
# 406 "data/maps/PetalburgWoods/scripts.pory"

# 407 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_CantBePopularIfILose:
# 408 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be popular if I lose.$"
# 409 "data/maps/PetalburgWoods/scripts.pory"

# 410 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_PeopleRespectYou:
# 411 "data/maps/PetalburgWoods/scripts.pory"
	.string "If you have a big BUG POKéMON,\n"
# 412 "data/maps/PetalburgWoods/scripts.pory"
	.string "people respect you for it.$"
# 413 "data/maps/PetalburgWoods/scripts.pory"

# 414 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWantRematch1:
# 415 "data/maps/PetalburgWoods/scripts.pory"
	.string "I want a rematch when my BUG\n"
# 416 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON grow up!\p"
# 417 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'm registering you in my POKéNAV!$"
# 418 "data/maps/PetalburgWoods/scripts.pory"

# 419 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWantRematch2:
# 420 "data/maps/PetalburgWoods/scripts.pory"
	.string "I want a rematch when my BUG \n"
# 421 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON grow up!\p"
# 422 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'm registering you in my POKéNAV!$"
# 423 "data/maps/PetalburgWoods/scripts.pory"

# 424 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_MyPokemonHaveGrown:
# 425 "data/maps/PetalburgWoods/scripts.pory"
	.string "My BUG POKéMON have grown.\n"
# 426 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'll be popular again.$"
# 427 "data/maps/PetalburgWoods/scripts.pory"

# 428 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_CantBePopularIfLose:
# 429 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be popular if I lose.$"
# 430 "data/maps/PetalburgWoods/scripts.pory"

# 431 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IveBeenTrainingHard:
# 432 "data/maps/PetalburgWoods/scripts.pory"
	.string "You get to be popular if you have\n"
# 433 "data/maps/PetalburgWoods/scripts.pory"
	.string "strong POKéMON, right?\l"
# 434 "data/maps/PetalburgWoods/scripts.pory"
	.string "So, I've been training hard.$"
# 435 "data/maps/PetalburgWoods/scripts.pory"

# 436 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_StayOutOfTallGrass:
# 437 "data/maps/PetalburgWoods/scripts.pory"
	.string "Yo, there!\n"
# 438 "data/maps/PetalburgWoods/scripts.pory"
	.string "Your POKéMON doing okay?\p"
# 439 "data/maps/PetalburgWoods/scripts.pory"
	.string "If your POKéMON are weak and you want\n"
# 440 "data/maps/PetalburgWoods/scripts.pory"
	.string "to avoid battles, you should stay out\l"
# 441 "data/maps/PetalburgWoods/scripts.pory"
	.string "of tall grass.$"
# 442 "data/maps/PetalburgWoods/scripts.pory"

# 443 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HiddenItemsExplanation:
# 444 "data/maps/PetalburgWoods/scripts.pory"
	.string "Sometimes, there are things on the\n"
# 445 "data/maps/PetalburgWoods/scripts.pory"
	.string "ground even if you can't see them.\p"
# 446 "data/maps/PetalburgWoods/scripts.pory"
	.string "That's why I always check where I'm\n"
# 447 "data/maps/PetalburgWoods/scripts.pory"
	.string "walking.$"
# 448 "data/maps/PetalburgWoods/scripts.pory"

# 449 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TryUsingThisItem:
# 450 "data/maps/PetalburgWoods/scripts.pory"
	.string "Oh, neat!\n"
# 451 "data/maps/PetalburgWoods/scripts.pory"
	.string "That's the BADGE from RUSTBORO GYM!\p"
# 452 "data/maps/PetalburgWoods/scripts.pory"
	.string "You must be a TRAINER.\n"
# 453 "data/maps/PetalburgWoods/scripts.pory"
	.string "You should try using this item.$"
# 454 "data/maps/PetalburgWoods/scripts.pory"

# 455 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_MiracleSeedExplanation:
# 456 "data/maps/PetalburgWoods/scripts.pory"
	.string "It's a MIRACLE SEED.\n"
# 457 "data/maps/PetalburgWoods/scripts.pory"
	.string "If a POKéMON holds that item, its\l"
# 458 "data/maps/PetalburgWoods/scripts.pory"
	.string "GRASS-type moves become stronger.\p"
# 459 "data/maps/PetalburgWoods/scripts.pory"
	.string "Besides MIRACLE SEED, I think there are\n"
# 460 "data/maps/PetalburgWoods/scripts.pory"
	.string "other convenient items for POKéMON\l"
# 461 "data/maps/PetalburgWoods/scripts.pory"
	.string "to hold.$"
# 462 "data/maps/PetalburgWoods/scripts.pory"

# 463 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TrainerTipsExperience:
# 464 "data/maps/PetalburgWoods/scripts.pory"
	.string "TRAINER TIPS\p"
# 465 "data/maps/PetalburgWoods/scripts.pory"
	.string "Any POKéMON that appears even once\n"
# 466 "data/maps/PetalburgWoods/scripts.pory"
	.string "in a battle is awarded EXP Points.\p"
# 467 "data/maps/PetalburgWoods/scripts.pory"
	.string "To raise a weak POKéMON, put it at the\n"
# 468 "data/maps/PetalburgWoods/scripts.pory"
	.string "left of the team list.\p"
# 469 "data/maps/PetalburgWoods/scripts.pory"
	.string "As soon as a battle starts, switch it\n"
# 470 "data/maps/PetalburgWoods/scripts.pory"
	.string "out. It will earn EXP Points without\l"
# 471 "data/maps/PetalburgWoods/scripts.pory"
	.string "being exposed to any harm.$"
# 472 "data/maps/PetalburgWoods/scripts.pory"

# 473 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TrainerTipsPP:
# 474 "data/maps/PetalburgWoods/scripts.pory"
	.string "TRAINER TIPS\p"
# 475 "data/maps/PetalburgWoods/scripts.pory"
	.string "In addition to Hit Points (HP), POKéMON\n"
# 476 "data/maps/PetalburgWoods/scripts.pory"
	.string "have Power Points (PP) that are used to\l"
# 477 "data/maps/PetalburgWoods/scripts.pory"
	.string "make moves during battle.\p"
# 478 "data/maps/PetalburgWoods/scripts.pory"
	.string "If a POKéMON runs out of PP, it must be\n"
# 479 "data/maps/PetalburgWoods/scripts.pory"
	.string "taken to a POKéMON CENTER.$"

Legendary_EventScript_CELEBI::
# 484 "data/maps/PetalburgWoods/scripts.pory"
	lockall
# 485 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_CELEBI_DFTD, Legendary_EventScript_CELEBI_2
	checkitem ITEM_TEA
# 0 "data/maps/PetalburgWoods/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Legendary_EventScript_CELEBI_5
Legendary_EventScript_CELEBI_4:
# 536 "data/maps/PetalburgWoods/scripts.pory"
	msgbox Legendary_EventScript_CELEBI_Text_6
# 537 "data/maps/PetalburgWoods/scripts.pory"
	releaseall
	end

Legendary_EventScript_CELEBI_2:
# 486 "data/maps/PetalburgWoods/scripts.pory"
	msgbox Legendary_EventScript_CELEBI_Text_0
# 487 "data/maps/PetalburgWoods/scripts.pory"
	releaseall
	end

Legendary_EventScript_CELEBI_5:
# 491 "data/maps/PetalburgWoods/scripts.pory"
	msgbox Legendary_EventScript_CELEBI_Text_1
# 492 "data/maps/PetalburgWoods/scripts.pory"
	msgbox Legendary_EventScript_CELEBI_Text_2, MSGBOX_YESNO
# 493 "data/maps/PetalburgWoods/scripts.pory"
	switch VAR_RESULT
# 494 "data/maps/PetalburgWoods/scripts.pory"
	case YES, Legendary_EventScript_CELEBI_8
# 530 "data/maps/PetalburgWoods/scripts.pory"
	case NO, Legendary_EventScript_CELEBI_9
	goto Legendary_EventScript_CELEBI_4

Legendary_EventScript_CELEBI_8:
# 495 "data/maps/PetalburgWoods/scripts.pory"
	clearflag FLAG_CELEBI_BATTLE
# 496 "data/maps/PetalburgWoods/scripts.pory"
	addobject 14
# 497 "data/maps/PetalburgWoods/scripts.pory"
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
# 498 "data/maps/PetalburgWoods/scripts.pory"
	fadescreenswapbuffers FADE_TO_WHITE
# 499 "data/maps/PetalburgWoods/scripts.pory"
	delay 20
# 500 "data/maps/PetalburgWoods/scripts.pory"
	fadescreenswapbuffers FADE_FROM_WHITE
# 501 "data/maps/PetalburgWoods/scripts.pory"
	msgbox Legendary_EventScript_CELEBI_Text_3
# 502 "data/maps/PetalburgWoods/scripts.pory"
	applymovement 14, Celebi_Descend
# 503 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 504 "data/maps/PetalburgWoods/scripts.pory"
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
# 505 "data/maps/PetalburgWoods/scripts.pory"
	fadescreenswapbuffers FADE_TO_WHITE
# 506 "data/maps/PetalburgWoods/scripts.pory"
	delay 20
# 507 "data/maps/PetalburgWoods/scripts.pory"
	fadescreenswapbuffers FADE_FROM_WHITE
# 508 "data/maps/PetalburgWoods/scripts.pory"
	msgbox Legendary_EventScript_CELEBI_Text_4, MSGBOX_AUTOCLOSE
# 509 "data/maps/PetalburgWoods/scripts.pory"
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
# 510 "data/maps/PetalburgWoods/scripts.pory"
	delay 40
# 511 "data/maps/PetalburgWoods/scripts.pory"
	waitmoncry
# 512 "data/maps/PetalburgWoods/scripts.pory"
	setwildbattle SPECIES_CELEBI, 65
# 513 "data/maps/PetalburgWoods/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 514 "data/maps/PetalburgWoods/scripts.pory"
	waitstate
# 515 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 516 "data/maps/PetalburgWoods/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Legendary_EventScript_CELEBI_11
# 519 "data/maps/PetalburgWoods/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Legendary_EventScript_CELEBI_12
# 522 "data/maps/PetalburgWoods/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Legendary_EventScript_CELEBI_13
# 525 "data/maps/PetalburgWoods/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Legendary_EventScript_CELEBI_14
Legendary_EventScript_CELEBI_10:
# 528 "data/maps/PetalburgWoods/scripts.pory"
	releaseall
	end

Legendary_EventScript_CELEBI_9:
# 531 "data/maps/PetalburgWoods/scripts.pory"
	msgbox Legendary_EventScript_CELEBI_Text_5
# 532 "data/maps/PetalburgWoods/scripts.pory"
	releaseall
	end

Legendary_EventScript_CELEBI_11:
# 517 "data/maps/PetalburgWoods/scripts.pory"
	call CELEBIWon_or_Caught
	goto Legendary_EventScript_CELEBI_10

Legendary_EventScript_CELEBI_12:
# 520 "data/maps/PetalburgWoods/scripts.pory"
	call CELEBIWon_or_Caught
	goto Legendary_EventScript_CELEBI_10

Legendary_EventScript_CELEBI_13:
# 523 "data/maps/PetalburgWoods/scripts.pory"
	call CELEBIRanAway
	goto Legendary_EventScript_CELEBI_10

Legendary_EventScript_CELEBI_14:
# 526 "data/maps/PetalburgWoods/scripts.pory"
	call CELEBIRanAway
	goto Legendary_EventScript_CELEBI_10


CELEBIWon_or_Caught::
# 542 "data/maps/PetalburgWoods/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 543 "data/maps/PetalburgWoods/scripts.pory"
	removeobject 14
# 544 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_CELEBI_BATTLE
# 545 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_CELEBI_DFTD
# 546 "data/maps/PetalburgWoods/scripts.pory"
	completequest QUEST_CELEBI
# 547 "data/maps/PetalburgWoods/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 548 "data/maps/PetalburgWoods/scripts.pory"
	msgbox CELEBIWon_or_Caught_Text_0
	return


CELEBIRanAway::
# 553 "data/maps/PetalburgWoods/scripts.pory"
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
# 554 "data/maps/PetalburgWoods/scripts.pory"
	delay 20
# 555 "data/maps/PetalburgWoods/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 556 "data/maps/PetalburgWoods/scripts.pory"
	hideobjectat 14, MAP_PETALBURG_WOODS
# 557 "data/maps/PetalburgWoods/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 558 "data/maps/PetalburgWoods/scripts.pory"
	msgbox CELEBIWon_or_Caught_Text_0
	return


# 562 "data/maps/PetalburgWoods/scripts.pory"
Celebi_Descend:
# 563 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 563 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 563 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 563 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 563 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 563 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 563 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 563 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 563 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 564 "data/maps/PetalburgWoods/scripts.pory"
	face_player
	step_end

PetalburgWoods_EventScript_ShinyBudew::
# 572 "data/maps/PetalburgWoods/scripts.pory"
	lock
# 573 "data/maps/PetalburgWoods/scripts.pory"
	faceplayer
# 574 "data/maps/PetalburgWoods/scripts.pory"
	setwildbattle SPECIES_BUDEW, 5
# 575 "data/maps/PetalburgWoods/scripts.pory"
	special ForceScriptedWildShiny
# 576 "data/maps/PetalburgWoods/scripts.pory"
	waitse
# 577 "data/maps/PetalburgWoods/scripts.pory"
	playmoncry SPECIES_BUDEW, CRY_MODE_ENCOUNTER
# 578 "data/maps/PetalburgWoods/scripts.pory"
	delay 40
# 579 "data/maps/PetalburgWoods/scripts.pory"
	waitmoncry
# 580 "data/maps/PetalburgWoods/scripts.pory"
	dowildbattle
# 581 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 582 "data/maps/PetalburgWoods/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq PetalburgWoods_EventScript_ShinyBudew_2
# 588 "data/maps/PetalburgWoods/scripts.pory"
	hideobjectat LOCALID_PETALBURG_WOODS_SHINY_BUDEW, MAP_PETALBURG_WOODS
PetalburgWoods_EventScript_ShinyBudew_1:
# 590 "data/maps/PetalburgWoods/scripts.pory"
	release
	end

PetalburgWoods_EventScript_ShinyBudew_2:
# 583 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_BUDEW_CAUGHT
# 584 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_PETALBURG_WOODS_SHINY_BUDEW
# 585 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_EventScript_ShinyBudew_Text_0
	goto PetalburgWoods_EventScript_ShinyBudew_1


Legendary_EventScript_CELEBI_Text_0:
# 486 "data/maps/PetalburgWoods/scripts.pory"
	.string "Time flows through the forest, but I\n"
	.string "feel like something is missing...$"

Legendary_EventScript_CELEBI_Text_1:
# 491 "data/maps/PetalburgWoods/scripts.pory"
	.string "This is a nice spot for a tea break.$"

Legendary_EventScript_CELEBI_Text_2:
# 492 "data/maps/PetalburgWoods/scripts.pory"
	.string "Place the tea?$"

Legendary_EventScript_CELEBI_Text_3:
# 501 "data/maps/PetalburgWoods/scripts.pory"
	.string "The vibe of the forest has changed...$"

Legendary_EventScript_CELEBI_Text_4:
# 508 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can see the past!!! The future!!! All\n"
	.string "at once!!$"

Legendary_EventScript_CELEBI_Text_5:
# 531 "data/maps/PetalburgWoods/scripts.pory"
	.string "Might need it for later..$"

Legendary_EventScript_CELEBI_Text_6:
# 536 "data/maps/PetalburgWoods/scripts.pory"
	.string "Something feels special about this\n"
	.string "spot...$"

CELEBIWon_or_Caught_Text_0:
# 548 "data/maps/PetalburgWoods/scripts.pory"
	.string "The things I saw... A family... Best I\n"
	.string "move on.$"

PetalburgWoods_EventScript_ShinyBudew_Text_0:
# 585 "data/maps/PetalburgWoods/scripts.pory"
	.string "The shining Budew was caught!\p"
	.string "The flower-shop girl back on Route 104\n"
	.string "will want to see this.$"
