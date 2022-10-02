#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){

if(argc!=2){
printf("Enter one argument in the command line!\n");
exit(0);
}

printf("The argument you entered is: %s\n", argv[1]);

return 0;
}

