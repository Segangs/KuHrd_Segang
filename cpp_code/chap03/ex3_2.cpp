#include <iostream>
using namespace std;

// 선언부
class Rectangle
{
public:
    int width;
    int height;

    int getArea();

    Rectangle();
    Rectangle(int w);
    Rectangle(int w, int h);
};

// 생성자
Rectangle::Rectangle()
{
    width = 3;
    height = 5;
    cout << width << ", " << height << endl;
}

Rectangle::Rectangle(int w)
{
    width = w;
    height = 5;
    cout << width << ", " << height << endl;
}

Rectangle::Rectangle(int w, int h)
{
    width = w;
    height = h;
    cout << width << ", " << height << endl;
}

int main()
{

    Rectangle rect;
    double area = rect.getArea();
    cout << "사각형의 면적은 " << area << endl;

    Rectangle rect2(10);
    area = rect2.getArea();
    cout << "사각형의 면적은 " << area << endl;

    Rectangle rect3(20, 20);
    area = rect3.getArea();
    cout << "사각형의 면적은 " << area << endl;

    // area = rect2.getArea();

    // rect.width = 3;
    // rect.height = 5;
    // cout << "사각형의 면적은 " << rect.getArea() << endl;

    // Rectangle rect2(10);
    // rect2.height = 20;
    // cout << "사각형의 면적은 " << rect2.getArea() << endl;

    // Rectangle rect3(20, 20);

    return 0;
}

// 구현부
int Rectangle::getArea()
{
    return width * height;
}