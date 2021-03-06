#include <iostream>
#include <string.h>
#include <utility>
#include <vector>
#include <stdlib.h> // srand, rand
#include <algorithm> // sort
#include <iterator> // begin, end, reverse
#include <functional> // hash
#include "Character.h"
#include "Helper.h"

using namespace std;

#define numAbil 6

Character::Character() {
	//height, weight, age, speed, level, exp, initiative = 0;
	//memset(stats, 0, sizeof(stats));
	//memset(savingThrows, 0, sizeof(savingThrows));

	size = "small";
	//deity = "";
	name = "Joe Schmo";
	charRace = human;
	charClass = cleric;
	charAlign = LawfulGood;
	charAbils.str = 0;
	charAbils.dex = 0;
	charAbils.con = 0;
	charAbils.intl = 0;
	charAbils.wis = 0;
	charAbils.cha = 0;

	mods.str = 0;
	mods.dex = 0;
	mods.con = 0;
	mods.intl = 0;
	mods.wis = 0;
	mods.cha = 0;
	
	AC = 0;
	speed = 0;

	selName();
	selAlign();
	//setLevel();
	selRace();
	selClass(); //should set hitdice/hp  too
	//proficiencies should be set somewhere in here
	setAbilities();
	calcMods();
	//setArmor();
	//setWeapons();
	//setEquipment();
}

Character::Character(const string nam) {
	size = "small";
	deity = "";
	name = nam;
	charRace = human;
	charClass = cleric;
	charAlign = LawfulGood;
	charAbils.str = 0;
	charAbils.dex = 0;
	charAbils.con = 0;
	charAbils.intl = 0;
	charAbils.wis = 0;
	charAbils.cha = 0;

	mods.str = 0;
	mods.dex = 0;
	mods.con = 0;
	mods.intl = 0;
	mods.wis = 0;
	mods.cha = 0;
	AC = 0;
	speed = 0;
}

Align Character::getAlign() const {
	return charAlign;
}

void Character::selAlign() {
	cout << "Select a number corresponding with a alignment." << endl;
	cout << "1. Neutral Good   2. Neutral Evil   3. True Neutral" << endl
		  << "4. Chaotic Good   5. Chaotic Evil   6. Chaotic Neutral" << endl
		  << "7. Lawful Good    8. Lawful Evil    9. Lawful Neutral" << endl
		  << ": ";
	charAlign = (Align) (getNum(((int) NeutralGood) + 1, ((int) LawfulNeutral) + 1) - 1);
}

void Character::setAlign(const Align& a) {
	charAlign = a;
}

Class Character::getClass() const {
	return charClass;
}

void Character::selClass() {
	cout << "Select a number corresponding with a class." << endl
		  << "1. Cleric      2. Fighter\n"
		  << "3. Rogue       4. Wizard\n: ";
	setClass((Class) (getNum(((int) cleric) + 1, ((int) wizard) + 1) - 1));
}

void Character::setClass(const Class c) {
	charClass = c;
	switch (c) {
	case cleric:
		hitDie = 8;
		hp = 8 + mods.con;
		cantrips = 3;
		spellslots = mods.wis + level;
		spellsknown = 2;
		break;
	case fighter:
		hitDie = 10;
		hp = 10 + mods.con;
		break;
	case rogue:
		hitDie = 8;
		break;
	case wizard:
		hitDie = 6;
		break;
	default:
		hitDie = 0;
		cout << "Class not found; Hit Die set to 0" << endl;
		break;
	}
}

Race Character::getRace() const {
	return charRace;
}

void Character::selRace() {
	cout << "Select a number corresponding with a race." << endl
		  << "1. Dwarf      2. Elf\n"
		  << "3. Hafling    4. Human\n: ";
	setRace((Race) (getNum(((int) dwarf) + 1, ((int) human) + 1) - 1));
}

void Character::setRace(const Race r) {
	//What if we set height and weight ranges by height, and user input has to fall in that range?
	charRace = r;
	switch (r) {
	case dwarf:
		size = "Medium";
		//cout << "1. Hill Dwarf /n2. Mountain Dwarf"; // FIXME? Should this be an input... in the set?
		speed = 25; //note that this is not reduced when dwarves wear heavy armor
		charAbils.con += 2; //increase con by 2
		break;
	case elf:
		size = "Medium";
		speed = 30;
		charAbils.dex += 2; //increase dex by 2
		break;
	case halfling:
		size = "Small";
		speed = 25;
		charAbils.dex += 2; //increase dex by 2
		break;
	case human:
		size = "Medium";
		speed = 30;
		charAbils.str += 1;
		charAbils.dex += 1;
		charAbils.con += 1;
		charAbils.intl += 1;
		charAbils.wis += 1;
		charAbils.cha += 1;
		break;
	}
}

string Character::getName() const {
   return name;
}

void Character::selName() {
	cout << "Character name: " << endl;
	getline(cin, name);
}

int Character::getHitDie() const {
	return hitDie;
}

