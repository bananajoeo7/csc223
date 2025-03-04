#pragma once
#include "LinkedList.h"

template <class T>
class Stack : public LinkedList<T> {
    public:
        void push(T item) {
            LinkedList<T>::addFirst(item);
        }
        T pop() {
            return LinkedList<T>::removeFront();
        }
        bool empty() const {
            return LinkedList<T>::empty();
        }
        T top() {
            if (LinkedList<T>::empty())
                throw runtime_error("Cannot return top item of empy stack.");
            return LinkedList<T>::getHead()->getCargo();
        }
        // "Topples" the stack (removes all of its elements)
        void topple() {
            while (!LinkedList<T>::empty()) {
                pop();
            }
            LinkedList<T>::numNodes = 0;
        }
        // Returns the number of elements in the stack
        int height() {
            return LinkedList<T>::size();
        }
};