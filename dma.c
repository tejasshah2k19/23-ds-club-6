#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *p;
    p = (int *)malloc(4); // 1 block
    free(p);

    p = (int *)calloc(5, 4); // 4byte -> 5 block -> array
    free(p);

    return 0;
}