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
using std::string;
using std::vector;

int main()
{
    srand (time(NULL)); //seed random

    // Get the main menu ready
    vector<string> mainMenuItems = {"Run a Predator/Prey Simulation", "Exit"};

    Menu menu;

    //run the intro art
	menu.introArtReader();
    
    Menu mainMenu("Welcome to Doodlebugs, would you like to play?", mainMenuItems);
    int menuChoice = mainMenu.showMenu();

    // Also make a menu to prompt for more steps at the end of the simulation
    vector<string> continueMenuItems = {"Keep running simulation", "Exit"};
    int continueChoice = 1;
    Menu continueMenu("Would you like to continue to run the simulation for more steps?", continueMenuItems);
    
    // Start the program
    while (menuChoice != 2) {
        
        // Tell the grader we did the extra credit:
        cout << "Enter the setup variables to start the game (EXTRA CREDIT):" << endl << endl;
        Grid simulation;
        
        for(int i = 0; i < simulation.getSteps() && continueChoice == 1; i++) {
            currentStep++;
            cout << "Step: " << (i + 1) << endl;
            simulation.moveCritters();
            cout << endl;
            // If it's the last step, see if the user wants to run for more steps
            if (i == simulation.getSteps() - 1) {
                continueChoice = continueMenu.showMenu();
                if (continueChoice == 1) {
                    int steps = Menu::getNumSteps();
                    simulation.setSteps(steps);
                    i = 0;
                }
            }
        }
        menuChoice = mainMenu.showMenu();
    }
    //goodbye art
	menu.goodbyeArtReader();
	cout << "Press Enter to Exit. . .\n";
    std::cin.get();

    return 0;
}
