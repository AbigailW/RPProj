#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include "DataTypes.h"

class Item {
	public:
		Item();
		Item(std::string nam);
		Item(std::string n, std::string des, double w);
		int getWeight() const;
		std::string getName() const;
		std::string getDescription() const;
		void editDescription(std::string);
		void printInfo() const;
		void addBonus();
		void addBonus(const AbilBonus);
		void addBonus(const AbilTypes& at, const int& bon);
		bool removeBonus(const AbilBonus&);
		int getBonus(const AbilTypes&) const;
		bool operator==(const Item&) const;
		bool operator!=(const Item&) const;
	protected:
		double weight;
		std::string name, description;
		std::vector<AbilBonus> bonuses;
};

#endif