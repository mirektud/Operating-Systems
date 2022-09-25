#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
pid_t pid;
    pid = fork();           /* Fork a child process */
    if (pid < 0) {          /* Error occurred */
        printf("Fork failed\n");
        return 1; 
    }
    else if (pid == 0){      /* Child process */
        printf("Child's process is running with PID = %d\n", getpid());
        while(1);             /* Child process completes */
    }
    else {                  /* Parent process */
        printf("\nParent's process is terminating with PID = %d\n", getpid());
        exit(0);
    }
return 0;
}
