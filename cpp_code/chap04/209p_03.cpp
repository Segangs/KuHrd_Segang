#include <iostream>
#include <string>
using namespace std;

int main()
{
    string txt;
    string txts;

    cout << "텍스트 입력 :";
    getline(cin, txt, '\n');

    int size = txt.size();

    for (int i = 0; i < size; i++)
    {
        if ((txt[i] == ' ') && (txt[i + 1] == ' '))
            txt[i] = txt[i + 1];

        cout << txt[i];
    }

    //cout << txt << endl;
    return 0;
}