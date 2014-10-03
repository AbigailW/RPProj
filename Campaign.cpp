#include <string>
#include <vector>
#include <iterator>
#include <iostream>

#include "Container.h"
#include "Campaign.h"
#include "Character.h"
#include "Armor.h"
#include "Item.h"
#include "Helper.h"

using namespace std;

Character* Campaign::getCharacter(const std::string nam) {
	std::vector<Character>::iterator it = charList.begin();
	for (int x = 0; x < charList.size(); x++) {
		if (it->getName() == nam) {
			return &(*it);
		}
		it++;
	}
	cout << "Could not find character" << endl;
	return NULL;
}

Armor* Campaign::getItem(const std::string nam) {
	std::vector<Armor>::iterator it = armorList.begin();
	for (int x = 0; x < armorList.size(); x++) {
		if (it->getName() == nam) {
			return &(*it);
		}
		it++;
	}
	cout << "Could not find item" << endl;
	return NULL;
}

void Campaign::itemMenu() {
	bool quit = false;
	int choice = 0;
	cout << "Item Menu!" << endl;
	while (!quit) {
		cout << "1. Create an item" << endl
			 << "2. View item list"  << endl
			 << "3. View an item" << endl
			 << "4. Modify an item" << endl
			 << "5. Go back to main menu" << endl;
		choice = getNum(1, 5);
		cout << endl;
		switch (choice) {
			case 1: //create an item
				cout << "Future, should check to see what item type." << endl;
				armorList.push_back(Armor());
				cout << endl;
				break;
			case 2: //view item list
				for (int i = 0; i < armorList.size(); i++) {
					cout << armorList[i].getName() << endl;
				}
				cout << endl;
				break;
			case 3: { //view an item
				string tempNam;
				cout << "Which item would you like to view?" << endl;
				getline(cin, tempNam);
				cout << endl;
				getItem(tempNam)->printInfo();
				cout << endl;
				break;
			}
			case 4: { //modify an item
				cout << "Modify an item by giving it an ability bonus." << endl << endl;
				Armor::printArmor(armorList);
				cout << endl << "Which item?" << endl;
				string tempNam;
				getline(cin, tempNam);
				cout << endl;
				for (int x = 0; x < armorList.size(); x++) {
					if (tempNam == armorList[x].getName()) {
						armorList[x].addBonus();
						break; // for(x)
					}
				}
				//should print bonus like "+3 Str"
				cout << "Finished modifying shit" << endl;
				cout << endl;
				break;
			} //finish modifying shit
			case 5:
				quit = true;
				break;
			default:
				cout << "Not an appropriate answer." << endl << endl;
				break;
		}
	}
}

void Campaign::characterMenu() {
	bool quit = false;
	int choice = 0;
	cout << "Character Menu!" << endl;
	while (!quit) {
		cout << "1. Create a character" << endl
			 << "2. View Character list"  << endl
			 << "3. View a character" << endl
			 << "4. Modify a character" << endl
			 << "5. Go back to main menu" << endl;
		choice = getNum(1, 5);
		switch (choice) {
			case 1: //create a character
				cout << endl;
				charList.push_back(Character());
				cout << endl;
				break;
			case 2: //view character list
				cout << endl;
				Character::printCharNames(charList);
				cout << endl;
				break;
			case 3: { //view a character
				cout << endl;
				Character::printCharNames(charList);
				string tempNam;
				cout << "Which character would you like to see?" << endl;
				getline(cin, tempNam);
				cout << endl;
				getCharacter(tempNam)->printCharacter();
				cout << endl;
				break;
			}
			case 4: { //modify a character
				Character::printCharNames(charList);
				string tempNam;
				cout << "Which character would you like to modify?" << endl;
				getline(cin, tempNam);
				if (getCharacter(tempNam)) {
					charModMenu(getCharacter(tempNam));
				} else {
					cout << "Not a valid character name" << endl;
				}
				cout << endl;
				break;
			}
			case 5: 
				quit = true;
				cout << endl;
				break;
			default:
				cout << "You dun fucked up, son." << endl;
				break;
		}
	}
}

/*
void Campaign::mountMenu() {
	bool quit = false;
	int choice;
	while (quit != true) {
		//will add more items later when I can think of them
		cout << "Mount Menu" << endl
		<< 1. Create Mount
		<< 2. List Mounts
		<< 3. View Mount
		<< 4. Go back to main Menu
	}
}
*/

void Campaign::charModMenu(Character *t){
	bool quit = false;
	int choice;
	
	while (!quit) {
		cout << endl << "Menu for " << t->getName() << endl
			<< "1. View full character" << endl
			<< "2. Add item to backpack" << endl
			<< "3. Equip from backpack" << endl
			<< "4. Remove equipped" << endl
			<< "5. Remove from backpack" << endl
			<< "6. Go back to character menu" << endl;
		choice = getNum(1, 6);
		switch (choice) {
			case 1: //print character
				t->printCharacter();
				cout << endl;
				break;
			case 2: { //acquire to backpack
				Armor::printArmor(armorList);
				cout << "Which item?" << endl;
				string tempNam;
				getline(cin, tempNam);
				if (getItem(tempNam)) {
					t->backpack.addItem(*getItem(tempNam));
					cout << "Acquired!" << endl;
				} else {
					cout << "Not a valid item." << endl;
				}
				cout << endl;
				break;
			}
			case 3: { //equip from backpack
				//when there's nothing to unequip, it still asks what 
				//you want to unequip
				t->backpack.printContainer();
				cout << "Which do you want to equip?" << endl;
				string tempNam;
				getline(cin, tempNam);
				Item * tempItem = t->backpack.searchContainer(tempNam);
				if (tempItem) {
					if (t->backpack.moveItem(*tempItem, &(t->equipped))) {
						cout << "Equipped!" << endl;
					} else {
						cout << "Failed to equip " << tempItem->getName() << endl;
					}
				} else {
					cout << "Could not find an item named " << tempNam << endl;
				}
				cout << endl;
				break;
			}
			case 4: { //remove from equipped to backpack
				//does not actually remove
				t->equipped.printContainer();
				cout << "Which do you want to unequip?" << endl;
				string tempNam;
				getline(cin, tempNam);
				Item * tempItem = t->equipped.searchContainer(tempNam);
				if (tempItem) {
					if (t->equipped.moveItem(*tempItem, &(t->backpack))) {
						cout << "Unequipped!" << endl;
					} else {
						cout << "Failed to unequip " << tempItem->getName() << endl;
					}
				} else {
					cout << "Could not find an item named " << tempNam << endl;
				}
				cout << endl;
				break;
			}
			case 5: { //remove from backpack
				t->backpack.printContainer();
				cout << "What do you want to drop?" << endl;
				string tempNam;
				getline(cin, tempNam);
				Item * tempItem = t->backpack.searchContainer(tempNam);
				if (tempItem) {
					if (!t->backpack.removeItem(*tempItem)) {
						cout << "Failed to remove the item!" << endl;
					}
				} else {
					cout << "Item either does not exist or is not carried" << endl;
				}
				cout << endl;
				break;
			}
			case 6:
				quit = true;
				cout << endl;
				break;
			default:
				cout << "No. Just no." << endl;
				break;
		}
	}
}