#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *left, *right;

public:
    Node(int data) : data(data), left(nullptr), right(nullptr) {}
    friend class BST;
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

    void deleteNode(Node *&ptr, int data)
    {
        if (ptr == nullptr)
            return;

        if (data < ptr->data)
        {
            deleteNode(ptr->left, data);
        }
        else if (data > ptr->data)
        {
            deleteNode(ptr->right, data);
        }
        else
        {
            // Node with Only Right Child or No Child
            if (ptr->left == nullptr)
            {
                Node *temp = ptr->right;
                delete ptr;
                ptr = temp;
            }
            // Node with Only Left Child
            else if (ptr->right == nullptr)
            {
                Node *temp = ptr->left;
                delete ptr;
                ptr = temp;
            }
            // Node with Two Children
            else
            {
                Node *temp = minValueNode(ptr->right);
                ptr->data = temp->data;
                deleteNode(ptr->right, temp->data);
            }
        }
    }

    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (current && current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }

public:
    BST() : root(nullptr) {}

    void insert_node(int data)
    {
        insert_node(root, data);
    }

    void delete_node(int data)
    {
        deleteNode(root, data);
    }
};

int main()
{
    BST tree;
    tree.insert_node(50);
    tree.insert_node(30);
    tree.insert_node(70);
    tree.insert_node(20);
    tree.insert_node(40);
    tree.insert_node(60);
    tree.insert_node(80);

    tree.delete_node(50);

    return 0;
}
