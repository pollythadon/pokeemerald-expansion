# 1 "data/maps/JaggedPass/scripts.pory"
JaggedPass_MapScripts::
# 2 "data/maps/JaggedPass/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
# 3 "data/maps/JaggedPass/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
# 4 "data/maps/JaggedPass/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
# 5 "data/maps/JaggedPass/scripts.pory"
	.byte 0
# 6 "data/maps/JaggedPass/scripts.pory"

# 7 "data/maps/JaggedPass/scripts.pory"
JaggedPass_OnResume:
# 8 "data/maps/JaggedPass/scripts.pory"
	setstepcallback STEP_CB_ASH
# 9 "data/maps/JaggedPass/scripts.pory"
	call_if_eq VAR_JAGGED_PASS_STATE, 0, JaggedPass_EventScript_CheckHasMagmaEmblem
# 10 "data/maps/JaggedPass/scripts.pory"
	call_if_eq VAR_HEATRAN_CAVE_STATE, 0, JaggedPass_EventScript_CheckHasHeatranite
# 11 "data/maps/JaggedPass/scripts.pory"
	end
# 12 "data/maps/JaggedPass/scripts.pory"

# 13 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_CheckHasMagmaEmblem::
# 14 "data/maps/JaggedPass/scripts.pory"
	checkitem ITEM_MAGMA_EMBLEM
# 15 "data/maps/JaggedPass/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
# 16 "data/maps/JaggedPass/scripts.pory"
	return
# 17 "data/maps/JaggedPass/scripts.pory"

# 18 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_SetReadyToOpenHideout::
# 19 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_JAGGED_PASS_STATE, 1
# 20 "data/maps/JaggedPass/scripts.pory"
	return
# 21 "data/maps/JaggedPass/scripts.pory"

# 22 "data/maps/JaggedPass/scripts.pory"
JaggedPass_OnTransition:
# 23 "data/maps/JaggedPass/scripts.pory"
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
# 24 "data/maps/JaggedPass/scripts.pory"
	end
# 25 "data/maps/JaggedPass/scripts.pory"

# 26 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_SetWeatherAsh::
# 27 "data/maps/JaggedPass/scripts.pory"
	setweather WEATHER_VOLCANIC_ASH
# 28 "data/maps/JaggedPass/scripts.pory"
	doweather
# 29 "data/maps/JaggedPass/scripts.pory"
	return
# 30 "data/maps/JaggedPass/scripts.pory"

# 31 "data/maps/JaggedPass/scripts.pory"
JaggedPass_OnLoad:
# 32 "data/maps/JaggedPass/scripts.pory"
	call_if_le VAR_JAGGED_PASS_STATE, 1, JaggedPass_EventScript_ConcealHideoutEntrance
# 33 "data/maps/JaggedPass/scripts.pory"
	call_if_le VAR_HEATRAN_CAVE_STATE, 1, JaggedPass_EventScript_ConcealHeatranCave
# 34 "data/maps/JaggedPass/scripts.pory"
	end
# 35 "data/maps/JaggedPass/scripts.pory"

# 36 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_ConcealHideoutEntrance::
# 37 "data/maps/JaggedPass/scripts.pory"
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
# 38 "data/maps/JaggedPass/scripts.pory"
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
# 39 "data/maps/JaggedPass/scripts.pory"
	return
# 40 "data/maps/JaggedPass/scripts.pory"

# 41 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_OpenMagmaHideout::
# 42 "data/maps/JaggedPass/scripts.pory"
	lockall
# 43 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 44 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 45 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 46 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 47 "data/maps/JaggedPass/scripts.pory"
	special ShakeCamera
# 48 "data/maps/JaggedPass/scripts.pory"
	waitstate
# 49 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
# 50 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 51 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8004, 1   @ vertical pan
# 52 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8005, 1   @ horizontal pan
# 53 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8006, 16  @ num shakes
# 54 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8007, 3   @ shake delay
# 55 "data/maps/JaggedPass/scripts.pory"
	special ShakeCamera
# 56 "data/maps/JaggedPass/scripts.pory"
	waitstate
# 57 "data/maps/JaggedPass/scripts.pory"
	playse SE_EFFECTIVE
