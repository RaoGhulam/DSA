#include <iostream>
using namespace std;

template <typename T>
class dynamicArray
{
    int capacity;
    int size;
    T *arr;
    void grow()
    {
        int newCapacity = capacity + 5;
        T *temp = new T[newCapacity];
        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        capacity = newCapacity;
    }

    void shrink()
    {
        int newCapacity = capacity - 5;
        T *temp = new T[newCapacity];
        for (int i = 0; i < size; i++)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        capacity = newCapacity;
    }

public:
    dynamicArray(int capacity) : capacity(capacity), size(0), arr(new T[capacity]) {}
    ~dynamicArray()
    {
        delete[] arr;
    }
    void push(T val)
    {
        if (size == capacity)
        {
            grow();
        }
        arr[size++] = val;
    }
    void insert(T val, int index)
    {
        if (index >= 0 && index <= size)
        {
            if (size == capacity)
            {
                grow();
            }
            for (int i = size; i > index; i--)
            {
                arr[i] = arr[i - 1];
            }
            arr[index] = val;
            size++;
        }
    }
    T pop()
    {
        T val = arr[--size];
        if (size + 6 == capacity)
        {
            shrink();
        }
        return val;
    }
    T remove(int index)
    {
        if (index >= 0 && index < size)
        {
            T val = arr[index];
            for (int i = index; i < size - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            size--;
            if (size + 6 == capacity)
            {
                shrink();
            }
            return val;
        }
    }
    int get_size()
    {
        return size;
    }
    int get_capacity()
    {
        return capacity;
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};