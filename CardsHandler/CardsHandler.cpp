#include "CardsHandler.h"


using namespace std;

void  CardsHandler::prepareGame() {
    randomizeCards();
    prepareStructures();
}

void CardsHandler::prepareStructures(){
    // Encolar las 24 primeras cartas
    for (int i = 0; i < 24; ++i) {
        firstQueue.enqueue(randomizedCards[i]);
    }

    // Encolar las 28 cartas restantes
    randomizedCards[24]->isHidden = false;
    randomizedCards[26]->isHidden = false;
    randomizedCards[29]->isHidden = false;
    randomizedCards[33]->isHidden = false;
    randomizedCards[38]->isHidden = false;
    randomizedCards[44]->isHidden = false;
    randomizedCards[51]->isHidden = false;

    int cardsToInsert[] = {1, 2, 3, 4, 5, 6, 7};
    int startingIndex[] = {24, 25, 27, 30, 34, 39, 45};

    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < cardsToInsert[i]; ++j) {
            lists[i].insertRear(randomizedCards[startingIndex[i] + j]);
        }
    }
}

CardsHandler::CardsHandler() {
    // Se generarán las cartas iniciales en el constructor`
    // corazones, diamantes, treboles, espadas
    string suits[] = {"<3", "<>", "E3", "!!"};
    string values[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    // Cada iteración representa un palo
    for (int s = 0; s < 4; s++) {
        // Cada iteracion es un valor
        for (int v = 0; v < 13; v++) {
            // Dar color
            string color = (s < 2) ? "R" : "N";
            // Crear la carta
            Card* newCard = new Card(color, suits[s], values[v] + suits[s] + color, v + 1, false);
            cards[s*13 + v] = newCard;
        }
    }
}

void CardsHandler::printCardsArray() {
    cout << "Generated card: " << endl;
    for (int i = 0; i < 52; i++) {
        cout << cards[i]->displayValue << endl;
    }


    cout << "Randomized cards: " << endl;
    for (int i = 0; i < 52; i++) {
        cout << randomizedCards[i]->displayValue << endl;
    }
}

void CardsHandler::showQueues() {
    cout << "First queue: " << endl;
    firstQueue.display();
    cout << "Second queue: " << endl;
    secondQueue.display();
}

void CardsHandler::randomizeCards() {
    randomizer->generateRandomNumbers();
    for (int i = 0; i < 52; i++) {
        randomizedCards[i] = new Card(
                cards[randomizer->randomNums[i]]->color,
                cards[randomizer->randomNums[i]]->symbol,
                cards[randomizer->randomNums[i]]->displayValue,
                cards[randomizer->randomNums[i]]->value,
                true
                );
    }

}

void CardsHandler::handleUserChoice() {
    int selected;

    do {
        cout << " -- Solitario -- " << endl;
        cout << "Selecciona una opción: " << endl;
        cout << "1. Ver carta de la primera cola" << endl;
        cout << "0. Salir" << endl;
        cout << "Opción >: ";

        cin >> selected;
        if (selected == 1) {
            seeCard();
            showMainGame();
        }
    }
    while ((selected > 0 && selected < 2));
}

void CardsHandler::seeCard() {
    if (firstQueue.isEmpty()) {
        cout << "La primera cola está vacía, deseas regresar las cartas desde la segunda cola?" << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        int selected;
        cin >> selected;
        if (selected == 1) {
            while (!secondQueue.isEmpty()) {
                firstQueue.enqueue(secondQueue.dequeue());
            }
            firstQueue.display();
            secondQueue.display();
        } else { return; }
    } else {


        cout << "[test]" << endl;
        firstQueue.peek()->isHidden = false;
        secondQueue.enqueue(firstQueue.dequeue());
        cout << "====================================" << endl;
        cout << "Carta de la primera cola: " << secondQueue.peekRear()->displayCard() << endl;
    }
}

void CardsHandler::showMainGame() {

    cout << "Columnas de cartas: " << endl;
    for (int i = 0; i < 7; i++) {
        cout << "Columna " << i + 1 << ": " << endl;
        lists[i].displayForward();
    }

    cout << "====================================" << endl;
    cout << "Disponibles:    Sacadas: " << endl;
    if (!firstQueue.isEmpty()) {

        cout << "*****";
    } else {cout << "-----";}
    if (!secondQueue.isEmpty()) {
        cout << "           " << secondQueue.peekRear()->displayCard() << endl;
    } else {cout << "           #####" << endl;}
    cout << "====================================" << endl;


}

CardsHandler::~CardsHandler() {
    for (int i = 0; i < 52; i++) {
        delete cards[i];
    }
}

