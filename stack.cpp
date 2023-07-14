#include <iostream>
#define SIZE 5

using namespace std;

class Stack
{
    int s[SIZE];
    int top;

public:
    Stack()
    {
        top = -1; // EMPTY
    }

    void push(int num)
    {
        if (top == SIZE - 1)
        {
            cout << "\nSTACK OVERFLOW";
        }
        else
        {
            top++;
            s[top] = num;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "\nSTACK UNDERFLOW";
        }
        else
        {
            cout << s[top] << " POP (deleted)";
            top--;
        }
    }

    void display()
    {
        int i;
        if (top == -1)
        {
            cout << "\nSTACK UNDERFLOW";
        }
        else
        {
            for (i = top; i >= 0; i--)
            {
                cout << endl
                     << s[i];
            }
        }
    }
};

int main()
{
    Stack stack;
    int choice, num;
    // condition -> true | false -> 1 2 3 -1 -3 any TRUE   { 0 FALSE }
    while (1)
    {
        cout << endl
             << "1 For PUSH\n2 For POP\n3 For Display\n0 Exit";
        cout << endl
             << "Enter your choice";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter Number";
            cin >> num;
            stack.push(num);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            stack.display();
            break;
        case 0:
            exit(0);
        default:
            cout << "\n*** INVALID CHOICE *** ";
        }
    }

    return 0;
}