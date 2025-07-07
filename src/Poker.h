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

using namespace std;

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


#endif