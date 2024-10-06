#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    int running = 1;
    char last_message[128] = "";  // To store the last message read

    // shmget returns an ID of the shared memory
    int shm_id = shmget(3333, 1024, 0666|IPC_CREAT);
    printf("Shared memory ID: %d\n", shm_id);

    // attaching shared memory segment to the address space
    char *str = shmat(shm_id, NULL, 0);
    printf("Shared memory is attached to the address space\n");

    while (running) {
        // Check if the message in shared memory is different from the last message
        if (strncmp(str, last_message, 128) != 0) {
            // Print the new message
            printf("New message received: %s\n", str);

            // Update the last message with the current one
            strncpy(last_message, str, 128);

            // Check if the new message is "end"
            if (strncmp(str, "end", 3) == 0) {
                running = 0;  // End the loop if "end" is found
            }
        }

        // Sleep for 1 second before checking again
        sleep(1);
    }

    // detaching from shared memory
    shmdt(str);
    printf("Shared memory is detached.\n");

    return 0;
}

