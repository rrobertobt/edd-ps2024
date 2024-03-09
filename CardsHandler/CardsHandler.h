//
// Created by Roberto Bautista on 08/03/2024.
//

#ifndef EDD_PS2024_CARDSHANDLER_H
#define EDD_PS2024_CARDSHANDLER_H


#include "../Structures/Card/Card.h"
#include "../Structures/Queue/Queue.h"
#include "../Structures/Stack/Stack.h"
#include "../Structures/List/LinkedList.h"
#include "../Randomizer/Randomizer.h"

// Esta clase maneja todo lo relacionado con las cartas del juego de solitario
// Aqui se manejan las colas, pilas y listas que se usan para el juego

class CardsHandler {
public:
    // Arreglo de cartas que se usan para el juego y se tomaran
    Card *cards[52];
    Card *randomizedCards[52];
    // Colas que se usan para las cartas sobrantes
    Queue firstQueue;
    Queue secondQueue;

    // 4 Pilas que se usan para las cartas que se van acomodando ya en orden (desde el as hasta el rey)
    Stack piles[4];

    // 7 Listas que se usan para acomodar las cartas en el tablero
    DoublyLinkedList lists[7];

    // Constructor de la clase
    CardsHandler();
    // Destructor de la clase
    ~CardsHandler();

    void printCardsArray();
    void randomizeCards();
    void prepareGame();
    void prepareStructures();
    void handleUserChoice();
    void showMainGame();
    void seeCard();


private:
    Randomizer *randomizer = new Randomizer();

    void showQueues();
};




#endif //EDD_PS2024_CARDSHANDLER_H
