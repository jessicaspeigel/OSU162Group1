/**********************************************************************
** Program
** Author: Group 1
** Date : 2/ / 18
* * Description :

*********************************************************************/

#include "Ant.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

Ant::Ant(int row, int column) : Critter(row, column)
{
    this->breedAge = 3;
}

int Ant::getType()
{
    return 1; 
}

bool Ant::move(int* arr)
{
    int dir = rand() % 4; //enum type defined in Critter.hpp, UP=0, RIGHT=1, DOWN=2, LEFT=3 (clockwise rotation as index increases)
    bool validMove = false;

    if(arr[dir] == 0) //If the arr[dir] == 0, the grid cell is an open space, not a wall or critter, and move is valid
    {
        validMove = true; 
        switch(dir)
        {    
            case(UP): //0
                row -= 1; 
                break;
            case(RIGHT): //1
                 col += 1; 
                 break;
            case(DOWN): //2 
                row += 1; 
                break; 
             case(LEFT): //3
                col -= 1; 
                break;
        }
    }

    // Time to breed?
    if (getTimeSinceBreed() >= getBreedingAge()) {
        breed();
    }

    // Age the ant for breeding
    incrementTimeSinceBreed();

    //update the critter's moved variable, true if moved, false otherwise
    moved = validMove;
    return validMove;
}

void Ant::breed() {
    cout << "ant breed" << endl;
    setReadyToBreed(true);
}