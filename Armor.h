#ifndef ARMOR_H
#define ARMOR_H
#include "Item.h"

using namespace std;

enum Weight {
    light, medium, heavy, shield
};

enum Stealth {
    disadvantage, advantage, none
};

class Armor: public Item {
    public:
        Armor();
        Armor(Weight, int ACinp, int str, Stealth, string n, string des,
              string loc, double w);
        Armor(string nam): Item(nam) {
        	name = nam;
        	description = "Tested shit";
        	location = "In a place";
        	weight = 1000;
        	armorWeight = shield;
        	AC = 42;
        	armorStealth = none;
        	strReq = 9001;
        }
        string printArmorWeight(bool cap = false) const;
        string printStealth(bool cap = false) const;
        void printInfo() const;
    private:
        Weight armorWeight;
        Stealth armorStealth;
        int AC, strReq;
        
};

#endif