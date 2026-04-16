#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char password[11];
    char address[100];
    cout << "암호를 입력하쇼" << endl;

    while (true)
    {
        cout << "암호 : ";
        cin >> password;
        if (strcmp(password, "C++") == 0)
        {
            cout << "통과. 주소를 입력하쇼" << endl;
            cin.getline(address, 100, '\n');
            cout << "주소: " << address << endl;
        }
        else
            cout << "틀렸습니다" << endl;
    }

    return 0;
}