#include <iostream>
#include <windows.h> // Permite usar Unicode y funciones de Windows

#include "Player_profiles.h"
#include "Bingo.h"
#include "Menu.h"
#include "Dice.h"

using namespace std;

int main()
{
    int option;

    SetConsoleOutputCP(CP_UTF8); // Configura la consola para UTF-8
    Logo();                      // Muestra el logo

    option = ShowMenu();         // Muestra el menú y guarda la opción

    system("cls");               // Limpia la consola

    switch (option)
    {
    case 1:
    //     add();
    //     Save();
    //     system("cls");
    //     Welcome();
        BingoCards();
        RandomNumber();
        MarkNumber();
        Boards();

        break;

    case 2:
        runTheHouseofDice(); // Run "The House of Dice" game
        break;

    default:
        cout << "Opción no válida." << endl;
        break;
    }

    system("pause"); // Espera antes de cerrar la consola

    return 0;
}
