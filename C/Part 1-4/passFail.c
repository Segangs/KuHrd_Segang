// 외부 데이터 사용하는 함수

#include <stdio.h>
#include <stdlib.h> //atoi() 함수를 사용하기 위해서 (array를 int로 바꿔주겠다)

int main(int argc, char *argv[]) // main은 무조건 char문자열로 들어온다
{
   // int score;
   // printf("점수를 입력하시오:");
   //  scanf("%d", &score);


    if(argc >= 60){
 printf("점수 : %d (합격)", score);
    } else {
       printf("점수 : %d (불합격)", score);
    }
    return 0;
}