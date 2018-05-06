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
	string message = "not inside.";

public:
	explicit Field(int maxWidth, int maxHeight);

	Field(const Field & f);

	Field();
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

        void insertAlly(Character & c, int upperLimit);

	void insertEnemy(Character & c, int lowerLimit);

	void placeCharacter( Character & c, int partition);

	bool contains(std::vector<std::string> vec, string affinity);

	bool contains(std::vector<Point> vec, Point currentLoc);

	static char** copyGrid(const Field & f);

//	void printCharacters();

    ~Field();
};
