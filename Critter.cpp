/****************************************************************************
 ** Group Project 1 Program name: Predator-Prey Game
 ** Author: 
 ** Date: 
 ** Description: Implementation file for the Critter class
 ****************************************************************************/
 
#include "Critter.hpp" 


Critter::Critter(int row, int col, int breedAge)
{
    this->breedAge = breedAge;
    this->row = row;
    this->col = col;
    this->moved = false;
    this->breedFlag = false;
    this->timeSinceBreed = 0;
}

void Critter::incrementTimeSinceBreed()
{
    timeSinceBreed += 1; 
    if(timeSinceBreed == breedAge)
    {
        breedFlag = true; 
    }
}

void Critter::resetTimeSinceBreed()
{
    timeSinceBreed = 0;
    breedFlag = false; 
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

bool Critter::readyToBreed() {
    return breedFlag;
}

Critter::~Critter(){}
