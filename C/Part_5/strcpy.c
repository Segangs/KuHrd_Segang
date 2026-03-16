//strcpy 함수를 구현해보기

#include <stdio.h>

char *myStrcpy(char *pDes, char*pSrc);

int main(void) {
    char str2[200] = "strawberry";
    myStrcpy(str2, "apple");
    printf("str2: %s\n", str2);
    myStrcpy(str2, "banana");
    printf("str2: %s\n", str2);
    printf("str2: %s\n", myStrcpy(str2, "pineapple"));

    return 0;
}

char *myStrcpy(char *pDes, char*pSrc)
{
    char *pA = pDes;
    while (*pSrc != '\0') // While문이 돌면서 메모리 덮어 씌움.
    {
        *pDes = *pSrc;   //돌면서 한글자씩 넣는다.
        pDes++;
        pSrc++;
    }
    *pDes = '\0'; // \0 = NULL이라는 뜻. 마지막에 NULL 을 씌워줌.
    return pA;
}