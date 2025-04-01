#include "Evaluator.h"
#include <math.h>
#include <iostream>
using namespace std;

Evaluator::Evaluator() {
    currentChar = '\0';
}

bool Evaluator::isDigit() {
    return (currentChar > 47 && currentChar < 58);
}
bool Evaluator::isLeftParen() {
    return (currentChar == '(');
}
bool Evaluator::isRightParen() {
    return (currentChar == ')');
}
bool Evaluator::isOp() {
    return (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/' || currentChar == '^' || currentChar == '%');
}
bool Evaluator::isVariable() {
    return ((currentChar > 64 && currentChar < 91) || (currentChar > 96 && currentChar < 123));
}

int Evaluator::applyOp(int op1, int op2, char oprtr) {
    switch (oprtr) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        case '^': return pow(op1, op2);
        case '%': return op1 % op2;
        default: return 0;
    }
}

// Evaluates whether an infix expression is valid or not
bool Evaluator::isValidExp(string expression) {
    int i;
    int value;
    int parenCounter;
    int leftParens = 0;
    int rightParens = 0;
    int operators = 0;
    int operands = 0;

    // First, loop through to see if the number of right
    // and left parentheses balance out. If they do,
    // continue; otherwise, the expression is invalid.
    for (i = 0; i < expression.length(); i++) {
        currentChar = expression[i];
        if (isLeftParen()) {
            leftParens++;
        }
        if (isRightParen()) {
            rightParens++;
        }
    }
    if (rightParens != leftParens) return false;

    string e = "";
    // If the parentheses balance out, loop through
    // the expression a second time.
    for (i = 0; i < expression.length(); i++) {
        currentChar = expression[i];
        // If there is a left parthenthesis, collect
        // the expression between the left and right
        // parentheses and see if it is valid. If it
        // isn't valid, then the entire expression is
        // invalid. Otherwise, continue.
        if (isLeftParen()) {
            // If there was another right parenthesis directly
            // before this one, that indicates multiplication.
            currentChar = expression[i-1];
            if (isRightParen()) {
                operators++; // So, increment operators.
            }

            e = "";
            i++;
            currentChar = expression[i];
            parenCounter = 0;
            // However, you can't just loop till the next right parenthesis;
            // you have to take into account all of the pairs of parentheses
            // that you encounter along the way. That's what parenCounter is
            // for.
            do {
                if (isLeftParen()) parenCounter++;
                if (isRightParen()) parenCounter--;
                e += expression[i];
                i++;
                currentChar = expression[i];
            } while (!isRightParen() || parenCounter != 0);

            cout << e << endl;
            if (!isValidExp(e)) return false;
            operands++; // The expression between parentheses just counts as another operand.
        } else if (isVariable()) {
            operands++;
            // If there was another variable directly
            // before this one, that indicates multiplication.
            currentChar = expression[i-1];
            if (isVariable()) {
                operators++; // So, increment operators.
            }
        } else if (isDigit()) {
            operands++;
            while(isDigit()) {
                i++;
                currentChar = expression[i];
            }
            i--;
        } else if (isOp()) {
            operators++;
        }
    }
    cout << "operators: " << operators << endl;
    cout << "operands: " << operands << endl;
    if (operators != operands - 1) return false;
    cout << endl << endl;
    return true;
}

int Evaluator::evaluate(string expression) {
    int i;
    for (i = 0; i < expression.length(); i++) {
    }
    return 0.0;
}