#include <stdio.h>
#include <stdbool.h>

bool arrayCompare(int *array, int  *array2, int index);
// 배열을 넘길때는 배열의 최대 개수를 같이 넘겨야 처리가 가능하다. 배열의 크기를 알 수 없기 때문에. 배열의 최대 개수를 넘겨주면 for문을 돌려서 비교할 수 있다.

int main(void)
{   
    int nums1[] = {1, 2, 3, 4, 5};
    int nums2[] = {1, 2, 3, 4, 5}; 
    int nums3[] = {1, 2, 4, 5, 6}; 


    // (nums1 == nums2) 이건 주소값이 다르기 때문에 false가 나온다. 배열은 포인터이기 때문에 주소값이 다르면 다른 배열로 인식한다. 따라서 배열을 비교할 때는 for문을 사용하여 요소 하나하나를 비교해야 한다.
    if(nums1[i] != nums2[i]){ // nums1과 nums2의 i번째 요소가 다르면
            break;
        }
    }
    if (i == 5)
    {
        printf("두 배열은 같다.\n");
    } else {
        printf("두 배열은 다르다.\n");
    }

    return 0;
}

bool arrayCompare(int *array, int  *array2, int index){
    int i;
    for (i = 0; i < 5; ++i)
    {
        if(nums1[i] != nums2[i]){ // nums1과 nums2의 i번째 요소가 다르면
            break;
        }
    }
    if (i == index)
    {
        printf("두 배열은 같다.\n");
        return true;
    } else {
        printf("두 배열은 다르다.\n");
    }

    return 0;
}
