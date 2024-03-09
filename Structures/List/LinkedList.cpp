#include "LinkedList.h"

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

DoublyLinkedList::~DoublyLinkedList() {
    while (head != nullptr) {
        Card* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

bool DoublyLinkedList::isEmpty() {
    return size == 0;
}

void DoublyLinkedList::insertFront(Card* card) {
    if (isEmpty()) {
        head = card;
        tail = card;
    } else {
        card->next = head;
        head->previous = card;
        head = card;
    }
    size++;
}

void DoublyLinkedList::insertRear(Card* card) {
    if (isEmpty()) {
        head = card;
        tail = card;
    } else {
        tail->next = card;
        card->previous = tail;
        tail = card;
    }
    size++;
}

void DoublyLinkedList::remove(Card* card) {
    if (isEmpty()) {
        std::cout << "Lista vacia" << std::endl;
        return;
    }
    if (card == head) {
        head = head->next;
        if (head != nullptr) {
            head->previous = nullptr;
        } else {
            tail = nullptr;
        }
    } else if (card == tail) {
        tail = tail->previous;
        tail->next = nullptr;
    } else {
        card->previous->next = card->next;
        card->next->previous = card->previous;
    }
    delete card;
    size--;
}

void DoublyLinkedList::displayForward() {
    if (isEmpty()) {
        std::cout << "List vacia" << std::endl;
        return;
    }
//    std::cout << "List cards (forward):" << std::endl;
    Card* current = head;
    while (current != nullptr) {
//        std::cout << "Color: " << current->color << ", Symbol: " << current->symbol << ", Value: " << current->value << std::endl;
        std::cout << current->displayCard() << std::endl;
        current = current->next;
    }
}

void DoublyLinkedList::displayBackward() {
    if (isEmpty()) {
        std::cout << "Lista vacia" << std::endl;
        return;
    }
    Card* current = tail;
    while (current != nullptr) {
//        std::cout << "Color: " << current->color << ", Symbol: " << current->symbol << ", Value: " << current->value << std::endl;
        std::cout << current->displayValue << to_string(current->isHidden) << std::endl;
        current = current->previous;
    }
}

int DoublyLinkedList::getSize() {
    return size;
}
