#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h>
#include <string>
#include "Bingo.h"
// #include "output\Logo/Functions.h"

using namespace std;

void RunningBingo()
{
    Player data[2];
    ifstream file("Player_profiles.txt");
    char a = '|';

    if (!file.is_open())
    {
        cout << " ERROR: No se pudo abrir el archivo." << endl;
        return;
    }

    string line;
    getline(file, line);

    int i = 0;
    while (getline(file, line) && i < 2)
    {
        // Ejemplo de línea: Astrid - 74 years - $ 458

        stringstream ss(line);
        string name, delete1, delete2, years, dollarSign;
        int age;
        float balance;

        ss >> name >> delete1 >> age >> years >> delete2 >> dollarSign >> balance;

        data[i].name = name;
        data[i].age = age;
        data[i].balance = balance;
        i++;
    }
    cout << endl;

#include <iostream>
    using namespace std;

    cout << R"(                 
                                             ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
                                             ▓▓                                      ▓▓
                                             ▓▓   ▓▓      ▓▓   ▓▓      ▓▓    ▓▓▓▓    ▓▓
                                             ▓▓     ▓▓    ▓▓   ▓▓      ▓▓       ▓▓   ▓▓
                                             ▓▓   ▓▓▓▓   ▓▓   ▓▓▓▓▓▓  ▓▓   ▓▓▓▓▓▓    ▓▓
                                             ▓▓                                      ▓▓
                                             ▓▓          W E L C O M E   T O         ▓▓
                                             ▓▓               B I N G O              ▓▓
                                             ▓▓                                      ▓▓
                                             ▓▓  ▓▓▓▓▓   ▓▓▓▓   ▓▓  ▓▓   ▓▓▓▓▓▓▓▓▓▓  ▓▓
                                             ▓▓    ▓▓     ▓▓   ▓▓▓▓▓▓     ▓▓         ▓▓
                                             ▓▓  ▓▓▓▓    ▓▓   ▓▓  ▓▓     ▓▓▓▓▓▓      ▓▓
                                             ▓▓                                      ▓▓
                                             ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓


                                                       **Bingo Game Rules:**

                                           
                                         1- Minimum bet: $75 to participate in the game.

                                         2- Bingo cards are automatically assigned to 
                                            players before the game starts.

                                         3- The game is automated: numbers are drawn 
                                            randomly by the system and displayed on the 
                                            screen.

                                         4- To win, a player must complete a valid pattern
                                            on their card. The system will automatically 
                                            detect and announce the winner.

                                          5- Players are expected to follow the rules and act 
                                            responsibly at all times.



)" << endl;

    Sleep(9000);

    system("cls");

    cout << R"(                 
                                             ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓
                                             ▓▓                                      ▓▓
                                             ▓▓   ▓▓      ▓▓   ▓▓      ▓▓    ▓▓▓▓    ▓▓
                                             ▓▓     ▓▓    ▓▓   ▓▓      ▓▓       ▓▓   ▓▓
                                             ▓▓   ▓▓▓▓   ▓▓   ▓▓▓▓▓▓  ▓▓   ▓▓▓▓▓▓    ▓▓
                                             ▓▓                                      ▓▓
                                             ▓▓          W E L C O M E   T O         ▓▓
                                             ▓▓               B I N G O              ▓▓
                                             ▓▓                                      ▓▓
                                             ▓▓  ▓▓▓▓▓   ▓▓▓▓   ▓▓  ▓▓   ▓▓▓▓▓▓▓▓▓▓  ▓▓
                                             ▓▓    ▓▓     ▓▓   ▓▓▓▓▓▓     ▓▓         ▓▓
                                             ▓▓  ▓▓▓▓    ▓▓   ▓▓  ▓▓     ▓▓▓▓▓▓      ▓▓
                                             ▓▓                                      ▓▓
                                             ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓

)" << endl;

    for (int k = 0; k < i; k++)
    {

        bool valid = false;
        while (!valid)
        {
            cout << endl;
            cout << "\t\t\t\t\t\t══════════════════════════════" << endl;
            cout << "\t\t\t\t\t\t" << " Welcome: " << data[k].name << endl;
            cout << "\t\t\t\t\t\t  Cuanto deseas apostar? " << endl;
            cout << "\t\t\t\t\t\t  $";
            cin >> data[k].bet;
            cout << "\t\t\t\t\t\t Guardando información..." << endl;
            cout << endl;
            cout << "\t\t\t\t\t\t══════════════════════════════" << endl;
            Sleep(2000);

            if (data[k].bet <= 75)
            {

                cout << "Debes de apostar mas de $75" << endl;
            }

            else if (data[k].bet > data[k].balance)
            {
                cout << "\n\t\t\t\t\t\tNo posees suficiente dinero para apostar esa cantidad.\n";
            }

            else
            {

                valid = true;

                cout << "\t\t\t\t\t\tSaved" << endl;

                if (valid = true)
                {

                    ofstream file("Player_profiles.txt");

                    file << "Dinero apostado: " << data[k].bet << endl;
                }
            }
        }
    }

    system("cls");
    for (int j = 0; j < i; j++)
    {
        cout << "╔═══════════════════════════════╗" << endl;
        cout << a << "\tPlayer: " << j + 1 << "\t\t" << a << "\n";
        cout << a << "\tName: " << data[j].name << "\t\t" << a << endl;
        cout << a << "\t$ Bet: " << data[j].bet << "\t\t" << a << endl;
        cout << "╚═══════════════════════════════╝" << endl;
        cout << endl;
    }

    file.close();
}

int main()
{
    system("cls");
    SetConsoleOutputCP(CP_UTF8);
    RunningBingo();

    return 0;
}