#include <iostream>
#include <string>
#include "Stack.h"
#include "Stack_Infix.h"

using namespace std;

bool is_valid_infix_expr(const string& s) {
    Stack<char> parenthesis;  // Use Stack<char> instead of Stack<string>

    for (char ch : s) {
        if (ch == '(') {
            parenthesis.push(ch);
        } else if (ch == ')') {
            if (parenthesis.empty()) {  // Fix: empty() is a function
                return false;  // More closing parentheses than opening ones
            }
            parenthesis.pop();
        }
    }

    return parenthesis.empty();  // True if all parentheses are matched
}
