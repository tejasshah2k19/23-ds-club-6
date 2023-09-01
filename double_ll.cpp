#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
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

        cout << "\n0 For Exit\n1 For Add\n2 For List\n3 For InsertAtBeg\n4 for Delete Beg\n5 For Delete Last\n6 for insert any\n7 for delete any\n8 For Reverse Display\nEnter choice";
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
                head->data = num;
                head->next = NULL;
                head->prev = NULL;
                last = head;
            }
            else
            {
                tmp = new Node();
                tmp->data = num;
                tmp->next = NULL;
                tmp->prev = last;
                last->next = tmp;
                last = tmp;
            }
            break;

        case 2:
            p = head;

            while (p != NULL)
            {
                cout << p->data << " ";
                p = p->next;
            }
            break;
        case 3:
            cout << "\nEnter number";
            cin >> num;
            tmp = new Node();
            tmp->data = num;
            tmp->next = head;
            head->prev = tmp;
            tmp->prev = NULL;
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
                q = p->getNext(); // null
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
        case 7:
            cout << "Enter num that you want to delete";
            cin >> num;
            p = head;
            while (p != NULL)
            {
                if (p->getData() == num)
                {
                    break;
                }
                p = p->getNext();
            }

            if (p == NULL)
            {
                cout << "\nInvalid Number";
            }
            else
            {
                tmp = p->getNext();
                q = head;
                while (q->getNext() != p)
                {
                    q = q->getNext();
                }
                q->setNext(tmp);
                delete p;
            }
            break;
        } // switch
    }     // while
    return 0;
}