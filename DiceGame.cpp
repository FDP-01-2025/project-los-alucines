#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Dice.h"

using namespace std;

struct Player {
    string name;
    int money;
    int wins;
};

string dice[6][5]={
    {" ------- ", "|       |", "|   *   |", "|       |", " ------- "},
    {" ------- ", "| *     |", "|       |", "|     * |", " ------- "},
    {" ------- ", "| *     |", "|   *   |", "|     * |", " ------- "},
    {" ------- ", "| *   * |", "|       |", "| *   * |", " ------- "},
    {" ------- ", "| *   * |", "|   *   |", "| *   * |", " ------- "},
    {" ------- ", "| *   * |", "| *   * |", "| *   * |", " ------- "}
};

void printCenteredDiceLine(const string& line, int width = 60) {
    int spaces = max(0, (width - (int)line.length()) / 2);
    for (int i = 0; i < spaces; i++) cout << " ";
    cout << line << endl;
}

void printCentered(string text, int width = 60) {
    int spaces = max(0, (width - (int)text.length()) / 2);
    for (int i = 0; i < spaces; i++) cout << " ";
    cout << text << endl;
}

int rollDice() {
    return rand() % 6 + 1;
}

void showDiceHorizontal(int d1, int d2) {
    for (int i = 0; i < 5; i++) {
        string line = dice[d1 - 1][i] + "   " + dice[d2 - 1][i];
        printCenteredDiceLine(line);
    }
}

void runTheHouseofDice() {
    srand(time(0));

    Player players[2];
    cout << endl;
    printCentered("==================== THE HOUSE OF DICE ====================");
    cout << endl;
    printCentered("=============== GAME RULES ===============");
    printCentered("1. Two players enter their names.");
    printCentered("2. Each starts with $500.");
    printCentered("3. Both place a bet each round.");
    printCentered("4. Each player rolls 2 dice.");
    printCentered("5. Highest total wins the round and takes the opponent's bet.");
    printCentered("6. If it's a tie, nothing happens.");
    printCentered("7. First to reach 3 wins takes the game.");
    printCentered("8. The game also ends if a player runs out of money.");
    printCentered("9. After 6 rounds, the player with more wins is the winner.");
    printCentered("==========================================");
    cout << endl;
    printCentered("Press ENTER to begin...");
    cin.ignore();
    cin.get();

    printCentered("Player 1, please enter your name: ");
    getline(cin, players[0].name);
    printCentered("Player 2, please enter your name: ");
    getline(cin, players[1].name);

    for(int i = 0; i < 2; i++) {
        players[i].money = 500;
        players[i].wins = 0;
    }
    
    int round = 1;
    while (players[0].wins < 3 && players[1].wins < 3 && round <= 6) {
        cout << endl;
        printCentered("ROUND " + to_string(round));
        cout << endl;

        int bet[2];
        for (int i = 0; i < 2; i++) {
            printCentered(players[i].name + ", you have $" + to_string(players[i].money) + ". Enter your bet: ");
            cin >> bet[i];
            if (bet[i] > players[i].money || bet[i] <= 0) {
                printCentered("Invalid bet! A minimum bet of $1 was assigned.");
                bet[i] = 1;
            }

        }
    }
