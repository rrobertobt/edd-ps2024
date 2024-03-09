//
// Created by Roberto Bautista on 08/03/2024.
//

#ifndef EDD_PS2024_CARD_H
#define EDD_PS2024_CARD_H
#include <string>
#include <utility>

using namespace std;
// Clase que representa una carta, basicamente un nodo como si fuera una lista doblemente enlazada
class Card {
public:
    Card(string color, string symbol, string displayValue, int value, bool isHidden);

    Card *next;
    Card *previous;

    // Atributos de la carta, serviran para identificarla y mostrarla
    string color;
    string symbol;
    string displayValue;

    // Valor de la carta, para saber su valor en el juego, por ejemplo, el 1 es el as, el 11 es el jack, etc
    bool isHidden;
    int value;

    // Funcion para mostrar la carta
    string displayCard();
};


#endif //EDD_PS2024_CARD_H
