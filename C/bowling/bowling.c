#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// 볼링 프레임 구조체
typedef struct
{
    int throws[3];   // 투구 점수 (10프레임은 최대 3번)
    int score;       // 해당 프레임까지의 누적 점수
    int throw_count; // 현재 프레임에서 몇 번 던졌는지
    bool is_done;    // 프레임 종료 여부
} Frame;

typedef struct
{
    char name[50];
    Frame frames[10];
    int current_frame; // 0 ~ 9
    int current_throw; // 1, 2, or 3 (display purpose mostly)
} Player;

void init_player(Player *p);
void print_board(Player *p);
void calculate_scores(Player *p);

int main(void)
{
    Player player;
    int seed;
    int pins_knocked;
    int remaining_pins;
    int consecutive_strikes = 0;

    init_player(&player);

    // 1. 화면 clear 및 이름 입력
    system("clear");
    printf("볼링 게임을 시작합니다!\n");
    printf("플레이어 이름을 입력하세요: ");
    scanf("%s", player.name);

    printf("볼링 게임을 시작합니다\n"); // 2. 인사

    while (player.current_frame < 10)
    {
        // 3. 유효한 점수(시드) 입력 받기
        printf("유효한 점수를 입력하세요 (0-3): ");
        if (scanf("%d", &seed) != 1) {
            while(getchar() != '\n'); // 입력 버퍼 비우기
            continue;
        }
        srand(seed); // 난수 시드 설정

        // 4. 점수 계산 (볼링 룰 적용)
        // 현재 프레임 포인터
        Frame *f = &player.frames[player.current_frame];
        
        // 남은 핀 계산
        if (player.current_frame < 9) {
            // 1~9 프레임
            if (f->throw_count == 0) {
                remaining_pins = 10;
            } else {
                remaining_pins = 10 - f->throws[0];
            }
        } else {
            // 10 프레임 특수 룰
            if (f->throw_count == 0) {
                remaining_pins = 10;
            } else if (f->throw_count == 1) {
                // 첫번째가 스트라이크면 다시 10개 세팅, 아니면 남은거
                if (f->throws[0] == 10) remaining_pins = 10;
                else remaining_pins = 10 - f->throws[0];
            } else { // throw_count == 2
                // 두번째가 스트라이크거나 스페어처리면 10개, 아니면 남은거(사실상 오픈이면 끝이지만 로직상)
                if (f->throws[1] == 10 || (f->throws[0] + f->throws[1] == 10)) remaining_pins = 10;
                else remaining_pins = 10 - f->throws[1] /*사실 여기서 게임끝*/;
            }
        }

        // 0에서 남은 핀 개수 사이의 난수 생성
        pins_knocked = rand() % (remaining_pins + 1);
        
        // 스트라이크 판별 및 터키(3연속) 체크
        bool is_strike = false;
        if (pins_knocked == 10) {
            if (f->throw_count == 0) is_strike = true;
            else if (player.current_frame == 9) { // 10프레임 추가 투구 처리
                if (f->throw_count == 1 && f->throws[0] == 10) is_strike = true;
                else if (f->throw_count == 2) is_strike = true;
            }
        }
        if (is_strike) consecutive_strikes++;
        else consecutive_strikes = 0;
        
        // 점수 기록
        f->throws[f->throw_count] = pins_knocked;
        f->throw_count++;

        // 프레임 종료 조건 체크
        if (player.current_frame < 9) {
            // 1~9 프레임: 스트라이크거나 2번 던졌으면 종료
            if (f->throws[0] == 10 || f->throw_count == 2) {
                f->is_done = true;
            }
        } else {
            // 10 프레임
            if (f->throw_count == 3) {
                f->is_done = true;
            } else if (f->throw_count == 2) {
                // 스트라이크도 아니고 스페어도 아니면 종료
                if (f->throws[0] + f->throws[1] < 10) {
                    f->is_done = true;
                }
            }
        }

        // 점수 계산 (누적 점수 업데이트)
        calculate_scores(&player);

        // 5. 화면 Clear 및 점수표 출력
        system("clear");
        print_board(&player);

        // 현재 투구 정보 출력
        // 프레임 번호는 0부터 시작하므로 +1, cast도 직전 던진 횟수
        printf("%d frame %d cast : %d\n", player.current_frame + 1, f->throw_count, pins_knocked);

        // 터키 축하 메시지 출력
        if (consecutive_strikes >= 3) {
            printf("\n******************************************\n");
            printf("*           !!! TURKEY !!!               *\n");
            printf("*       3연속 스트라이크 축하합니다!     *\n");
            printf("******************************************\n");
        }

        // 프레임 넘기기
        if (f->is_done) {
            player.current_frame++;
        }
    }

    printf("\n게임 종료! 최종 점수표입니다.\n");
    
    return 0;
}

