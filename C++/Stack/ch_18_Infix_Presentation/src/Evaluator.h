#pragma once
#include "Stacks.h"
#include <string>
#include <vector>
using namespace std;

class Evaluator {
    private:
        Stack<int> numbers;
        Stack<char> operators;
        // Stores the current character being looked
        // at from the expression
        char currentChar;
    public:
        // Default constructor
        Evaluator();
        // Checks if a char is a digit
        bool isDigit();
        // Checks if currentChar is an operation
        bool isOp();
        // Checks if currentChar is a left parenthesis
        bool isLeftParen();
        // Checks if currentChar is a right parenthesis
        bool isRightParen();
        // Checks if currentChar is a variable
        bool isVariable();
        // Checks if an infix expression is valid,
        // i.e. balanced parentheses, two operands
        // per operator, etc.
        bool isValidExp(string expression);
        // Evaluates a string expression
        int evaluate(string expression);
        // Applies an operation to two operands
        int applyOp(int op1, int op2, char oprtr);
};