#include <stdio.h>
int main(void)
{
    int num;
    printf("숫자 입력 1-9:");
    scanf("%d", &num);

    printf ("1 <= %d <= 9 : %s \n", num, (1 <= num) && (num <= 9) ? "true" : "false");
    return 0;
}