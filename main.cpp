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
		cout << "What would you like to get into?" << endl
			 << "1. Items" << endl
			 << "2. Characters" << endl
			 << "3. Quit" << endl;
		cin >> choice;
		switch(choice){
			case 1:
				thisGame.itemMenu();
				break;
			case 2:
				thisGame.characterMenu();
				break;
			case 3:
				go = false;
				break;
			default:
				cout << "Nope nope nope" << endl;
				break;
			
		}
	}
	return 0;
}