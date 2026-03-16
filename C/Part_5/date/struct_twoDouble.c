#include <stdio.h>

/*  struct 첫번째 예 (이렇게 쓰지 않도록 함)
struct vision
{
    double left;
    double right;
}Vision;

Vision exchange(struct Vision robot); // 3. 안좋은 예. 메모리를 낭비함. 포인터로 넘기는게 가장 좋다. 리턴도 하지 않도록 함. (메모리 바로 수정)

int main(void)
{
    Vision robot; // 1. 메인에 변수 하나 생성 메모리공간 잡아먹고
    printf("시력 입력 : ");
    scanf("%lf %lf", &(robot.left), &(robot.right) );
    robot = exchange(robot);
    printf("바뀐 시력 : %.1lf %.1lf\n", robot.left, robot.right);    
    return 0;
}

Vision exchange(Vision robot) // 2. Visoon robot = robot + 메모리공간 = 메모리를 낭비하는 꼴
{
    double temp;
    temp = robot.left;
    robot.left = robot.right;
    robot.right = temp;
    
    return robot;
} 
*/

typedef struct
{
    double left;
    double right;
}Vision;

void exchange(Vision *robot); 

int main(void)
{
    Vision robot; 
    printf("시력 입력 : ");
    scanf("%lf %lf", &robot.left, &robot.right );
    exchange(&robot);
    printf("바뀐 시력 : %.1lf %.1lf\n", robot.left, robot.right);    
    return 0;
}

void exchange(Vision *robot) 
{
    double temp;
    temp = robot->left; 
    robot->left = robot->right;
    robot->right = temp;
    
   //  return robot;    // 리턴할 필요 없음
} 
