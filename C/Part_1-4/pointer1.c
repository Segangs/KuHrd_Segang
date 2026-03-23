// 포인터 기본

#include <stdio.h>
#include <string.h>

int main(void)
{
   // int *p;     
    /* 포인터 변수 선언, p는 int형 포인터이다. 즉, p는 int형 변수의 주소값을 저장할 수 있다. 
    포인터 변수는 메모리 주소를 저장하는 변수이다. 포인터 변수를 선언할 때는 *를 사용하여 포인터임을 나타낸다. 
    포인터 변수는 메모리 주소를 저장하므로, 포인터 변수를 사용할 때는 주소 연산자(&)를 사용하여 변수의 주소값을 전달해야 한다. */

    int Value= 400;  
    /* 일반 변수 선언 */

 //   p = &Value; 
    /* 포인터가 변수의 주소를 가리키도록 하지 않으면 세그먼트 에러가 뜬다.
    포인터 변수 p에 일반 변수 Value의 주소값을 저장한다. &Value는 Value 변수의 주소값을 나타낸다. 
    포인터 변수 p는 Value 변수의 주소값을 저장하므로, p를 사용하여 Value 변수의 값을 간접적으로 접근할 수 있다. */
    

    int *p = &Value; 
    *p = 500;
    /* 포인터 변수를 사용하여 일반 변수의 값을 변경한다. *p는 p가 가리키는 주소에 저장된 값을 나타낸다.
    *p = 200;은 p가 가리키는 주소에 200이라는 값을 저장한다. 즉, Value 변수의 값이 200으로 변경된다. */

    printf("포인터 ptr의 주소는 %p 이고, 가리키는 값은 %d 이다.\n", p, *p);
    // printf("포인터 ptr의 주소는 %d 이고, 가리키는 값은 %d 이다.\n", *ptr, &Value);  //에러


    //아래는 혼공씨 예제
    int num01 = 1234;

    double num02 = 3.14;
    int *ptr_num01 = &num01;
    double *ptr_num02 = &num02;

    printf("포인터의 크기는 %d입니다.\n", sizeof(ptr_num01));
    printf("포인터 ptr_num01이 가리키고 있는 주소값은 %#x입니다.\n", ptr_num01);
    printf("포인터 ptr_num02가 가리키고 있는 주소값은 %#x입니다.\n", ptr_num02);
    printf("포인터 ptr_num01이 가리키고 있는 주소에 저장된 값은 %d입니다.\n", *ptr_num01);
    printf("포인터 ptr_num02가 가리키고 있는 주소에 저장된 값은 %f입니다.\n", *ptr_num02);

    return 0;
}