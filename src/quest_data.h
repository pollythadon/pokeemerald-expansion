#ifndef GUARD_QUEST_DATA_H
#define GUARD_QUEST_DATA_H

// Strings for the 10 post-game legendary quests. Included by src/quests.c so the
// definitions are local to the quest table below them.
//
// Each quest carries a "start" location + hint (shown while the quest is still
// unaccepted, pointing the player at the giver) and one or more "active" desc +
// map entries (shown once accepted, pointing at the next place to go). The
// "done" line is the lore recap after the legendary is faced.

// QUEST_MEWTWO
static const u8 sQuestName_Mewtwo[] = _("Genetic Terror");
static const u8 sQuestStartMap_Mewtwo[] = _("Weather Institute");
static const u8 sQuestStart_Mewtwo[] = _("A scientist in the Weather\nInstitute is holding two stones.");
static const u8 sQuestDesc_Mewtwo[] = _("Take the Mewtwonites to Artisan\nCave, hidden off Route 103.");
static const u8 sQuestDone_Mewtwo[] = _("You cornered the clone Mewtwo\nin the depths of Artisan Cave.");
static const u8 sQuestMap_Mewtwo[] = _("Artisan Cave");

// QUEST_DIALGA
static const u8 sQuestName_Dialga[] = _("Lord of Time");
static const u8 sQuestStartMap_Dialga[] = _("Space Center");
static const u8 sQuestStart_Dialga[] = _("A scientist at the Mossdeep\nSpace Center studies the Orbs.");
static const u8 sQuestDesc_Dialga[] = _("Bring the Adamant Orb to the\nCave of Origin to wake Dialga.");
static const u8 sQuestDone_Dialga[] = _("Time itself groaned as you woke\nDialga in the Cave of Origin.");
static const u8 sQuestMap_Dialga[] = _("Cave of Origin");

// QUEST_PALKIA
static const u8 sQuestName_Palkia[] = _("Lord of Space");
static const u8 sQuestStartMap_Palkia[] = _("Cozmo's House");
static const u8 sQuestStart_Palkia[] = _("Professor Cozmo in Fallarbor\nkept a strange, shining pearl.");
static const u8 sQuestDesc_Palkia[] = _("Bring the Lustrous Orb to\nMeteor Falls to wake Palkia.");
static const u8 sQuestDone_Palkia[] = _("Space itself folded as you woke\nPalkia deep in Meteor Falls.");
static const u8 sQuestMap_Palkia[] = _("Meteor Falls");

// QUEST_GIRATINA
static const u8 sQuestName_Giratina[] = _("The Renegade");
static const u8 sQuestStartMap_Giratina[] = _("Ever Grande City");
static const u8 sQuestStart_Giratina[] = _("There's a mysterious sign in\nEver Grande City.");
static const u8 sQuestDesc_Giratina[] = _("Carry the Griseous Core to the\nrift torn open in Ever Grande.");
static const u8 sQuestDone_Giratina[] = _("The core pried a door open. You\nfaced Giratina beyond reality.");
static const u8 sQuestMap_Giratina[] = _("Ever Grande City");

// QUEST_ARCEUS
static const u8 sQuestName_Arceus[] = _("The Original One");
static const u8 sQuestStartMap_Arceus[] = _("Sootopolis City");
static const u8 sQuestStart_Arceus[] = _("A believer in Sootopolis waits\nfor one who tamed the trio.");
static const u8 sQuestDesc_Arceus[] = _("Board the rocket at the Mossdeep\nSpace Center.");
static const u8 sQuestDone_Arceus[] = _("You rode beyond the sky to the\nSpace Meteor and met Arceus.");
static const u8 sQuestMap_Arceus[] = _("Mossdeep City");

// QUEST_JIRACHI (2 active states)
static const u8 sQuestName_Jirachi[] = _("The Wishmaker");
static const u8 sQuestStartMap_Jirachi[] = _("Lilycove City");
static const u8 sQuestStart_Jirachi[] = _("A sailor in Lilycove parts with\na worn Old Sea Map.");
static const u8 sQuestDesc_Jirachi_0[] = _("Show the Old Sea Map to the\ngirl in Mossdeep City.");
static const u8 sQuestDesc_Jirachi_1[] = _("Sail from Pacifidlog Town to\nthe star-blessed isle.");
static const u8 sQuestDone_Jirachi[] = _("For one night you woke Jirachi,\nand it granted your wish.");
static const u8 sQuestMap_Jirachi_0[] = _("Mossdeep City");
static const u8 sQuestMap_Jirachi_1[] = _("Pacifidlog Town");

