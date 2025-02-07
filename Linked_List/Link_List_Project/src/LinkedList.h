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
class LinkedList
{
    int num_nodes;
    Node<T>* head;

public:
    LinkedList() {
        num_nodes = 0;
        head = nullptr;
    }

    void insert_at_front(T cargo) {
        Node<T>* front = new Node<T>(cargo, head);
        head = front;
        num_nodes++;
    }

    T remove_from_front() {
        if (head == nullptr)
            throw runtime_error("Can't remove from and empty list!");
        T cargo = head->cargo;
        Node<T>* front = head;
        head = head->next;
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