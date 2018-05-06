#include <iostream>
#include <string>
using namespace std;
#include "../Character/Character.h"
#include "PriorityQueue.h"
#include "MenuHandler.h"
#include "Field.h"

#include "../Menus/Menu.h"
#include "../Menus/BattleMenu.h"
#include "../Menus/TargetingMenu.h"
#include "../Menus/MoveMenu.h"
#include "../Menus/ItemMenu.h"
#include "../Menus/FightMenu.h"

void sortCharacters(vector<Character> &  chars)
{
	PriorityQueue<Character> pq(chars.size());
	for (auto c : chars)
	{
		pq.insert(c);
	}
	for(int i = 0; i < chars.size(); ++i)
	{
		chars[i] = pq.pop();	
	}
}


int main()
{
    
    vector<Move> Moves;
    vector<Item> Items;
    CharStats stats(1,1,1,1,1);
    CharStats stats1(2,2,2,2,2);
    CharStats stats2(3,3,3,3,3);
    CharStats stats3(4,4,4,4,4);
    CharStats stats4(5,5,5,5,5);
    Weapon weap("Boomstick", 1, 1);
    CounterBox counters(1,1,1,1);
    Point pt(1,1);
    Character char1("Name", weap, counters, Moves, Items, "Healthy", pt, 'c', stats, "Ally");
    //char1.SetCharAffinity("Ally");
    //cout << "char1 affinity: " << char1.GetCharAffinity() << endl;
    Character char2("Name2", weap, counters, Moves, Items, "Healthy", pt, 'd', stats3, "Enemy");
    //char2.SetCharAffinity("Enemy");
    Character char3("Name2", weap, counters, Moves, Items, "Healthy", pt, 'e', stats4, "Enemy");
    //char3.SetCharAffinity("Enemy");
    Character char4("Name2", weap, counters, Moves, Items, "Healthy", pt, 'f', stats1, "Ally");
    //char4.SetCharAffinity("Ally");
    Character char5("Name2", weap, counters, Moves, Items, "Healthy", pt, 'g', stats2, "Enemy");
    //char5.SetCharAffinity("Enemy");

    vector<Character> chars;
    chars.push_back(char1);
    chars.push_back(char2);
    chars.push_back(char3);
    chars.push_back(char4);
    chars.push_back(char5);
    Field f(15, 15);
    //f.printField();
    sortCharacters(chars);
    cout << "Printing characters in char loop" << endl;
    for (int i = 0; i < chars.size(); ++i)
    { 
	    cout << i << " ";
	    cout << chars[i] << " ";
    }
    cout << endl;
    BattleMenu b = BattleMenu();
    FightMenu fight = FightMenu();
    ItemMenu i = ItemMenu();
    TargetingMenu t = TargetingMenu();
    MoveMenu moves = MoveMenu();
    map<string,Menu *> menus;
    menus["Battle"] = &b;
    menus["Fight"] = &fight;
    menus["Item"] = &i;
    menus["Target"] = &t;
    menus["Move"] = &moves;
    // =============== test menu handler =====================
    MenuHandler m(chars, f, menus);
    //m.printField();
    return 0;


}
