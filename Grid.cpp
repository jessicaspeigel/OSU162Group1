/*********************************************************************
** Group Project 1 Program name: Predator-Prey Game
** Author: Group 1
** Date: 2/5/2018
** Description: Implementation file for the Grid class.
*********************************************************************/

#include "Menu.hpp"
#include "Grid.hpp"
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setfill;
using std::setw;


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
    Critter* thisCritter; 
    Critter* newCritter;
    bool deadCritter = false;   ///If a doodlebug starves, don't ask if it can breed.
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < columns; c++)
        {
            deadCritter = false; //reset deadCritter to false every loop.
            if(grid[r][c] != nullptr)
            { 
                thisCritter = grid[r][c]; 
                if(!thisCritter->getMoved()) //Check to see if cell is critter, and critter has not already moved
                {
                    getSurroundingCells(r, c);             
                    validMove = thisCritter->move(surroundingCells); //critter row and column update, if a valid move is made 
                    if(validMove)
                    {
                        newRow = thisCritter->getRow(); //get the updated row, changed in critter instance 
                        newCol = thisCritter->getCol(); //get the updated column, changed in critter instance 
                        grid[newRow][newCol] = thisCritter; //new cell equals the critter with updated row and column 
                        grid[r][c] = nullptr; //clear the previous cell
                    }
                }
                
                if (thisCritter->getType() == 2) { //If the critter is a Doodlebug
                    if (thisCritter->starvationCheck() == true) { // If the Doodlebug is starving.
                        //cout << "Deleting doodlebug: " << thisCritter << " from row: " << newRow << " / col: " << newCol << endl;
                        newRow = thisCritter->getRow(); //We need to get row and col, in case critter did not move
                        newCol = thisCritter->getCol(); 
                        thisCritter = nullptr;
                        grid[newRow][newCol] = nullptr;
                        // If the doodlebug starves, remove the doodlebug, and make sure no breeding ensues for this critter.
                        // This prevents memory leaks.
                        deadCritter = true;
                    }
                }
                if((deadCritter == false) && thisCritter->readyToBreed())
                {
                    getSurroundingCells(thisCritter->getRow(), thisCritter->getCol());
                    newCritter = thisCritter->breed(surroundingCells);
                    if(newCritter != nullptr)
                    {
                        newRow = newCritter->getRow();
                        newCol = newCritter->getCol();
                        grid[newRow][newCol] = newCritter;
                    }
                }
            } //if no valid move was made, we move on to the next cell
        }
    }
    printGrid();
}


void Grid::printGrid()
{
    // Constants
    const char FILLCHAR = '-';
    const char ANTCHAR = 'O';
    const char BUGCHAR = 'X';
    const char SPACECHAR = ' ';
    const char EDGECHAR = '|';
    // Clear the screen (code from Piazza as an alternative to system("clear"))
    cout << "\033[2J\033[1;1H" << endl;
    // Output the first line
    cout << setfill(FILLCHAR);
    cout << FILLCHAR << setw(columns * 2) << FILLCHAR << endl;
    // Loop through rows and columns and print the values
    for (int r = 0; r < rows; r++) {
        // Output the first edge
        cout << EDGECHAR;
        for (int c = 0; c < columns; c++) {
            // Print the cell
            if(grid[r][c] != nullptr)
            {
                grid[r][c]->setToNotMoved();
                if(grid[r][c]->getType() == ANT)
                {
                    cout << ANTCHAR << EDGECHAR;
                }
                else
                {
                    cout << BUGCHAR << EDGECHAR;
                }
            }
            else
            {
                cout << SPACECHAR << EDGECHAR;
            }
        }
        cout << endl << FILLCHAR << setw(columns * 2) << FILLCHAR << endl;
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
