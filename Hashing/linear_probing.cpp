#include <iostream>
#include <vector>
using namespace std;

class HASH
{
    int capacity;
    int size;
    vector<int> table;

public:
    HASH(int size) : capacity(size), size(0), table(size, -1) {}

    int hash_function(int x)
    {
        return x % capacity;
    }

    void insert_item(int key)
    {
        if (size == capacity)
        {
            cout << "Hash Table is Full" << endl;
            return;
        }

        int index = hash_function(key);
        while (table[index] != -1 && table[index] != -2)
        { // -2 is a "deleted" marker
            index = (index + 1) % capacity;
        }

        table[index] = key;
        size++;
    }

    bool search(int key)
    {
        int index = hash_function(key);
        int originalIndex = index;

        while (table[index] != -1)
        { // Stop when an empty slot is encountered
            if (table[index] == key)
            {
                return true;
            }
            index = (index + 1) % capacity;
            if (index == originalIndex)
            { // If we loop back to the starting index
                break;
            }
        }
        return false;
    }

    void delete_item(int key)
    {
        int index = hash_function(key);
        int originalIndex = index;

        while (table[index] != -1)
        { // Stop when an empty slot is encountered
            if (table[index] == key)
            {
                table[index] = -2; // Mark slot as deleted
                size--;
                return;
            }
            index = (index + 1) % capacity;
            if (index == originalIndex)
            { // If we loop back to the starting index
                break;
            }
        }

        cout << "Key not found" << endl;
    }

    void display()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (table[i] == -1)
            {
                cout << i << ": " << "Empty" << endl;
            }
            else if (table[i] == -2)
            {
                cout << i << ": " << "Deleted" << endl;
            }
            else
            {
                cout << i << ": " << table[i] << endl;
            }
        }
    }
};

int main()
{
    HASH h(7);

    h.insert_item(10);
    h.insert_item(20);
    h.insert_item(15);
    h.insert_item(7);

    h.display();

    cout << "Search for 15: " << (h.search(15) ? "Found" : "Not Found") << endl;

    h.delete_item(15);
    h.display();

    cout << "Search for 15: " << (h.search(15) ? "Found" : "Not Found") << endl;

    return 0;
}
