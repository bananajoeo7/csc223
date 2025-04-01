#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "Stack.h"
using namespace std;

TEST_CASE("Test basic stack operations on stack of ints") {
    Stack<int> stack;
    stack.push(9);
    CHECK(stack.top() == 9);
    stack.push(11);
    CHECK(stack.top() == 11);
    stack.push(42);
    CHECK(stack.top() == 42);
    CHECK(stack.pop() == 42);
    CHECK(stack.top() == 11);
    CHECK(stack.empty() == false);
    stack.pop();
    CHECK(stack.pop() == 9);
    CHECK(stack.empty() == true);
}

TEST_CASE("Test basic stack operations on stack of strings") {
    Stack<string> stack;
    stack.push("cheese");
    CHECK(stack.top() == "cheese");
    stack.push("anchovies");
    CHECK(stack.top() == "anchovies");
    stack.push("onions");
    CHECK(stack.top() == "onions");
    CHECK(stack.pop() == "onions");
    CHECK(stack.top() == "anchovies");
    CHECK(stack.empty() == false);
    stack.pop();
    CHECK(stack.pop() == "cheese");
    CHECK(stack.empty() == true);
}

struct Card {
    string suit;
    string rank;

    bool operator == (const Card& other) const {
        return suit == other.suit && rank == other.rank;
    }
};

TEST_CASE("Test stack operations with Cards") {
    Stack<Card> stack;
    CHECK(stack.empty() == true);

    Card ace_spades = {"Spades", "Ace"};
    Card king_hearts = {"Hearts", "King"};
    Card queen_diamonds = {"Diamonds", "Queen"};
    
    stack.push(ace_spades);
    CHECK(stack.top() == ace_spades);
    CHECK(stack.empty() == false);
    stack.push(king_hearts);
    CHECK(stack.top() == king_hearts);
    stack.push(queen_diamonds);
    CHECK(stack.top() == queen_diamonds);
    CHECK(stack.pop() == queen_diamonds);
    CHECK(stack.top() == king_hearts);
    CHECK(stack.pop() == king_hearts);
    CHECK(stack.top() == ace_spades);
    CHECK(stack.pop() == ace_spades);
    CHECK(stack.empty() == true);
}