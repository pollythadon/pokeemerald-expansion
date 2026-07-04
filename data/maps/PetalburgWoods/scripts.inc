# 1 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_MapScripts::
# 2 "data/maps/PetalburgWoods/scripts.pory"
	.byte 0
# 3 "data/maps/PetalburgWoods/scripts.pory"

# 4 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherLeft::
# 5 "data/maps/PetalburgWoods/scripts.pory"
	lockall
# 6 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherIntro
# 7 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
# 8 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 9 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
# 10 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 11 "data/maps/PetalburgWoods/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 12 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
# 13 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 14 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
# 15 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 16 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
# 17 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 18 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 19 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 20 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
# 21 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 22 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
# 23 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 24 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
# 25 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 26 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
# 27 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 28 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
# 29 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
# 30 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
# 31 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 32 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
# 33 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
# 34 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
# 35 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 36 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
# 37 "data/maps/PetalburgWoods/scripts.pory"
	end
# 38 "data/maps/PetalburgWoods/scripts.pory"

# 39 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherRight::
# 40 "data/maps/PetalburgWoods/scripts.pory"
	lockall
# 41 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherIntro
# 42 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
# 43 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 44 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 45 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 46 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
# 47 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 48 "data/maps/PetalburgWoods/scripts.pory"
	playbgm MUS_ENCOUNTER_AQUA, FALSE
# 49 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
# 50 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 51 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
# 52 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 53 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
# 54 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 55 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
# 56 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 57 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
# 58 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 59 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
# 60 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 61 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
# 62 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 63 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 64 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
# 65 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
# 66 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
# 67 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 68 "data/maps/PetalburgWoods/scripts.pory"
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
# 69 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
# 70 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
# 71 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 72 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
# 73 "data/maps/PetalburgWoods/scripts.pory"
	end
# 74 "data/maps/PetalburgWoods/scripts.pory"

# 75 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherIntro::
# 76 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
# 77 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 78 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
# 79 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 80 "data/maps/PetalburgWoods/scripts.pory"
	return
# 81 "data/maps/PetalburgWoods/scripts.pory"

# 82 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherPostBattle::
# 83 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
# 84 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 85 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaRunAway
# 86 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 87 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_PETALBURG_WOODS_GRUNT
# 88 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 89 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 90 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
# 91 "data/maps/PetalburgWoods/scripts.pory"
	giveitem ITEM_GREAT_BALL
# 92 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
# 93 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_DevonResearcherFinish
# 94 "data/maps/PetalburgWoods/scripts.pory"
	end
# 95 "data/maps/PetalburgWoods/scripts.pory"

# 96 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_BagFull::
# 97 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
# 98 "data/maps/PetalburgWoods/scripts.pory"
	goto PetalburgWoods_EventScript_DevonResearcherFinish
# 99 "data/maps/PetalburgWoods/scripts.pory"
	end
# 100 "data/maps/PetalburgWoods/scripts.pory"

# 101 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_DevonResearcherFinish::
# 102 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
# 103 "data/maps/PetalburgWoods/scripts.pory"
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
# 104 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 105 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
# 106 "data/maps/PetalburgWoods/scripts.pory"
	closemessage
# 107 "data/maps/PetalburgWoods/scripts.pory"
	return
# 108 "data/maps/PetalburgWoods/scripts.pory"

# 109 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RemoveDevonResearcher::
# 110 "data/maps/PetalburgWoods/scripts.pory"
	removeobject LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE
# 111 "data/maps/PetalburgWoods/scripts.pory"
	setvar VAR_PETALBURG_WOODS_STATE, 1
# 112 "data/maps/PetalburgWoods/scripts.pory"
	releaseall
# 113 "data/maps/PetalburgWoods/scripts.pory"
	end
# 114 "data/maps/PetalburgWoods/scripts.pory"

# 115 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherLookAround:
# 116 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 117 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 118 "data/maps/PetalburgWoods/scripts.pory"
	delay_4
# 119 "data/maps/PetalburgWoods/scripts.pory"
	face_right
# 120 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 121 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 122 "data/maps/PetalburgWoods/scripts.pory"
	face_left
# 123 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 124 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 125 "data/maps/PetalburgWoods/scripts.pory"
	face_down
