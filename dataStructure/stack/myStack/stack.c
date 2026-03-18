#include "stack.h"

static int stack[100];
static int tos = 0 ; // top of stack의 약자. 사실 전역변수라서 초기화 0으로 안해도 됨 (자동으로 초기화)


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
