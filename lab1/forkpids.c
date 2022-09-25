#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

pid_t pid;

    pid = fork(); /* Fork a child process */
    
    
    if (pid < 0) {          /* Error occurred */
        printf("Fork failed\n");
        return 1; 
    }
    else if (pid == 0){      /* Child process */
        
        printf("\nHello World, this is the Child!\n");
	printf("My parent's process ID is: %d\n", getppid());
        printf("My process ID is: %d\n", getpid());
    }
    else {                  /* Parent process */
        
        printf("\nHello World, this is the Parent!\n");
	printf("My parent's process ID is: %d\n", getppid());
        printf("My process ID is: %d\n", getpid());
        printf("My child's process ID is: %d\n", pid);
    }
    
return 0;
}

