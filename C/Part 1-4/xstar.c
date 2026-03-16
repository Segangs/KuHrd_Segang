// 피라미드 형태 출력 이중 for 문 사용
// *   *
//  * * 
//   *
//  * *
// *   *



/*
    i\j 1 2 3 4 5
    1   *       *
    2     *   *
    3       *
    4     *   *
    5   *       *

    i+j == 6 이거나 i == j 일 때 별이 출력된다.
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main (void)
{
    system("clear"); // 화면을 깨끗하게 지워주는 명령어, system() 함수는 C에서 외부 명령어를 실행할 때 사용한다. clear는 터미널 화면을 지우는 명령어이다. 이 코드를 실행하면 프로그램이 시작될 때마다 터미널 화면이 깨끗하게 지워진다.
    system("ls -al");

    for (int i = 1 ; i <= 5 ; ++i)
    {
        for (int j = 1; j <= 5; ++j)
        {
            // if (i+j == 6 || i == j)
            // {
            //     printf("*");
            // }else
            // {
            //     printf(" ");
            // }

            printf((i + j == 6 || i == j) ? "*" : " "); // 삼항연산자 사용, 위 주석처리한 7줄과 같은 효과가 있음. 하지만 가독성이 떨어진다.
        }
        printf("\n");
    }
}
