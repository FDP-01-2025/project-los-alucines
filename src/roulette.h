#ifndef ROULETTE_H
#define ROULETTE_H

#include "Player_profiles.h"

void playRoulette(Player &player);

#endif 

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <algorithm>

#include "roulette.h"
#include "Player_profiles.h"

using namespace std;

string getColor(int number) {
    int reds[] = {1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
    if (number == 0) return "Green";
    for (int i = 0; i < 18; i++)
        if (number == reds[i]) return "Red";
    return "Black";
}

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

int validateBet(int money) {
    int bet;
    cin >> bet;
    if (bet > money || bet < 1) {
        cout << "Invalid bet! Betting $1 by default.\n";
        return 1;
    }
    return bet;
}

void playRoulette(Player &player) {
    srand((unsigned)time(nullptr));
    int rounds = 5;

    cout << R"(
  _____   _    _ _      _      _       
 |  __ \ | |  | (_)    | |    | |      
 | |__) || |__| |_ ___ | | __ | |_ ___ 
 |  _  / |  __  | / __|| |/ / | __/ _ \
 | | \ \ | |  | | \__ \|   <  | ||  __/
 |_|  \_\|_|  |_|_|___/_|\_\  \__\___|

)" << "\n";
    cout << "===== ROULETTE =====\n";
    cout << "Starting balance: $" << player.money << "\n";
    cout << "You will play " << rounds << " rounds.\n";
    cout << "Bet types:\n"
         << " 1. Exact number (0‑36) — payout 35×\n"
         << " 2. Color (Red/Black) — payout 2×\n"
         << " 3. Even/Odd — payout 2×\n";
    cout << "Enter a valid bet (min $1).\nPress ENTER to begin...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    player.wins = 0;
    for (int i = 1; i <= rounds && player.money > 0; i++) {
        system("cls");
        cout << "ROUND " << i << " — Balance: $" << player.money << "\n";
        cout << "Choose bet type (1‑3): ";
        int type; cin >> type;
        cout << "Enter bet amount: $";
        int bet = validateBet(player.money);

        int guessNum = -1;
        string guessStr;

        if (type == 1) {
            cout << "Pick number (0‑36): ";
            cin >> guessNum;
        } else if (type == 2) {
            cout << "Pick color (Red/Black): ";
            cin >> guessStr;
            guessStr = toLower(guessStr);
        } else if (type == 3) {
            cout << "Pick (Even/Odd): ";
            cin >> guessStr;
            guessStr = toLower(guessStr);
        } else {
            cout << "Invalid choice, skipping round.\n";
            continue;
        }

        int result = rand() % 37;
        string color = getColor(result);
        cout << "\nWheel spun: " << result << " (" << color << ")\n";

        bool win = false;
        int payout = 0;

        if (type == 1 && guessNum == result) {
            win = true; payout = bet * 35;
        } else if (type == 2 && color.size() && toLower(color) == guessStr) {
            win = true; payout = bet * 2;
        } else if (type == 3) {
            if (result != 0) {
                if (guessStr == "even" && result % 2 == 0) win = true;
                if (guessStr == "odd" && result % 2 == 1) win = true;
            }
            if (win) payout = bet * 2;
        }

        if (win) {
            cout << "You WON $" << payout << "! 🎉\n";
            player.money += payout;
            player.wins++;
        } else {
            cout << "You LOST $" << bet << ". 💸\n";
            player.money -= Bet;
        }

        cout << "Current balance: $" << player.money << "\n";
        system("pause");
    }

    cout << "\nGAME OVER\n";
    cout << "Final balance: $" << player.money << "\n";
    cout << "Rounds won: " << player.wins << "\n";

    ofstream file("Roulette_scores.txt", ios::app);
    if (file) {
        file << "=== ROULETTE ===\n";
        file << "Player: " << player.name << "\n";
        file << "Final Money: $" << player.money << "\n";
        file << "Rounds Won: " << player.wins << "\n";
        file << "-----------------\n";
        file.close();
    }

    cout << "Score saved. Thanks for playing!\n";
}
