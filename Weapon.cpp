#include <iostream>
#include <string>
#include <utility> // pair
#include "Item.h"
#include "Weapon.h"
#include "DataTypes.h"

using namespace std;

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

void Weapon::printInfo() const {
	Item::printInfo();
	cout << handReq << "-handed" << endl
		 << "Range: " << range << " ft" << endl
		 << group << endl
		 << damage.first << "d" << damage.second << endl;
}

Weapon::Weapon(int handR, int r, int profB, weapGroup wG, damType dT, int f, int s) {
	handReq = handR;
	range = r;
	profBon = profB;
	group = wG;
	damage = make_pair(f,s);
	damT = dT;
}

Weapon::Weapon(string nam) {
	
}

Weapon::createWeapon() {
	cout << endl << "Hand requirements?" << endl;
	int handR = getNum();
	cout << endl << "Range?" << endl;
	int r = getNum();
	cout << endl << "Proficiency Bonus?" << endl;
	int profB = getNum();
	cout << endl << "Group type?" << endl;
	//make menu for weapon group
	//damType
	cout << endl << "Damage type?" << endl;
	//make menu for damage type;

	cout << endl << "For damage. How many dice?" << endl;
	f = getNum();
	cout << endl << "Sides on dice?" << endl;
	s = getNum();
	cout << endl;
}