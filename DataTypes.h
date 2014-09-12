#ifndef DATATYPES_H
#define DATATYPES_H

// Character
enum Class {
	cleric, fighter, rogue, wizard
};
std::string printClass(const Class&, bool capitalize = false);

enum Race {
	dwarf, elf, halfling, human
};
std::string printRace(const Race&, bool capitalize = false);

enum Align {
	NeutralGood, NeutralEvil, TrueNeutral, ChaoticGood, ChaoticEvil,
	ChaoticNeutral, LawfulGood, LawfulEvil, LawfulNeutral
};
std::string printAlign(const Align&, bool capitalize = false);

struct Abilities {
	int str, dex, con, intl, wis, cha;
	bool operator==(const Abilities&) const;
	bool operator!=(const Abilities&) const;
};

enum AbilTypes {
	str, dex, con, intl, wis, cha
};

enum DivineDomain {
	Knowledge, Life, Light, Nature, Tempest, Trickery, War
};

// Item
struct AbilBonus {
	AbilTypes abil;
	int bonus;
	bool operator==(const AbilBonus&) const;
	bool operator!=(const AbilBonus&) const;
};

// Armor
enum Weight {
	light, medium, heavy, shield
};
std::string printWeight(const Weight&, bool capitalize = false);

enum Stealth {
	disadvantage, advantage, none
};
std::string printStealth(const Stealth&, bool capitalize = false);

// Weapon
enum weapGroup {
	simpleMelee, simpleRanged, martialMelee, martialRanged
};

enum damType {
	bludge, pierce, slash
};

#endif // DATATYPES_H