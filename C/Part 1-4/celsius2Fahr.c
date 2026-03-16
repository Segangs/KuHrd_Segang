#include <stdio.h>

/*

# 섭씨에서 화씨 구하기

int main()
{
    int celsius;
    printf("C 온도를 넣으시오 :");
    scanf("%d", &celsius);
    double fahr;
    fahr = 9.0 / 5.0 * (double)celsius + 32.0;
    printf("F(fahr) 온도 : %.2f\n", fahr);
    return 0;
}
    
*/


// 화씨에서 섭씨 구하기
int main()

{
    int fahr;
    scanf("%d", &fahr);
    printf("F 온도를 넣으시오 :");
    double celsius;
    celsius = ((double)fahr - 32.0) / 1.8;
    printf("C(Celsius) 온도 : %.2f\n", celsius);
    return 0;
}