// QUEST_CELEBI
static const u8 sQuestName_Celebi[] = _("Voice of the Forest");
static const u8 sQuestStartMap_Celebi[] = _("Oldale Town");
static const u8 sQuestStart_Celebi[] = _("A woman in Oldale Town brews a\nfragrant, gentle Tea.");
static const u8 sQuestDesc_Celebi[] = _("Carry the Tea into Petalburg\nWoods and call to Celebi.");
static const u8 sQuestDone_Celebi[] = _("A voice in the trees answered.\nCelebi stepped out of time.");
static const u8 sQuestMap_Celebi[] = _("Petalburg Woods");

// QUEST_DARKRAI
static const u8 sQuestName_Darkrai[] = _("Bringer of Nightmares");
static const u8 sQuestStartMap_Darkrai[] = _("Name Rater's House");
static const u8 sQuestStart_Darkrai[] = _("The Name Rater's cousin in\nSlateport hides a stone of dark.");
static const u8 sQuestDesc_Darkrai[] = _("Take the Darkranite into Granite\nCave to draw out Darkrai.");
static const u8 sQuestDone_Darkrai[] = _("Darkrai rose from the black of\nGranite Cave to meet you.");
static const u8 sQuestMap_Darkrai[] = _("Granite Cave");

// QUEST_CRESSELIA
static const u8 sQuestName_Cresselia[] = _("Bringer of Dreams");
static const u8 sQuestStartMap_Cresselia[] = _("Dewford Town");
static const u8 sQuestStart_Cresselia[] = _("A dreamer in Dewford Town hands\nyou a cold Dread Plate.");
static const u8 sQuestDesc_Cresselia[] = _("Carry the Dread Plate to the\nmoonlit sea of Route 126.");
static const u8 sQuestDone_Cresselia[] = _("Cresselia crossed the moonlit\nwaves of Route 126 to you.");
static const u8 sQuestMap_Cresselia[] = _("Route 126");

// QUEST_SHAYMIN
static const u8 sQuestName_Shaymin[] = _("Gratitude");
static const u8 sQuestStartMap_Shaymin[] = _("Route 104");
static const u8 sQuestStart_Shaymin[] = _("The florist on Route 104 tucks\na Gracidea into your bag.");
static const u8 sQuestDesc_Shaymin[] = _("Carry the Gracidea and sail from\nPacifidlog to the flowered isle.");
static const u8 sQuestDone_Shaymin[] = _("Among the flowers it took wing\nas Sky Forme, and thanked you.");
static const u8 sQuestMap_Shaymin[] = _("Pacifidlog Town");

// ======================= Post-game event-island legendaries =======================

// QUEST_MEW (Old Sea Map, shared with Jirachi -> Faraway Island)
static const u8 sQuestName_Mew[] = _("The New Species");
static const u8 sQuestStartMap_Mew[] = _("Lilycove City");
static const u8 sQuestStart_Mew[] = _("The sailor in Lilycove holds an\nOld Sea Map to a far isle.");
static const u8 sQuestDesc_Mew[] = _("Sail from Lilycove Harbor to\ndistant Faraway Island.");
static const u8 sQuestDone_Mew[] = _("On Faraway Island you met the\nancestor of all, Mew.");
static const u8 sQuestMap_Mew[] = _("Lilycove Harbor");

// QUEST_LUGIA (Mystic Ticket -> Navel Rock: Lugia + Ho-Oh)
static const u8 sQuestName_Lugia[] = _("The Tower Duo");
static const u8 sQuestStartMap_Lugia[] = _("Lavaridge Town");
static const u8 sQuestStart_Lugia[] = _("Someone in Lavaridge is parting\nwith a Mystic Ticket.");
static const u8 sQuestDesc_Lugia[] = _("Sail from Lilycove Harbor to\nNavel Rock's peak and depths.");
static const u8 sQuestDone_Lugia[] = _("Atop and beneath Navel Rock you\nfaced Ho-Oh and Lugia.");
static const u8 sQuestMap_Lugia[] = _("Lilycove Harbor");

// QUEST_DEOXYS (Aurora Ticket -> Birth Island)
static const u8 sQuestName_Deoxys[] = _("Visitor From Space");
static const u8 sQuestStartMap_Deoxys[] = _("Mossdeep City");
static const u8 sQuestStart_Deoxys[] = _("A researcher in Mossdeep offers\nan Aurora Ticket.");
static const u8 sQuestDesc_Deoxys[] = _("Sail from Lilycove Harbor to\nlonely Birth Island.");
static const u8 sQuestDone_Deoxys[] = _("On Birth Island's triangle you\nfaced Deoxys from the stars.");
static const u8 sQuestMap_Deoxys[] = _("Lilycove Harbor");

