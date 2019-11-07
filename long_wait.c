#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main() {
    volatile int id = getpid();

#ifdef PBS
    set_priority(100 - id);
#endif

    for(int i = 0; i < 10; i++) {
#ifndef MLFQ
        printf(1, "pid: %d    %d\n", id, i);
#endif

        for(int j = 0; j < 5000000; j++) {
            id = id + 1;
            id = id - 1;
        }
    }

    exit();
}
