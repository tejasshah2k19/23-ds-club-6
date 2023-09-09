#include <stdio.h>
#define SIZE 9

int main()
{

    int a[] = {11,
               2,
               44,
               5,
               89, 66,
               34,
               88,
               3};
    int i, j, key;

    printf("\nElements In the Array\n");
    for (i = 0; i < SIZE; i++)
    {
        printf(" %d", a[i]);
    }

    // for array scan
    // for array print - before sort
    for (i = 1; i < SIZE; i++)
    {
        key = a[i]; // 5
        for (j = i - 1; j >= 0; j--)
        {
            if (key < a[j])
            {
                a[j + 1] = a[j];
            }
            else
            {
                break;
            }
        }
        a[j + 1] = key;
    }

    // for array print -after sort
    printf("\nElements In the Array\n");
    for (i = 0; i < SIZE; i++)
    {
        printf(" %d", a[i]);
    }
    return 0;
}