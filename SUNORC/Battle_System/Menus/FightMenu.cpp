#include "FightMenu.h"

void FightMenu::startMenu(Character & currentCharacter, vector<Character> & characterList, string & Field)
{
	setActionCarriedOut(false);
	setCancelledFight(false);

	while (!actionCarriedOut)
	{
		FightMenu::printMenu(currentCharacter, characterList, Field);
		FightMenu::askForResponse(currentCharacter, characterList, Field);
		if (hasCancelledFight)
			break;
	}

	cout << "Finished Fight Menu. " << endl;
}

void FightMenu::printMenu(Character & currentCharacter, vector<Character> & characterList, string & Field)
{
	cout << "Abilities: " << endl;
	cout << "####    Name            Cooldown Remaining    Total Cooldown" << endl;
	for (unsigned int i = 0; i < currentCharacter.GetMoveList().size(); ++i)
	{
		cout << left << setw(8) << i+1 << setw(16) << currentCharacter.GetMoveList()[i].Name << right << setw(22) << currentCharacter.GetMoveList()[i].currentCooldown << setw(14) << currentCharacter.GetMoveList()[i].maxCooldown << endl;
	}
}

void FightMenu::askForResponse(Character & currentCharacter, vector<Character> & characterList, string & Field)
{
	cout << "Pick an Ability to use: ";
	int response;
	cin >> response;

	// for indexing purposes; options are printed starting at 1, but needs zero-indexing
	if (response > 0)
		--response;

	if (response == 'b' || response == 'B')
	{
		setCancelledFight(true);
		return;
	}

	TargetingMenu TargetMenu;
	TargetMenu.startMenu(currentCharacter, characterList, Field);

	if (TargetMenu.getCancelledAttack())
	{
		setCancelledFight(true);
		return;
	}

	// if move is carried out
	if (TargetMenu.hasCompletedAction())
	{
		cout << currentCharacter.GetMoveList()[response].Name << endl;
		setCooldownTimer(currentCharacter, response);
		cout << currentCharacter.GetMoveList()[response].currentCooldown << " / " << currentCharacter.GetMoveList()[response].maxCooldown << endl;
		// TODO damage calculation and subtract from TargetMenu.getTargetedCharacter()
		// PlaceHolder Calculations
		calculateDamage(currentCharacter, TargetMenu.getTargetedCharacter(), response);
		
		/*
		TargetMenu.getTargetedCharacter()->SetCharStats(TargetMenu.getTargetedCharacter()->GetCharStats().Atk, 
			TargetMenu.getTargetedCharacter()->GetCharStats().Def, 
			TargetMenu.getTargetedCharacter()->GetCharStats().Spd,
			TargetMenu.getTargetedCharacter()->GetCharStats().CurHP - ((currentCharacter.GetCharStats().Atk * currentCharacter.GetCharWeapon().AttackModifier * currentCharacter.GetMoveList()[response].damageModifier) - TargetMenu.getTargetedCharacter()->GetCharStats().Def),
			TargetMenu.getTargetedCharacter()->GetCharStats().MaxHP);
		*/
		setActionCarriedOut(true);
		//cout << TargetMenu.getTargetedCharacter()->GetCharStats().CurHP - ((currentCharacter.GetCharStats().Atk * currentCharacter.GetCharWeapon().AttackModifier * currentCharacter.GetMoveList()[response].damageModifier) - TargetMenu.getTargetedCharacter()->GetCharStats().Def) << endl;//<< " / " << TargetMenu.getTargetedCharacter()->GetCharStats().MaxHP << endl;
		//cout << currentCharacter.GetMoveList()[response].damageModifier << endl;
	}
	else
		setActionCarriedOut(false);
}

void FightMenu::calculateDamage(Character & currentCharacter, Character * targetedCharacter, int moveEntry)
{
	int totalDamage = (currentCharacter.GetCharStats().Atk * currentCharacter.GetCharWeapon().AttackModifier * currentCharacter.GetMoveList()[moveEntry].damageModifier - targetedCharacter->GetCharStats().Def);
	if (totalDamage <= 0)
		totalDamage = 1;

	targetedCharacter->SetCharStats(targetedCharacter->GetCharStats().Atk,
		targetedCharacter->GetCharStats().Def,
		targetedCharacter->GetCharStats().Spd, 
		targetedCharacter->GetCharStats().CurHP - totalDamage,
		targetedCharacter->GetCharStats().MaxHP);

}

void FightMenu::decreaseCooldownTimers(Character & currentCharacter)
{
	for (unsigned int i = 0; i < currentCharacter.GetMoveList().size(); ++i)
	{
		if (currentCharacter.GetMoveList()[i].currentCooldown > 0)
			--currentCharacter.GetMoveList()[i].currentCooldown;
	}
}

void FightMenu::setCooldownTimer(Character & currentCharacter, int entry)
{
	currentCharacter.SetMoveCooldown(entry);
	//currentCharacter.GetMoveList()[entry].currentCooldown = currentCharacter.GetMoveList()[entry].maxCooldown;
}

void FightMenu::resetAllCooldownTimers(vector<Character> & characterList)
{
}

void FightMenu::setActionCarriedOut(bool state) { actionCarriedOut = state; }
bool FightMenu::getActionCarriedOut() {	return actionCarriedOut; }
void FightMenu::setCancelledFight(bool state) { hasCancelledFight = state; }
bool FightMenu::getCancelledFight() { return hasCancelledFight; }
