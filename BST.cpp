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
        if (root->data > data)
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

void inOrder(Node *root) // 60
{
    if (root != NULL)
    {
        inOrder(root->left);       // left  inOrder(50)
        printf(" %d", root->data); // root
        inOrder(root->right);      // right
    }
}

// pre ->  root left  right
// post -> left right root
// in   -> left root  right

void preOrder(Node *root) // 60
{
    if (root != NULL)
    {
        printf(" %d", root->data); // root
        preOrder(root->left);      // left  inOrder(50)
        preOrder(root->right);     // right
    }
}
int search(Node *root, int key)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->data == key)
    {
        // logic delete
        return 1;
    }
    else if (root->data > key)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}
int main()
{
    Node *root = NULL;
    root = addNode(root, 60);
    addNode(root, 70); // 60,70
    addNode(root, 80); // 60 , 80
    addNode(root, 50);

    inOrder(root); // 60

    search(root, 40); // no present
    search(root, 80); // present

    return 0;
}
