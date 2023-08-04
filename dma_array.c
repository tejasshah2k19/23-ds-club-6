#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *arr;
    int totalElement;
    int i;

    printf("\nHow many Elements You want to store?");
    scanf("%d", &totalElement); // 5 { 11 22 33 44 55 }

    arr = (int *)malloc(totalElement * sizeof(int)); // 5 byte

    if (arr == NULL)
    {
        printf("\nSMW Please TAG");
    }
    else
    {
        for (i = 0; i < totalElement; i++)
        {
            printf("\nEnter value");
            scanf("%d", &arr[i]);
        }
        printf("\nValues in Array\n");
        for (i = 0; i < totalElement; i++)
        {
            printf("\n%d", arr[i]);
        }
        free(arr);
    }

    return 0;
}