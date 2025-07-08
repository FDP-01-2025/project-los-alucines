#ifndef Poker_H 
#define Poker_H 
// These two are directives to avoid including the .h file more than once

#include <iostream>
#include <iomanip> 
// Used to control how data is displayed on screen, will be used to align card numbers
#include <string> 
// For using string data type
#include <fstream> 
// For file operations
#include <cstdlib>  
// For rand() and srand() which will be used for shuffling and dealing cards randomly
#include <ctime>    
// Initializes the random seed with a different value each time
#include <sstream> 
// Will be used to convert string data to int
#include <windows.h> 
// For Windows-specific functions, Sleep() to pause, system("cls") to clear screen
#include "Player_profiles.h"

using namespace std;

// Array to store up to 2 players
extern Player data[2];

void StartPokerBet() 
{
    
            cout << R"(

                   ╔═══════════════════════════════════════════════════════════════════════╗
                   ║                                                                       ║
      ▓▓           ║   ████████╗██╗  ██╗███████╗       ██████╗  █████╗ ███╗   ███╗███████╗ ║         ▓▓
    ▓▓▓▓▓▓         ║   ╚══██╔══╝██║  ██║██╔════╝      ██╔════╝ ██╔══██╗████╗ ████║██╔════╝ ║       ▓▓▓▓▓▓
  ▓▓▓▓▓▓▓▓▓▓       ║      ██║   ███████║█████╗        ██║  ███╗███████║██╔████╔██║█████╗   ║     ▓▓▓▓▓▓▓▓▓▓
▓▓▓▓▓▓▓▓▓▓▓▓▓▓     ║      ██║   ██╔══██║██╔══╝        ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝   ║   ▓▓▓▓▓▓▓▓▓▓▓▓▓▓
  ▓▓▓▓▓▓▓▓▓▓       ║      ██║   ██║  ██║███████╗      ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗ ║     ▓▓▓▓▓▓▓▓▓▓
    ▓▓▓▓▓▓         ║      ╚═╝   ╚═╝  ╚═╝╚══════╝       ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝ ║       ▓▓▓▓▓▓
      ▓▓           ║                                                                       ║         ▓▓
                   ║                 ♦♦♦  T H E   G A M E   O F   P O K E R  ♠♠♠           ║
                   ╚═══════════════════════════════════════════════════════════════════════╝
 

                   ╔════════════════════════════════════════════════════════════════════════╗
      ▓▓           ║                                                                        ║
    ▓▓▓▓▓▓         ║   █████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█████     ║
  ▓▓▓▓▓▓▓▓▓▓       ║   █    ▒▒▒▒▒▒▒▒▒▒▒▒▒ ♠ THE VEGAS ROYALE POKER ♠ ▒▒▒▒▒▒▒▒▒▒▒▒▒    █     ║
▓▓▓▓▓▓▓▓▓▓▓▓▓▓     ║   █    ▒▒▒▒▒▒▒▒▒▒▒▒▒                            ▒▒▒▒▒▒▒▒▒▒▒▒▒    █     ║
  ▓▓▓▓▓▓▓▓▓▓       ║   █████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█████     ║
    ▓▓▓▓▓▓         ║                                                                        ║
      ▓▓           ║   ♠ Welcome to the dazzling world of high stakes poker ♠               ║          ▓▓
                   ║   ♦ Only $100 to enter. Winner takes all.                              ║        ▓▓▓▓▓▓
                   ║   ♣ Use your skills. Bluff with style. Win BIG.                        ║      ▓▓▓▓▓▓▓▓▓▓
                   ║   ♥ Only the brave bet. Only the best win.                             ║    ▓▓▓▓▓▓▓▓▓▓▓▓▓▓
                   ║                                                                        ║      ▓▓▓▓▓▓▓▓▓▓
                   ║   Minimum Buy-In: $100   ||   Max Players: 2                           ║        ▓▓▓▓▓▓
                   ╚════════════════════════════════════════════════════════════════════════╝          ▓▓

            )" << endl;

            bool valid = false;
            for(int i = 0; i < 2; i++){
                
            cout << "\n\t\t\t Welcome, " << data[i].name << "!" << endl;
            cout << "\t\t\t Enter your bet amount: $";
            cin >> data[i].bet;

            cout << "\n\t\t\t Processing your bet...\n";
            Sleep(2000);

            if (data[i].bet < 100) 
            {
                cout << "\n\t\t\t Minimum bet is $100. Try again.\n";
                Sleep(2000);
                system("cls");
            } else if (data[i].bet > data[i].balance) 
            {
                cout << "\n\t\t\t Insufficient balance for that bet.\n";
                Sleep(2000);
                system("cls");
            } else 
            {
                valid = true;
                cout << "\n\t\t\t Bet of $" << data[i].bet << " registered successfully!\n";
                Sleep(2000);
                system("cls");
            }
        }
    

    cout << R"(

        cout << R"(

 ███████╗██╗   ██╗███████╗██████╗ ████████╗███████╗
 ██╔════╝██║   ██║██╔════╝██╔══██╗╚══██╔══╝██╔════╝
 ███████╗██║   ██║█████╗  ██████╔╝   ██║   █████╗  
 ╚════██║╚██╗ ██╔╝██╔══╝  ██╔══██╗   ██║   ██╔══╝  
 ███████║ ╚████╔╝ ███████╗██║   ██╗  ██║   ███████╗
 ╚══════╝  ╚═══╝  ╚══════╝╚═╝   ╚═╝  ╚═╝   ╚══════╝

       LET THE CARDS FALL WHERE THEY MAY...
    )" << endl;
}