// ============================= Gym-badge quests =============================

static const u8 sQuestName_Badge1[] = _("Stone Badge");
static const u8 sQuestDesc_Badge1[] = _("Defeat Roxanne at the\nRustboro City Gym.");
static const u8 sQuestDone_Badge1[] = _("You earned the Stone Badge\nfrom Roxanne.");
static const u8 sQuestMap_Badge1[] = _("Rustboro City");

static const u8 sQuestName_Badge2[] = _("Knuckle Badge");
static const u8 sQuestDesc_Badge2[] = _("Defeat Brawly at the\nDewford Town Gym.");
static const u8 sQuestDone_Badge2[] = _("You earned the Knuckle Badge\nfrom Brawly.");
static const u8 sQuestMap_Badge2[] = _("Dewford Town");

static const u8 sQuestName_Badge3[] = _("Dynamo Badge");
static const u8 sQuestDesc_Badge3[] = _("Defeat Wattson at the\nMauville City Gym.");
static const u8 sQuestDone_Badge3[] = _("You earned the Dynamo Badge\nfrom Wattson.");
static const u8 sQuestMap_Badge3[] = _("Mauville City");

static const u8 sQuestName_Badge4[] = _("Heat Badge");
static const u8 sQuestDesc_Badge4[] = _("Defeat Flannery at the\nLavaridge Town Gym.");
static const u8 sQuestDone_Badge4[] = _("You earned the Heat Badge\nfrom Flannery.");
static const u8 sQuestMap_Badge4[] = _("Lavaridge Town");

static const u8 sQuestName_Badge5[] = _("Balance Badge");
static const u8 sQuestDesc_Badge5[] = _("Defeat Norman at the\nPetalburg City Gym.");
static const u8 sQuestDone_Badge5[] = _("You earned the Balance Badge\nfrom Norman.");
static const u8 sQuestMap_Badge5[] = _("Petalburg City");

static const u8 sQuestName_Badge6[] = _("Feather Badge");
static const u8 sQuestDesc_Badge6[] = _("Defeat Winona at the\nFortree City Gym.");
static const u8 sQuestDone_Badge6[] = _("You earned the Feather Badge\nfrom Winona.");
static const u8 sQuestMap_Badge6[] = _("Fortree City");

static const u8 sQuestName_Badge7[] = _("Mind Badge");
static const u8 sQuestDesc_Badge7[] = _("Defeat Tate & Liza at the\nMossdeep City Gym.");
static const u8 sQuestDone_Badge7[] = _("You earned the Mind Badge\nfrom Tate & Liza.");
static const u8 sQuestMap_Badge7[] = _("Mossdeep City");

static const u8 sQuestName_Badge8[] = _("Rain Badge");
static const u8 sQuestDesc_Badge8[] = _("Defeat Juan at the\nSootopolis City Gym.");
static const u8 sQuestDone_Badge8[] = _("You earned the Rain Badge\nfrom Juan.");
static const u8 sQuestMap_Badge8[] = _("Sootopolis City");

// ============================= Milestone quests =============================

// QUEST_CHAMPION
static const u8 sQuestName_Champion[] = _("Champion of Hoenn");
static const u8 sQuestDesc_Champion[] = _("Conquer the Elite Four and\nbest the Champion.");
static const u8 sQuestDone_Champion[] = _("You bested the Elite Four and\nstand as Champion of Hoenn.");
static const u8 sQuestMap_Champion[] = _("Ever Grande City");

// QUEST_DEXNAV (giver: Petalburg House1 scientist; stays inactive so bubble shows)
static const u8 sQuestName_DexNav[] = _("The DexNav");
static const u8 sQuestStartMap_DexNav[] = _("Petalburg City");
static const u8 sQuestStart_DexNav[] = _("A scientist in a Petalburg\nhouse built a handy app.");
static const u8 sQuestDesc_DexNav[] = _("Visit the scientist in\nPetalburg City.");
static const u8 sQuestDone_DexNav[] = _("The scientist installed the\nDexNav on your PokéNav.");
static const u8 sQuestMap_DexNav[] = _("Petalburg City");

// QUEST_POKEDEX
static const u8 sQuestName_Pokedex[] = _("Complete the Pokédex");
static const u8 sQuestDesc_Pokedex[] = _("Catch every Pokémon to\nfill the Pokédex.");
static const u8 sQuestDone_Pokedex[] = _("You completed the Pokédex --\na true master's feat!");
static const u8 sQuestMap_Pokedex[] = _("All Regions");

