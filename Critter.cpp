/****************************************************************************
 ** Group Project 1 Program name: Predator-Prey Game
 ** Author: Group 1
 ** Date: 2/14/18
 ** Description: Implementation file for the Critter class
 ****************************************************************************/
 
#include "Critter.hpp" 

/***************************************************
 ** Description: Constructor for Critters.
 ****************************************************/

Critter::Critter(int row, int col, int breedAge)
{
    this->breedAge = breedAge;
    this->row = row;
    this->col = col;
    this->moved = false;
    this->breedFlag = false;
    this->timeSinceBreed = 0;
}

/***************************************************
 ** Description: Increment the amount of time (steps) since a critter has bred.
 ****************************************************/

void Critter::incrementTimeSinceBreed()
{
    timeSinceBreed += 1; 
    if(timeSinceBreed == breedAge)
    {
        breedFlag = true; 
    }
}

/***************************************************
 ** Description: Reset the amount of time (steps) since a critter has bred.
 ****************************************************/

void Critter::resetTimeSinceBreed()
{
    timeSinceBreed = 0;
    breedFlag = false; 
}

/***************************************************
 ** Description: Get the row a critter is located on.
 ****************************************************/

int Critter::getRow()
{
    return row; 
}

/***************************************************
 ** Description: Get the column a critter is located on.
 ****************************************************/

int Critter::getCol()
{
    return col;
}

/***************************************************
 ** Description: Set the critter to moved once it has been moved.
 ****************************************************/

void Critter::setToNotMoved()
{
    moved = false;
}

/***************************************************
 ** Description: Return if the critter has been moved or not.
 ****************************************************/

bool Critter::getMoved()
{
    return moved; 
}

/***************************************************
 ** Description: Return if the critter is ready for breed or not.
 ****************************************************/

bool Critter::readyToBreed() {
    return breedFlag;
}

/***************************************************
 ** Description: Destructor for Critters.
 ****************************************************/

Critter::~Critter(){}
