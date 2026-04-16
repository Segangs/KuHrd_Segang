#include <iostream>
using namespace std;

int main()
{
    char firstname[10]={};
    char secondname[20]={}; 
    char fs_name[50]={};

    int i = 0;
    int j = 0;

    cout << "첫번째 이름 입력 : ";
    cin >> firstname;
    cout << "두번째 이름 입력 : ";
    cin >> secondname;

    while (firstname[i] != '\0')
    {
        fs_name[i] = firstname[i];
        i++;
    }

    while (secondname[j] != '\0')
    {
        fs_name[i+j] = secondname[j];
        j++;
    }

    cout << fs_name <<endl;
}