#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H
#include <string>
#include <iostream>
using namespace std;

template <class T>
class Node { // A basic node for a linked list
    private:
        Node<T>* next;
    protected:
        T cargo;

    public:
        Node() {}
        Node(T cargo) {
            this->cargo = cargo;
            this->next = nullptr;
        }
        // Creates a new node
        // @param cargo: the data held by the new node
        // @param nextNode: the address of the next node
        Node(T cargo, Node<T>* nextNode) {
            this->cargo = cargo;
            this->next = nextNode;
        }
        T getCargo() {
            return cargo;
        }
        Node<T>* getNext() {
            return next;
        }
        void setNext(Node<T>* n) {
            this->next = n;
        }
        string to_string() const {
            return std::to_string(cargo);
        }
};

template <class T>
class DoubleNode : public Node<T> {
    DoubleNode<T>* previous;
    DoubleNode<T>* next;

    public:
        DoubleNode(T cargo) {
            this->cargo = cargo;
            this->next = nullptr;
            this->previous = nullptr;
        }
        DoubleNode(T cargo, DoubleNode<T>* nextNode) {
            this->cargo = cargo;
            this->next = nextNode;
            this->previous = nullptr;
        }
        DoubleNode(T cargo, DoubleNode<T>* nextNode, DoubleNode<T>* prevNode) {
            this->cargo = cargo;
            this->next = nextNode;
            this->previous = prevNode;
        }
        string to_string() {
            return std::to_string(this->cargo);
        }
        DoubleNode<T>* getPrev() {
            return this->previous;
        }
        DoubleNode<T>* getNext() {
            return this->next;
        }
        void setPrev(DoubleNode<T>* dNode) {
            this->previous = dNode;
        }
};

template <class T>
class LinkedList { // Singly-linked list
    private:
        Node<T>* head; // The front of the list
    protected:
        int numNodes; // Number of nodes in the list
    public:
        bool empty() const {
            return (this->head == nullptr);
        }
        Node<T>* getHead() {
            return this->head;
        }
        // Default constructor
        LinkedList() {
            this->head = nullptr;
            this->numNodes = 0;
        }
        // Returns the number of nodes in the list
        int size() const {
            return this->numNodes;
        }
        // Adds a node to the beginning of the list
        // @param cargo: the data held by the new starting node
        void addFirst(T cargo) {
            Node<T>* n = new Node<T>(cargo, head);
            this->head = n;
            this->numNodes++;
        }
        // Removes the item at the front of the list and returns the data it contains
        T removeFront() {
            if (this->head == nullptr) {
                throw runtime_error("Error: cannot remove from an empty list.");
            }
            T frontCargo = head->getCargo();
            Node<T>* front = head;
            head = head->getNext();
            delete front;
            numNodes--;
            return frontCargo;
        }
        string to_string() const {
            if (head == nullptr) {
                return "Empty list";
            }
            Node<T>* node = head;
            string s = "(";

            while (node != nullptr) {
                s += node->to_string();
                node = node->getNext();
                if (node != nullptr)
                    s += ", ";
            }
            s += ")";
            return s;
        }
        string to_string_reverse() const {
            if (head == nullptr) {
                string s = "Empty list";
                return s;
            }
            Node<T>* node = head;
            string s = ")";

            while (node != nullptr) {
                s = node->to_string() + s;
                node = node->getNext();
                if (node != nullptr)
                    s = ", " + s;
            }
            s = "(" + s;
            return s;
        }
};

