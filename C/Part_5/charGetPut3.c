// 표준입출력 - POSIX 표준을 지키는가? 지원하는가? : 대부분의 기기는 POSIX표준을 지키긴 함.

#include <stdio.h>

int main(void) {
    // 출력합니다.
    char *string1 = "배열입니다.";
    char string2[100];

    printf("printf로 터미널에 출력합니다.\n", string1);
    fprintf(stderr, "fprintf로 터미널에 출력합니다.\n",  string1);
    // strcpy 같은 기능을 함.
    // 버퍼를 거치지 않고 화면에 바로 출력한다. 웬만하면 버퍼를 거치는것을 사용하나 예외 상황에서만 사용

    sprintf(string2, "배열에 문자열을 출력합니다.", 15); // 꽤 많이 쓰임. 15는 배열
    printf("%s", string2);
    
    return 0;
}