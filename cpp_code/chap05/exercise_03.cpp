#include <iostream>
using namespace std;


class Bubble
{
    int radius;

public:
    Bubble(int radius) { this->radius = radius; }
    int getRadius() { return radius; };
    void setRadius(int n) { radius = n; }
};

void addBubble(Bubble *c, Bubble *a, Bubble *b)
{
    int sum = a->getRadius() + b->getRadius();
    c->setRadius(sum);
}


int main()
{
    Bubble a(50), b(25), c(130);
    addBubble(&c, &a, &b);
    cout << "버블 C의 반지름" << c.getRadius() << endl;
    return 0;
}
