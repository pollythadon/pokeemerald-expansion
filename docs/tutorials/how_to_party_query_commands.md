# Party query script commands

## Overview

These are overworld script commands for asking questions about the player's
party from a map script, without writing any C. They pick up where the built-in
`getpartysize` leaves off: instead of only "how many Pokémon do I have", you can
now check for a species, a move, a type, an ability, a held item, a shiny, count
things by species or type, and read a specific slot's level, species or HP.

Every command reports its answer in `VAR_RESULT`, exactly like `getpartysize`
already does, so they slot straight into the `compare` / `goto_if` flow you
already use, and into poryscript `if ()` conditions.

## How the commands hand back their answers

Before the examples, it's worth understanding *where* the answers go, because it
explains every "why did my script do the wrong thing" you might hit.

There are two kinds of storage at play, and both are **shared scratch** — not
private to your script. Every script in the game reuses the same handful. That's
fine and intended; you just have to treat them as short-term.

**`VAR_RESULT`** is the answer slot. Every command here writes its main result
into it (`TRUE`/`FALSE`, a count, a level, and so on). It's the same variable
`yesnobox`, `checkitem`, `getpartysize` and dozens of others use, so it gets
overwritten constantly. Read it right away — never expect it to still hold your
answer after the next command runs.

**`VAR_0x8004`** is a second scratch slot the "check" commands use to hand back
the *party slot* (0–5) of the first match, or `PARTY_SIZE` (6) if nothing
matched. Several other commands write `VAR_0x8004` too (including this pack's own
`getpartymonhp`, which puts max HP there), so if you need the slot, use it before
you run anything else.

**`STR_VAR_1` / `STR_VAR_2` / `STR_VAR_3`** are the three text buffers. You fill
one with a `buffer*` command (like `bufferpartymonnick`) and then insert it into
message text as `{STR_VAR_1}`. They're volatile too: fill one, then use it in the
very next message. Reach for `STR_VAR_2`/`3` only when a single message needs more
than one insert.

The practical rule is about **lifetime**:

| Need the value to last… | Store it in |
| --- | --- |
| just for the next line or two | `VAR_RESULT` / `VAR_0x8004` / `STR_VAR_x` (reuse these freely in every script) |
| for the rest of this map visit | `VAR_TEMP_0`–`VAR_TEMP_F` (cleared on map load) |
| forever, across saves and maps | a free `VAR_UNUSED_*` from `include/constants/vars.h`, or a `FLAG_*` |

If anything runs between setting one of these and using it, copy it out first:

```
checkpartymove(MOVE_SURF)
setvar(VAR_TEMP_0, VAR_0x8004)   // stash the slot before anything else touches VAR_0x8004
```

Otherwise, just reuse `VAR_RESULT`, `VAR_0x8004` and `STR_VAR_1` and don't think
twice — that is exactly what they're for.

## Combining checks with `&&` and `||`

You can chain these in a single `if ()`, and it does the sensible thing even
though every command writes the same `VAR_RESULT`. Poryscript evaluates each
check and branches on its result *before* running the next command, so nothing
gets clobbered — it's the "read it right away" rule applied automatically between
each `&&`.

The classic case is a gate that only opens when the player is carrying several
specific Pokémon at once — like the three golems that awaken Regigigas:

```
script Regigigas_Statue {
	lockall
	if (countpartymon(SPECIES_REGICE) >= 1 && countpartymon(SPECIES_REGIROCK) >= 1 && countpartymon(SPECIES_REGISTEEL) >= 1) {
		msgbox(format("The three golems resonate as one... the ancient titan stirs!"))
		// ... start the encounter here ...
	} else {
		msgbox(format("The statue stands silent. Something is still missing."))
	}
	releaseall
	end
}
```

`&&` short-circuits: the moment one check fails, poryscript jumps past the whole
block without running the rest. `||` is the mirror image — the first check that
passes jumps straight *into* the block:

```
	if (checkpartytype(TYPE_WATER) || checkpartymove(MOVE_SURF)) {
		msgbox(format("One way or another, you can cross this water. Go ahead."))
	}
```

One thing to watch: the "check" commands each overwrite `VAR_0x8004`, so after a
chained condition it holds the slot from the *last* check that ran, not the
first. If you need a particular match's slot, grab it right after that command
(the copy-out tip above), not after the whole `&&` chain.

