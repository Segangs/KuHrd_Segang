//공용체 UNION - 메모리 아낄때 사용 , 덮어씌워지기때문에 잘 안씀..
// 책 530p

#include <stdio.h>

union student
{
    int num;
    double grade;
};

int main(void) {
    union student s1 = {315};
    printf("학번: %d\n", s1.num);   //315
    
    s1.grade = 4.4;
    printf("학점: %1lf\n", s1.grade);    // 4.4
    printf("학번: %d\n", s1.num);    // -1717986918
    return 0;
}