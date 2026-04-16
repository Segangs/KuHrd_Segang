#include <iostream>
using namespace std;

class Storage
{
public:
    // 변수
    double data[10] = {};
    int next = 0;

    // 함수
    void put(double tmpt);
    double dump();
    double getAvg();

    // 생성자
    Storage();
};

// 함수 구현
void Storage::put(double tmpt)
{
}

void Storage::dump()
{
    for 
}

double Storage::getAvg()
{
    double sum = 0.0;
    int i;
    for (i = 0; i < next; i++)
    {
        sum = data[i] + sum;
    }
    
    double avg = sum / next;
}

// 생성자 구현
Storage::Storage()
{
    for (int i = 0; i < next; i++)
    {
        cout << data[i] << " ";
    }
}

int main()
{
    Storage a;
    a.put(36.7);
    a.put(36.9);
    a.put(36.4);
    a.dump(); // a에 저장된 모든 체온 값 출력
    cout << "평균 체온은 " << a.gerAvg() << "입니다." << endl;

    return 0;
}