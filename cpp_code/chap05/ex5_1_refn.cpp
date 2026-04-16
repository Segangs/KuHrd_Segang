#include <iostream>
using namespace std;

class Circle
{
private:
    int radius;

public:
    Circle();
    Circle(int r);
    ~Circle();
    double getArea() { return 3.14 * radius * radius; }
    int getRadius() { return radius; }
    void setRadius(int radius) { this->radius = radius; }
};

Circle::Circle()
{
    radius = 1;
    cout << "생성자 실행 radius = " << radius << endl;
}

Circle::Circle(int radius)
{
    this->radius = radius;
    cout << "생성자 실행 radius = " << radius << endl;
}

Circle::~Circle()
{
    cout << "소멸자 실행 radius = " << radius << endl;
}

void increase(Circle &c)   //참조 변수로 사용.  값의의한참조로 사용하고, 인자값만 &로 변경하면 된다.
{
    int r = c.getRadius();
    c.setRadius(r + 1);
}

int main()
{
    Circle waffle(30);
    increase(waffle);
    cout << waffle.getRadius() << endl;
    return 0;
}