# 126 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 127 "data/maps/PetalburgWoods/scripts.pory"
	face_right
# 128 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 129 "data/maps/PetalburgWoods/scripts.pory"
	delay_8
# 130 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 131 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 132 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 133 "data/maps/PetalburgWoods/scripts.pory"

# 134 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherExitLeft:
# 135 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 136 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 137 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 138 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 139 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 140 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 141 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 142 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 143 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 144 "data/maps/PetalburgWoods/scripts.pory"

# 145 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
# 146 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 147 "data/maps/PetalburgWoods/scripts.pory"
	face_player
# 148 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 149 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 150 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 151 "data/maps/PetalburgWoods/scripts.pory"

# 152 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
# 153 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 154 "data/maps/PetalburgWoods/scripts.pory"
	face_player
# 155 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 156 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 157 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 158 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_right
# 159 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 160 "data/maps/PetalburgWoods/scripts.pory"

# 161 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherExitRight:
# 162 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_left
# 163 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 164 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 165 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 166 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 167 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 168 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 169 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 170 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 171 "data/maps/PetalburgWoods/scripts.pory"

# 172 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_WatchResearcherLeave:
# 173 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 174 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 175 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
# 176 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 177 "data/maps/PetalburgWoods/scripts.pory"

# 178 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
# 179 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 180 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 181 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 182 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_left
# 183 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
# 184 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 185 "data/maps/PetalburgWoods/scripts.pory"

# 186 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
# 187 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 188 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_right
# 189 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_up
# 190 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 191 "data/maps/PetalburgWoods/scripts.pory"

# 192 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_DevonResearcherStartExit:
# 193 "data/maps/PetalburgWoods/scripts.pory"
	walk_in_place_faster_down
# 194 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 195 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 196 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 197 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 198 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 199 "data/maps/PetalburgWoods/scripts.pory"
	face_up
# 200 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 201 "data/maps/PetalburgWoods/scripts.pory"

# 202 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachResearcherLeft:
# 203 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 204 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 205 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 206 "data/maps/PetalburgWoods/scripts.pory"

# 207 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaBackOff:
# 208 "data/maps/PetalburgWoods/scripts.pory"
	lock_facing_direction
# 209 "data/maps/PetalburgWoods/scripts.pory"
	walk_up
# 210 "data/maps/PetalburgWoods/scripts.pory"
	unlock_facing_direction
# 211 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 212 "data/maps/PetalburgWoods/scripts.pory"

# 213 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaRunAway:
# 214 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 215 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 216 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 217 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 218 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_up
# 219 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 220 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 221 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 222 "data/maps/PetalburgWoods/scripts.pory"

# 223 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachResearcherRight:
# 224 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 225 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 226 "data/maps/PetalburgWoods/scripts.pory"
	walk_fast_down
# 227 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 228 "data/maps/PetalburgWoods/scripts.pory"

# 229 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaEntrance:
# 230 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 231 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 232 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 233 "data/maps/PetalburgWoods/scripts.pory"
	delay_16
# 234 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 235 "data/maps/PetalburgWoods/scripts.pory"

# 236 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Movement_AquaApproachPlayer:
# 237 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 238 "data/maps/PetalburgWoods/scripts.pory"
	step_end
# 239 "data/maps/PetalburgWoods/scripts.pory"

# 240 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Boy1::
# 241 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
# 242 "data/maps/PetalburgWoods/scripts.pory"
	end
# 243 "data/maps/PetalburgWoods/scripts.pory"

# 244 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Boy2::
# 245 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
# 246 "data/maps/PetalburgWoods/scripts.pory"
	end
# 247 "data/maps/PetalburgWoods/scripts.pory"

# 248 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Girl::
# 249 "data/maps/PetalburgWoods/scripts.pory"
	lock
# 250 "data/maps/PetalburgWoods/scripts.pory"
	faceplayer
# 251 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
# 252 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
# 253 "data/maps/PetalburgWoods/scripts.pory"
	giveitem ITEM_MIRACLE_SEED
# 254 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
# 255 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_RECEIVED_MIRACLE_SEED
# 256 "data/maps/PetalburgWoods/scripts.pory"
	release
# 257 "data/maps/PetalburgWoods/scripts.pory"
	end
