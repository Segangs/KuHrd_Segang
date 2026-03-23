#include <avr/io.h>
#include <util/delay.h>

int main()
{
    uint8_t led_data = 0x00; // 초기 꺼짐
    DDRC = 0x0F;             // DDRC = 0x00001111;

    while (1)
    {
        PORTC = led_data;
        led_data++;
        if (led_data > 0x0F)
            led_data = 0;
        _delay_ms(100);

    }

    return 0;
}