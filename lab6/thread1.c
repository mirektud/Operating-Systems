#include<pthread.h>
#include<stdio.h>

void * function(){
   printf("Hello world, this is child thread!\n");

   //terminate thread
   printf("Child thread is exiting\n");
   pthread_exit(NULL);
}

int main(){

   pthread_t t_id;
   printf("Hello world, this is master thread!\n");
        
   //create  thread 
   int r = pthread_create(&t_id, NULL, function, NULL);
   if (r == 0){
      printf("Child thread created, t_id = %lu\n", (unsigned long)t_id);
   }
   else{
      printf("Thread error nr: %d\n", r);
   }
        
  printf("Master thread is exiting\n");
  return 0;
}