# 258 "data/maps/PetalburgWoods/scripts.pory"

# 259 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_ExplainMiracleSeed::
# 260 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
# 261 "data/maps/PetalburgWoods/scripts.pory"
	release
# 262 "data/maps/PetalburgWoods/scripts.pory"
	end
# 263 "data/maps/PetalburgWoods/scripts.pory"

# 264 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Sign1::
# 265 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
# 266 "data/maps/PetalburgWoods/scripts.pory"
	end
# 267 "data/maps/PetalburgWoods/scripts.pory"

# 268 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Sign2::
# 269 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
# 270 "data/maps/PetalburgWoods/scripts.pory"
	end
# 271 "data/maps/PetalburgWoods/scripts.pory"

# 272 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_Lyle::
# 273 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
# 274 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
# 275 "data/maps/PetalburgWoods/scripts.pory"
	end
# 276 "data/maps/PetalburgWoods/scripts.pory"

# 277 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_James::
# 278 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
# 279 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 280 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
# 281 "data/maps/PetalburgWoods/scripts.pory"
	setvar VAR_0x8004, TRAINER_JAMES_1
# 282 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, IsTrainerRegistered
# 283 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
# 284 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
# 285 "data/maps/PetalburgWoods/scripts.pory"
	release
# 286 "data/maps/PetalburgWoods/scripts.pory"
	end
# 287 "data/maps/PetalburgWoods/scripts.pory"

# 288 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TryRegisterJames::
# 289 "data/maps/PetalburgWoods/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 290 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 291 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
# 292 "data/maps/PetalburgWoods/scripts.pory"
	release
# 293 "data/maps/PetalburgWoods/scripts.pory"
	end
# 294 "data/maps/PetalburgWoods/scripts.pory"

# 295 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RegisterJames::
# 296 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
# 297 "data/maps/PetalburgWoods/scripts.pory"
	register_matchcall TRAINER_JAMES_1
# 298 "data/maps/PetalburgWoods/scripts.pory"
	release
# 299 "data/maps/PetalburgWoods/scripts.pory"
	end
# 300 "data/maps/PetalburgWoods/scripts.pory"

# 301 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_TryRegisterJames2::
# 302 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
# 303 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
# 304 "data/maps/PetalburgWoods/scripts.pory"
	release
# 305 "data/maps/PetalburgWoods/scripts.pory"
	end
# 306 "data/maps/PetalburgWoods/scripts.pory"

# 307 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_RegisterJames2::
# 308 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
# 309 "data/maps/PetalburgWoods/scripts.pory"
	register_matchcall TRAINER_JAMES_1
# 310 "data/maps/PetalburgWoods/scripts.pory"
	release
# 311 "data/maps/PetalburgWoods/scripts.pory"
	end
# 312 "data/maps/PetalburgWoods/scripts.pory"

# 313 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_EventScript_JamesRematch::
# 314 "data/maps/PetalburgWoods/scripts.pory"
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
# 315 "data/maps/PetalburgWoods/scripts.pory"
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
# 316 "data/maps/PetalburgWoods/scripts.pory"
	end
# 317 "data/maps/PetalburgWoods/scripts.pory"

# 318 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_NotAOneToBeFound:
# 319 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hmmm…\n"
# 320 "data/maps/PetalburgWoods/scripts.pory"
	.string "Not a one to be found…$"
# 321 "data/maps/PetalburgWoods/scripts.pory"

# 322 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HaveYouSeenShroomish:
# 323 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hello, have you seen any POKéMON\n"
# 324 "data/maps/PetalburgWoods/scripts.pory"
	.string "called SHROOMISH around here?\p"
# 325 "data/maps/PetalburgWoods/scripts.pory"
	.string "I really love that POKéMON.$"
# 326 "data/maps/PetalburgWoods/scripts.pory"

# 327 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWasGoingToAmbushYou:
# 328 "data/maps/PetalburgWoods/scripts.pory"
	.string "I was going to ambush you, but you\n"
# 329 "data/maps/PetalburgWoods/scripts.pory"
	.string "had to dawdle in PETALBURG WOODS\l"
# 330 "data/maps/PetalburgWoods/scripts.pory"
	.string "forever, didn't you?\p"
