#include <iostream>

using namespace std;

int main()
{
    int *p;
    int totalElelement;

    cout << "How many elemements you want to store?";
    cin >> totalElelement;

    p = new int(totalElelement);

    for (int i = 0; i < totalElelement; i++)
    {
        cout << endl
             << "Enter Value";
        cin >> p[i];
    }

    cout << endl
         << "Values in array" << endl;
    for (int i = 0; i < totalElelement; i++)
    {
        cout << endl
             << p[i];
    }
    delete p;
}