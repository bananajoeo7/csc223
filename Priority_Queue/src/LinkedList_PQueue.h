#ifndef LINKEDLIST_PQUEUE_H
#define LINKEDLIST_PQUEUE_H

#include "LinkedList.h"

template <typename T>
class PriorityQueue : private LinkedList<T> {
public:
    using LinkedList<T>::length;

    bool empty() const {
        return this->length() == 0;
    }

    void insert(T item) {
        Node<T>* newNode = new Node<T>(item, nullptr);

        if (this->getHead() == nullptr || item > this->getHead()->cargo) { 
            newNode->next = this->getHead();
            this->head = newNode;
        } else {
            Node<T>* current = this->getHead();
            while (current->next != nullptr && current->next->cargo >= item) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    T remove() {
        if (this->getHead() == nullptr) {
            throw std::underflow_error("Can't remove from empty queue");
        }
        return this->remove_from_front();
    }
};

#endif