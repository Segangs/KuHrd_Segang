// 구조체 기초

#include <stdio.h>

// 첫번째 방식
/*
struct data
{
    int year;
    int month;
    int day;
};

int main(void) {
    struct data d;
    d.year = 2026;
    d.month = 7;
    d.day = 19;

    printf("%d-%d-%d\n", d.year, d.month, d.day);

    return 0;
}
*/ 

// 두번째 방식 (typedef 를 사용하여 간편하게 구조체 사용)
typedef struct   // typedef
{
    int year;
    int month;
    int day;
}Date;  // 명시


int main(void) {
    Date d;    // 불러올때 struct를 쓰지 않아도 되어 편리
    d.year = 2026;
    d.month = 7;
    d.day = 19;

    printf("%d-%d-%d\n", d.year, d.month, d.day);

    return 0;
}