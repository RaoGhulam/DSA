#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class HASH
{
    int size;
    int capacity;
    vector<int> table;

public:
    HASH(int capacity) : capacity(capacity), size(0), table(capacity, -1) {}
    int hashFunction1(int key)
    {
        return key % capacity;
    }
    int hashFunction2(int key)
    {
        return 1 + (key % (capacity - 1));
    }
    void insert(int key)
    {
        if (size == capacity)
        {
            return;
        }
        int index = hashFunction1(key);
        int stepSize = hashFunction2(key);
        int i = 0;
        while (table[index] != -1 and table[index] != -2)
        {
            index = (index + i * stepSize) % capacity;
            i++;
        }
        table[index] = key;
        size++;
        return;
    }
    bool search(int key)
    {
        int index = hashFunction1(key);
        int stepSize = hashFunction2(key);
        int originalIndex = index;
        int i = 0;
        while (table[index] != -1)
        {
            if (table[index] == key)
            {
                return true;
            }
            index = (index + i * stepSize) % capacity;
            i++;
            if (i == capacity)
            { // Prevent infinite loops
                break;
            }
        }
        return false;
    }
    void delete_(int key)
    {
        int index = hashFunction1(key);
        int stepSize = hashFunction2(key);
        int originalIndex = index;
        int i = 0;
        while (table[index] != -1)
        {
            if (table[index] == key)
            {
                table[index] = -2;
                size--;
                return;
            }
            index = (index + i * stepSize) % capacity;
            i++;
            if (i == capacity)
            { // Prevent infinite loops
                break;
            }
        }
    }

    void display()
    {
        for (int i = 0; i < capacity; i++)
        {
            cout << table[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    HASH hashTable(7);
    hashTable.insert(10);
    hashTable.insert(20);
    hashTable.insert(15);
    hashTable.insert(7);

    hashTable.display();

    cout << (hashTable.search(10) ? "Found" : "Not Found") << endl;
    cout << (hashTable.search(25) ? "Found" : "Not Found") << endl;

    hashTable.delete_(15);
    hashTable.display();

    return 0;
}
