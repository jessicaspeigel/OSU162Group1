/*********************************************************************
** Group Project 1 Program name: Predator-Prey Game
** Author: Ryan Mack
** Date: 2/5/2018
** Description: Implementation file for the Menu class.
*********************************************************************/

#include "Menu.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;
using std::numeric_limits;
using std::streamsize;
using std::ifstream;


/****************************************************
** Constructors
****************************************************/
Menu::Menu()
{
}

Menu::Menu(vector<string> items)
{
	setMenuItems(items);
	// Set prompt text to null if it doesn't exist
	setPromptText("");
}


Menu::Menu(string text, vector<string> items)
{
	setMenuItems(items);
	setPromptText(text);
}


/****************************************************
** Getters / Setters
****************************************************/
void Menu::setMenuItems(vector<string> items)
{
	// If menu items exists, delete it before making a new array
	menuItems.clear();
	for (string i : items) {
		menuItems.push_back(i);
	}
}


void Menu::setPromptText(string text)
{
	promptText = text;
}


string Menu::getPromptText()
{
	return promptText;
}


/****************************************************
** PUBLIC FUNCTIONS
****************************************************/

/****************************************************
** Description: Show the menu items and return the
** index of selected item.
****************************************************/
int Menu::showMenu()
{
	// Create a variable to hold the user's menu choice
	int choice = 0;

	// Show the prompt, if there is one
	if (getPromptText() != "") {
		cout << "\n" << getPromptText() << "\n";
	}

	// Show the user the menu
	for (int i = 0; i < menuItems.size(); i++) {
		// Show the menu item
		cout << i + 1 << ". " << menuItems[i] << "\n";
	}
	// Get input from the user
	cin >> choice;
	// Loop while the input is bad until we get a valid data and a valid number
	while (cin.fail()|| (choice < 1 || choice > menuItems.size())) {
		cin.clear();
		cin.ignore(999,'\n');
		cout << "I'm sorry, that's not a valid choice. Please enter a choice between 1 and " << menuItems.size() << endl;
		// Get input from the user again
		cin >> choice;
	}
	return choice;
}


/****************************************************
** Description: Get integer input from the user
****************************************************/
int Menu::getInteger(string prompt)
{
	// Variable to store the number entered by the user.
	int num;

	// Prompt the user to enter an integer.
	cout << prompt << endl;
	cin >> num;

	// While the input entered is not an integer, prompt the user to enter an integer.
	while (!cin) {
		cout << "That's not a valid integer. Please try again." << endl;
		cin.clear();
		cin.ignore(1000,'\n');
		cin >> num;
	}
	return num;
}


int Menu::getIntegerWithMin(string prompt, int minVal)
{
	// Variable to store the number entered by the user.
	int num = getInteger(prompt);
	string newPrompt = "Please enter a valid integer.";
	while (num < minVal) {
		num = getInteger(newPrompt);
	}
	return num;
}


int Menu::getIntegerWithMinMax(string prompt, int minVal, int maxVal)
{
	// Variable to store the number entered by the user.
	int num = getInteger(prompt);
	string newPrompt = "Please enter a valid integer.";
	while (num < minVal || num > maxVal) {
		num = getInteger(newPrompt);
	}
	return num;
}


/****************************************************
** Description: Menus to get game variables from
** the user.
****************************************************/
int Menu::getNumSteps()
{
	string prompt = "How many steps (between 1 and 1,000) would you like the simulation to run for?";
	const int MIN_STEPS = 1;
	const int MAX_STEPS = 1000;

    int steps = getIntegerWithMinMax(prompt, MIN_STEPS, MAX_STEPS);
	return steps;
}


int Menu::getRows()
{
	string prompt = "How many rows (between 20 and 50) would you like the grid to be?";
	const int MIN_ROWS = 20;
	const int MAX_ROWS = 50;

    int rows = getIntegerWithMinMax(prompt, MIN_ROWS, MAX_ROWS);
	return rows;
}


int Menu::getColumns()
{
	string prompt = "How many columns (between 20 and 50) would you like the grid to be?";
	const int MIN_COLS = 20;
	const int MAX_COLS = 50;

    int columns = getIntegerWithMinMax(prompt, MIN_COLS, MAX_COLS);
	return columns;
}


int Menu::getNumAnts()
{
	string prompt = "How many ants (between 1 and 100) would you like at the start of the simulation?";
	const int MIN_ANTS = 1;
	const int MAX_ANTS = 100;

    int ants = getIntegerWithMinMax(prompt, MIN_ANTS, MAX_ANTS);
	return ants;
}


int Menu::getNumDoodlebugs()
{
	string prompt = "How many doodlebugs (between 1 and 10) would you like at the start of the simulation?";
	const int MIN_DBUGS = 1;
	const int MAX_DBUGS = 10;

    int bugs = getIntegerWithMinMax(prompt, MIN_DBUGS, MAX_DBUGS);
	return bugs;
}


/***************************************************
** Citation - This code is modified from
** http://www.cplusplus.com/forum/general/58945/user
** TheMassiveChipmunk
**
** introArtReader() - reads the intro ascii art from
** a file using getFileContents(), then couts the 
** file lines to the console and closes the file
****************************************************/
void Menu::introArtReader()
{
		//Open file
		ifstream Reader("introFile.txt");

		//Get file
		string introArt = getFileContents(Reader);

		//Print it to the screen
		cout << introArt << endl;               

		 //Close file
		Reader.close();                          
}



/***************************************************
** Citation - This code is modified from
** http://www.cplusplus.com/forum/general/58945/user
** TheMassiveChipmunk
**
** goodbyeArtReader() - reads the intro ascii art 
** from a file using getFileContents(), then couts 
** the file lines to the console and closes the file
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
** Checks to make sure the file is available and if
** it is get the appropriately space and /n art
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
