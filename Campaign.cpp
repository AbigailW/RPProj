#include <string>
#include <vector>
#include <iterator>

#include "Campaign.h"
#include "Character.h"
#include "Armor.h"

Character* Campaign::getCharacter(const std::string nam) {
	std::vector<Character>::iterator it = charList.begin();
	for (int x = 0; x < charList.size(); x++) {
		if (it->getName() == nam) {
			return &(*it);
		}
		it++;
	}
	return NULL;
}

Armor* Campaign::getItem(const std::string nam) {
	std::vector<Armor>::iterator it = armorList.begin();
	for (int x = 0; x < armorList.size(); x++) {
		if (it->getName() == nam) {
			return &(*it);
		}
		it++;
	}
	return NULL;
}