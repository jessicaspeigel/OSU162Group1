/********************************************************************** //update moved, so doodlebug not moved again if true
** Program
** Author: Group 1
** Date : 2/ / 18
* * Description :

*********************************************************************/

#include "Doodlebug.hpp"

Doodlebug::Doodlebug(int row, int col) : Critter(row, col) 
{
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
            switch(dir) //adjust position of doodlebug based on direction taken (i.e. the index in surroundingCells array)
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
    moved = validMove; //update moved, so doodlebug not moved again if true
    return validMove;
}
