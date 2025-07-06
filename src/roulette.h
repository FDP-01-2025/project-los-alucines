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

