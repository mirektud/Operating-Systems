#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main()
{

   // shmget returns an ID of the shared memory
   int shm_id = shmget(3333, 1024, 0666|IPC_CREAT);
   printf("Shared memory ID: %d\n",shm_id);

   // attaching shared memory to the address space
   char *str = shmat(shm_id, NULL, 0);
   printf("Shared memory is attached to the address space.\n");

   // copying "Hello World!" to the shared memory segment
   sprintf(str,"Hello World!");
   printf("Data '%s' is written in shared memory.\n",str);

   //detaching shared memory
   shmdt(str);
   printf("Shared memory is detached.\n");

return 0;
}

