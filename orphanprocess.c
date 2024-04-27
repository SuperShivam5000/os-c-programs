#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    
    if (pid > 0) {
        printf("Parent process\n");
        sleep(2);
    } else if (pid == 0) {
        printf("Child process\n");
        sleep(5);
        printf("Orphan process, adopted by init process\n");
    } else {
        printf("Fork failed\n");
        return 1;
    }

    return 0;
}
