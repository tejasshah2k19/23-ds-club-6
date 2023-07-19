#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int f = -1;
int r = -1;

void insert(int num)
{
    if (r == SIZE - 1)
    {
        printf("\nQueue is Full");
    }
    else
    {
        r++;
        queue[r] = num;
        if (f == -1)
        {
            f = 0;
        }
    }
}

void remove1()
{

    if (f == -1)
    {
        printf("\nQueue is Empty...");
    }
    else
    {
        printf("\n%d deleted", queue[f]);
        if (f == r)
        {
            f = -1;
            r = -1; // empty
        }
        else
        {
            f++;
        }
    }
}

void display()
{
    int i;
    for (i = f; i <= r; i++)
    {
        printf("  %d", queue[i]);
    }
}

int main()
{
    int choice;
    int num;

    while (1)
    {
        printf("\n1 For Insert\n2 for Delete\n3 For Display\n0 Exit\nEnter Your Choice");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter number");
            scanf("%d", &num);
            insert(num);
            break;
        case 2:
            remove1();
            break;
        case 3:
            display();
            break;
        case 0:
            exit(0);

        default:
            printf("\nInvalid choice PTA");
            break;
        } // switch
    }     // while

    return 0;
}