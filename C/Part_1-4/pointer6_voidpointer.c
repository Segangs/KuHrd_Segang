#include <stdio.h>

int main(void)
{
    int i = 100;
    double d = 3.14;

    void *p; 
    /* void 포인터 선언, void 포인터는 어떤 타입의 데이터도 가리킬 수 있는 포인터이다. 
    void 포인터는 메모리 주소만 저장할 수 있고, 그 주소에 저장된 데이터의 타입을 알 수 없기 때문에, 
    void 포인터를 사용할 때는 반드시 적절한 타입으로 캐스팅하여 사용해야 한다. 
    역참조가 불가능하다. 타입캐스팅을 하면 참조가 가능하다) */

    p = &i;
    *(int *)p = 200;

    p = &d;
    *(double *)p = 2.718;
    printf("i : %d, d : %f, *p : %f", i , d, *(double *)p);




    return 0;

}