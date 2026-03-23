# 📚 C언어 만능 스택(Generic Stack) 뽀개기

이 문서는 `myStack4` 폴더의 코드를 분석하여, **어떤 데이터든 저장할 수 있는 스택**이 어떻게 작동하는지 쉽게 설명합니다.

---

## 1. 핵심 개념: 왜 "만능"인가요?

보통 스택은 `int`만 저장하거나 `double`만 저장하도록 만듭니다. 하지만 이 코드는 **`void *` (보이드 포인터)**를 사용하여 **자료형에 상관없이** 데이터를 저장할 수 있습니다.

- **일반 스택:** 정수 전용 상자 📦 (정수만 넣을 수 있음)
- **만능 스택:** 마법의 상자 ✨ (크기만 알려주면 무엇이든 넣을 수 있음)

---

## 2. 구조체 분석 (`stack4.h`)

스택을 관리하기 위한 설계도입니다.

```c
typedef struct
{
    void *pArr;    // 🏠 스택의 시작 주소 (무엇이든 가리킬 수 있는 포인터)
    int eleSize;   // 📏 데이터 하나당 크기 (int면 4바이트, double이면 8바이트)
    int *tos;      // 👆 현재 데이터가 쌓인 위치 (Top of Stack)
    int size;      // 📦 스택이 담을 수 있는 최대 개수
} Stack;
```

> **포인트:** `eleSize`가 중요합니다! 데이터의 타입을 모르기 때문에, "몇 바이트씩 잘라서 쓸지" 미리 기록해두는 것입니다.

---

## 3. 주요 함수 동작 원리 (`stack4.c`)

### ① `initStack` (창고 짓기)
스택을 처음 만들 때, 내가 무엇을 담을지(크기)를 알려줍니다.

```c
void initStack(Stack *ps, int size, int eleSize)
{
    // 전체 필요한 메모리 = (데이터 1개 크기) * (개수)
    ps->pArr = malloc(eleSize * size); 
    ps->eleSize = eleSize; 
    // ...
}
```

### ② `push` (데이터 넣기)
값을 넣을 때는 **`memcpy` (메모리 복사)**를 사용합니다. 타입을 따지지 않고 바이트 단위로 복사해서 붙여넣습니다.

```c
void push(Stack *ps, const void *pData)
{
    // 1. 현재 tos 위치에 데이터를 'eleSize'만큼 복사합니다.
    memcpy(ps->tos, pData, ps->eleSize);
    
    // 2. tos를 다음 빈 칸으로 이동시킵니다.
    // (unsigned char*)로 형변환 하는 이유는 1바이트 단위로 정확히 계산하기 위함입니다.
    ps->tos = (unsigned char *)ps->tos + ps->eleSize;
}
```

### ③ `pop` (데이터 꺼내기)
넣을 때와 반대 순서로 작동합니다.

```c
void pop(Stack *ps, void *pData)
{
    // 1. tos를 데이터가 있는 이전 칸으로 되돌립니다.
    ps->tos = (unsigned char *)ps->tos - ps->eleSize;
    
    // 2. 그 위치의 데이터를 사용자에게 복사해줍니다.
    memcpy(pData, (unsigned char *)ps->tos, ps->eleSize);
}
```

---

## 4. 실전 사용 예시 (`main.c`)

이 코드가 대단한 이유는 **하나의 코드로 두 가지 스택**을 동시에 다루기 때문입니다.

### 1) 정수(int) 스택 만들기
```c
Stack s1;
initStack(&s1, 10, sizeof(int)); // "4바이트짜리 데이터 10개 저장할래"

int i = 100;
push(&s1, &i); // 정수 주소를 넘겨주면 복사해서 저장함
```

### 2) 실수(double) 스택 만들기
```c
Stack s2;
initStack(&s2, 100, sizeof(double)); // "8바이트짜리 데이터 100개 저장할래"

double d = 1.1;
push(&s2, &d); // 실수 주소를 넘겨주면 복사해서 저장함
```

---

## 5. 요약 및 주의사항

1.  **`void *`의 힘:** 타입을 가리지 않고 주소만 받아서 처리합니다.
2.  **`memcpy` 사용:** 대입(`=`) 연산자 대신 메모리를 직접 복사합니다.
3.  **포인터 연산:** `tos`를 이동시킬 때 `(unsigned char *)`로 변환하여 바이트 단위로 정밀하게 이동합니다.
4.  **사용자 책임:** `pop` 할 때, 내가 넣은 데이터 타입(int 혹은 double)에 맞는 변수에 값을 받아와야 합니다.

> **💡 결론:** 이 코드는 C언어의 **메모리 조작 능력**을 보여주는 아주 훌륭한 예제입니다!

---
Created by Gemini Code Assist