#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main() {
    int id = getpid();
    for(int i = 0; i < 10; i++) {
        printf(1, "pid: %d    %d\n", id, i);

        for(volatile int j = 0; j < 5000000; j++) {
            j += 1;
            j -= 1;
        }
    }

    exit();
}
