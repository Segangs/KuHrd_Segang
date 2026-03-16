#include <stdio.h>

int main(void)
{
    int sum = 0;
    int i = 1;
    while (i <= 10){
        sum += i; // = sum = sum+i 와 같은 효과
        i++;
    }
printf("%d\n", sum);

return 0;
}