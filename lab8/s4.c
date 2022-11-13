#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>

sem_t *mutex;

long balance = 0; //global variable

void * inc(void * arg) {
    long i;
    for (i = 0; i < 10000000; i++) {
        sem_wait(mutex);
        balance++;
        sem_post(mutex);
    }
    pthread_exit(NULL);
}
void * dec(void * arg) {
    long j;
    for (j = 0; j < 10000000; j++) {
        sem_wait(mutex);
        balance--;
        sem_post(mutex);
    }
    pthread_exit(NULL);
}
int main() {

char *name = "/sem1";
mutex = sem_open(name, O_CREAT, 0666, 1);

    pthread_t t1, t2;
    pthread_create( & t1, NULL, inc, NULL);
    pthread_create( & t2, NULL, dec, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Value of balance is :%ld\n", balance);

    sem_close(mutex);
    sem_unlink(name);
    return 0;
}
