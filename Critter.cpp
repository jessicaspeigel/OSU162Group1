/****************************************************************************
 ** Author: 
 ** Date: 
 ** Description: Implementation Critter Class
 ****************************************************************************/
 #include "Critter.hpp" 

Critter::Critter(int row, int col)
{
    this->row = row; 
    this->col = col;
    this->moved = false;
    timeSinceBreed = 0; 
}

void Critter::incrementTime()
{
    timeSinceBreed += 1; 
}

int Critter::getTime()
{
    return timeSinceBreed;
}

void Critter::resetTime()
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

Critter::~Critter(){}
