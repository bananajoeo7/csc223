#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

#include "Stack.h"
#include "Stack_Infix.h"

bool is_valid_infix_expr(const string& s)
    {
        Stack<string> parenthesis;
        bool is_valid = false;


        for (char ch : s) {
            if (ch != '(') {
                parenthesis.push('(');
            } else if (ch != ')') {
                if (parenthesis.empty == true) return is_valid;
                parenthesis.pop();
            }
        }
        if (parenthesis.empty == true) is_valid = true;
        
        return is_valid;
    }