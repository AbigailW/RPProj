#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <vector>
#include "Item.h"
#include "Armor.h"
#include "Helper.h"
#include "Weapon.h"

using namespace std;

void Weapon::printInfo() const {
	Item::printInfo();
	cout << handReq << "-handed" << endl
		 << "Range: " << range << " ft" << endl
		 << group << endl 
		 << damage.first << "d" << damage.second << endl;
}