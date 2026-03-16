#include "struct_twoDouble.h"

void exchange(Vision *robot) 
{
    double temp;
    temp = robot->left; 
    robot->left = robot->right;
    robot->right = temp;
    
   //  return robot;    // 리턴할 필요 없음
} 
