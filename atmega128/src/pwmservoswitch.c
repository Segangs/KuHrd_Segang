#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include "lcd.h"

uint8_t switch_flag = 0, switch_flag_pre = 0x01;

int main(void)
{
    // 서보 신호는 Timer3의 OC3A 핀(PE3)으로 출력한다.
    DDRE = _BV(PE3);
    DDRC = 0x0F;


    // Timer3 Fast PWM mode 14:
    // TOP은 ICR3로 지정하고, OC3A는 비교일치 시 non-inverting 출력으로 사용한다.
    TCCR3A = _BV(COM3A1) | _BV(WGM31);
    TCCR3B = _BV(WGM33) | _BV(WGM32) | _BV(CS31);
    // 분주비 8 기준으로 16MHz / 8 = 2MHz, 타이머 1카운트는 0.5us

    // 40000카운트 x 0.5us = 20ms 주기(50Hz)로 서보 제어 주파수를 만든다.
    ICR3 = 40000;

    // 초기 펄스폭 3000카운트 = 1.5ms로 서보 중립 위치에 해당한다.
    // 일반적인 서보 기준으로 2000~4000카운트는 대략 1.0ms~2.0ms 범위다.
    OCR3A = 3000;

    // LCD에 현재 OCR3A 값을 표시하기 위해 초기화한다.
    lcdInit();
    lcdClear();

    char buffer[16];

    // 펄스폭을 증가/감소시키며 서보를 좌우로 왕복시킨다.
    while (1)
    {

        switch_flag = PINE >> 4;
        if (switch_flag == 0x01 || switch_flag == 0x02 || switch_flag == 0x04 || switch_flag == 0x08)
        // 하나만 눌렀을때 입력되도록.. 두개 동시에 눌러서 오류나는것 방지
        {
             switch_flag_pre = switch_flag; //스위치를 떼었을때에도 계속 유지되도록 저장 공간을 하나 더 만든다.(switch_flag만 쓰면 상태가 유지되지 않음)
            
        }


        if (switch_flag_pre == 0x01) 
        {
            OCR3A = 3000;
            itoa(3000, buffer, 10);
            lcdGotoXY(0, 0);
            lcdPrint(buffer);
            _delay_ms(20);
        }
        else if (switch_flag_pre == 0x02)
        {
            OCR3A = 2200;
            itoa(2200, buffer, 10);
            lcdGotoXY(0, 0);
            lcdPrint(buffer);
            _delay_ms(20);
        }
        else if (switch_flag_pre == 0x04)
        {
            OCR3A = 1300;
            itoa(1300, buffer, 10);
            lcdGotoXY(0, 0);
            lcdPrint(buffer);
            _delay_ms(20);
        }
        else if (switch_flag_pre == 0x08)
        {
            OCR3A = 1000;
            itoa(1000, buffer, 10);
            lcdGotoXY(0, 0);
            lcdPrint(buffer);
            _delay_ms(20);
        }




        // // 1.0ms -> 2.0ms 방향으로 증가시키며 한쪽 끝으로 이동
        // for (int pulse = 2000; pulse <= 4000; pulse += 40)
        // {
        //     OCR3A = pulse;
        //     itoa(pulse, buffer, 10);
        //     lcdGotoXY(0, 0);
        //     lcdPrint(buffer);
        //     _delay_ms(20);
        // }

        // // 2.0ms -> 1.0ms 방향으로 감소시키며 반대쪽으로 복귀
        // for (int pulse = 4000; pulse >= 2000; pulse -= 40)
        // {
        //     OCR3A = pulse;
        //     itoa(pulse, buffer, 10);
        //     lcdGotoXY(0, 0);
        //     lcdPrint(buffer);
        //     _delay_ms(20);
        // }
    }

    return 0;
}
