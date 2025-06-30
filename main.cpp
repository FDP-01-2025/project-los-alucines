#include <iostream>
#include "output\logo/Functions.h"
#include <windows.h> //Esta libreria permite mostrar en consola los caracteres expandidos dentro del Unicode.

using namespace std;

// Archivo principal.

int main(void)
{

    int option;

    SetConsoleOutputCP(CP_UTF8);
    // Esto hace que la consola use UTF-8 para mostrar los caracteres utilizados en el diseño del logo.
    Logo();
    // Muestra el logo

    cout << R"(                                                           1. Play 
    )" << endl;

    cout << R"(                                                           2. Exit  


)"
         << endl;

    cin >> option;

    system("cls"); // Se utiliza para limpiar la pantalla de la consola y empezar en una nueva.
    switch (option)
    {
    case 1:

        add();
        Save();
        break;

    case 2:
        cout << "Adiós..." << endl;
        break;

    default:
        cout << "Opción no válida." << endl;
        break;
    }

    system("pause"); // Detiene consola antes de salir (solo en Windows)

    return 0;
}
