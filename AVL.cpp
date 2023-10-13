#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height; // avl
};

Node *createNode(int num)
{
    Node *node = new Node();
    node->data = num;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}
int calculateHeight(Node *root)
{
    int leftH = 0;
    int rightH = 0;

    if (root->left != NULL)
    {
        leftH = root->left->height;
    }
    if (root->right != NULL)
    {
        rightH = root->right->height;
    }

    return leftH > rightH ? leftH : rightH;
}

int calculateBalanceFactor(Node *root)
{
    int leftH = 0;
    int rightH = 0;

    if (root->left != NULL)
    {
        leftH = root->left->height;
    }

    if (root->right != NULL)
    {
        rightH = root->right->height;
    }
    return leftH - rightH;
}
Node *addNode(Node *root, int num) // 50,70
{
    if (root == NULL)
    {
        root = createNode(num);
        return root;
    }
    else if (num > root->data)
    {
        // right
        root->right = addNode(root->right, num);
    }
    else if (num < root->data)
    {
        // left
        root->left = addNode(root->left, num);
    }
    else
    {
        // no insertion
        return root;
    }

    // height
    root->height = 1 + calculateHeight(root);

    // balance factor
    int bf = calculateBalanceFactor(root);

    // tree imbalance
    if (!(bf >= -1 && bf <= 1))
    {
        if (bf < 0)
        {
            cout << " R Imbalance => " << root->data << " => " << bf;
        }
        else
        {
            cout << " L Imbalance => " << root->data << " => " << bf;
        }
    }

    return root;
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data << "(" << root->height << ") ";
        inOrder(root->right);
    }
}
int main()
{

    Node *root = NULL;
    root = addNode(root, 50);
    root = addNode(root, 40);
    root = addNode(root, 30);

    cout << "\n";
    inOrder(root);

    return 0;
}