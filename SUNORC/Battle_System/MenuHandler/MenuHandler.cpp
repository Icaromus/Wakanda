#include <string>
#include "MenuHandler.h"

bool MenuHandler::hasActionCounters(Character currentCharacter) // Tells us if the current character can make any actions (fight, use item)
{
	return currentCharacter.GetActionCount();
}

bool MenuHandler::hasMoveCounters(Character currentCharacter) // Does current character have enough counters to make a move on the field?
{
	return currentCharacter.GetMoveCount();
}

bool MenuHandler::canEscape()
{
	; // Need to figure out how to decide this.
	  // Based on your speed / total speed of all chars on field (or some combination of chars on field)
	  // Flat probability percentage (60%)
}

void MenuHandler::endTurn(Character currentCharacter) //For now, just wipes current character's counters. Has potential to do other clean-up operations
{
	currentCharacter.resetCounters();
	endLoop = false; // Stops current character's turn by ending the 'turn' while loop in 'canMakeTurn'
}

bool MenuHandler::allEnemiesDead()
{
	for (auto character : characters)
	{
		if (character.alignment = "Enemy" and character.Status != "Dead") // Need to iron this out w/ noah, but if there's an enemy that's not dead, then continue the turn loop.
			return false;
	}
	return true;
}

bool MenuHandler::canMakeTurn(Character currentCharacter) // Checks current character's status to make sure they are able to move, attack or use an item
{
	std::string statuses[2] = { "Stunned", "Dead" };
	for (auto status : statuses)
	{
		if (status == currentCharacter.Status)
			return false;
	}
	return true;
}

void MenuHandler::makeTurn(Character currentCharacter)
{
	while (!endLoop)
	{
		char userOption = menus["Main"].start();
		// We need a way to extract information from cin through the Main menu, so that we can navigate to other menus
		switch (userOption)
		{
		case 'm': // User tries to move themselves / ally on the field
			if (hasMoveCounters(currentCharacter)) // Check if user has sufficient move counters
				menus["Move"].start(); // fire up 'Move' UI
			break;
		case 'f':
			if (hasActionCounters(currentCharacter)) // Check if user has sufficient action counters
				menus["Fight"].start(); // fire up 'Fight' UI
			break;
		case 'i':
			if (hasActionCounters(currentCharacter)) // Check if user has sufficient action counters
				menus["Inventory"].start(); // fire up 'Inventory' UI
			break;
		case 'p':
			if (canEscape()) // If player can escape, then end turn
				endTurn(currentCharacter);
			break;
		case 'e': // End turn works regardless of conditions or counters
			endTurn(currentCharacter);
			break;
		default:
			std::cout << "Please Enter a Valid Input" << std::endl;
		}
	}
	endTurn(currentCharacter);
}

void MenuHandler::loopCharacters(Character currentCharacter)
{
	int totalCharacters = characters.size(); // Total number of characters so we know when we need to loop from the end of the Char vector back to the beginning
	int currentChar = 0; // When we start iterating through players' turns, we start at index 0 of the character list, then keep looping through the list until battle is over
	while (!allEnemiesDead()) // While there are still enemies on the field to fight...
	{
		if (canMakeTurn(characters[currentChar]))
			makeTurn(characters[currentChar]);
		currentChar = ++currentChar % totalCharacters; // Once currentChar reaches the last value in the char list, this allows the fn to loop back to the first value
	}

}

void MenuHandler::setCharacterOrder() // alters the character list data member
{
    PriorityQueue q(characters.size());
    // steps:
    // Insert all characters into the priority queue
    // Pop characters out of the PQ and re-insert them into the vector, but this time in the correct order
    for (auto c : characters)
	q.insert(c);
    for (int i = 0; i < characters.size(); ++i)
    {
	characters[i] = q.pop(); // This reorders the characters so that they are ordered by speed, descending from index 0 to index characters.size() -1
    }    
}

