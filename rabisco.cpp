#include<stdio.h>
#include<conio2.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

int main(void){
	float nf;
	int aux,aux2;
	scanf("%f",&nf);
	aux=nf*100000;
	aux-=aux%10;
	nf=aux*0.00001;
	printf("%.4f",nf);
	return 0;
}
