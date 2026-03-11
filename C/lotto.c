// 로또 번호를 추천받는 코드

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int lotto[6]; // 배열로 만든다
    int i, j; 

    srand(time(NULL)); //

    for (int i = 0; i < 6; ++i){
        lotto[i] = (rand() % 45) + 1; // 1~45 사이의 숫자가 나오도록 한다
        
        //중복검사
        for (int j=0; j < i; j++) 
        {
            if(lotto[i] == lotto[j])
            {
                i--;
                break;
            }
        }

    }

    for (int i = 0; i < 6; ++i)
    {
        printf("%d ", lotto[i]);
    }
    printf("\n");
    return 0;

}
