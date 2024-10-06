#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>

int main() {
    char buffer[256];
    int running = 1;

    // shmget returns an ID of the shared memory
    int shm_id = shmget(3333, 1024, 0666|IPC_CREAT);
    printf("Shared memory ID: %d\n", shm_id);

    // attaching shared memory to the address space
    char *str = shmat(shm_id, NULL, 0);
    printf("Shared memory is attached to the address space.\n");

    while(running) {
        // Read input from the user
        printf("\nEnter some text: ");
        fgets(buffer, 256, stdin);

        // Remove trailing newline character from input, if present
        buffer[strcspn(buffer, "\n")] = '\0';

        // Copy the input to the shared memory
        sprintf(str, "%s", buffer);
        printf("Data '%s' is written in shared memory.\n", str);

        // Check if the user input is "end", which will stop the loop
        if (strncmp(buffer, "end", 3) == 0) {
            running = 0;
        }
    }

    // Detaching shared memory
    shmdt(str);
    printf("Shared memory is detached.\n");

    return 0;
}

