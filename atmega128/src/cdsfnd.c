#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

// ADC 변환 결과를 저장할 전역 변수 (인터럽트 서비스 루틴에서 수정하므로 volatile 선언)
volatile uint16_t ADC_result = 0;

// FND 숫표 표시를 위한 데이터 테이블 (0~9)
    uint8_t FND_DATA_TBL[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

int main(void)
{
    // 포트 설정
    DDRB = 0x10;      // PB4(OC0) 핀을 출력으로 설정 (PWM 출력용)
    DDRA = 0xFF;      // PORTA를 출력으로 설정 (FND 제어용)

    // 타이머/카운터 0 설정 (PWM 제어용)
    TCCR0 = 0x62;     // Fast PWM 모드, 비반전 출력 모드, 분주비 64
    TCNT0 = 0x00;     // 타이머 카운터 초기화

    // ADC 설정
    ADMUX = 0x40;     // 기준 전압 AVCC(5V), ADC0 채널 선택
    ADCSRA = 0xAF;    // ADC 활성화, 프리 러닝 모드, 인터럽트 허용, 프리스케일러 128
    ADCSRA |= 0x40;   // ADC 변환 시작 (ADSC 비트 Set)

    sei();            // 전역 인터럽트 허용

    while (1)
    {
        uint8_t fnd_index = 0;

        // 조도 센서 값에 따른 PWM(LED 밝기) 제어
        if (ADC_result < 40) // 최저 밝기 제한
        {
            OCR0 = 0;
            fnd_index = 0;
        }
        else if(ADC_result > 700) // 최고 밝기 제한
        {
            OCR0 = 255;
            fnd_index = 9;
        }
        else // 40 ~ 700 사이의 값을 0 ~ 255 범위로 매핑 (660 구간)
        {
            OCR0 = (ADC_result - 40) * 255 / 660;
            // 40~700 사이를 0~9 단계로 나누어 계산
            fnd_index = (uint16_t)(ADC_result - 40) * 9 / 660;
        }

        // FND에 결과 출력
        PORTA = FND_DATA_TBL[fnd_index];

        _delay_ms(200); // 0.2초 대기
    }
    return 0;
}

ISR(ADC_vect) // ADC 변환 완료 인터럽트 서비스 루틴
{
    ADC_result = ADC; // 변환된 10비트 결과를 읽어 전역 변수에 저장
}