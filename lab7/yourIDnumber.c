// ==================== yourIDnumber.c ========================
// studentID number = 12345678                // default student ID

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

long ones               = 8; //number of ones in your tudent ID number
long tens               = 7; //number of tens in your student ID number
long hundreds           = 6;
long thousands          = 5;
long tensOfThousands    = 4;
long hundredsOfThousands= 3;
long millions           = 2;
long tensOfMillions     = 1;
long studentNR          = 0; //global variable representing your student ID number

void * onesThread(void * arg){
   long i;
   for(i=0;i<ones;i++){
      studentNR++;
   }
   pthread_exit(NULL);
};

void * tensThread(void * arg){
   long i;
   for(i=0;i<tens*10;i++){
      studentNR++;
   }
   pthread_exit(NULL);
};


void * hundredsThread(void * arg){
   long i;
   for(i=0;i<hundreds*100;i++){
      studentNR++;
   }
   pthread_exit(NULL);
};


void * thousandsThread(void * arg){
   long i;
   for(i=0;i<thousands*1000;i++){
      studentNR++;
   }
   pthread_exit(NULL);
};
void * tensOfThousandsThread(void * arg){
   long i;
   for(i=0;i<tensOfThousands*10000;i++){
      studentNR++;

}
   pthread_exit(NULL);
};

void * hundredsOfThousandsThread(void * arg){
   long i;
   for(i=0;i<hundredsOfThousands*100000;i++){
      studentNR++;
   }
   pthread_exit(NULL);
};

void * millionsThread(void * arg){
   long i;
   for(i=0;i<millions*1000000;i++){
      studentNR++;
   }
   pthread_exit(NULL);
};


void * tensOfMillionsThread(void * arg){
   long i;
   for(i=0;i<tensOfMillions*10000000;i++){
      studentNR++;
   }
   pthread_exit(NULL);
};


int main(){
   pthread_t t1, t2, t3, t4, t5, t6, t7, t8;

   pthread_create(&t1, NULL, onesThread,                NULL);
   pthread_create(&t2, NULL, tensThread,                NULL);
   pthread_create(&t3, NULL, hundredsThread,            NULL);
   pthread_create(&t4, NULL, thousandsThread,           NULL);
   pthread_create(&t5, NULL, tensOfThousandsThread,     NULL);
   pthread_create(&t6, NULL, hundredsOfThousandsThread, NULL);
   pthread_create(&t7, NULL, millionsThread,            NULL);
   pthread_create(&t8, NULL, tensOfMillionsThread,      NULL);

   pthread_join(t1,NULL);
   pthread_join(t2,NULL);
   pthread_join(t3,NULL);
   pthread_join(t4,NULL);
   pthread_join(t5,NULL);
   pthread_join(t6,NULL);
   pthread_join(t7,NULL);
   pthread_join(t8,NULL);

   printf("My student ID number is :%ld\n", studentNR);
return 0;
}


