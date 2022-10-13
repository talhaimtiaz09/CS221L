#include <iostream>
using namespace std;
void swap(int *ptr1, int *ptr2)
{  
    *(ptr1) += *(ptr2);
    *(ptr2) = *(ptr1) - *(ptr2);
    *(ptr1) -= *(ptr2);
}
int main()
{
    int a = 5, b = 3;
    cout<<"Before swap: a="<<a<<" b="<<b<<endl;
    swap(&a,&b);
    cout<<"After swap: a="<<a<<" b="<<b<<endl;

    return 0;
}