# 331 "data/maps/PetalburgWoods/scripts.pory"
	.string "I got sick of waiting, so here I am!$"
# 332 "data/maps/PetalburgWoods/scripts.pory"

# 333 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HandOverThosePapers:
# 334 "data/maps/PetalburgWoods/scripts.pory"
	.string "You! DEVON RESEARCHER!\p"
# 335 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hand over those papers!$"
# 336 "data/maps/PetalburgWoods/scripts.pory"

# 337 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YouHaveToHelpMe:
# 338 "data/maps/PetalburgWoods/scripts.pory"
	.string "Aiyeeeh!\p"
# 339 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're a POKéMON TRAINER, aren't you?\n"
# 340 "data/maps/PetalburgWoods/scripts.pory"
	.string "You've got to help me, please!$"
# 341 "data/maps/PetalburgWoods/scripts.pory"

# 342 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_NoOneCrossesTeamAqua:
# 343 "data/maps/PetalburgWoods/scripts.pory"
	.string "Hunh? What do you think you're doing?\n"
# 344 "data/maps/PetalburgWoods/scripts.pory"
	.string "What, you're going to protect him?\p"
# 345 "data/maps/PetalburgWoods/scripts.pory"
	.string "No one who crosses TEAM AQUA\n"
# 346 "data/maps/PetalburgWoods/scripts.pory"
	.string "gets any mercy, not even a kid!\p"
# 347 "data/maps/PetalburgWoods/scripts.pory"
	.string "Come on and battle me!$"
# 348 "data/maps/PetalburgWoods/scripts.pory"

# 349 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YoureKiddingMe:
# 350 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're kidding me! You're tough!$"
# 351 "data/maps/PetalburgWoods/scripts.pory"

# 352 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YouveGotSomeNerve:
# 353 "data/maps/PetalburgWoods/scripts.pory"
	.string "Grrr… You've got some nerve\n"
# 354 "data/maps/PetalburgWoods/scripts.pory"
	.string "meddling with TEAM AQUA!\l"
# 355 "data/maps/PetalburgWoods/scripts.pory"
	.string "Come on and battle me again!\p"
# 356 "data/maps/PetalburgWoods/scripts.pory"
	.string "I wish I could say that, but I'm out of\n"
# 357 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON…\p"
# 358 "data/maps/PetalburgWoods/scripts.pory"
	.string "And, hey, we of TEAM AQUA are also\n"
# 359 "data/maps/PetalburgWoods/scripts.pory"
	.string "after something in RUSTBORO.\p"
# 360 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'll let you go today!$"
# 361 "data/maps/PetalburgWoods/scripts.pory"

# 362 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ThatWasAwfullyClose:
# 363 "data/maps/PetalburgWoods/scripts.pory"
	.string "Whew…\n"
# 364 "data/maps/PetalburgWoods/scripts.pory"
	.string "That was awfully close!\p"
# 365 "data/maps/PetalburgWoods/scripts.pory"
	.string "Thanks to you, he didn't rob me of\n"
# 366 "data/maps/PetalburgWoods/scripts.pory"
	.string "these important papers.\p"
# 367 "data/maps/PetalburgWoods/scripts.pory"
	.string "I know, I'll give you a GREAT BALL as\n"
# 368 "data/maps/PetalburgWoods/scripts.pory"
	.string "my thanks!$"
# 369 "data/maps/PetalburgWoods/scripts.pory"

# 370 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
# 371 "data/maps/PetalburgWoods/scripts.pory"
	.string "Didn't that TEAM AQUA thug say\n"
# 372 "data/maps/PetalburgWoods/scripts.pory"
	.string "they were after something in\l"
# 373 "data/maps/PetalburgWoods/scripts.pory"
	.string "RUSTBORO, too?$"
# 374 "data/maps/PetalburgWoods/scripts.pory"

# 375 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ICantBeWastingTime:
# 376 "data/maps/PetalburgWoods/scripts.pory"
	.string "Uh-oh! It's a crisis!\n"
# 377 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be wasting time!$"
# 378 "data/maps/PetalburgWoods/scripts.pory"

# 379 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_YoureLoadedWithItems:
# 380 "data/maps/PetalburgWoods/scripts.pory"
	.string "You're loaded with items.\n"
