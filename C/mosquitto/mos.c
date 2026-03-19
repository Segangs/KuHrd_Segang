#include "MQTTClient.h"
#include <stdio.h>
#include <string.h>

// 클라이언트 ID와 토픽을 정의합니다.
#define CLIENTID "Segang"
#define TOPIC "school/test"

int main()
{
    // 발송할 브로커 주소 목록
    const char *addresses[] = {
        "tcp://163.152.213.113:1883",
        "tcp://163.152.213.214:1883",
        // 추가 주소를 여기에 계속 작성
    };

    // 배열 요소 개수를 계산
    const int addressCount = sizeof(addresses) / sizeof(addresses[0]);

    // 전송할 메시지 페이로드
    const char *payload =
        "\n안녕하세요 장세강입니다.\n"
        "  _   _      _ _        __        __         _     _ _ _\n"
        " | | | | ___| | | ___   \\ \\      / /__  _ __| | __| | | |\n"
        " | |_| |/ _ \\ | |/ _ \\   \\ \\ /\\ / / _ \\| '__| |/ _` | | |\n"
        " |  _  |  __/ | | (_) |   \\ V  V / (_) | |  | | (_| |_|_|\n"
        " |_| |_|\\___|_|_|\\___/     \\_/\\_/ \\___/|_|  |_|\\__,_(_|_)";

    // 주소 목록 각각에 연결 및 publish 반복
    for (int i = 0; i < addressCount; ++i)
    {
        MQTTClient client;
        MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
        MQTTClient_message pubmsg = MQTTClient_message_initializer;

        printf("[%d/%d] 접속 시도: %s\n", i + 1, addressCount, addresses[i]);

        // 클라이언트 객체 생성
        MQTTClient_create(&client, addresses[i], CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);

        // 브로커 연결 시도
        if (MQTTClient_connect(client, &conn_opts) != MQTTCLIENT_SUCCESS)
        {
            printf("%s 접속 실패!\n", addresses[i]);
            MQTTClient_destroy(&client);  // 리소스 정리
            continue;                    // 다음 주소로 이동
        }

        // 메시지 데이터 설정
        pubmsg.payload = (char *)payload;
        pubmsg.payloadlen = (int)strlen(payload);
        pubmsg.qos = 1;

        // 메시지 발행
        if (MQTTClient_publishMessage(client, TOPIC, &pubmsg, NULL) == MQTTCLIENT_SUCCESS)
        {
            printf("%s에 메시지 전송 완료!\n", addresses[i]);
        }
        else
        {
            printf("%s에 메시지 전송 실패!\n", addresses[i]);
        }

        // 연결 종료 및 클라이언트 객체 파괴
        MQTTClient_disconnect(client, 10000);
        MQTTClient_destroy(&client);
    }

    return 0;
}
