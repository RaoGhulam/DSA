#include <iostream>
using namespace std;

class stack;

class node
{
    int data;
    node *nextNode;

public:
    node(int data) : data(data), nextNode(nullptr) {}
    friend stack;
};

class stack
{
    node *top;
    bool isEmpty()
    {
        return (top == nullptr);
    }
    bool isFull()
    {
        node *newNode = new (nothrow) node(0);
        if (newNode == nullptr)
        {
            return true;
        }
        delete newNode;
        return false;
    }

public:
    stack() : top(nullptr) {}
    void push(int data)
    {
        if (!isFull())
        {
            node *newNode = new node(data);
            newNode->nextNode = top;
            top = newNode;
        }
        else
        {
            cout << "Stack is Full." << endl;
        }
    }
    int pop()
    {
        if (!isEmpty())
        {
            int data = top->data;
            node *del = top;
            top = top->nextNode;
            delete del;
            return data;
        }
        else
        {
            cout << "Stack is Empty." << endl;
            return -1;
        }
    }
    void display()
    {
        node *ptr = top;
        while (ptr != nullptr)
        {
            cout << ptr->data << " -> ";
        }
        cout << "Null" << endl;
    }
};