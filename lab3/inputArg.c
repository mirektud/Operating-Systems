#include<stdio.h>
int main(int argc, char** argv){

int i;
printf("The number of input arguments are: %d\n",argc);
printf("The arguments are:\n");

for ( i = 0; i < argc; i++)
{
printf("%s\n", argv[i]);
}
return 0;
}

