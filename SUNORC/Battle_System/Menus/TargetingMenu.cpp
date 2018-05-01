#include "TargetingMenu.h"

void TargetingMenu::startMenu(Character & currentCharacter, vector<Character> & characterList, string & Field)
{
	setCancelledAttack(false);
	setSuccessfulAction(false);

	while (!successfulAction)
	{
		resetTargetsList();
		generateTargetsList(currentCharacter, characterList);
		printMenu(currentCharacter, characterList, Field);
		askForResponse(currentCharacter, characterList, Field);
		if (hasCancelledAttack)
			break;
	}
	cout << "Finished Targeting SubMenu. " << endl;
}

void TargetingMenu::printMenu(Character & currentCharacter, vector<Character> & characterList, string & Field)
{
	if (targetsList.empty())
	{
		cout << "No targets within range" << endl;
		setCancelledAttack(true);
		return;
	}

	cout << "Available Targets" << endl;
	for (unsigned int i = 0; i < targetsList.size(); ++i)
		cout << left << setw(8) << i + 1 << targetsList[i]->GetCharName() << endl;
}

void TargetingMenu::askForResponse(Character & currentCharacter, vector<Character> & characterList, string & Field)
{
	if (getCancelledAttack())
	{
		cout << "cancelling attack" << endl;
		return;
	}

	int response;
	cout << "Select a target: ";
	cin >> response;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	if (response > 0)
		--response;
	
	if (response == 'b' || response == 'B')
	{
		setCancelledAttack(true);
		return;
	}

	string confirmation;
	cout << "Are you sure you want to attack " << (targetsList[response])->GetCharName() << "? ";
		
	getline(cin, confirmation);

	if (confirmation == string("y") || confirmation == string("Y"))
		successfulAction = true;

	targetChar = (targetsList[response]);

	return;
}

void TargetingMenu::generateTargetsList(Character & currentCharacter, vector<Character> & characterList)
{
	for (unsigned int i = 0; i < characterList.size(); ++i)
	{
		cout << characterList[i].GetCharName() << endl;
		if (currentCharacter.GetCharLoc().dist(characterList[i].GetCharLoc()) <= currentCharacter.GetCharWeapon().AttackRange && currentCharacter.GetCharName() != characterList[i].GetCharName())
			targetsList.push_back(&characterList[i]);
	}
}

void TargetingMenu::resetTargetsList()
{
	targetsList.clear();
}

void TargetingMenu::setSuccessfulAction(bool state)
{
	successfulAction = state;
}

bool TargetingMenu::getCancelledAttack()
{
	return hasCancelledAttack;
}

void TargetingMenu::setCancelledAttack(bool state)
{
	hasCancelledAttack = state;
}

bool TargetingMenu::hasCompletedAction()
{
	return successfulAction;
}

Character * TargetingMenu::getTargetedCharacter()
{
	return targetChar;
}
