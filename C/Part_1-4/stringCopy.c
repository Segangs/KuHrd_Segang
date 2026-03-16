#include <stdio.h>
#include <string.h>

int main()
{
    char fruit[20] = "strawberry";
    printf("딸기 : %s\n", fruit);
    printf("딸기잼 : %s %s\n", fruit, "jam");
    strcpy(fruit, "banana");
    printf("바나나 : %s\n", fruit);

    // strcpy fruit -> apple
    fruit[0] = 'a';
    fruit[1] = 'p';
    fruit[2] = 'p';
    fruit[3] = 'l';
    fruit[4] = 'e';

    printf("사과 : %s\n", fruit); // string을 다룰 때 NULL이 어디에 있는지가 중요
    return 0;
}