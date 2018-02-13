/****************************************************************************
** Group Project 1 Program name: Predator-Prey Game
** Author: 
** Date: 
** Description: Specification file for the Critter class. The Critter class
** is an abstract base class for the Ant and Doodlebug classes
****************************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP
#include <stdlib.h>
#include <iostream>

class Critter 
{
protected: 
    enum directions {UP, RIGHT, DOWN, LEFT};
    int breedAge;
    int timeSinceBreed; //track time since last breeding
    int row;            //track critter row
    int col;            //track critter col    
    bool moved;         //track if a critter has moved already in the present time-unit, prevents removing
    bool breedFlag;     //is the critter ready to breed?
        
public:
    // constructor & destructor
    Critter(int, int, int);
    virtual ~Critter(); 
        
    // abstract base class functions
    virtual bool move(int*) = 0; 
    virtual int getType() = 0;
    virtual bool starvationCheck() = 0;
   
    // getters    
    int getTimeSinceBreed();
    int getRow(); 
    int getCol();
    bool readyToBreed();
    int getBreedingAge();
    bool getMoved(); //returns the bool moved
    
    // setters
    /****************************************************************************
    ** Resets Critter::moved to false
    ****************************************************************************/
    void setToNotMoved(); 
    void incrementTimeSinceBreed();
    void resetTimeSinceBreed();   //call after breeding to reset clock to 0
    virtual Critter* breed(int*) = 0;
}; 

#endif
