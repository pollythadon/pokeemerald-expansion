#ifndef GUARD_CONSTANTS_QUESTS_H
#define GUARD_CONSTANTS_QUESTS_H

//questmenu scripting command params
#define QUEST_MENU_OPEN                 0   //opens the quest menu (questId = 0)
#define QUEST_MENU_UNLOCK_QUEST         1   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_SET_ACTIVE           2   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_SET_REWARD           3   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_COMPLETE_QUEST       4   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_CHECK_UNLOCKED       5   //checks if questId has been unlocked. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_INACTIVE       6 //check if a questID is inactive. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_ACTIVE         7   //checks if questId has been unlocked. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_REWARD         8  //checks if questId is in Reward state. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_COMPLETE       9   //checks if questId has been completed. Returns result to gSpecialVar_Result
#define QUEST_MENU_BUFFER_QUEST_NAME    10   //buffers a quest name to gStringVar1

#define QUEST_NONE                      0xFFFF // object_event has no assigned quest

// quest number defines
#define QUEST_1          0
#define QUEST_2          1
#define QUEST_3          2
#define QUEST_4          3
#define QUEST_5          4
#define QUEST_6          5
#define QUEST_7          6
#define QUEST_8          7
#define QUEST_9          8
#define QUEST_10         9
#define QUEST_11        10
#define QUEST_12        11
#define QUEST_13        12
#define QUEST_14        13
#define QUEST_15        14
#define QUEST_16        15
#define QUEST_17        16
#define QUEST_18        17
#define QUEST_19        18
#define QUEST_20        19
#define QUEST_21        20
#define QUEST_22        21
#define QUEST_23        22
#define QUEST_24        23
#define QUEST_25        24
#define QUEST_26        25
#define QUEST_27        26
#define QUEST_28        27
#define QUEST_29        28
#define QUEST_30        29
#define QUEST_31        30
#define QUEST_32        31
#define QUEST_33        32
#define QUEST_34        33
#define QUEST_35        34
#define QUEST_36        35
#define QUEST_37        36
#define QUEST_38        37
#define QUEST_39        38
#define QUEST_40        39
#define QUEST_41        40
#define QUEST_42        41
#define QUEST_43        42
#define QUEST_44        43
#define QUEST_45        44
#define QUEST_46        45
#define QUEST_47        46
#define QUEST_48        47
#define QUEST_49        48
#define QUEST_50        49
#define QUEST_51        50

// Post-game legendary quest aliases (custom framework tie-in)
#define QUEST_MEWTWO     QUEST_1
#define QUEST_DIALGA     QUEST_2
#define QUEST_PALKIA     QUEST_3
#define QUEST_GIRATINA   QUEST_4
#define QUEST_ARCEUS     QUEST_5
#define QUEST_JIRACHI    QUEST_6
#define QUEST_CELEBI     QUEST_7
#define QUEST_DARKRAI    QUEST_8
#define QUEST_CRESSELIA  QUEST_9
#define QUEST_SHAYMIN    QUEST_10
// Post-game event-island legendaries (vanilla encounters wrapped as quests)
#define QUEST_MEW        QUEST_11
#define QUEST_LUGIA      QUEST_12   // covers Lugia + Ho-Oh at Navel Rock
#define QUEST_DEOXYS     QUEST_13

// Gym-badge quests (unlock sequentially, one per badge)
#define QUEST_BADGE_1    QUEST_14
#define QUEST_BADGE_2    QUEST_15
#define QUEST_BADGE_3    QUEST_16
#define QUEST_BADGE_4    QUEST_17
#define QUEST_BADGE_5    QUEST_18
#define QUEST_BADGE_6    QUEST_19
#define QUEST_BADGE_7    QUEST_20
#define QUEST_BADGE_8    QUEST_21

// Milestone quests
#define QUEST_CHAMPION   QUEST_22
#define QUEST_DEXNAV     QUEST_23
#define QUEST_POKEDEX    QUEST_24

