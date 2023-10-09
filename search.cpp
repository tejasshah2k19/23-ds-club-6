#include <iostream>
using namespace std;

void linearSearch()

{
    int a[5] = {1,
                33,
                44,
                55,
                66};

    int search = 55;
    int flag = 0;
    for (int i = 0; i < 5; i++)
    {
        if (a[i] == search)
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
        cout << "\n Data Found";
    else
        cout << "\nNot Found";
}

void binarySearch()
{
    // array must be sorted -> prior condition
    // 10 20 30 40 50
    // search 10

    // 10 20 30 40 50
    // min         max
    // 0           4
    // mid = min+max/2;
    // mid = 2 => value 30
    int a[] = {10, 20, 30, 40, 50};
    int search = 10;
    int flag = 0;
    int min = 0, max = 4; // SIZE-1
    int mid;

    // logic
    while (min <= max)
    {

        mid = (min + max) / 2;
        if (a[mid] == search)
        {
            flag = 1;
            break;
        }
        else if (search < a[mid])
        {
            // left
            max = mid - 1;
        }
        else
        {
            // right
            min = mid + 1;
        }
    }

    if (flag == 1)
        cout << "\n found at " << mid + 1;
    else
        cout << "\n Not found";
}
int main()
{
    binarySearch();
    return 0;
}