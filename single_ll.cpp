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
    Node *p, *tmp, *q;
    int choice;
    int num, source;

    while (1)
    {

        cout << "\n0 For Exit\n1 For Add\n2 For List\n3 For InsertAtBeg\n4 for Delete Beg\n5 For Delete Last\n6 for insert any\nEnter choice";
        cin >> choice;
        switch (choice)
        {
        case 0:
            exit(0);
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
                tmp = new Node();
                tmp->setData(num);
                tmp->setNext(NULL);
                last->setNext(tmp);
                last = tmp;
            }
            break;

        case 2:
            p = head;

            while (p != NULL)
            {
                cout << p->getData() << " ";
                p = p->getNext();
            }
            break;
        case 3:
            cout << "\nEnter number";
            cin >> num;
            tmp = new Node();
            tmp->setData(num);
            tmp->setNext(head);
            head = tmp;
            break;
        case 4:
            p = head;
            head = head->getNext();
            delete p;
            break;
        case 5:
            p = head;
            while (p->getNext() != last)
            {
                p = p->getNext();
            }
            p->setNext(NULL);
            delete last;
            last = p;
            break;
        case 6:
            cout << "Enter number";
            cin >> num;
            cout << "Enter Node Data After which you want to add new data:";
            cin >> source;
            p = head;
            while (p != NULL)
            {
                if (p->getData() == source)
                {
                    break;
                }
                p = p->getNext();
            }
            if (p != NULL)
            {
                q = p->getNext();
                tmp = new Node();
                tmp->setData(num);
                p->setNext(tmp);
                tmp->setNext(q);
            }
            else
            {
                cout << endl
                     << "Invalid Source";
            }
            break;
        } // switch
    }     // while
    return 0;
}