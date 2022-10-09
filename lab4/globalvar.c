#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
int myValue = 100;
int main(){
pid_t pid;
    pid = fork(); /* Fork a child process */
    if (pid < 0) {          /* Error occurred */
        printf("Fork failed\n");
        return 1; 
    }
    else if (pid == 0){      /* Child process */
        printf("\nHello World, this is the Child!\n");
         printf("myValue is %d \n", myValue);
        exit(0);             /* Child process completes */
    }
    else {                  /* Parent process */
        wait(NULL);         /* Parent will wait for the child to complete */
        printf("\nHello World, this is the Parent!\n");
        printf("myValue is %d \n", myValue);
    }
return 0;
}