## Command reference

| Command | Argument | `VAR_RESULT` | `VAR_0x8004` |
| --- | --- | --- | --- |
| `checkpartymon <species>` | a `SPECIES_` constant (or var) | `TRUE` if any party Pokémon is that species, else `FALSE` | slot of the first match, or `PARTY_SIZE` if none |
| `checkpartymove <move>` | a `MOVE_` constant (or var) | `TRUE` if any party Pokémon knows the move, else `FALSE` | slot of the first match, or `PARTY_SIZE` if none |
| `checkpartytype <type>` | a `TYPE_` constant (or var) | `TRUE` if any party Pokémon is that type | slot of the first match, or `PARTY_SIZE` |
| `checkpartyability <ability>` | an `ABILITY_` constant (or var) | `TRUE` if any party Pokémon has that ability | slot of the first match, or `PARTY_SIZE` |
| `checkpartyhelditem <item>` | an `ITEM_` constant (or var) | `TRUE` if any party Pokémon holds that item | slot of the first match, or `PARTY_SIZE` |
| `checkpartyshiny` | none | `TRUE` if any party Pokémon is shiny | slot of the first shiny, or `PARTY_SIZE` |
| `countpartymon <species>` | a `SPECIES_` constant (or var) | number of that species in the party | unused |
| `countpartytype <type>` | a `TYPE_` constant (or var) | number of that type in the party | unused |
| `countalivemons` | none | number of non-egg Pokémon that aren't fainted | unused |
| `countfaintedmons` | none | number of non-egg Pokémon that are fainted | unused |
| `getpartymonlevel <slot>` | slot `0`-`5` | that Pokémon's level, or `0` if the slot is empty | unused |
| `getpartymonspecies <slot>` | slot `0`-`5` | that Pokémon's species (`SPECIES_EGG` for an egg, `SPECIES_NONE` if empty) | unused |
| `getpartymonhp <slot>` | slot `0`-`5` | that Pokémon's current HP, or `0` if empty | that Pokémon's max HP, or `0` if empty |

A few things that apply to all of them:

- Party slots count from zero. The first Pokémon is slot `0`, the last is slot
  `5`. `PARTY_SIZE` is `6`, which is why the "check" commands use it to mean
  "no match".
- The `check` and `count` commands skip eggs and empty slots. The `getpartymon`
  commands read exactly the slot you name, so they report `SPECIES_EGG` for an
  egg and `0` / `SPECIES_NONE` for an empty slot.
- Every argument accepts a plain constant (like `MOVE_SURF`) or a variable (like
  `VAR_TEMP_0`), the same as most other script commands.

## The commands, one by one

Each example is a complete poryscript `script` you can adapt. They all follow the
same shape: run the command, then branch on `VAR_RESULT` (poryscript reads it for
you inside `if ()`).

### `checkpartymon` — is a given species in the party?

The simplest question of the set: is the player carrying this Pokémon at all?
`VAR_0x8004` gives you the slot of the first one, so you can name it. It matches
on the exact species, so an egg reads as `SPECIES_EGG` (not the species it will
hatch into); use `checkpartymon(SPECIES_EGG)` if you specifically want to know
whether the player is carrying *any* egg. It's the yes/no twin of
`countpartymon` — `checkpartymon(SPECIES_PIKACHU)` is the same test as
`countpartymon(SPECIES_PIKACHU) >= 1`, but it also hands you the slot.

```
script OldRival_NPC {
	lockall
	faceplayer
	if (checkpartymon(SPECIES_EEVEE)) {
		bufferpartymonnick(STR_VAR_1, VAR_0x8004)
		msgbox(format("You still have that {STR_VAR_1}?\p"
		              "We each picked one all those years ago. Good memories."))
	} else {
		msgbox(format("An EEVEE can become so many things. Have you raised one?"))
	}
	releaseall
	end
}
```

### `checkpartymove` — does anyone know this move?

Great for field-move gates or a tutor that won't teach a move a Pokémon already
has. `VAR_0x8004` gives you the slot, so you can name the Pokémon.

