#include <iostream>
#include <string>
using namespace std;
string s;
string t;

int main()
{
    cout << "가위바위보 게임을 합니다. 가위바위보 중에서 입력하세요." << endl;
    cout << "로미오 : ";
    getline(cin, s);
    cout << "줄리엣 : " ;
    getline(cin, t);
    
    if(s == t)
    cout << "비겼습니다." << endl;

    if(s == "가위" && t == "보")
    cout << "로미엣이 이겼습니다." << endl;

    if(s == "가위" && t == "보")
    cout << "로미엣이 이겼습니다." << endl;
    

    return 0;
}