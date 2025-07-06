#ifndef ROULETTE_H
#define ROULETTE_H

#include <string>
using namespace std;

// Struct to store player information
struct Player {
    string name;
    int money;
    int wins;
};

// Function declarations
void showMenu();
string getColor(int number);
int validateBet(int availableMoney);
void playRoulette(Player &player);

#endif

include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>

using namespace std;

// Player structure
struct Player {
    string name;
    int money;
    int wins;
};


// Show betting menu
void showMenu() {
    cout << "\n--- BETTING OPTIONS ---\n";
    cout << "1. Exact number (0-36)\n";
    cout << "2. Color (red or black)\n";
    cout << "3. Even or odd\n";
    cout << "Choose an option: ";
}


// Get the color of the number
string getColor(int number) {
    if (number == 0) return "green";
    return (number % 2 == 0) ? "black" : "red";
}

// Validate bet amount
int validateBet(int availableMoney) {
    int bet;
    do {
        cout << "\nEnter your bet amount (minimum $1): ";
        cin >> bet;
        if (bet < 1 || bet > availableMoney) {
            cout << "Invalid bet. Please try again.\n";
        }
    } while (bet < 1 || bet > availableMoney);
    return bet;
}