#include <stdio.h>

int main(void) {
    FILE *a;
    a = fopen("test2.dat", "w");
    printf("파일 디스크립터 번호: %d\n", a->_fileno);

    if (a==NULL)
    {
        printf("파일을 열수 없습니다. \n");
        return -1;
    }

    fputs("이것은 파일포인터로 저장되는 예시 데이터입니다. \n", a);
    fclose(a);

    return 0;
}
