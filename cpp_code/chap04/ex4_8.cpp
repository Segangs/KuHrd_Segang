#include <iostream>
#include <string>
using namespace std;

void str_append(string str1, char *str2)
{
    return str1 + str2;
}

int main() {
    string str = "I LOVE";
    string str2 = "test";

    //str.append("C++");
    //str.append(str1);

    //cout << str.append("C++") << endl;
    //cout << str.append(str1) << endl;

    str_append(str, "C++");
    cout << str << endl;
   // cout << *str2 << endl;
    return 0;
}