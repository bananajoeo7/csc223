#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include "Array_PQueue.h"

TEST_CASE("Use Linked List Implementation to test basic priority queue operations on queue of integers") {
    std::cout << "Use Array Implementation to test basic priority queue operations on queue of integers." << "\n";
    PriorityQueue<int> pq;
    CHECK(pq.empty() == true);

    pq.insert(5);
    CHECK(pq.empty() == false);

    pq.insert(3);
    pq.insert(10);
    CHECK(pq.remove() == 10);
    pq.insert(7);
    pq.insert(1);
    pq.insert(8);

    CHECK(pq.remove() == 8);
    CHECK(pq.remove() == 7);
    CHECK(pq.remove() == 5);
    CHECK(pq.remove() == 3);
    CHECK(pq.remove() == 1);
    CHECK(pq.empty() == true);
}

TEST_CASE("Test priority queue handles underflow") {
    PriorityQueue<int> pq;
    CHECK_THROWS_WITH(pq.remove(), "Can't remove from empty queue");
}