# 58 "data/maps/JaggedPass/scripts.pory"
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
# 59 "data/maps/JaggedPass/scripts.pory"
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
# 60 "data/maps/JaggedPass/scripts.pory"
	special DrawWholeMapView
# 61 "data/maps/JaggedPass/scripts.pory"
	delay 30
# 62 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_JAGGED_PASS_STATE, 2
# 63 "data/maps/JaggedPass/scripts.pory"
	waitse
# 64 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 65 "data/maps/JaggedPass/scripts.pory"
	end
# 66 "data/maps/JaggedPass/scripts.pory"

# 67 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_MagmaHideoutGuard::
# 68 "data/maps/JaggedPass/scripts.pory"
	lockall
# 69 "data/maps/JaggedPass/scripts.pory"
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
# 70 "data/maps/JaggedPass/scripts.pory"
	waitse
# 71 "data/maps/JaggedPass/scripts.pory"
	playse SE_PIN
# 72 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_ExclamationMark
# 73 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 74 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_Delay48
# 75 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 76 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
# 77 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 78 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
# 79 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 80 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
# 81 "data/maps/JaggedPass/scripts.pory"
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
# 82 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
# 83 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 84 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 85 "data/maps/JaggedPass/scripts.pory"
	end
# 86 "data/maps/JaggedPass/scripts.pory"

# 87 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_GuardDefeated::
# 88 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
# 89 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 90 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
# 91 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 92 "data/maps/JaggedPass/scripts.pory"
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
# 93 "data/maps/JaggedPass/scripts.pory"
	waitmovement 0
# 94 "data/maps/JaggedPass/scripts.pory"
	releaseall
# 95 "data/maps/JaggedPass/scripts.pory"
	end
# 96 "data/maps/JaggedPass/scripts.pory"

# 97 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Eric::
# 98 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
# 99 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
# 100 "data/maps/JaggedPass/scripts.pory"
	end
# 101 "data/maps/JaggedPass/scripts.pory"

# 102 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Diana::
# 103 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
# 104 "data/maps/JaggedPass/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 105 "data/maps/JaggedPass/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
# 106 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
# 107 "data/maps/JaggedPass/scripts.pory"
	release
# 108 "data/maps/JaggedPass/scripts.pory"
	end
# 109 "data/maps/JaggedPass/scripts.pory"

# 110 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_RegisterDiana::
# 111 "data/maps/JaggedPass/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 112 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
# 113 "data/maps/JaggedPass/scripts.pory"
	register_matchcall TRAINER_DIANA_1
# 114 "data/maps/JaggedPass/scripts.pory"
	release
# 115 "data/maps/JaggedPass/scripts.pory"
	end
# 116 "data/maps/JaggedPass/scripts.pory"

# 117 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_DianaRematch::
# 118 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
# 119 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
# 120 "data/maps/JaggedPass/scripts.pory"
	end
# 121 "data/maps/JaggedPass/scripts.pory"

# 122 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Ethan::
# 123 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
# 124 "data/maps/JaggedPass/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 125 "data/maps/JaggedPass/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
# 126 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
# 127 "data/maps/JaggedPass/scripts.pory"
	release
# 128 "data/maps/JaggedPass/scripts.pory"
	end
# 129 "data/maps/JaggedPass/scripts.pory"

# 130 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_RegisterEthan::
# 131 "data/maps/JaggedPass/scripts.pory"
	special PlayerFaceTrainerAfterBattle
# 132 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
# 133 "data/maps/JaggedPass/scripts.pory"
	register_matchcall TRAINER_ETHAN_1
# 134 "data/maps/JaggedPass/scripts.pory"
	release
# 135 "data/maps/JaggedPass/scripts.pory"
	end
# 136 "data/maps/JaggedPass/scripts.pory"

# 137 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_EthanRematch::
# 138 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
# 139 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
# 140 "data/maps/JaggedPass/scripts.pory"
	end
# 141 "data/maps/JaggedPass/scripts.pory"

# 142 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Julio::
# 143 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
# 144 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
# 145 "data/maps/JaggedPass/scripts.pory"
	end
# 146 "data/maps/JaggedPass/scripts.pory"

