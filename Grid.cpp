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
    
    surroundingCells = new int[4]; 

    //Initialize grid with nullptr
    grid = new Critter**[rows]; 
    for(int r = 0; r < rows; r++)
    {
        grid[r] = new Critter*[columns]; 
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
        } while(grid[randRow][randCol] != nullptr);
        
        grid[randRow][randCol] = new Ant(randRow, randCol); 
    }

    for(int d = 0; d < doodleBugs; d++)
    {
        do
        {
            randRow = rand() % rows; 
            randCol = rand() % columns; 
        } while(grid[randRow][randCol] != nullptr);
        
        grid[randRow][randCol] = new Doodlebug(randRow, randCol); 
    }
}

int Grid::checkCell(int row, int col)
{
    if(grid[row][col] == nullptr)
    {
        return 0;
    }
    else
    {
        return grid[row][col]->getType();
    }
}

void Grid::clearCell(int row, int col)
{
    grid[row][col] = nullptr;
}

void Grid::moveCritters()
{
    bool validMove; 
    int newRow; 
    int newCol;
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < columns; c++)
        {
            if(grid[r][c] != nullptr && !grid[r][c]->getMoved()) //Check to see if cell is critter, and critter has not already moved
            {
                getSurroundingCells(r, c);             
                validMove = grid[r][c]->move(surroundingCells); //critter row and column update, if a valid move is made 
                if(validMove)
                {
                    newRow = grid[r][c]->getRow(); //get the updated row, changed in critter instance 
                    newCol = grid[r][c]->getCol(); //get the updated column, changed in critter instance 
                    grid[newRow][newCol] = grid[r][c]; //new cell equals the critter with updated row and column 
                    grid[r][c] = nullptr; //clear the previous cell
                } 
            } //if no valid move was made, we move on to the next cell
        }
    }
    //We loop again to reset Critter::moved to false, which allows critters to move again the next round
    //Print here as well
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < columns; c++)
        {
            if(grid[r][c] != nullptr)
            {
                grid[r][c]->setToNotMoved(); 
                if(grid[r][c]->getType() == ANT)
                {
                    std::cout << " O "; 
                }
                else
                {
                    std::cout << " X "; 
                }
            }
            else
            {
                std::cout << "  "; 
            }
        }
        std::cout << std::endl;
    }
}

void Grid::getSurroundingCells(int row, int col)
{
    for(int cell = 0; cell < 4; cell++)
    {
        surroundingCells[cell] = -1; //-1 means the cell is a wall (ie, moving in that direction is off grid)
    }

    if(row - 1 >= 0) //UP = (critter's current row) - 1, only change value of surroundingCells[0] if Up is not off grid
    {
        if(grid[row - 1][col] == nullptr)
        {
            surroundingCells[0] = 0;  
        }
        else if(grid[row - 1][col]->getType() == ANT)
        {
            surroundingCells[0] = 1;  
        }
        else if(grid[row - 1][col]->getType() == DOODLEBUG)
        {
            surroundingCells[0] = 2;  
        }
    }
    if(col + 1 < columns) //Right, only change if Right is not off grid
    {
        if(grid[row][col + 1] == nullptr)
        {
            surroundingCells[1] = 0;  
        }
        else if(grid[row][col + 1]->getType() == ANT)
        {
            surroundingCells[1] = 1;  
        }
        else if(grid[row][col + 1]->getType() == DOODLEBUG)
        {
            surroundingCells[1] = 2;  
        }
    }
    if(row + 1 < rows) //Down, only change if going Down is not off grid
    {
        if(grid[row + 1][col] == nullptr)
        {
            surroundingCells[2] = 0;  
        }
        else if(grid[row + 1][col]->getType() == ANT)
        {
            surroundingCells[2] = 1;  
        }
        else if(grid[row + 1][col]->getType() == DOODLEBUG)
        {
            surroundingCells[2] = 2;  
        }
    }
    if(col - 1 >= 0) //Left, only change if going Left is not off grid
    {
        if(grid[row][col - 1] == nullptr)
        {
            surroundingCells[3] = 0;  
        }
        else if(grid[row][col - 1]->getType() == ANT)
        {
            surroundingCells[3] = 1;  
        }
        else if(grid[row][col - 1]->getType() == DOODLEBUG)
        {
            surroundingCells[3] = 2;  
        }
    }
}

int Grid::getSteps()
{
    return steps;
}

Grid::~Grid() 
{
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < columns; c++)
        {
            if(grid[r][c] != nullptr)
            {
                delete grid[r][c];
            }
        }
        delete [] grid[r]; 
    }
    delete [] grid;
    delete [] surroundingCells; 
}
