#include <iostream>
using namespace std;

double *p = new double[5];

int main()
{
    cout << "온도 5개 입력 >> ";

    for (int i = 0; i < 5; i++)
    {
        cin >> p[i];
    }

    double sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum = sum + p[i];
    }

    cout << "평균은 " << (sum / 5) << endl;
    return 0;
}