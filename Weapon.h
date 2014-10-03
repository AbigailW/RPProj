#ifndef WEAPON_H
#define WEAPON_H
#include <utility>
#include <string>
#include "Item.h"
#include "DataTypes.h"

class Weapon: public Item {
	public:
		// Constructors
		Weapon();
		Weapon(int handReq, int range, int profBon, weapGroup,
			   damType, int f, int s);
		Weapon(std::string nam): Item(nam) {
			name = nam;
			description = "Testing weapon";
			weight = 10;
			handReq = 2;
			range = 3;
			profBon = 2;
			group = simpleMelee;
			damT = slash;
			damage.first = 1;
			damage.second = 6;
		}
		// Operators
		bool operator==(const Weapon&) const;
		bool operator!=(const Weapon&) const;
		// Functions
		void printInfo() const;
	private:
		int handReq;
		int range;
		int profBon;
		weapGroup group;
		damType damT;
		std::pair<int,int> damage;
};

#endif