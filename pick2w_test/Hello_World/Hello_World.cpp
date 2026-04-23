#include <stdio.h>
#include "pico/stdlib.h"

class my_GPIO
{
private:
    const bool HIGH = 1;
    const bool LOW = 0;
    uint pin_num;
    bool dir;

public:
    int setHigh();
    int setLow();

    int setToggle();
    bool getRead();

    // my_GPIO(uint pin_num);
    my_GPIO(uint pin_num, bool dir);
    ~my_GPIO();
};

// 멤버 함수
int my_GPIO ::setHigh()
{
    if (this->dir == GPIO_OUT)
    {
        gpio_put(this->pin_num, this->HIGH);
        return 0;
    }
    else
    {
        return -1;
    }
}

int my_GPIO ::setLow()
{
    if (this->dir == GPIO_OUT)
    {
        gpio_put(this->pin_num, this->LOW);
        return 0;
    }
    else
    {
        return -1;
    }
}

bool my_GPIO::getRead()
{
    return gpio_get(this->pin_num);
}

int my_GPIO::setToggle()
{
    if (gpio_get(this->pin_num) == this->HIGH)
    {
        this->setLow();
    }
    else
    {
        this->setHigh();
    }
}

// 생성자

my_GPIO::my_GPIO(uint pin_num, bool dir = GPIO_IN)
{
    this->pin_num = pin_num;
    this->dir = dir;
    gpio_init(this->pin_num);
    gpio_set_dir(this->pin_num, this->dir);
}

my_GPIO::~my_GPIO()
{
}

int main()
{
    stdio_init_all();
    printf("프로그램 시작 \n");

    // gpio 객체 생성
    my_GPIO led1(21, GPIO_IN);
    my_GPIO led2(22, GPIO_OUT);

    my_GPIO sw1(20, GPIO_IN);


    gpio_pull_down(20);

    int state_led1 = 0; // 0:LOW, 1:HIGH
    bool cur_sw1 = 0;
    bool pre_sw1 = 0;

    while (true)
    {
        cur_sw1 = sw1.getRead();

        if ((pre_sw1 == 0) && (cur_sw1 == 1))
        {
            if (state_led1 == 0)
            {
                led1.setHigh();
                state_led1 = 1;
            }
            else
            {
                led1.setLow();
                state_led1 = 0;
            }
        }

        pre_sw1 = cur_sw1;

        // printf("sw1 = %d\n", sw1.getRead());
        // sleep_ms(1000);

        if (sw1.getRead() == 1)
        {
            if (status_led1 == 0)
            {
                led1.setHigh();
                status_led1 = 1;
            }
            else 
            {
                led1.setLow();
                status_led1 = 0;
            }
            // sleep_ms(300);
        }
    }
}
