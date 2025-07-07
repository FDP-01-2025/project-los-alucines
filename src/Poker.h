#ifndef Poker_H 
#define Poker_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

// Estructura Carta
struct Carta
{
    int numero;
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

    string colorAnsi = (carta.color == "rojo") ? "\033[31m" : "\033[30m";
    string resetAnsi = "\033[0m";

    //diseño de las cartas
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

//array donde se guarda el mazo de 52 cartas que se exportan desde el archivo .txt
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























#endif