//대문자인지 소문자인지 확인하기

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    char ch;
    printf("char을 입력하시오 :");
    scanf("%c", &ch); // 캐릭터 연산자, 주소 연산자

    bool isBig;
    isBig = ('A' <= ch) && (ch <= 'Z'); // 대문자 범위에 있는지 확인하는 조건식
    printf("%c %d는 %s\n ", ch, ch, isBig ? "대문자입니다" : "대문자가 아닙니다"); // 삼항 연산자를 사용하여 isBig이 참이면 "대문자", 거짓이면 "대문자가 아닙니다" 출력
    return 0;
}