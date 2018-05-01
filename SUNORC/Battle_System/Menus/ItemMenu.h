#pragma once
#include "Menu.h"
#include "TargetingMenu.h"

class ItemMenu : public Menu
{
public:
	void startMenu(Character & currentCharacter, vector<Character> & characterList, string & Field);

	void printMenu(Character & currentCharacter, vector<Character> & characterList, string & Field);
	void askForResponse(Character & currentCharacter, vector<Character> & characterList, string & Field);

	// void generateItemList(Character & currentCharacter);

	// decreases item count when used as an Action turn;
	void decreaseItemCount(Character & currentCharacter, int entry, int amount);

	// increases item count if reward from battle; maybe randomized from a DropTable
	void increaseItemCount(Character & currentCharacter, vector<Item> rewards);

	void setBackedOut(bool state);
	bool getBackedOut();

	void setUsedAction(bool state);
	bool getUsedAction();

private:
	bool hasBackedOut = false;
	bool hasUsedAction = false;

};