# 381 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't give you this GREAT BALL.$"
# 382 "data/maps/PetalburgWoods/scripts.pory"

# 383 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_GoBugPokemonTeam:
# 384 "data/maps/PetalburgWoods/scripts.pory"
	.string "I caught a whole bunch of POKéMON!\p"
# 385 "data/maps/PetalburgWoods/scripts.pory"
	.string "Go, go, go!\n"
# 386 "data/maps/PetalburgWoods/scripts.pory"
	.string "My BUG POKéMON team!$"
# 387 "data/maps/PetalburgWoods/scripts.pory"

# 388 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ICouldntWin:
# 389 "data/maps/PetalburgWoods/scripts.pory"
	.string "I have all these POKéMON,\n"
# 390 "data/maps/PetalburgWoods/scripts.pory"
	.string "but I couldn't win…$"
# 391 "data/maps/PetalburgWoods/scripts.pory"

# 392 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_ImOutOfPokeBalls:
# 393 "data/maps/PetalburgWoods/scripts.pory"
	.string "I caught a bunch of POKéMON.\n"
# 394 "data/maps/PetalburgWoods/scripts.pory"
	.string "Now I'm out of POKé BALLS.$"
# 395 "data/maps/PetalburgWoods/scripts.pory"

# 396 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
# 397 "data/maps/PetalburgWoods/scripts.pory"
	.string "If you take BUG POKéMON to school,\n"
# 398 "data/maps/PetalburgWoods/scripts.pory"
	.string "you get to be instantly popular!$"
# 399 "data/maps/PetalburgWoods/scripts.pory"

# 400 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_CantBePopularIfILose:
# 401 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be popular if I lose.$"
# 402 "data/maps/PetalburgWoods/scripts.pory"

# 403 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_PeopleRespectYou:
# 404 "data/maps/PetalburgWoods/scripts.pory"
	.string "If you have a big BUG POKéMON,\n"
# 405 "data/maps/PetalburgWoods/scripts.pory"
	.string "people respect you for it.$"
# 406 "data/maps/PetalburgWoods/scripts.pory"

# 407 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWantRematch1:
# 408 "data/maps/PetalburgWoods/scripts.pory"
	.string "I want a rematch when my BUG\n"
# 409 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON grow up!\p"
# 410 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'm registering you in my POKéNAV!$"
# 411 "data/maps/PetalburgWoods/scripts.pory"

# 412 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IWantRematch2:
# 413 "data/maps/PetalburgWoods/scripts.pory"
	.string "I want a rematch when my BUG \n"
# 414 "data/maps/PetalburgWoods/scripts.pory"
	.string "POKéMON grow up!\p"
# 415 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'm registering you in my POKéNAV!$"
# 416 "data/maps/PetalburgWoods/scripts.pory"

# 417 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_MyPokemonHaveGrown:
# 418 "data/maps/PetalburgWoods/scripts.pory"
	.string "My BUG POKéMON have grown.\n"
# 419 "data/maps/PetalburgWoods/scripts.pory"
	.string "I'll be popular again.$"
# 420 "data/maps/PetalburgWoods/scripts.pory"

# 421 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_CantBePopularIfLose:
# 422 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can't be popular if I lose.$"
# 423 "data/maps/PetalburgWoods/scripts.pory"

# 424 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_IveBeenTrainingHard:
# 425 "data/maps/PetalburgWoods/scripts.pory"
	.string "You get to be popular if you have\n"
# 426 "data/maps/PetalburgWoods/scripts.pory"
	.string "strong POKéMON, right?\l"
# 427 "data/maps/PetalburgWoods/scripts.pory"
	.string "So, I've been training hard.$"
# 428 "data/maps/PetalburgWoods/scripts.pory"

# 429 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_StayOutOfTallGrass:
# 430 "data/maps/PetalburgWoods/scripts.pory"
	.string "Yo, there!\n"
# 431 "data/maps/PetalburgWoods/scripts.pory"
	.string "Your POKéMON doing okay?\p"
# 432 "data/maps/PetalburgWoods/scripts.pory"
	.string "If your POKéMON are weak and you want\n"
# 433 "data/maps/PetalburgWoods/scripts.pory"
	.string "to avoid battles, you should stay out\l"
