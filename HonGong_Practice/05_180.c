#include <stdio.h>

int main(void)
{
    int front, rear, result = 0;
    char operator;

    printf("사칙연산 입력(정수) : ");
    scanf("%d%c%d", &front, &operator, &rear);

    if (operator == '+')
        result = front + rear;
    else if(operator == '-')
        result = front - rear;
    else if(operator == '/')
        result = front / rear;
    else if(operator == '*')
        result = front * rear;
    else
        printf("잘못 입력하셨읍니다.\n");
    
    printf("%d%c%d=%d\n", front, operator, rear, result);// 귀찮아서 대충함
    return 0;
}