# 147 "data/maps/JaggedPass/scripts.pory"
JaggedPass_EventScript_Autumn::
# 148 "data/maps/JaggedPass/scripts.pory"
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
# 149 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
# 150 "data/maps/JaggedPass/scripts.pory"
	end
# 151 "data/maps/JaggedPass/scripts.pory"

# 152 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EricIntro:
# 153 "data/maps/JaggedPass/scripts.pory"
	.string "MT. CHIMNEY's JAGGED PASS…\p"
# 154 "data/maps/JaggedPass/scripts.pory"
	.string "Now this is what I've always wanted\n"
# 155 "data/maps/JaggedPass/scripts.pory"
	.string "in a mountain.\p"
# 156 "data/maps/JaggedPass/scripts.pory"
	.string "This jagged bumpiness…\n"
# 157 "data/maps/JaggedPass/scripts.pory"
	.string "It rocks my soul!$"
# 158 "data/maps/JaggedPass/scripts.pory"

# 159 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EricDefeat:
# 160 "data/maps/JaggedPass/scripts.pory"
	.string "Losing left me bitter!$"
# 161 "data/maps/JaggedPass/scripts.pory"

# 162 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EricPostBattle:
# 163 "data/maps/JaggedPass/scripts.pory"
	.string "Yes, I did lose at POKéMON…\p"
# 164 "data/maps/JaggedPass/scripts.pory"
	.string "But, when it comes to the love of\n"
# 165 "data/maps/JaggedPass/scripts.pory"
	.string "the mountains, I have you beat!$"
# 166 "data/maps/JaggedPass/scripts.pory"

# 167 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaIntro:
# 168 "data/maps/JaggedPass/scripts.pory"
	.string "This place isn't your casual hike.\n"
# 169 "data/maps/JaggedPass/scripts.pory"
	.string "It's not suited for a picnic.$"
# 170 "data/maps/JaggedPass/scripts.pory"

# 171 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaDefeat:
# 172 "data/maps/JaggedPass/scripts.pory"
	.string "Ohhh, no!\n"
# 173 "data/maps/JaggedPass/scripts.pory"
	.string "The ground is too bumpy…$"
# 174 "data/maps/JaggedPass/scripts.pory"

# 175 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaPostBattle:
# 176 "data/maps/JaggedPass/scripts.pory"
	.string "Did you know?\p"
# 177 "data/maps/JaggedPass/scripts.pory"
	.string "Some people cleverly ride their\n"
# 178 "data/maps/JaggedPass/scripts.pory"
	.string "bicycles up this horribly bumpy pass.$"
# 179 "data/maps/JaggedPass/scripts.pory"

# 180 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaRegister:
# 181 "data/maps/JaggedPass/scripts.pory"
	.string "Will you ever be back in this area?\n"
# 182 "data/maps/JaggedPass/scripts.pory"
	.string "If you do return, I'd like a rematch.$"
# 183 "data/maps/JaggedPass/scripts.pory"

# 184 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaRematchIntro:
# 185 "data/maps/JaggedPass/scripts.pory"
	.string "Picnics are fun wherever you go.\n"
# 186 "data/maps/JaggedPass/scripts.pory"
	.string "Just like POKéMON!$"
# 187 "data/maps/JaggedPass/scripts.pory"

# 188 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaRematchDefeat:
# 189 "data/maps/JaggedPass/scripts.pory"
	.string "I only lost because the ground is\n"
# 190 "data/maps/JaggedPass/scripts.pory"
	.string "too bumpy!$"
# 191 "data/maps/JaggedPass/scripts.pory"

# 192 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_DianaPostRematch:
# 193 "data/maps/JaggedPass/scripts.pory"
	.string "I'll forget about losing and just\n"
# 194 "data/maps/JaggedPass/scripts.pory"
	.string "enjoy this bumpy hike.$"
# 195 "data/maps/JaggedPass/scripts.pory"

# 196 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanIntro:
# 197 "data/maps/JaggedPass/scripts.pory"
	.string "JAGGED PASS is hard to walk on.\n"
# 198 "data/maps/JaggedPass/scripts.pory"
	.string "It's a good place for training.$"
# 199 "data/maps/JaggedPass/scripts.pory"

# 200 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanDefeat:
# 201 "data/maps/JaggedPass/scripts.pory"
	.string "It was all over while we were still\n"
