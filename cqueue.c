#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int cqueue[SIZE];
int f = -1, r = -1;

void insert(int num) // 10 20 30 40 50
{
    if (f == 0 && r == SIZE - 1)
    {
        printf("\nQueue is Full");
    }
    else if (r == f - 1)
    {
        printf("\nQueue is Full");
    }
    else
    {

        if (r == SIZE - 1)
        {
            r = 0; // cq
        }
        else
        {
            r++; // sq
        }
        cqueue[r] = num;
        if (f == -1)
        {
            f++;
        }
    }
}

void delete()
{
    if (f == -1)
    {
        printf("\nQueue is Empty");
    }
    else
    {

        // last element
        if (f == r)
        {
            printf("\n%d is deleted ", cqueue[f]);
            f = -1;
            r = -1;
        }
        else
        {
            printf("\n%d is deleted ", cqueue[f]);

            if (f == SIZE - 1)
            {

                // cq
                f = 0;
            }
            else
            {
                // sq
                f++;
            }
        }
    }
}

void display()
{
    int i;
    if (r < f)
    {
        // cq
        for (i = f; i < SIZE; i++)
        {
            printf("  %d", cqueue[i]);
        }
        for (i = 0; i <= r; i++)
        {
            printf("  %d", cqueue[i]);
        }
    }
    else
    {
        // sq
        for (int i = f; i <= r; i++)
        {
            printf("  %d", cqueue[i]);
        }
    }
}

int main()
{

    return 0;
}