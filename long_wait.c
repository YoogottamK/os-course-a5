#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

#define N 5000000
#define loop 20

int main() {
    volatile int id = getpid();

    for(int i = 0; i < loop; i++) {

#ifndef MLFQ
        printf(1, "pid: %d    %d\n", id, i);
#endif

#ifdef PBS
            if(i == loop / 2)
                set_priority(100 - id);
#endif

        for(int j = 0; j < N; j++) {
            id = id + 1;
            id = id - 1;
        }
    }

    exit();
}
