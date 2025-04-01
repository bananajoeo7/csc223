#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

// Template struct for a Node in the circular linked list
template <class T>
struct Node
{
    T cargo; // Stores the value of the node
    Node<T>* next; // Pointer to the next node in the circular list

    // Constructor to initialize a node with given cargo and next pointer
    Node(T cargo, Node<T>* next)
    {
        this->cargo = cargo;
        this->next = next;
    }
    #include <type_traits> // Needed for std::is_same

    // Converts the cargo into a string representation
    string stringy() const
    {
        if constexpr (std::is_same<T, int>::value) { // Checks if T is an int
            return std::to_string(cargo);
        } else {
            return string(cargo); // Assumes T is std::string or another string-convertible type
        }
    }
};
// Template class for a Circular Linked List
template <class T>
class CircularList
{
    int num_nodes; // Number of nodes in the list
    Node<T>* tail; // Pointer to the last node in the circular list

public:
    // Constructor initializes an empty circular list
    CircularList() : tail(nullptr), num_nodes(0) {}

    // Checks if the list is empty
    bool is_empty() const {
        return num_nodes == 0;
    }

    // Destructor to free memory when the list is destroyed
    ~CircularList() {
        while (!is_empty()) {
            remove_from_front();
        }
    }

    // Inserts a new node at the front of the circular list
    void insert_at_front(T cargo, Node<T>* next = nullptr)
    {
      // Creates a new node, linking it to the head of the list
      Node<T>* new_node = new Node<T>(cargo, tail ? tail->next : nullptr);
      if (tail == nullptr) { // Case when the list is empty
          tail = new_node;
          tail->next = tail; // Self-loop to maintain circularity
      } else {
          new_node->next = tail->next;
          tail->next = new_node;
      }
      num_nodes++;
    }

    // Removes the front node from the circular list and returns its cargo
    T remove_from_front()
    {
      if (tail == nullptr) { // Throws an error if the list is empty
          throw runtime_error("Can't remove from an empty list!");
      }

      Node<T>* front = tail->next; // The first node in the list
      T cargo = front->cargo;

      if (tail == front) { // Case when there is only one node in the list
          tail = nullptr;
      } else {
          tail->next = front->next; // Bypasses the removed node
      }

      delete front; // Free memory of the removed node
      num_nodes--;
      return cargo;
    }

    // Returns a string representation of the circular list
    string to_str() const
    {
        if (tail == nullptr) return ""; // Empty list case

        string result = "";
        Node<T>* node = tail->next; // Start from the head of the list
        do {
            result += node->stringy(); // Convert node data to string
            node = node->next;
            if (node != tail->next) result += ", "; // Format output
        } while (node != tail->next); // Stop when we loop back to the start

        return result;
    }
};