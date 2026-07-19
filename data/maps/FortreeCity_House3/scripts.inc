FortreeCity_House3_MapScripts::
	.byte 0

FortreeCity_House3_EventScript_Maniac::
	msgbox FortreeCity_House3_Text_MetStevenHadAmazingPokemon, MSGBOX_NPC
	end

FortreeCity_House3_EventScript_SchoolKidM::
	msgbox FortreeCity_House3_Text_OhYouHavePokedex, MSGBOX_NPC
	end

FortreeCity_House3_EventScript_EonNavigator::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EON_TICKET, FortreeCity_House3_EventScript_EonTicketReceived
	checkitem ITEM_EON_TICKET
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_House3_EventScript_RecognizeEonTicket
	msgbox FortreeCity_House3_Text_EonNavigatorIntroduction, MSGBOX_DEFAULT
	giveitem ITEM_EON_TICKET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	startquest QUEST_EON_TICKET
	goto FortreeCity_House3_EventScript_EnableSouthernIsland
	end

FortreeCity_House3_EventScript_RecognizeEonTicket::
	msgbox FortreeCity_House3_Text_RecognizeEonTicket, MSGBOX_DEFAULT
	questmenu QUEST_MENU_CHECK_UNLOCKED, QUEST_EON_TICKET
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_House3_EventScript_EnableSouthernIsland
	startquest QUEST_EON_TICKET

FortreeCity_House3_EventScript_EnableSouthernIsland::
	setflag FLAG_RECEIVED_EON_TICKET
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	msgbox FortreeCity_House3_Text_TakeTicketToLilycove, MSGBOX_DEFAULT
	release
	end

FortreeCity_House3_EventScript_EonTicketReceived::
	msgbox FortreeCity_House3_Text_EonTicketReceived, MSGBOX_DEFAULT
	release
	end

FortreeCity_House3_Text_MetStevenHadAmazingPokemon:
	.string "While speaking about POKéDEXES,\n"
	.string "I remembered something.\p"
	.string "I met this TRAINER, STEVEN, when\n"
	.string "I was searching for rare stones.\p"
	.string "Hoo, boy, he had some amazing POKéMON\n"
	.string "with him.\p"
	.string "They weren't just rare, they were\n"
	.string "trained to terrifying extremes!\p"
	.string "He might even be stronger than the\n"
	.string "GYM LEADER in this town…$"

FortreeCity_House3_Text_OhYouHavePokedex:
	.string "What's that thing you have there?\p"
	.string "… … … … … …\p"
	.string "Oh, it's called a POKéDEX?\n"
	.string "It's really awesome!$"

FortreeCity_House3_Text_EonNavigatorIntroduction:
	.string "Those are the eyes of HOENN's new\n"
	.string "CHAMPION… Then perhaps you can hear it.\p"
	.string "Long ago, I navigated by two lights that\n"
	.string "crossed the southern sky.\p"
	.string "They led me to an island absent from\n"
	.string "every chart but this old Ticket.\p"
	.string "Take it. I believe its twin wings have\n"
	.string "been waiting for you.$"

FortreeCity_House3_Text_RecognizeEonTicket:
	.string "That EON TICKET… The southern winds\n"
	.string "have already chosen you.\p"
	.string "Let me mark its forgotten route on the\n"
	.string "LILYCOVE ferry charts.$"

FortreeCity_House3_Text_TakeTicketToLilycove:
	.string "Show the EON TICKET at LILYCOVE\n"
	.string "HARBOR. It will carry you beyond the\l"
	.string "usual sea lanes to SOUTHERN ISLAND.\p"
	.string "When you reach the stone at its heart,\n"
	.string "listen for the other wing.$"

FortreeCity_House3_Text_EonTicketReceived:
	.string "Red and blue lights still cross in my\n"
	.string "dreams. SOUTHERN ISLAND is calling.\p"
	.string "Take the EON TICKET to LILYCOVE\n"
	.string "HARBOR when you are ready.$"
