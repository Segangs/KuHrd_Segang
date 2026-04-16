#include <iostream>
#include <string>
using namespace std;

class Account
{
public:
    int total = 0;
    string ownername;

    string getOwner();
    int inquiry();
    void deposit(int dp);
    int withdraw(int wd);

    Account(string acc);
};

Account::Account(string acc)
{
    ownername = acc;
}

void Account::deposit(int dp)
{
    total += dp;
}

int Account::withdraw(int wd)
{
    if(total > wd){
    total -= wd;
    }
    else{
    wd = total;
    total = 0;
    }

    return wd;
}

string Account::getOwner()
{
    return ownername;
}

int Account::inquiry()
{
    return total;
}

int main()
{
    Account a("황수희");
    a.deposit(20000);
    cout << a.getOwner() << "잔액은" << a.inquiry() << endl;

    int money = a.withdraw(15000);
    cout << money << "원 출금, ";
    cout << a.getOwner() << "잔액은" << a.inquiry() << endl;

    money = a.withdraw(8000);
    cout << money << "원 출금, ";
    cout << a.getOwner() << "잔액은" << a.inquiry() << endl;

    return 0;
}