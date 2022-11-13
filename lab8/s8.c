// ==================== orderedNR.c ========================
// studentID = C12345678                // your student ID
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>

sem_t *semA, *semB, *semC, *semD, *semE, *semF, *semG;


void * f1(void * parm){
while(1){
sem_wait(semA);
   fprintf(stderr, "2");
}
}

void * f2(void * parm){
while(1){
sem_wait(semB);
   fprintf(stderr, "8");
}
}

void * f3(void * parm){
while(1){
sem_wait(semC);
   fprintf(stderr,"4");
}
}

void * f4(void * parm){
while(1){
sem_wait(semD);
   fprintf(stderr, "7");
}
}

void * f5(void * parm){
while(1){
sem_wait(semD);
   fprintf(stderr, "5");
}
}

void * f6(void * parm){
while(1){
sem_wait(semE);
   fprintf(stderr,"3");
}
}

void * f7(void * parm){
while(1){
sem_wait(semF);
   fprintf(stderr, "6");
}
}

void * f8(void * parm){
while(1){
sem_wait(semG);
   fprintf(stderr, "1");
}
}


int main() {

 char *name1 = "/sem1";
    semA = sem_open(name1, O_CREAT, 0666, 0);

 char *name2 = "/sem2";
    semB = sem_open(name2, O_CREAT, 0666, 0);

 char *name3 = "/sem3";
    semC = sem_open(name3, O_CREAT, 0666, 0);

 char *name4 = "/sem4";
    semD = sem_open(name4, O_CREAT, 0666, 0);

 char *name5 = "/sem5";
    semE = sem_open(name5, O_CREAT, 0666, 0);

 char *name6 = "/sem6";
    semF = sem_open(name6, O_CREAT, 0666, 0);

 char *name7 = "/sem7";
    semG = sem_open(name7, O_CREAT, 0666, 1);

 pthread_t t1, t2, t3, t4, t5, t6, t7, t8;


 pthread_create(&t1, NULL, f1, NULL);
 pthread_create(&t2, NULL, f2, NULL);
 pthread_create(&t3, NULL, f3, NULL);
 pthread_create(&t4, NULL, f4, NULL);
 pthread_create(&t5, NULL, f5, NULL);
 pthread_create(&t6, NULL, f6, NULL);
 pthread_create(&t7, NULL, f7, NULL);
 pthread_create(&t8, NULL, f8, NULL);

 pthread_join(t1, NULL);
 pthread_join(t2, NULL);
 pthread_join(t3, NULL);
 pthread_join(t4, NULL);
 pthread_join(t5, NULL);
 pthread_join(t6, NULL);
 pthread_join(t7, NULL);
 pthread_join(t8, NULL);

 printf("\n");
return 0;
}
// ==================== end of orderedNR.c ========================

