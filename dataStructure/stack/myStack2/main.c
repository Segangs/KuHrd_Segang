#include "stack3.h"

int main(void)
{

    // push(100);
    // push(200);
    // push(300);

    // printf("첫번째 pop() 리턴 값: %d \n", pop()); //300
    // printf("두번째 pop() 리턴 값: %d \n", pop()); //200
    // printf("세번째 pop() 리턴 값: %d \n", pop()); //100
    // return 0;

    // 위 코드의 문제점해결

    Stack s1, s2;  // 스택을 두개 만들어봄

    //스택 초기화
    initStack(&s1);
    initStack(&s2);


    push(&s1, 700);
    push(&s1, 800);
    push(&s1, 900);

    printf("첫번째 pop() 리턴 값: %d \n", pop(&s1)); // 00
    printf("두번째 pop() 리턴 값: %d \n", pop(&s1)); // 00
    printf("세번째 pop() 리턴 값: %d \n", pop(&s1)); // 00


    push(&s2, 100);
    push(&s2, 200);
    push(&s2, 400);

    printf("첫번째 pop() 리턴 값: %d \n", pop(&s2)); // 00
    printf("두번째 pop() 리턴 값: %d \n", pop(&s2)); // 00
    printf("세번째 pop() 리턴 값: %d \n", pop(&s2)); // 00

    printf("s1 스택 메모리 사이즈는 : %d \n", s1.size);
    printf("s2 스택 메모리 사이즈는 : %d \n", s2.size);

    cleanupStack(&s1);
    cleanupStack(&s2);

}