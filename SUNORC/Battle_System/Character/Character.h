#pragma once
#include <string>
#include <vector>
#include "Point.cpp"
#include <map>

using namespace std;

struct CharStats 
{
	int Atk;
	int Def;
	int Spd;
	int CurHP;
	int MaxHP;

	explicit CharStats(int Attack, int Defense, int Speed, int CurHealth, int MaxHealth);
	CharStats(const CharStats& inChar);
};

struct CounterBox
{
	int MoveCount;
	int MaxMoveCount;
	int ActionCount;
	int MaxActionCount;

	explicit CounterBox(int MoveCount, int MaxMoveCount, int ActionCount, int MaxActionCount);
	CounterBox(const CounterBox& inCountBox);
};

// temporary obviously
// SHOULD PROBABLY BE MADE INTO CHARACTER EQUIPMENT AT SOME POINT
struct Weapon
{
	string Name;
	int AttackModifier;
	int AttackRange;

	explicit Weapon(string Name, int AttackModifier, int AttackRange);
	Weapon(const Weapon& inWeap);
};

// temporary obviously
struct Item
{
	string Name;
	int Quantity;
	string Effect;

	explicit Item(string Name, int Quantity, string Effect);
	Item(const Item& inItem);
};

// obviously temporary
struct Move
{
	string Name;
	int currentCooldown;
	int maxCooldown;
	double damageModifier;
	string Effect;

	explicit Move(string Name, int Cooldown, double damageMod, string Effect);
	Move(const Move& inMove);
	Move();
};


class Character
{
public:
	Character(			// constructor
		string Name,
		Weapon Weapon,
		CounterBox Counters,
		vector<Move> Moves,
		vector<Item> Items,
		string StatusEffect,
		Point Loc,
		char Symbol,
		CharStats inStats);

	string GetCharName();
	void SetCharName(string);

	Weapon GetCharWeapon();
	void SetCharWeapon(Weapon newWeapon);
	
	vector<Move> GetMoveList();
	void SetMoveList(vector<Move>);
	void SetMoveCooldown(int entry);

	vector<Item> GetItemList();
	void AddNewItem(Item);
	void ChangeItemCount(int entry, int amount);

	string GetCharAffinity();
	void SetCharAffinity(string newAffinity);

	string GetCharStatus();
	void SetCharStatus(string);

	CounterBox GetCounterBox();
	void SetMoveCounter(int newCounter);
	void SetActionCounter(int newCounter);
	void ResetCounters();

	Point GetCharLoc();
	void SetCharLoc(Point);
	char GetCharSymbol();
	void SetCharSymbol(char);

	CharStats GetCharStats();
	void SetCharStats(int newAtk, int newDef, int newSpd, int newCurHP, int newMaxHP);

private:
	string CharName;
	Weapon CharWeapon;

	vector<Move> MoveList;
	vector<Item> ItemList;

	string CharAffinity;
	string CharStatus;

	CounterBox Counters;

	Point CharLoc;
	char CharSymbol;
	CharStats Stats;
};