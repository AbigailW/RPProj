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


bool Weapon::operator==(const Weapon& oth) const {
	return ((Item) *this == (Item) oth && handReq == oth.handReq
			&& range == oth.range && profBon == oth.profBon
			&& group == oth.group && damT == oth.damT
			&& damage == oth.damage);
}

bool Weapon::operator!=(const Weapon& oth) const {
	return ((Item) *this != (Item) oth && handReq != oth.handReq
			&& range != oth.range && profBon != oth.profBon
			&& group != oth.group && damT != oth.damT
			&& damage != oth.damage);
}