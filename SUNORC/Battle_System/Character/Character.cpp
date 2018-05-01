#include "Character.h"
#include <map>

CharStats::CharStats(int Attack, int Defense, int Speed, int CurHealth, int MaxHealth)
	: Atk(Attack), Def(Defense), Spd(Speed), CurHP(CurHealth), MaxHP(MaxHealth)
{
}

CharStats::CharStats(const CharStats& inChar)
	: Atk(inChar.Atk), Def(inChar.Def), Spd(inChar.Spd), CurHP(inChar.CurHP), MaxHP(inChar.MaxHP)
{
}

CounterBox::CounterBox(int MoveCount, int MaxMoveCount, int ActionCount, int MaxActionCount)
	: MoveCount(MoveCount), MaxMoveCount(MaxMoveCount), ActionCount(ActionCount), MaxActionCount(MaxActionCount)
{
}

CounterBox::CounterBox(const CounterBox& inCountBox)
	: MoveCount(inCountBox.MoveCount), MaxMoveCount(inCountBox.MaxMoveCount), ActionCount(inCountBox.ActionCount), MaxActionCount(inCountBox.MaxActionCount)
{
}

Weapon::Weapon(string Name, int AttackModifier, int AttackRange)
	: Name(Name), AttackModifier(AttackModifier), AttackRange(AttackRange)
{
}

Weapon::Weapon(const Weapon& inWeap)
	: Name(inWeap.Name), AttackModifier(inWeap.AttackModifier), AttackRange(inWeap.AttackRange)
{
}

Item::Item(string Name, int Quantity, string Effect)
	: Name(Name), Quantity(Quantity), Effect(Effect)
{
}

Item::Item(const Item& inItem)
	: Name(inItem.Name), Quantity(inItem.Quantity), Effect(inItem.Effect)
{
}

Move::Move(string Name, int Cooldown, double damageMod, string Effect)
	: Name(Name), currentCooldown(0), maxCooldown(Cooldown), damageModifier(damageMod),Effect(Effect)
{
}

Move::Move(const Move& inMove)
	: Name(inMove.Name), currentCooldown(0), maxCooldown(inMove.maxCooldown), damageModifier(inMove.damageModifier), Effect(inMove.Effect)
{
}

Move::Move()
	:Name("Struggle"), currentCooldown(0), maxCooldown(0), damageModifier(0.0), Effect("")
{
}

// constructor
Character::Character(		// constructor
	string Name,	
	Weapon Weapon,
	CounterBox Counters,
	vector<Move> Moves,
	vector<Item> Items,
	string StatusEffect,
	Point Loc,
	char Symbol,
	CharStats inStats)
	: CharName(Name), CharWeapon(Weapon), Counters(Counters), MoveList(Moves),
	  ItemList(Items), CharStatus(StatusEffect), CharLoc(Loc), CharSymbol(Symbol), Stats(inStats)
	{
	}

// Character Name
string Character::GetCharName(){ return CharName; }
void Character::SetCharName(string newCharName) { CharName = newCharName; }

// Character Weapons
Weapon Character::GetCharWeapon(){ return CharWeapon; }
void Character::SetCharWeapon(Weapon newWeapon){ CharWeapon = newWeapon; }

// Character Move List and Item List
vector<Move> Character::GetMoveList(){ return MoveList; }
void Character::SetMoveList(vector<Move> newMoveList) { MoveList = newMoveList; }
void Character::SetMoveCooldown(int entry) { MoveList[entry].currentCooldown += MoveList[entry].maxCooldown; }

vector<Item> Character::GetItemList() { return ItemList; }
void Character::AddNewItem(Item newItem) { ItemList.push_back(newItem); }
void Character::ChangeItemCount(int entry, int amount)
{
	ItemList[entry].Quantity += amount;
	if (ItemList[entry].Quantity <= 0)
		ItemList.erase(ItemList.begin() + entry);
}

// Character Affinity
string Character::GetCharAffinity() { return CharAffinity; }
void Character::SetCharAffinity(string newAffinity) { CharAffinity = newAffinity; }

// Character Status Effect
string Character::GetCharStatus(){ return CharStatus; }
void Character::SetCharStatus(string newStatus) { CharStatus = newStatus; }

// Move Counter and Action Counter
CounterBox Character::GetCounterBox(){ return Counters; }
void Character::SetMoveCounter(int newCounter) { Counters.MoveCount = newCounter; }
void Character::SetActionCounter(int newCounter) { Counters.ActionCount = newCounter; }
void Character::ResetCounters()
{ 
	Counters.MoveCount = Counters.MaxMoveCount;
	Counters.ActionCount = Counters.MaxActionCount;
}

// Character Location
Point Character::GetCharLoc(){ return CharLoc; }
void Character::SetCharLoc(Point newCharLoc) { CharLoc = newCharLoc; }
char Character::GetCharSymbol(){ return CharSymbol; }
void Character::SetCharSymbol(char newCharSymbol) { CharSymbol = newCharSymbol; }

// Character Stats
CharStats Character::GetCharStats() { return Stats; }

void Character::SetCharStats(int newAtk, int newDef, int newSpd, int newCurHP, int newMaxHP)
{
	Stats.Atk = newAtk;
	Stats.Def = newDef;
	Stats.Spd = newSpd;
	Stats.CurHP = newCurHP;
	Stats.MaxHP = newMaxHP;
}
