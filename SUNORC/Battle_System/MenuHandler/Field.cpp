#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
using namespace std;
#include "Field.h"
#include <time.h>

Field::Field(int maxWidth, int maxHeight)
	:width(maxWidth), height(maxHeight), grid(new char *[height])
{



	/*for (int i = 0; i < height+1; ++i) // Iterate through every row
	{
		grid[i] = new char[width + 1]; // each row is now initialized as an array
		int j;
		for (j = 0; j < width; ++j) // Iterate through every cell in row 'i'
			grid[i][j] = '_'; // Assign every cell within the grid to the character '_'
		grid[i][j] = '\0'; // This loop will set all the last index values to a null character. This way, when we want to print out the field, we can stop at every null char
	
	}
	*/
}

void Field::generateRandomField()
{
    srand(time(NULL));
    int randomHeight = Field::currentHeight = rand() % (Field::height / 2) + Field::height / 2; // The # of rows that this grid can be is any number between 1/2 the max height and the max height
    cout << "Random Height: " << randomHeight << endl;
    int minActiveCells = Field::width * .3 / 1; // The number of minimum active cells (the lower bound for our randomizer below. At minimum, our active cell count will be minActiveCells
 
   for (int i = 0; i < randomHeight; ++i) // Iterate through every row
	{
	    /*int rowWidth = rand() % (Field::width - minActiveCells) + minActiveCells; // The width of the current row becomes a random integer between (total width of row - total # of minimum active cells in that row) and (total width of row) Ex. max width (total width)  = 10, total # minimum active cells = 3. The row width will be some integer betweeen 3 and 10.
	    cout << "Current rowWidth: " << rowWidth << endl;
	    dimensions.push_back(rowWidth); // Fill the slot for our current row's dimension in the dimensions data member
	    int rowOffset = createRowOffset(rowWidth); // In order to center the current row so that it isn't left aligned, we need to create a padding on both the right and left sides. The padding will be denoted as ''
	    //grid[i] = new char[width + 1]; // each row is now initialized as an array
	    grid[i] = new char[Field::width]; // We don't need a null terminator right now, but the above line shows how to do it */
	    generateCurrentRow(i, minActiveCells);
	    fillCurrentRow(i); // Fills the cells of the current row with either null chars or underscores depending on if the cells are active  
	} 
}

/*void Field::insertCharacter(Character & c)
{
    int coords[2] = { 0,1 }; // Placeholder for now; we want to randomly generate these coordinates
    c.setCoords(coords[0], coords[1]);
    characters.push_back(c);
} */


void Field::generateCurrentRow(int currentRow, int minActiveCells)
{
    int rowWidth = rand() % (Field::width - minActiveCells) + minActiveCells; // The width of the current row becomes a random integer between (total width of row - total # of minimum active cells in that row) and (total width of row) Ex. max width (total width)  = 10, total # minimum active cells = 3. The row width will be some integer betweeen 3 and 10.
    dimensions.push_back(rowWidth); // Fill the slot for our current row's dimension in the dimensions data member
	    int rowOffset = createRowOffset(rowWidth); // In order to center the current row so that it isn't left aligned, we need to create a padding on both the right and left sides. The padding will be denoted as ''
	    //grid[i] = new char[width + 1]; // each row is now initialized as an array
	    grid[currentRow] = new char[Field::width]; // We don't need a null terminator right now, but the above line shows how to do it
}


void Field::fillCurrentRow(int currentRow)
{
    // This loop will set all the last index values to a null character. This way, when we want to print out the field, we can stop at every null char
    for ( int i = 0; i < Field::width; ++i)
    {
	if (i < Field::offsets[currentRow] || i >= Field::offsets[currentRow] + Field::dimensions[currentRow])
	    grid[currentRow][i] = '\0';
	else
	    grid[currentRow][i] = '_';
    }

}


int Field::createRowOffset(int rowWidth) // This function will center the current row in between the left and right grid boundaries
{
    int offset = (Field::width - rowWidth) / 2;
    Field::offsets.push_back(offset);
    return offset;
}


void Field::printField()
{
	//grid[2][2] = 'a';
	//grid[2][3] = 'b';
	//for (int j = 0; grid[0][j] != '\0'; ++j)
	printFieldTop(); // Prints the top boundary of the field
	/*for (int j = 0; j < Field::dimensions[0]; ++j) // Prints out the topmost line of the grid
		cout << " _"; */
	
	for (int i = 0; i < Field::currentHeight; ++i)
		printCell(i, Field::grid);
	cout << endl << endl;;
	//printCharacters();
}

void Field::printFieldTop()
{
    for (int i = 0; i < Field::height; ++i)
    {
	if (grid[0][i] != '\0') // If the cell we're looking at in the first row is an active cell, then add a roof to the cell
	    (i == 0 || grid[0][i-1] == '\0') ? cout << " _" : cout << " _";
	    //cout << " _";
	else
	    cout << "  "; // If it's an inactive cell, just move past it.
    }
}

void Field::printCell(int x, char ** grid)
{
	cout << endl;
	/*for (int i = 0; i < Field::offsets[x]; ++i) // Print out a bunch of space to symbolize the row offset
	    cout << "  ";*/
	for (int j = 0; j < Field::width; ++j) // While we're still within the boundaries of the grid's current row...
	{
	        if (grid[x][j] == '\0')
		{
		    if (x < currentHeight - 1 && grid[x+1][j] != '\0') // If the cell in the row below (in the same column) is an active cell, then place an underscore so that the grid looks complete on the top side of that cell
		    {
		        if (j < Field::offsets[x])
			    cout << " _";
			else
		            cout << "_ ";

		    }
		    else
		        cout << "  ";
		}
		else 
		{
		    cout << "|" << grid[x][j]; // print out the contents of the current cell
		    if (j == offsets[x] + dimensions[x] -1)
			cout << "|";
		}
	}
	//cout << "|";
	// This printing will be to cover up the baldness of the row below ours
	/*if (x < height-1) // If this is the last row (if it's the last row, we don't have to cover up the baldness of any rows below, because it IS the last row.
	{
	    for (int i = 0; i < dimensions[x+1] - dimensions[x]; ++i)
		cout << "_" << " ";
	}	*/
}

/*void Field::printCharacters()
{

	cout << "Name" << setw(20) << "Symbol" << setw(10) << "Status" << setw(10) << "Health" << setw(15) << "Coordinates" << endl;
	cout << "-----------------------------------------------------------" << endl;
	for (auto character : characters)
	{
		character.printStats();
	}
	cout << endl;
} */


Field::~Field()
{
    
    for (int i = 0; i < Field::currentHeight; ++i)
    {
	delete[] grid[i];
	cout << "Deleted row: " << i << endl;
    }
    delete[] grid;

}







