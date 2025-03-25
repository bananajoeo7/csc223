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

        Queue<RGThing> RED_queue;
        Queue<RGThing> GREEN_queue;

        bool empty() {
            return PriorityQueue<RGThing>::LinkedList::length() == 0;
        }

        void insert(RGThing rgt) {
            if (rgt.color == RED) {
                RED_queue.insert(rgt);
            } else if (rgt.color == GREEN) {
                GREEN_queue.insert(rgt);
            } else {
                throw error("Error: Invalid color for object.");
            }
           
        }

        RGTpair remove() {
            if (RED_queue.empty == true && GREEN_queue.empty == true) {
                throw underflow_error("Error: Cannot dequeue from empty queue.");
            } else if (RED_queue.empty == true) {
                throw underflow_error("Error: No red items left in queue.");
            } else if (GREEN_queue.empty == true){
                throw underflow_error("Error: No green items left in queue.");
            }

        }

        int size() {
            return PriorityQueue<RGThing>::LinkedList::length();
        }
};