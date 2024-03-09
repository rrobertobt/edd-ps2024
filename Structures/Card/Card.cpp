//
// Created by Roberto Bautista on 08/03/2024.
//

#include <iostream>
#include "Card.h"

using namespace std;

// Constructor de la carta
Card::Card(string color, string symbol, string displayValue, int value, bool isHidden) :
        color(std::move(color)),
        symbol(std::move(symbol)),
        displayValue(std::move(displayValue)),
        value(value),
        isHidden(isHidden),
        next(nullptr),
        previous(nullptr) {}

// Funcion para mostrar la carta
string Card::displayCard() {
    // Si la carta esta oculta, se mostrara como oculta
    if (isHidden) {
        return "****";
    } else {
        return displayValue;
    }
}
