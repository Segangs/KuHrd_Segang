#include <iostream>
using namespace std;

int add(int a[], int b);
int add(int c[], int d, int e);


int main() {
    int a[] = {1,2,3,4,5};
    int b[] = {7,8,9,10,11};
    int c = add(a,5);
    int d = add(b,4,c);
    cout << c << endl;
    cout << d << endl;

    return 0;
}

int add(int a[], int b)
{
    int sum = 0;
    for(int i = 0; i < b; i++)
    {
       sum = a[i] + sum;
    }
    return sum;
}

int add(int c[], int d, int e)
{
    int sum = 0;
    for(int i = 0; i < d; i++)
    {
       sum = c[i] + sum;
    }
    return sum + e;
}
