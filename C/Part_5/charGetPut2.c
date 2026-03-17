//fgets와 scanf의 차이점 알기


#include <stdio.h>
#include <string.h>

int main(void)
{
    char string1[100];
    printf("문자열을 입력하시오 : \n");
    // gets -> 널이 있을때까지 받음. 지금은 쓰이지 않는다.
    // gets();

    fgets(string1, 10, stdin); // fgets와 scanf를 같이 쓸수는 
    printf("%s", string1);
    printf("문자열을 입력하시오 : \n");
    scanf("%s", string1);
    printf("문자열을 입력하시오 : \n"); 
    scanf("%s", string1);

    return 0;
}