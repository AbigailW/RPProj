#ifndef CONTAINER_H
#define CONTAINER_H
#include <string>
#include <vector>
#include "Item.h"

class Container {
	public:
		// Constructors
		Container() : Container("") {}
		Container(std::string const& nameInp) : name(nameInp), weight(0) {}
		// Operators
		// Functions
		void printContainer() const;
		Item * searchContainer(std::string);
		std::string getName() const;
		void setName(std::string);
		void addItem(Item);
		bool removeItem(Item);
		bool moveItem(Item, Container *);
		// Data
		std::vector <Item> items;
	private:
		std::string name;
		int weight;
};
#endif