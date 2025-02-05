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

std::string Node::render_list(Node* list) {
    Node* node = list;
    std::string s = "";
    while (node != nullptr) {
        s += node->to_str();  // Ensure Node has a valid to_string() method
        node = node->next;
        if (node != nullptr)
            s += ", ";
    }
    return s;
}

std::string Node::render_list_backward(Node* list) {
    if (list->next != nullptr) {
        // Recursively render the rest of the list first
        std::string rest = render_list_backward(list->next);
        return rest + ", " + list->to_str();
    } else {
        return list->to_str();
    }
}

std::string Node::render_pretty(Node* list, string (*list_renderer)(Node*)) {
    return "(" + list_renderer(list) + ")";
}

Node* Node::remove_second(Node* list) {
    if (list == nullptr || list->next == nullptr) {
        return nullptr;
    }
    Node* first = list;
    Node* second = list->next;

    // make the first node point to the third
    first->next = second->next;

    // remove the second node from the list and return a pointer to it
    second->next = nullptr;
    return second;
}
