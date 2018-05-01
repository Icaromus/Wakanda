#include "ItemMenu.h"

void ItemMenu::startMenu(Character & currentCharacter, vector<Character> & characterList, string & Field)
{
	setBackedOut(false);
	while (!hasUsedAction)
	{
		printMenu(currentCharacter, characterList, Field);
		askForResponse(currentCharacter, characterList, Field);
		if (hasBackedOut)
			break;
	}
}

void ItemMenu::printMenu(Character & currentCharacter, vector<Character> & characterList, string & Field)
{
	cout << "Inventory: " << endl;
	cout << "####    Item Name        Description            Quantity" << endl;
	for (unsigned int i = 0; i < currentCharacter.GetItemList().size(); ++i)
	{
		cout << left << setw(8) << i 
			<< setw(17) << currentCharacter.GetItemList()[i].Name 
			<< setw(23) << currentCharacter.GetItemList()[i].Effect 
			<< right << setw(8) << currentCharacter.GetItemList()[i].Quantity << endl;
	}
}

void ItemMenu::askForResponse(Character & currentCharacter, vector<Character> & characterList, string & Field)
{
	int response;
	cout << "Select an item to use: ";
	cin >> response;

	if (response == 'b' || response == 'B')
	{
		setBackedOut(true);
		return;
	}

	TargetingMenu Target;
	Target.startMenu(currentCharacter, characterList, Field);

	// apply currenctCharacter.GetItemList()[response].Effect to Target.getTargetedCharacter()

	decreaseItemCount(currentCharacter, response, 1);
}

void ItemMenu::decreaseItemCount(Character & currentCharacter, int entry, int amount)
{
	currentCharacter.ChangeItemCount(entry, 0 - amount);
}

void ItemMenu::increaseItemCount(Character & currentCharacter, vector<Item> rewards)
{
	for (unsigned int i = 0; i < rewards.size(); ++i)
	{
		bool needToAddNewItem = true;
		for (unsigned int n = 0; n < currentCharacter.GetItemList().size(); ++i)
		{
			if (rewards[i].Name == currentCharacter.GetItemList()[n].Name)
			{
				currentCharacter.ChangeItemCount(n, rewards[i].Quantity);
				needToAddNewItem = false;
				break;
			}
		}
		if (needToAddNewItem)
			currentCharacter.AddNewItem(rewards[i]);
	}
}

void ItemMenu::setBackedOut(bool state)
{
	hasBackedOut = state;
}

bool ItemMenu::getBackedOut()
{
	return hasBackedOut;
}

void ItemMenu::setUsedAction(bool state)
{
	hasUsedAction = state;
}

bool ItemMenu::getUsedAction()
{
	return hasUsedAction;
}
