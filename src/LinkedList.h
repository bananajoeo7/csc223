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
};