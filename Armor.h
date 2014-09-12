#ifndef ARMOR_H
#define ARMOR_H
#include "Item.h"
#include "DataTypes.h"

class Armor: public Item {
	public:
		// Constructors
		Armor();
		Armor(Weight, int ACinp, int str, Stealth, std::string n, std::string des,
			  std::string loc, double w);
		Armor(std::string nam): Item(nam) {
			name = nam;
			description = "Tested shit";
			weight = 1000;
			armorWeight = shield;
			AC = 42;
			armorStealth = none;
			strReq = 9001;
		}
		// Operators
		bool operator==(const Armor&) const;
		bool operator!=(const Armor&) const;
		// Functions
		void printInfo() const;
		static void printArmor(const std::vector<Armor>&);
	private:
		Weight armorWeight;
		Stealth armorStealth;
		int AC, strReq;
};

#endif