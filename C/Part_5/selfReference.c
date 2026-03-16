// 중요 - 자기참조구조체 (책 527p 예제)

#include <stdio.h>

typedef struct list
{
    int num;
    List *next *next;
}List;


int main(void) {
    List a = {10, 0}, b = {20, 0}, c = {30, 0};
    List *head = &a, *current;
    a.next = &b;
    b.next = &c;
    // a가 b주소를 가리키고, b가 c 주소를 가리킨다. 링크드 리스트라고 한다.
    // 배열은 중간에 삽입이 힘들다.  a b c e f g 중간에 d를 넣으려면 뒤에것을 temp로 하나씩 돌려가며 옮겨야 한다.
    // 링크드 데이터를 사용하면 메모리의 이동 하나도 없이 포인터 값만을 이용하여 삽입이나 수정을 쉽게 할수 있다.
    // 중요하여 면접에서 많이 물어보던 알고리즘 중의 하나이다.


    printf("head->num : %d\n", head->num);
    printf("head->next->num : %d\n", head->next->num);

    printf("list all : ");
    current = head;
    while(current ! = NULL)
    {
        printf("%d ", current -> num);
        current = current -> next;
    }
    printf("\n");
    return 0;
}