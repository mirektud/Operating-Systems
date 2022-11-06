#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


long i, j;
long balance = 0; //global variable
pthread_mutex_t mut;

void * inc(void * arg) {
    for (i = 0; i < 10000000; i++){
	pthread_mutex_lock(&mut);
        balance++;
	pthread_mutex_unlock(&mut);
    }
    pthread_exit(NULL);
};

void * dec(void * arg) {
    for (j = 0; j < 10000000; j++){
	pthread_mutex_lock(&mut);
        balance--;
	pthread_mutex_unlock(&mut);
    }
    pthread_exit(NULL);
};

int main() {
    pthread_t t1, t2;
    pthread_mutex_init(&mut,NULL);

    pthread_create( & t1, NULL, inc, NULL);
    pthread_create( & t2, NULL, dec, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Value of balance is: %ld\n", balance);
return 0;
}
