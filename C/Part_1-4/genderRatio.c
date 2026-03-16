#include <stdio.h>

int main()
{
    int man, woman;
    double sum, manRate, womanRate;

    printf("남자 수 :");
    scanf("%d", &man);
    printf("여자 수 :");
    scanf("%d", &woman);

    sum = man + woman; // man과 woman은 int형이지만 sum은 double형이므로 자동으로 double형으로 변환되어 계산
    womanRate = woman / sum * 100; 
    manRate = man / sum * 100;

    printf("남자의 수는 %d명이고 여자의 수는 %d명이다. \n", man, woman);
    printf("총 수는 %.f명\n남자의 비율은 %.2f\n여자의 비율은 %.2f\n", sum, manRate, womanRate);
    
    return 0;

}