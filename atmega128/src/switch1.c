#include <avr/io.h>

int main(void)
{
    DDRC = 0x0F; // LED 설정
    DDRE = 0x00; // switch 설정
    uint8_t switch0;

    while(1){

        switch0 = PINE; // 0b 0101 0000
        PORTC = switch0 >> 4; // 0b 0000 0101
        // PORTC = PINE >> 4; // PINE의 메모리(레지스트리)의 정보를 읽어오겠다
        
        // .. 시간이 걸리는 코드 
        //    시간이 걸리는 코드가 스위치를 읽어오는 코드랑 같이있으면 인터럽트로 제어
        
    }
}