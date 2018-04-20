#pragma once
//#include "Character.h"
#include <vector>

class Field {

private:
	//vector<Character> characters; // List of all the characters currently on the field
	int width, height, currentHeight;
	char **grid;
	std::vector<int> dimensions; // Stores the sizes of every row in the grid
	std::vector<int> offsets; // Offset values for each row, so that they can be more centered instead of left aligned	

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

//	void printCharacters();

    ~Field();
};
