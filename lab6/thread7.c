#include<pthread.h>
#include<stdio.h>

void * function(void * ptr){
	printf("Hello world, this is child thread!\n"); 
        int *x = (int*) ptr;
	printf("I received an integer: %d\n", *x); 
        pthread_exit(NULL);
}

int main(){
	printf("Hello world, this is master thread!\n");
	pthread_t t_id;
	
	//a variable x stores the integer value
	int x = 10;
	
	// a pointer to the address of x will be passed 
	int * ptr = &x;
	
	int r = pthread_create(&t_id, NULL, function, (void *)ptr); 
        pthread_join(t_id, NULL);
	printf("Master thread is exiting\n");
}

