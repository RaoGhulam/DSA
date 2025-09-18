#include <iostream>
using namespace std;

const int MAX = 100;

class Stack {
    int top;
    int size;
    int* arr;
public:
    Stack(int size) : size(size), top(-1), arr(new int[size]) {}
    
    ~Stack() { delete[] arr; }

    bool isFull() {
        return (top == size - 1);
    }

    bool isEmpty() {
        return (top == -1);
    }

    void push(int num) {
        if (!isFull()) {
            arr[++top] = num;
        }
        else {
            cout << "Stack Overflow" << endl;
        }
    }

    int pop() {
        if (!isEmpty()) {
            return arr[top--];
        }
        else {
            cout << "Stack Underflow" << endl;
            return -1;
        }
    }

    int peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        else {
            cout << "Stack Underflow" << endl;
            return -1;
        }
    }
};

bool match(char x, char y) {
    return ((x == '{' && y == '}') || (x == '[' && y == ']') || (x == '(' && y == ')'));
}

bool paranthesis_match(char exp[MAX]) {
    Stack paranthesisStack(MAX);
    int i = 0;
    while (exp[i] != '\0') {
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(') {
            paranthesisStack.push(exp[i]);
        }
        else if (exp[i] == '}' || exp[i] == ']' || exp[i] == ')') {
            if (paranthesisStack.isEmpty()) {
                return false;  // No matching opening bracket
            }
            char c = paranthesisStack.pop();
            if (!match(c, exp[i])) {
                return false;  // Mismatched pair
            }
        }
        i++;
    }
    // If stack is empty, all parentheses matched; otherwise, some are unmatched
    return paranthesisStack.isEmpty();
}
