#include <iostream>
#include <queue>
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

public:
    BST() : root(nullptr) {}

    void insert_node(int data)
    {
        insert_node(root, data);
    }

    void BFS()
    {
        if (root == nullptr)
        {
            cout << "Tree is empty." << endl;
            return;
        }

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();

            cout << current->data << " ";

            // Enqueue left child
            if (current->left != nullptr)
            {
                q.push(current->left);
            }

            // Enqueue right child
            if (current->right != nullptr)
            {
                q.push(current->right);
            }
        }
        cout << endl;
    }
};