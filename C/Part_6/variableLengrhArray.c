// VLA(variable Length Array) : 동적할당없이 array (windows에서 지원)
// 일반적으로는 사이즈를 잡고 동적 할당을 해서 써야한다. VLA를 사용했다가 문제가 될 수도 있음.


#include <stdio.h>

int main(void)
{
    int size;
    scanf("%d", &size);
    int num[size]; // 이 구문에서 에러가 안나면 VLA를 지원하는 컴파일러이다.

    for (int i = 0; i < size; ++i)
    {
        num[i] = i + 1;
    }
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", num[i]);
    }
    printf("\n");
    return 0;
}