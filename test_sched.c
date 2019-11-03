#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char * argv[] = { "long_wait" };

int main() {
    for(int i = 0; i < 10; i++) {
        int f = fork();

        if(f == 0) {
            exec(argv[0], argv);
            exit();
        }
    }

    for(int i = 0; i < 10; i++)
        wait();

    exit();
}
