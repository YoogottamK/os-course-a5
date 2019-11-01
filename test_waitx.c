#include "types.h"
#include "user.h"

int main(int argc, char * argv[]) {
    int f = fork();

    if(f == 0) {
        for(volatile int i = 0; i < 200000000; i++) {
            i += 1;
            i -= 1;
        }
    } else {
        int rtime, wtime;
        waitx(&wtime, &rtime);

        printf(1, "%d %d\n", rtime, wtime);
    }
}
