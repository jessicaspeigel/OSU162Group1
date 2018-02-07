/*********************************************************************
** Group Project 1 Program name: Predator-Prey Game
** Author: Ryan Mack
** Date: 2/5/2018
** Description: Implementation file for the Grid class.
*********************************************************************/

#include "Menu.hpp"
#include "Grid.hpp"
#include <iostream>
using std::cout;
using std::endl;


Grid::Grid()
{
	steps = Menu::getNumSteps();
	columns = Menu::getColumns();
	rows = Menu::getRows();
	ants = Menu::getNumAnts();
	doodleBugs = Menu::getNumDoodlebugs();

    //Initialize grid with nullptr
    grid = new Critter*[rows]; 
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < columns; c++)
        {
            grid[r][c] = nullptr; 
        }
    }
   
    //Fill the grid with ants and doodlebugs 
    fillGrid(); 

	cout << "\n\nSteps: " << steps << endl;
	cout << "Columns: " << columns << endl;
	cout << "Rows: " << rows << endl;
	cout << "Ants: " << ants << endl;
	cout << "Doodlebugs: " << doodleBugs << endl;
}

void Grid::fillGrid()
{
    int randRow; 
    int randCol; 

    for(int a = 0; a < ants; a++)
    {
        do
        {
            randRow = rand() % rows; 
            randCol = rand() % columns; 
        } while(grid[randRow][randCol] != nullptr)
        
        grid[randRow][randCol] = new Ant(); 
    }

    for(int d = 0; d < doodlebugs; d++)
    {
        do
        {
            randRow = rand() % rows; 
            randCol = rand() % columns; 
        } while(grid[randRow][randCol] != nullptr)
        
        grid[randRow][randCol] = new Doodlebug(); 
    }
}