```
script SurfFerry_Sailor {
	lockall
	faceplayer
	if (checkpartymove(MOVE_SURF)) {
		// use VAR_0x8004 now, before anything else overwrites it
		bufferpartymonnick(STR_VAR_1, VAR_0x8004)
		msgbox(format("Ahoy! That {STR_VAR_1} of yours could carry you across.\p"
		              "Want a lift to the far shore?"), MSGBOX_YESNO)
		if (var(VAR_RESULT) == YES) {
			closemessage
			fadescreen(FADE_TO_BLACK)
			warp(MAP_ROUTE125, 0)   // set to your destination
			waitstate
		}
	} else {
		msgbox(format("These waters are too rough to swim. Come back with a Pokémon that knows Surf."))
	}
	releaseall
	end
}
```

### `checkpartytype` — is anyone this type?

Handy for themed areas or a doorman who only lets a certain type through.

```
script FireShrine_Guardian {
	lockall
	faceplayer
	if (checkpartytype(TYPE_FIRE)) {
		msgbox(format("The flames part for one who travels with fire. Enter."))
		setflag(FLAG_FIRE_SHRINE_OPEN)
	} else {
		msgbox(format("The heat drives you back. Only a trainer with a Fire-type may pass."))
	}
	releaseall
	end
}
```

### `checkpartyability` — does anyone have this ability?

```
script Researcher_Levitate {
	lockall
	faceplayer
	if (checkpartyability(ABILITY_LEVITATE)) {
		bufferpartymonnick(STR_VAR_1, VAR_0x8004)
		msgbox(format("Fascinating... your {STR_VAR_1} floats without a sound.\p"
		              "Here, take this for letting me study it."), MSGBOX_DEFAULT)
		giveitem(ITEM_RARE_CANDY)
	} else {
		msgbox(format("I study Pokémon that defy gravity. Bring me one sometime."))
	}
	releaseall
	end
}
```

### `checkpartyhelditem` — is anyone holding this item?

```
script Collector_Leftovers {
	lockall
	faceplayer
	if (checkpartyhelditem(ITEM_LEFTOVERS)) {
		msgbox(format("Ah, a trainer who lets their partner snack mid-battle. A wise one."))
	} else {
		msgbox(format("A good held item can turn a long battle. Something to think about."))
	}
	releaseall
	end
}
```

### `checkpartyshiny` — is anyone shiny?

```
script ShinyHunter_NPC {
	lockall
	faceplayer
	if (checkpartyshiny()) {
		bufferpartymonnick(STR_VAR_1, VAR_0x8004)
		msgbox(format("Wait... {STR_VAR_1} has an unusual color!\p"
		              "You lucky thing. I've searched years for one of those."))
	} else {
		msgbox(format("I hunt for Pokémon with rare colors. Haven't seen one on you... yet."))
	}
	releaseall
	end
}
```

### `countpartymon` — how many of this species?

Counts copies of one species. For a plain yes/no, `countpartymon(...) >= 1` does the job.

```
script Fisher_MagikarpFan {
	lockall
	faceplayer
	if (countpartymon(SPECIES_MAGIKARP) >= 2) {
		msgbox(format("Two or more MAGIKARP? A trainer after my own heart!"))
		giveitem(ITEM_NUGGET)
	} else {
		msgbox(format("MAGIKARP may look useless, but patience is rewarded. Raise a few!"))
	}
	releaseall
	end
}
```

### `countpartytype` — how many of this type?

```
script BugClub_Doorman {
	lockall
	faceplayer
	if (countpartytype(TYPE_BUG) >= 3) {
		msgbox(format("Three or more Bug-types! You're a true member. Go on in."))
		setflag(FLAG_BUG_CLUB_MEMBER)
	} else {
		msgbox(format("The Bug Club is for the devoted. Come back with at least three Bug-types."))
	}
	releaseall
	end
}
```

### `countalivemons` — how many can still battle?

Non-egg, non-fainted. Good for "are you even able to fight" checks.

```
script Gatekeeper_AbleToBattle {
	lockall
	faceplayer
	if (countalivemons() == 0) {
		msgbox(format("Every Pokémon you have has fainted! I can't let you go on like this.\p"
		              "Rest at the Pokémon Center first."))
	} else {
		msgbox(format("You've got fight left in you. The road ahead is open."))
		setflag(FLAG_GATE_OPEN)
	}
	releaseall
	end
}
```

