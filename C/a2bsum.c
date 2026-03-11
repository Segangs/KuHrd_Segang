// scanf를 입력받아 a~b 까지의 합을 for문으로 구하는 프로그램

#include <stdio.h>

int main(void)
{
    int a,b = 0;
    int sum = 0;

    printf("첫번째 숫자(a) 입력 : ");
    scanf("%d", &a);
    printf("두번째 숫자(b) 입력 : ");
    scanf("%d", &b);

    for(int i = a ; i <= b ; i++ ){
        sum = sum + i;
    };
    printf("합 : %d\n", sum);

    return 0;
}