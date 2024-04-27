#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid < 0) {
        // Error handling if fork fails
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // This code runs in the child process

        // Set higher priority for the child process
        if (nice(-10) == -1) {
            perror("nice");
            exit(EXIT_FAILURE);
        }

        // Print current priority to confirm
        printf("Child process priority: %d\n", getpriority(PRIO_PROCESS, 0));

        // Child process work here
        printf("Child process: My PID is %d\n", getpid());

    } else {
        // This code runs in the parent process

        // Print current priority
        printf("Parent process priority: %d\n", getpriority(PRIO_PROCESS, 0));

        // Parent process work here
        printf("Parent process: My PID is %d\n", getpid());

        // Wait for the child process to finish
        wait(NULL);
    }

    return 0;
}