// ============================= Catch-count quests =============================

static const u8 sQuestName_Catch50[] = _("Budding Collector");
static const u8 sQuestDesc_Catch50[] = _("Register 50 species as\ncaught in your Pokédex.");
static const u8 sQuestDone_Catch50[] = _("You've caught 50 species!");
static const u8 sQuestMap_Catch[] = _("Anywhere");

static const u8 sQuestName_Catch100[] = _("Seasoned Collector");
static const u8 sQuestDesc_Catch100[] = _("Register 100 species as\ncaught in your Pokédex.");
static const u8 sQuestDone_Catch100[] = _("You've caught 100 species!");

static const u8 sQuestName_Catch300[] = _("Devoted Collector");
static const u8 sQuestDesc_Catch300[] = _("Register 300 species as\ncaught in your Pokédex.");
static const u8 sQuestDone_Catch300[] = _("You've caught 300 species!");

static const u8 sQuestName_Catch500[] = _("Master Collector");
static const u8 sQuestDesc_Catch500[] = _("Register 500 species as\ncaught in your Pokédex.");
static const u8 sQuestDone_Catch500[] = _("You've caught 500 species!");

static const u8 sQuestName_Catch800[] = _("Living Legend");
static const u8 sQuestDesc_Catch800[] = _("Register 800 species as\ncaught in your Pokédex.");
static const u8 sQuestDone_Catch800[] = _("You've caught 800 species!");

// QUEST_INTRO
static const u8 sQuestName_Intro[] = _("A New Adventure");
static const u8 sQuestDesc_Intro[] = _("Get your Pokédex and set\nout across Hoenn.");
static const u8 sQuestDone_Intro[] = _("Your journey through Hoenn\nhas begun!");
static const u8 sQuestMap_Intro[] = _("Littleroot Town");

// ============================== Gift-egg quest ===============================

static const u8 sQuestName_ShinyPichuEgg[] = _("The Traveler's Egg");
static const u8 sQuestStartMap_ShinyPichuEgg[] = _("Verdanturf Town");
static const u8 sQuestStart_ShinyPichuEgg[] = _("A traveler in Verdanturf Town\nholds a mysterious Egg.");
static const u8 sQuestDesc_ShinyPichuEgg[] = _("Raise the mysterious Egg with\ncare until it hatches.");
static const u8 sQuestDone_ShinyPichuEgg[] = _("The Egg hatched into a shining\nPichu -- a one-of-a-kind friend.");
static const u8 sQuestMap_ShinyPichuEgg[] = _("Verdanturf Town");

// ============================ Heatran quest ==================================

static const u8 sQuestName_Heatran[] = _("Lord of the Magma");
static const u8 sQuestStartMap_Heatran[] = _("Fiery Path");
static const u8 sQuestStart_Heatran[] = _("A researcher in the Fiery Path\nstudies the volcano's tremors.");
static const u8 sQuestDesc_Heatran[] = _("Carry the Heatranite to Jagged\nPass to reveal a hidden cave.");
static const u8 sQuestDone_Heatran[] = _("Heatran stirred from the magma\ndeep beneath Jagged Pass.");
static const u8 sQuestMap_Heatran[] = _("Jagged Pass");

// ========================== Regigigas quest =================================

static const u8 sQuestName_Regigigas[] = _("The Ancient Titan");
static const u8 sQuestStartMap_Regigigas[] = _("Desert Underpass");
static const u8 sQuestStart_Regigigas[] = _("A colossal statue sleeps at the\nfar end of Desert Underpass.");
static const u8 sQuestDesc_Regigigas[] = _("Bring Regirock, Regice, and\nRegisteel before the statue.");
static const u8 sQuestDone_Regigigas[] = _("The three titans awakened their\nancient master, Regigigas.");
static const u8 sQuestMap_Regigigas[] = _("Desert Underpass");

// ======================== Native Hoenn legendaries =========================

static const u8 sQuestName_Groudon[] = _("Continent in Motion");
static const u8 sQuestStartMap_Groudon[] = _("Weather Institute");
static const u8 sQuestStart_Groudon[] = _("The Weather Institute detects\nstrange post-League droughts.");
static const u8 sQuestDesc_Groudon[] = _("Track the drought to Terra Cave's\nshifting entrance.");
static const u8 sQuestDone_Groudon[] = _("Deep in Terra Cave, you faced\nGroudon, the continent Pokémon.");
static const u8 sQuestMap_Groudon[] = _("Terra Cave");

