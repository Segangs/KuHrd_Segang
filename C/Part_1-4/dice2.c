//배열을 사용한 주사위

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int dice[30];
    srand(time(NULL));
    for (int i = 0; i < 30; ++i)
    {
        dice[i] = rand() %6 + 1;
        printf("%d ,", dice[i]); // 값 프린트
        printf("%p ", &dice[i]); // 주소 프린트 (p는 포인터의 약자)
    }
    printf("\n");
    for (int i = 0; i < 30; ++i)
    {
        dice[i] *= 10; // 값을 변경했을 때에
        printf("%d ,", dice[i]);
        printf("%p ", &dice[i]); // 주소는 위와 동일한가 확인
    }

    return 0;
}