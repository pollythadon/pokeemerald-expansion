#ifndef GUARD_QUEST_DATA_H
#define GUARD_QUEST_DATA_H

// Strings for the 10 post-game legendary quests. Included by src/quests.c so the
// definitions are local to the quest table below them.

// QUEST_MEWTWO
static const u8 sQuestName_Mewtwo[] = _("Genetic Terror");
static const u8 sQuestDesc_Mewtwo[] = _("Take the Mewtwonite to Artisan\nCave, off Route 103, to challenge Mewtwo.");
static const u8 sQuestDone_Mewtwo[] = _("You faced the cloned terror,\nMewtwo, deep in Artisan Cave.");
static const u8 sQuestMap_Mewtwo[] = _("Artisan Cave");

// QUEST_DIALGA
static const u8 sQuestName_Dialga[] = _("Lord of Time");
static const u8 sQuestDesc_Dialga[] = _("Bring the Adamant Orb to the\nCave of Origin to rouse Dialga.");
static const u8 sQuestDone_Dialga[] = _("Time itself bent as you faced\nDialga in the Cave of Origin.");
static const u8 sQuestMap_Dialga[] = _("Cave of Origin");

// QUEST_PALKIA
static const u8 sQuestName_Palkia[] = _("Lord of Space");
static const u8 sQuestDesc_Palkia[] = _("Bring the Lustrous Orb to\nMeteor Falls to rouse Palkia.");
static const u8 sQuestDone_Palkia[] = _("Space itself folded as you faced\nPalkia in Meteor Falls.");
static const u8 sQuestMap_Palkia[] = _("Meteor Falls");

// QUEST_GIRATINA (2 states)
static const u8 sQuestName_Giratina[] = _("The Renegade");
static const u8 sQuestDesc_Giratina_0[] = _("Dig up the Griseous Core from\nthe marked spot near Ever Grande.");
static const u8 sQuestDesc_Giratina_1[] = _("Show the Griseous Core to the\ntraveler in Ever Grande City.");
static const u8 sQuestDone_Giratina[] = _("You crossed into the Distortion\nWorld and faced Giratina.");
static const u8 sQuestMap_Giratina_0[] = _("Ever Grande City");
static const u8 sQuestMap_Giratina_1[] = _("Ever Grande City");

// QUEST_ARCEUS (2 states)
static const u8 sQuestName_Arceus[] = _("The Original One");
static const u8 sQuestDesc_Arceus_0[] = _("Catch Dialga, Palkia and Giratina,\nthen see the elder in Sootopolis.");
static const u8 sQuestDesc_Arceus_1[] = _("Board the rocket in Mossdeep City\nto reach the Space Meteor.");
static const u8 sQuestDone_Arceus[] = _("You ascended to the Space Meteor\nand faced Arceus itself.");
static const u8 sQuestMap_Arceus_0[] = _("Sootopolis City");
static const u8 sQuestMap_Arceus_1[] = _("Mossdeep City");

// QUEST_JIRACHI (2 states)
static const u8 sQuestName_Jirachi[] = _("The Wishmaker");
static const u8 sQuestDesc_Jirachi_0[] = _("Take the Old Sea Map to the\ngirl in Mossdeep City.");
static const u8 sQuestDesc_Jirachi_1[] = _("Sail from Pacifidlog Town to the\nstar-blessed isle.");
static const u8 sQuestDone_Jirachi[] = _("You made your wish upon the\nWishmaker, Jirachi.");
static const u8 sQuestMap_Jirachi_0[] = _("Mossdeep City");
static const u8 sQuestMap_Jirachi_1[] = _("Pacifidlog Town");

// QUEST_CELEBI
static const u8 sQuestName_Celebi[] = _("Voice of the Forest");
static const u8 sQuestDesc_Celebi[] = _("Bring the Tea to Petalburg Woods\nto call out to Celebi.");
static const u8 sQuestDone_Celebi[] = _("The Voice of the Forest, Celebi,\nanswered you in Petalburg Woods.");
static const u8 sQuestMap_Celebi[] = _("Petalburg Woods");

// QUEST_DARKRAI
static const u8 sQuestName_Darkrai[] = _("Bringer of Nightmares");
static const u8 sQuestDesc_Darkrai[] = _("Bring the Darkranite to Granite\nCave to face Darkrai.");
static const u8 sQuestDone_Darkrai[] = _("You faced Darkrai in the dark of\nGranite Cave.");
static const u8 sQuestMap_Darkrai[] = _("Granite Cave");

// QUEST_CRESSELIA
static const u8 sQuestName_Cresselia[] = _("Bringer of Dreams");
static const u8 sQuestDesc_Cresselia[] = _("Bring the Dread Plate to Route\n126 to face Cresselia.");
static const u8 sQuestDone_Cresselia[] = _("You met Cresselia in the moonlit\nsea of Route 126.");
static const u8 sQuestMap_Cresselia[] = _("Route 126");

// QUEST_SHAYMIN
static const u8 sQuestName_Shaymin[] = _("Gratitude");
static const u8 sQuestDesc_Shaymin[] = _("Carry the Gracidea and sail from\nPacifidlog to the flowered isle.");
static const u8 sQuestDone_Shaymin[] = _("You offered gratitude to Shaymin\nin the flowered paradise.");
static const u8 sQuestMap_Shaymin[] = _("Pacifidlog Town");

#endif // GUARD_QUEST_DATA_H
