#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>

struct cliente
{
	char nome[15],status;
	float preco;
};

void cadastro(void)
{
	cliente cli;
	FILE *ptr = fopen("cliente.dat","ab");
	
	cli.status='A';
	
	printf("DIGITE O NOME: ");
	fflush(stdin);
	gets(cli.nome);
	
	printf("DIGITE O PRECO: ");
	scanf("%f",&cli.preco);
	
	fwrite(&cli,sizeof(cliente),1,ptr);
	fclose(ptr);
}

void Busca(void)
{
	cliente cli;
	FILE *ptr = fopen("cliente.dat","rb");
	char aux[15];	
	
	printf("QUAL O NOME QUE VOCE DESEJA ENCONTRAR: ");
	fflush(stdin);
	gets(aux);
	
	rewind(ptr);
	fread(&cli,sizeof(cliente),1,ptr);
	while(!feof(ptr) && strcmp(aux,cli.nome)!=0)
	{
		fread(&cli,sizeof(cliente),1,ptr);
	}
	if(!feof(ptr))
	{
		printf("Encontrou!");
	}
	else
	{
		printf("Nao Encontrou!");
	}
}

void ordenar(void)
{
	cliente cli1,cli2;
	FILE *ptr = fopen("cliente.dat","rb+");
	int qnt;
	int qnt;
	
	fseek(ptr,0,2);

}

int main()
{
	char op;
	op=getch();
	do
	{
		switch(op)
		{
			case '1':
				cadastro();
				break;
			case '2':
				Busca();
				Sleep(1000);
				break;
		}
		clrscr();
		op=getch();
	}while(op!=27);
	
	return 0;
}
