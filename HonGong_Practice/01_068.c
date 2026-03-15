#include <stdio.h>

int main(void) {
    printf("%.1lf\n", 1e6); // 1000000.0
    printf("%.7lf\n", 3.14e-5); //  0.0000314 
    printf("%le\n", 0.0000314); // 3.140000e-05
    printf("%.2le\n", 0.0000314); // 3.14e-05
    
    return 0;
}