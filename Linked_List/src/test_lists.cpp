#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "LinkedList.h"
using namespace std;

TEST_CASE("Test can create and render List Nodes") {
    Node* node1 = new Node;
    CHECK(node1->cargo == 0);
}

// #1 exercise test case: Create and render list nodes.
TEST_CASE("Test can create and render List Nodes") {
    Node* node1 = new Node;
    CHECK(node1->cargo == 0);
    Node* node2 = new Node(42);
    CHECK(node2->cargo == 42);
    CHECK(node1->to_str() == "0");
    CHECK(node2->to_str() == "42");
}

// #2 exercise test case: Link them together.
TEST_CASE("Test can link nodes together") {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2, node1);
    Node* node3 = new Node(3, node2);
    CHECK(node2->next == node1);
    CHECK(node3->next == node2);
    CHECK(node3->next->next == node1);
}

// #3 exercise test case: Render a list as a string.
TEST_CASE("Test can display linked nodes") {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2, node1);
    Node* node3 = new Node(3, node2);
    CHECK(Node::render_list(node3) == "3, 2, 1");
}

// #4 exercise test case: Render a list backward.
TEST_CASE("Test can display linked nodes backwards") {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2, node1);
    Node* node3 = new Node(3, node2);
    Node* node4 = new Node(4, node3);
    CHECK(Node::render_list(node4) == "4, 3, 2, 1");
    CHECK(Node::render_list_backward(node4) == "1, 2, 3, 4");
}

// #5 exercise test case: Now make it “pretty” by putting parenthesis around it.
TEST_CASE("Test can display linked nodes with parenthesis") {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2, node1);
    Node* node3 = new Node(3, node2);
    Node* node4 = new Node(4, node3);
    CHECK(Node::render_pretty(node4, &Node::render_list) == "(4, 3, 2, 1)");
    CHECK(Node::render_pretty(node4, &Node::render_list_backward) == "(1, 2, 3, 4)");
}
