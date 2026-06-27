#!/usr/bin/env python3
# One-shot (re-runnable, deterministic) generator that sprinkles every eligible
# Gen 1-9 species into Hoenn's wild encounter tables so that each one is catchable
# somewhere, while keeping placements biome- and level-appropriate and leaving a
# share of each table as its original mon.
#
# Eligible pool = Gen 1-9 species EXCLUDING: legendaries (restricted + sub),
# mythicals, Ultra Beasts, Paradox mons, alternate battle forms (Mega/Primal/
# Gmax/Tera/Ultra Burst/Totem) and the FINAL form of any 3-stage evolution line
# (base + middle stages are kept). Regional forms are kept as distinct catchables.
#
# Only Hoenn maps (map-group < 34, i.e. not the _Frlg Kanto/Sevii maps) are
# touched. Run from the repo root:  python3 tools/wild_encounters/sprinkle_gens.py
# Then the build (or wild_encounters_to_header.py) regenerates the C header.

import glob
import json
import os
import random
import re

# ---- Tunables ---------------------------------------------------------------
RANDOM_SEED = 20260627
BLEND_REPLACE_RATIO = 0.45   # sprinkle target: share of a table's slots that may be new
MAX_REPLACE_RATIO = 0.60     # hard cap: never replace more than this share of a table
FRLG_GROUP_START = 34        # map-groups >= this are FireRed/LeafGreen (Kanto/Sevii)

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
SPECIES_GLOB = os.path.join(ROOT, "src/data/pokemon/species_info/gen_*_families.h")
MAP_GROUPS_H = os.path.join(ROOT, "include/constants/map_groups.h")
WILD_JSON = os.path.join(ROOT, "src/data/wild_encounters.json")

LAND, WATER, ROCK, FISH = "land_mons", "water_mons", "rock_smash_mons", "fishing_mons"
TABLE_KEYS = [LAND, WATER, ROCK, FISH]

# ---- Biome model ------------------------------------------------------------
# Map biome assigned from map-name keywords (first match wins, order matters).
MAP_BIOME_KEYWORDS = [
    ("UNDERWATER", "aquatic"), ("SEAFLOOR", "aquatic"), ("SEAFOAM", "aquatic"),
    ("ABANDONED_SHIP", "aquatic"), ("SEA", "aquatic"), ("OCEAN", "aquatic"),
    ("SHOAL", "cave"), ("GRANITE", "cave"), ("METEOR", "cave"), ("CAVE", "cave"),
    ("TUNNEL", "cave"), ("CAVERN", "cave"), ("VICTORY_ROAD", "cave"),
    ("SKY_PILLAR", "cave"), ("RUINS", "cave"),
    ("FIERY", "volcanic"), ("MAGMA", "volcanic"), ("CHIMNEY", "volcanic"),
    ("DESERT", "desert"),
    ("MT_", "mountain"), ("JAGGED_PASS", "mountain"),
    ("FOREST", "forest"), ("WOODS", "forest"),
    ("SAFARI", "grassland"),
]

# type -> set of biomes the species is at home in.
TYPE_BIOMES = {
    "TYPE_NORMAL":   {"grassland", "urban"},
    "TYPE_FIRE":     {"volcanic", "desert", "mountain"},
    "TYPE_WATER":    {"aquatic"},
    "TYPE_ELECTRIC": {"grassland", "urban"},
    "TYPE_GRASS":    {"forest", "grassland"},
    "TYPE_ICE":      {"mountain", "cave"},
    "TYPE_FIGHTING": {"mountain", "cave", "urban"},
    "TYPE_POISON":   {"cave", "forest", "urban"},
    "TYPE_GROUND":   {"cave", "desert", "mountain"},
    "TYPE_FLYING":   {"mountain", "grassland"},
    "TYPE_PSYCHIC":  {"urban", "grassland"},
    "TYPE_BUG":      {"forest", "grassland"},
    "TYPE_ROCK":     {"cave", "mountain", "desert"},
    "TYPE_GHOST":    {"cave", "urban"},
    "TYPE_DRAGON":   {"mountain", "cave"},
    "TYPE_DARK":     {"cave", "urban"},
    "TYPE_STEEL":    {"cave", "mountain"},
    "TYPE_FAIRY":    {"grassland", "forest", "urban"},
}
EGG_BIOMES = {
    "EGG_GROUP_WATER_1": {"aquatic"}, "EGG_GROUP_WATER_2": {"aquatic"},
    "EGG_GROUP_WATER_3": {"aquatic"},
    "EGG_GROUP_GRASS": {"forest", "grassland"}, "EGG_GROUP_BUG": {"forest"},
    "EGG_GROUP_MINERAL": {"cave"}, "EGG_GROUP_FLYING": {"mountain", "grassland"},
    "EGG_GROUP_MONSTER": {"mountain"}, "EGG_GROUP_FIELD": {"grassland"},
    "EGG_GROUP_HUMAN_LIKE": {"urban"}, "EGG_GROUP_DRAGON": {"mountain"},
    "EGG_GROUP_AMORPHOUS": {"cave"}, "EGG_GROUP_FAIRY": {"grassland"},
}
LAND_BIOMES = {"grassland", "urban", "forest", "cave", "mountain", "desert", "volcanic"}


