#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
};

Node *addNode(Node *root, int data) // 60,80   70,80 NULL,80
{
    if (root == NULL)
    {
        root = new Node();
        root->left = NULL;
        root->right = NULL;
        root->data = data;
        return root;
    }
    else
    {
        if (root->data < data)
        {
            // left
            root->left = addNode(root->left, data); // NULL,80
        }
        else
        {
            // right
            root->right = addNode(root->right, data); // 70,80
        }
    }
    return root;
}

int main()
{
    Node *root = NULL;
    root = addNode(root, 60);
    addNode(root, 70); // 60,70
    addNode(root, 80); // 60 , 80
    return 0;
}