# 202 "data/maps/JaggedPass/scripts.pory"
	.string "trying to find a good footing…$"
# 203 "data/maps/JaggedPass/scripts.pory"

# 204 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanPostBattle:
# 205 "data/maps/JaggedPass/scripts.pory"
	.string "If I had an ACRO BIKE, I'd be able to\n"
# 206 "data/maps/JaggedPass/scripts.pory"
	.string "jump ledges.$"
# 207 "data/maps/JaggedPass/scripts.pory"

# 208 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanRegister:
# 209 "data/maps/JaggedPass/scripts.pory"
	.string "When I get more used to this bumpiness,\n"
# 210 "data/maps/JaggedPass/scripts.pory"
	.string "I'll be sure to win!\p"
# 211 "data/maps/JaggedPass/scripts.pory"
	.string "Can you register me in your POKéNAV?$"
# 212 "data/maps/JaggedPass/scripts.pory"

# 213 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanRematchIntro:
# 214 "data/maps/JaggedPass/scripts.pory"
	.string "I got used to this bumpiness.\n"
# 215 "data/maps/JaggedPass/scripts.pory"
	.string "I sing while I climb now.$"
# 216 "data/maps/JaggedPass/scripts.pory"

# 217 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanRematchDefeat:
# 218 "data/maps/JaggedPass/scripts.pory"
	.string "It's still not easy to battle on this\n"
# 219 "data/maps/JaggedPass/scripts.pory"
	.string "bumpy ground…$"
# 220 "data/maps/JaggedPass/scripts.pory"

# 221 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_EthanPostRematch:
# 222 "data/maps/JaggedPass/scripts.pory"
	.string "I should get an ACRO BIKE from RYDEL\n"
# 223 "data/maps/JaggedPass/scripts.pory"
	.string "in MAUVILLE CITY…$"
# 224 "data/maps/JaggedPass/scripts.pory"

# 225 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_GruntIntro:
# 226 "data/maps/JaggedPass/scripts.pory"
	.string "Wah!\n"
# 227 "data/maps/JaggedPass/scripts.pory"
	.string "What are you doing here?\p"
# 228 "data/maps/JaggedPass/scripts.pory"
	.string "What am I doing in a place like this?\p"
# 229 "data/maps/JaggedPass/scripts.pory"
	.string "What business is it of yours?$"
# 230 "data/maps/JaggedPass/scripts.pory"

# 231 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_GruntDefeat:
# 232 "data/maps/JaggedPass/scripts.pory"
	.string "Urrrgh…\p"
# 233 "data/maps/JaggedPass/scripts.pory"
	.string "I should've ducked into our HIDEOUT\n"
# 234 "data/maps/JaggedPass/scripts.pory"
	.string "right away…$"
# 235 "data/maps/JaggedPass/scripts.pory"

# 236 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_GoWhereverYouWant:
# 237 "data/maps/JaggedPass/scripts.pory"
	.string "Okay, oh-kay!\n"
# 238 "data/maps/JaggedPass/scripts.pory"
	.string "I admit it--you're strong!\p"
# 239 "data/maps/JaggedPass/scripts.pory"
	.string "Don't worry about me.\n"
# 240 "data/maps/JaggedPass/scripts.pory"
	.string "Go wherever you want!$"
# 241 "data/maps/JaggedPass/scripts.pory"

# 242 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_BoulderShakingInResponseToEmblem:
# 243 "data/maps/JaggedPass/scripts.pory"
	.string "Oh! This boulder is shaking in response\n"
# 244 "data/maps/JaggedPass/scripts.pory"
	.string "to the MAGMA EMBLEM!$"
# 245 "data/maps/JaggedPass/scripts.pory"

# 246 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_JulioIntro:
# 247 "data/maps/JaggedPass/scripts.pory"
	.string "Aiyeeh! It's awfully scary to shoot\n"
# 248 "data/maps/JaggedPass/scripts.pory"
	.string "down the mountain in one go!$"
# 249 "data/maps/JaggedPass/scripts.pory"

# 250 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_JulioDefeat:
# 251 "data/maps/JaggedPass/scripts.pory"
	.string "I feel like I'm falling apart…$"
# 252 "data/maps/JaggedPass/scripts.pory"

