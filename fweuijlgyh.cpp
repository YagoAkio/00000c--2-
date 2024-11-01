#include<stdio.h>
#include<conio2.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>
#include<time.h>

#include "TADFILAP.h"

#define MAXFILA 

struct pessoa{
	int prioridade,id;
};

struct CAIXA1{
	int fim,t=5,qnt;
	char op;
	pessoa fila[/* a se colocar*/]	
};

struct CAIXA2{
	int fim,t=2,qnt;
	char op;
	pessoa fila[/* a se colocar*/]	
};

struct CAIXA3{
	int fim,t=4,qnt;
	char op;
	pessoa fila[/* a se colocar*/]	
};

struct CAIXA4{
	int fim,t=7,qnt;
	char op;
	pessoa fila[/* a se colocar*/]	
};

void tempo(void){
	Sleep(1000);
}

void Busca(FILE *ptr,char elem){
	struct aux;
	rewind(ptr);
	fscanf(ptr,"\n",&aux);
	while(!feof(ptr) || strcmp(aux,elem)!=0){
		fscanf(ptr,"\n",&aux);
	}
	if(feof(ptr)){
		printf("não encontrado!!!");
	}
	else{
		printf("encontrado");
		printf("%%%%%%",aux,aux,aux,aux);
	}
}

void disponibilidade_de_caixas(CAIXA1 c1,CAIXA2 c2,CAIXA3 c3,CAIXA4 c4){
	if(rand()%2==0){
		c1.op='D';
		c1.fim=MAXFILA+1;
	}
	if(rand()%2==0){
		c2.op='D';
		c1.fim=MAXFILA+1;
	}
	if(rand()%2==0){
		c3.op='D';
		c1.fim=MAXFILA+1;
	}
	if(rand()%2==0){
		c4.op='D';
		c1.fim=MAXFILA+1;
	}
}

int main(void){
	int i=0;
	pessoa p;
	CAIXA1 c1;
	CAIXA2 c2;
	CAIXA3 c3;
	CAIXA4 c4;
	Inicializar(CAIXA1);
	Inicializar(CAIXA2);
	Inicializar(CAIXA3);
	Inicializar(CAIXA4);
	
	nrand(time(NULL));
	disponibilidade_de_caixas(c1,c2,c3,c4);
	while(c1.op=='D'&&c2.op=='D'&&c3.op=='D'&&c4.op=='D'){
		disponibilidade_de_caixas(c1,c2,c3,c4);
	}
	do{
		tempo();
		if(i%3==0){
			p.proridade=(rand()/3);//123
			p.id=(i/3);//1
		}
		if(c1.op!='D' || !FPCheia(c1) && c1.fim<c2.fim && c1.fim<c3.fim && c1.fim<c4.fim){
			Inserir(c1,p);
			c1.qnt++;
		}else if(c2.op!='D' || !FPCheia(c2) && c2.fim<c3.fim && c2.fim<c4.fim){
			Inserir(c2,p);
			c2.qnt++;
		}else if(c3.op!='D' || !FPCheia(c3) && c3.fim<c4.fim){
			Inserir(c3,p);
			c3.qnt++;
		}else if(c4.op!='D' || !FPCheia(c4)){
			Inserir(c4,p);
			c4.qnt++;
		}
		if(i%c1.t==0){
			retirar(c1);
		}
		if(i%c2.t==0){
			retirar(c2);
		}
		if(i%c3.t==0){
			retirar(c3);
		}
		if(i%c4.t==0){
			retirar(c4);
		}
		i++;
	}while(i!=1000000);
	printf("%d",((c1.qnt*c1.t)+(c2.qnt*c2.t)+(c3.qnt*c3.t)+(c4.qnt*c4.t))/p.id);
}
