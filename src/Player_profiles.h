#include <iostream>
#include <fstream>
#include <windows.h> // REQUIRED for SetConsoleOutputCP
#include "Bingo.h"

using namespace std;

Player data[2]; // This array holds 2 player profiles
int total = 0;

void add()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 9); // Light blue color

    cout << R"(
                                                        ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
                                                        
                                                           PLAYER PROFILE SETUP 
                                                        ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄ 
    )" << endl;

    if (total >= 2)
    {
        cout << "Full capacity" << endl;
        return;
    }

    for (int i = total; i < 2; i++) // Loop twice to fill the array
    {
        cout << " ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬" << endl;
        cout << endl;
        cout << "\n \t PLAYER PROFILE " << endl;

        cout << " \n \t Enter your name: ";
        cin >> data[i].name;

        bool valid = true;
        for (int j = 0; j < data[i].name.length(); j++)
        {
            if (!isalpha(data[i].name[j]))
            {
                valid = false;
            }
        }

        if (!valid)
        {
            cout << "\n \t Invalid name. Use only letters (no numbers or symbols)." << endl;
            exit(0);
        }

        cout << "\n \t Enter your age: ";
        cin >> data[i].age;

        if (cin.fail())
        {
            cout << "\n\t\t Invalid number" << endl;
            valid = false;
            exit(0);
        }
        else if (data[i].age < 18 || data[i].age > 90)
        {
            cout << "\t \n Age restriction: only users aged 18 to 90 can play." << endl;
            exit(0);
        }
        else
        {
            cout << "\n \t Enter your initial balance: $ ";
            cin >> data[i].balance;

            if (cin.fail())
            {
                cout << "\n\t\t Invalid number" << endl;
                valid = false;
                exit(0);
            }
            else if (data[i].balance < 10)
            {
                cout << "\n \t You do not have enough money to bet." << endl;
                cout << "\n\t Please restart the game." << endl;
                exit(0);
            }
            else
            {
                ++total;

                cout << "\n \t Added!" << endl;
                cout << endl;
                cout << " ▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬" << endl;
            }
        }
    }
}

void Save()
{
    ofstream file("src/Player_profiles.txt"); // Open or create file

    for (int i = 0; i < total; i++)
    {
        file << data[i].name << " - " << data[i].age << " years " << "- $ " << data[i].balance << endl;
    }

    file.close();

    cout << "\n \t Player profiles saved successfully \n" << endl;
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
    if (total > 2)
    {
        total = 2; // avoid overflow
    }

    for (int i = 0; i < total; ++i)
    {
        file >> data[i].name >> data[i].age;
    }
    file.close();
}
