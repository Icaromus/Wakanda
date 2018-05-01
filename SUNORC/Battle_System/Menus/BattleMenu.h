#pragma once
#include <algorithm>
#include <random>

#include "Menu.h"
#include "FightMenu.h"
#include "ItemMenu.h"
#include "MoveMenu.h"

class BattleMenu : public Menu
{
public:
	void startMenu(Character & currentCharacter, vector<Character> & characterList, string & Field);

	void printMenu(Character & currentCharacter, vector<Character> & characterList, string & Field);
	void askForResponse(Character & currentCharacter, vector<Character> & characterList, string & Field);

	bool hasActionCounterRemaining(Character & currentCharacter);
	bool hasMoveCounterRemaining(Character & currentCharacter);

	void PullOut(Character & currentCharacter, vector<Character> & characterList);

	void setTurnHasEnded(bool state);
	void setBattleHasEnded(bool state);

	Character getCharacterWithGreatestSpeed(vector<Character> & characterList);

private:
	bool battleHasEnded = false;
	bool turnHasEnded = false;

};