int Character::getStat(const AbilTypes abil) const {
	// Initialize the sum to the base value
	int sum = ((int *) &charAbils.str)[(int) abil];

	// If nothing is equipped we don't need to check
	if (equipped.items.size() < 1) {
		return sum;
	}

	// Add up all item bonuses that apply to the desired stat
	for (auto const it : equipped.items) {
		sum += it.getBonus(abil);
	}
	return sum;
}

void Character::calcMods() { //this is beautiful. do not touch. Sorry -Berk
	for (int x = 0; x < numAbil; x++) {
		((int *) &mods.str)[x] = (((int *) &charAbils.str)[x] / 2) - 5;
	} // I touched it, sosume.
}

void Character::setAbilities() {
	array<int, numAbil> tempScores {{0}};
	genAbilities(tempScores.data());
	// genAbilities returns a random order, sort largest to smallest
	sort(begin(tempScores), end(tempScores));
	reverse(begin(tempScores), end(tempScores));
	// Assign the abilities to the desired slots
	setAbilitiesHelper(tempScores.data());
}

void Character::genAbilities(int * tempScores) const {
	int total, roll, smallest;
	for (int i = 0; i < numAbil; i++) {
		total = 0;
		for (int j = 0; j < 4; j++) { //Rolls the four d6 and adds them  together
			roll = rollDice(1, 6);
			total += roll;
			if (j == 0) { //Keeps track of smallest value
				smallest = roll; //Sets smallest to the first value in first run
			} else if (roll < smallest) {
				smallest = roll;
			}
		}
		tempScores[i] = total - smallest;
	}
}

void Character::setAbilitiesHelper(const int * tempScores) {
	//VARIABLES
	bool isSet[6];
	string sele;
	int sel;
	bool done = false;
	int printed;
	int toPrint;

	for (int x = 0; x < numAbil; x++) {
		isSet[x] = false;
	}

	while (done != true) {
		for (int m = 0; m < numAbil; m++) {
			printed = 0;
			toPrint = 0;
			for (int i = 0; i < numAbil; i++) {
				if (!isSet[i]) {
					toPrint++;
				}
			}
			cout << "Available scores: (";
			// Print these out sorted?
			for (int l = m; l < numAbil; l++) {
				cout << tempScores[l] << ((l < numAbil - 1) ? ", " : "");
			}
			cout << "), Where do you want " << tempScores[m] << " to go?" << endl;
			for (int n = 0; n < numAbil; n++) {
				if (!isSet[n]) {
					cout << "  " << (n +1) << " - " << getAbility(n);
					printed++;
					if (printed % 3 == 0 || printed == toPrint) {
						// Every 3 abilities, or at the end of the ones we are printing
						cout << endl;
					}
				}
			}
			cout << ": ";
			sel = getNum(1, numAbil);
			sel--; // Turn input into an index number
			if (isSet[sel] == false) {
				isSet[sel] = true;
				switch (sel) {
				case 0:
					charAbils.str += tempScores[m];
					isSet[0] = true;
					break;
				case 1:
					charAbils.dex += tempScores[m];
					isSet[1] = true;
					break;
				case 2:
					charAbils.con += tempScores[m];
					isSet[2] = true;
					break;
				case 3:
					charAbils.intl += tempScores[m];
					isSet[3] = true;
					break;
				case 4:
					charAbils.wis += tempScores[m];
					isSet[4] = true;
					break;
				case 5:
					charAbils.cha += tempScores[m];
					isSet[5] = true;
					break;
				default:
					break;
				}
			} else {
				// Something went wrong, we always want to retry the selection.
				m--;
				if (isSet[sel] == true) {
					cout << "Value already set" << endl;
				} else {
					cout << "Value '" << sel << "' not recognized" << endl;
				}
			}
		}
		done = true;
	}
}

string Character::getAbility(const int num) const {
	switch (num) {
	case 0:
		return "str";
		break;
	case 1:
		return "dex";
		break;
	case 2:
		return "con";
		break;
	case 3:
		return "int";
		break;
	case 4:
		return "wis";
		break;
	case 5:
		return "cha";
		break;
	default:
		return "Unrecognized value";
		break;
	}
}

void Character::printAbilities() const {
	cout << "Str: " << getStat(str) << " (" << mods.str << ")"
		<< "		Dex: " << getStat(dex) << " (" << mods.dex << ")"
		<< "		Con: " << getStat(con) << " (" << mods.con << ")" << endl;
	cout << "Int: " << getStat(intl) << " (" << mods.intl << ")"
		<< "		Wis: " << getStat(wis) << " (" << mods.wis << ")"
		<< "		Cha: " << getStat(cha) << " (" << mods.cha << ")" << endl;
}

void Character::printCharacter() const {
	cout << name << endl
		  << "Race: " << printRace(charRace, true)
		  << "		Class: " << printClass(charClass, true)
		  << "		Alignment: " << printAlign(charAlign, true) << endl;
	printAbilities();
	cout << "AC: " << AC << "   Speed: " << speed << endl;
	backpack.printContainer();
	equipped.printContainer();
}

void Character::printCharNames(const vector<Character>& charList) {
	for (auto const it: charList) {
		cout << it.getName() << endl;
	}
}