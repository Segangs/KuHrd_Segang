#include <iostream>
using namespace std;

bool compare(int a, int b, int &mini, int &maxi)
{
    if (a == b)
        return true;
    if (a < b)
    {
        mini = a;
        maxi = b;
        return false;
    }
    else
    {
        mini = b;
        maxi = a;
        return false;
    }
}

int main()
{
    int a, b, min, max;
    cout << "두 수 입력";
    cin >> a >> b;

    bool res = compare(a, b, min, max);
    if (res == true)
        cout << " 두 수는 같습니다.";
    else
        cout << " 작은 수는 " << min << " , 큰수는" << max;

    return 0;
}