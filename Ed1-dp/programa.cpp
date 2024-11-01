#include<stdio.h>
#include<conio2.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include"funcoes.h"

void check_out(DescProc &DP){
	FILE *arq = fopen("","ab+");
	if(!feof(arq)){
		fscanf(arq,"%d,%d,%d,%d,%d,%d\n",&P->contD,&P->contGE,&P->contGI,&P->contI,&P->contL,&P->Nprocessador);
		while(P->Prox!=NULL){
			P=P->Prox;
			fscanf(arq,"%d,%d,%d,%d,%d,%d\n",&P->contD,&P->contGE,&P->contGI,&P->contI,&P->contL,&P->Nprocessador);
		}
	}
	fclose(arq);
	remove("processadores.txt");
}
