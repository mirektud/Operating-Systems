#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int i,j;
void f1(){
 for (i=0; i<10; i++){
 printf("1");
 fflush(stdout);
 sleep(1);
 }
}
void f2(){
 for (j=0; j<10; j++){
 printf("2");
 fflush(stdout);
 sleep(1);
 }
}
int main(){
 f1();
 f2();
return 0;
}


