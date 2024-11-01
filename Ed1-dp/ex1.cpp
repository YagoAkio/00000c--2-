#include<stdio.h>
#include<conio2.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

//13 10 quebra de linha
FILE *minu(FILE *ptr){
	FILE *aux = fopen("auxiliar.txt","w");
	char c;
	rewind(ptr);
	c = fgetc(ptr);
	while(c != NULL){
		fputc(tolower(c),aux);
		c = fgetc(ptr);
	}	
	return aux;
}

void qtd(FILE *ptr){
	char c;
-	while(c != '.'){
		
		c = fgetc(ptr);
	}
}

int main(){
	FILE *ptr= fopen("dc.txt","r");
	minu(ptr);
	
	return 0;
}
