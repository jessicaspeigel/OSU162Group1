/*********************************************************************
** Group Project 1 Program name: Predator-Prey Game
** Author: Ryan Mack
** Date: 2/5/2018
** Description: Specification file for the Menu class.
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <vector>
#include <fstream>
using std::string;
using std::vector;
using std::ifstream;
	

class Menu
{
	// Used when an actual menu is being instantiated
	private:
		vector<string> menuItems;
		string promptText;

	public:
		Menu(vector<string> menuItems);
		Menu(string promptText, vector<string> menuItems);
		int showMenu();
		void setPromptText(string text);
		string getPromptText();
		void setMenuItems(vector<string> menuItems);

		/*********************************************************************
		** Static methods are great because they can be called without having
		** to instantiate an object.
		** https://softwareengineering.stackexchange.com/a/113034
		*********************************************************************/
		static int getInteger(std::string promptText);
		static int getIntegerWithMin(std::string promptText, int minVal);
		static int getIntegerWithMinMax(std::string promptText, int minVal, int maxVal);

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
