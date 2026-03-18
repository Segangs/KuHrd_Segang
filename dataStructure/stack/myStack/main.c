#include "stack.h"
//문제점 : 전역 변수 사용. 포인터로 매개변수를 넘기기
//배열의 사용 범위가 정해져 있음.
//다수의 스택 운영이 불가능함

int main(void) {
    
    push(100);
    push(200);
    push(300);
    
    printf("첫번째 pop() 리턴 값: %d \n", pop()); //300
    printf("두번째 pop() 리턴 값: %d \n", pop()); //200
    printf("세번째 pop() 리턴 값: %d \n", pop()); //100
    return 0;
}

