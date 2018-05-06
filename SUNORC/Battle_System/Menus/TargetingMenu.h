#pragma once
#include "Menu.h"
#include <limits>
#include "../MenuHandler/Field.h"

class TargetingMenu : public Menu
{
public:
	//TargetingMenu() {}

	void startMenu(Character & currentCharacter, vector<Character> & characterList, string & field);
	void printMenu(Character & currentCharacter, vector<Character> & characterList, string & field);
	void askForResponse(Character & currentCharacter, vector<Character> & characterList, string & field);

	void generateTargetsList(Character & currentCharacter, vector<Character> & characterList);
	void resetTargetsList();

	void setSuccessfulAction(bool state);

	bool getCancelledAttack();
	void setCancelledAttack(bool state);

	bool hasCompletedAction();

	Character * getTargetedCharacter();

private:
	bool hasCancelledAttack = false;
	bool successfulAction = false;
	vector<Character * > targetsList;
	Character * targetChar;

};
