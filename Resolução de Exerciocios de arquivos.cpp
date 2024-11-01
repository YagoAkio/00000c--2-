#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

struct alunos
{
	char ra[11], Nome[20];	
};

struct disciplinas
{
	int cod;
	char disc[25];
};

struct aldi
{
	char ra[11];
	int cod;
	float nota;
};

void insercao(FILE *ptr)
{
	alunos a,a2;
	int pos;
	
	fseek(ptr,0,2);
	pos = ftell(ptr) / sizeof(alunos)-1;
	
	fseek(ptr,pos*sizeof(alunos),0);
	fread(&a,sizeof(alunos),1,ptr);
	
	fseek(ptr,(pos-1)*sizeof(alunos),0);
	fread(&a2,sizeof(alunos),1,ptr);
	
	while(pos>0 && stricmp(a.Nome,a2.Nome)<0)
	{
		fseek(ptr ,pos*sizeof(alunos), 0);
		fwrite(&a2,sizeof(alunos),1,ptr);
		
		fseek(ptr,(pos-1)*sizeof(alunos),0);
		fwrite(&a,sizeof(alunos),1,ptr);
		
		pos--;
		
		if(pos>0)
		{
			fseek(ptr,pos*sizeof(alunos),0);
			fread(&a,sizeof(alunos),1,ptr);
			
			fseek(ptr,(pos-1)*sizeof(alunos),0);
			fread(&a2,sizeof(alunos),1,ptr);
		}	
	}
	fclose(ptr);
	printf("ORDENADO!\n");
}



int buscara(FILE *ptr,char ra[11])
{
	fseek(ptr,0,0);
	alunos a;
	fread(&a,sizeof(alunos),1,ptr);
	while(!feof(ptr) && strcmp(a.ra,ra)!=0)
	{
		fread(&a,sizeof(alunos),1,ptr);	
	}
	if(!feof(ptr))
	{
		return ftell(ptr)-sizeof(alunos);
	}
	else
	{
		return -1;
	}
}

void CadastroA(void)
{
	alunos a;
	FILE *ptr = fopen("Alunos.dat","ab+");
	
	printf("QUAL O RA: ");
	fflush(stdin);
	gets(a.ra);
	while(buscara(ptr,a.ra)!=-1)
	{
		printf("QUAL O RA: ");
		fflush(stdin);
		gets(a.ra);
	}
	printf("QUAL O NOME: ");
	fflush(stdin);
	gets(a.Nome);
	fwrite(&a,sizeof(alunos),1,ptr);
	fclose(ptr);
	
	ptr = fopen("Alunos.dat","rb+");
	insercao(ptr);
	fclose(ptr);
}

void exibir(void)
{
	alunos a;
	FILE *ptr = fopen("Alunos.dat","rb");
	
	fseek(ptr,0,0);
	fread(&a,sizeof(alunos),1,ptr);
	while(!feof(ptr))
	{
		printf("%s - %s\n",a.ra,a.Nome);
		fread(&a,sizeof(alunos),1,ptr);
	}
	fclose(ptr);
}

void ordenar(void)
{
	alunos al1,al2;
	int qnt,a,b;
	FILE *ptr = fopen("Alunos.dat","rb+");
	
	fseek(ptr,0,2);
	qnt = ftell(ptr) / sizeof(alunos);
	for(a=0;a<qnt-1;a++)
		for(b=a+1;b<qnt;b++)
		{
			fseek(ptr,a*sizeof(alunos),0);
			fread(&al1,sizeof(alunos),1,ptr);
			
			fseek(ptr,b*sizeof(alunos),0);
			fread(&al2,sizeof(alunos),1,ptr);
			
			if(stricmp(al1.Nome,al2.Nome)>0)
			{
				fseek(ptr,a*sizeof(alunos),0);
				fwrite(&al2,sizeof(alunos),1,ptr);
				
				fseek(ptr,b*sizeof(alunos),0);
				fwrite(&al1,sizeof(alunos),1,ptr);
			}
		}
	fclose(ptr);
}

int buscaND (FILE *ptr,char aux[25])
{	
	disciplinas a;
	fseek(ptr,0,2);
	int inicio=0, fim = ftell(ptr)/sizeof(disciplinas)-1, meio;
	meio = fim/2;
	fseek(ptr,meio*sizeof(disciplinas),0);
	
	fread(&a,sizeof(disciplinas),1,ptr);
	while (inicio<fim && strcmp(a.disc,aux)!=0)
	{	 
		if (strcmp(a.disc,aux)<0)
		{
			inicio = meio + 1;
		}
		else
		{
			fim = meio;
		}
		meio = (inicio+fim)/2;
		fseek(ptr,meio*sizeof(disciplinas),0);
		fread(&a,sizeof(disciplinas),1,ptr);
	}	 
	if (strcmp(a.disc,aux)==0)
	{
		return meio*sizeof(disciplinas);
	}
	else
		return -1;
}

void CadastroB(void)
{
	disciplinas a;
	FILE *ptr = fopen("DISC.dat","ab+");
	
	printf("QUAL A MATERIA: ");
	fflush(stdin);
	gets(a.disc);
	while(buscaND(ptr,a.disc)!=-1)
	{
		printf("QUAL A MATERIA: ");
		fflush(stdin);
		gets(a.disc);
	}
	printf("QUAL O CODIGO: ");
	scanf("%d",&a.cod);
	fwrite(&a,sizeof(disciplinas),1,ptr);
	fclose(ptr);
}



int main (void)
{
	int op,op2;
	op = getch();
	while(op!=27)
	{
		CadastroA();
		op = getch();
	}
	//ordenar();
	exibir();
	getch();
	do 
	{
		CadastroB();
		op2 = getch();
	}while(op2!=27);
}
