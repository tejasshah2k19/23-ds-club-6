#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *next;

public:
    void setData(int x)
    {
        data = x;
    }
    void setNext(Node *n)
    {
        next = n;
    }
    int getData()
    {
        return data;
    }
    Node *getNext()
    {
        return next;
    }
};

int main()
{

    Node *head = new Node();
    head->setData(100);
    head->setNext(NULL);

    Node *tmp = new Node();
    tmp->setData(500);
    tmp->setNext(NULL);

    head->setNext(tmp);

    cout << head->getData();
    cout << endl
         << head->getNext()->getData();
    return 0;
}