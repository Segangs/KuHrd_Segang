#include <stdio.h>
#include "pico/stdlib.h"

class MY_GPIO// GPIO 핀 관리 클래스
{
private:
    const bool HIGH = 1, LOW = 0; // 상수로 HIGH와 LOW 정의 이 변
    uint pin_num;
    bool dir;

public:
    int set_high();
    int set_low();
    int set_toggle();
    bool get_read();

    MY_GPIO(uint pin_num);
    MY_GPIO(uint pin_num, bool dir);
    ~MY_GPIO();
};

int MY_GPIO::set_high(){//출력으로 설정
    if(this->dir == GPIO_OUT){
        gpio_put(this->pin_num, this->HIGH);
        return 0;
    }
    else{
        return -1;
    }
}

int MY_GPIO::set_low(){//입력으로 설정
    if(this->dir == GPIO_IN){
        gpio_put(this->pin_num, this->LOW);
        return 0;
    }
    else{
        return -1;
    }
}
int MY_GPIO::set_toggle(){
    if(this->dir == GPIO_OUT){
        if (gpio_get(this->pin_num) == this->LOW){
            gpio_put(this->pin_num, this->HIGH);
        }
        else{
            gpio_put(this->pin_num, this->LOW);
        }
        return 0;
    }
    return -1;
}

bool MY_GPIO::get_read(){

}

MY_GPIO::MY_GPIO(uint pin_num) : MY_GPIO(pin_num, GPIO_IN){//위임 생성자
}

MY_GPIO::MY_GPIO(uint pin_num, bool dir){
    this->pin_num = pin_num;
    this->dir = dir;
    gpio_init(this->pin_num);
    gpio_set_dir(this->pin_num, this->dir);
}

MY_GPIO::~MY_GPIO(){
    
}


int main()
{
    stdio_init_all();

    printf("프로그램 시작\n");

    sleep_ms(3000);


    //GPIO 객체 생성
    MY_GPIO led1(21, GPIO_OUT);
    MY_GPIO led2(22, GPIO_OUT);

    MY_GPIO sw1(20, GPIO_IN);



    while (true) {
        //printf("sw1 = %d")


//========================================================
        // led1.set_toggle();
        // led2.set_toggle();

        // sleep_ms(500);
//========================================================
        // led1.set_high();
        // if(led1.set_high() == -1){
        //     printf("출력 방향이 입력이기 때문에 출력 불가\n");
        //     while(1);
        // }
        // led2.set_high();
        // if(led2.set_high() == -1){
        //     printf("출력 방향이 입력이기 때문에 출력 불가\n");
        //     while(1);
        // }
        // printf("LED1: LED2 on\n");
        // sleep_ms(2000);
        // led1.set_low();
        // if(led1.set_low() == -1){
        //     printf("출력 방향이 입력이기 때문에 출력 불가\n");
        //     while(1);
        // }
        // led2.set_low();
        // if(led2.set_low() == -1){
        //     printf("출력 방향이 입력이기 때문에 출력 불가\n");
        //     while(1);
        // }
        // printf("LED1: LED2 off\n");

        // sleep_ms(2000);
        // printf("Hello, world!\n");
    }
}