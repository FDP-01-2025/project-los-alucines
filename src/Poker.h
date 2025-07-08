//CAMBIAR COMENTARIOS A INGLES

#ifndef Poker_H 
#define Poker_H 
//Estos dos son directivas para evitar incluir el archivo .h mas de una vez

#include <iostream>
#include <iomanip> 
//Se utiliza para controlar como se muestran los datos en pantalla, Se utilizara para alinear los numeros de las cartas
#include <string> 
//Para utilizar datos tipo string
#include <fstream> 
//para uso de archivos
#include <cstdlib>  
// Para rand() y srand() que sera el random para barajear y repartir cartas
#include <ctime>    
// Inicializa el random con un valor diferente cada vez
#include <sstream> 
//Se utilizara para convertir dato tipo string en int
#include <windows.h> 
//Para funciones especificas de windows, dormir el sistema Sleep() para limpiar pantalla system("cls")


using namespace std;


// Estructura del jugador
struct Player 
{
    string name;
    int age;
    float balance;
    float bet;
};

// Arreglo para guardar hasta 2 jugadores
Player players[2];

void IniciarPokerBet() 
{
    ifstream file("Player_profiles.txt");
    if (!file.is_open()) 
    {
        cout << "ERROR: No se pudo abrir el archivo de jugadores." << endl;
        return;
    }

    string line;
    int i = 0;
    while (getline(file, line) && i < 2) 
    {
        stringstream ss(line);
        string name, skip1, skip2, word1, symbol;
        int age;
        float balance;

        ss >> name >> skip1 >> age >> word1 >> skip2 >> symbol >> balance;
        players[i].name = name;
        players[i].age = age;
        players[i].balance = balance;
        i++;
    }
    file.close();
    system("cls");

    for (int k = 0; k < i; k++) 
    {
        bool valid = false;
        while (!valid) {
            cout << R"(
        
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

            cout << "\n\t\t\t Welcome, " << players[k].name << "!" << endl;
            cout << "\t\t\t Enter your bet amount: $";
            cin >> players[k].bet;

            cout << "\n\t\t\t Processing your bet...\n";
            Sleep(2000);

            if (players[k].bet < 100) 
            {
                cout << "\n\t\t\t Minimum bet is $100. Try again.\n";
                Sleep(2000);
                system("cls");
            } else if (players[k].bet > players[k].balance) 
            {
                cout << "\n\t\t\t Insufficient balance for that bet.\n";
                Sleep(2000);
                system("cls");
            } else 
            {
                valid = true;
                cout << "\n\t\t\t Bet of $" << players[k].bet << " registered successfully!\n";
                Sleep(2000);
                system("cls");
            }
        }
    }

    cout << R"(
       LET THE CARDS FALL WHERE THEY MAY...
    )" << endl;
}


// Estructura Carta
struct Carta
{
    string numero;
    string palo;
    string color;
};


// Función que imprime una línea específica de una carta
void imprimirCartaLinea(const Carta &carta, int linea)
{
    string paloSimbolo;
    if (carta.palo == "corazones")
        paloSimbolo = "♥";
    else if (carta.palo == "diamantes")
        paloSimbolo = "♦";
    else if (carta.palo == "treboles")
        paloSimbolo = "♣";
    else if (carta.palo == "picas")
        paloSimbolo = "♠";
    else
        paloSimbolo = "?";

    string colorAnsi = (carta.color == "rosado") ? "\033[31m" : "\033[30m"; //cambio de color a las cartas
    string resetAnsi = "\033[0m";

    //Diseño de las cartas
    switch (linea)
    {
    case 0:
        cout << colorAnsi << "+---------+" << resetAnsi;
        break;
    case 1:
        cout << colorAnsi << "| " << setw(2) << left << carta.numero << "      |" << resetAnsi;
        break;
    case 2:
        cout << colorAnsi << "|         |" << resetAnsi;
        break;
    case 3:
        cout << colorAnsi << "|   " << paloSimbolo << "     |" << resetAnsi;
        break;
    case 4:
        cout << colorAnsi << "|         |" << resetAnsi;
        break;
    case 5:
        cout << colorAnsi << "|      " << setw(2) << right << carta.numero << " |" << resetAnsi;
        break;
    case 6:
        cout << colorAnsi << "+---------+" << resetAnsi;
        break;
    }
}

