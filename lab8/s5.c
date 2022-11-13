#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void * f1(void * parm) {
    fprintf(stderr, " Operating Systems ");
}

void * f2(void * parm) {
    fprintf(stderr, " is fun. ");
}

void * f3(void * parm) {
    fprintf(stderr, " Learning ");
}

int main() {

    pthread_t t1, t2, t3;

    pthread_create( & t1, NULL, f1, NULL);
    pthread_create( & t2, NULL, f2, NULL);
    pthread_create( & t3, NULL, f3, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    printf("\n");
    return 0;
}