# 434 "data/maps/PetalburgWoods/scripts.pory"
	.string "of tall grass.$"
# 435 "data/maps/PetalburgWoods/scripts.pory"

# 436 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_HiddenItemsExplanation:
# 437 "data/maps/PetalburgWoods/scripts.pory"
	.string "Sometimes, there are things on the\n"
# 438 "data/maps/PetalburgWoods/scripts.pory"
	.string "ground even if you can't see them.\p"
# 439 "data/maps/PetalburgWoods/scripts.pory"
	.string "That's why I always check where I'm\n"
# 440 "data/maps/PetalburgWoods/scripts.pory"
	.string "walking.$"
# 441 "data/maps/PetalburgWoods/scripts.pory"

# 442 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TryUsingThisItem:
# 443 "data/maps/PetalburgWoods/scripts.pory"
	.string "Oh, neat!\n"
# 444 "data/maps/PetalburgWoods/scripts.pory"
	.string "That's the BADGE from RUSTBORO GYM!\p"
# 445 "data/maps/PetalburgWoods/scripts.pory"
	.string "You must be a TRAINER.\n"
# 446 "data/maps/PetalburgWoods/scripts.pory"
	.string "You should try using this item.$"
# 447 "data/maps/PetalburgWoods/scripts.pory"

# 448 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_MiracleSeedExplanation:
# 449 "data/maps/PetalburgWoods/scripts.pory"
	.string "It's a MIRACLE SEED.\n"
# 450 "data/maps/PetalburgWoods/scripts.pory"
	.string "If a POKéMON holds that item, its\l"
# 451 "data/maps/PetalburgWoods/scripts.pory"
	.string "GRASS-type moves become stronger.\p"
# 452 "data/maps/PetalburgWoods/scripts.pory"
	.string "Besides MIRACLE SEED, I think there are\n"
# 453 "data/maps/PetalburgWoods/scripts.pory"
	.string "other convenient items for POKéMON\l"
# 454 "data/maps/PetalburgWoods/scripts.pory"
	.string "to hold.$"
# 455 "data/maps/PetalburgWoods/scripts.pory"

# 456 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TrainerTipsExperience:
# 457 "data/maps/PetalburgWoods/scripts.pory"
	.string "TRAINER TIPS\p"
# 458 "data/maps/PetalburgWoods/scripts.pory"
	.string "Any POKéMON that appears even once\n"
# 459 "data/maps/PetalburgWoods/scripts.pory"
	.string "in a battle is awarded EXP Points.\p"
# 460 "data/maps/PetalburgWoods/scripts.pory"
	.string "To raise a weak POKéMON, put it at the\n"
# 461 "data/maps/PetalburgWoods/scripts.pory"
	.string "left of the team list.\p"
# 462 "data/maps/PetalburgWoods/scripts.pory"
	.string "As soon as a battle starts, switch it\n"
# 463 "data/maps/PetalburgWoods/scripts.pory"
	.string "out. It will earn EXP Points without\l"
# 464 "data/maps/PetalburgWoods/scripts.pory"
	.string "being exposed to any harm.$"
# 465 "data/maps/PetalburgWoods/scripts.pory"

# 466 "data/maps/PetalburgWoods/scripts.pory"
PetalburgWoods_Text_TrainerTipsPP:
# 467 "data/maps/PetalburgWoods/scripts.pory"
	.string "TRAINER TIPS\p"
# 468 "data/maps/PetalburgWoods/scripts.pory"
	.string "In addition to Hit Points (HP), POKéMON\n"
# 469 "data/maps/PetalburgWoods/scripts.pory"
	.string "have Power Points (PP) that are used to\l"
# 470 "data/maps/PetalburgWoods/scripts.pory"
	.string "make moves during battle.\p"
# 471 "data/maps/PetalburgWoods/scripts.pory"
	.string "If a POKéMON runs out of PP, it must be\n"
# 472 "data/maps/PetalburgWoods/scripts.pory"
	.string "taken to a POKéMON CENTER.$"

Legendary_EventScript_CELEBI::
# 477 "data/maps/PetalburgWoods/scripts.pory"
	lockall
