#include<pthread.h>
#include<stdio.h>

int i, j;

void * f1(){
   for (i=0; i<10000; i++){
      printf("1");
      fflush(stdout);
    }
   pthread_exit(NULL);
}

void * f2(){
   for (j=0; j<10000; j++){
      printf("2");
      fflush(stdout);
    }
   pthread_exit(NULL);
}

int main(){
   pthread_t t_id1, t_id2;
   int r1 = pthread_create(&t_id1, NULL, f1, NULL);
   int r2 = pthread_create(&t_id2, NULL, f2, NULL);
   pthread_join(t_id1, NULL);
   pthread_join(t_id2, NULL);
return 0;
}
