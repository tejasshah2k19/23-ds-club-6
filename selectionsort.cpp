#include <iostream>

int main()
{

    int arr[5] = {11, 22, 3, 4, 24};

    for (int i = 0; i < 5 - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < 5; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }

    return 0;
}