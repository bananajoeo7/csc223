#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "Queue.h"
using namespace std;

TEST_CASE("Test basic queue operations on queue of strings") {
    Queue<string> queue;
    CHECK(queue.empty() == true);
    queue.insert("first");
    CHECK(queue.empty() == false);
    queue.insert("second");
    queue.insert("third");
    CHECK(queue.remove() == "first");
    queue.insert("forth");
    queue.insert("fifth");
    queue.insert("sixth");
    queue.insert("seventh");
    queue.insert("eight");
    queue.insert("nineth");
    CHECK(queue.remove() == "second");
    CHECK(queue.remove() == "third");
    queue.insert("tenth");
    queue.insert("eleventh");
    CHECK(queue.remove() == "forth");
    queue.insert("twelfth");
    queue.insert("thirteenth");
    CHECK(queue.remove() == "fifth");
}

TEST_CASE("Test queue handles overflow and underflow") {
    Queue<int> q;
    for (int i = 1; i < 10; i++)
        q.insert(i);
    CHECK(q.empty() == false);
    CHECK_THROWS_WITH(q.insert(11), "No more space in queue");
    for (int i = 1; i < 10; i++)
        CHECK(q.remove() == i);
    CHECK_THROWS_WITH(q.remove(), "Can't remove from empty queue");
}