#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// void push(int data);
// int pop(void);
// int stack[50];
// int tos = 0; // top of stack의 약자. 사실 전역변수라서 초기화 0으로 안해도 됨 (자동으로 초기화)


typedef struct 
{
    int *pArr;
    int *tos;
    int size;
} Stack;

void initStack(Stack *ps, int size);
void cleanupStack(Stack *ps);

void push(Stack *ps, int data);
int pop(Stack *ps);
int size(Stack *ps);