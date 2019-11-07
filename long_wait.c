#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "proc_stat.h"

#define N 5000000
#define loop 20

int main() {
    volatile int id = getpid();

    for(int i = 0; i < loop; i++) {

        printf(1, "pid: %d    %d\n", id, i);

#ifdef PBS
            if(i == loop / 2)
                set_priority(100 - id);
#endif

        for(int j = 0; j < N; j++) {
            id = id + 1;
            id = id - 1;
        }
    }

    struct proc_stat p;
    getpinfo(&p);

    printf(1, "%d %d %d %d ", p.pid, p.runtime, p.num_run, p.current_queue);
    for(int i = 0; i < NQUE; i++)
        printf(1, "%d ", p.ticks[i]);
    printf(1, "\n");

    exit();
}
