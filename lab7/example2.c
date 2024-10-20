#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Thread function to create a child process and run the ping command
void *perform_ping(void *arg) {
    char *ip = (char *)arg;  // IP address passed as an argument
    pid_t pid;

    printf("IN THREAD: Pinging IP: %s - Starting process\n", ip);

    // Fork to create a child process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        printf("IN THREAD: Failed to create child process for IP: %s\n", ip);
        pthread_exit(NULL);
    } 
    else if (pid == 0) {
        // Child process: run the ping command
        execlp("ping", "ping", "-c", "3", ip, NULL);  // Ping 3 times
        // If execlp() fails
        perror("execlp failed");
        exit(1);  // Exit the child process if execlp() fails
    } 
    else {
        // Parent thread: wait for the child process to finish
        wait(NULL);
        printf("IN THREAD: Pinging IP: %s - Completed process\n", ip);
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("IN MAIN: Please provide at least one IP address.\n");
        return 1;
    }

    // Create a thread for each IP address
    pthread_t threads[argc - 1];
    
    for (int i = 1; i < argc; i++) {
        printf("IN MAIN: Creating thread to ping IP: %s\n", argv[i]);
        pthread_create(&threads[i - 1], NULL, perform_ping, argv[i]);
    }

    // Wait for all threads to complete
    for (int i = 1; i < argc; i++) {
        pthread_join(threads[i - 1], NULL);
        printf("IN MAIN: Thread for IP %s finished.\n", argv[i]);
    }

    printf("IN MAIN: Program completed.\n");
    return 0;
}

