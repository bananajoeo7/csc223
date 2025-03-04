#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;
#ifndef STACK_H
#define STACK_H
#define MAX_SIZE 128
#include <stdexcept>

template <class T>
class Stack {
    int top_item;
    T items[MAX_SIZE];

public:
    Stack() {
        top_item = -1;
    }

    void push(const T& value) {
        if (top_item >= MAX_SIZE - 1) {
            throw std::overflow_error("Stack overflow");
        }
        items[++top_item] = value;
    }

    T pop() {
        if (empty()) {
            throw std::underflow_error("Stack underflow");
        }
        return items[top_item--];
    }

    const T& top() const {
        if (empty()) {
            throw std::underflow_error("Stack is empty");
        }
        return items[top_item];
    }

    bool empty() const {
        return top_item == -1;
    }

    size_t size() const {
        return top_item + 1;
    }

    vector<string> split_on_spaces(const string& s)
    {
        vector<string> tokens;
        string token;
        bool in_token = false;

        for (char ch : s) {
            if (ch != ' ') {
                // if ch not a space, add it to current token
                token += ch;
                in_token = true;
            } else if (in_token) {
            // if space and in a token, push token to tokens list 
                tokens.push_back(token);
                token.clear(); // clear token for next word
                in_token = false;
            }
        }

        // handle last token if string doesn't end with a space
        if (in_token)
            tokens.push_back(token);

        return tokens;
    }
};

#endif // STACK_H