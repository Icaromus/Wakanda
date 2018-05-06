#pragma once
#include <iomanip>

#include "Menu.h"
#include "TargetingMenu.h"

class FightMenu : public Menu
{
public:
	//FightMenu() {}

	void startMenu(Character & currentCharacter, vector<Character> & characterList, string & Field);

	void printMenu(Character & currentCharacter, vector<Character> & characterList, string & Field);
	void askForResponse(Character & currentCharacter, vector<Character> & characterList, string & Field);

	void calculateDamage(Character & currentCharacter, Character * targetedCharacter, int moveEntry);

	// decreases cooldown timer of abilities that are greater than 0 at the very beginning of their turn
	void decreaseCooldownTimers(Character & currentCharacter);

	void setCooldownTimer(Character & currentCharacter, int entry);

	// called at the end of the battle to reset every characters' cooldown timers 
	void resetAllCooldownTimers(vector<Character> & characterList);

	void setActionCarriedOut(bool state);
	bool getActionCarriedOut();

	void setCancelledFight(bool state);
	bool getCancelledFight();

private:
	bool hasCancelledFight = false;
	bool actionCarriedOut = false;

};
