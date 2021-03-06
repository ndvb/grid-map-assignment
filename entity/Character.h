//!  Character\n
//
//!  Created by Hyjaz Loudin on 2016-10-15.\n
//!  Copyright � 2016 Hyjaz Loudin. All rights reserved.\n
//! //! @file \n
//! @brief Header file for the Character class  \n
//!
//! (1) The Game rules are as followed:\n
//!     \t A user is of class Fighter\n
//!     \t A user chooses its level at the beninning\n
//!     \t Depending on the level the user chooses to start the game as, this will reflect how much hitpoints, attack bonus and attack damage he will have\n
//!     \t The ability scores are generated randomly, by roling 4 dices and summing them.\n
//!     \t Once we have the ability score we calculate the modifiers. The modifiers are calculated as follow: modifiers = (ability score - 10)/2.\n
//!     \t It is going to be the the (ability score - 10)/2.\n
//!     \t We then add the modifier to the ability score and let the user know how much of the ability comes from the modifier\n
//!     \t Every we level the ability changes depending on the level and the modifier \n
//! (2) Design Description \n
//!     We have a fighter class that inherents from the Character class. \n
//!		The character class has two special static private variables that are being used in the different public methods in order to set or update.\n
//!	(3) Libraries used in this c++ program are the following:\n
//!		<vector>, <string>, <iostream>, <random>, <ctime>, <algorithm>, <windows.h>\ns


#pragma once
#ifndef Character_h
#define Character_h
#include <vector>
#include <string>

#include "../core/Subject.h"
#include "ItemContainer.h"
#include "Item.h"
#include "../controller/ItemEditor.h"
#include "GameItem.h"
//#include "../controller/ItemEditor.h"
//! Class that implements a character
class Character: public Subject
{
public:
	Character();
	~Character();
	Character(int, int, int, int, int, int);
	Character(Character* character);
	//hit points
	void hit(int);
	void previousHitPoints();
	void nextHitPoints();
    void setHitPoints(int);
	int getHitPoints();
	void GenerateModifiers();
	//set modifier based on ability scores
	int modifier(int);
	//generate ability scores
	int genAbilityScores();
	//leveling up
	int getLevel();
	void setLevel(int);
	void levelUp();
	//armor class
	void armorClass();
	int getArmorClass();
	//attack bonus
	void attackBonus();
	void nextAttackBonus();
	//void setAttackBonus();
	int getAttackBonus();
	//attack damage
	void damageBonus();
	int getDamageBonus();
	//load
	bool saveCharacter(std::string name);
	bool loadCharacter(std::string name);
	//update
	void update();
	void display();
	//Item update
	void updateStatsAtEquip(Item*);
	void updateStatsAtUnequip(Item*);
	//print ability score
	void printAbilityScores();
	//unit testing validation
	bool validateNewCharacter(int);
	bool validateHitPoints();
	bool validateAttackBonus();
	//setter for ability scores
	void setStrength(int);
	void setDexterity(int);
	void setIntelligence(int);
	void setCharisma(int);
	void setWisdom(int);
	void setConstitution(int);
	//getter for ability score
	int getStrength();
	int getDexterity();
	int getIntelligence();
	int getCharisma();
	int getWisdom();
	int getConstitution();
	//setter for modifiers
	void setModStrength(int);
	void setModDexterity(int);
	void setModIntelligence(int);
	void setModCharisma(int);
	void setModWisdom(int);
	void setModConstitution(int);
	//getter for modifiers
	int getModStrength();
	int getModDexterity();
	int getModIntelligence();
	int getModCharisma();
	int getModWisdom();
	int getModConstitution();
	//name
	std::string getName();
	void setName(std::string name);

	void removeItemHelper(vector<string>* item, string itemName);
	void removeItemFromBackpack(std::string);
	void removeItemFromWornItems(string itemName);
	//validate worn Items
	bool validateContainer(vector<Item*>*, Item* item);
	//equip and unequip
	void equipItem(string);
	void unequipItem(string);
	//checkIfItemExists in backpack
	bool checkIfItemExists(string, string);
	vector<std::string>* backpack;
	vector<std::string>* wornItems;
	//display Items
	void displayItemsHelper(std::vector<string>* items);
	vector<Item*>* getAllItems(vector<string>* items);
	void displayBackpack();
	void displayWornItems();
	//get item
	Item* getItemHelper(std::vector<string>* items, std::string name);
	Item* getBackpackItem(std::string name);
	Item* getWornItemsItem(std::string name);

	bool hasItemInBackpack(std::string itemName);
	bool hasItemHelper(std::vector<string>* items, std::string name);

	bool isWearingItem(std::string itemName);
	//void attack(Character *enemy);
	void numberOfAttack();
	void lootItems(Character *victm);
	void lootItems(GameItem *chest);
	
	int getNumberOfattack();
	
	int getArmorPoints();
	void setArmorPoints(int);

	int getShieldPoints();
	void setShieldPoints(int);

	int getInitialHP();
private:
	vector<Item> items;
	int lvl;
	int modifiers[6];
	int abilityScores[6];
	int damageB;
	int attackB = 0;
	int ac;
	int armorPoints = 0;
	int shieldPoints = 0;
	int initialHitPoints = 0;
	int currentHitPoints = 0;
	int attPerRound = 1;
	std::string name;

};

inline void Character::setName(std::string name) {
    this->name = name;
}

inline std::string Character::getName() {
    return this->name;
}

inline void Character::setHitPoints(int i){
    currentHitPoints = i;
}

#endif
