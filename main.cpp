#include <iostream>
#include "Funciones.h"
#include <windows.h> //Esta libreria permite mostrar en consola los caracteres expandidos dentro del Unicode.

using namespace std;

int main(void)
{

    int opcion;

    SetConsoleOutputCP(CP_UTF8);
    // Esto hace que la consola use UTF-8 para mostrar los caracteres utilizados en el diseño del logo.
    Logo();
    // Muestra el logo

    MostrarMenu();
    return 0;
}
