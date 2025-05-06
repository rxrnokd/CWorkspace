#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define PORT 9002
#define BUF_SIZE 1024

int main() {
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_addr, clnt_addr;
    socklen_t clnt_size;
    char buf[BUF_SIZE];

    serv_sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    listen(serv_sock, 5);
    printf("채팅 서버 대기 중...\n");

    clnt_size = sizeof(clnt_addr);
    clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_size);

    if (fork() == 0) { // 자식 프로세스 - 송신
        while (1) {
            fgets(buf, BUF_SIZE, stdin);
            send(clnt_sock, buf, strlen(buf), 0);
        }
    } else { // 부모 프로세스 - 수신
        while (1) {
            int len = recv(clnt_sock, buf, BUF_SIZE, 0);
            if (len <= 0) break;
            buf[len] = 0;
            printf("상대방: %s", buf);
        }
    }

    close(clnt_sock);
    close(serv_sock);
    return 0;
}

