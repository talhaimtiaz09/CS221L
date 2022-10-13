#include <iostream>
using namespace std;

void input(int *ptr)
{
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter " << i << "th element: ";
        cin >> *(ptr + i);
    }
}
void printReverse(int *ptr, int size)
{
    cout << endl;
    for (int i = size - 1; i >= 0; i--)
    {
        cout << *(ptr + i) << " ";
    }
    cout << endl;
}
int main()
{
    int sz;
    cout << "Please enter the size of Arr: ";
    cin >> sz;
    int *arr = new int[sz];
    input(arr);
    printReverse(arr, sz);
    delete [] arr;
    arr=NULL;

    return 0;
}