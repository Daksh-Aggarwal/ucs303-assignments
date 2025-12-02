#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
    int fd = shm_open("shmfile", O_CREAT | O_RDWR, 0666);
    ftruncate(fd, sizeof(int));
    int *ptr = mmap(NULL, sizeof(int), PROT_WRITE, MAP_SHARED, fd, 0);

    for(int i = 1; i <= 10; i++) {
        *ptr = i;
        printf("Produced: %d\n", i);
        sleep(1);
    }
}