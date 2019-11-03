#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int main(int argc, char * argv[]) {
    int f = fork();

    if(f == 0) {
        exec(argv[1], argv + 1);
    } else {
        int rtime, wtime;
        waitx(&wtime, &rtime);

        printf(1, "rtime = %d\nwtime = %d\n", rtime, wtime);
    }
    exit();
}
