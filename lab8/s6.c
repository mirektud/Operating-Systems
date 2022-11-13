#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>

sem_t *semA, *semB;

void * f1(void * parm) {
    sem_wait(semA);
    fprintf(stderr, " Operating Systems ");
    sem_post(semB);
}

void * f2(void * parm) {
    sem_wait(semB);
    fprintf(stderr, " is fun. ");
    sem_post(semA);
}

void * f3(void * parm) {
    fprintf(stderr, " Learning ");
    sem_post(semA);
}

int main() {

    char *name1 = "/sem1";
    semA = sem_open(name1, O_CREAT, 0666, 0);
    char *name2 = "/sem2";
    semB = sem_open(name2, O_CREAT, 0666, 0);

    pthread_t t1, t2, t3;

    pthread_create( & t1, NULL, f1, NULL);
    pthread_create( & t2, NULL, f2, NULL);
    pthread_create( & t3, NULL, f3, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    printf("\n");

    sem_close(semA);
    sem_close(semB);
    sem_unlink(name1);
    sem_unlink(name2);
    return 0;
}
