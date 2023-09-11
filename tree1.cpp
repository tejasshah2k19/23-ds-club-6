#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
};

int main()
{

    Node *root = NULL;

    root = new Node();
    root->data = 30;
    root->left = NULL;
    root->right = NULL;

    Node *t1 = new Node();
    t1->data = 50;
    t1->left = NULL;
    t1->right = NULL;
    root->left = t1;

    Node *t2 = new Node();
    t2->data = 60;
    t2->left = NULL;
    t2->right = NULL;
    root->right = t2;

    cout << root->data << endl
         << root->left->data << endl
         << root->right->data;
    return 0;
}
