#include <iostream>
using namespace std;

class linkedList;

class node
{
    int data;
    node *nextNode;
    node *preNode;

public:
    node() {}
    node(int data) : data(data), nextNode(nullptr), preNode(nullptr) {}
    friend linkedList;
};

class linkedList
{
    node *head;

public:
    linkedList() : head(nullptr) {}

    void insert_head(int data)
    {
        node *newNode = new node(data);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->nextNode = head;
            head->preNode = newNode;
            head = newNode;
        }
    }
    void insert_tail(int data)
    {
        node *newNode = new node(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        node *ptr = head;
        while (ptr->nextNode != nullptr)
        {
            ptr = ptr->nextNode;
        }
        newNode->preNode = ptr;
        ptr->nextNode = newNode;
    }
    void insert_before(int data, node *target)
    {
        node *newNode = new node(data);
        if (target == nullptr)
        {
            cout << "Target node cannot be null." << endl;
            return;
        }
        if (head == nullptr)
        {
            return;
        }
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
            newNode->preNode = ptr;
            ptr->nextNode->preNode = newNode;
            ptr->nextNode = newNode;
        }
        head = dummy->nextNode;
        delete dummy;
    }
    void insert_after(int data, node *target)
    {
        if (target == nullptr)
        {
            cout << "Target node cannot be null." << endl;
            return;
        }
        node *newNode = new node(data);
        if (head == nullptr)
        {
            delete newNode;
            return;
        }
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
            newNode->preNode = ptr;
            newNode->nextNode = ptr->nextNode;
            if (ptr->nextNode != nullptr)
            {
                ptr->nextNode->preNode = newNode;
            }
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
        if (head != nullptr)
        {
            head->preNode = nullptr;
        }
        delete del;
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
    void delete_value(int val)
    {
        if (head == nullptr)
        {
            return;
        }
        node *dummy = new node();
        dummy->nextNode = head;
        node *ptr = dummy;
        while (ptr->nextNode != nullptr && ptr->nextNode->data != val)
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
            ptr->nextNode = del->nextNode;

            if (del->nextNode != nullptr)
            {
                del->nextNode->preNode = ptr;
            }

            delete del;
        }
        head = dummy->nextNode;
        if (head != nullptr)
        {
            head->preNode = nullptr;
        }
        delete dummy;
    }
};