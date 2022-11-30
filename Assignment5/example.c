/* ==================== example.c ========================
 student ID number: 12131413
=========================================================*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
sem_t *semA, *semB, *semC, *semD, *semE, *semF;

int i, j, k, l, m, n, o, p, q, r;
int NUMBER_OF_1 = 4;
int NUMBER_OF_2 = 1;
int NUMBER_OF_3 = 2;
int NUMBER_OF_4 = 1;
int NUMBER_OF_5 = 0;
int NUMBER_OF_6 = 0;
int NUMBER_OF_7 = 0;
int NUMBER_OF_8 = 0;
int NUMBER_OF_9 = 0;
int NUMBER_OF_0 = 0;

void * f1(void * parm){
for (i=0; i<NUMBER_OF_1; i++){
 sem_wait(semA);
  fprintf(stderr, "1");
// usleep(100);
 sem_post(semB);
 sem_post(semC);
 sem_post(semD);
}
}

void * f2(void * parm){
for (j=0; j<NUMBER_OF_2; j++){
 sem_wait(semB);
  fprintf(stderr, "2");
 sem_post(semA);
 sem_wait(semC);
 sem_wait(semD);
 sem_post(semE);
 sem_wait(semF);
}
}

void * f3(void * parm){
for (k=0; k<NUMBER_OF_3; k++){
 sem_wait(semC);
 sem_wait(semE);
  fprintf(stderr,"3");
 sem_post(semA);
 sem_wait(semB);
 sem_wait(semD);
 sem_post(semF);
}
}
void * f4(void * parm){
for (l=0; l<NUMBER_OF_4; l++){
 sem_wait(semD);
 sem_wait(semF);
  fprintf(stderr, "4");
 sem_post(semA);
 sem_wait(semB);
 sem_post(semC);
 sem_post(semE);
 sem_wait(semF);
}
}
void * f5(void * parm){
for (m=0; m<NUMBER_OF_5; m++){
 fprintf(stderr, "5");
}
}
void * f6(void * parm){
for (n=0; n<NUMBER_OF_6; n++){
 fprintf(stderr, "6");
}
}
void * f7(void * parm){
for (o=0; o<NUMBER_OF_7; o++){
 fprintf(stderr,"7");
}
}
void * f8(void * parm){
for (p=0; p<NUMBER_OF_8; p++){
 fprintf(stderr, "8");
}
}

void * f9(void * parm){
for (q=0; q<NUMBER_OF_9; q++){
 fprintf(stderr,"9");
}
}
void * f0(void * parm){
for (r=0; r<NUMBER_OF_0; r++){
 fprintf(stderr, "0");
}
}



int main() {
pthread_t t1, t2, t3, t4, t5, t6, t7, t8;
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

pthread_create(&t1, NULL, f1, NULL); //function f1 prints "1"
pthread_create(&t2, NULL, f2, NULL); //function f1 prints "2"
pthread_create(&t3, NULL, f3, NULL); //function f1 prints "3"
pthread_create(&t4, NULL, f4, NULL); //function f1 prints "4"

pthread_join(t1, NULL);
pthread_join(t2, NULL);
pthread_join(t3, NULL);
pthread_join(t4, NULL);

sem_close(semA);
sem_close(semB);
sem_close(semC);
sem_close(semD);
sem_close(semE);
sem_close(semF);

sem_unlink(name1);
sem_unlink(name2);
sem_unlink(name3);
sem_unlink(name4);
sem_unlink(name5);
sem_unlink(name6);

printf("\n");
return 0;
}

