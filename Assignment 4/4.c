#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("test.txt", O_RDONLY);
    char buf[50];
    int n = read(fd, buf, 50);
    write(1, buf, n);
    close(fd);
}