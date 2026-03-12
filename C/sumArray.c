//random 으로 int 10개짜리 배열을 만들어서 값을 넣고 총합을 계산하는 프로그램

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int dice[10];
    int sum = 0;
    srand(time(NULL));

    for(int i = 0; i < 10 ; i++)
    {
        dice[i] = rand() % 6 + 1 ;
        printf("%d ", dice[i]);
    }
    for (int i = 0; i < 10; ++i)
    {
        sum += dice[i];
    }

    printf("\n 배열의 총합은 %d 이다. \n", sum);
    return 0;

}