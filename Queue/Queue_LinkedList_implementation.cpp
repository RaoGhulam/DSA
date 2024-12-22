#include <iostream>
using namespace std;

class queue;

class node
{
    int data;
    node *nextNode;

public:
    node(int data) : data(data), nextNode(nullptr) {}
    friend queue;
};

class queue
{
    node *front;
    node *rear;

    bool isEmpty()
    {
        return (front == nullptr);
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
    queue() : front(nullptr), rear(nullptr) {}

    void enqueue(int data)
    {
        if (!isFull())
        {
            node *newNode = new node(data);
            if (isEmpty())
            {
                front = rear = newNode;
            }
            else
            {
                rear->nextNode = newNode;
                rear = newNode;
            }
        }
        else
        {
            cout << "Queue is Full." << endl;
        }
    }

    int dequeue()
    {
        if (!isEmpty())
        {
            int data = front->data;
            node *del = front;
            front = front->nextNode;
            delete del;
            return data;
        }
        else
        {
            cout << "Queue is Empty." << endl;
            return -1;
        }
    }

    void display()
    {
        node *ptr = front;
        while (ptr != nullptr)
        {
            cout << ptr->data << " -> ";
        }
        cout << "Null" << endl;
    }
};