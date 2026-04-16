#include <iostream>
using namespace std;

class Rectangle
{
public:
    int width, height;
    Rectangle();
    Rectangle(int w, int h);
    Rectangle(int length);

    // 복사 생성자
    Rectangle(const Rectangle &c);
    Rectangle(const Rectangle &d, const Rectangle &e);

    bool isSquare();
};

Rectangle::Rectangle()
{
    width = height = 1;
}

Rectangle::Rectangle(int w, int h)
{
    width = w;
    height = h;
}

Rectangle::Rectangle(int length)
{
    width = height = length;
}

// 복사 생성자

Rectangle::Rectangle(const Rectangle &c)
{
    this->width = this->height = c;
}

Rectangle::Rectangle(const Rectangle &d, const Rectangle &e)
{
    this->width = d.width;
    this->height = e.width;
}



bool Rectangle::isSquare()
{
    if (width == height)
        return true;
    else
        return false;
}

int main()
{
    Rectangle rect1;
    Rectangle rect2(3, 5);
    Rectangle rect3(3);

    Rectangle copy(rect1);
    Rectangle copy2(rect2);
    Rectangle copy3(rect3);

    if (rect1.isSquare())
        cout << "rect1은 정사각형이다" << endl;
    if (rect2.isSquare())
        cout << "rect2은 정사각형이다" << endl;
    if (rect3.isSquare())
        cout << "rect3은 정사각형이다" << endl;

    if (copy2.isSquare())
        cout << "(복사)rect2은 정사각형이다" << endl;
    if (copy3.isSquare())
        cout << "(복사)rect3은 정사각형이다" << endl;

    return 0;
}