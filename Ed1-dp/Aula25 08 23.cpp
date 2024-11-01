#include<stdio.h>
#include<conio2.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

void GravarProd(char NomeArq[50]){
	char Descr[30];
	int Qtd,codigo;
	float Preco;
	FILE *arq = fopen(NomeArq,"a");
	clrscr();
	printf("Descricao do Produto");
	fflush(stdin);
	gets(Descr);
	while(strcmp(Descr,"\0")!=0){
		
		printf("Codigo: ");
		scanf("%d",&codigo);
		printf("Qtd em estoque: ");
		scanf("%d",Qtd);
		printf("Preco: R$ ");
		scanf("%f",&Preco);
		
		fprintf(arq,"%d\t%s\t%d\t%.2f\n",codigo,Descr,Qtd,Preco);
		
		printf("Descricao do Produto");
		fflush(stdin);
		gets(Descr);
	}
	
}

void RecuperarProd(char NomeArq[50]){
	
}

int main(){
	GravarProd((char*)"Produtos.txt");
	//RecuperProd("Produtos.txt");
	return 0;
}
