#include <iostream>
using namespace std;

class linkedList;

class node
{
    int data;
    node *nextNode;

public:
    node() {}
    node(int data) : data(data), nextNode(nullptr) {}
    friend linkedList;
};

class linkedList
{
    node *head;

public:
    linkedList() : head(nullptr) {}

    void insert_head(int val)
    {
        node *newNode = new node(val);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->nextNode = head;
            head = newNode;
        }
    }

    void insert_at_index(int val, int index)
    {
        node *newNode = new node(val);
        node *dummy = new node();
        dummy->nextNode = head;
        node *ptr = dummy;
        int i = 0;
        while (ptr->nextNode != nullptr && i < index)
        {
            ptr = ptr->nextNode;
            i++;
        }
        if (i != index)
        {
            cout << "Index is out of bounds." << endl;
            delete newNode;
        }
        else
        {
            newNode->nextNode = ptr->nextNode;
            ptr->nextNode = newNode;
        }
        head = dummy->nextNode;
        delete dummy;
    }

    void insert_before(int val, node *target)
    {
        if (target == nullptr)
        {
            cout << "Target node cannot be null." << endl;
            return;
        }
        node *newNode = new node(val);
        node *dummy = new node();
        dummy->nextNode = head;
        node *ptr = dummy;
        while (ptr->nextNode != nullptr && ptr->nextNode != target)
        {
            ptr = ptr->nextNode;
        }
        if (ptr->nextNode == nullptr)
        {
            cout << "Given node does not exist." << endl;
            delete newNode;
        }
        else
        {
            newNode->nextNode = ptr->nextNode;
            ptr->nextNode = newNode;
        }
        head = dummy->nextNode;
        delete dummy;
    }

    void insert_after(int val, node *target)
    {
        if (target == nullptr)
        {
            cout << "Target node cannot be null." << endl;
            return;
        }
        node *newNode = new node(val);
        node *ptr = head;
        while (ptr != nullptr && ptr != target)
        {
            ptr = ptr->nextNode;
        }
        if (ptr == nullptr)
        {
            cout << "Given node does not exist." << endl;
            delete newNode;
        }
        else
        {
            newNode->nextNode = ptr->nextNode;
            ptr->nextNode = newNode;
        }
    }

    void delete_head()
    {
        if (head == nullptr)
        {
            return;
        }
        node *del = head;
        head = head->nextNode;
        delete del;
    }

    void delete_index(int index)
    {
        if (head == nullptr)
        {
            return;
        }
        node *dummy = new node();
        dummy->nextNode = head;
        node *ptr = dummy;
        int i = 0;
        while (ptr->nextNode != nullptr && i < index)
        {
            ptr = ptr->nextNode;
            i++;
        }
        if (ptr->nextNode == nullptr)
        {
            cout << "Index is out of bound" << endl;
        }
        else
        {
            node *del = ptr->nextNode;
            ptr->nextNode = ptr->nextNode->nextNode;
            delete del;
        }
        head = dummy->nextNode;
        delete dummy;
    }

    void delete_value(int value)
    {
        if (head == nullptr)
        {
            return;
        }
        node *dummy = new node();
        dummy->nextNode = head;
        node *ptr = dummy;
        while (ptr->nextNode != nullptr && ptr->nextNode->data != value)
        {
            ptr = ptr->nextNode;
        }
        if (ptr->nextNode == nullptr)
        {
            cout << "Value not found." << endl;
        }
        else
        {
            node *del = ptr->nextNode;
            ptr->nextNode = ptr->nextNode->nextNode;
            delete del;
        }
        head = dummy->nextNode;
        delete dummy;
    }

    void delete_tail()
    {
        if (head == nullptr)
        {
            return;
        }
        node *dummy = new node();
        dummy->nextNode = head;
        node *ptr = dummy;
        while (ptr->nextNode->nextNode != nullptr)
        {
            ptr = ptr->nextNode;
        }
        node *del = ptr->nextNode;
        ptr->nextNode = nullptr;
        delete del;
        head = dummy->nextNode;
        delete dummy;
    }

    void display()
    {
        node *ptr = head;
        while (ptr != nullptr)
        {
            cout << ptr->data << " -> ";
            ptr = ptr->nextNode;
        }
        cout << "Null" << endl;
    }
};

int main()
{
    linkedList ll;
    ll.insert_head(3);
    ll.insert_head(1);
    ll.insert_at_index(2, 1);
    ll.insert_at_index(10, 3);
    ll.display();
}