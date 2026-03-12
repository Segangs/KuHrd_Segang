// 배열과 포인터와의 관계 
// 배열을 포인터로 써도 상관없다. 포인터도 배열의 형식으로 접근이 가능하다.
// 포인터가 몇바이트인지 포인터의 타입이 중요하다. (메모리 주소를 확인해보면 int형이라서 4바이트씩 올라간다.)

#include <stdio.h>

int main(void)
{
    int nums[] = {1,2,3,4,5};
    int *p;

    p=nums;
    p=p;

    *(p+1) = *(p+2);
    (p) = (p + 1);
    for (int i = 0; i < 5; ++i)
    {
        printf("nums[%d] : %d\t", i, nums[i]);
        printf("*(p+%d) : %d\t", i, *(p + i));
        printf("*(nums+%d): %d\t", i, *(nums+i));
        printf("p[%d] : %d\n", i, p[i]);
    }   

    for (int i = 0; i < 5; ++i)
    {
        printf("nums : %p\t", nums);
        printf("*(p+%d) : %p\t", i, (p + i));
        printf("*(nums+%d): %p\t", i, (nums+i));
        printf("p[%d] : %p\n", i, &p[i]);
    }  

    return 0; 

}