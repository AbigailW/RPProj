#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <vector>
#include "Item.h"
#include "Container.h"

using namespace std;

void Container::printContainer() const {
	if (items.size() < 1) {
		if (name == "") {
			std::cout << std::endl << "Nothing in the container." << endl;
		} else {
			std::cout << std::endl << "No items in " << name << "." << endl;
		}
		return;
	}
	std::cout << (name == "" ? "Contents" : name) << ":" << endl;
	for (const auto i : items) {
		cout << i.getName() << endl;
	}
}

Item * Container::searchContainer(string name) {
	std::vector<Item>::iterator it = items.begin();
	for (int x = 0; x < items.size(); x++) {
		if (it->getName() == name) {
			return &(*it);
		}
		it++;
	}
	return NULL;
}

string Container::getName() const {
	return name;
}

void Container::setName(const string nameInp) {
	name = nameInp;
}

void Container::addItem(Item i) {
	items.push_back(i);
	weight += i.getWeight();
}

bool Container::removeItem(Item i) {
	std::vector<Item>::iterator it = items.begin();
	for (int x = 0; x < items.size(); x++) {
		if (*it == i) {
			items.erase(it);
			return true;
		}
		it++;
	}
	return false;
}

bool Container::moveItem(Item i, Container* b) {
	std::vector<Item>::iterator it = items.begin();
	for (int x = 0; x < items.size(); x++) {
		if (*it == i) {
			b->addItem(*it);
			items.erase(it);
			return true;
		}
		it++;
	}
	return false;
}