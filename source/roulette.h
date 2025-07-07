// roulette.h
// Header file for Roulette game - Final Project

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




#include <iostream>
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
    return bet;
}

// Main game logic
void playRoulette(Player &player) {
    int round = 1;
    while (player.money > 0 && round <= 6 && player.wins < 3) {
        cout << "\n=== ROUND " << round << " ===\n";
        cout << "Current balance: $" << player.money << endl;

        int bet = validateBet(player.money);
        showmenu();

        int option;
        cin >> option;

        int betNumber = -1;
        string betColor;
        string betEvenOdd;

        switch (option) {
            case 1:
                cout << "Bet on number (0-36): ";
                cin >> betNumber;
                if (betNumber < 0 || betNumber > 36) {
                    cout << "Invalid number. You lose this round.\n";
                    player.money -= bet;
                    round++;
                    continue;
                }
                break;
            case 2:
                cout << "Bet on color (red/black): ";
                cin >> betColor;
                break;
            case 3:
                cout << "Bet on even or odd: ";
                cin >> betEvenOdd;
                break;
            default:
                cout << "Invalid option. You lose this round.\n";
                player.money -= bet;
                round++;
                continue;
   }   }   }   

     int result = rand() % 37;
        string resultColor = getColor(result);

        cout << "Roulette spun... Number: " << result << " - Color: " << resultColor << endl;

        bool won = false;

        if (option == 1 && result == betNumber) {
            player.money += bet * 35;
            player.wins++;
            won = true;
        } else if (option == 2 && resultColor == betColor) {
            player.money += bet;
            player.wins++;
            won = true;
        } else if (option == 3) {
            if ((betEvenOdd == "even" && result % 2 == 0 && result != 0) ||
                (betEvenOdd == "odd" && result % 2 != 0)) {
                player.money += bet;
                player.wins++;
                won = true;
            }
        }

        if (!won) {
            player.money -= bet;
            cout << "Result: You lost this round.\n";
        } else {
            cout << "🎉 You won this round!\n";
        }

        round++;
    

    // Final result
    cout << "\n===== FINAL RESULTS =====\n";
    cout << "Player: " << player.name << endl;
    cout << "Wins: " << player.wins << endl;
    cout << "Final balance: $" << player.money << endl;

    if (player.wins >= 3)
        cout << "You won with 3 correct bets!\n";
    else if (player.money <= 0)
        cout << "You ran out of money. 😢\n";
    else
        cout << "Game ended after 6 rounds.\n";


int main() {
    srand(time(0));
    Player player;
    player.wins = 0;
    player.money = 100;

    cout << "🎰 WELCOME TO ROULETTE 🎰\n";
    cout << "Enter your name: ";
    cin.ignore();
    getline(cin, player.name);

    playRoulette(player);
    return 0;
}