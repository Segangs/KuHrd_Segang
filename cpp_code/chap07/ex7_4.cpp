// 연산자 오버로딩

#include <iostream>
using namespace std;

class Power
{
private:
    int kick;
    int punch;

public:
    void show();
    Power(int kick = 0, int punch = 0);
    friend Power operator+(int op1, Power op2);

    Power operator+(Power op2);
    bool operator==(Power op2);
    Power &operator+=(Power op2);
};

Power ::Power(int kick, int punch)
{
    this->kick = kick;
    this->punch = punch;
}

void Power::show()
{
    cout << "kick = " << kick << ',' << "punch =" << punch << endl;
}

Power Power::operator+(Power op2)
{
    Power tmp;
    tmp.kick = this->kick + op2.kick;
    tmp.punch = this->punch + op2.punch;
    return tmp;
}

bool Power::operator==(Power op2)
{
    if ((kick == op2.kick) && (punch == op2.punch))
        return true;
    else
        return false;
}

Power &Power::operator+=(Power op2)
{
    this->kick = this->kick + op2.kick;
    this->punch = this->punch + op2.punch;
    return *this;
}

// 359p 프렌드를 이용한 연산자 중복 2+a실습. 일반 사용자 함수
Power operator+(int op1, Power op2)
{
    Power tmp;
    tmp.kick =op1 + op2.kick;
    tmp.punch = op1 + op2.punch;
    return tmp;
}

int main()
{
    Power a(3.5), b(4.6), c;
    a.show();
    b.show();
    c.show();
    c = a + b;

    b = 2 + a;
    b.show();

    return 0;
}