# Priority Queue Implementations: Array and Linked List

## 1. Array Priority Queue

#### Key Aspects:
- **Fixed Size**: The queue uses a fixed-size array (`MAX_SIZE`), which limits the number of elements.
- **Circular Array**: The array wraps around when the end is reached, so it behaves as a circular buffer so the array, both optimizes and doesn't run out of space.

#### Code:
```cpp
template <class T>
class PriorityQueue {
    int first;
    int last;
    T items[MAX_SIZE];

public:
    PriorityQueue() : first(0), last(0) {}

    // Check if the queue is empty
    bool empty() const {
        return first == last;
    }

    // Insert item into the queue
    void insert(const T& value) {
        if ((last + 1) % MAX_SIZE == first) {
            throw std::overflow_error("No more space in queue");
        }

        int pos = last;
        while (pos != first && items[(pos - 1 + MAX_SIZE) % MAX_SIZE] < value) {
            items[pos] = items[(pos - 1 + MAX_SIZE) % MAX_SIZE];
            pos = (pos - 1 + MAX_SIZE) % MAX_SIZE;
        }

        items[pos] = value;
        last = (last + 1) % MAX_SIZE;
    }

    // Remove the item with the highest priority
    T remove() {
        if (empty()) {
            throw std::underflow_error("Can't remove from empty queue");
        }

        T removedValue = items[first];
        first = (first + 1) % MAX_SIZE;
        return removedValue;
    }
};
```

## 2. Link List Priority Queue

### Key Aspects:
- **Dynamic Size**: The queue can grow or shrink dynamically without a fixed size limit.
- **Linked List**: Each element in the queue is stored in a node that contains a value and a pointer to the next node. This allows for dynamic memory usage and efficient insertions and removals.

### Changes to LinkList.h
- Moved the Head from private to public and added a "gethead()" function

Here is my <b/>[LinkedList.h](https://github.com/bananajoeo7/csc223/blob/main/Priority_Queue/src/LinkedList.h)</b>.

### Code:
```cpp
#ifndef LINKEDLIST_PQUEUE_H
#define LINKEDLIST_PQUEUE_H

#include "LinkedList.h"

template <typename T>
class PriorityQueue : private LinkedList<T> {
public:
    using LinkedList<T>::length;

    // Check if the queue is empty
    bool empty() const {
        return this->length() == 0;
    }

    // Insert an item into the queue, maintaining the priority order
    void insert(T item) {
        Node<T>* newNode = new Node<T>(item, nullptr);  // Create a new node

        // If the queue is empty or the item has the highest priority
        if (this->getHead() == nullptr || item > this->getHead()->cargo) { 
            newNode->next = this->getHead();  // Insert at the front
            this->head = newNode;
        } else {
            // Find the appropriate position in the list to maintain priority order
            Node<T>* current = this->getHead();
            while (current->next != nullptr && current->next->cargo >= item) {
                current = current->next;
            }
            // Insert the new node in its correct position
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Remove the highest-priority item (i.e., the front item)
    T remove() {
        if (this->getHead() == nullptr) {
            throw std::underflow_error("Can't remove from empty queue");
        }
        return this->remove_from_front();  // Remove from the front of the list
    }
};

#endif  // LINKEDLIST_PQUEUE_H
'''