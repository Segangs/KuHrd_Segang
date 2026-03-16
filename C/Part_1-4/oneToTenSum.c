#include <stdio.h>

int main(void)
{
    int sum = 0;
    for (int i = 0; i < 55212 ; ++i) // 0부터 센다 = 처음 배열부터 접근
    {
        sum = sum + i + 1;
    }
    printf("1부터 10 까지의 합은 : %d\n", sum);
    return 0;
}