/**********************************************************************
** Group Project 1 Program name: Predator-Prey Game
** Author: Group 1
** Date : 2/ / 18
** Description: Specification file for the Ant class
*********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP


#include "Critter.hpp"

class Ant : public Critter
{
public:
    Ant(int, int);
    
    
    /****************************************************************************
    ** Input: pointer to an int arrray created in the Grid class. Array represents
    **  cells adjacent to ant. Ant tries to move to one of four adjacent spaces 
    **  in the grid. If move is valid, ant adjusts row and column and returns true. 
    **	Function returns false otherwise, and no move made
    ****************************************************************************/
    virtual bool move(int*);
    
    
    /****************************************************************************
    ** Returns 1, used for identifying creature in Grid::grid
    ****************************************************************************/
    virtual int getType();
    Critter* breed(int*);
};

#endif
