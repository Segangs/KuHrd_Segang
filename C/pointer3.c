// little endian, big endian : 
// 메모리에 데이터를 저장하는 방식. 
// little endian은 작은 단위의 데이터가 먼저 저장되는 방식, big endian은 큰 단위의 데이터가 먼저 저장되는 방식. 
// 예를 들어, 0x12345678이라는 4바이트 데이터를 little endian으로 저장하면 메모리에 78 56 34 12 순서로 저장되고, 
// big endian으로 저장하면 12 34 56 78 순서로 저장된다. 대부분의 컴퓨터는 little endian 방식을 사용한다.

#include <stdio.h>

int main(void)
{
    int a = 0x12345678; // 12 34 56 78 = 4바이트
    char *p;
    p = (char *)&a; //
    printf("*p : 0x%x \n", *(p+3)); // 0x78이 나오면 big endian이다. 뒤쪽부터 1바이트씩 읽어옴. (*p+1 하면 56으로 나옴)

    return 0;
}