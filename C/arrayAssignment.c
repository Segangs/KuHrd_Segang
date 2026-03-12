// 배열을 배열로 복사해서 넣을 때

#include <stdio.h>

int main(void)
{
    int nums[] = {6, 5, 8, 3, 2, 1};
    int nums2[6];

    // nums2 값을 nums로 복사하고 싶을때 nums2=nums; 이건 작동하지 않는다. 
    // (배열 주소값 포인터이기 때문에 덮어씌울수 없다.) for문을 돌려서 넣어야함.

    for (int i = 0; i < 6; ++i)
    {
        nums2[i] = nums[i];  // nums2의 i번째 요소에 nums의 i번째 요소를 복사한다. 이렇게 하면 nums2는 nums와 같은 값을 가지게 된다.
    }

    for (int i = 0; i < 6; ++i)
    {
        printf("%d, ", nums2[i]);
    }

    printf("\n");
    return 0;

    
}