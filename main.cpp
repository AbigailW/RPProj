#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <stdio.h>
#include <cstdlib> 

#include "Item.h"
#include "Character.h"
#include "Armor.h"
#include "Helper.h"
#include "Campaign.h"

using namespace std;

int main() {
	Campaign thisGame;

	cout << "Loading character data" << endl;
	thisGame.charList.push_back(Character("Bobby"));
	thisGame.charList.push_back(Character("Jordan"));
	thisGame.charList.push_back(Character("Louise"));

	cout << "Loading armor data" << endl;
	thisGame.armorList.push_back(Armor("Tit Protection"));
	thisGame.armorList.push_back(Armor("Doom Staff"));
	thisGame.armorList.push_back(Armor("Foobar Shield"));

	cout << "Welcome to DnD 5.0 All-Purpose Shit!" << endl;

	bool go = true;
	int choice = 0;
	while (go) {
		cout << endl << "1. Create a character " << endl << "2. Create an item " << endl
			 << "3. See character list " << endl << "4. See item list " << endl
			 << "5. Add items to character " << endl << "6. View Character" << endl
			 << "7. Equip items" << endl << "8. Quit " << endl;
		choice = getNum(1, 8);
		switch (choice) {
			case 1: { // Create a character
				Character temp = Character();
				temp.printCharacter();
				thisGame.charList.push_back(temp);
				break;
			}
			case 2: { // Create an item
				//which kind of item?
				Armor temp = Armor();
				temp.printInfo();
				thisGame.armorList.push_back(temp);
				break;
			}
			case 3: // List characters
				cout << endl << "---Characters---" << endl;
				Character::printCharNames(thisGame.charList);
				break;
			case 4: // List items
				for (int i = 0; i < thisGame.armorList.size(); i++) {
					thisGame.armorList[i].printInfo();
					cout << endl;
				}
				break;     
			case 5: { // Add items to character bag
				string tempNam, tempItem;
				cout << endl << "---Character List---" << endl;
				Character::printCharNames(thisGame.charList);
				cout << "Which character?" << endl;
				getline(cin, tempNam);
				if (thisGame.getCharacter(tempNam)) {
					cout << endl << "---Item List---" << endl;
					Armor::printArmor(thisGame.armorList);
					cout << endl << "Which item?" << endl;
					getline(cin, tempItem);
					if (thisGame.getItem(tempItem)) {
						thisGame.getCharacter(tempNam)->backpack.addItem(*thisGame.getItem(tempItem));
						cout << "Added to " << thisGame.getCharacter(tempNam)->getName() << "'s "
							<< thisGame.getCharacter(tempNam)->backpack.getName() << endl;
					} else {
						cout << "No such item." << endl;
					}
				} else {
					cout << "Didn't find a character named " << tempNam << endl;
				}
				break;
			}
			case 6: { // Display character
				string charInp;
				cout << endl << "---Characters---" << endl;
				Character::printCharNames(thisGame.charList);
				cout << endl << "Which character would you like to view?" << endl;
				getline(cin, charInp);
				Character * tempChar = thisGame.getCharacter(charInp);
				if (tempChar) {
					tempChar->printCharacter();
				} else {
					cout << "Didn't find a character named " << charInp << endl;
				}
				break;
			}
			case 7: { // Equip an item
				string charInp, itemInp;
				cout << endl << "---Characters---" << endl;
				Character::printCharNames(thisGame.charList);
				cout << endl << "Which character would you like to equip items on?" << endl;
				getline(cin, charInp);
				Character * tempChar = thisGame.getCharacter(charInp);
				if (tempChar) {
					cout << endl << "Currently in " << tempChar->getName() << "'s ";
					tempChar->backpack.printContainer();
					cout << endl << "Which item?" << endl;
					getline(cin, itemInp);
					Item * tempItem = tempChar->backpack.searchContainer(itemInp);
					if (tempItem) {
						tempChar->equipped.moveItem(*tempItem, &(tempChar->equipped));
						cout << "Equipped!" << endl;
					} else {
						cout << "No such item in " << tempChar->getName() << "'s bag." << endl;
					}
				} else {
					cout << "Didn't find a character named " << charInp << endl;
				}
				break;
			}
			case 8: // Exit
				go = false;
				break;
			default: // Wtf?
				cout << "How did you get here?!?";
				break;
		}
	}
	return 0;
}