### `countfaintedmons` — how many have fainted?

```
script FieldMedic_NPC {
	lockall
	faceplayer
	if (countfaintedmons() >= 1) {
		msgbox(format("You look like you've had a rough time out there.\p"
		              "Let me tend to your fainted Pokémon."), MSGBOX_DEFAULT)
		special(HealPlayerParty)
		msgbox(format("There. Good as new. Travel safe."))
	} else {
		msgbox(format("Your team looks healthy. Off you go."))
	}
	releaseall
	end
}
```

### `getpartymonlevel` — what level is the Pokémon in this slot?

Reads the exact slot you name. `0` means the slot is empty.

```
script LevelGate_NPC {
	lockall
	faceplayer
	if (getpartymonlevel(0) < 20) {
		// VAR_RESULT still holds the level here, so buffer it to print the number
		buffernumberstring(STR_VAR_1, VAR_RESULT)
		msgbox(format("Your lead Pokémon is only level {STR_VAR_1}... a little green for what's ahead.\p"
		              "Train up to level 20 and come back."))
	} else {
		msgbox(format("Strong enough. The path is yours."))
		setflag(FLAG_LEVEL_GATE_CLEARED)
	}
	releaseall
	end
}
```

### `getpartymonspecies` — what species is in this slot?

`SPECIES_EGG` if the slot holds an egg, `SPECIES_NONE` if it's empty.

```
script LeadReaction_NPC {
	lockall
	faceplayer
	if (getpartymonspecies(0) == SPECIES_PIKACHU) {
		msgbox(format("A PIKACHU leading the way! Now that's a classic."))
	} elif (getpartymonspecies(0) == SPECIES_NONE) {
		msgbox(format("...You don't seem to have a Pokémon with you at all."))
	} else {
		msgbox(format("A fine Pokémon walking up front. Lead on."))
	}
	releaseall
	end
}
```

### `getpartymonhp` — how hurt is the Pokémon in this slot?

Current HP lands in `VAR_RESULT`, max HP in `VAR_0x8004`, so you can compare the
two to spot a Pokémon that isn't at full health.

```
script WorriedNurse_NPC {
	lockall
	faceplayer
	getpartymonhp(0)
	if (var(VAR_RESULT) == 0) {
		msgbox(format("Your lead Pokémon has fainted! Please, get it to a Center."))
	} elif (var(VAR_RESULT) < var(VAR_0x8004)) {
		// current HP is below max HP
		msgbox(format("Your lead is hurt. Want me to patch it up a little?"))
	} else {
		msgbox(format("Your lead is in perfect shape. Wonderful."))
	}
	releaseall
	end
}
```

## Using them in plain (non-poryscript) scripts

If you write raw `.inc` scripts, it's the same idea — run the command, then
`compare` against `VAR_RESULT`:

```
CanAnyoneSurf::
	lockall
	checkpartymove MOVE_SURF
	compare VAR_RESULT, TRUE
	goto_if_eq CanAnyoneSurf_Yes
	msgbox gText_NoOneCanSurf, MSGBOX_DEFAULT
	releaseall
	end

CanAnyoneSurf_Yes::
	@ VAR_0x8004 is the slot of the Pokémon that knows Surf
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	msgbox gText_ThatMonCanSurf, MSGBOX_DEFAULT
	releaseall
	end
```

Counting and slot-reading work the same way with `compare` and the
`goto_if_ge` / `goto_if_lt` family:

```
	countpartytype TYPE_FIRE
	compare VAR_RESULT, 2
	goto_if_ge TwoOrMoreFireTypes

	getpartymonlevel 0
	compare VAR_RESULT, 50
	goto_if_ge LeadIsStrong
```

## Installing on your own project

This lives on a feature branch. Add the repo it's published from as a remote and
pull it into your project, then rebuild:

```
git remote add partyquery <REPO_URL>
git fetch partyquery
git merge partyquery/party-query-feature
make -j$(nproc)
```

Replace `<REPO_URL>` and the branch name with wherever you're pulling it from.

There is no config switch to flip. Like every other script command, these are
always available once the branch is merged; they cost nothing unless a script
actually calls them. If you use poryscript, no extra step is needed either, as
the command config ships with the branch.
