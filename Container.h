#ifndef CONTAINER_H
#define CONTAINER_H
#include <string>
#include <vector>
#include "Item.h"

class Container {
	public:
		int weight;
		std::vector <Item> items;
		
		Container() : Container("") {}
		Container(std::string const& nameInp) : weight(0), name(nameInp) {}
		
		void setName(string);
		string getName() const;
		void addItem(Item);
		bool removeItem(Item);
		bool moveItem(Item, Container *);
		Item * searchContainer(string);
		
		void printContainer() const;
	private:
		std::string name;
};
#endif