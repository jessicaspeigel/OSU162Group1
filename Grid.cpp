/*********************************************************************
** Group Project 1 Program name: Predator-Prey Game
** Author: Ryan Mack
** Date: 2/5/2018
** Description: Implementation file for the Grid class.
*********************************************************************/

#include "Menu.hpp"
#include "Grid.hpp"
#include <iostream>
using std::cout;
using std::endl;


Grid::Grid()
{
	steps = Menu::getNumSteps();
	columns = Menu::getColumns();
	rows = Menu::getRows();
	ants = Menu::getNumAnts();
	doodleBugs = Menu::getNumDoodlebugs();


	cout << "\n\nSteps: " << steps << endl;
	cout << "Columns: " << columns << endl;
	cout << "Rows: " << rows << endl;
	cout << "Ants: " << ants << endl;
	cout << "Doodlebugs: " << doodleBugs << endl;
}