#include "Queue.h"

Queue::Queue() {
    front = nullptr;
    rear = nullptr;
    size = 0;
}

Queue::~Queue() {
    while (front != nullptr) {
        Card* temp = front;
        front = front->next;
        delete temp;
    }
    rear = nullptr;
}

bool Queue::isEmpty() {
    return size == 0;
}

void Queue::enqueue(Card* cardToQueue) {
    Card* card = new Card(cardToQueue->color, cardToQueue->symbol, cardToQueue->displayValue, cardToQueue->value, cardToQueue->isHidden);
    if (isEmpty()) {
        front = card;
        rear = card;
    } else {
        rear->next = card;
        rear = card;
        rear->next = nullptr;
    }
    size++;
}

Card* Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "Cola esta vacia" << std::endl;
        return nullptr;
    }
    Card* dequeuedCard = front;
    front = front->next;
    dequeuedCard->next = nullptr;
    size--;
    if (isEmpty()) {
        rear = nullptr;
    }
    return dequeuedCard;
}

Card* Queue::peek() {
    return front;
}

Card* Queue::peekRear() {
    return rear;
}

void Queue::display() {
    if (isEmpty()) {
        std::cout << "Cola esta vacia" << std::endl;
        return;
    }
    std::cout << "Cartas en cola" << std::endl;
    Card* current = front;
    while (current != nullptr) {
        std::cout << current->displayCard() << std::endl;
        current = current->next;
    }
}

int Queue::getSize() {
    return size;
}
