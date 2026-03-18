#include <stdio.h>
#include <stdlib.h>
#define ARRAYSIZE 100

typedef struct {
    int queue[ARRAYSIZE];  // 배열 선언
    int *front;   // 포인터 선언 (넣기)
    int *rear;   // 포인터 선언 (빼기)
} Qu;

void initQueue(Qu *pQu);
void push(Qu *pQu, int data);
int pop(Qu *pQu);


int main(void)
{
    Qu qu1, qu2;
    initQueue(&qu1);
    initQueue(&qu2);
    push(&qu1, 100);
    push(&qu1, 200);
    printf("첫번째 pop(): %d\n", pop(&qu1)); // 100

    push(&qu1, 300);
    printf("두번째 pop(): %d\n", pop(&qu1)); // 200
    printf("세번째 pop(): %d\n", pop(&qu1)); // 300

    push(&qu2, 700);
    push(&qu2, 800);
    printf("첫번째 pop(): %d\n", pop(&qu2)); // 700

    push(&qu2, 900);
    printf("두번째 pop(): %d\n", pop(&qu2)); // 800
    printf("세번째 pop(): %d\n", pop(&qu2)); // 900

    return 0;





    
}




void initQueue(Qu *pQu)
{
    pQu->front = pQu->queue;    // 구조체 안에 배열명 첫번째 주소값을 가리킨다. 
    pQu->rear = pQu->queue;     
}
void push(Qu *pQu, int data)
{
    if(pQu->rear == ARRAYSIZE){     
        pQu->rear = pQu->queue+ARRAYSIZE;     //rear가 끝까지 돌아가면 다시 처음으로 가겠다
    }
    if(pQu->rear+1 == pQu->front){
        fprintf(stderr, "stack is full\n");
        exit(1);
    }
    *(pQu->rear++) = data;
}
int pop(Qu *pQu)
{
    if(pQu->front == ARRAYSIZE){
        pQu->front = pQu->queue+ARRAYSIZE;
    }
    if(pQu->front == pQu->rear){
        fprintf(stderr, "there is no data\n");
        exit(1);
    }
    return *(pQu->front++);
}