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