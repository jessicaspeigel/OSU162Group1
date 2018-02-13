/*********************************************************************
** Group Project 1 Program name: Predator-Prey Game
** Author: Ryan Mack
** Date: 2/5/2018
** Description: Specification file for the Simulation class.
*********************************************************************/

#ifndef GRID_HPP
#define GRID_HPP
#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"
#include <string>
using std::string;

class Grid
{
enum cells {SPACE, ANT, DOODLEBUG}; 

private:
	int steps;
	int ants;
	int doodleBugs;
	int rows;
	int columns;
    	int* surroundingCells;
    	Critter*** grid;	

public:
	Grid();
	
	
    /****************************************************************************
    ** Randomly place ants and doodlebugs in grid
    ****************************************************************************/
    void fillGrid(); 
	
	
    /****************************************************************************
    ** Loops through Grid::grid and calls move function for each critter, mutates
    ** grid as necessary
    ****************************************************************************/
    void moveCritters();
	
	
	/****************************************************************************
    ** Prints the grid
    ****************************************************************************/
	void printGrid();
	
	
    /****************************************************************************
    ** Input: int row, int col. If grid[row][col] == nullptr, else returns 
    ** the critter's type.
    ****************************************************************************/
    int checkCell(int, int); 
    void clearCell(int, int); 
	
	
    /****************************************************************************
    ** Input: int row, int col (the location of a critter in the grid). For each 
    ** critter position, this function mutates the Grid::surroundingCells array. 
    ** surroundingCells[0] = cell above critter
    ** surroundingCells[1] = cell right of critter
    ** surroundingCells[2] = cell below critter
    ** surroundingCells[3] = cell left of critter
    ****************************************************************************/
    void getSurroundingCells(int, int);

	/****************************************************************************
    ** Getters and setters for number of steps
    ****************************************************************************/
    int getSteps();
	void setSteps(int steps);
    ~Grid();
};

#endif
