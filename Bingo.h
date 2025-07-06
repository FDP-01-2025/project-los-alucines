
#ifndef BINGO_H
#define BINGO_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h>
#include <string>
#include <cstdlib> // para rand() y srand()
#include <ctime>   // para time()
#include <random>  // para generador moderno (más recomendado)

using namespace std;
const int rows = 5;
const int cols = 5;
int board1[rows][cols];
int board2[rows][cols];

struct Player
{
    int balance;
    string name;
    int age;
    float bet;
};

void RunningBingo()
{
    Player data[2];
    ifstream file("Player_profiles.txt");
    char a = '|';

    if (!file.is_open())
    {
        cout << "ERROR: No se pudo abrir el archivo." << endl;
        return;
    }

    string line;
    getline(file, line); // Salta la primera línea

    int i = 0;
    while (getline(file, line) && i < 2)
    {
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
    file.close();

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
            cout << "\t\t\t\t\t\t  ¿Cuánto deseas apostar? " << endl;
            cout << "\t\t\t\t\t\t  $";
            cin >> data[k].bet;

            cout << "\t\t\t\t\t\t Guardando información..." << endl;
            Sleep(2000);
            cout << "\t\t\t\t\t\t══════════════════════════════" << endl;

            if (data[k].bet < 75)
            {
                cout << "\n\t\t\t\t\t\tDebes apostar al menos $75.\n";
            }
            else if (data[k].bet > data[k].balance)
            {
                cout << "\n\t\t\t\t\t\tNo tienes suficiente saldo para apostar esa cantidad.\n";
            }
            else
            {
                valid = true;
                cout << "\t\t\t\t\t\tApuesta registrada con éxito.\n";

                ofstream outFile("Bets.txt", ios::app);
                outFile << "Jugador: " << data[k].name << ", Edad: " << data[k].age << ", Apuesta: $" << data[k].bet << endl;
                outFile.close();
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
}

void BingoCards()
{

    srand(time(0)); // Inicializar aleatorio

    // Llenar ambas tarjetas
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            board1[i][j] = rand() % 99 + 1;
            board2[i][j] = rand() % 99 + 1;
        }
    }

    cout << "\n\t\tPLAYER 1\t\t\t\t\t\t\tPLAYER 2\n";
    cout << endl;
    cout << "  ------------------------------------\t\t\t\t--------------------------------------\n";
    cout << endl;

    for (int i = 0; i < rows; i++)
    {
        // Tarjeta 1
        for (int j = 0; j < cols; j++)
        {
            if (board1[i][j] < 10)
                cout << " [ 0" << board1[i][j] << " ] ";
            else
                cout << " [ " << board1[i][j] << " ] ";
        }

        cout << "\t\t\t"; // espacio entre las dos tarjetas

        // Tarjeta 2
        for (int j = 0; j < cols; j++)
        {
            if (board2[i][j] < 10)
                cout << " [ 0" << board2[i][j] << " ] ";
            else
                cout << " [ " << board2[i][j] << " ] ";
        }

        cout << endl
             << endl; // salto de línea entre filas
    }
    cout << "  ------------------------------------\t\t\t\t--------------------------------------\n";

    cout << "\n\n\n\n";
}

void RandomNumber()
{
    int number;
    number = rand() % 99 + 1;
    cout << "\nRandom Number: " << number << endl;
}

void MarkNumber()
{

    int number;
    // Reemplaza el número con un marcador especial (-1) cuando sea encontrado en cualquiera de las cartas
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (board1[i][j] == number)
                board1[i][j] = 'x'; // Marcamos con -1 (podrías usar otro marcador como "X")

            if (board2[i][j] == number)
                board2[i][j] = 'x'; // Marcamos con -1 (podrías usar otro marcador como "X")
        }
    }
}

void Boards()
{
    cout << "\n\t\tPLAYER 1\t\t\t\t\t\t\tPLAYER 2\n";
    cout << endl;
    cout << "  ------------------------------------\t\t\t\t--------------------------------------\n";
    cout << endl;

    for (int i = 0; i < rows; i++)
    {

        for (int j = 0; j < cols; j++)
        {
            if (board1[i][j] == 'x')
                cout << " [ XX ] "; // Marcado con "X"
            else if (board1[i][j] < 10)
                cout << " [ 0" << board1[i][j] << " ] "; // Espaciado si el número es de un solo dígito
            else
                cout << " [ " << board1[i][j] << " ] "; // Para números de dos dígitos
        }

        cout << "\t\t\t"; // espacio entre las dos tarjetas

        // Tarjeta 2
        for (int j = 0; j < cols; j++)
        {
            if (board2[i][j] == 'x')
                cout << " [ XX ] "; // Marcado con "X"
            else if (board2[i][j] < 10)
                cout << " [ 0" << board2[i][j] << " ] "; // Espaciado si el número es de un solo dígito
            else
                cout << " [ " << board2[i][j] << " ] "; // Para números de dos dígitos
        }

        cout << endl
             << endl; // salto de línea entre filas
    }

    cout << "  ------------------------------------\t\t\t\t--------------------------------------\n";
}

#endif
