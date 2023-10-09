#include <iostream>
using namespace std;

int main()
{
    int a[5] = {10, 20, 30, 40, 50};
    int b[5] = {11, 22, 25, 45, 55};
    int c[10];
    int i, j, k;

    i = 0;
    j = 0;
    k = 0;

    while (i < 5 && j < 5)
    {
        if (a[i] < b[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else
        {
            c[k++] = b[j++];
        }
    }
    while (i < 5)
    {
        c[k++] = a[i++];
    }

    while (j < 5)
    {
        c[k++] = b[j++];
    }
    return 0;
}