// Card structure
struct Card
{
    string number;
    string suit;
    string color;
};


// Function that prints a specific line of a card
void printCardLine(const Card &card, int line)
{
    string suitSymbol;
    if (card.suit == "hearts")
        suitSymbol = "♥";
    else if (card.suit == "diamonds")
        suitSymbol = "♦";
    else if (card.suit == "clubs")
        suitSymbol = "♣";
    else if (card.suit == "spades")
        suitSymbol = "♠";
    else
        suitSymbol = "?";

    string colorAnsi = (card.color == "pink") ? "\033[31m" : "\033[30m"; //change card colors
    string resetAnsi = "\033[0m";

    //Card design
    switch (line)
    {
    case 0:
        cout << colorAnsi << "+---------+" << resetAnsi;
        break;
    case 1:
        cout << colorAnsi << "| " << setw(2) << left << card.number << "      |" << resetAnsi;
        break;
    case 2:
        cout << colorAnsi << "|         |" << resetAnsi;
        break;
    case 3:
        cout << colorAnsi << "|   " << suitSymbol << "     |" << resetAnsi;
        break;
    case 4:
        cout << colorAnsi << "|         |" << resetAnsi;
        break;
    case 5:
        cout << colorAnsi << "|      " << setw(2) << right << card.number << " |" << resetAnsi;
        break;
    case 6:
        cout << colorAnsi << "+---------+" << resetAnsi;
        break;
    }
}

//Array where the 52-card deck is stored, imported from .txt file
Card deck[52];

void ReadFiles()
{
    ifstream cards("Cards.txt");
    if (cards.is_open())
    {
        for (int i = 0; i < 52; i++)
        {
            cards >> deck[i].number >> deck[i].suit >> deck[i].color;
        }
    }
    cards.close();

    for (int i = 0; i < 52; i++)
    {
        cout << deck[i].number << " - " << deck[i].suit << " - "<< deck[i].color << endl;
    }
}

// Declaration of each player's hand
Card player1Hand[5];
Card player2Hand[5];

// Auxiliary array to mark which cards in the deck have already been dealt
bool usedCard[52] = {false};

// Function that prints cards horizontally
void printHandHorizontal(const Card hand[], int numCards)
{
    const int NUM_LINES = 7; // Each card has 7 lines

    for (int line = 0; line < NUM_LINES; ++line)
    {
        for (int i = 0; i < numCards; ++i)
        {
            printCardLine(hand[i], line);
            cout << "  "; // Space between cards
        }
        cout << endl;
    }
}

// Function that deals 5 random cards to each player without repeating
void dealCards()
{
    srand(time(0)); // Initialize random seed (only once)

    int cardsDealt = 0;

    // Deal 5 cards to player 1
    for (int i = 0; i < 5; i++)
    {
        int index;
        do
        {
            index = rand() % 52; // Generate random number between 0 and 51
        } while (usedCard[index]); // Repeat while card has already been used

        player1Hand[i] = deck[index]; // Assign card to player
        usedCard[index] = true;      // Mark card as used
        cardsDealt++;
    }

    // Deal 5 cards to player 2
    for (int i = 0; i < 5; i++)
    {
        int index;
        do
        {
            index = rand() % 52;
        } while (usedCard[index]);

        player2Hand[i] = deck[index];
        usedCard[index] = true;
        cardsDealt++;
    }
     // Show original hands
    cout << "\n" << data[0].name << "'s cards:\n";
}