// Catch-count quests
#define QUEST_CATCH_50   QUEST_25
#define QUEST_CATCH_100  QUEST_26
#define QUEST_CATCH_300  QUEST_27
#define QUEST_CATCH_500  QUEST_28
#define QUEST_CATCH_800  QUEST_29

// Intro guide quest
#define QUEST_INTRO      QUEST_30

// Gift-egg quest (Verdanturf traveler's mysterious Egg)
#define QUEST_SHINY_PICHU_EGG QUEST_31

// Post-game legendary (Fiery Path researcher gifts the Heatranite)
#define QUEST_HEATRAN    QUEST_32

// Post-game legendary (the three Hoenn titans awaken the Desert Underpass statue)
#define QUEST_REGIGIGAS  QUEST_33

// Hoenn's native legendary encounters and the Southern Island event.
// Keep these appended so existing quest IDs remain save-compatible.
#define QUEST_GROUDON     QUEST_34
#define QUEST_KYOGRE      QUEST_35
#define QUEST_RAYQUAZA    QUEST_36
#define QUEST_REGIROCK    QUEST_37
#define QUEST_REGICE      QUEST_38
#define QUEST_REGISTEEL   QUEST_39
#define QUEST_EON_TICKET  QUEST_40
#define QUEST_SEALED_CHAMBER QUEST_41

// Post-Champion character stories. Keep these appended so every older quest ID
// and the first extension block remain stable in existing save files.
#define QUEST_WALLY             QUEST_42
#define QUEST_STEVEN            QUEST_43
#define QUEST_ROXANNE           QUEST_44
#define QUEST_BRAWLY            QUEST_45
#define QUEST_WATTSON           QUEST_46
#define QUEST_FLANNERY          QUEST_47
#define QUEST_NORMAN            QUEST_48
#define QUEST_WINONA            QUEST_49
#define QUEST_TATE_AND_LIZA     QUEST_50
#define QUEST_JUAN              QUEST_51

#define QUEST_LEGACY_COUNT            33
#define QUEST_HOENN_EXTENSION_COUNT    8
#define QUEST_CHARACTER_START         QUEST_42
#define QUEST_CHARACTER_COUNT         10
#define QUEST_COUNT                   51

#define SUB_QUEST_1          0
#define SUB_QUEST_2          1
#define SUB_QUEST_3          2
#define SUB_QUEST_4          3
#define SUB_QUEST_5          4
#define SUB_QUEST_6          5
#define SUB_QUEST_7          6
#define SUB_QUEST_8          7
#define SUB_QUEST_9          8
#define SUB_QUEST_10         9
#define SUB_QUEST_11        10
#define SUB_QUEST_12        11
#define SUB_QUEST_13        12
#define SUB_QUEST_14        13
#define SUB_QUEST_15        14
#define SUB_QUEST_16        15
#define SUB_QUEST_17        16
#define SUB_QUEST_18        17
#define SUB_QUEST_19        18
#define SUB_QUEST_20        19
#define SUB_QUEST_21        20
#define SUB_QUEST_22        21
#define SUB_QUEST_23        22
#define SUB_QUEST_24        23
#define SUB_QUEST_25        24
#define SUB_QUEST_26        25
#define SUB_QUEST_27        26
#define SUB_QUEST_28        27
#define SUB_QUEST_29        28
#define SUB_QUEST_30        29

#define QUEST_1_SUB_COUNT 10
#define QUEST_2_SUB_COUNT 20
#define SUB_QUEST_COUNT (QUEST_1_SUB_COUNT + QUEST_2_SUB_COUNT)

#define QUEST_ARRAY_COUNT (SUB_QUEST_COUNT > QUEST_COUNT ? SUB_QUEST_COUNT : QUEST_COUNT)
#endif // GUARD_CONSTANTS_QUESTS_H
