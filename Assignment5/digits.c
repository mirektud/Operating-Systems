/* ==================== digits.c ========================
 student ID number: 12345678
=========================================================*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
sem_t *semA, *semB, *semC, *semD, *semE, *semF, *semG, *semH;

int i, j, k, l, m, n, o, p, q, r;
int NUMBER_OF_1 = 1;  // number of 1s in your student ID 
int NUMBER_OF_2 = 1;  // number of 2s in your student ID
int NUMBER_OF_3 = 1;  // number of 3s in your student ID
int NUMBER_OF_4 = 1;  // number of 4s in your student ID
int NUMBER_OF_5 = 1;  // number of 5s in your student ID
int NUMBER_OF_6 = 1;  // number of 6s in your student ID
int NUMBER_OF_7 = 1;  // number of 7s in your student ID
int NUMBER_OF_8 = 1;  // number of 8s in your student ID
int NUMBER_OF_9 = 0;  // number of 9s in your student ID
int NUMBER_OF_0 = 0;  // number of 0s in your student ID

void * f1(void * parm){      //function f1 prints "1"
for (i=0; i<NUMBER_OF_1; i++){
  fprintf(stderr, "1");
}
}

void * f2(void * parm){      //function f2 prints "2"
for (j=0; j<NUMBER_OF_2; j++){
  fprintf(stderr, "2");
}
}
void * f3(void * parm){      //function f3 prints "3"
for (k=0; k<NUMBER_OF_3; k++){
  fprintf(stderr,"3");
}
}
void * f4(void * parm){      //function f4 prints "4"
for (l=0; l<NUMBER_OF_4; l++){
  fprintf(stderr, "4");
}
}
void * f5(void * parm){      //function f5 prints "5"
for (m=0; m<NUMBER_OF_5; m++){
 fprintf(stderr, "5");
}
}
void * f6(void * parm){      //function f6 prints "6"
for (n=0; n<NUMBER_OF_6; n++){
 fprintf(stderr, "6");
}
}
void * f7(void * parm){      //function f7 prints "7"
for (o=0; o<NUMBER_OF_7; o++){
 fprintf(stderr,"7");
}
}
void * f8(void * parm){      //function f8 prints "8"
for (p=0; p<NUMBER_OF_8; p++){
 fprintf(stderr, "8");
}
}
void * f9(void * parm){
for (q=0; q<NUMBER_OF_9; q++){//function f9 prints "9"
 fprintf(stderr,"9");
}
}
void * f0(void * parm){      //function f0 prints "0"
for (r=0; r<NUMBER_OF_0; r++){
 fprintf(stderr, "0");
}
}

int main() {
pthread_t t1, t2, t3, t4, t5, t6, t7, t8, t9, t0;
char *name1 = "/sem1";
semA = sem_open(name1, O_CREAT, 0666, 1);   // semA with initial value 1
char *name2 = "/sem2";
semB = sem_open(name2, O_CREAT, 0666, 0);   // semB with initial value 0 
char *name3 = "/sem3";
semC = sem_open(name3, O_CREAT, 0666, 0);   // semA with initial value 0
char *name4 = "/sem4";
semD = sem_open(name4, O_CREAT, 0666, 0);   // semD with initial value 0
char *name5 = "/sem5";
semE = sem_open(name5, O_CREAT, 0666, 0);   // semE with initial value 0
char *name6 = "/sem6";
semF = sem_open(name6, O_CREAT, 0666, 0);   // semF with initial value 0
char *name7 = "/sem7";
semG = sem_open(name7, O_CREAT, 0666, 0);   // semG with initial value 0
char *name8 = "/sem8";
semH = sem_open(name8, O_CREAT, 0666, 0);   // semH with initial value 0

pthread_create(&t1, NULL, f1, NULL); //thread1 with function f1
pthread_create(&t2, NULL, f2, NULL); //thread2 with function f2
pthread_create(&t3, NULL, f3, NULL); //(...)
pthread_create(&t4, NULL, f4, NULL); 
pthread_create(&t5, NULL, f5, NULL); 
pthread_create(&t6, NULL, f6, NULL);
pthread_create(&t7, NULL, f7, NULL);
pthread_create(&t8, NULL, f8, NULL);
pthread_create(&t9, NULL, f9, NULL);
pthread_create(&t0, NULL, f0, NULL);

pthread_join(t1, NULL);
pthread_join(t2, NULL);
pthread_join(t3, NULL);
pthread_join(t4, NULL);
pthread_join(t5, NULL);
pthread_join(t6, NULL);
pthread_join(t7, NULL);
pthread_join(t8, NULL);
pthread_join(t9, NULL);
pthread_join(t0, NULL);


sem_close(semA);
sem_close(semB);
sem_close(semC);
sem_close(semD);
sem_close(semE);
sem_close(semF);
sem_close(semG);
sem_close(semH);

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

