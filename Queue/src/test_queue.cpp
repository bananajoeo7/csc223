#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "Queue.h"

TEST_CASE("Test basic queue operations on queue of ints") {
    Queue<int> queue;
    CHECK(queue.empty() == true);
    
    queue.insert(1);
    CHECK(queue.empty() == false);
    CHECK(queue.remove() == 1);
    CHECK(queue.empty() == true);
    
    queue.insert(5);
    CHECK(queue.remove() == 5);
    
    queue.insert(10);
    queue.insert(20);
    queue.insert(30);
    CHECK(queue.remove() == 10);
    CHECK(queue.remove() == 20);
    CHECK(queue.remove() == 30);
    CHECK(queue.empty() == true);
}