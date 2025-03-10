#ifndef QUEUE_H
#define QUEUE_H
#define MAX_SIZE 1024
#include <stdexcept>

template <class T>
class Queue {
    int first;
    int last;
    T items[MAX_SIZE];

public:
    Queue() {
        first = 0;
        last = 0;
    }

    void insert(const T& value) {
        if ((last + 1) % MAX_SIZE == first) {
            throw std::overflow_error("No more space in queue");
        }
        items[last] = value;
        last = (last + 1) % MAX_SIZE;
    }

    T remove() {
        if (empty()) {
            throw std::underflow_error("Can't remove from empty queue");
        }
        int oldfirst = first;
        first = (first + 1) % MAX_SIZE;
        return items[oldfirst];
    }

    bool empty() const {
        return first == last;
    }
};
#endif // QUEUE_H