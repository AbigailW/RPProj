#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <vector>
#include "Item.h"
#include "Armor.h"
#include "Helper.h"

using namespace std;

void Armor::printInfo() const {
	Item::printInfo();
	cout << printArmorWeight(true) << " armor" << endl
		 << "Stealth: " << printStealth() << endl
		 << "AC: " << AC
		 << "    Strength Requirement: " << strReq
		 << endl;
}

string Armor::printArmorWeight(const bool cap) const {
	switch (armorWeight) {
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

string Armor::printStealth(const bool cap) const {
	switch (armorStealth) {
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

Armor::Armor() {
	cout << "Armor weight? 1 - light, 2 - medium, 3 - heavy, 4 - shield" << endl;
	armorWeight = (Weight) (getNum(((int) light) + 1, ((int) shield) + 1) - 1);
	cout << "Steal benefits? 1 - disadvantage, 2 - advantage, or 3 - none" << endl;
	armorStealth = (Stealth) (getNum(((int) disadvantage) + 1, ((int) none) + 1) - 1);
	cout << "Armor class?" << endl;
	AC = getNum<int>();
	cout << "Strength requirements?" << endl;
	strReq = getNum<int>();
	cout << endl;
}

Armor::Armor(const Weight aw, const int ACinp, const int str, const Stealth ste,
			 const string n, const string des, const string loc,
			 const double w) {
	name = n;
	description = des;
	weight = w;
	armorWeight = aw;
	AC = ACinp;
	armorStealth = ste;
	strReq = str;
}

void Armor::printArmor(const vector<Armor>& container) {
	for (const auto i : container) {
		cout << i.getName() << endl;
	}
}

bool Armor::operator==(const Armor& oth) const {
	return ((Item) *this == (Item) oth
			&& this->armorWeight == oth.armorWeight
			&& this->armorStealth == oth.armorStealth
			&& this->AC == oth.AC
			&& this->strReq == oth.strReq);
}

bool Armor::operator!=(const Armor& oth) const {
	return !(*this == oth);
}