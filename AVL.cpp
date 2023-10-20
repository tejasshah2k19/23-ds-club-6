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

Node *rightRotate(Node *root)
{
    // root->50
    Node *left = root->left;       // 40
    Node *leftRight = left->right; // 45

    root->left = leftRight; // 45 | NULL
    left->right = root;     // 40->right = 50

    // 40
    // 50
    root->height = 1 + calculateHeight(root);
    left->height = 1 + calculateHeight(left);
    return left; // 40
}
Node *leftRotate(Node *root) // root->60
{
    Node *right = root->right; // 70
    root->right = right->left; // 65
    right->left = root;

    root->height = 1 + calculateHeight(root);
    right->height = 1 + calculateHeight(right);

    return right;
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
        if (bf < 0) // R
        {
            if (num < root->right->data)
            {
                cout << " RL Imbalance => " << root->data << " => " << bf;
                root->right = rightRotate(root->right);
                return leftRotate(root);
            }
            else
            {
                {
                    cout << " RR Imbalance => " << root->data << " => " << bf;
                    return leftRotate(root);
                }
            }
        }
        else // L
        {
            if (num < root->left->data)
            {
                cout << " LL Imbalance => " << root->data << " => " << bf;
                return rightRotate(root); // 50 => 40
            }
            else
            {
                cout << " LR Imbalance => " << root->data << " => " << bf;
                root->left = leftRotate(root->left);
                return rightRotate(root);
            }
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
    // LL
    //  root = addNode(root, 50);
    //  root = addNode(root, 40);
    //  root = addNode(root, 30);

    // RR
    //  root = addNode(root, 50);
    //  root = addNode(root, 60);
    //  root = addNode(root, 70);

    // RL
    //  root = addNode(root, 50);
    //  root = addNode(root, 60);
    //  root = addNode(root, 55);

    // LR
    //  root = addNode(root, 50);
    //  root = addNode(root, 10);
    //  root = addNode(root, 20);

    // 50 100 40 30 45 20
    cout << "\n";
    inOrder(root);

    return 0;
}