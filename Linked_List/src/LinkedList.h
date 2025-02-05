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
    static std::string render_list_backward(Node* list, string s);
    //static Node* remove_second(Node* list);

};