static const u8 sQuestName_Kyogre[] = _("The Deep Stirs");
static const u8 sQuestStartMap_Kyogre[] = _("Weather Institute");
static const u8 sQuestStart_Kyogre[] = _("The Weather Institute detects\nstrange post-League downpours.");
static const u8 sQuestDesc_Kyogre[] = _("Track the rain to Marine Cave's\nshifting entrance.");
static const u8 sQuestDone_Kyogre[] = _("Deep in Marine Cave, you faced\nKyogre, the sea basin Pokémon.");
static const u8 sQuestMap_Kyogre[] = _("Marine Cave");

static const u8 sQuestName_Rayquaza[] = _("Lord of the Sky");
static const u8 sQuestStartMap_Rayquaza[] = _("Cave of Origin");
static const u8 sQuestStart_Rayquaza[] = _("Wallace believes Sky Pillar holds\nthe answer to Hoenn's crisis.");
static const u8 sQuestDesc_Rayquaza[] = _("Follow Wallace to Sky Pillar.\nReturn later to face Rayquaza.");
static const u8 sQuestDone_Rayquaza[] = _("At Sky Pillar's summit, you faced\nRayquaza, the sky high Pokémon.");
static const u8 sQuestMap_Rayquaza[] = _("Sky Pillar");

// The three ruin quests unlock together when the Sealed Chamber opens. This
// preserves the original any-order puzzles while making them one linked chain.
static const u8 sQuestName_Regirock[] = _("The Stone Seal");
static const u8 sQuestStartMap_Regirock[] = _("Sealed Chamber");
static const u8 sQuestStart_Regirock[] = _("The Sealed Chamber's message\nechoes through three old ruins.");
static const u8 sQuestDesc_Regirock[] = _("Find Desert Ruins on Route 111.\nBreak its seal for Regirock.");
static const u8 sQuestDone_Regirock[] = _("The stone seal answered.\nRegirock joined the titans.");
static const u8 sQuestMap_Regirock[] = _("Desert Ruins");

static const u8 sQuestName_Regice[] = _("The Frozen Seal");
static const u8 sQuestStartMap_Regice[] = _("Sealed Chamber");
static const u8 sQuestStart_Regice[] = _("The Sealed Chamber's message\nechoes through three old ruins.");
static const u8 sQuestDesc_Regice[] = _("Find Island Cave on Route 105.\nCircle its walls for Regice.");
static const u8 sQuestDone_Regice[] = _("The frozen seal answered.\nRegice joined the titans.");
static const u8 sQuestMap_Regice[] = _("Island Cave");

static const u8 sQuestName_Registeel[] = _("The Iron Seal");
static const u8 sQuestStartMap_Registeel[] = _("Sealed Chamber");
static const u8 sQuestStart_Registeel[] = _("The Sealed Chamber's message\nechoes through three old ruins.");
static const u8 sQuestDesc_Registeel[] = _("Find Ancient Tomb on Route 120.\nShine at its heart for Registeel.");
static const u8 sQuestDone_Registeel[] = _("The iron seal answered.\nRegisteel joined the titans.");
static const u8 sQuestMap_Registeel[] = _("Ancient Tomb");

// ============================= Eon Ticket ==================================

static const u8 sQuestName_EonTicket[] = _("The Eon Couple");
static const u8 sQuestStartMap_EonTicket[] = _("Fortree City");
static const u8 sQuestStart_EonTicket[] = _("A retired Fortree navigator has\nan Eon Ticket.");
static const u8 sQuestDesc_EonTicket[] = _("Take the Eon Ticket to Lilycove's\nferry and sail for Southern Island.");
static const u8 sQuestDone_EonTicket[] = _("On Southern Island, you met the Eon\nPokémon that answered the Ticket.");
static const u8 sQuestMap_EonTicket[] = _("Southern Island");

// ========================== Sealed Chamber prelude =========================

static const u8 sQuestName_SealedChamber[] = _("The Sunken Chamber");
static const u8 sQuestStartMap_SealedChamber[] = _("Route 134");
static const u8 sQuestStart_SealedChamber[] = _("Dive may reveal an ancient chamber\nbeneath Route 134's currents.");
static const u8 sQuestDesc_SealedChamber[] = _("Ride Route 134's currents west.\nDive where calm water hides a trench.");
static const u8 sQuestDone_SealedChamber[] = _("Beneath Route 134, you found the\nancient Sealed Chamber.");
static const u8 sQuestMap_SealedChamber[] = _("Route 134");

#endif // GUARD_QUEST_DATA_H
