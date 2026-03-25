// 인터럽트 예제
// _delay_ 함수는 내부 함수이므로 사용하지 않아야 한다. (교육상으로만 배움)

#include <avr/io.h>
#include <avr/interrupt.h>

// 인터럽트 핸들러에서 변경할 전역 변수는 volatile로 선언
volatile uint8_t milliseconds = 0;

// 타이머0 overflow 인터럽트 서비스 루틴
ISR(TIMER0_OVF_vect)
{
    // 이 ISR은 자동으로 중단 가능 상태가 아니므로,
    // 호출 중 다른 같은 우선순위(또는 낮은 우선순위) 인터럽트의
    // 중단을 방지함.
    ++milliseconds; // 타이머0 오버플로우 발생 시마다 카운트 증가
    // 여기에 복잡한 작업을 넣으면 안 됨 (응답성 저하)
}

// 타이머0 설정 함수
void timer0_init(void)
{
    // 클럭 분주: CS02, CS01, CS00 모두 1 => 분주 1024
    // 타이머0가 CPU 클록/1024로 카운트
    TCCR0 = _BV(CS02) | _BV(CS01) | _BV(CS00);

    // 타이머0 오버플로우 인터럽트 허용
    TIMSK |= _BV(TOIE0);

    // 전역 인터럽트 허용
    sei();
}

int main()
{
    timer0_init(); // 타이머 및 인터럽트 초기화

    // 7세그먼트 10진 숫자 패턴 (common cathode 기준)
    uint8_t numbers[] = {
        0x3F, // 0
        0x06, // 1
        0x5B, // 2
        0x4F, // 3
        0x66, // 4
        0x6D, // 5
        0x7D, // 6
        0x07, // 7
        0x7F, // 8
        0x6F  // 9
    };

    int count = 0;    // 현재 표시할 숫자 인덱스
    DDRA = 0xFF;      // PORTA를 출력으로 설정

    while (1)
    {
        // 타이머 오버플로우가 32번 발생할 때마다 7세그먼트 숫자 변경
        if (milliseconds >= 32)
        {
            milliseconds = 0;        // 카운터 리셋
            count = (count + 1) % 10; // 0~9 반복
            PORTA = numbers[count];   // PORTA에 7세그먼트 패턴 출력
        }
    }

    return 0;
}