#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <iomanip>

#include "Character.h"

//#include "Character.h"  //Placeholder

using namespace std;

class Menu
{
public:
	virtual void startMenu(Character & currentCharacter, vector<Character> & characterList, string & Field) = 0;

	// Menu is generated when the character has their turn making the menu in real-time(?) i.e. AbilityCooldowns affect what displays in FightMenu, MoveCounters affect what number of spaces MoveMenu shows
	virtual void printMenu(Character & currentCharacter, vector<Character> & characterList, string & Field) = 0;         // display(s) text of the menu //currentCharacter holds what the character can do i.e. moves/abilities to use for FightMenu or the movement counter for MoveMenu
	
	// Also generated to some degree like printMenu i.e. asks which ability to use in FightMenu but different characters have different Abilities
	virtual void askForResponse(Character & currentCharacter, vector<Character> & characterList, string & Field) = 0;    // prompts for responses to the menu options
	//string & currentAction, int & menuNum, bool & terminate
private:
	
};