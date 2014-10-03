//NOTE:DOES NOT COMPILE WITH MAKE FILE YET
//nothing to see here move along
#include <iostream>
#include <string>
#include <stdlib>

#include "Helper.h"
#include "Mount.h"

Mount::Mount(){
	name = "Horse";
	des = "a normal mount"
	speed = 10; //just some random number
	cWeight = 10; //just some random number
}

Mount::Mount(std::string name){
	
}

std::string getName(){
	return name;
}

std::getDescription(){
	return des;
}

double getSpeed(){
	return speed;
}

double getWeight(){
	return cWeight;
}

void setName(std:string n){
 	name = n;
 }
 
void setDescription(std:: string d){
	des = d;
}

void setSpeed(double s){
	speed = s;
}

void setWeight(double w)
	cWeight = w;
}

void printMount(){
	
}