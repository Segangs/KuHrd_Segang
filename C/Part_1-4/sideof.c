#include <stdio.h>
#include <stdint.h>


// C 언어에서 각 데이터 타입의 크기를 구하는 코드 (바이트 단위로 출력)
int main(void)
{
    int num;
    printf("sizeof(char) : %ld\n", sizeof(char));
    printf("sizeof(short) : %ld\n", sizeof(short));
    printf("sizeof(int) : %ld\n", sizeof(int));
    printf("sizeof(long) : %ld\n", sizeof(long));
    printf("sizeof(float) : %ld\n", sizeof(float));
    printf("sizeof(double) : %ld\n", sizeof(double));
    printf("sizeof(num) : %ld\n", sizeof(num)); // num은 int형 변수이므로 sizeof(int)와 동일한 결과를 출력
    printf("sizeof(3.141592) : %ld\n", sizeof(3.141592)); // 리터럴 3.141592는 double 타입으로 간주되므로 sizeof(double)과 동일한 결과를 출력
    printf("sizeof(uint32_t) : %ld\n", sizeof(uint32_t)); // uint32_t는 4바이트로 고정되어 있음

    return 0;
}