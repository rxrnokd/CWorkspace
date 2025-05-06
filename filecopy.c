#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int src_fd, dest_fd;
    char buf[BUF_SIZE];
    ssize_t bytes;

    if (argc != 3) {
        fprintf(stderr, "사용법: %s <원본파일> <대상파일>\n", argv[0]);
        exit(1);
    }

    src_fd = open(argv[1], O_RDONLY);
    if (src_fd < 0) {
        perror("원본 파일 열기 실패");
        exit(1);
    }

    dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) {
        perror("대상 파일 열기 실패");
        close(src_fd);
        exit(1);
    }

    while ((bytes = read(src_fd, buf, BUF_SIZE)) > 0) {
        if (write(dest_fd, buf, bytes) != bytes) {
            perror("쓰기 오류");
            break;
        }
    }

    close(src_fd);
    close(dest_fd);
    return 0;
}

