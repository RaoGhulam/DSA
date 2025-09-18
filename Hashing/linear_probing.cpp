#include <iostream>
#include <vector>
using namespace std;

class HASH
{
    int size;
    int capacity;
    vector<int> table;

public:
    HASH(int capacity) : capacity(capacity), size(0), table(capacity, -1) {}

    int hashFunction(int key)
    {
        return key % capacity;
    }

    void insert(int key)
    {
        if (size == capacity)
        {
            return;
        }
        int index = hashFunction(key);
        int i = 0;

        // Quadratic probing
        while (table[(index + i * i) % capacity] != -1 &&
               table[(index + i * i) % capacity] != -2)
        {
            i++;
        }
        table[(index + i * i) % capacity] = key;
        size++;
    }

    bool search(int key)
    {
        int index = hashFunction(key);
        int i = 0;

        // Quadratic probing
        while (table[(index + i * i) % capacity] != -1)
        {
            if (table[(index + i * i) % capacity] == key)
            {
                return true;
            }
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
        int index = hashFunction(key);
        int i = 0;

        // Quadratic probing
        while (table[(index + i * i) % capacity] != -1)
        {
            if (table[(index + i * i) % capacity] == key)
            {
                table[(index + i * i) % capacity] = -2; // Mark as deleted
                size--;
                return;
            }
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
