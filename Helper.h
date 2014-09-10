#ifndef HELPER_H
#define HELPER_H
#include <iostream> // cin, cout
#include <string> // string, getline
#include <sstream> // stringstream
#include <limits> // Number limits

#include "DataTypes.h"

/*
	Function: rollDice
	Parameters:
		number: The number of dice to roll
		sides: The number of sides on the dice
	Return:
		The sum of the values rolled.
*/
int rollDice(int number, int sides);

/*
	Function: getNum
	Parameters:
		[min]: Minimum desired number
		[max]: Maximum desired number
	Return:
		The user-entered number
*/
template<typename Type> Type getNum(
							const Type min = std::numeric_limits<Type>::min(),
							const Type max = std::numeric_limits<Type>::max()) {
	bool success = false;
	Type tempVal;
	std::string temp;
	std::stringstream ss;
	// None of the following actually works :(
	//std::cin.sync();
	//std::cin.clear();
	//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	while (!success) {
		std::getline(std::cin, temp);
		ss << temp; // Load the string to the stringstream
		success = ss >> tempVal; // Attempt to get the number from it
		ss.clear();
		ss.str("");
		if (success) {
			if (tempVal < min) {
				std::cout << tempVal
					<< " is too small of a number, please try again: ";
				success = false;
			} else if (tempVal > max) {
				std::cout << tempVal
					<< " is too large of a number, please try again: ";
				success = false;
			}
		} else {
			if (temp != "") {
				/* Make sure something was actually in the string, this is a
					workaround for being unable to properly reset cin.
				*/
				std::cout << "\"" << temp
					<< "\" is not a valid number, please try again: ";
			}
			continue;
		}
	}
	return tempVal;
}

#endif