#ifndef DATATYPES_H
#define DATATYPES_H

// Character
enum Class {
	cleric, fighter, rogue, wizard
};

enum Race {
	dwarf, elf, halfling, human
};

enum Align {
	NeutralGood, NeutralEvil, TrueNeutral, ChaoticGood, ChaoticEvil,
	ChaoticNeutral, LawfulGood, LawfulEvil, LawfulNeutral
};

struct Abilities {
	int str, dex, con, intl, wis, cha;
};

struct AbilMods {
	int str, dex, con, intl, wis, cha;
};

enum DivineDomain {
	Knowledge, Life, Light, Nature, Tempest, Trickery, War
};

// Armor
enum Weight {
	light, medium, heavy, shield
};

enum Stealth {
	disadvantage, advantage, none
};

#endif // DATATYPES_H