# 478 "data/maps/PetalburgWoods/scripts.pory"
	goto_if_set FLAG_CELEBI_DFTD, Legendary_EventScript_CELEBI_2
	checkitem ITEM_TEA
# 0 "data/maps/PetalburgWoods/scripts.pory"
	compare VAR_RESULT, 0
	goto_if_ne Legendary_EventScript_CELEBI_5
Legendary_EventScript_CELEBI_4:
# 529 "data/maps/PetalburgWoods/scripts.pory"
	msgbox Legendary_EventScript_CELEBI_Text_6
# 530 "data/maps/PetalburgWoods/scripts.pory"
	releaseall
	end

Legendary_EventScript_CELEBI_2:
# 479 "data/maps/PetalburgWoods/scripts.pory"
	msgbox Legendary_EventScript_CELEBI_Text_0
# 480 "data/maps/PetalburgWoods/scripts.pory"
	releaseall
	end

Legendary_EventScript_CELEBI_5:
# 484 "data/maps/PetalburgWoods/scripts.pory"
	msgbox Legendary_EventScript_CELEBI_Text_1
# 485 "data/maps/PetalburgWoods/scripts.pory"
	msgbox Legendary_EventScript_CELEBI_Text_2, MSGBOX_YESNO
# 486 "data/maps/PetalburgWoods/scripts.pory"
	switch VAR_RESULT
# 487 "data/maps/PetalburgWoods/scripts.pory"
	case YES, Legendary_EventScript_CELEBI_8
# 523 "data/maps/PetalburgWoods/scripts.pory"
	case NO, Legendary_EventScript_CELEBI_9
	goto Legendary_EventScript_CELEBI_4

Legendary_EventScript_CELEBI_8:
# 488 "data/maps/PetalburgWoods/scripts.pory"
	clearflag FLAG_CELEBI_BATTLE
# 489 "data/maps/PetalburgWoods/scripts.pory"
	addobject 14
# 490 "data/maps/PetalburgWoods/scripts.pory"
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
# 491 "data/maps/PetalburgWoods/scripts.pory"
	fadescreenswapbuffers FADE_TO_WHITE
# 492 "data/maps/PetalburgWoods/scripts.pory"
	delay 20
# 493 "data/maps/PetalburgWoods/scripts.pory"
	fadescreenswapbuffers FADE_FROM_WHITE
# 494 "data/maps/PetalburgWoods/scripts.pory"
	msgbox Legendary_EventScript_CELEBI_Text_3
# 495 "data/maps/PetalburgWoods/scripts.pory"
	applymovement 14, Celebi_Descend
# 496 "data/maps/PetalburgWoods/scripts.pory"
	waitmovement 0
# 497 "data/maps/PetalburgWoods/scripts.pory"
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
# 498 "data/maps/PetalburgWoods/scripts.pory"
	fadescreenswapbuffers FADE_TO_WHITE
# 499 "data/maps/PetalburgWoods/scripts.pory"
	delay 20
# 500 "data/maps/PetalburgWoods/scripts.pory"
	fadescreenswapbuffers FADE_FROM_WHITE
# 501 "data/maps/PetalburgWoods/scripts.pory"
	msgbox Legendary_EventScript_CELEBI_Text_4, MSGBOX_AUTOCLOSE
# 502 "data/maps/PetalburgWoods/scripts.pory"
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
# 503 "data/maps/PetalburgWoods/scripts.pory"
	delay 40
# 504 "data/maps/PetalburgWoods/scripts.pory"
	waitmoncry
# 505 "data/maps/PetalburgWoods/scripts.pory"
	setwildbattle SPECIES_CELEBI, 65
# 506 "data/maps/PetalburgWoods/scripts.pory"
	special BattleSetup_StartLegendaryBattle
# 507 "data/maps/PetalburgWoods/scripts.pory"
	waitstate
# 508 "data/maps/PetalburgWoods/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 509 "data/maps/PetalburgWoods/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq Legendary_EventScript_CELEBI_11
# 512 "data/maps/PetalburgWoods/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Legendary_EventScript_CELEBI_12
# 515 "data/maps/PetalburgWoods/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Legendary_EventScript_CELEBI_13
# 518 "data/maps/PetalburgWoods/scripts.pory"
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Legendary_EventScript_CELEBI_14
Legendary_EventScript_CELEBI_10:
# 521 "data/maps/PetalburgWoods/scripts.pory"
	releaseall
	end

