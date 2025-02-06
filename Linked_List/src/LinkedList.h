#include <string>
using namespace std;

struct Node {
    int cargo;
    Node* next;

    // constructors
    Node();
    Node(int);
    Node(int, Node*);
    std::string to_str() const;

    static std::string render_list(Node* list);
    static std::string render_list_backward(Node* list);
    static std::string render_pretty(Node* list, string (*list_renderer)(Node*));
    static Node* remove_second(Node* list);

};

class LinkedList
{
    int num_nodes;
    Node* head;

public:
    LinkedList() {
        num_nodes = 0;
        head = nullptr;
    }

    void insert_in_front(int cargo);
    std::string render() const;
};