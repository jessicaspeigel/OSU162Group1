/****************************************************************************
 ** Author: 
 ** Date: 
 ** Description: Implementation Critter Class
 ****************************************************************************/
 #include "Critter.hpp" 

Critter::Critter(int row, int col, shared_ptr<Grid>& grid)
{
    this->row = row; 
    this->col = col;
    this->grid = grid;
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

Critter* Critter::breed(int row, int col, shared_ptr<Grid>& g)
{
    return new Critter(row, col, g); 
}

Critter::~Critter(){}
