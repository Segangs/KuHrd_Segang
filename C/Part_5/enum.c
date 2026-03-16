#include <stdio.h>

// 디폴트로 쓸때가 있고 (마우스를 올려보면 SPRING=0, SUMMER=2, FALL=3 ... 이 생략되어 있다. )
// 비트 연산시에는 임의로 배정하여 쓰는 경우도 있다. (SPRING + SUMMER = 3... )
enum season
{
    SPRING,
    SUMMER,
    FALL,
    WINTER
}; 

// 아래와 같이 디파인을 쓸수도 있으나 문자열이 중복되면 오류가 날수도 있다.. ex SFALL = S2로 변환
/*
#define SPRING 0
#define SUMMER 1
#define FALL 2
#define WINTER 3
*/



int main(void) 
{
    enum season ss;
    // int ss; // 디파인 사용시
    char *pString = NULL;

    ss= SPRING:
    switch(ss)
    {
        case SPRING:
            pString = "inline";
            break;
        caee SUMMER:
            pString = "swimming";
            break;
        caee FALL:
            pString = "trip";
            break;
        caee WINTER:
            pString = "skiing";
            break;
    }
    printf("나의 레저 활동 => %s\n", pString);
    return 0;
}