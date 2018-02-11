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
    int breedAge;
    int timeSinceBreed; //track time since last breeding
    int row; //track critter row
    int col; //track critter col    
    bool moved; //track if a critter has moved already in the present time-unit, prevents removing
    bool breedFlag; //is the critter ready to breed?
public: 
    Critter(int, int);
    virtual bool move(int*) = 0; 
    virtual int getType() = 0; 
    void incrementTimeSinceBreed();
    void resetTimeSinceBreed();   //call after breeding to reset clock to 0
    int getTimeSinceBreed();
    int getRow(); 
    int getCol();
    void setReadyToBreed(bool flag);
    bool getReadyToBreed();
    int getBreedingAge();
    /****************************************************************************
    ** Resets Critter::moved to false
    ****************************************************************************/
    void setToNotMoved(); 
    bool getMoved(); //returns the bool moved
    virtual ~Critter(); 
}; 

#endif
