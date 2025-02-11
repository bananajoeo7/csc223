#include <string>
using namespace std;

template <class T>
struct Node
{
    T cargo;
    Node<T>* next;

    Node(T cargo, Node<T>* next)
    {
        this->cargo = cargo;
        this->next = next;
    }

    string to_string() const
    {
        return string(cargo);
    }
};


template <class T>
class CircularList
{
    int num_nodes;
    Node<T>* tail; // establishes the last node in the list so when edited the program won't enter an infinite loop

public:
    -CircularList() {
        while (!is_empty()) {
            remove_from_front();
        }
    }

    void insert_at_front(T cargo) 
    {
      Node<T>* new_node = new Node<T>(cargo);
      if (tail == nullptr) {
          tail = new_node;
          tail->next = tail; // Circular link
      } else {
          new_node->next = tail->next;
          tail->next = new_node;
      }
      num_nodes++;
    }

    T remove_from_front() 
    {
      if (tail == nullptr) { //checks if the tail is null, if so, it throws an error
          throw runtime_error("Can't remove from an empty list!");
      }

      Node<T>* front = tail->next;
      T cargo = front->cargo;

      if (tail == front) { // edge case if there is only one node in the list
          tail = nullptr;
      } else {
          tail->next = front->next;
      }

      delete front;
      num_nodes--;
      return cargo;
    }

    string to_string() const
    {
        Node<T>* node = head;
        string s = "";
        while (node != nullptr) {
            s += node->to_string();
            node = node->next;
            if (node != nullptr)
                s += ", ";
        }
        return s;
    }
};