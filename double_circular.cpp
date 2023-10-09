#include <iostream>

using namespace std;

class Node
{
private:
    int data;
    Node *next;
    Node *prev;

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
    void setPrev(Node *n)
    {
        prev = n;
    }

    Node *getPrev()
    {
        return prev;
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

        std::cout << "\nEnter choice ";
        std::cin >> choice;
        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            std::cout << "Enter number";
            std::cin >> num;
            if (head == NULL)
            {

                head = new Node();
                head->setData(num);
                head->setNext(head);
                head->setPrev(NULL);
                last = head;
            }
            else
            {
                tmp = new Node();
                tmp->setData(num);
                tmp->setNext(head);
                tmp->setPrev(last);
                last->setNext(tmp);
                last = tmp;
            }
            break;

        case 2:
            p = head;

            do
            {
                cout << p->getData() << " ";
                p = p->getNext();
            } while (p != head);
            break;

        } // switch
    }     // while
    return 0;
}

// swap
//  enter source1 number
//   20
//  enter source2 number
//   40
