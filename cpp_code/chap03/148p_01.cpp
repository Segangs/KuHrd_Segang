#include <iostream>
#include <string>
using namespace std;

class Picture
{
public:
    int width;
    int height;
    string Place;

    int getWidth();
    int getHeight();
    string getPlace();

    Picture();
    Picture(int w, int h, string wPlace);
};

Picture::Picture()
{
    width = 5;
    height = 7;
    Place = "모름";
}

Picture::Picture(int w, int h, string wPlace)
{
    width = w;
    height = h;
    Place = wPlace;
}

int Picture::getWidth()
{
    return width;
}

int Picture::getHeight()
{
    return height;
}
string Picture::getPlace()
{
    return Place;
}

int main()
{
    Picture pic;
    Picture mt(10, 14, "한라산");
    cout << pic.getWidth() << "x" << pic.getHeight() << " " << pic.getPlace() << endl;
    cout << mt.getWidth() << "x" << mt.getHeight() << " " << mt.getPlace() << endl;
    return 0;
}