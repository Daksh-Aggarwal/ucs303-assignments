#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int a = atoi(argv[1]), b = atoi(argv[2]), s;

    if (fork() == 0)
        exit(a + b);

    wait(&s);
    printf("Sum = %d\n", WEXITSTATUS(s));
    return 0;
}
