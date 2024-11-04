// ==================== orderedNR.c ========================
// studentID = C12345678                // your student ID
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>

sem_t  *semA, *semB, *semC, *semD, *semE, *semF, *semG, *semH;

void * f1(void * parm){
sem_wait(semB);
   fprintf(stderr, "2");
sem_post(semC);
}

void * f2(void * parm){
sem_wait(semH);
   fprintf(stderr, "8");
}

void * f3(void * parm){
sem_wait(semD);
   fprintf(stderr,"4");
sem_post(semE);
}

void * f4(void * parm){
sem_wait(semG);
   fprintf(stderr, "7");
sem_post(semH);
}

void * f5(void * parm){
sem_wait(semE);
   fprintf(stderr, "5");
sem_post(semF);
}

void * f6(void * parm){
sem_wait(semC);
   fprintf(stderr,"3");
sem_post(semD);
}

void * f7(void * parm){
sem_wait(semF);
   fprintf(stderr, "6");
sem_post(semG);
}

void * f8(void * parm){
sem_wait(semA);
   fprintf(stderr, "1");
sem_post(semB);
}


int main() {


char *name1 = "/sem1";
semA = sem_open(name1, O_CREAT, 0666, 1);

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
semG = sem_open(name7, O_CREAT, 0666, 0);

char *name8 = "/sem8";
semH = sem_open(name8, O_CREAT, 0666, 0);

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

sem_close(semA);
sem_close(semB);
sem_close(semC);
sem_close(semD);
sem_close(semE);
sem_close(semF);
sem_close(semG);

sem_unlink(name1);
sem_unlink(name2);
sem_unlink(name3);
sem_unlink(name4);
sem_unlink(name5);
sem_unlink(name6);
sem_unlink(name7);
sem_unlink(name8);


 printf("\n");
return 0;
}
// ==================== end of orderedNR.c ========================

