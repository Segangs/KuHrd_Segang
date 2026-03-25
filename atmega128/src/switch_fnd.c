// 스위치를 눌렀을때 fnd 숫자가 증가하는 코드 작성
// PINE0 -> ++1, PINE1 -> -1
// 스위치를 오래 눌러도 한번만 변환하게 할것!
// 숫자 범위는 0~9 까지
// 9가 넘어가면 0을 표시하세요.
// 0 아래로 가면 9를 표시하세요.

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    uint8_t switch_flag = 0, switch_flag_pre = 0x01;
    uint8_t FND_DATA_TBL[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};
    int8_t cnt = 0;
    DDRA = 0xFF;
    DDRE = 0x00;

    while (1)
    {
        if (switch_flag != PINE >> 4) // 누르고 있는것 방지
        {
            switch_flag = PINE >> 4;
            if (switch_flag == 0x01 || switch_flag == 0x02)
            {
                switch_flag_pre = switch_flag;
            }

            if (switch_flag_pre == 0x01) // switch_flag_pre
            {
                cnt++;
            }

            else if (switch_flag_pre == 0x02) // switch_flag_pre
            {
                cnt--;
            }
            switch_flag_pre = 0;

            // cnt 범위 0~9
            cnt = cnt % 10;
            if (cnt < 0)
            {
                cnt = 9;
            }
        }

        PORTA = FND_DATA_TBL[cnt];
    }
    return 0;
}