template <class T>
class DoubleLinkedList: public LinkedList<T> {
    private:
        DoubleNode<T>* head;
    public:
        DoubleLinkedList() {
            this->head = nullptr;
            this->numNodes = 0;
        }
        DoubleNode<T>* getHead() {
            return this->head;
        }
        void addFirst(T newCargo) {
            DoubleNode<T>* newNode = new DoubleNode<T>(newCargo, this->head);
            this->head = newNode;
            if (this->head->getNext() != nullptr)
                this->head->getNext()->setPrev(newNode);
            this->numNodes++;
        }
        T removeFront() {
            if (this->head == nullptr) {
                throw runtime_error("Error: cannot remove from an empty list.");
            }
            T frontCargo = head->getCargo();
            DoubleNode<T>* front = this->head;
            this->head = this->head->getNext();
            delete front;
            this->numNodes--;
            return frontCargo;
        }
        string to_string() const {
            if (head == nullptr) {
                return "Empty list";
            }
            DoubleNode<T>* node = head;
            string s = "(";

            while (node != nullptr) {
                s += node->to_string();
                node = node->getNext();
                if (node != nullptr)
                    s += ", ";
            }
            s += ")";
            return s;
        }
        string to_string_reverse() const {
            if (head == nullptr) {
                string s = "Empty list";
                return s;
            }
            DoubleNode<T>* node = head;
            string s = ")";

            while (node != nullptr) {
                s = node->to_string() + s;
                node = node->getNext();
                if (node != nullptr)
                    s = ", " + s;
            }
            s = "(" + s;
            return s;
        }
};

template <class T>
class CircleLinkedList: public LinkedList<T> {
    private:
        Node<T>* head; // The first node of the circle
        Node<T>* tail; // The last node of the circle
    public:
        Node<T>* getTail() {
            return this->tail;
        }
        CircleLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
            this->numNodes = 0;
        }
        void addNode(T cargo) {
            Node<T>* n = new Node<T>(cargo, n);
            n->setNext(head);
            if (head == nullptr) { // If the list is empty, n just points to itself
                this->tail = n;
                this->head = n;
                head->setNext(tail);
            } else {
                tail->setNext(n);
                tail = n;
            }
        }
        string to_string() const {
            if (head == nullptr) {
                return "Empty list";
            }
            Node<T>* node = head;
            string s = "(";

            while (node != this->tail) {
                s += node->to_string();
                node = node->getNext();
                if (node != this->tail)
                    s += ", ";
            }
            s += ")";
            return s;
        }
        string to_string_reverse() const {
            if (head == nullptr) {
                string s = "Empty list";
                return s;
            }
            DoubleNode<T>* node = head;
            string s = ")";

            while (node != this->tail) {
                s = node->to_string() + s;
                node = node->getNext();
                if (node != this->tail)
                    s = ", " + s;
            }
            s = "(" + s;
            return s;
        }
};

template <class T>
class OrderedLinkedList: public LinkedList<T> { // A singly-linked list in which the elements are in ascending order.
    private:
        Node<T>* head;
    public:
        Node<T>* getHead() {
            return this->head;
        }
        OrderedLinkedList() {
            this->head = nullptr;
            this->numNodes = 0;
        }
        // There cannot be an add first function in OrderedLinkedList, that would ruin the order.
        void addFirst(T cargo) = delete;
        // Adds an item to the list
        void addItem(T c) {
            this->numNodes++;
            Node<T>* n = new Node<T>(c);
            if (head == nullptr || head->getCargo() >= n->getCargo()) {
                n->setNext(head);
                head = n;
            } else {
                Node<T>* tracker = head;
                while (tracker->getNext() != nullptr && tracker->getNext()->getCargo() < n->getCargo()) {
                    tracker = tracker->getNext();
                }
                n->setNext(tracker->getNext());
                tracker->setNext(n);
            }
        }
        string to_string() const {
            if (head == nullptr) {
                return "Empty list";
            }
            Node<T>* node = head;
            string s = "(";

            while (node != nullptr) {
                s += node->to_string();
                node = node->getNext();
                if (node != nullptr)
                    s += ", ";
            }
            s += ")";
            return s;
        }
        string to_string_reverse() const {
            if (head == nullptr) {
                string s = "Empty list";
                return s;
            }
            Node<T>* node = head;
            string s = ")";

            while (node != nullptr) {
                s = node->to_string() + s;
                node = node->getNext();
                if (node != nullptr)
                    s = ", " + s;
            }
            s = "(" + s;
            return s;
        }
};

#endif