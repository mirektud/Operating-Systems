#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

long *balance;  // global variable

void inc(){ //inc() function
 long i;
 for(i=0;i<10000000;i++){
 *balance = *balance + 1;
 }
}

void dec(){ //dec() function
 long j;
 for(j=0;j<10000000;j++){
 *balance = *balance - 1;
 }
}

int main(){

int shm_id =shmget(111, 8, 0777|IPC_CREAT);

balance = shmat(shm_id, NULL, 0); //attaching balance var.

*balance=0; //initializing balance value

int pid = fork();

if (pid == 0){ //child process
 inc(); // calling inc() function
 shmdt(balance); //detaching balance
 exit(0);
}
else{ //parent process
 dec(); //calling dec() function
 printf("Value of balance is: %ld\n", *balance);
 shmdt(balance); //detaching balance
return 0;
}
}

