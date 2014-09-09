#include <iostream>
#include <string>
#include <stdio.h>
#include "Item.h"
#include "Helper.h"

using namespace std;

string Item::getDescription() const {
	return description;
}

void Item::editDescription(const string s) {
	description = s;
}

void Item::editLocation(const string s) {
	location = s;
}

void Item::printInfo() const {
	cout << name << endl << description << endl
		 << weight << " lbs" << endl
		 << "Location: " << location << endl;
}

Item::Item() {
	cout << "Name?" << endl;
	getline(cin, name);
	cout << "Description?" << endl;
	getline(cin,description);
	cout << "Weight?" << endl;
	weight = getNum<double>();
	cout << "Location?" << endl;
	getline(cin,location);
}

Item::Item(const string nam){
	name = nam;
	description = "tested shit";
	weight = 2500;
	location = "places unknown";
}

Item::Item(const string n, const string des, const string loc, const double w) {
	name = n;
	description = des;
	location = loc;
	weight = w;
}

int Item::getWeight() const {
	return weight;
}

string Item::getName() const {
	return name;
}

int Item::getBonus(const AbilTypes& checkAbil) const {
	vector<AbilBonus>::const_iterator it = bonuses.begin();
	int sum = 0;
	for (int i = 0; i < bonuses.size(); i++) {
		if (it->abil == checkAbil) {
			sum += it->bonus;
		}
		it++;
	}
	return sum;
}

void Item::addBonus(const AbilBonus newAbilBonus) {
	bonuses.push_back(newAbilBonus);
}

void Item::addBonus(const AbilTypes& at, const int& bon, const string& nam,
					const string& desc) {
	AbilBonus ab = {at, bon, nam, desc};
	bonuses.push_back(ab);
}

bool Item::removeBonus(const AbilBonus& checkAbil) {
	vector<AbilBonus>::iterator it = bonuses.begin();
	for (int i = 0; i < bonuses.size(); i++) {
		if (eqAbilBonus(*it, checkAbil)) {
			bonuses.erase(it);
			return true;
		}
		it++;
	}
	return false;
}