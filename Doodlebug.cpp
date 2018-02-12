/**********************************************************************
** Group Project 1 Program name: Predator-Prey Game
** Author: Group 1
** Date: 2/ / 18
** Description: 
*********************************************************************/

#include "Doodlebug.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;


Doodlebug::Doodlebug(int row, int col) : Critter(row, col, 8) 
{
    daysToStarvation = 3;
    timeSinceFeed = 0;
    timeSinceFeed = 0;
}


int Doodlebug::getType()
{
    return 2;
}


bool Doodlebug::move(int* arr)
{
    bool validMove = false; 
    int dir = rand() % 4;

    for(int cell = 0; cell < 4; cell++)
    {
        if(arr[cell] == 1)
        {
            validMove = true; //If an ant is in at least one adjacent cell, a valid move is available
        }
    }
    
    if(validMove)
    {
        timeSinceFeed = 0; //reset time since feeding
        while(arr[dir] != 1)
        {
            dir = rand() % 4; //keep looking until ant is found; if more than one ant, doodlebug chooses randomly
        }
            switch(dir) //adjust position of doodlebug based on index where ant was found
            {    
                case(UP): //check up
                    row -= 1; 
                    break;
                case(RIGHT):
                     col += 1; 
                     break;
                case(DOWN): 
                    row += 1; 
                    break; 
                 case(LEFT):
                    col -= 1; 
                    break;
            }
         
    }
    else
    {
        timeSinceFeed += 1; //no food for doodlebug
        if(arr[dir] == 0) //if the cell is open space, valid move is true
        {
            validMove = true; 
            
             //adjust position of doodlebug based on direction taken (i.e. the index in surroundingCells array)
            switch(dir)
            {    
                case(UP): //check up
                    row -= 1; 
                    break;
                case(RIGHT):
                     col += 1; 
                     break;
                case(DOWN): 
                    row += 1; 
                    break; 
                 case(LEFT):
                    col -= 1; 
                    break;
            }
        }
    }

    // Time to starve?
    if (timeSinceFeed >= daysToStarvation) {
        starve();
    }

    // Age the doodlebug for breeding
    incrementTimeSinceBreed();

    moved = validMove; //update moved, so doodlebug not moved again if true
    return validMove;
}


void Doodlebug::starve() {
    cout << "doodlebug starve" << endl;
    starveFlag = true;
}


bool Doodlebug::isStarving() {
    return starveFlag;
}


Critter* Doodlebug::breed(int* surroundingCells)
{
    Critter* offspring; //offspring to return, nullptr of new Critter
    int checkSequence[4]; //random sequence in which to check surroundingCells
    int offspringRow; 
    int offspringCol;
    bool uniqueOrder = false; 
    bool breedSuccess = false; 

    for(int i = 0; i < 4; i++)
    {
        while(!uniqueOrder) 
        {
            uniqueOrder = true; 
            checkSequence[i] = rand() % 4; 
            for(int j = 0; j < i; j++)
            {
                if(checkSequence[i] == checkSequence[j])
                {
                    uniqueOrder = false; //if any of the previous indexes match, try again
                }
            }
        }
    }

    for(int cell = 0; cell < 4; cell++)
    {
        if(!breedSuccess)
        {
            switch(checkSequence[cell])
            {
                case(UP):
                    if(surroundingCells[0] == 0)
                    {
                        offspringRow = row - 1; 
                        offspringCol = col;
                        breedSuccess = true; 
                    }
                    break; 
                case(RIGHT):
                    if(surroundingCells[1] == 0)
                    {
                        offspringRow = row; 
                        offspringCol = col + 1;
                        breedSuccess = true; 
                    }
                    break; 
                case(DOWN):
                    if(surroundingCells[2] == 0)
                    {
                        offspringRow = row + 1; 
                        offspringCol = col;
                        breedSuccess = true; 
                    }
                    break; 
                case(LEFT):
                    if(surroundingCells[3] == 0)
                    {
                        offspringRow = row; 
                        offspringCol = col - 1;
                        breedSuccess = true; 
                    }
                    break; 
            }
        }
    }

    if(breedSuccess)
    {
        offspring = new Doodlebug(offspringRow, offspringCol);
        resetTimeSinceBreed(); 
    }
    else
    {
        offspring = nullptr;
    }
    return offspring; 
}
