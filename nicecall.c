#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/wait.h> // Added this header for wait()

int main() {
    pid_t pid;
    int child_priority, new_priority;

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Child process: PID = %d\n", getpid());
        
        // Get the current nice value of the child process
        child_priority = nice(0);
        printf("Child process initial priority (nice value): %d\n", child_priority);
        
        // Increase priority by 5
        new_priority = nice(5);
        printf("Child process new priority (nice value): %d\n", new_priority);

        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        printf("Parent process: PID = %d\n", getpid());
        wait(NULL); // Wait for child to finish
        printf("Parent process exiting\n");
    }

    return 0;
}


