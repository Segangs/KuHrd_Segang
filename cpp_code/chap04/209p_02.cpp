#include <iostream>
using namespace std;

int main()
{

    int ea = 0;
    
    cout << "구입할 물품의 개수 >> ";
    cin >> ea;
    int *p = new int[ea];

    cout << "물품" << ea << "개의 가격 입력 >> ";
    for (int i = 0; i < ea; i++)
    {
        cin >> p[i];
    }

    int min = p[0];
    int max = p[1];

    for (int i = 0; i < ea; i++)
    {
        if (min > p[i])
            min = p[i];

        if (max < p[i])
            max = p[i];
    }

    cout << "제일 싼 가격은 " << min << endl;
    cout << "제일 비싼 가격은 " << max << endl;

    return 0;
}