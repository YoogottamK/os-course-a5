#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


int main(int argc, char * argv[]) {
    int f = fork();

    if(f == 0) {
        close(0);
        close(1);
        close(2);
        exec(argv[1], argv);
    } else {
        int rtime, wtime;
        waitx(&wtime, &rtime);

        printf(1, "rtime = %d\nwtime = %d\n", rtime, wtime);
    }
    exit();
}
