#include <stdio.h>

int main(void) {
    printf("%c\n", 'A'); // charactor 는 꼭 '' 로 묶고
    printf("%s\n", "A"); // string은 꼭 ""로 묶어줘야 (세그멘테이션 폴트)
    
    printf("%c는 %s입니다.\n", '1', "first");

    return 0;
}