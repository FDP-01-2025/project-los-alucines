#ifndef DICE_H
#define DICE_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

struct Player {
    string name;
    int money;
    int wins;
};

string dice[6][5] = {
    {" ------- ", "|       |", "|   *   |", "|       |", " ------- "},
    {" ------- ", "| *     |", "|       |", "|     * |", " ------- "},
    {" ------- ", "| *     |", "|   *   |", "|     * |", " ------- "},
    {" ------- ", "| *   * |", "|       |", "| *   * |", " ------- "},
    {" ------- ", "| *   * |", "|   *   |", "| *   * |", " ------- "},
    {" ------- ", "| *   * |", "| *   * |", "| *   * |", " ------- "}
};

void centerText(const string& text, int width = 60) {
    int spaces = max(0, (width - static_cast<int>(text.length())) / 2);
    for (int i = 0; i < spaces; i++) cout << " ";
    cout << text << endl;
}

void centerDiceLine(const string& line, int width = 60) {
    int spaces = max(0, (width - static_cast<int>(line.length())) / 2);
    for (int i = 0; i < spaces; i++) cout << " ";
    cout << line << endl;
}

int rollDice() {
    return rand() % 6 + 1;
}

void showDiceHorizontal(int d1, int d2) {
    for (int i = 0; i < 5; i++) {
        string line = dice[d1 - 1][i] + "   " + dice[d2 - 1][i];
        centerDiceLine(line);
    }
}

void saveGameResult(const Player& p1, const Player& p2) {
    ofstream outFile("Dice_Results.txt", ios::app);
    outFile << "=== THE HOUSE OF DICE ===" << endl;
    outFile << "Player 1: " << p1.name << " | Wins: " << p1.wins << " | Final Money: $" << p1.money << endl;
    outFile << "Player 2: " << p2.name << " | Wins: " << p2.wins << " | Final Money: $" << p2.money << endl;
    if (p1.wins > p2.wins)
        outFile << "Winner: " << p1.name << endl;
    else if (p2.wins > p1.wins)
        outFile << "Winner: " << p2.name << endl;
    else
        outFile << "Result: Tie" << endl;
    outFile << "--------------------------" << endl;
    outFile.close();
}


void runTheHouseofDice() {
    srand(time(0));

    Player players[2];
    cout << endl;
    cout << R"(

  _______ _            _     _                            _         
 |__   __| |          | |   | |                          | |        
    | |  | |__   ___  | |__ | | ___  ___  ___ _ ____   __| | ___    
    | |  | '_ \ / _ \ | '_ \| |/ _ \/ __|/ _ \ '__\ \ / /| |/ _ \   
    | |  | | | |  __/ | | | | |  __/\__ \  __/ |   \ V / | | (_) |  
    |_|  |_| |_|\___| |_| |_|_|\___||___/\___|_|    \_/  |_|\___/   

      _    _                                                  
     | |  | |                                                 
     | |__| |_   _ _ __   ___  _____      _____  ___ _ __ ___ 
     |  __  | | | | '_ \ / _ \/ __\ \ /\ / / _ \/ _ \ '__/ __|
     | |  | | |_| | | | |  __/\__ \\ V  V /  __/  __/ |  \__ \
     |_|  |_|\__,_|_| |_|\___||___/ \_/\_/ \___|\___|_|  |___/

)" << endl;
    cout << endl;
    centerText("=============== GAME RULES ===============");
    centerText("1. Two players enter their names.");
    centerText("2. Each starts with $500.");
    centerText("3. Both place a bet each round.");
    centerText("4. Each player rolls 2 dice.");
    centerText("5. Highest total wins the round and takes the opponent's bet.");
    centerText("6. If it's a tie, nothing happens.");
    centerText("7. First to reach 3 wins takes the game.");
    centerText("8. The game also ends if a player runs out of money.");
    centerText("9. After 6 rounds, the player with more wins is the winner.");
    centerText("==========================================");
    cout << endl;
    centerText("Press ENTER to begin...");
    cin.ignore();
    cin.get();

    centerText("Player 1, enter your name: ");
    getline(cin, players[0].name);
    centerText("Player 2, enter your name: ");
    getline(cin, players[1].name);

      for (int i = 0; i < 2; i++) {
        players[i].money = 500;
        players[i].wins = 0;
    }

    int round = 1;
    while (players[0].wins < 3 && players[1].wins < 3 && round <= 6) {
        cout << endl;
        centerText("ROUND " + to_string(round));
        cout << endl;

        int bet[2];
        for (int i = 0; i < 2; i++) {
            centerText(players[i].name + ", you have $" + to_string(players[i].money) + ". Enter your bet:");
            cin >> bet[i];
            if (bet[i] > players[i].money || bet[i] <= 0) {
                centerText("Invalid bet! A minimum bet of $1 was assigned.");
                bet[i] = 1;
            }
        }

        int sum[2];
        for (int i = 0; i < 2; i++) {
            cout << endl;
            centerText("Rolling dice for " + players[i].name + "...");
            int d1 = rollDice();
            int d2 = rollDice();
            sum[i] = d1 + d2;
            showDiceHorizontal(d1, d2);
            centerText("Total: " + to_string(sum[i]));
        }

        if (sum[0] > sum[1]) {
            cout << endl;
            centerText(players[0].name + " wins this round!");
            players[0].wins++;
            players[0].money += bet[1];
            players[1].money -= bet[1];
        }
        else if (sum[1] > sum[0]) {
            cout << endl;
            centerText(players[1].name + " wins the round.!");
            players[1].wins++;
            players[1].money += bet[0];
            players[0].money -= bet[0];
        }
        else {
            cout << endl;
            centerText("It's a tie! No money exchanged");
        }

        cout << endl;
        centerText("Current Scores:");
        centerText(players[0].name + " [" + to_string(players[0].wins) + " wins, $" + to_string(players[0].money) + "]");
        centerText("VS");
        centerText(players[1].name + " [" + to_string(players[1].wins) + " wins, $" + to_string(players[1].money) + "]");

        round++;
        
        if (players[0].money <= 0 || players[1].money <= 0) {
            cout << endl;
            centerText("A player has run out of money! Ending game...");
            break;
        }
    }
    
    cout << endl;
    centerText("==================== FINAL RESULT ====================");
    if (players[0].wins > players[1].wins)
        centerText(players[0].name + " wins the game with $" + to_string(players[0].money) + " remaining.");
    else if (players[1].wins > players[0].wins)
        centerText(players[1].name + " wins the game with $" + to_string(players[1].money) + " remaining.");
    else
        centerText("The game ended in a tie.");
    centerText("======================================================");
    centerText("Thank you for playing The House of Dice, enjoy the rest of the games!");

    saveGameResult(players[0], players[1]);
}

#endif