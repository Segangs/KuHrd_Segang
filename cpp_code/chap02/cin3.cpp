// 함수 만들기

#include <iostream>
#include <string>
using namespace std;

void my_strcat(const string str1, const string str2, string str3); // 1. 함수 선언

int main()
{
    string firstname;
    string lastname;
    string fullname;
    // char firstname[10] = {};
    // char secondname[20] = {};
    // char fs_name[50] = {};

    cout << "첫번째 이름 입력 : ";
    getline(cin, firstname);
    cout << "두번째 이름 입력 : ";
    getline(cin, lastname);

    my_strcat(firstname, lastname, fullname);
    cout << fullname << endl;


    // cout << "첫번째 이름 입력 : ";
    // cin >> firstname;
    // cout << "두번째 이름 입력 : ";
    // cin >> secondname;

    // my_strcat(firstname, secondname, fs_name);    // 3. 함수 호출
    // cout << fs_name << endl;

    return 0;
}

void my_strcat(const string str1, const string str2, string str3) // 2. 함수 구현
{

    // int temp = 0;

    // // for문 str1 구현
    // for (int i = 0; i < 10; i++)
    // {
    //     if (str1[i] != '\0')
    //         str3[i] = str1[i];
    //     else
    //     {
    //         str3[i] = '\0';
    //         temp = i;
    //         break;
    //     }
    // }

    // for (int i = 0; i < 10; i++)
    // {
    //     if (str2[i] != '\0')
    //         str3[i + temp] = str2[i];
    //     else
    //     {
    //         str3[i + temp] = '\0';
    //         break;
    //     }
    // }
}