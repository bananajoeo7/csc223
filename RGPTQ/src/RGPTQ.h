#include <string>
#include "PriorityQueue.h"
using namespace std;
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

enum Color {RED, GREEN};

struct RGThing {
    Color color; 
    string label;

    string to_string() {
        return label;
    }
};

struct RGTpair {
    RGThing thing1;
    RGThing thing2;
};

class RGTPQ : public PriorityQueue<RGThing> {
    public:
        RGTPQ() = default;

        bool empty() {
            return PriorityQueue<RGThing>::LinkedList::length() == 0;
        }

        void insert(RGThing rgt) {
            
           
        }

        RGTpair remove() {
            
        }

        int size() {
            return PriorityQueue<RGThing>::LinkedList::length();
        }
};