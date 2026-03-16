//int로 점수입력받아서 90이상이면 A, 80이상이면 B, 70이상이면 C, 60이상이면 D, 나머지는 F를 출력
// if문 사용

#include <stdio.h>

int main(void)
{
    int score;
    char grade = 'F';

    printf("점수를 입력하시오 : ");
    scanf("%d", &score);

    if(score >= 90){
        grade = 'A';
    }
    else if(score >= 80){
        grade = 'B';
    }
    else if(score >= 70){
        grade = 'C';
    }
    else if(score >= 60){
        grade = 'D';
    }
    
    printf("%d 는 %c 입니다.\n", score, grade);
    
    return 0;
}