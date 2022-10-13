#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

#define NUM_THREADS 5

void *perform_work(void *arguments){
  int index = *((int *)arguments);
  int sleep_time = index;
  printf("THREAD %d: Started.\n", index);
  printf("THREAD %d: Will be sleeping for %d seconds.\n", index, sleep_time);
  sleep(sleep_time);
  printf("THREAD %d: Ended.\n", index);
  pthread_exit(NULL);
}

int main(void) {
  pthread_t threads[NUM_THREADS];
  int thread_args[NUM_THREADS];
  int i,j;

//create all threads one by one
  for (i = 0; i < NUM_THREADS; i++) {
    printf("IN MAIN: Creating thread %d.\n", i);
    thread_args[i] = i;
    int r = pthread_create(&threads[i], NULL, perform_work, &thread_args[i]);
    if (r == 0){
      printf("Thread %d created succeffully\n", i);
     }
     else{
      printf("Thread %d error nr: %d\n", i, r);
     }
  }
  printf("IN MAIN: All threads are created.\n");

  //wait for each thread to complete
  for (j = 0; j < NUM_THREADS; j++) {
    pthread_join(threads[j], NULL);
    printf("IN MAIN: Thread %d has ended.\n", j);
  }

  printf("MAIN program has ended.\n");
  return 0;
}

