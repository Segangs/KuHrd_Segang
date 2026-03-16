//배열을 이용한 구조체

// ./structArray < address.dat

#include <stdio.h>

typedef struct{
    char name[20];
    int age;
    char tel[20];
    char addr[80];
} Address;

void printList(const Address *pList);
void inputList(Address *pList);

int main(void) {
    // Address list[5]={
    // {.name="홍길동", .age=23, .tel="111-1111", .addr="울릉도 독도"}, // 구조체 리스트는 아래와 같이 생략해도됨
    // {"이순신", 35, "222-2222", "서울 건천동"},   
    // {"장보고", 19, "333-3333", "완도 청해진"},   
    // {"유관순", 15, "444-4444", "충남 천안"},   
    // {"안중근", 45, "555-5555", "황해도 해주"}   
    // };
    Address list[5];
    inputList(list);

    // printList(list, 5); 배열의 크기도 같이 넘김(정석)
    // printList(&list[0]);
    printList(list);   // 위 두줄과 똑같은 효과

    return 0;
}

void inputList(Address *pList)
{
    for (int i = 0; i < 5 ; ++i)
    {
    scanf("%s %d %s %s", (pList+i)->name, &(pList+i)->age, (pList+i)->tel, (pList+i)->addr);
    }
}


void printList(const Address *pList)
{
    int i;
    for (i = 0 ; i < 5 ; i++)
    {
        //printf("%10s%5d%15s%20s\n", list[i].name, list[i].age, list[i].tel, list[i].addr);
        printf("%s\t%d\t%s\t%s\n", (pList + i)->name, (pList + i)->age, (pList + i)->tel, (pList + i)->addr);
        // 구조체를 선언했을때는 포인터로 넘어가면 포인터 형식으로만 사용해야 함
    }
}

