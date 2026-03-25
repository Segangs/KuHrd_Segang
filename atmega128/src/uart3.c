#include "lcd.h"
#include "uart0.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

// 외부 인터럽트가 들어오면 어떤 스위치가 눌렸는지 문자로 저장한다.
volatile uint8_t int_data = '0';
// LCD 현재 출력 위치를 직접 추적하기 위한 커서 변수.
uint8_t cursor = 0;

FILE OUTPUT = FDEV_SETUP_STREAM(uart0Transmit, NULL, _FDEV_SETUP_WRITE);
FILE INPUT = FDEV_SETUP_STREAM(NULL, uart0Receive, _FDEV_SETUP_READ);

int main(void)
{
    // UART0를 초기화해서 printf / fgetc를 시리얼과 연결한다.
    uart0Init();
    // 문자 LCD를 초기화한다.
    lcdInit();

    stdin = &INPUT;
    stdout = &OUTPUT;

    // PORTE.1을 출력으로 설정한다.
    // 현재 코드에서는 직접 쓰지 않지만, 보드 연결 상태에 따라 LED/제어 핀 용도로 둘 수 있다.
    DDRE = 0x02;

    // INT4~INT7을 상승/하강엣지 방식으로 동작시키는 설정이다.
    // EICRB는 외부 인터럽트 4~7의 감지 조건을 정한다.
    EICRB = 0xFF;
    // INT4~INT7 인터럽트를 허용한다.
    EIMSK = 0xF0;
    // 남아 있을 수 있는 인터럽트 플래그를 먼저 지운다.
    EIFR = 0xF0;

    // 전역 인터럽트 허용.
    sei();
    char cData;
    // char buffer[32];
    // UART로 들어온 문자가 몇 개인지 세기 위한 카운터.
    uint8_t count = 0;

    printf("Hi, I'm Atmega128");
    // LCD 첫 줄 첫 칸으로 이동.
    lcdGotoXY(0, 0);

    while(1)
    {
        // 외부 인터럽트가 발생하면 어느 스위치였는지 UART로 출력한다.
        if(int_data != '0')
        {
            printf("\n\r Input Switch : %c", int_data);
            int_data = '0';
        }

        // UART 수신 버퍼에 문자가 들어와 있는 동안 계속 읽는다.
        while(UCSR0A & (1 << RXC0))
        {
            count++;
            cData = fgetc(stdin);

            // 받은 문자와 문자 번호를 LCD에 순서대로 표시한다.
            lcdDataWrite(cData);
            lcdDataWrite('0' + count);
            cursor++;
            cursor++;

            // LCD 한 줄이 16칸이므로, 16칸이 차면 둘째 줄로 이동한다.
            if(cursor == 16)
                lcdGotoXY(0, 1);
            // 2줄 16칸을 다 채우면 다시 처음 위치로 돌아간다.
            else if(cursor >=32)
            {
                cursor = 0;
                lcdGotoXY(0, 0);
            }
        }
    }
    return 0;
}

ISR(INT4_vect)
{
    // INT4 스위치 입력.
    cli();
    int_data = '1';
    sei();
}

ISR(INT5_vect)
{
    // INT5 스위치 입력.
    cli();
    int_data = '2';
    sei();
}

ISR(INT6_vect)
{
    // INT6 스위치 입력.
    cli();
    int_data = '3';
    sei();
}

ISR(INT7_vect)
{
    // INT7 스위치 입력.
    cli();
    int_data = '4';
    sei();
}
