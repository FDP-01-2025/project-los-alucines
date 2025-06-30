#include <iostream>
#include <fstream>
#include <windows.h> // NECESARIO para SetConsoleOutputCP
#include "Functions.h"

using namespace std;

const int Max = 2;
Player data[Max]; // Se supone que esto es un arreglo así que la variable data va a contener 2 espacios de memoria.
int total = 0;    // Total esto va porque lo vamos a necesitar mas adelante.

void add()
{
    if (total >= Max)
    {
        cout << "Full capacity" << endl;
    }
    for (int i = 0; i < Max; i++) // Recorre 2 veces el arreglo.
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
            cout << "\t Age restriction: only users aged 18 to 90 can play. " << endl;
            return;
        }
        else
        {
            cout << "\n \t Enter your initial balance: \n ";
            cout << "\t $ ";
            cin >> data[total].balance;

            if (data[total].balance < 10)
            {

                cout << "\n \t You do not have enough money to bet" << endl;
                cout << "Please, started the game again. " << endl;
                return;
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
