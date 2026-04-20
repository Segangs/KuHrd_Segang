#include <iostream>
using namespace std;

class Coffee
{
private:
    int water, espresso, sugar, cream;

public:
    Coffee(int water = 1, int coffee = 1, int sugar = 0, int cream = 0);
    void show();
    Coffee operator+(Coffee op2);
    friend Coffee operator+(Coffee op1, int op2);
    ~Coffee();
};

Coffee::Coffee(int water, int coffee, int sugar, int cream)
{
    this->water = water;
    this->espresso = coffee;
    this->sugar = sugar;
    this->cream = cream;
}

void Coffee::show()
{
    cout << "물 " << water << "커피" << espresso;
    cout << ",설탕 " << sugar << ", 크림" << cream << endl;
}


Coffee Coffee::operator+(Coffee op2)
{   
    Coffee tmp;

    tmp.water = this->water + op2.water;
    tmp.espresso = this->espresso + op2.espresso;
    tmp.sugar = this->sugar + op2.sugar;
    tmp.cream = this->cream + op2.cream;

    return tmp;
}

Coffee operator+(Coffee op1, int op2)
{   
    op1.espresso = op1.espresso + op2;
    return op1;
}


Coffee::~Coffee()
{
}



int main()
{
    Coffee black(2, 5, 0, 0), dabang(2, 2, 2, 2), c, d;
    c = black + dabang;
    d = c + 1;
    c.show();
    d.show();

    return 0;
}