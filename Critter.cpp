/****************************************************************************
 ** Group Project 1 Program name: Predator-Prey Game
 ** Author: 
 ** Date: 
 ** Description: Implementation Critter Class
 ****************************************************************************/
 
#include "Critter.hpp" 


Critter::Critter(int row, int col)
{
    this->breedAge = 3;
    this->row = row;
    this->col = col;
    this->moved = false;
    setReadyToBreed(false);
}


void Critter::incrementTimeSinceBreed()
{
    timeSinceBreed += 1; 
}


int Critter::getTimeSinceBreed()
{
    return timeSinceBreed;
}


void Critter::resetTimeSinceBreed()
{
    timeSinceBreed = 0;
}


int Critter::getRow()
{
    return row; 
}


int Critter::getCol()
{
    return col;
}


void Critter::setToNotMoved()
{
    moved = false;
}


bool Critter::getMoved()
{
    return moved; 
}


void Critter::setReadyToBreed(bool flag) {
    if (flag == true || flag == false) {
        // Make sure it's a bool
        breedFlag = flag;
        // Reset the internal clock
        resetTimeSinceBreed();
    }
}


bool Critter::getReadyToBreed() {
    return breedFlag;
}


int Critter::getBreedingAge() {
    return breedAge;
}


Critter::~Critter(){}
