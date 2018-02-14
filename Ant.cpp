/**********************************************************************
** Group Project 1 Program name: Predator-Prey Game
** Author: Group 1
** Date : 2/ / 18
** Description: Implementation file for the Ant class
*********************************************************************/

#include "Ant.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;


Ant::Ant(int row, int column) 
    : Critter(row, column, 3)
{
}


int Ant::getType()
{
    return 1; 
}


void Ant::setEatFlag(bool eat) 
{
    return eat;  
}

bool Ant::getEatFlag()
{
    return false;
}

bool Ant::starvationCheck()
{
    return false; 
}


bool Ant::move(int* arr)
{
    int dir = rand() % 4; //enum type defined in Critter.hpp, UP=0, RIGHT=1, DOWN=2, LEFT=3 (clockwise rotation as index increases)
    bool validMove = false;

    if(arr[dir] == 0) //If the arr[dir] == 0, the grid cell is an open space, not a wall or critter, and move is valid
    {
        validMove = true; 
        switch(dir)
        {    
            case(UP): //0
                row -= 1; 
                break;
            case(RIGHT): //1
                 col += 1; 
                 break;
            case(DOWN): //2 
                row += 1; 
                break; 
             case(LEFT): //3
                col -= 1; 
                break;
        }
    }

    // Age the ant for breeding
    incrementTimeSinceBreed();

    //update the critter's moved variable, true if moved, false otherwise
    moved = validMove;
    return validMove;
}

Critter* Ant::breed(int* surroundingCells)
{
    Critter* offspring; 
    int checkSequence[4] = {-1, -1, -1, -1}; 
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
                    uniqueOrder = false; 
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
        offspring = new Ant(offspringRow, offspringCol);
        resetTimeSinceBreed(); 
    }
    else
    {
        offspring = nullptr;
    }
    return offspring; 
}
