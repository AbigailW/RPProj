#ifndef ARMOR_H
#define ARMOR_H
#include "Item.h"
#include "DataTypes.h"

class Armor: public Item {
	public:
		Armor();
		Armor(Weight, int ACinp, int str, Stealth, std::string n, std::string des,
			  std::string loc, double w);
		Armor(std::string nam): Item(nam) {
			name = nam;
			description = "Tested shit";
			location = "In a place";
			weight = 1000;
			armorWeight = shield;
			AC = 42;
			armorStealth = none;
			strReq = 9001;
		}
		std::string printArmorWeight(bool cap = false) const;
		std::string printStealth(bool cap = false) const;
		static void printArmor(const std::vector<Armor>&);
		void printInfo() const;
	private:
		Weight armorWeight;
		Stealth armorStealth;
		int AC, strReq;
};

#endif