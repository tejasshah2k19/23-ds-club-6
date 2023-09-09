#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

char stack[SIZE];
char str[SIZE];
int top = -1; // empty

int push(char c)
{
    if (top == SIZE - 1)
    {
        printf("\nStack OVERFLOW  - MAX SIZE %d", SIZE); // sdjflkjdsdklfslkfslddsjfkljsdf
        top = -1;                                        // sdjfklsdjflksdflksdflksjdf
        return 0;                                        // false
    }
    else
    {
        top++;
        stack[top] = c;
        return 1; // true
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
char peek()
{
    return stack[top];
}
int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int validator()
{
    char str[23];
    int i;
    char tmp;
    printf("\nEnter string");
    gets(str);

    for (i = 0; str[i] != '\0'; i++)
    {

        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
        {
            push(str[i]);
        }
        else
        {
            tmp = peek();
            if (str[i] == '}' && tmp == '{')
            {
                pop();
            }
            else if (str[i] == ')' && tmp == '(')
            {
                pop();
            }
            else if (str[i] == ']' && tmp == '[')
            {
                pop();
            }
            else
            {
                return -1;
            }
        }
    } //(()

    if (isEmpty() == 1)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int ans = validator();
    if (ans == 1)
    {
        printf("Valid");
    }
    else
    {
        printf("Invalid");
    }
    return 0;
}