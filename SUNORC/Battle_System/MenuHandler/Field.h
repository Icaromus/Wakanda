#pragma once
//#include "Character.h"
#include <vector>
#include "../Character/Character.h"
#include "../Character/Point.cpp"
class Field {

private:
	//vector<Character> characters; // List of all the characters currently on the field
	int width, height, currentHeight;
	char **grid;
	std::vector<int> dimensions; // Stores the sizes of every row in the grid
	std::vector<int> offsets; // Offset values for each row, so that they can be more centered instead of left aligned	
	std::vector<Point> occupiedCells; // Keeps track of all the cells active characters occupy

public:
	Field(int maxWidth, int maxHeight);

	void generateRandomField();

	int createRowOffset(int rowWidth);

//	void insertCharacter(Character & c);

	void generateCurrentRow(int currentRow, int minActiveCells);

	void fillCurrentRow(int currentRow);

	void printField();

	void printFieldTop();

	void printCell(int x, char ** grid);

        void insertCharacters(vector<Character> & Characters);

	void setCharacterOrder(vector<Character> & characters);

        static void insertAlly(Character & c, int upperLimit);

	static void insertEnemy(Character & c, int lowerLimit);

	static void Field::placeCharacter( Character & c, int partition);

//	void printCharacters();

    ~Field();
};
