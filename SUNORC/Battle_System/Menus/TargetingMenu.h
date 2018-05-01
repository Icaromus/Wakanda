#pragma once
#include "Menu.h"

class TargetingMenu : public Menu
{
public:
	//TargetingMenu();

	void startMenu(Character & currentCharacter, vector<Character> & characterList, string & Field);
	void printMenu(Character & currentCharacter, vector<Character> & characterList, string & Field);
	void askForResponse(Character & currentCharacter, vector<Character> & characterList, string & Field);

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