#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Enter at least one input argument in the command line\n");
        printf("Usage: ./myEcho <input argument 1> <input argument 2> ... <input argument n>\n");
        return 0;
    }

// Child processes: execute the 'echo' command
for (int i = 1; i < argc; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            printf("Fork failed\n");
            return 0;
        } else if (pid == 0) {
            execlp("echo", "echo", argv[i], NULL);
        exit(0);
        }
}

// Parent process: wait for all child processes and print their PIDs
for (int i = 1; i < argc; i++) {
        pid_t returned_pid;
        returned_pid = wait(NULL);
        printf("Child process PID=%d terminated\n", returned_pid);
}

return 0;
}
