#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUF_SIZE 1024

int main() {
    int server_fd, client_fd;
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    char buffer[BUF_SIZE];
    FILE *fp;

    // 소켓 생성
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    // 바인딩
    bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 1);

    printf("서버 대기 중...\n");
    client_fd = accept(server_fd, (struct sockaddr*)&addr, &addr_len);
    printf("클라이언트 연결됨\n");

    // 파일 저장용
    fp = fopen("received_file.txt", "wb");
    if (fp == NULL) {
        perror("파일 열기 실패");
        exit(1);
    }

    int bytes;
    while ((bytes = read(client_fd, buffer, BUF_SIZE)) > 0) {
        fwrite(buffer, sizeof(char), bytes, fp);
    }

    printf("파일 수신 완료\n");

    fclose(fp);
    close(client_fd);
    close(server_fd);

    return 0;
}
