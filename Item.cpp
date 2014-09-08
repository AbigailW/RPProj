#include <iostream>
#include <string>
#include <stdio.h>
#include "Item.h"
#include "Helper.h"

using namespace std;

string Item::getDescription() const {
	return description;
}

void Item::editDescription(const string s) {
	description = s;
}

void Item::editLocation(const string s) {
	location = s;
}

void Item::printInfo() const {
	cout << name << endl << description << endl
		 << weight << " lbs" << endl
		 << "Location: " << location << endl;
}

Item::Item() {
	cout << "Name?" << endl;
	getline(cin, name);
	cout << "Description?" << endl;
	getline(cin,description);
	cout << "Weight?" << endl;
	weight = getNum<double>();
	cout << "Location?" << endl;
	getline(cin,location);
}

Item::Item(const string nam){
	name = nam;
	description = "tested shit";
	weight = 2500;
	location = "places unknown";
}

Item::Item(const string n, const string des, const string loc, const double w) {
	name = n;
	description = des;
	location = loc;
	weight = w;
}

int Item::getWeight() const {
	return weight;
}

string Item::getName() const {
	return name;
}