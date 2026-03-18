// 스택 - push, pop

#include <stdio.h>

// void push(int data);
// int pop(void);
// int stack[50];
// int tos = 0; // top of stack의 약자. 사실 전역변수라서 초기화 0으로 안해도 됨 (자동으로 초기화)

#define STACKSIZE 100 // 나중에 확장 가능하게 수정
typedef struct 
{
    int array[STACKSIZE];
    int tos;
} Stack;

void initStack(Stack *ps);
void push(Stack *ps, int data);
int pop(Stack *ps);


// typedef int Stack;
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


}


void initStack(Stack *ps)
{
    ps->tos = ps->array;
}

void push(Stack *ps, int data)
{
    //ps->tos=data;
    // stack[tos] = data;
    *(ps->tos++) = data;
}
int pop(Stack *ps)
{
    --(ps->tos);
    //return stack[tos];
    return *(--ps->tos);
}