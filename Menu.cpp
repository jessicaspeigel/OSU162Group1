/*********************************************************************
** Group Project 1 Program name: Predator-Prey Game
** Author: Ryan Mack
** Date: 2/5/2018
** Description: Implementation file for the Menu class.
*********************************************************************/

#include "Menu.hpp"
#include <iostream>
#include <sstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;


int Menu::inputInt(int lowerBound, int upperBound, string prompt)
{
	string input;		// holds contents of getline
	int validInt;		// return value
	bool error = false;	// error

						// display prompt on a new line.
	cout << prompt << endl;

	do
	{
		cout << "Enter a number >= " << lowerBound << " and <= " << upperBound << ": ";
		// save the entire line in the string variable input
		getline(cin, input);
		cout << endl;

		// write the input to the string stream
		stringstream line(input);

		// feed the line (string stream) to int
		// if it was a valid int there shouldn't be anything left
		if (line >> validInt && !(line >> input))
		{
			if (validInt < lowerBound || validInt > upperBound)
			{
				cout << "ERROR: Integer out of range." << endl;
				error = true;
			}
			else
			{
				// valid input
				error = false;
			}
		}
		else
		{
			cout << "ERROR: You must enter a proper integer." << endl;
			error = true;
		}
	} while (error);

	return validInt;
}


int Menu::getNumSteps()
{
	string prompt = "How many steps would you like the simulation to run for?";
	const int MIN_STEPS = 1;
	const int MAX_STEPS = 1000;

	int steps = inputInt(MIN_STEPS, MAX_STEPS, prompt);
	return steps;
}


int Menu::getRows()
{
	string prompt = "How many rows would you like the grid to be?";
	const int MIN_ROWS = 20;
	const int MAX_ROWS = 50;

	int rows = inputInt(MIN_ROWS, MAX_ROWS, prompt);
	return rows;
}


int Menu::getColumns()
{
	string prompt = "How many columns would you like the grid to be?";
	const int MIN_COLS = 20;
	const int MAX_COLS = 50;

	int columns = inputInt(MIN_COLS, MAX_COLS, prompt);
	return columns;
}


int Menu::getNumAnts()
{
	string prompt = "How many ants would you like at the start of the simulation?";
	const int MIN_ANTS = 1;
	const int MAX_ANTS = 100;

	int ants = inputInt(MIN_ANTS, MAX_ANTS, prompt);
	return ants;
}


int Menu::getNumDoodlebugs()
{
	string prompt = "How many doodlebugs would you like at the start of the simulation?";
	const int MIN_DBUGS = 1;
	const int MAX_DBUGS = 10;

	int ants = inputInt(MIN_DBUGS, MAX_DBUGS, prompt);
	return ants;
}