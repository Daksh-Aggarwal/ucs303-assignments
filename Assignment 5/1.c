#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t p = fork();

    if (p == 0)
        printf("Child: PID=%d PPID=%d\n", getpid(), getppid());
    else
        printf("Parent: PID=%d PPID=%d\n", getpid(), getppid());

    return 0;
}
