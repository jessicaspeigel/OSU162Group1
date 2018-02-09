/*********************************************************************
** Group Project 1 Program name: Predator-Prey Game
** Author: Ryan Mack
** Date: 2/5/2018
** Description: File that contains the main function.
*********************************************************************/

#include "Grid.hpp"
#include <iostream> 
#include <stdlib.h> 
#include <time.h> 
using std::cout;
using std::endl;

int main()
{
    srand (time(NULL)); //seed random
	Grid simulation;
    for(int i = 0; i < simulation.getSteps(); i++)
    {
        simulation.moveCritters(); 
        cout << "-----------------------------------------------" << endl << endl; //helps to see between each step
    }
    return 0;
}
