#include <stdio.h>
#include <unistd.h>
#include <STDLIB.h>

int main(void){
	int c1,c2;
	
	c2=0;
	c1=fork();
	printf("\nFork 1 - I am process %ld and my C2 is %d, my C1  is %d\n",(long)getpid(),c2,c1);
	if(c1==0){
		c2=fork();
		printf("\nFork 2 - I am process %ld and my C2 is %d, my C1  is %d\n",(long)getpid(),c2,c1);

	}
	fork();
	printf("\nFork 3 - I am process %ld and my C2 is %d, my C1  is %d\n",(long)getpid(),c2,c1);
	if(c2>0){
		fork();
		printf("\nFork 4 - I am process %ld and my C2 is %d, my C1  is %d\n",(long)getpid(),c2,c1);

	}
	exit(0;
}

