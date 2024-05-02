#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child_pid;

    // Create a child process
    child_pid = fork();

    if (child_pid < 0) {
        // Fork failed
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (child_pid == 0) {
        // Child process
        printf("Child process created with PID: %d\n", getpid());
        // Sleep to make the child process a zombie
        sleep(2);
        printf("Child process exiting\n");
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        printf("Parent process with PID: %d\n", getpid());
        // Sleep to make sure the child process becomes a zombie before parent exits
        sleep(5);
        printf("Parent process exiting\n");
        exit(EXIT_SUCCESS);
    }

    return 0;
}

