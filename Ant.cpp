/**********************************************************************
** Program
** Author: Group 1
** Date : 2/ / 18
* * Description :

*********************************************************************/

#include "Ant.hpp"

Ant::Ant(int row, int column) : Critter(row, column)
{
}

int Ant::getType()
{
    return 1; 
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

    // Is it time to breed?

    // Age the ant
    incrementTime();

    //update the critter's moved variable, true if moved, false otherwise
    moved = validMove;
    return validMove;
}
