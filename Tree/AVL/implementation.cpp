#include <iostream>
#include <algorithm>
using namespace std;

class AVL;

class Node
{
    int data;
    Node *left;
    Node *right;
    int height;

public:
    Node(int data) : data(data), left(nullptr), right(nullptr), height(1) {}
    friend class AVL;
};

class AVL
{
    Node *root;

    int get_height(Node *ptr)
    {
        return (ptr == nullptr) ? 0 : ptr->height;
    }

    int get_balance_factor(Node *ptr)
    {
        return (ptr == nullptr) ? 0 : get_height(ptr->left) - get_height(ptr->right);
    }

    Node *LL_rotation(Node *ptr)
    {
        Node *new_root = ptr->left;
        ptr->left = new_root->right;
        new_root->right = ptr;
        ptr->height = max(get_height(ptr->left), get_height(ptr->right)) + 1;
        new_root->height = max(get_height(new_root->left), get_height(new_root->right)) + 1;
        return new_root;
    }

    Node *RR_rotation(Node *ptr)
    {
        Node *new_root = ptr->right;
        ptr->right = new_root->left;
        new_root->left = ptr;
        ptr->height = max(get_height(ptr->left), get_height(ptr->right)) + 1;
        new_root->height = max(get_height(new_root->left), get_height(new_root->right)) + 1;
        return new_root;
    }

    Node *insert_node(Node *&ptr, int data)
    {
        if (ptr == nullptr)
        {
            ptr = new Node(data);
            return ptr;
        }

        if (data < ptr->data)
        {
            insert_node(ptr->left, data);
        }
        else if (data > ptr->data)
        {
            insert_node(ptr->right, data);
        }
        else
        {
            return ptr;
        }

        ptr->height = max(get_height(ptr->left), get_height(ptr->right)) + 1;
        int balance = get_balance_factor(ptr);

        // Left-Left (LL) case
        if (balance > 1 && data < ptr->left->data)
            return LL_rotation(ptr);

        // Right-Right (RR) case
        if (balance < -1 && data > ptr->right->data)
            return RR_rotation(ptr);

        // Left-Right (LR) case
        if (balance > 1 && data > ptr->left->data)
        {
            ptr->left = RR_rotation(ptr->left);
            return LL_rotation(ptr);
        }

        // Right-Left (RL) case
        if (balance < -1 && data < ptr->right->data)
        {
            ptr->right = LL_rotation(ptr->right);
            return RR_rotation(ptr);
        }

        return ptr;
    }

    Node *deleteNode(Node *&ptr, int data)
    {
        if (ptr == nullptr)
        {
            return nullptr;
        }

        // Traverse the tree
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
            // Node to delete found
            if (ptr->left == nullptr)
            {
                Node *temp = ptr->right;
                delete ptr;
                ptr = temp;
            }
            else if (ptr->right == nullptr)
            {
                Node *temp = ptr->left;
                delete ptr;
                ptr = temp;
            }
            else
            {
                // Node with two children
                Node *temp = minValueNode(ptr->right);
                ptr->data = temp->data;
                deleteNode(ptr->right, temp->data);
            }
        }

        if (ptr == nullptr)
            return ptr;

        // Update the height
        ptr->height = max(get_height(ptr->left), get_height(ptr->right)) + 1;

        // Balance the node
        int balance = get_balance_factor(ptr);

        // Left Left Case
        if (balance > 1 && get_balance_factor(ptr->left) >= 0)
        {
            return LL_rotation(ptr);
        }

        // Right Right Case
        if (balance < -1 && get_balance_factor(ptr->right) <= 0)
        {
            return RR_rotation(ptr);
        }

        // Left Right Case
        if (balance > 1 && get_balance_factor(ptr->left) < 0)
        {
            ptr->left = RR_rotation(ptr->left);
            return LL_rotation(ptr);
        }

        // Right Left Case
        if (balance < -1 && get_balance_factor(ptr->right) > 0)
        {
            ptr->right = LL_rotation(ptr->right);
            return RR_rotation(ptr);
        }

        return ptr;
    }

    // Helper function to find the node with the minimum value in a subtree
    Node *minValueNode(Node *ptr)
    {
        Node *current = ptr;
        while (current && current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

public:
    AVL() : root(nullptr) {}

    void insert_node(int data)
    {
        root = insert_node(root, data);
    }
    void delete_node(int data){
        root = deleteNode(root, data);
    }
};
