#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    uint8_t switch_flag = 0, switch_flag_pre = 0x01;

    DDRC = 0x0F;
    DDRE = 0x00;
    PORTC = 0x00;

    while (1)
    {
        switch_flag = PINE >> 4;
        if (switch_flag == 0x01 || switch_flag == 0x02 || switch_flag == 0x04 || switch_flag == 0x08)
        // 하나만 눌렀을때 입력되도록.. 두개 동시에 눌러서 오류나는것 방지
        {
            // switch_flag_pre = switch_flag; //스위치를 떼었을때에도 계속 유지되도록 저장 공간을 하나 더 만든다.
            // (switch_flag만 쓰면 상태가 유지되지 않음)
        }
        PORTC ^= 0x0F;

        if (switch_flag == 0x01)   // switch_flag_pre
            _delay_ms(100);
        else if (switch_flag == 0x02)
            _delay_ms(200);
        else if (switch_flag == 0x04)
            _delay_ms(300);
        else if (switch_flag == 0x08)
            _delay_ms(500);
    }

    return 0;
}