#include <iostream>
using namespace std;

class Queue
{
    int size;
    int front;
    int rear;
    int *arr;

    bool isFull()
    {
        return (rear == size - 1);
    }

    bool isEmpty()
    {
        return (rear == front);
    }

public:
    Queue(int size) : size(size), front(-1), rear(-1), arr(new int[size]) {}

    ~Queue()
    {
        delete[] arr;
    }

    void enqueue(int num)
    {
        if (!isFull())
        {
            arr[++rear] = num;
        }
        else
        {
            cout << "Queue is full" << endl;
        }
    }

    int dequeue()
    {
        if (!isEmpty())
        {
            return arr[++front];
        }
        else
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
    }

    void display()
    {
        if (!isEmpty())
        {
            for (int i = front + 1; i <= rear; ++i)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Queue is empty" << endl;
        }
    }
};

int main()
{
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.display();

    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    
    q.display();

    // cout << "Dequeued: " << q.dequeue() << endl;

    // q.display();

    // q.enqueue(40);
    // q.display();

    return 0;
}
