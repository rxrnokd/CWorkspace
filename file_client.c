#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUF_SIZE 1024

int main() {
    int sock;
    struct sockaddr_in serv_addr;
    char buffer[BUF_SIZE];
    FILE *fp;

    // 소켓 생성
    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    // 보낼 파일 열기
    fp = fopen("send_me.txt", "rb");
    if (fp == NULL) {
        perror("파일 열기 실패");
        exit(1);
    }

    int bytes;
    while ((bytes = fread(buffer, sizeof(char), BUF_SIZE, fp)) > 0) {
        send(sock, buffer, bytes, 0);
    }

    printf("파일 전송 완료\n");

    fclose(fp);
    close(sock);

    return 0;
}

