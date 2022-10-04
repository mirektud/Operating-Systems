#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
  
int main() { 
  
   // shmget returns an ID of the shared memory 
   int shm_id = shmget(3333, 1024, 0666|IPC_CREAT); 
   printf("Shared memory ID: %d\n",shm_id);
  
   // attaching shared memory segment to the address space
   char *str = shmat(shm_id, NULL, 0); 
   printf("Shared memory is attached to the address space\n");

   // reading data from the shared memory segment
   printf("Data read from shared memory: %s\n",str); 
      
   // detaching from shared memory  
   shmdt(str);
   printf("Shared memory is detached.\n"); 
    
return 0; 
} 