//Array donde se guarda el mazo de 52 cartas que se exportan desde el archivo .txt
Carta mazo[52];
string formatearCarta(const Carta &carta);

void LeerArchivos()
{
    ifstream cartas("Cartas.txt");
    if (cartas.is_open())
    {
        for (int i = 0; i < 52; i++)
        {
            cartas >> mazo[i].numero >> mazo[i].palo >> mazo[i].color;
        }
    }
    cartas.close();

    for (int i = 0; i < 52; i++)
    {
        cout << mazo[i].numero << " - " << mazo[i].palo << " - "<< mazo[i].color << endl;
    }
}

// Función que imprime las cartas horizontalmente
void imprimirManoHorizontal(const Carta mano[], int numCartas)
{
    const int NUM_LIN = 7; // Cada carta tiene 7 líneas

    for (int linea = 0; linea < NUM_LIN; ++linea)
    {
        for (int i = 0; i < numCartas; ++i)
        {
            imprimirCartaLinea(mano[i], linea);
            cout << "  "; // Espacio entre cartas
        }
        cout << endl;
    }
}


// Declaración de las manos por cada jugador
Carta manoJugador1[5];
Carta manoJugador2[5];

// Arreglo auxiliar para marcar qué cartas del mazo ya han sido repartidas
bool cartaUsada[52] = {false};

// Función que reparte 5 cartas aleatorias a cada jugador sin repetir
void repartirCartas()
{
    srand(time(0)); // Inicializa la semilla para números aleatorios (una sola vez)

    int cartasRepartidas = 0;

    // Repartir 5 cartas al jugador 1
    for (int i = 0; i < 5; i++)
    {
        int indice;
        do
        {
            indice = rand() % 52; // Genera un número aleatorio entre 0 y 51
        } while (cartaUsada[indice]); // Repite mientras la carta ya haya sido usada

        manoJugador1[i] = mazo[indice]; // Asigna la carta al jugador
        cartaUsada[indice] = true;      // Marca la carta como usada
        cartasRepartidas++;
    }

    // Repartir 5 cartas al jugador 2
    for (int i = 0; i < 5; i++)
    {
        int indice;
        do
        {
            indice = rand() % 52;
        } while (cartaUsada[indice]);

        manoJugador2[i] = mazo[indice];
        cartaUsada[indice] = true;
        cartasRepartidas++;
    }
}

//Funcion para cambiar un maximo de 2 cartas por jugador
void cambiarCartas(Carta mano[], const string& nombreJugador)
{
    for (int intento = 0; intento < 2; intento++) // Dos oportunidades de cambiar carta
    {
        imprimirManoHorizontal(mano, 5);
        cout << nombreJugador << ", ¿quieres cambiar una carta? (s/n): ";
        char respuesta;
        cin >> respuesta;

        if (respuesta == 's' || respuesta == 'S')
        {
            int indice;
            do {
                cout << "¿Cuál carta quieres cambiar? (1-5): ";
                cin >> indice;
            } while (indice < 1 || indice > 5);

            // Buscar una carta nueva no usada en el mazo
            int nuevaCartaIndex;
            do {
                nuevaCartaIndex = rand() % 52;
            } while (cartaUsada[nuevaCartaIndex]);

            // Reemplazar la carta en la mano
            mano[indice - 1] = mazo[nuevaCartaIndex];
            cartaUsada[nuevaCartaIndex] = true;

            cout << "Carta cambiada exitosamente.\n\n";
        }
        else
        {
            cout << "No se cambió ninguna carta en este intento.\n\n";
        }
    }
}

#endif