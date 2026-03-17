// 동적할당 예제

// 몇개인지 모를때 사용 ex) int 4개에서 10개 받을 때
// 아래 코드는 쓸모있는 코드는 아님.

#include <stdio.h>
#include <stdlib.h>
#include "dynamicAllocation.h"


int main(void) {
    char *pLiteral = "리터럴 상수이다";
    int *pInt; // 주소값 선언 포인터
    double *pDouble;
    char localVariable = 'C';
    char pArray[20] = "지역 변수 (배열)";


    pInt = (int*)malloc(sizeof(int));   
    // 메모리 할당. Void로 넘길 것이 아니면 Int 뒤에는 캐스팅(*)이 반드시 들어감. 
    // sizeof(int)는 바이트로 들어가기 때문에( 4바이트) 4를 써도 됨.
    // 1. heap에 메모리 공간 할당 2. 주소값을 리턴 3. 그 주소값으로 assign하여 pInt에 넘김

    if(pInt == NULL)
    {
        printf("메모리가 부족합니다. \n");
        exit(1);
    }
    pDouble = (double*)malloc(sizeof(double));

    *pInt = 10000; // 포인터이니까 참조하여 값을 넣음, 
    *pDouble = 3.4;

    printf("정수형으로 사용: %d \n", *pInt); 
    printf("실수형으로 사용: %lf \n", *pDouble);
    printf("%s : 0x%p", pLiteral, pLiteral);
    printf("%d 힙메모리 : 0x%p \n", *pInt, pInt);
    printf("%c 지역변수 : 0x%p \n", localVariable, &localVariable);
    printf("%s : 0x%p \n", pArray, pArray);



    // 포인터가 주소값을 잃어버리면 찾을 방법이 없으므로, 메모리 누수 현상과 메모리 침범 현상이 일어난다.
    // 반드시 malloc을 썼으면 free를 같이 써서 닫아줘야 함
    free(pInt);
    free(pDouble);
    return 0;
}