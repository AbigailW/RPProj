#include <iostream>
#include <string>
#include <stdio.h>
#include "Item.h"
#include "Helper.h"

using namespace std;

Item::Item() {
	cout << "Name?" << endl;
	getline(cin, name);
	cout << "Description?" << endl;
	getline(cin,description);
	cout << "Weight?" << endl;
	weight = getNum<double>();
}

Item::Item(const string nam) {
	name = nam;
	description = "tested shit";
	weight = 2500;
}

Item::Item(const string n, const string des, const double w) {
	name = n;
	description = des;
	weight = w;
}

bool Item::operator==(const Item& oth) const {
	if (this->weight == oth.weight
		&& this->name == oth.name
		&& this->description == oth.description)
	{
		int found = 0;
		for (const auto i : this->bonuses) {
			for (const auto j : oth.bonuses) {
				if (i == j) {
					found++;
				}
			}
		}
		return (found == this->bonuses.size()); // Doesn't handle duplicates
	}
	return false;
}

bool Item::operator!=(const Item& oth) const {
	return !(*this == oth);
}

void Item::printInfo() const {
	cout << name << endl << description << endl
		 << weight << " lbs" << endl;
	if (bonuses.size() > 0) {
		for (const auto i: bonuses) {
			cout << "Bonus: " << (int) i.abil << " " << i.bonus << endl;
		}
	}
}

int Item::getWeight() const {
	return weight;
}

string Item::getName() const {
	return name;
}

string Item::getDescription() const {
	return description;
}

void Item::setDescription(const string s) {
	description = s;
}

void Item::addBonus() {
	AbilBonus newAbilBonus;
	cout << "New item bonus:" << endl
		<< "Which score does the bonus change?" << endl
		<< "1. Str   2. Dex   3. Con" << endl
		<< "4. Int   5. Wis   6. Cha" << endl;
	newAbilBonus.abil = (AbilTypes) (getNum(((int) str) + 1, ((int) cha) + 1) - 1);
	cout << "Bonus amount: ";
	newAbilBonus.bonus = getNum<int>();
	bonuses.push_back(newAbilBonus);
}

void Item::addBonus(const AbilBonus newAbilBonus) {
	bonuses.push_back(newAbilBonus);
}

void Item::addBonus(const AbilTypes& at, const int& bon) {
	AbilBonus ab = {at, bon};
	bonuses.push_back(ab);
}

bool Item::removeBonus(const AbilBonus& checkAbil) {
	vector<AbilBonus>::iterator it = bonuses.begin();
	for (int i = 0; i < bonuses.size(); i++) {
		if (*it == checkAbil) { //eqAbilBonus
			bonuses.erase(it);
			return true;
		}
		it++;
	}
	return false;
}

int Item::getBonus(const AbilTypes& checkAbil) const {
	int sum = 0;
	for (auto const it: bonuses) {
		if (it.abil == checkAbil) {
			sum += it.bonus;
		}
	}
	return sum;
}