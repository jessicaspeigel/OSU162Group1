/****************************************************************************
 ** Author: 
 ** Date: 
 ** Description: Critter Header File, abstract base class for Ant and
        Doodlebug classes
 ****************************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP
#include <stdlib.h>
#include <iostream>

class Critter 
{
protected: 
    enum directions {UP, RIGHT, DOWN, LEFT}; 
    int timeSinceBreed; //track time since last breeding
    int row; //track critter row
    int col; //track critter col    
    bool moved; //track if a critter has moved already in the present time-unit, prevents removing
public: 
    Critter(int, int);
    virtual bool move(int*) = 0; 
    virtual int getType() = 0; 
    void incrementTime();  
    void resetTime();   //call after breeding to reset clock to 0
    int getTime(); 
    int getRow(); 
    int getCol(); 
    /****************************************************************************
    ** Resets Critter::moved to false
    ****************************************************************************/
    void setToNotMoved(); 
    bool getMoved(); //returns the bool moved
    virtual ~Critter(); 
}; 

#endif
