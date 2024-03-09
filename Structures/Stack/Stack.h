#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "../Card/Card.h"

class Stack {
private:
    Card* top; // Pointer to the top of the stack
    Card* last; // Pointer to the last card of the stack
    int size; // Size of the stack
public:
    Stack(); // Constructor
    ~Stack(); // Destructor

    bool isEmpty(); // Function to check if the stack is empty
    void push(Card* card); // Function to push a card onto the stack
    Card* pop(); // Function to pop a card from the stack
    Card* peek(); // Function to return the top card of the stack without popping it
    void display(); // Function to display the cards in the stack
    Card* lastCard(); // Function to return the last card of the stack
    int getSize(); // Function to return the size of the stack
};

#endif
