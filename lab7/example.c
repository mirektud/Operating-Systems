#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void *perform_ping(void *arg) {
    char *ip = (char *)arg;  // IP address passed as an argument
    pid_t pid;

    printf("IN THREAD: Pinging IP: %s - Starting process\n", ip);

    // Fork to create a child process
    pid = fork();

    if (pid == 0) {
        // Child process: run the ping command
        execlp(...);  // Ping 3 times
    } 
    else {
        // Parent thread: wait for the child process to finish
        // (...)
        printf("IN THREAD: Pinging IP: %s - Completed process\n", ip);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    char *ip_address = "127.0.0.1";  // Hardcoded IP address to pass to the thread

    // Create a thread and pass the IP address as an argument
    printf("IN MAIN: Creating thread to ping IP: %s\n", ip_address);
    pthread_create(&thread, NULL, perform_ping, (void *)ip_address);

    // Wait for the thread to complete
    pthread_join(...);
    printf("IN MAIN: Thread has finished.\n");

    printf("IN MAIN: Program completed.\n");
    return 0;
}

