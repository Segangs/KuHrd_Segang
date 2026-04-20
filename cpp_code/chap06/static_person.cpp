// static 실습

#include <iostream>
using namespace std;

class Person
{
private:
public:
    int money;

    void addMoney(int money);

    static int shareMoney; // 클래스 틀을 만들때부터 있어야 함. 객체가 생성될 때 생김
    static void addShared(int n);

    Person();
    ~Person();
};

void Person::addMoney(int money)
{
    this->money += money;
}

int Person::shareMoney = 10; // main함수 들어가기 전에 생성됨. static 전역 변수. 맨 앞 static text는 지워줘야 함.

void Person::addShared(int n)
{
    shareMoney = shareMoney + n;
    // this를 쓰지 못한다. :
}

Person::Person() {}

Person::~Person() {}

int main(void)
{
    Person::shareMoney = 20; // Public으로 되어있으면 main에서 이렇게 넣어줄수도 있다.

    cout << Person::shareMoney << endl;

    Person han;
    han.money = 100;
    han.shareMoney = 200;

    Person lee;
    lee.money = 150;
    lee.addMoney(200);
    lee.addShared(200);

    cout << han.money << endl;
    cout << han.shareMoney << endl;
    cout << lee.money << endl;
    cout << lee.shareMoney << endl;

    return 0;
}