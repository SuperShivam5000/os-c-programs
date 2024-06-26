#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    
    if (pid > 0) {
        printf("Parent process\n");
        sleep(10);
    } else if (pid == 0) {
        printf("Child process\n");
        exit(0);
    } else {
        printf("Fork failed\n");
        return 1;
    }

    return 0;
}
