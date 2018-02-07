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


#include <fstream>
using std::ifstream;

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
/***************************************************
Citation - Thise code is modified from
http://www.cplusplus.com/forum/general/58945/
user - TheMassiveChipmunk

introArtReader() - reads the intro ascii art from a file using getFileContents();
then couts the file lines to the console and closes the file

****************************************************/
void Menu::introArtReader()
{
		//Open file
		ifstream Reader("introFile.txt");

		//Get file
		string introArt = getFileContents(Reader);

		cout << introArt << endl;               //Print it to the screen

		Reader.close();                           //Close file
}

/***************************************************
Citation - Thise code is modified from
http://www.cplusplus.com/forum/general/58945/
user - TheMassiveChipmunk

goodbyeArtReader() - reads the intro ascii art from a file using getFileContents();
then couts the file lines to the console and closes the file

****************************************************/
void Menu::goodbyeArtReader()
{
	//Open file
	ifstream Reader("byefile.txt");

	//Get file
	string goodbyeArt = getFileContents(Reader);

	cout << goodbyeArt << endl;               //Print it to the screen

	Reader.close();                           //Close file
}

/***************************************************

getFileContents() - cheks to make sure the file is available
and if it is get the appropriately space and /n art

****************************************************/
string Menu::getFileContents(ifstream & File)
{
	//All lines
	string Lines = "";

	//Check if everything is good
	if (File)
	{
		while (File.good())
		{
			string TempLine;                  //Temp line
			getline(File, TempLine);        //Get temp line
			TempLine += "\n";                      //Add newline character

			Lines += TempLine;                     //Add newline
		}
		return Lines;
	}
	else                           //Return error
	{
		return "ERROR File does not exist.";
	}
}
