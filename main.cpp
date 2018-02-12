/*********************************************************************
** Group Project 1 Program name: Predator-Prey Game
** Author: Ryan Mack
** Date: 2/5/2018
** Description: File that contains the main function.
*********************************************************************/

#include "Grid.hpp"
#include "Menu.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h> 
#include <time.h> 
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

int main()
{
    srand (time(NULL)); //seed random
    
    // Get the main menu ready
    vector<string> mainMenuItems = {"Run a Predator/Prey Simulation", "Exit"};

	Menu menu;

	menu.introArtReader();

    Menu mainMenu("Welcome to Doodlebugs, would you like to play?", mainMenuItems);
    int menuChoice = mainMenu.showMenu();
    
    // Start the program
    while (menuChoice != 2) {
        
        // Tell the grader we did the extra credit:
        cout << "Enter the setup variables to start the game (EXTRA CREDIT):" << endl << endl;
        Grid simulation;
        
        for(int i = 0; i < simulation.getSteps(); i++) {
            cout << "Step: " << (i + 1) << endl;
            simulation.moveCritters();
            cout << endl;
        }
        menuChoice = mainMenu.showMenu();
    }

	menu.goodbyeArtReader();
	cout << "Press enter to exit. . .\n";
	cin.get();
	cin.get();

    return 0;
}
