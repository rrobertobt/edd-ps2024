#include "Stack.h"

Stack::Stack() {
    top = nullptr;
    last = nullptr;
    size = 0;
}

Stack::~Stack() {
    while (top != nullptr) {
        Card* temp = top;
        top = top->next;
        delete temp;
    }
}

bool Stack::isEmpty() {
    return size == 0;
}

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

Card* Stack::peek() {
    return top;
}

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

Card* Stack::lastCard() {
    return last;
}

int Stack::getSize() {
    return size;
}
