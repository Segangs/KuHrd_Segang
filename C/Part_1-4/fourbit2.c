#include <stdio.h>
#include <stdint.h>

#define BOLD 0x01 // 1번 옵션을 나타내는 상수, 0b00000001과 동일한 값을 가짐
#define ITALIC (0x01 << 1) // 2번 옵션을 나타내는 상수, 0b00000010과 동일한 값을 가짐 (1을 왼쪽으로 1비트 이동)
#define SHADOW (0x01 << 2) // 3번 옵션을 나타내는 상수, 0b00000100과 동일한 값을 가짐 (1을 왼쪽으로 2비트 이동)
#define UNDERLINE (0x01 << 3) // 4번 옵션을 나타내는 상수, 0b00001000과 동일한 값을 가짐 (1을 왼쪽으로 3비트 이동)


int main(void)
{
    // unsigned char attr; // 0~255까지의 값을 가질 수 있는 부호 없는 8비트 정수형 변수
    uint8_t attr; // unsigned char와 동일한 크기와 범위를 가지나 조금더 명확하게 선언 11111111

    attr = attr ^ attr; //XOR연산, 0으로 초기화할때 많이 씀
    attr = attr | BOLD; // 1번옵션 T로 만들기
    printf("attr: 0x%02x\n", attr); // 0b00000001이 16진수로 0x01이므로 attr의 값은 0x01이 됨
    attr = attr | (ITALIC + SHADOW); //
    printf("attr: 0x%02x\n", attr);
    attr = attr & (~BOLD); //1번옵션 F로 만들기(2진법)
    printf("attr: 0x%02x\n", attr); 
    
    if (attr & BOLD)
    {
        printf("BOLD 옵션이 활성화 되었습니다.\n");
    }else
    {
        printf("BOLD 옵션이 비활성화 되었습니다.\n");
    }

    if (attr & ITALIC >> 1 )
    {
        printf("ITALIC 옵션이 활성화 되었습니다.\n");
    }else
    {
        printf("ITALIC 옵션이 비활성화 되었습니다.\n");
    }

    return 0;

}

