#include <iostream>
using namespace std;

int main()
{
    char firstname[10] = {};
    char secondname[20] = {};
    char fs_name[50] = {};

    int temp = 0;

    cout << "첫번째 이름 입력 : ";
    cin >> firstname;
    cout << "두번째 이름 입력 : ";
    cin >> secondname;

    // for문 f_name 구현
    for (int i = 0; i < 10; i++)
    {
        if (firstname[i] != '\0')
            fs_name[i] = firstname[i];
        else
        {
            fs_name[i] = '\0';
            temp = i;
            break;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (secondname[i] != '\0')
            fs_name[i + temp] = secondname[i];
        else
        {
            fs_name[i + temp] = '\0';
            break;
        }
    }

    cout << fs_name << endl;
    return 0;
}