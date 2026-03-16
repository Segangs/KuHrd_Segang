// 함수 만들기

#include <stdio.h>

int add(int a, int b); // 함수 선언 (프로토타입)

int main(void)
{
    int first = 43, second = 72; // main 함수에서 지역 변수 선언 및 초기화
    printf("%d + %d = %d", first, second, add(first, second)); // add 함수 호출하여 결과 출력 function call
    return 0;
}

int add(int a, int b) // add 함수 정의, 매개변수 a와 b는 add 함수의 지역 변수 <프로토타입은 선언과 동일해야 함.> 
{
    //int a = first , int b = second ; 가 숨겨져 있음. 메모리 사용이 늘어남. 함수 사용시에는 메모리 사용량에 주의하여 사용한다.
    return a + b;
}