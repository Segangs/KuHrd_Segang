// 선택 정렬
// 첫번째 자리를 알맞게 1번 순회, 두번째 자리를 알맞게 순회 ... 

// 변수 쓰는 규칙 - 식별자는 항상 소문자로 시작해야 (써도 에러는 안나지만)

#include <stdio.h>


void swap(int *a, int *b); // swap 함수 선언, 매개변수는 포인터로 선언하여 주소값을 받는다. <프로토타입은 선언과 동일해야 함.>

int main(void)
{
    int nums [10] = {40, 20, 52, 12, 34, 64, 93, 42, 42, 5};

    int indexN = sizeof(nums) / sizeof(int); // 배열의 크기를 구하는 방법, sizeof(nums) 는 배열 전체의 크기, sizeof(int)는 int형 하나의 크기, 둘을 나누면 배열의 요소 개수가 나온다.

    printf("배열크기 %ld \n",sizeof(nums));
    printf("int크기 %ld \n",sizeof(int));
    for (int i = 0; i < indexN ; ++i){   // i는 0부터 시작해서 indexN-1까지 순회한다.
        for (int j = i + 1 ; j < indexN ; ++j){ // j는 i+1부터 시작해서 indexN-1까지 순회한다. i+1부터 시작하는 이유는 i번째 요소와 비교하기 위해서이다. i번째 요소는 이미 정렬되어 있기 때문에 j는 i+1부터 시작한다.
            if(nums[i] > nums[j]){ // i번째 요소가 j번째 요소보다 크면 swap한다. 즉, i번째 요소가 더 작은 요소로 바뀐다.
                swap(&nums[i], &nums[j]); 
                // swap선언시 포인터 사용했으므로 주소 연산자로 사용. swap함수는 i번째 요소와 j번째 요소의 값을 맞교환한다. swap함수는 void형이므로 return값이 없다. swap함수는 매개변수로 포인터를 사용하므로 주소값을 전달해야 한다. &nums[i]는 i번째 요소의 주소값, &nums[j]는 j번째 요소의 주소값이다.
            }
        }
    }

    for (int i = 0 ; i < indexN ; ++i)
    {
        printf("%d, ", nums[i]);
    }

    return 0;
}



void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}