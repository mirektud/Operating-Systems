#include<pthread.h>
#include<stdio.h>

void * function(void * ptr){
	printf("Hello world, this is child thread!\n");
	printf("I got a message: %s\n", ptr);
	pthread_exit(NULL);
}

int main(){
	printf("Hello world, this is master thread!\n"); 

	pthread_t t_id;
	
	//create a message "hello mr thread" 
	char message[25] = {"hello mr thread"};

	//create a thread and pass the message to the thread function
	int r = pthread_create(&t_id, NULL, function, message);

	//wait for the thread function to exit
	pthread_join(t_id, NULL);

	printf("Master thread is exiting\n"); 
return 0;
}
