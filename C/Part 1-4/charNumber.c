#include <stdio.h>

int main(void)
{
    char ch1 = 'A'; // 선언과 동시에 대입
    char ch2 = 64;
    char ch3; // 선언만
    printf("ch1: %c Number : %d\n", ch1, ch1);
    printf("ch2: %c Number : %d\n", ch2, ch2);
    printf("ch3 입력 :");
    scanf("%c", &ch3); // 문자입력
    printf("ch3: %c Number : %d\n", ch3, ch3); //c언어는 주소 연산자 입력(메모리 주소로 접근해야만 함)
    return 0;
}