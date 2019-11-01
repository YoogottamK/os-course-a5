#include "types.h"
#include "user.h"

int main() {
    for(int i = 0; i < 10; i++){
        int f = fork();

        if(f == 0) {
            for(volatile int i = 0; i < 2000000; i++) {
                i += 1;
                i -= 1;
            }

            exit();
        } else {
            int rtime, wtime;
            waitx(&wtime, &rtime);

            printf(1, "rtime = %d\nwtime = %d\n", rtime, wtime);
        }
    }
    exit();
}
