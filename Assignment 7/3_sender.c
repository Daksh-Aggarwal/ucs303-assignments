#include <sys/msg.h>
#include <stdio.h>

struct msg { long type; char text[50]; };

int main() {
    int q = msgget(1234, 0666 | IPC_CREAT);
    struct msg m = {1, "Hello"};
    msgsnd(q, &m, sizeof(m.text), 0);
    return 0;
}
