#include <iostream>
using namespace std;

class BST;

class Node
{
    int data;
    Node *left;
    Node *right;

public:
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
    friend BST;
};

class BST
{
    Node *root;

    void insert_node(Node *&ptr, int data)
    {
        if (ptr == nullptr)
        {
            ptr = new Node(data);
            return;
        }
        if (data == ptr->data)
        {
            return;
        }
        else if (data < ptr->data)
        {
            insert_node(ptr->left, data);
        }
        else
        {
            insert_node(ptr->right, data);
        }
    }

    Node *search(Node *ptr, int data)
    {
        if (ptr == nullptr)
        {
            return nullptr;
        }
        if (data == ptr->data)
        {
            return ptr;
        }
        else if (data < ptr->data)
        {
            return search(ptr->left, data);
        }
        else
        {
            return search(ptr->right, data);
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int data)
    {
        insert_node(root, data);
    }

    Node *search(int data)
    {
        return search(root, data);
    }
};