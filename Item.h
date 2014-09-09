#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include "DataTypes.h"

class Item {
	public:
		Item();
		Item(std::string nam);
		Item(std::string n, std::string des, std::string loc, double w);
		int getWeight() const;
		std::string getName() const;
		std::string getDescription() const;
		void editDescription(std::string);
		void editLocation(std::string);
		void printInfo() const;
		void addBonus(const AbilBonus);
		void addBonus(const AbilTypes& at, const int& bon,
					  const std::string& nam, const std::string& desc);
		bool removeBonus(const AbilBonus&);
		int getBonus(const AbilTypes&) const;
	protected:
		double weight;
		std::string name, description, location;
		std::vector<AbilBonus> bonuses;
};

#endif