// 파일디스크립터로 파일 열고, 쓰고, 다루는 방식



#include <stdio.h>      // printf, sprintf 함수 사용을 위해 포함
#include <fcntl.h>      // open 함수 및 파일 옵션 사용을 위해 포함
#include <unistd.h>     // write, close 함수 사용을 위해 포함


int main(void) {
    
    int fd;     // 파일 디스크립터를 저장할 정수 변수
    char *path = "/home/segang/segang/C/Part_6"; // 파일이 생성될 디렉토리 경로
    char fpath[100];    // 전체 파일 경로를 저장할 문자 배열

    // sprintf 함수로 디렉토리 경로와 파일명을 합쳐 전체 파일 경로를 만듭니다.
    sprintf(fPath, "%s%s", path, "/test.dat,");

    // open 함수로 파일을 엽니다.
    // O_WRONLY: 쓰기 전용
    // O_CREAT: 파일이 없으면 생성
    // O_TRUNC: 파일이 존재하면 내용 삭제
    // 0644: 파일 권한
    fd = open(fPath, 0_WRONLY | 0_CREAT | 0_TRUNC, 0644); //0644는 권한

    // 파일 열기 실패 시 -1을 반환합니다.
    if (fd == -1)
        printf("파일을 열수 없습니다. \n"); // 실패 메시지를 출력합니다.

        // write 함수로 파일에 데이터를 씁니다.
        write(fd, "이것은 파일로 저장되는 예시 데이터입니다.!:", 63);

        // 사용이 끝난 파일은 반드시 close로 닫아줍니다.
        close(fd);  // open했으면 반드시 close

    return 0;
}
