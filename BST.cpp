#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
};

Node *addNode(Node *root, int data) //  NULL,65
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
            // 70->left  = addNode(Null,65)  [65]
        }
        else
        {
            // right
            root->right = addNode(root->right, data); // 70,80
            // 60->right = addNode(70,65)
        }
    }
    return root; // parent-> root
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

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
    {
        return root; // NULL
    }

    if (root->data == key)
    {
        // 70:root
        if (root->left != NULL && root->right != NULL)
        {
            // 2 child
            cout << "\n2 Child";
            //
        }
        else if (root->left == NULL && root->right == NULL)
        {
            // leaf - o child

            cout << "\n0 Child";
            return NULL;
        }
        else
        {
            // 1 child
            cout << "\n1 Child";
            if (root->right != NULL)
            {
                return root->right;
            }
            else
            {
                return root->left;
            }
        }
        // delete
        // leaf node
        // return NULL;
        return root;
    }
    else if (root->data > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (root->data < key)
    {
        root->right = deleteNode(root->right, key);
    }
    return root;
}
int main()
{
    Node *root = NULL;
    root = addNode(root, 60);
    addNode(root, 70); // 60,70
    addNode(root, 80); // 60 , 80
    addNode(root, 50);

    // inOrder(root); // 60

    // search(root, 40); // no present
    // search(root, 80); // present
    deleteNode(root, 80);
    deleteNode(root, 70);
    deleteNode(root, 60);
    deleteNode(root, 50);
    return 0;
}
