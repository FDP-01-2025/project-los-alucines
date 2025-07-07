#include <iostream>
#include <windows.h> // Required for SetConsoleOutputCP and Windows functions

#include "src/Player_profiles.h"
#include "src/Bingo.h"
#include "src/Menu.h"
#include "src/Dice.h"
<<<<<<< HEAD
#include "src/roulette.h"
=======
#include "src/Poker.h"
#include "src/Roulette.h"

>>>>>>> dea8ef3f3665ca5a90ff320dba0c530b5a1a478a

using namespace std;

int main()
{
    int option;

    SetConsoleOutputCP(CP_UTF8); // Set console to UTF-8 encoding
    Logo();                      // Display the logo

    system("cls"); // Clear the screen

    add();         // Add players
    Save();        // Save player data

    option = ShowMenu(); // Show the menu and store the chosen option

    switch (option)
    {
    case 1:
        RunningBingo();   // Load player data and get bets
        BingoCards();     // Generate bingo cards
        RandomNumber();   // Generate first random number
        Boards();         // Display boards and current scores
        Play();           // Start game loop
        break;

    case 2:
        cout << "Dice" << endl;
        runTheHouseofDice(); // Run "The House of Dice" game
        break;

    case 3:
        cout << "Black Jack" << endl;
        break;

    case 4:
        cout << "Roulette" << endl;
        break;

    case 5:
        exit(0); // Exit the program
        break;

    default:
        break;
    }

    while (option != 5)
        ; // Empty loop to keep console open if not exiting

    system("pause"); // Pause before closing the console
    return 0;
}