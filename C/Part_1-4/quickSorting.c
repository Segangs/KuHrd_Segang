// 실전에서는 선택, 버블정렬보다는 라이브러리로 만들어져있는 퀵소팅을 많이 씀.

#include <stdio.h>
#include <stdlib.h>

int compare (const void *a, const void *b); // const : 상수처럼 쓰겠다

int main(void) // 
{
    int nums [10] = {40, 20, 52, 12, 34, 64, 93, 42, 42, 5};
    int indexN = sizeof(nums) / sizeof(int);


    qsort(nums, indexN, sizeof(int), compare);

    for (int i = 0; i < indexN; ++i)
    {
        printf("%d, ", nums[i]);
    }

    return 0;
}

int compare (const void *a, const void *b) // 정의
{
    return (*(int *)a - *(int *)b); // 

}