#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


long i, j;
long balance = 0; //global variable


void * inc(void * arg) {
    for (i = 0; i < 10000000; i++){

        balance++;

    }
    pthread_exit(NULL);
};

void * dec(void * arg) {
    for (j = 0; j < 10000000; j++){

        balance--;

    }
    pthread_exit(NULL);
};

int main() {
    pthread_t t1, t2;

    pthread_create( & t1, NULL, inc, NULL);
    pthread_create( & t2, NULL, dec, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Value of balance is: %ld\n", balance);
return 0;
}
