#include <stdio.h>

int main(void) {
    char name[10]; //10바이트까지만 입력가능 (실제론  9바이트+널문자1바이트, 한글은 글자당 2바이트)
    printf("이름 입력 : ");
    scanf("%s", name);
    printf("이름 : %s\n", name);
    
    return 0;
}