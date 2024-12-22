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

    void preOrderTraversal(Node *ptr)
    {
        if (ptr != nullptr)
        {
            cout << ptr->data << ", ";
            preOrderTraversal(ptr->left);
            preOrderTraversal(ptr->right);
        }
    }

    void inOrderTraversal(Node *ptr)
    {
        if (ptr != nullptr)
        {
            inOrderTraversal(ptr->left);
            cout << ptr->data << ", ";
            inOrderTraversal(ptr->right);
        }
    }

    void postOrderTraversal(Node *ptr)
    {
        if (ptr != nullptr)
        {
            postOrderTraversal(ptr->left);
            postOrderTraversal(ptr->right);
            cout << ptr->data << ", ";
        }
    }

public:
    BST() : root(nullptr) {}

    void insert(int data)
    {
        insert_node(root, data);
    }

    // Pre_Order Traversal
    void preOrderTraversal()
    {
        preOrderTraversal(root);
    }
    // In_Order Traversal
    void inOrderTraversal()
    {
        inOrderTraversal(root);
    }
    // Post_Order Traversal
    void postOrderTraversal()
    {
        postOrderTraversal(root);
    }
};