void init_player(Player *p)
{
    memset(p, 0, sizeof(Player));
}

void calculate_scores(Player *p)
{
    int total = 0;
    for (int i = 0; i < 10; i++) {
        Frame *f = &p->frames[i];
        int frame_score = 0;

        // 아직 완료되지 않은 프레임이 있으면 계산 중단 (단, 스트라이크/스페어 처리를 위해 미래 데이터 필요)
        // 편의상 단순히 계산 가능한지만 체크
        
        if (i < 9) {
            // 1. 스트라이크 (X)
            if (f->throws[0] == 10) {
                frame_score = 10;
                // 다음 2번의 투구 점수 더하기
                if (p->frames[i+1].throw_count > 0) {
                    frame_score += p->frames[i+1].throws[0];
                    if (p->frames[i+1].throws[0] == 10) { // 다음이 스트라이크면 다다음 프레임 첫구(단, 9프레임일땐 10프레임 두번째)
                        if (i == 8) { // 9프레임인 경우 10프레임의 두번째 투구를 더함
                             if (p->frames[i+1].throw_count > 1) frame_score += p->frames[i+1].throws[1];
                             else frame_score = -1; // 데이터 부족
                        } else {
                            if (p->frames[i+2].throw_count > 0) frame_score += p->frames[i+2].throws[0];
                            else frame_score = -1;
                        }
                    } else {
                        if (p->frames[i+1].throw_count > 1) frame_score += p->frames[i+1].throws[1];
                        else frame_score = -1;
                    }
                } else {
                    frame_score = -1; // 데이터 부족
                }
            }
            // 2. 스페어 (/)
            else if (f->throw_count == 2 && (f->throws[0] + f->throws[1] == 10)) {
                frame_score = 10;
                if (p->frames[i+1].throw_count > 0) frame_score += p->frames[i+1].throws[0];
                else frame_score = -1;
            }
            // 3. 오픈
            else if (f->is_done) {
                frame_score = f->throws[0] + f->throws[1];
            } else {
                frame_score = -1; // 진행중
            }
        } else {
            // 10 프레임
            if (f->is_done) {
                frame_score = 0;
                for(int k=0; k<f->throw_count; k++) frame_score += f->throws[k];
            } else {
                frame_score = -1;
            }
        }

        if (frame_score != -1) {
            total += frame_score;
            f->score = total;
        }
    }
}

void print_board(Player *p)
{
    printf("Player name: %s\n", p->name);
    
    // 헤더 출력 (Tab으로 구분하여 깔끔하게 정렬)
    printf("1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n");
    printf("-----------------------------------------------------------------------------\n");
    
    // 투구 결과 출력
    for (int i = 0; i < 10; i++) {
        Frame *f = &p->frames[i];
        char s1[5] = "", s2[5] = "", s3[5] = "";
        char buf[20] = "";
        
        // 10 프레임 처리
        if (i == 9) {
            if (f->throw_count >= 1) sprintf(s1, "%c", f->throws[0] == 10 ? 'X' : f->throws[0] + '0');
            if (f->throw_count >= 2) {
                if (f->throws[1] == 10) sprintf(s2, "X");
                else if (f->throws[0] != 10 && (f->throws[0] + f->throws[1] == 10)) sprintf(s2, "/");
                else sprintf(s2, "%d", f->throws[1]);
            }
            if (f->throw_count >= 3) {
                if (f->throws[2] == 10) sprintf(s3, "X");
                else if (f->throws[1] != 10 && f->throws[1] + f->throws[2] == 10) sprintf(s3, "/");
                else sprintf(s3, "%d", f->throws[2]);
            }
            // 10프레임은 칸 구분 없이 연결하거나 파이프로 구분
            sprintf(buf, "%s%s%s%s%s", s1, s2[0]?" | " : "", s2, s3[0]?" | " : "", s3);
        } 
        // 1~9 프레임 처리
        else {
            if (f->throw_count >= 1) {
                if (f->throws[0] == 10) sprintf(s1, "X");
                else sprintf(s1, "%d", f->throws[0]);
            }
            if (f->throw_count >= 2) {
                if (f->throws[0] + f->throws[1] == 10) sprintf(s2, "/");
                else sprintf(s2, "%d", f->throws[1]);
            }
            // 스트라이크면 두번째 칸 비우기
            if (s1[0] == 'X') sprintf(buf, "X");
            else if (s2[0]) sprintf(buf, "%s | %s", s1, s2);
            else sprintf(buf, "%s", s1);
        }
        printf("%s\t", buf);
    }
    printf("\n");
    
    // 점수 출력 라인
    for (int i = 0; i < 10; i++) {
        if (p->frames[i].score != 0 || (i==0 && p->frames[i].is_done)) printf("%d\t", p->frames[i].score);
        else printf("\t");
    }
    printf("\n-----------------------------------------------------------------------------\n");
}