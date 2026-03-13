#include "serial.h"

// 시리얼 함수 정의
int getSerialNumber(void)
{
    static int count = 0; // 전역 변수를 사용하지 않고(보안취약점 방지) 함수 내부에서 static으로 선언하여 전역 변수처럼 쓸수있다(스택에는 생성되지 않음). 
    // static으로 선언된 변수는 함수가 처음 호출될 때 한 번만 초기화되고, 이후에는 함수가 호출될 때마다 이전에 저장된 값을 유지합니다.
    // static을 사용하지 않고 int count를 선언하면 호출될때마다 0이 출력되어 값이 증가하지 않는다.

    int result = count; // 현재 count 값을 result에 저장
    ++count; // count 값을 1 증가시킴
    return result;
}