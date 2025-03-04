#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "Stack.h"
#include "Stack_Infix.h"
using namespace std;

TEST_CASE("Test is_valid_infix_expression") {
    std::string expr = "(4 + a) / c";
    CHECK(is_valid_infix_expr(expr) == true);
    expr = "(x * ((5 - d) + c) - y) * 2";
    CHECK(is_valid_infix_expr(expr) == true);
    expr = "(x * ((5 - d) + c - y) * 2";
    CHECK(is_valid_infix_expr(expr) == false);
}