Legendary_EventScript_CELEBI_9:
# 524 "data/maps/PetalburgWoods/scripts.pory"
	msgbox Legendary_EventScript_CELEBI_Text_5
# 525 "data/maps/PetalburgWoods/scripts.pory"
	releaseall
	end

Legendary_EventScript_CELEBI_11:
# 510 "data/maps/PetalburgWoods/scripts.pory"
	call CELEBIWon_or_Caught
	goto Legendary_EventScript_CELEBI_10

Legendary_EventScript_CELEBI_12:
# 513 "data/maps/PetalburgWoods/scripts.pory"
	call CELEBIWon_or_Caught
	goto Legendary_EventScript_CELEBI_10

Legendary_EventScript_CELEBI_13:
# 516 "data/maps/PetalburgWoods/scripts.pory"
	call CELEBIRanAway
	goto Legendary_EventScript_CELEBI_10

Legendary_EventScript_CELEBI_14:
# 519 "data/maps/PetalburgWoods/scripts.pory"
	call CELEBIRanAway
	goto Legendary_EventScript_CELEBI_10


CELEBIWon_or_Caught::
# 535 "data/maps/PetalburgWoods/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 536 "data/maps/PetalburgWoods/scripts.pory"
	removeobject 14
# 537 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_CELEBI_BATTLE
# 538 "data/maps/PetalburgWoods/scripts.pory"
	setflag FLAG_CELEBI_DFTD
# 539 "data/maps/PetalburgWoods/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 540 "data/maps/PetalburgWoods/scripts.pory"
	msgbox CELEBIWon_or_Caught_Text_0
	return


CELEBIRanAway::
# 545 "data/maps/PetalburgWoods/scripts.pory"
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
# 546 "data/maps/PetalburgWoods/scripts.pory"
	delay 20
# 547 "data/maps/PetalburgWoods/scripts.pory"
	fadescreenswapbuffers FADE_TO_BLACK
# 548 "data/maps/PetalburgWoods/scripts.pory"
	removeobject 14
# 549 "data/maps/PetalburgWoods/scripts.pory"
	fadescreenswapbuffers FADE_FROM_BLACK
# 550 "data/maps/PetalburgWoods/scripts.pory"
	msgbox CELEBIWon_or_Caught_Text_0
	return


# 554 "data/maps/PetalburgWoods/scripts.pory"
Celebi_Descend:
# 555 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 555 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 555 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 555 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 555 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 555 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 555 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 555 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 555 "data/maps/PetalburgWoods/scripts.pory"
	walk_down
# 556 "data/maps/PetalburgWoods/scripts.pory"
	face_player
	step_end

Legendary_EventScript_CELEBI_Text_0:
# 479 "data/maps/PetalburgWoods/scripts.pory"
	.string "Time flows through the forest, but I\n"
	.string "feel like something is missing...$"

Legendary_EventScript_CELEBI_Text_1:
# 484 "data/maps/PetalburgWoods/scripts.pory"
	.string "This is a nice spot for a tea break.$"

Legendary_EventScript_CELEBI_Text_2:
# 485 "data/maps/PetalburgWoods/scripts.pory"
	.string "Place the tea?$"

Legendary_EventScript_CELEBI_Text_3:
# 494 "data/maps/PetalburgWoods/scripts.pory"
	.string "The vibe of the forest has changed...$"

Legendary_EventScript_CELEBI_Text_4:
# 501 "data/maps/PetalburgWoods/scripts.pory"
	.string "I can see the past!!! The future!!! All\n"
	.string "at once!!$"

Legendary_EventScript_CELEBI_Text_5:
# 524 "data/maps/PetalburgWoods/scripts.pory"
	.string "Might need it for later..$"

Legendary_EventScript_CELEBI_Text_6:
# 529 "data/maps/PetalburgWoods/scripts.pory"
	.string "Something feels special about this\n"
	.string "spot...$"

CELEBIWon_or_Caught_Text_0:
# 540 "data/maps/PetalburgWoods/scripts.pory"
	.string "The things I saw... A family... Best I\n"
	.string "move on.$"