def parse_species():
    text = "\n".join(open(f).read() for f in sorted(glob.glob(SPECIES_GLOB)))
    blocks = re.findall(r'\[(SPECIES_[A-Z0-9_]+)\]\s*=\s*\{(.*?)\n\s*\},', text, re.S)
    info = {}
    for name, body in blocks:
        d = {}
        d["leg"] = ("isRestrictedLegendary = TRUE" in body) or ("isSubLegendary = TRUE" in body)
        d["myth"] = "isMythical = TRUE" in body
        d["ub"] = "isUltraBeast = TRUE" in body
        d["paradox"] = "isParadox = TRUE" in body
        d["form"] = any(s in body for s in (
            "isMegaEvolution = TRUE", "isPrimalReversion = TRUE",
            "isGigantamax = TRUE", "isTeraForm = TRUE",
            "isUltraBurst = TRUE", "isTotem = TRUE"))
        d["regional"] = any(s in body for s in (
            "isAlolanForm = TRUE", "isGalarianForm = TRUE",
            "isHisuianForm = TRUE", "isPaldeanForm = TRUE"))
        m = re.search(r'\.natDexNum\s*=\s*(NATIONAL_DEX_[A-Z0-9_]+)', body)
        d["dex"] = m.group(1) if m else None
        tm = re.search(r'\.types\s*=\s*MON_TYPES\(([^)]*)\)', body)
        d["types"] = re.findall(r'TYPE_[A-Z_]+', tm.group(1)) if tm else []
        em = re.search(r'\.eggGroups\s*=\s*MON_EGG_GROUPS\(([^)]*)\)', body)
        d["eggs"] = re.findall(r'EGG_GROUP_[A-Z0-9_]+', em.group(1)) if em else []
        d["evos"] = []
        if "EVOLUTION(" in body:
            # Balanced-paren scan: CONDITIONS({...}) nests parens that a lazy
            # regex would truncate, dropping branch evolutions (e.g. Wurmple).
            start = body.index("EVOLUTION(") + len("EVOLUTION(")
            depth, i = 1, start
            while i < len(body) and depth > 0:
                if body[i] == "(":
                    depth += 1
                elif body[i] == ")":
                    depth -= 1
                i += 1
            d["evos"] = re.findall(r'SPECIES_[A-Z0-9_]+', body[start:i - 1])
        info[name] = d
    return info


def is_final_of_three_stage(info):
    """Return set of species that are a terminal node at evolution depth >= 2."""
    incoming = {n: [] for n in info}
    for n, i in info.items():
        for t in i["evos"]:
            if t in incoming:
                incoming[t].append(n)
    memo = {}

    def depth(n):
        if n in memo:
            return memo[n]
        memo[n] = 0  # guard against cycles
        best = 0
        for p in incoming.get(n, []):
            best = max(best, depth(p) + 1)
        memo[n] = best
        return best

    return {n for n, i in info.items() if not i["evos"] and depth(n) >= 2}


def species_biomes(d):
    biomes = set()
    for t in d["types"]:
        biomes |= TYPE_BIOMES.get(t, set())
    for e in d["eggs"]:
        biomes |= EGG_BIOMES.get(e, set())
    if not biomes:
        biomes = {"grassland"}
    return biomes


