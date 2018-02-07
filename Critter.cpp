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

Critter* Critter::breed(int row, int col)
{
    return new Critter(row, col); 
}

Critter::~Critter(){}
