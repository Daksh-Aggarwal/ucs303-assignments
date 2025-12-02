#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    if (fork() == 0) {
        printf("Child exiting\n");
        exit(5);
    } else {
        int status;
        wait(&status);
        printf("Child exited with %d\n", WEXITSTATUS(status));
    }
}
