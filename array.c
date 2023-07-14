#include <stdio.h>
#define SIZE 5

int array[SIZE];

void insert(int location, int data)
{
    int index = location - 1, i;
    if (index < 0 && index >= SIZE)
    {
        printf("\nInvalid Location PTA :: ");
    }
    else
    {
        for (i = SIZE - 1; i > index; i--)
        {
            array[i] = array[i - 1];
        }
        array[index] = data;
    }
}

void removeElement(int location)
{
    int index = location - 1;
    int i;
    for (i = index; i < SIZE - 1; i++)
    {
        array[i] = array[i + 1];
    }
    array[SIZE - 1] = 0;
}

void display()
{
    int i;
    printf("\nElements in the Array\n");
    for (i = 0; i < SIZE; i++)
    {
        printf(" %d", array[i]);
    }
}

int main()
{
    int choice;
    int location, data;
    while (1)
    {
        printf("\n1 For Add \n2 For Delete \n3 For Display\n0 For Exit\n\nEnter your choice");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("\nEnter Location and Data :: ");
            scanf("%d%d", &location, &data);
            insert(location, data);
            break;
        case 3:
            display();
            break;
        case 0:
            exit(0);

        default:
            printf("\nInvalid Choice PTA::");
        }
    }
    return 0;
}