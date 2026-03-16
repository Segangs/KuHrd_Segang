#include <stdio.h>
#include <string.h>


//문자열 값에 포인터만 붙이면 변경이 안된다.

int main(void)
{
    char *ga = "dsadsadefefwgfregjiadsfjasdfdskfas";
    char *str = "wonderful tonight";

    // str length 구해보기
    int len = strlen(str); // 원래는 17(wonderful tonught)이나 맨뒤 null문자까지 세어야 한다 (18)
    printf("len: %d\n", len);

    // strcpy
    char str2[200];
    strcpy(str2, ga);
    strcpy(str2, str);

    for (int i = 0; i < 100; ++i)
    {
        printf("C%d: %c\n", i, str2[i]);
    }


    str2[10] = 'A';
    // strcmp
    if (strcmp(str2, str) == 0)
    {
        printf("str과 str2는 같다. \n");
    }
    else
    {
        printf("str과 str2는 다르다. \n");
    }

    // strcat 앞뒤로 붙임
    char *str3 = "eric claption";
    strcat(str2, " - ");
    strcat(str2, str3);
    printf("str2: %s\n", str2);
    return 0;
}