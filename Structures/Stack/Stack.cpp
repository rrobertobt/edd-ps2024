#include "Stack.h"

// Constructor
Stack::Stack() {
    top = nullptr;
    last = nullptr;
    size = 0;
}

// Destructor
Stack::~Stack() {
    // Free memory for all cards in the stack
    while (top != nullptr) {
        Card* temp = top;
        top = top->next;
        delete temp;
    }
}

// Function to check if the stack is empty
bool Stack::isEmpty() {
    return size == 0;
}

// Function to push a card onto the stack
void Stack::push(Card* card) {
    card->next = top;
    card->previous = nullptr;
    if (top != nullptr) {
        top->previous = card;
    }
    top = card;
    if (last == nullptr) {
        last = card;
    }
    size++;
}

// Function to pop a card from the stack
Card* Stack::pop() {
    if (isEmpty()) {
        std::cout << "Stack is empty. Cannot pop." << std::endl;
        return nullptr;
    }
    Card* poppedCard = top;
    top = top->next;
    if (top != nullptr) {
        top->previous = nullptr;
    }
    poppedCard->next = nullptr;
    size--;
    if (isEmpty()) {
        last = nullptr;
    }
    return poppedCard;
}

// Function to return the top card of the stack without popping it
Card* Stack::peek() {
    return top;
}

// Function to display the cards in the stack
void Stack::display() {
    if (isEmpty()) {
        std::cout << "Stack is empty." << std::endl;
        return;
    }
    std::cout << "Stack cards:" << std::endl;
    Card* current = top;
    while (current != nullptr) {
        std::cout << "Color: " << current->color << ", Symbol: " << current->symbol << ", Value: " << current->value << std::endl;
        current = current->next;
    }
}

// Function to return the last card of the stack
Card* Stack::lastCard() {
    return last;
}

// Function to return the size of the stack
int Stack::getSize() {
    return size;
}
