#include <iostream>
#include <string>
#include <utility> // pair
#include "Item.h"
#include "Weapon.h"
#include "DataTypes.h"

using namespace std;

void Weapon::printInfo() const {
	Item::printInfo();
	cout << handReq << "-handed" << endl
		 << "Range: " << range << " ft" << endl
		 << group << endl 
		 << damage.first << "d" << damage.second << endl;
}