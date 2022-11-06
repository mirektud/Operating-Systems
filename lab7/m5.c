#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
pthread_mutex_t mut;
int charcount = 0;

void * f1(void * args) {
    char * filename = (char * ) args;
    char ch;
    int fd = open(filename, O_RDONLY);
    while ((read(fd, & ch, 1)) != 0) {
      pthread_mutex_lock(&mut);  
        charcount++;
      pthread_mutex_unlock(&mut);
    }
    close(fd);
    pthread_exit(NULL);
}

int main(int argc, char * argv[]) {
    if (argc != 3) {
        printf("Input two text filenames.\n");
        exit(1);
    }
    pthread_mutex_init(&mut,NULL);
    pthread_t tid1, tid2;
  
    pthread_create( & tid1, NULL, f1, (void*) argv[1]);
    pthread_create( & tid2, NULL, f1, (void*) argv[2]);
  
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
  
    printf("Number of characters in both files: %d\n", charcount);
    return 0;
}
