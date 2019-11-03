#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char * argv[] = { "long_wait" , 0 };

int main() {
    for(int i = 0; i < 10; i++) {
        int f = fork();

        if(f < 0) {
            printf(2, "fork() failed\n");
            exit();
        } else if(f == 0) {
            exec(argv[0], argv);
            printf(2, "exec() failed\n");
            exit();
        }
    }

    for(int i = 0; i < 10; i++)
        wait();

    exit();
}
