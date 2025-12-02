#include <sys/msg.h>
#include <stdio.h>

struct msg { long type; char text[50]; };

int main() {
    int q = msgget(1234, 0666);
    struct msg m;
    msgrcv(q, &m, sizeof(m.text), 1, 0);
    printf("Received: %s\n", m.text);
    msgctl(q, IPC_RMID, NULL);
}
