#include <stdio.h>


// C 언어에서 증감 연산자(++, --)의 사용 예시를 보여주는 프로그램

int main(void)
{
    int a, b;
    a = 5;
    b = ++a; // a를 1 증가시킨 후 b에 대입함
    printf("a: %d \t b: %d\n", a, b); 
 
    a = 5;
    b = a++; //5를 b에 대입한 후 a를 1 증가시킴
    printf("a: %d \t b: %d\n", a, b); 

    printf("a: %d \t b: %d\n", a, a++);
    printf("a: %d \t b: %d\n", a, ++a);

return 0;

}
