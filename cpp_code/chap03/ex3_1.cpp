#include <iostream>
using namespace std;

// 선언부
class Circle
{
    private:
    int radius;

    public:
    double getArea();
    int read_radius();
    void write_radius(int r);
};   // 클래스 선언에서 세미콜론 빼먹지 않도록 주의!

//구현부
double Circle::getArea()
{
    return 3.14*radius*radius;
}

int Circle::read_radius()
{
    return radius;
}

void Circle::write_radius(int r)
{
    radius = r;
}

int main()
{
    Circle donut;
    donut.Wriradius = 1;
    
    double area = donut.getArea();
    cout << "donut 면적은 " << area << endl;


    Circle pizza;
    pizza.radius = 30;
    area = pizza.getArea();
    cout << "pizza 면적은 " << area << endl;
    
    return 0;
}