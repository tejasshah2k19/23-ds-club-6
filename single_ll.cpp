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
    Node *head = NULL;
    Node *last = NULL;

    int choice;
    int num;
    while (1)
    {

        cout << "\n0 For Exit\n1 For Add\n2 For List\nEnter choice";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter number";
            cin >> num;
            if (head == NULL)
            {
                head = new Node();
                head->setData(num);
                head->setNext(NULL);
                last = head;
            }
            else
            {
                Node *tmp = new Node();
                tmp->setData(num);
                tmp->setNext(NULL);
                last->setNext(tmp);
                last = tmp;
            }
            break;
        }
    }
    return 0;
}