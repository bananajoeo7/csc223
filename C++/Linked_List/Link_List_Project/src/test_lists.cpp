#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "CircularList.h"
using namespace std;

TEST_CASE("Test basic list of strings operations") {
    CircularList<string> toppings;
    toppings.insert_at_front("cheese");
    CHECK(toppings.to_str() == "cheese");
    toppings.insert_at_front("anchovies");
    CHECK(toppings.to_str() == "anchovies, cheese");
    toppings.insert_at_front("onions");
    CHECK(toppings.to_str() == "onions, anchovies, cheese");
    CHECK(toppings.remove_from_front() == "onions");
    CHECK(toppings.to_str() == "anchovies, cheese");
}

TEST_CASE("Test inserting and removing a single element") {
    CircularList<string> list;
    list.insert_at_front("apple");
    CHECK(list.to_str() == "apple");
    list.remove_from_front();
    CHECK(list.to_str() == "");
    CHECK(list.is_empty());
}


TEST_CASE("Test multiple insertions and removals") {
    CircularList<string> list;
    list.insert_at_front("A");
    list.insert_at_front("B");
    list.insert_at_front("C");
    CHECK(list.to_str() == "C, B, A");
    
    CHECK(list.remove_from_front() == "C");
    CHECK(list.to_str() == "B, A");
    
    CHECK(list.remove_from_front() == "B");
    CHECK(list.to_str() == "A");

    CHECK(list.remove_from_front() == "A");
    CHECK(list.to_str() == "");
    CHECK(list.is_empty());
}


TEST_CASE("Test inserting and clearing the list") {
    CircularList<int> list;
    list.insert_at_front(1);
    list.insert_at_front(2);
    list.insert_at_front(3);
    CHECK(list.to_str() == "3, 2, 1");

    list.remove_from_front();
    list.remove_from_front();
    list.remove_from_front();

    CHECK(list.to_str() == "");
    CHECK(list.is_empty());

}
