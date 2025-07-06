#include <iostream>
#include <fstream>
#include <windows.h> // NECESARIO para SetConsoleOutputCP
#include "Bingo.h"

using namespace std;

const int Max = 2;
Player data[Max]; // Se supone que esto es un arreglo así que la variable data va a contener 2 espacios de memoria.
int total = 0;    // Total esto va porque lo vamos a necesitar mas adelante.

void add()
{
    if (total >= Max)
    {
        cout << "Full capacity" << endl;
        return;
    }
    for (int i = total; i < Max; i++) // Recorre 2 veces el arreglo.
    {
        cout << "---------------------------------------" << endl;
        cout << endl;
        cout << "\n \t PLAYER PROFILE " << endl;

        cout << " \n \t Enter your name: " << endl;
        cout << "\t ";
        cin >> data[total].name;

        cout << "\n \t Enter your age: " << endl;
        cout << "\t ";
        cin >> data[total].age;

        if (data[total].age < 18 || data[total].age > 90)
        {
            cout << "\t \n Age restriction: only users aged 18 to 90 can play. " << endl;
            exit(0);
        }
        else
        {
            cout << "\n \t Enter your initial balance: \n ";
            cout << "\t $ ";
            cin >> data[total].balance;

            if (data[total].balance < 10)
            {

                cout << "\n \t You do not have enough money to bet" << endl;
                cout << "\n\t Please, started the game again. " << endl;
                exit(0);
            }
            else
            {

                ++total;

                cout << "\n \t Added!" << endl;
                cout << endl;
                cout << "---------------------------------------" << endl;
            }
        }
    }
}

void Show()
{

    cout << "---------------------------------PLAYERS----------------------------------" << endl;

    if (total == 0)
    {
        cout << "No one is added" << endl;
        return;
    }

    for (int i = 0; i <= total; i++)
    {
        cout << data[i].name << endl;
        cout << data[i].age << "years" << endl;
        cout << endl;
    }
}

void Welcome()
{

    cout << R"(             
                
    
    
    
    
    
                                       ╔═══════════════════════════════════════════════════════════════════════════╗
                                       ║                                                                           ║
                                       ║           ¡¡¡¡  WELCOME TO THE ROYALE CASINO EXPERIENCE  !!!              ║
                                       ║                                                                           ║
                                       ║    You are invited to test your luck in our finest selection of games.    ║
                                       ║           Please choose one of the following options to begin             ║
                                       ║                                                                           ║
                                       ║                                                                           ║ 
                                       ║                        1. Russian Roulette                                ║
                                       ║                                                                           ║
                                       ║                        2. Blackjack                                       ║
                                       ║                                                                           ║
                                       ║                        3. Bingo                                           ║
                                       ║                                                                           ║
                                       ║                        4. Dice                                            ║
                                       ║                                                                           ║
                                       ║                                                                           ║  
                                       ╚═══════════════════════════════════════════════════════════════════════════╝ 
                
                
                
                
                
                
                
                
                
                )"
         << endl;
}

void Save()
{

    ofstream file("Player_profiles.txt"); // Abrir y si no lo encuentra crearlo.
    file << total << " PLAYERS: " << endl;

    for (int i = 0; i < total; i++)
    {

        file << data[i].name << " - " << data[i].age << " years " << "- $ " << data[i].balance << endl;
    }

    file.close();

    cout << "\n \t Player profiles saved succesfully \n"
         << endl;
}

void open()
{

    ifstream file("Player_profiles.txt");
    if (!file)
    {
        cout << "File not found" << endl;
        return;
    }

    file >> total;
    if (total > Max)
        total = Max;
    for (int i = 0; i < total; ++i)
    {
        file >> data[i].name >> data[i].age;
    }
    file.close();
}
