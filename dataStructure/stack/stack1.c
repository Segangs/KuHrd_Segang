// 스택 - push, pop

//문제점 : 전역 변수 사용. 포인터로 매개변수를 넘기기
//배열의 사용 범위가 정해져 있음.
//다수의 스택 운영이 불가능함
//stack2.c에서 보완

#include <stdio.h>

void push(int data);
int pop(void);
int stack[50];
int tos = 0 ; // top of stack의 약자. 사실 전역변수라서 초기화 0으로 안해도 됨 (자동으로 초기화)

int main(void) {
    
    push(100);
    push(200);
    push(300);
    
    printf("첫번째 pop() 리턴 값: %d \n", pop()); //300
    printf("두번째 pop() 리턴 값: %d \n", pop()); //200
    printf("세번째 pop() 리턴 값: %d \n", pop()); //100
    return 0;
}

void push(int data)
{
    stack[tos] = data;
    ++tos;
}

int pop(void)
{
    --tos;
    return stack[tos];
}
