  // 캐릭터 다룰때 버퍼에서 언제 나오는지 확인.
// 나중 통신 구현시 데이터가 안가면 버퍼에 데이터가 남아있는지 확인해봐야 함.

#include <stdio.h>
#include <unistd.h>

int main(void) {
    char ch = 'a';

    printf("프로그램 시작\n");
    putchar(ch);  // 버퍼에 a가 저장됨
    sleep(1); // 

    fflush(stdout); //버퍼 비워줌

    sleep(1);
    printf("\n"); // a 출력, putchar 실행 후. 바로 개행문자와 동시에 찍힘.

    putc(ch, stdout); // 버퍼가 남아 있고
    fflush(stdout); //버퍼 비워줌
    sleep(1);
    
    char *string1= "스트링1 배열입니다";
    puts(string1); // puts은 작동 방식이 마지막에 개행을 자동 추가한다.
    sleep(1); 
    printf("프로그램 끝입니다.");
    fputs(string1, stdout); // 개행 추가가 없다.
    sleep(1);
    printf("프로그램 끝입니다.")    
    printf("")
 
    return 0; // 프로그램이 종료될 때 버퍼가 비워짐
}