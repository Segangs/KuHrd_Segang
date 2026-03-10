#include <stdio.h>

int main()
{
    int num;
    printf("숫자를 넣으세요:");
    scanf("%d", &num);

    int isOdd;
    isOdd = (num % 2 == 1);

    printf("숫자는: %d \t is isOdd : %d\n", num, isOdd);

    if(isOdd)
    {
        printf("%d 홀수입니다\n", num);
    }
    else
    {
        printf("%d 짝수입니다\n", num);
    }
    
    return 0;
}