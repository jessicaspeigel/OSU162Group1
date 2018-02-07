/*********************************************************************
** Group Project 1 Program name: Predator-Prey Game
** Author: Ryan Mack
** Date: 2/5/2018
** Description: Specification file for the Menu class.
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <string>
using std::string;

class Menu
{
/*********************************************************************
** Static methods are great because they can be called without having
** to instantiate an object.
** https://softwareengineering.stackexchange.com/a/113034
*********************************************************************/
public:

	/*********************************************************************
	** Takes in two ints and a prompt. Prompts a user for an integer
	**	in the range of those two integers (inclusive)
	*********************************************************************/
	static int inputInt(int lowerBound, int upperBound, string prompt);


	// all use the inputInt function to get input from the user for the simulations
	static int getNumSteps();
	static int getRows();
	static int getColumns();
	static int getNumAnts();
	static int getNumDoodlebugs();
	
	//includes the intro and goodbye ascii art
	void introArtReader();
	void goodbyeArtReader();
	string getFileContents(ifstream& File);
};

#endif
