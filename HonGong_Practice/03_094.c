#include <stdio.h>

int main(void) {
    int income = 0;
    double tax;
    const double tax_rate = 0.12;

    income = 30000000;
    // tax_rate = 500;  // const는 상수처럼 사용되어 고정값이 된다. 덮어씌울수 없음.
    tax = income * tax_rate;
    printf("납부하실 세금 : %.1lf 원 입니다.\n", tax);

    return 0;
}