/*********************************************************************
** Group Project 1 Program name: Predator-Prey Game
** Author: Ryan Mack
** Date: 2/5/2018
** Description: Specification file for the Simulation class.
*********************************************************************/

#ifndef GRID_HPP
#define GRID_HPP
#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"

#include <string>
using std::string;

class Grid
{
private:
	int steps;
	int ants;
	int doodleBugs;
	int rows;
	int columns;
    Critter*** grid;	

public:
	Grid();
    /****************************************************************************
    ** Randomly place ants and doodlebugs in grid
    ****************************************************************************/
    void fillGrid(); 
    ~Grid(); 
};

#endif
