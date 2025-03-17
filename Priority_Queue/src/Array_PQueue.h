#ifndef ARRAY_PQUEUE_H
#define ARRAY_PQUEUE_H

#include <stdexcept>

#define MAX_SIZE 10

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

    T remove() {
        if (empty()) {
            throw std::underflow_error("Can't remove from empty queue");
        }

        T removedValue = items[first];
        first = (first + 1) % MAX_SIZE;
        return removedValue;
    }
};

#endif // ARRAY_PQUEUE_H
