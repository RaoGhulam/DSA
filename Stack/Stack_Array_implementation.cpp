#include <iostream>
using namespace std;

class stack
{
    int size;
    int top;
    int *arr;
    
    void grow()
    {
        int newSize = size + 5;
        int *temp = new int[newSize];

        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }

        delete[] arr;
        arr = temp;
        size = newSize;
    }

public:
    stack(int size) : size(size), top(-1), arr(new int[size]) {}
    ~stack()
    {
        delete[] arr;
    }
    bool isEmpty()
    {
        return (top == -1);
    }
    bool isFull()
    {
        return (top == size - 1);
    }
    void push(int num)
    {
        if (isFull())
        {
            grow();
        }
        arr[++top] = num;
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
        else
        {
            return arr[top--];
        }
    }
    void display()
    {
        if (!isEmpty())
        {
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Stack is empty" << endl;
        }
    }
};

int main()
{
    stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.pop();
    s.display();

    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);

    s.display();

    return 0;
}