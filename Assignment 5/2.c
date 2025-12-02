#include <stdio.h>
#include <unistd.h>

int main() {
    if (fork() == 0) {          // Child
        sleep(5);               // Parent will exit → child becomes orphan
        printf("Orphan: %d, New PPID=%d\n", getpid(), getppid());
    } else {                    // Parent
        fork();                 // Create another child for zombie demo
        if (fork() == 0)
            return 0;           // Child exits → becomes zombie
        sleep(10);              // Parent sleeps → zombie exists during sleep
    }
    return 0;
}
