#include <stdio.h>

int main(void) {
    char ch;
    char str[100];
    printf("문자를 입력하세요: ");
    //ch = getc(stdin);
    // ch = fgetc(stdin); // getc와 동일하지만 매크로냐 함수냐의 차이
    ch = getchar(); //getchar는 stdin을 받지 않음

    printf("%d, %d, %d", stdin->_fileno, stdout->_fileno, stderr->_fileno);
    printf("입력한 문자는 %c 입니다. \n", ch);
    while(getchar() != '\n') //  버퍼를 비우는 코드 

    ch= fgetc(stdin);
    printf("입력한 문자는 %c 입니다. \n", ch);
    scanf("%s", str);
    printf("입력한 문자열은 %s입니다. \n", str);

    return 0;
}