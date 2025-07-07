#ifndef DICE_H
#define DICE_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <fstream>

#include "Bingo.h"     
extern Player data[2]; 

using namespace std;

string dice[6][5] = {
    {" ------- ", "|       |", "|   *   |", "|       |", " ------- "},
    {" ------- ", "| *     |", "|       |", "|     * |", " ------- "},
    {" ------- ", "| *     |", "|   *   |", "|     * |", " ------- "},
    {" ------- ", "| *   * |", "|       |", "| *   * |", " ------- "},
    {" ------- ", "| *   * |", "|   *   |", "| *   * |", " ------- "},
    {" ------- ", "| *   * |", "| *   * |", "| *   * |", " ------- "}};

void centerText(const string &text, int width = 60)
{
    int spaces = max(0, (width - static_cast<int>(text.length())) / 2);
    for (int i = 0; i < spaces; i++)
        cout << " ";
    cout << text << endl;
}

void centerDiceLine(const string &line, int width = 60)
{
    int spaces = max(0, (width - static_cast<int>(line.length())) / 2);
    for (int i = 0; i < spaces; i++)
        cout << " ";
    cout << line << endl;
}

int rollDice()
{
    return rand() % 6 + 1;
}

void showDiceHorizontal(int d1, int d2)
{
    for (int i = 0; i < 5; i++)
    {
        string line = dice[d1 - 1][i] + "   " + dice[d2 - 1][i];
        centerDiceLine(line);
    }
}

void runTheHouseofDice()
{
    srand(time(0));
    int wins[2] = {0, 0}; 

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
    centerText("1. Players already entered their profiles.");
    centerText("2. Each starts with their chosen balance.");
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

    int round = 1;
    while (wins[0] < 3 && wins[1] < 3 && round <= 6)
    {
        cout << endl;
        centerText("ROUND " + to_string(round));
        cout << endl;

        float bet[2];
        for (int i = 0; i < 2; i++)
        {
            centerText(data[i].name + ", you have $" + to_string(data[i].balance) + ". Enter your bet:");
            cin >> bet[i];
            if (bet[i] > data[i].balance || bet[i] <= 0)
            {
                centerText("Invalid bet! A minimum bet of $1 was assigned.");
                bet[i] = 1;
            }
        }

        int sum[2];
        for (int i = 0; i < 2; i++)
        {
            cout << endl;
            centerText("Rolling dice for " + data[i].name + "...");
            int d1 = rollDice();
            int d2 = rollDice();
            sum[i] = d1 + d2;
            showDiceHorizontal(d1, d2);
            centerText("Total: " + to_string(sum[i]));
        }

        if (sum[0] > sum[1])
        {
            cout << endl;
            centerText(data[0].name + " wins this round!");
            wins[0]++;
            data[0].balance += bet[1];
            data[1].balance -= bet[1];
        }
        else if (sum[1] > sum[0])
        {
            cout << endl;
            centerText(data[1].name + " wins this round!");
            wins[1]++;
            data[1].balance += bet[0];
            data[0].balance -= bet[0];
        }
        else
        {
            cout << endl;
            centerText("It's a tie! No money exchanged");
        }

        cout << endl;
        centerText("Current Scores:");
        centerText(data[0].name + " [" + to_string(wins[0]) + " wins, $" + to_string(data[0].balance) + "]");
        centerText("VS");
        centerText(data[1].name + " [" + to_string(wins[1]) + " wins, $" + to_string(data[1].balance) + "]");

        round++;

        if (data[0].balance <= 0 || data[1].balance <= 0)
        {
            cout << endl;
            centerText("A player has run out of money! Ending game...");
            break;
        }
    }

    cout << endl;
    centerText("==================== FINAL RESULT ====================");
    if (wins[0] > wins[1])
        centerText(data[0].name + " wins the game with $" + to_string(data[0].balance) + " remaining.");
    else if (wins[1] > wins[0])
        centerText(data[1].name + " wins the game with $" + to_string(data[1].balance) + " remaining.");
    else
        centerText("The game ended in a tie.");
    centerText("======================================================");
    centerText("Thank you for playing The House of Dice!");
}

#endif
