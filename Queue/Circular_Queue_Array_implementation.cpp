#include <iostream>
using namespace std;

class Queue
{
    int size;
    int front;
    int rear;
    int count;
    int *arr;

    bool isFull()
    {
        return (count == size);
    }

    bool isEmpty()
    {
        return (count == 0);
    }

public:
    Queue(int size) : size(size), front(0), rear(0), count(0), arr(new int[size]) {}

    ~Queue()
    {
        delete[] arr;
    }

    void enqueue(int num)
    {
        if (!isFull())
        {
            arr[rear] = num;
            rear = (rear + 1) % size; // Circular increment
            count++;
        }
        else
        {
            std::cout << "Queue is full" << std::endl;
        }
    }

    int dequeue()
    {
        if (!isEmpty())
        {
            int value = arr[front];
            front = (front + 1) % size; // Circular increment
            count--;
            return value;
        }
        else
        {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
    }
};
