#ifndef ITEM_H
#define ITEM_H

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
	protected:
		double weight;
		std::string name, description, location;
};

#endif