#include "MoveMenu.h"

#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>

void MoveMenu::startMenu(Character & currentCharacter, vector<Character>& characterList, string & Field)
{
	setCancelledMovement(false);

	while (currentCharacter.GetCounterBox().MoveCount > 0)
	{
		printMenu(currentCharacter, characterList, Field);
		askForResponse(currentCharacter, characterList, Field);
		if (hasCancelledMovement)
			break;
	}
}

void MoveMenu::printMenu(Character & currentCharacter, vector<Character> & characterList, string & Field)
{
	cout << currentCharacter.GetCounterBox().MoveCount << " / " << currentCharacter.GetCounterBox().MaxMoveCount << endl;
	// placeholder
	std::ifstream inFile;
	inFile.open("MoveMenu.txt");
	std::string line;
	while (std::getline(inFile, line))
	{
		std::cout << line << std::endl;
	}
	inFile.close();
	
}

void MoveMenu::askForResponse(Character & currentCharacter, vector<Character> & characterList, string & Field)
{
	char response1;
	int response2;
	cout << "Select a direction to move to: ";
	cin >> response1;
	if (response1 == 'b' || response1 == 'B')
	{
		setCancelledMovement(true);
		return;
	}

	cout << "How far do you want to move? Max: " << currentCharacter.GetCounterBox().MoveCount << " ";
	cin >> response2;
	if (response2 == 'b' || response2 == 'B')
	{
		setCancelledMovement(true);
		return;
	}

	if (response2 < 0 || response2 > currentCharacter.GetCounterBox().MoveCount)
	{
		cout << "That movement is not possible. Input a non negative number that is less than or equal to " << currentCharacter.GetCounterBox().MoveCount << "." << endl;
		return;
	}

	Point newLoc;
	// must add BorderOfMap Checking Later inside each case
	switch (response1)
	{
	case 'U':
		newLoc = currentCharacter.GetCharLoc().add(Point(0.0, response2));
		if (pointIsOccupiedByChar(newLoc, characterList, Field))
		{
			cout << "Point is occupied by another character." << endl;
			return;
		}
		break;
	case 'D':
		newLoc = currentCharacter.GetCharLoc().add(Point(0.0, 0 - response2));
		if (pointIsOccupiedByChar(newLoc, characterList, Field))
		{
			cout << "Point is occupied by another character." << endl;
			return;
		}
		break;
	case 'R':
		newLoc = currentCharacter.GetCharLoc().add(Point(response2, 0.0));
		if (pointIsOccupiedByChar(newLoc, characterList, Field))
		{
			cout << "Point is occupied by another character." << endl;
			return;
		}
		break;
	case 'L':
		newLoc = currentCharacter.GetCharLoc().add(Point(0 - response2, 0.0));
		if (pointIsOccupiedByChar(newLoc, characterList, Field))
		{
			cout << "Point is occupied by another character." << endl;
			return;
		}
		break;
	}

	currentCharacter.SetCharLoc(newLoc);
	currentCharacter.SetMoveCounter(currentCharacter.GetCounterBox().MoveCount - response2);
	// then updateField if needed
}

bool MoveMenu::pointIsOccupiedByChar(Point newLoc, vector<Character> & characterList, string & Field)
{
	bool isOccupied = false;
	for (unsigned int i = 0; i < characterList.size(); ++i)
	{
		if (newLoc.x() == characterList[i].GetCharLoc().x() && newLoc.y() == characterList[i].GetCharLoc().y())
		{
			isOccupied = true;
			break;
		}
	}

	return isOccupied;
}

void MoveMenu::decreaseMoveCounter(Character & currentCharacter, int decrement)
{
	currentCharacter.SetMoveCounter(currentCharacter.GetCounterBox().MoveCount - decrement);
}

void MoveMenu::updateField(Character & currentCharacter, vector<Character> & characterList, string & Field)
{
}

/*
void MoveMenu::resetMoveCounter(Character & currentCharacter)
{
}
void MoveMenu::resetAllMoveCounters(vector<Character> & characterList)
{
}
*/

void MoveMenu::setCancelledMovement(bool state)
{
	hasCancelledMovement = state;
}

bool MoveMenu::getCancelledMovement()
{
	return hasCancelledMovement;
}
