#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "RGTPQ.h"
using namespace std;

TEST_CASE("Test empty()") {
    RGTPQ rgtpq;
    CHECK(rgtpq.empty() == true);

    RGThing redThing;
    redThing.color = RED;
    redThing.label = "Red1";
    RGThing greenThing;
    greenThing.color = GREEN;
    greenThing.label = "Green1";

    rgtpq.insert(redThing);
    CHECK(rgtpq.empty() == false);
}

TEST_CASE("Test insert() and remove()") {
    RGTPQ rgtpq;

    CHECK_THROWS_WITH(rgtpq.remove(), "Error: Cannot dequeue from empty queue.");

    struct RGThing redThing = {RED, "Red1"};
    struct RGThing greenThing = {GREEN, "Green1"};

    rgtpq.insert(redThing);
    rgtpq.insert(greenThing);

    RGTpair pair = rgtpq.remove();

    CHECK(pair.thing1.color == RED);
    CHECK(pair.thing2.color == GREEN);
    CHECK(pair.thing1.label == "Red1");
    CHECK(pair.thing2.label == "Green1");

    CHECK(rgtpq.empty() == true);

    struct RGThing redThing2 = {RED, "Red2"};
    struct RGThing greenThing2 = {GREEN, "Green2"};

    struct RGThing redThing3 = {RED, "Red3"};
    struct RGThing greenThing3 = {GREEN, "Green3"};

    rgtpq.insert(redThing);
    CHECK_THROWS_WITH(rgtpq.remove(), "Error: No green items left in queue.");

    rgtpq.insert(redThing2);
    rgtpq.insert(redThing3);

    CHECK_THROWS_WITH(rgtpq.remove(), "Error: No green items left in queue.");

    rgtpq.insert(greenThing);
    rgtpq.insert(greenThing2);
    rgtpq.insert(greenThing3);

    pair = rgtpq.remove();

    CHECK(pair.thing1.color == RED);
    CHECK(pair.thing2.color == GREEN);
    CHECK(pair.thing1.label == "Red1");
    CHECK(pair.thing2.label == "Green1"); // Because green1 was the first green to be pushed, it'll be at the front

    pair = rgtpq.remove();

    CHECK(pair.thing1.color == RED);
    CHECK(pair.thing2.color == GREEN);
    CHECK(pair.thing1.label == "Red2");
    CHECK(pair.thing2.label == "Green2");

    pair = rgtpq.remove();
    
    CHECK(pair.thing1.color == RED);
    CHECK(pair.thing2.color == GREEN);
    CHECK(pair.thing1.label == "Red3");
    CHECK(pair.thing2.label == "Green3");

    CHECK(rgtpq.empty() == true);

    rgtpq.insert(greenThing);
    CHECK_THROWS_WITH(rgtpq.remove(), "Error: No red items left in queue.");
    rgtpq.insert(greenThing2);
    rgtpq.insert(greenThing3);
    CHECK_THROWS_WITH(rgtpq.remove(), "Error: No red items left in queue.");
}