//Function to change a maximum of 2 cards per player
void changeCards(Card hand[], const string& playerName)
{
    for (int attempt = 0; attempt < 2; attempt++) // Two opportunities to change cards
    {
        printHandHorizontal(hand, 5);
        cout << playerName << ", do you want to change a card? (y/n): ";
        char response;
        cin >> response;

        if (response == 'y' || response == 'Y')
        {
            int index;
            do {
                cout << "Which card do you want to change? (1-5): ";
                cin >> index;
            } while (index < 1 || index > 5);

            // Find a new unused card in the deck
            int newCardIndex;
            do {
                newCardIndex = rand() % 52;
            } while (usedCard[newCardIndex]);

            // Replace the card in the hand
            hand[index - 1] = deck[newCardIndex];
            usedCard[newCardIndex] = true;

            cout << "Card changed successfully.\n\n";
        }
        else
        {
            cout << "No card was changed this attempt.\n\n";
        }
    }
    cout << "\nFinal hand of " << data[0].name << ":\n";
}

// Evaluates and compares both hands with real poker rules
void evaluateHands() {
    // Conversion from string to numerical value 
    auto cardValue = [](const string& number) -> int {
        if (number == "A") return 1;
        if (number == "K") return 13;
        if (number == "Q") return 12;
        if (number == "J") return 11;
        return atoi(number.c_str());
    };

    // Evaluates a hand, assigns hand type (0 to 8) and high card
    auto evaluate = [&](Card hand[5], int& handType, int& highCard) {
        int values[5];
        string suits[5];
        int count[14] = {0}; // index 1 to 13
        bool used[14] = {false};

        for (int i = 0; i < 5; i++) {
            values[i] = cardValue(hand[i].number);
            suits[i] = hand[i].suit;
            count[values[i]]++;
            used[values[i]] = true;
        }

        // Sort values descending (simple bubble sort)
        for (int i = 0; i < 4; i++) {
            for (int j = i + 1; j < 5; j++) {
                if (values[i] < values[j]) {
                    int temp = values[i];
                    values[i] = values[j];
                    values[j] = temp;
                }
            }
        }

        // Check if all cards are the same suit
        bool isFlush = true;
        for (int i = 1; i < 5; i++) {
            if (suits[i] != suits[0]) {
                isFlush = false;
                break;
            }
        }

        // Check if it's a straight (5 consecutive values)
        bool isStraight = true;
        for (int i = 1; i < 5; i++) {
            if (values[i] != values[i - 1] - 1) {
                isStraight = false;
                break;
            }
        }

        // Check special straight A-2-3-4-5
        if (!isStraight &&
            values[0] == 5 &&
            values[1] == 4 &&
            values[2] == 3 &&
            values[3] == 2 &&
            values[4] == 1) {
            isStraight = true;
        }

        // Detect pairs, trios, four of a kind
        int pairs = 0, trios = 0, fourKind = 0;
        int pairValue1 = 0, pairValue2 = 0, trioValue = 0, fourKindValue = 0;

        for (int i = 1; i <= 13; i++) {
            if (count[i] == 4) { fourKind = 1; fourKindValue = i; }
            if (count[i] == 3) { trios++; trioValue = i; }
            if (count[i] == 2) {
                pairs++;
                if (pairValue1 == 0) pairValue1 = i;
                else pairValue2 = i;
            }
        }

        // Hand type classification
        if (isStraight && isFlush)      { handType = 8; highCard = values[0]; }
        else if (fourKind)                 { handType = 7; highCard = fourKindValue; }
        else if (trios && pairs)        { handType = 6; highCard = trioValue; }
        else if (isFlush)               { handType = 5; highCard = values[0]; }
        else if (isStraight)            { handType = 4; highCard = values[0]; }
        else if (trios)                 { handType = 3; highCard = trioValue; }
        else if (pairs == 2)            { handType = 2; highCard = (pairValue1 > pairValue2 ? pairValue1 : pairValue2); }
        else if (pairs == 1)            { handType = 1; highCard = pairValue1; }
        else                            { handType = 0; highCard = values[0]; } // high card
    };

    // Evaluate both hands
    int type1 = 0, type2 = 0;
    int high1 = 0, high2 = 0;

    evaluate(player1Hand, type1, high1);
    evaluate(player2Hand, type2, high2);

    cout << "\nGame result:\n";
    cout << data[0].name << " has hand type " << type1 << " with high card " << high1 << endl;
    cout << data[1].name << " has hand type " << type2 << " with high card " << high2 << endl;

    // Show winner
    if (type1 > type2) {
        cout << "\n The winner is: " << data[0].name << "\n";
    } else if (type2 > type1) {
        cout << "\n The winner is: " << data[1].name << "\n";
    } else {
        if (high1 > high2)
            cout << "\n The winner is: " << data[0].name << "\n";
        else if (high2 > high1)
            cout << "\n The winner is: " << data[1].name << "\n";
        else
            cout << "\n Technical tie!\n";
    }
}

#endif