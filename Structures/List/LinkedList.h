#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include "../Card/Card.h"

class DoublyLinkedList {
private:
    Card* head; // Pointer to the head of the list
    Card* tail; // Pointer to the tail of the list
    int size; // Size of the list
public:
    DoublyLinkedList(); // Constructor
    ~DoublyLinkedList(); // Destructor

    bool isEmpty(); // Function to check if the list is empty
    void insertFront(Card* card); // Function to insert a card at the front of the list
    void insertRear(Card* card); // Function to insert a card at the rear of the list
    void remove(Card* card); // Function to remove a card from the list
    void displayForward(); // Function to display the list in forward direction
    void displayBackward(); // Function to display the list in backward direction
    int getSize(); // Function to return the size of the list
};

#endif
