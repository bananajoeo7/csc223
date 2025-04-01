#include "LinkedList.h"

template <class T>
class Queue : public LinkedList<T>
{
  public:
    // constructors
    Queue() = default;

    // modifiers
    void insert(T item) {
        LinkedList<T>::insert_at_end(item);
    }

    T remove() {
        return LinkedList<T>::remove_from_front();
    }

    bool empty() {
        return (LinkedList<T>::length() == 0);
    }
};
