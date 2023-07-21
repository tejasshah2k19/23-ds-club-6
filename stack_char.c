#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

char stack[SIZE];
char str[SIZE];
int top = -1; // empty

void push(char c)
{
    if (top == SIZE - 1)
    {
        printf("\nStack OVERFLOW  - MAX SIZE %d", SIZE); // sdjflkjdsdklfslkfslddsjfkljsdf
    }
    else
    {
        top++;
        stack[top] = c;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("\nStack Is Empty");
    }
    else
    {
        printf("%c", stack[top]);
        top--;
    }
}
void display()
{
    int i;
    if (top == -1)
    {
        printf("\nStack Is Empty");
    }
    else
    {
        for (i = top; i >= 0; i--)
        {
            printf("%c", stack[i]);
        }
    }
}

int main()
{
    int choice, i;
    while (1)
    {
        printf("\n1 For PUSH\n2 For POP\n3 For Display\n0 For Exit\nEnter Your Choice");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter String::");
            fflush(stdin);
            gets(str); // royal

            for (i = 0; str[i] != '\0'; i++)
            {
                push(str[i]); // 0:r  1:o  2:y  3:a  4:l  5:X
            }
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 0:
            exit(0);
        default:
            break;
        }
    }

    return 0;
}