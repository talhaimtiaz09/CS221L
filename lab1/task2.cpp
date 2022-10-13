#include <iostream>
using namespace std;

int sum(int *ptr)
{
    int _sum = 0;
    for (int i = 0; i < 5; i++)
    {
        _sum += *(ptr + i);
    }
    return _sum;
}

void input(int *ptr)
{
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter " << i << "th element: ";
        cin >> *(ptr + i);
    }
}
int main()
{
    int arr[5];
    input(arr);
    cout << "\nSum: " << sum(arr) << endl;

    return 0;
}