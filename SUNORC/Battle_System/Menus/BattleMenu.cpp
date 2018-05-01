#include "BattleMenu.h"

#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>


void BattleMenu::startMenu(Character & currentCharacter, vector<Character>& characterList, string & Field)
{
	setTurnHasEnded(false);

	while (!turnHasEnded)
	{
		printMenu(currentCharacter, characterList, Field);
		askForResponse(currentCharacter, characterList, Field);
	}
}

void BattleMenu::printMenu(Character & currentCharacter, vector<Character>& characterList, string & Field)
{
	std::ifstream inFile;
	inFile.open("MainMenu.txt");
	std::string line;
	while (std::getline(inFile, line))
	{
		std::cout << line << std::endl;
	}
	inFile.close();
	/*
	cout << currentCharacter.GetCharName() << "'s Turn:" << endl;
	cout << "1. Fight" << endl;
	cout << "2. Move" << endl;
	cout << "3. Item" << endl;
	cout << "4. Pull Out" << endl;
	cout << "5. End Turn" << endl;
	*/
}

void BattleMenu::askForResponse(Character & currentCharacter, vector<Character> & characterList, string & Field)
{
	char response;
	while (true)
	{
		cout << "Select an action: ";
		cin >> response;
		if (response > 90)
			response -= 32;
		if (response == 'F' || response == 'M' || response == 'I' || response == 'P' || response == 'E')
			break;
		else
			cout << "Pick a valid option (F, M ,I, P, E)" << endl;
		/*
		if (response <= 5 && response >= 1)
			break;
		else
			cout << "Pick an option between 1-5" << endl;
		*/
	}
	FightMenu Fighting;
	MoveMenu Moving;
	ItemMenu Items;


	switch (response)
	{
	case 'F':
	{
		if (currentCharacter.GetCounterBox().ActionCount == 0)
		{
			cout << "You have already used your Action for this turn." << endl;
			break;
		}
		Fighting.startMenu(currentCharacter, characterList, Field);
		if (Fighting.getActionCarriedOut())
			currentCharacter.SetActionCounter(currentCharacter.GetCounterBox().ActionCount - 1);
		break;
	}
	case 'M':
	{
		if (currentCharacter.GetCounterBox().MoveCount == 0)
		{
			cout << "You have already used your Movement for this turn." << endl;
			break;
		}
		Moving.startMenu(currentCharacter, characterList, Field);
		break;
	}
	case 'I':
	{
		if (currentCharacter.GetCounterBox().ActionCount == 0)
		{
			cout << "You have already used your Action for this turn." << endl;
			break;
		}
		Items.startMenu(currentCharacter, characterList, Field);
		if (Items.getUsedAction())
			currentCharacter.SetActionCounter(currentCharacter.GetCounterBox().ActionCount - 1);
		break;
	}
	case 'P':
	{
		if (currentCharacter.GetCounterBox().ActionCount == 0 || currentCharacter.GetCounterBox().MoveCount < currentCharacter.GetCounterBox().MaxMoveCount)
		{
			cout << "You have already used your Action or Movement for this turn: you're committed to fighting." << endl;
			break;
		}
		PullOut(currentCharacter, characterList);
		break;
	}
	case 'E':
	{
		setTurnHasEnded(true);
		break;
	}
	}
}

bool BattleMenu::hasActionCounterRemaining(Character & currentCharacter)
{
	return currentCharacter.GetCounterBox().ActionCount == currentCharacter.GetCounterBox().MaxActionCount;
}

bool BattleMenu::hasMoveCounterRemaining(Character & currentCharacter)
{
	return currentCharacter.GetCounterBox().MoveCount == currentCharacter.GetCounterBox().MaxMoveCount;
}

void BattleMenu::PullOut(Character & currentCharacter, vector<Character> & characterList)
{
	// some calculations between currentCharacter stats vs enemies
	double escapeChance = (currentCharacter.GetCharStats().Spd) / ((currentCharacter.GetCharStats().Spd) + (getCharacterWithGreatestSpeed(characterList).GetCharStats().Spd));

	default_random_engine RNGsus;
	uniform_int_distribution<int> Distribution(0, 100);
	double chanceRoll = (double)(Distribution(RNGsus)) / 100.0;

	string hitEnter;
	// if currentCharacter wins
	if (chanceRoll <= escapeChance)
	{
		// leave battle
		cout << "You have successfully escaped the battle." << endl;
		cout << "Press ENTER to continue: ";
		cin >> hitEnter;
		setBattleHasEnded(true);
	}
	// else
	else
	{
		// end turn
		cout << "You have failed to escape the battle." << endl;
		cout << "Press ENTER to continue: ";
		cin >> hitEnter;
		setTurnHasEnded(true);
	}
}

void BattleMenu::setTurnHasEnded(bool state)
{
	turnHasEnded = state;
}

void BattleMenu::setBattleHasEnded(bool state)
{
	battleHasEnded = state;
}

bool spdCompare(Character & currentCharacter, Character & otherCharacter)
{
	return currentCharacter.GetCharStats().Spd > otherCharacter.GetCharStats().Spd;
}

Character BattleMenu::getCharacterWithGreatestSpeed(vector<Character> & characterList)
{
	vector<Character> sortedBySpeed;
	for (unsigned int i = 0; i < characterList.size(); ++i)
	{
		if (characterList[i].GetCharAffinity() == string("Enemy"))
			sortedBySpeed.push_back(characterList[i]);
	}
	sort(sortedBySpeed.begin(), sortedBySpeed.end(), spdCompare);
	return sortedBySpeed[0];
}