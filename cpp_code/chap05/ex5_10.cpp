//Circle 클래스의 복사 생성자와 객체 복사

#include <iostream>
using namespace std;

class Circle
{
    int radius;

public:
    Circle() { radius = 1; }
    Circle(int r) { radius = r; }
    Circle(const Circle &c);  //복사 생성자 함수. 


    void setRadius(int r) { radius = r; }
    double getArea();
};

double Circle::getArea()
{
    return 3.14 * radius * radius;
}

Circle::Circle(const Circle &c)
{
    this->radius = c.radius;
    cout << "복사 생성자 실행  radius = " << radius << endl;
}

int main()
{
    Circle src(30);
    Circle dest(src); // 객체안에 객체를 넣어줄 수 있다. (복사 생성자)

    cout << "원본의 면적 = " << src.getArea() << endl;
    cout << "사본의 면적 = " << dest.getArea() << endl;

    return 0;
}