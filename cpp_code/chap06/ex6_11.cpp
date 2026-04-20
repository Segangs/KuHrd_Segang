//static  멤버를 공유의 목적으로 사용하는 예

#include <iostream>
using namespace std;

class Circle
{
private:
    static int numOfCircles;
    int radius;

public:
    double getArea(void);

    static int getNumOfCircles();

    Circle(int r = 1); // 디폴트 매개변수를 줬다.
    ~Circle();
};

int Circle::numOfCircles = 0;

double Circle::getArea(void) // static
{
    return 3.14 * this->radius * this->radius;
}

int Circle::getNumOfCircles() // static
{
    return numOfCircles; // this를 써주지 못한다.
}

Circle::Circle(int r)
{
    this->radius = r;
    numOfCircles++;
}

Circle::~Circle()
{
    numOfCircles;
}

int main(void)
{
    Circle *p = new Circle[10]; // 배열 동적 할당
    cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;

    delete[] p; // 10개 소멸자 실행
    cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;

    Circle a; // 생성자 실행
    cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;

    Circle b; // 생성자 실행
    cout << "생존하고 있는 원의 개수 = " << Circle::getNumOfCircles() << endl;

    return 0;
}