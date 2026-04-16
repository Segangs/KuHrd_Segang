#include <iostream>
using namespace std;

class MyStack
{
    int *p;
    int size = 0;
    int tos = 0;

public:
    MyStack();
    MyStack(int size);
    MyStack(const MyStack &src);
    ~MyStack();
    bool push(int n);
    bool pop(int &n);
};

MyStack::MyStack()
{
    p = NULL;
    size = 0;
    tos = 0;
}

MyStack::MyStack(int size)
{
    this->p = new int[size];
    this->size = size;
}

bool MyStack::push(int n) // 9 까지 올라감
{
    if (size > (this->tos))
    {
        p[this->tos] = n;
        tos++;
        return true;
    }
    else
        return false;
}

bool MyStack::pop(int &n) //
{
    {
        if (0 < (this->tos))
        {
            tos--;
            n = p[this->tos];
            return true;
        }
        else
            return false;
    }
}

MyStack::MyStack(const MyStack &src)
{
    this->tos = src.tos;
    this->size = src.size;
    this->p = new int[this->size];
    for (int i = 0; i < this->size; i++)
    {
        this->p[i] = src.p[i];
    }
}

MyStack::~MyStack()
{
    if (p)
        delete[] p;
}

int main()
{
    MyStack a(10);
    a.push(10);
    a.push(20);
    a.push(30);
    a.push(40);
    a.push(50);

    MyStack b = a;
    b.push(70);
    int n;

    a.pop(n);
    cout << "스택 a에서 팝한 값" << n << endl;
    b.pop(n);
    cout << "스택 b에서 팝한 값" << n << endl;

    // MyStack st;
    // for (int i = 0; i < 11; i++)
    // {
    //     if (st.push(i))
    //         cout << i << ' ';
    //     else
    //         cout << endl
    //              << i + 1 << "번째 푸시 실패! 스택 차 있음" << endl;
    // }

    // int n;
    // for (int i = 0; i < 11; i++)
    // {
    //     if (st.pop(n))
    //         cout << n << ' ';
    //     else
    //         cout << endl
    //              << i + 1 << " 번째 팝 실패! 스택이 비어 있음" << endl;
    // }
    return 0;
}