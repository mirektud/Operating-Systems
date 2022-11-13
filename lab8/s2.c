#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>

sem_t *mutex;

long * balance;

void inc() { //inc() function
    long i;
    for (i = 0; i < 10000000; i++) {
        sem_wait(mutex);
        * balance = * balance + 1;
        sem_post(mutex);
    }
}
void dec() { //dec() function
    long j;
    for (j = 0; j < 10000000; j++) {
        sem_wait(mutex);
        * balance = * balance - 1;
        sem_post(mutex);
    }
}

int main() {
    int shm_id1 = shmget(111, 8, 0777 | IPC_CREAT);
    balance = (long * ) shmat(shm_id1, NULL, 0); //attaching memory
    * balance = 0; //initializing balance value

    char *name = "/name2";
    mutex = sem_open(name, O_CREAT, 0666, 1);
  
    int cpid = fork();
    if (cpid == 0) {
        inc(); // calling inc() function
        shmdt(balance); //detaching balance
        exit(0);
    } else { //parent process
        dec(); //calling dec() function
        wait(NULL);
        printf("Value of balance is: %ld\n", * balance);
        shmdt(balance); //detaching memory
    }
    sem_close(mutex);
    sem_unlink(name);
    return 0;
}
