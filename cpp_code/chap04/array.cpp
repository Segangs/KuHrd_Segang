#include <iostream>
using namespace std;

class myArray
{
    public:
    int *p;
    int aryLen;
    int sum = 0;

    myArray this_point() { return this; }
    void print();

    myArray();
    myArray(int num);
    ~myArray();
};

void myArray::print()
{
    for (int i = 0; i < aryLen; i++)
    {
        // cout << p[i] << "  ";
        cout << *(p + i) << "  ";
    }
    cout << endl;
}

myArray::myArray()
{
    for (int i = 0; i < aryLen; i++)
    {
        sum = sum + p[i];
    }
    cout << sum << endl;
}

myArray::myArray(int num)
{
    int aryLen = num;
    p = new int[num];
    for (int i = 0; i < num; i++)
        p[i] = i;
}

myArray::~myArray()
{
    delete[] p; // 소멸자 내에서 동적할당 메모리 반환!
}

int main()
{
    myArray test[3] = {myArray(3), myArray(9), myArray(4)};

    myArray* p = test[0].this_point();

    p->this_point;

    // int val = 1;
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < test[i].aryLen; j++)
    //     {
    //         test[i].p[j] = val++;
    //         cout << test[i].p[j] << endl;
    //     }
    // }

    // for (int i = 0; i < 3; i++)
    // {d
    //     test.p[i] = (i + 1) * 10;
    // }

    // a.print();

    return 0;
}