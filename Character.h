#ifndef CHARACTER_H
#define CHARACTER_H
#include "Item.h"
#include "Container.h"
#include "DataTypes.h"

class Character {
	public:
		// Constructors
		Character();
		Character(std::string name);
		// Functions
		Align getAlign() const;
		void selAlign();
		void setAlign(Align);
		Class getClass() const;
		void selClass();
		Race getRace() const;
		void selRace();
		std::string getName() const;
		void selName();
		int getHitDie() const;
		int getStat(AbilTypes) const;
		void printCharacter() const;
		static void printCharNames(const std::vector<Character>&);
		// Data
		Container backpack = Container("Backpack");
		Container equipped = Container("Equipped");
	private:
		Class charClass;
		Race charRace;
		Align charAlign;
		Abilities charAbils;
		Abilities mods;
		DivineDomain domain;

		//these two are an array of these stats in this order.
		//Maybe make them pairs so that you have the number and string
		//matching the stat abbreviation?

		//simple values represented by an int
		int proficiencyBonus;
		int inspiration; //What is inspiration? Is it background? i.e. criminal, folk hero
		int level, exp; //Add subtract exp/lv function?
		int AC; //armor class
		int initiative;
		int speed;
		int hitDie, hp;
		std::string name;
		std::string deity;
		std::string size;
		int height, weight, age;
		int spellslots, cantrips, spellsknown;

		void setClass(Class); // Sets the class of the character and hit die
		void setRace(Race); // Adds bonuses to stats based on race, sets speed, height weight age etc.
		
		void calcMods();
		void setAbilities();
		void genAbilities(int*) const;
		void setAbilitiesHelper(const int *);
		void printAbilities() const;
		std::string getAbility(int) const; // Remove?
};

//STUBBED FOR COMPILING PURPOSES//
/*//all of these will need their own objects--structs or classes
//Function to reroll scores. every time a score is rerolled, a point is taken from the skill of their choice
Effect effects[]; //for anything affecting the player
Item inventory[]; //this in particular will need an array of items to create the inventory
Skill skills[18]; //this is a set list of skills that can be done as a pair--(string,int)
Proficiency prof [];
Language lang []; //this can be done either by simply adding a string or as a pair
//if it's a pair, we would have a list of possible languages and a boolean for knowledge of it
Trait traits[];
Personality persTraits [];
Ideal ideals [];
Bond bonds [];
Flaw flaws [];
Attack attacklist[];
Spell spelllist[]; //perhaps for spell list, we could import/input a list of spells
//then create a search function to let the player select spells
//if we want to be extra special, create a prereq variable that checks to see if you can actually have the spell
*/
//END STUBBED//

#endif // CHARACTER_H