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

bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    if (c == '*' || c == '/') {
        return 2;
    }
    if (c == '^') {
        return 3;
    }
    return 0;
}

void infix_to_postfix(char infix[], char postfix[]) {
    Stack operatorStack(MAX);
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char c = infix[i];
        if (isOperand(c)) {
            postfix[j++] = c;
        }
        else if (c == '(') {
            operatorStack.push(c);
        }
        else if (c == ')') {
            while (!operatorStack.isEmpty() && operatorStack.peek() != '(') {
                postfix[j++] = operatorStack.pop();
            }
            operatorStack.pop();
        }
        else {
            while (!operatorStack.isEmpty() && precedence(operatorStack.peek()) >= precedence(c)) {
                postfix[j++] = operatorStack.pop();
            }
            operatorStack.push(c);
        }
        i++;
    }

    while (!operatorStack.isEmpty()) {
        postfix[j++] = operatorStack.pop();
    }
    postfix[j] = '\0';
}

void reverseString(char str[], char reversed[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    for (int k = 0; k < length; k++) {
        reversed[k] = str[length - 1 - k];
    }
    reversed[length] = '\0';
}

void infix_to_prefix(char infix[], char prefix[]) {
    Stack operatorStack(MAX);
    int i = 0, j = 0;

    // Reverse the infix expression
    char reversedInfix[MAX];
    int length = 0;
    while (infix[length] != '\0') {
        length++;
    }
    for (int k = 0; k < length; k++) {
        char c = infix[length - 1 - k];
        if (c == '(') {
            reversedInfix[k] = ')';
        } else if (c == ')') {
            reversedInfix[k] = '(';
        } else {
            reversedInfix[k] = c;
        }
    }
    reversedInfix[length] = '\0';

    // Convert reversed infix to postfix
    char tempPostfix[MAX];
    infix_to_postfix(reversedInfix, tempPostfix);

    // Reverse the postfix to get the prefix
    reverseString(tempPostfix, prefix);
}

int main() {
    char infix[MAX];
    char postfix[MAX];
    char prefix[MAX];
    
    cout << "Enter the expression: ";
    cin >> infix;
    
    infix_to_postfix(infix, postfix);
    cout << "Postfix Expression: " << postfix << endl;

    infix_to_prefix(infix, prefix);
    cout << "Prefix Expression: " << prefix << endl;
    
    return 0;
}
