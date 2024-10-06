#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    int running = 1;

    // shmget returns an ID of the shared memory
    int shm_id = shmget(3333, 1024, 0666|IPC_CREAT);
    printf("Shared memory ID: %d\n", shm_id);

    // attaching shared memory segment to the address space
    char *str = shmat(shm_id, NULL, 0);
    printf("Shared memory is attached to the address space\n");

    while (running) {
        // Read data from the shared memory
        printf("Data read from shared memory: %s\n", str);

        // Check if the data read is "end"
        if (strncmp(str, "end", 3) == 0) {
            running = 0; // End the loop if "end" is found
        }

        // Sleep for 1 second before reading again
        sleep(1);
    }

    // detaching from shared memory  
    shmdt(str);
    printf("Shared memory is detached.\n");

    return 0;
}

