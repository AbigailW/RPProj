#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include "DataTypes.h"

class Item {
	public:
		// Constructors
		Item();
		Item(std::string nam);
		Item(std::string n, std::string des, double w);
		// Operators
		bool operator==(const Item&) const;
		bool operator!=(const Item&) const;
		// Functions
		void printInfo() const;
		int getWeight() const;
		std::string getName() const;
		std::string getDescription() const;
		void setDescription(std::string);
		void addBonus();
		void addBonus(const AbilBonus);
		void addBonus(const AbilTypes& at, const int& bon);
		bool removeBonus(const AbilBonus&);
		int getBonus(const AbilTypes&) const;
	protected:
		double weight;
		std::string name, description;
		std::vector<AbilBonus> bonuses;
};

#endif