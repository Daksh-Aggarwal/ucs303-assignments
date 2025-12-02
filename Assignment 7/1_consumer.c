#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
    int fd = shm_open("shmfile", O_RDONLY, 0666);
    int *ptr = mmap(NULL, sizeof(int), PROT_READ, MAP_SHARED, fd, 0);

    for(int i = 1; i <= 10; i++) {
        printf("Consumed: %d\n", *ptr);
        sleep(1);
    }

    shm_unlink("shmfile");
}
