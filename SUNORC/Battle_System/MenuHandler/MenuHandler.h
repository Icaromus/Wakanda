#pragma once
#include "../Character/Character.h"
#include "Field.h"
#include <map>
#include <iostream>

class MenuHandler {

private:
	Character currentCharacter;
	Field field;
	std::map<std::string,Menu> menus; // Our collection of Menus that we'll be cycling through
	//PriorityQueue characterList; // This priority queue will decide the order in which the characters move; character start in here, and will move one by one into the characters vector.
	std::vector<Character> characters; // Base speed + (random integer between 0 and half your base speed)
	int totalCharacters; // need to construct this in the class's  init list
	int currentTurn = 0;
	
	bool endLoop = false; // When set to true, our current menu iteration will stop

public:

	MenuHandler(vector<Character> chars, std::map<std::string, Menu> m)
	    :characters(chars), menus(m)
	{}

	bool hasActionCounters(Character currentCharacter); // Tells us if the current character can make any actions (fight, use item)

	bool hasMoveCounters(Character currentCharacter); // Does current character have enough counters to make a move on the field?

	bool canEscape();

	void endTurn(Character currentCharacter); //For now, just wipes current character's counters. Has potential to do other clean-up operations

	bool allEnemiesDead();

	bool canMakeTurn(Character currentCharacter); // Checks current character's status to make sure they are able to move, attack or use an item


	void makeTurn(Character currentCharacter);

	void loopCharacters(Character currentCharacter);

	void setCharacterOrder();

};
