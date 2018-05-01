#pragma once
#include "Menu.h"

class MoveMenu : public Menu
{
public:
	void startMenu(Character & currentCharacter, vector<Character> & characterList, string & Field);

	void printMenu(Character & currentCharacter, vector<Character> & characterList, string & Field);
	void askForResponse(Character & currentCharacter, vector<Character> & characterList, string & Field);

	bool pointIsOccupiedByChar(Point newLoc, vector<Character> & characterList, string & Field);

	// decreases currentCharacter's currentMoveCounter for each step that character takes in their turn;
	void decreaseMoveCounter(Character & currentCharacter, int decrement);
	
	// updates the Field string with the new position(s) from the currentCharacter moving on their turn;
	void updateField(Character & currentCharacter, vector<Character> & characterList, string & Field);

	// resets a single character's (the currentCharacter's) MoveCounter back up to their max;
	// void resetMoveCounter(Character & currentCharacter);

	// resets all of the character's MoveCounter back up to their maxes when the battle concludes;
	// void resetAllMoveCounters(vector<Character> & characterList);

	void setCancelledMovement(bool state);
	bool getCancelledMovement();

private:
	bool hasCancelledMovement = false;

};