//리스트

#include <stdio.h>
#include <stdlib.h>

// 단일 연결 리스트 노드 정의
// data: 저장할 값
// next: 다음 노드 주소 (마지막 노드는 NULL)
typedef struct node{
    int data;
    struct node *next;
} Node;

// 함수 선언
void insertNode(int data, Node *p);   // 노드 p 뒤에 새로운 노드 삽입
void deleteList(Node *p);            // 일부 노드(임시 구현) 해제
void deleteNode(Node *p, int data);  // 값이 data인 노드 삭제

int main(void)
{
    Node *p;
    p = malloc(sizeof(Node));          // 첫 번째 노드 동적할당

    p->data = 100;
    // 두번째 데이터 생성
    p->next = malloc(sizeof(Node));
    p->next->data = 200;

    // 세번째 데이터 생성
    p->next->next = malloc(sizeof(Node));
    p->next->next->data = 300;

    p->next->next->next = malloc(sizeof(Node));
    p->next->next->next->data = 400;
    p->next->next->next->next = NULL;   // 리스트 끝 표시

    // 노드 삽입: p 뒤에 30 삽입, p->next 뒤에 40 삽입
    insertNode(30, p);
    insertNode(40, p->next);
    // insertNode(3, p->next->next);   // 필요시 주석 해제

    // 300 값을 가진 노드 삭제
    deleteNode(p, 300);

    // 리스트 출력
    Node *tmp;
    tmp = p;
    while(tmp){
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }

    // 리스트 메모리 해제 (임시 구현)
    deleteList(p);
    free(p);                            // 첫 노드 해제
    return 0;
}

// p 뒤에 data 값을 가진 새로운 노드 추가
void insertNode(int data, Node *p)
{
    Node *tmp = malloc(sizeof(Node));
    tmp->data = data;
    tmp->next = p->next;  // 기존 다음 노드를 이어주고
    p->next = tmp;        // p의 다음을 새 노드로 연결
}

// 경고: deleteList 구현이 일반적인 전체 리스트 삭제가 아니라
// 현재는 p에서 일부 노드만 해제하는 잘못된 구현입니다.
// (Code from original source 그대로 유지)
void deleteList(Node *p)
{
    Node *tmp = malloc(sizeof(Node));
    Node *tmp2 = malloc(sizeof(Node));
    tmp = p->next;
    for (int i = 0; i < 1; ++i){
        tmp = tmp->next;
    }
    tmp2 = p->next;
    for (int i = 0; i < 2; ++i)
    {
        tmp2 = tmp2->next;
    }
    tmp2 = tmp->next;
    free(tmp);
    free(tmp2);
}

// 값이 data인 노드를 찾아 삭제
void deleteNode(Node *p, int data)
{
    Node *curr = p;
    Node *prev = NULL;

    while(curr != NULL && curr->data != data){
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL)
        return;                        // 찾는 값이 없으면 종료

    if(prev == NULL){                  // 첫 노드 삭제 시
        p = curr->next;                // 로컬 p만 변경 (호출자 영향 없음)
    } else {
        prev->next = curr->next;       // 이전 노드가 다음 노드 건너뛰기
    }
    free(curr);                        // 대상 노드 메모리 해제
}
