#ifndef CAMPAIGN_H
#define CAMPAIGN_H

#include <vector>
#include <string>

#include "Character.h"
#include "Armor.h"

class Campaign {
	public:
		std::vector <Character> charList;
		std::vector <Armor> armorList;
		Character* getCharacter(std::string nam);
		Armor* getItem(std::string nam);
		void itemMenu();
		void characterMenu();
		void charModMenu(Character *t);
	private:
		
};

#endif