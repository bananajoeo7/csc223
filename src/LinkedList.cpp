#include "LinkedList.h"
#include <string>
using namespace std;

Node::Node()
{
    cargo = 0;
    next = nullptr;
}

Node::Node(int cargo)
{
    this->cargo = cargo;
    next = nullptr;
}

Node::Node(int cargo, Node* next)
{
    this->cargo = cargo;
    this->next = next;
}

std::string Node::to_str() const {
    return to_string(cargo);
}