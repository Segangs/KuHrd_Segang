#include <iostream>
using namespace std;

class MyStack
{
    int p[10] = {0};
    int tos = 0;

public:
    MyStack();
    bool push(int n);
    bool pop(int &n);
};

MyStack::MyStack()
{
}

bool MyStack::push(int n) // 9 까지 올라감
{
    if (10 > (this->tos))
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
            n =  p[(this->tos)-1];
            return true;
        }
        else
            return false;
    }
}

int main()
{
    MyStack st;
    for (int i = 0; i < 11; i++)
    {
        if (st.push(i))
            cout << i << ' ';
        else
            cout << endl
                 << i + 1 << "번째 푸시 실패! 스택 차 있음" << endl;
    }

    int n;
    for (int i = 0; i < 11; i++)
    {
        if (st.pop(n))
            cout << n << ' ';
        else
            cout << endl
                 << i + 1 << " 번째 팝 실패! 스택이 비어 있음" << endl;
    }
    return 0;
}