#include <stdio.h>
#include <stdint.h>

int main()
{
    // unsigned char attr; // 0~255까지의 값을 가질 수 있는 부호 없는 8비트 정수형 변수
    uint8_t attr; // unsigned char와 동일한 크기와 범위를 가지나 조금더 명확하게 선언 11111111

    attr = attr ^ attr; //XOR연산, 0으로 초기화할때 많이 씀
    attr = attr | 0b00000001; // 1번옵션 T로 만들기
    printf("attr: 0x%02x\n", attr); // 0b00000001이 16진수로 0x01이므로 attr의 값은 0x01이 됨
    attr = attr | (0b00000010 + 0b00000100); //
    printf("attr: 0x%02x\n", attr); 
    attr = attr & (~0b00000001); // 1번옵션 F로 만들기 (2진법)
    printf("attr: 0x%02x\n", attr); 
    
    return 0;

}

