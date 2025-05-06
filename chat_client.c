#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define PORT 9002
#define BUF_SIZE 1024

int main() {
    int sock;
    struct sockaddr_in serv_addr;
    char buf[BUF_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    printf("채팅 서버에 연결됨!\n");

    if (fork() == 0) {
        while (1) {
            fgets(buf, BUF_SIZE, stdin);
            send(sock, buf, strlen(buf), 0);
        }
    } else {
        while (1) {
            int len = recv(sock, buf, BUF_SIZE, 0);
            if (len <= 0) break;
            buf[len] = 0;
            printf("상대방: %s", buf);
        }
    }

    close(sock);
    return 0;
}

