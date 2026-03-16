// 함수 만들어 변수 간 값을 맞교환하는 코드

#include <stdio.h>

void swap(int *a, int*b); // *이 붙으면 메모리 주소값이다.
void info(int a, int b);
int main(void)
{
    int a, b, tmp;
    a = 100;
    b = 200;

    info(a,b);
        // tmp = a;
        // a = b; 
        // b = tmp;
    
    swap(&a, &b);
    info(a,b);

    return 0;
}

void swap(int *a, int *b) // return 되는게 없으므로 void로 한다
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void info(int a, int b)
{
    printf("a: %d, b: %d\n", a, b);
}
