#include <string>
#include "DataTypes.h"

using namespace std;

bool AbilBonus::operator==(const AbilBonus& oth) const {
	return (abil == oth.abil && bonus == oth.bonus);
}

bool AbilBonus::operator!=(const AbilBonus& oth) const {
	return !(abil == oth.abil && bonus == oth.bonus);
}

bool Abilities::operator==(const Abilities& oth) const {
	return (str == oth.str && dex == oth.dex && con == oth.con
			&& intl == oth.intl && wis == oth.wis && cha == oth.cha);
}

bool Abilities::operator!=(const Abilities& oth) const {
	return (str != oth.str && dex != oth.dex && con != oth.con
			&& intl != oth.intl && wis != oth.wis && cha != oth.cha);
}

string printAlign(const Align& a, const bool cap) {
	switch (a) {
		case NeutralGood:
			return (string) (cap ? "N" : "n") + "eutral " + (cap ? "G" : "g") + "ood";
			break;
		case NeutralEvil:
			return (string) (cap ? "N" : "n") + "eutral " + (cap ? "E" : "e") + "vil";
			break;
		case TrueNeutral:
			return (string) (cap ? "T" : "t") + "rue " + (cap ? "N" : "n") + "eutral";
			break;
		case ChaoticGood:
			return (string) (cap ? "C" : "c") + "haotic " + (cap ? "G" : "g") + "ood";
			break;
		case ChaoticEvil:
			return (string) (cap ? "C" : "c") + "haotic " + (cap ? "E" : "e") + "vil";
			break;
		case ChaoticNeutral:
			return (string) (cap ? "C" : "c") + "haotic " + (cap ? "N" : "n") + "eutral";
			break;
		case LawfulGood:
			return (string) (cap ? "L" : "l") + "awful " + (cap ? "G" : "g") + "ood";
			break;
		case LawfulEvil:
			return (string) (cap ? "L" : "l") + "awful " + (cap ? "E" : "e") + "vil";
			break;
		case LawfulNeutral:
			return (string) (cap ? "L" : "l") + "awful " + (cap ? "N" : "n") + "eutral";
			break;
		default:
			return "Unknown!";
			break;
	}
}

string printRace(const Race& r, const bool cap) {
	switch (r) {
		case dwarf:
			return (string) (cap ? "D" : "d") + "warf";
			break;
		case elf:
			return (string) (cap ? "E" : "e") + "lf";
			break;
		case halfling:
			return (string) (cap ? "H" : "h") + "afling";
			break;
		case human:
			return (string) (cap ? "H" : "h") + "uman";
			break;
		default:
			return "Unknown!";
			break;
	}
}

string printClass(const Class& c, const bool cap) {
	switch (c) {
		case cleric:
			return (string) (cap ? "C" : "c") + "leric";
			break;
		case fighter:
			return (string) (cap ? "F" : "f") + "ighter";
			break;
		case rogue:
			return (string) (cap ? "R" : "r") + "ogue";
			break;
		case wizard:
			return (string) (cap ? "W" : "w") + "izard";
			break;
		default:
			return "Unknown!";
			break;
	}
}

string printWeight(const Weight& w, const bool cap) {
	switch (w) {
		case light:
			return (string) (cap ? "L" : "l") + "ight"; break;
		case medium:
			return (string) (cap ? "M" : "m") + "edium"; break;
		case heavy:
			return (string) (cap ? "H" : "h") + "eavy"; break;
		case shield:
			return (string) (cap ? "S" : "s") + "hield"; break;
		default:
			return "unknown"; break;
	}
}

string printStealth(const Stealth& s, const bool cap) {
	switch (s) {
		case disadvantage:
			return (string) (cap ? "D" : "d") + "isadvantage"; break;
		case advantage:
			return (string) (cap ? "A" : "a") + "dvantage"; break;
		case none:
			return (string) (cap ? "N" : "n") + "one"; break;
		default:
			return "Unknown"; break;
	}
}
