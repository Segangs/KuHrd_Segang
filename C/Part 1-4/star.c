// 1씩 늘어나는 별표 화면에 찍기
// *
// **
// ***
// ****

#include <stdio.h>

int main(void)
{
    for (int i = 1; i <=5 ; i++) // i는 1부터 5까지 1씩 증가한다
    {
        for (int j = 1; j <= i; ++j) // j는 1부터 i까지 1씩 증가한다
        {
            printf("*");
        }
        printf("\n");
    }
        return 0;
}