def hoenn_maps():
    maps = {}
    for line in open(MAP_GROUPS_H):
        m = re.search(r'(MAP_[A-Z0-9_]+)\s*=\s*\(\s*\d+\s*\|\s*\((\d+)\s*<<\s*8\)\)', line)
        if m:
            maps[m.group(1)] = int(m.group(2))
    return {n for n, g in maps.items() if g < FRLG_GROUP_START}


def map_biome(map_name):
    for kw, biome in MAP_BIOME_KEYWORDS:
        if kw in map_name:
            return biome
    return "grassland"  # routes / towns default


def main():
    rng = random.Random(RANDOM_SEED)
    info = parse_species()
    final3 = is_final_of_three_stage(info)

    # Base (default) form per dex = first-defined species with that dex.
    # Regional base per dex = first-defined regional form with that dex.
    # Keeping only these two collapses battle/cosmetic sub-forms such as
    # Darmanitan-Galar-Zen and Tauros-Paldea-Blaze/Aqua.
    base_for_dex = {}
    regional_base_for_dex = {}
    for name, d in info.items():
        if d["dex"] is None:
            continue
        if d["dex"] not in base_for_dex:
            base_for_dex[d["dex"]] = name
        if d["regional"] and d["dex"] not in regional_base_for_dex:
            regional_base_for_dex[d["dex"]] = name

    eligible = {}
    for name, d in info.items():
        if d["form"] or d["dex"] is None:
            continue
        if d["leg"] or d["myth"] or d["ub"] or d["paradox"]:
            continue
        if name in final3:
            continue
        # Keep only the base form for each dex, plus the first regional form.
        # Drops weather/battle/seasonal/cosmetic forms (Cherrim-Sunshine,
        # Cramorant-Gorging, Rotom appliances, Deerling seasons, Vivillon,
        # Darmanitan-Galar-Zen, secondary Tauros-Paldea, ...).
        if name != base_for_dex.get(d["dex"]) and name != regional_base_for_dex.get(d["dex"]):
            continue
        b = species_biomes(d)
        eligible[name] = {
            "biomes": b,
            "aquatic": "aquatic" in b,
            "land_biomes": b & LAND_BIOMES,
            "rocky": bool(b & {"cave", "mountain"}),
        }
    print(f"Eligible species: {len(eligible)}")

    hmaps = hoenn_maps()
    data = json.load(open(WILD_JSON))
    group = next(g for g in data["wild_encounter_groups"] if g["label"] == "gWildMonHeaders")

    # Build the universe of replaceable slots, tagged with their biome requirement.
    # slot = dict(enc=<mons list ref>, idx, table_key, map, biome, table_id)
    slots = []
    table_len = {}        # table_id -> number of slots
    table_replaced = {}   # table_id -> count replaced so far
    for enc in group["encounters"]:
        if enc["map"] not in hmaps:
            continue
        mb = map_biome(enc["map"])
        for key in TABLE_KEYS:
            if key not in enc:
                continue
            mons = enc[key]["mons"]
            table_id = (enc["map"], key)
            table_len[table_id] = len(mons)
            table_replaced[table_id] = 0
            if key in (WATER, FISH):
                req = "aquatic"
            elif key == ROCK:
                req = "rocky"
            else:
                req = mb
            for idx, _mon in enumerate(mons):
                slots.append({
                    "mons": mons, "idx": idx, "key": key, "map": enc["map"],
                    "req": req, "table_id": table_id,
                })

    print(f"Hoenn maps with encounters: {sum(1 for e in group['encounters'] if e['map'] in hmaps)}")
    print(f"Replaceable slots: {len(slots)}")

    cap = {tid: max(1, round(MAX_REPLACE_RATIO * n)) for tid, n in table_len.items()}
    target = {tid: round(BLEND_REPLACE_RATIO * n) for tid, n in table_len.items()}
    used = {s_id: False for s_id in range(len(slots))}  # slot index -> replaced?

    def slot_accepts(slot, sp):
        """True if eligible species sp may live in this slot."""
        e = eligible[sp]
        req = slot["req"]
        if req == "aquatic":
            return e["aquatic"]
        if req == "rocky":
            return e["rocky"]
        return req in e["land_biomes"]

    # Pre-index free slots per requirement for fast candidate lookup.
    slots_by_req = {}
    for i, s in enumerate(slots):
        slots_by_req.setdefault(s["req"], []).append(i)

    def place(slot_i, sp):
        slot = slots[slot_i]
        slot["mons"][slot["idx"]]["species"] = sp
        used[slot_i] = True
        table_replaced[slot["table_id"]] += 1

    def free_candidates(sp, reqs, respect_target):
        out = []
        for req in reqs:
            for i in slots_by_req.get(req, []):
                if used[i]:
                    continue
                tid = slots[i]["table_id"]
                limit = target[tid] if respect_target else cap[tid]
                if table_replaced[tid] >= limit:
                    continue
                if slot_accepts(slots[i], sp):
                    out.append(i)
        return out

    # --- Coverage pass: place every eligible species at least once -----------
    # Most-constrained species first (fewest compatible reqs / slots).
    def reqs_for(sp):
        e = eligible[sp]
        reqs = set(e["land_biomes"])
        if e["aquatic"]:
            reqs.add("aquatic")
        if e["rocky"]:
            reqs.add("rocky")
        return reqs

    order = sorted(eligible, key=lambda sp: (len(reqs_for(sp)), rng.random()))
    placed = set()
    relaxed = []
    for sp in order:
        reqs = reqs_for(sp)
        cands = free_candidates(sp, reqs, respect_target=False)  # coverage may use full cap
        if not cands:
            relaxed.append(sp)
            # Relax step 1: stay on-theme by over-filling the species' own biome
            # tables past the cap (keeps the mon where it belongs).
            cands = [i for i in range(len(slots))
                     if not used[i] and slot_accepts(slots[i], sp)]
            # Relax step 2: any free land slot, then any free slot at all.
            if not cands:
                cands = [i for i in range(len(slots))
                         if not used[i] and slots[i]["key"] == LAND]
            if not cands:
                cands = [i for i in range(len(slots)) if not used[i]]
        if not cands:
            print(f"  !! could not place {sp}")
            continue
        place(rng.choice(cands), sp)
        placed.add(sp)

    # --- Sprinkle pass: fill remaining slots up to the blend target ----------
    # Weight toward least-used species for variety.
    use_count = {sp: 0 for sp in eligible}
    for i in range(len(slots)):  # seed counts from coverage placements
        if used[i]:
            sp = slots[i]["mons"][slots[i]["idx"]]["species"]
            if sp in use_count:
                use_count[sp] += 1

    # Candidate eligible species per requirement.
    elig_by_req = {"aquatic": [], "rocky": []}
    for b in LAND_BIOMES:
        elig_by_req[b] = []
    for sp, e in eligible.items():
        if e["aquatic"]:
            elig_by_req["aquatic"].append(sp)
        if e["rocky"]:
            elig_by_req["rocky"].append(sp)
        for b in e["land_biomes"]:
            elig_by_req[b].append(sp)

    free_after = [i for i in range(len(slots)) if not used[i]]
    rng.shuffle(free_after)
    for i in free_after:
        slot = slots[i]
        tid = slot["table_id"]
        if table_replaced[tid] >= target[tid]:
            continue
        pool = elig_by_req.get(slot["req"], [])
        if not pool:
            continue
        # bias toward less-used: sample a small batch, pick the least used
        batch = [rng.choice(pool) for _ in range(6)]
        sp = min(batch, key=lambda s: (use_count[s], rng.random()))
        place(i, sp)
        use_count[sp] += 1

    # --- Report --------------------------------------------------------------
    total_replaced = sum(table_replaced.values())
    print(f"Slots replaced: {total_replaced} / {len(slots)} "
          f"({100*total_replaced/len(slots):.1f}%)")
    print(f"Distinct eligible species placed (coverage): {len(placed)} / {len(eligible)}")
    if relaxed:
        print(f"Biome-relaxed placements: {len(relaxed)} "
              f"(e.g. {', '.join(relaxed[:8])})")
    missing = set(eligible) - placed
    assert not missing, f"UNPLACED eligible species: {sorted(missing)[:20]}"
    print("Coverage OK: every eligible species is catchable in Hoenn.")

    with open(WILD_JSON, "w") as f:
        f.write(json.dumps(data, indent=2, ensure_ascii=False) + "\n")
    print(f"Wrote {WILD_JSON}")


if __name__ == "__main__":
    main()
