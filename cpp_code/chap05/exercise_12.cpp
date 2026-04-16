#include <iostream>
using namespace std;

class MyPipe
{
    int size = 0;     // 할당된 동적배열크기
    int putIndex = 0; // 다음에 저장될 배열원소 인덱스
    int *p;           // 정수를 저장할 동적 배열을 가리키는 포인터

public:
    MyPipe();
    MyPipe(int size);
    MyPipe(const MyPipe &src);
    ~MyPipe();

    bool put(int n);
    bool get(int &n);
    int getsize() { return putIndex; }
};

MyPipe::MyPipe()
{
}
MyPipe::MyPipe(int size) {}
MyPipe::MyPipe(const MyPipe &src) {}
MyPipe::~MyPipe() {}



int main()
{
    MyPipe a(5);
    a.put(10);
    a.put(20);

    MyPipe b = a;
    b.put(30);
    cout << "파이프 a에 저장된 개수: " << a.getSize() << endl;
    cout << "파이프 b에 저장된 개수: " << a.getSize() << endl;

    int n;
    a.get(n);
    cout << "파이프 a에서 빼온 값 " << n << endl;

    b.get(n);
    cout << "파이프 b에서 빼온 값 " << n << endl;

    return 0;
}