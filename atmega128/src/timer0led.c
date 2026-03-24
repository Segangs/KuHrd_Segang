#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

uint8_t led_data =

    ISR(TIMER0_OVF_vect);

int main(void)
{
    DDRC = 0x0F;
    TCCR0 = _BV(CS02) | _BV(CS01) | _BV(CS00); // 분주비 1024
    TIMSK = _BV(TOIE0);
    sei();

    while (1)
    {
        led_data++;
        if (led_data > 0x0F)
            led_data = 0;
        timer0_cnt = 0;
    }
    PORTC = led_data;
}

ISR(timer0_cnt)
{
    cli();
    TCNT = 112;
    timer0_cnt++;
    sei();
}