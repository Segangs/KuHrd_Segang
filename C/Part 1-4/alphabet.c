// 입력받은 char가 알파벳인지 확인

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    char ch;
    printf("char을 입력하시오 :");
    scanf("%c", &ch); // 캐릭터 연산자, 주소 연산자

    bool english;
    english = (('a' <= ch) && (ch <= 'z')) || (('A' <= ch) && (ch <= 'Z')); // 알파벳인지 확인하는 조건식
    printf("%c (%d)는 %s\n ", ch, ch, english ? "알파벳" : "알파벳 아님"); // 삼항 연산자를 사용하여 english이 참이면 "알파벳입니다.", 거짓이면 "알파벳 아닙니다." 출력
    return 0;
}