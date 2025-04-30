/*Task 10:
Process Creation and Management in C
Write a C program that demonstrates process creation and management:
Use fork() to create a child process.
In the child process, execute an external program (e.g., ls command) using execvp().
In the parent process, wait for the child process to complete and print a message indicating the child’s termination.*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main() {
    pid_t pid;  // Variable to store the process ID

    // Create a child process using fork()
    pid = fork();

    if (pid < 0) {
        // If fork() fails
        perror("Fork failed");
        exit(1);
    }
    
    if (pid == 0) {
        // Child process
        printf("Child process created. Executing external program...\n");
        
        // Execute the 'ls' command using execvp() in the child process
        char *args[] = {"ls", "-l", NULL};  // Arguments for 'ls -l'
        
        if (execvp(args[0], args) < 0) {
            // If execvp() fails
            perror("Execvp failed");
            exit(1);
        }
    } else {
        // Parent process
        printf("Parent process: Waiting for child to complete...\n");

        // Wait for the child process to terminate
        wait(NULL);  // NULL to wait for any child process
        
        printf("Child process terminated. Parent process exiting...\n");
    }

    return 0;
}

