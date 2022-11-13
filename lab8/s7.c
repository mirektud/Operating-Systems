// ==================== orderedNR.c ========================
// studentID = C12345678                // your student ID
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void * f1(void * parm){
   fprintf(stderr, "2");
}

void * f2(void * parm){
   fprintf(stderr, "8");
}

void * f3(void * parm){
   fprintf(stderr,"4");
}

void * f4(void * parm){
   fprintf(stderr, "7");
}

void * f5(void * parm){
   fprintf(stderr, "5");
}

void * f6(void * parm){
   fprintf(stderr,"3");
}

void * f7(void * parm){
   fprintf(stderr, "6");
}

void * f8(void * parm){
   fprintf(stderr, "1");
}


int main() {
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

