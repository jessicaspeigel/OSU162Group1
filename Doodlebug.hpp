/**********************************************************************
** Program
** Author: Group 1
** Date : 2/ / 18
* * Description :

*********************************************************************/

#pragma once
#include "Critter.hpp"

class Doodlebug : public Critter
{
private:
    int timeSinceFeed; //track time since feeding
public:
	Doodlebug(int, int);
    /****************************************************************************
    ** Input: pointer to an int arrray created in the Grid class. Array represents
        cells adjacent to doodlebug. If ants in adjacent cells, doodlebug eats, 
        else it tries to move to random cell. If move is valid, doodlebug
        adjusts row and column and returns true. Function returns false otherwise, 
        and no move made
    ****************************************************************************/
    virtual bool move(int*); 
    virtual int getType(); 
};

