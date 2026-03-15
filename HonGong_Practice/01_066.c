#include <stdio.h>

int main(void) {
    printf("%d\n", 12); //10진수 -> 10진수
    printf("%d\n", 014); //8진수 -> 10진수
    printf("%d\n", 0xc); //16진수 -> 10진수

    printf("%o\n", 12); //10진수 -> 8진수
    printf("%x\n", 12); //10진수 -> 16진수 소문자
    printf("%X\n", 12); //10진수 -> 16진수 대문자

    return 0;
}