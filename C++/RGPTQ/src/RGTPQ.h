#include <string>
using namespace std;
#include "Queue.h"

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

class RGTPQ {
    public:
        RGTPQ() = default;

        Queue<RGThing> RED_queue;
        Queue<RGThing> GREEN_queue;

        bool empty() {
            return (RED_queue.empty() == true && GREEN_queue.empty() == true);
        }

        void insert(RGThing rgt) {
            if (rgt.color == RED) {
                RED_queue.insert(rgt);
            } else if (rgt.color == GREEN) {
                GREEN_queue.insert(rgt);
            } else {
                throw underflow_error("Error: Invalid color for object.");
            }
           
        }

        RGTpair remove() {
            if (RED_queue.empty() == true && GREEN_queue.empty() == true) {
                throw underflow_error("Error: Cannot dequeue from empty queue.");
            } else if (RED_queue.empty() == true) {
                throw underflow_error("Error: No red items left in queue.");
            } else if (GREEN_queue.empty() == true){
                throw underflow_error("Error: No green items left in queue.");
            }


            RGTpair rgtp;
            rgtp.thing1 = RED_queue.remove();
            rgtp.thing2 = GREEN_queue.remove();

            return rgtp;
        }
};