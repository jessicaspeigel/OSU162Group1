/**********************************************************************
** Group Project 1 Program name: Predator-Prey Game
** Author: Group 1
** Date: 2/ / 18
** Description: 
*********************************************************************/

#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"

class Doodlebug : public Critter
{
private:
    int timeSinceFeed; 	 	//track time since feeding
    bool starveFlag; 		//is the doodlebug starved?
    int daysToStarvation;

public:
    Doodlebug(int, int);
    
    /****************************************************************************
    ** Input: pointer to an int array created in the Grid class. Array represents
    ** cells adjacent to doodlebug. If ants in adjacent cells, doodlebug eats, 
    ** else it tries to move to random cell. If move is valid, doodlebug
    ** adjusts row and column and returns true. Function returns false otherwise, 
    ** and no move made
    ****************************************************************************/
    virtual bool move(int*); 
    virtual int getType();
    bool starvationCheck();
    Critter* breed(int*);

};

#endif
