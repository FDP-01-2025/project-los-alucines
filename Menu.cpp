#include <iostream>
#include <windows.h> // NECESARIO para SetConsoleOutputCP
#include "Funciones.h"

using namespace std;

void Logo()
{

    cout << R"(

*************************************************************************************************************************************
                                                                                                                                                  
                                                                                                                                                                                                                                                                                 *                                                                                                                                       *
                                                                                                                                            
                            ███═╗ ╔═███═╗  ███═╗ ╔███═╗  ╔═███████═╗  ███████████═╗  ╔═███████═╗                                            
                            ███ ║ ║ ███ ║  ███ ║ ║███ ║  ███ ╔╝  ███═╗  ╚═███   ╔═╝  ███ ╔╝  ███═╗                                          
                            ███ ╚═╝ ███═╝  ███ ╚═╝███ ║  ███ ║   ███ ║    ███  ╔╝    ███ ║   ███ ║                                          
                            ████████══╝    █████████╔═╝  ███ ║   ███ ║    ███  ║     ███ ║   ███ ║                                         
                            ███   ╚═███═╗    ╚═███ ╔╝    ███ ║   ███ ║    ███  ║     ███ ║   ███ ║                                          
                            ███ ╔═╗ ███ ║      ███ ╣     ███ ╚═══███═╝    ███  ║     ███ ╚═══███═╝                                          
                            ███═╝ ╚═███═╝      ███═╝       ███████═╝      ███══╝       ███████═╝                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
    █████████═╗    ████████═╗    ██████████   ╔████████  ████████═╗   ████████═╗   ███   ╔═███  █████████═╗    ██████████   ╔████████       
    ███ ╔╝  ███═╗ ███   ╚═███═╗ ███ ╔══╗ ███  ███ ╔═══╝ ███ ╔═╗ ███  ███ ╔╝  ███═╗ ███   ║ ███  ███     ███═╗ ███ ╔══╗ ███  ███ ╔═══╝       
    ███ ║   ███ ║ ███═╗   ███ ║ ███ ║  ╚══╝   ███ ║     ███ ║ ╚═══╝  ███ ║   ███ ║ ███   ║ ███  ███     ███ ║ ███ ║  ╚══╝   ███ ║           
    ███████████═╝ ███████████ ║ ████████████  ██████═╗  ███ ║        ███ ║   ███ ║ ███   ║ ███  ███████████═╝ ████████████  ██████═╗        
    ███ ╚═███╚═╗  ███ ╚═╗ ███ ║    ╚══╗  ███  ███ ╔══╝  ███ ║        ███ ║   ███ ║ ███ ╔═╝ ███  ███ ╚═███╚═╗     ╚══╗  ███  ███ ╔══╝        
    ███    ███ ╚╗ ███   ║ ███ ║ ███ ╔═╝  ███  ███ ╚═══╗ ███ ║ ╔═███  ███ ╚═══███═╝ ███═╝   ███  ███    ███ ╚╗ ███ ╔═╝  ███  ███ ╚═══╗       
    ███     ███═╝ ███   ╚═███═╝  █████████═╝  ╚████████  ████████═╝   ████████═╝    ████████═╝  ███     ███═╝  █████████═╝  ╚████████       
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
                                                                                                                                            
      ¡Bienvenido, estás en el casino virtual de Kyoto Rasecourse, por favor sigue las indicaciones que se te presentan a continuación!     
                                                                                                                                                                                                                                                                                                                                                                                                  
)" << endl;
}

void MostrarMenu()
{

    int opcion;
    cout << R"(                                                           1. Jugar 
    )" << endl;

    cout << R"(                                                           2. Salir  




    
    ************************************************************************************************************************************)" << endl;

    cin >> opcion;
}
