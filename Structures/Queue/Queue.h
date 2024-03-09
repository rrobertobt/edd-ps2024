#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "../Card/Card.h"

class Queue {
private:
    Card* front;
    Card* rear;
    int size;
public:
    Queue();
    ~Queue();

    bool isEmpty();
    void enqueue(Card* card);
    Card* dequeue();
    Card* peek();
    void display();
    int getSize();
    Card *peekRear();
};

#endif
