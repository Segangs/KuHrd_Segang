#include <iostream>
using namespace std;

void twice(int *num)
{
    *num = (*num * 2);
}

int main()
{
    int a = 128;
    int *n = &a;
   
    twice(n);
    cout << *n;

    return 0;
}