#ifndef WEAPON_H
#define WEAPON_H
#include <utility>
#include "Item.h"
#include "DataTypes.h"

class Weapon: public Item {
	public:
		Weapon();
		Weapon(int handReq, int range, int profBon, weapGroup, pair<int,int>damage);
		Armor(std::string nam): Item(nam) {
			name = nam;
			description = "Testing weapon";
			weight = 10;
			handReq = 2;
			range = 3;
			profBon = 2;
			group = heavyBlade;
			damage = (1,6);
		}

		void printInfo() const;
		bool operator==(const Weapon&) const;
		bool operator!=(const Weapon&) const;

	private:
		int handReq;
		int range;
		int profBon;
		weapGroup group;
		damType damT;
		pair<int,int>damage;
};

#endif