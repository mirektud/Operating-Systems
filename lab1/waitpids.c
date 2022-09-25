#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
pid_t pid, return_pid;
    pid = fork(); /* Fork a child process */
    if (pid < 0) {          /* Error occurred */
        printf("Fork failed\n");
        return 1; 
    }
    else if (pid == 0){      /* Child process */
        printf("\nHello World, this is the Child!\n");
        printf("My PID is %d\n", getpid());
        exit(0);             /* Child process completes */
    }
    else {                  /* Parent process */
        return_pid = wait(NULL);         /* Parent will wait for the child to complete */
        printf("\nHello World, this is the Parent!\n");
        printf("Process PID = %d has completed\n", return_pid);
    }
return 0;
}