# 253 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_JulioPostBattle:
# 254 "data/maps/JaggedPass/scripts.pory"
	.string "My bicycle bounced around so much,\n"
# 255 "data/maps/JaggedPass/scripts.pory"
	.string "my rear end's sore…$"
# 256 "data/maps/JaggedPass/scripts.pory"

# 257 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_AutumnIntro:
# 258 "data/maps/JaggedPass/scripts.pory"
	.string "I climb this hill every day.\n"
# 259 "data/maps/JaggedPass/scripts.pory"
	.string "I have confidence in my strength!$"
# 260 "data/maps/JaggedPass/scripts.pory"

# 261 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_AutumnDefeat:
# 262 "data/maps/JaggedPass/scripts.pory"
	.string "Hmm…\n"
# 263 "data/maps/JaggedPass/scripts.pory"
	.string "What went wrong?$"
# 264 "data/maps/JaggedPass/scripts.pory"

# 265 "data/maps/JaggedPass/scripts.pory"
JaggedPass_Text_AutumnPostBattle:
# 266 "data/maps/JaggedPass/scripts.pory"
	.string "What is that odd rock protrusion\n"
# 267 "data/maps/JaggedPass/scripts.pory"
	.string "a little up the hill from here?$"

JaggedPass_EventScript_CheckHasHeatranite::
# 276 "data/maps/JaggedPass/scripts.pory"
	checkitem ITEM_HEATRANITE
# 277 "data/maps/JaggedPass/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq JaggedPass_EventScript_CheckHasHeatranite_2
JaggedPass_EventScript_CheckHasHeatranite_1:
	return

JaggedPass_EventScript_CheckHasHeatranite_2:
# 278 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_HEATRAN_CAVE_STATE, 1
	goto JaggedPass_EventScript_CheckHasHeatranite_1


JaggedPass_EventScript_ConcealHeatranCave::
# 284 "data/maps/JaggedPass/scripts.pory"
	setmetatile 19, 4, METATILE_Lavaridge_RockWall, TRUE
# 285 "data/maps/JaggedPass/scripts.pory"
	setmetatile 19, 5, METATILE_Lavaridge_RockWall, TRUE
	return


JaggedPass_EventScript_OpenHeatranCave::
# 290 "data/maps/JaggedPass/scripts.pory"
	lockall
# 291 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8004, 1
# 292 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8005, 1
# 293 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8006, 8
# 294 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8007, 5
# 295 "data/maps/JaggedPass/scripts.pory"
	special ShakeCamera
# 296 "data/maps/JaggedPass/scripts.pory"
	waitstate
# 297 "data/maps/JaggedPass/scripts.pory"
	msgbox JaggedPass_Text_BoulderTremblingInResponseToHeatranite, MSGBOX_DEFAULT
# 298 "data/maps/JaggedPass/scripts.pory"
	closemessage
# 299 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8004, 1
# 300 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8005, 1
# 301 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8006, 16
# 302 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_0x8007, 3
# 303 "data/maps/JaggedPass/scripts.pory"
	special ShakeCamera
# 304 "data/maps/JaggedPass/scripts.pory"
	waitstate
# 305 "data/maps/JaggedPass/scripts.pory"
	playse SE_EFFECTIVE
# 306 "data/maps/JaggedPass/scripts.pory"
	setmetatile 19, 4, METATILE_Lavaridge_CaveEntrance_Top, TRUE
# 307 "data/maps/JaggedPass/scripts.pory"
	setmetatile 19, 5, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
# 308 "data/maps/JaggedPass/scripts.pory"
	special DrawWholeMapView
# 309 "data/maps/JaggedPass/scripts.pory"
	delay 30
# 310 "data/maps/JaggedPass/scripts.pory"
	setvar VAR_HEATRAN_CAVE_STATE, 2
# 311 "data/maps/JaggedPass/scripts.pory"
	waitse
# 312 "data/maps/JaggedPass/scripts.pory"
	releaseall
	end


JaggedPass_Text_BoulderTremblingInResponseToHeatranite::
# 316 "data/maps/JaggedPass/scripts.pory"
	.string "The rocky slope is trembling violently\n"
	.string "in response to the HEATRANITE!$"
