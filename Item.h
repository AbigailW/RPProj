#ifndef ITEM_H
#define ITEM_H

using namespace std;

class Item {
	public:
		Item();
		Item(string nam);
		Item(string n, string des, string loc, double w);
		int getWeight() const;
		string getName() const;
		string getDescription() const;
		void editDescription(string);
		void editLocation(string);
		void printInfo() const;
	protected:
		double weight;
		string name, description, location;
};

#endif