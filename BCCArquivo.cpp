#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

struct TpDic
{
	char Ingles[30], Port[30], Status;
	int Pontuacao;
};

void CadDic(void)
{
	TpDic Reg;
	FILE *PtrDic = fopen("Dicionario.dat","ab");
	clrscr();
	printf("\n## Cadastro de Palavras ##\n");
	printf("\nIngles: ");
	fflush(stdin);
	gets(Reg.Ingles);
	while (strcmp(Reg.Ingles,"\0")!=0)
	{
		printf("\nPortugues: ");
		fflush(stdin);
		gets(Reg.Port);
		Reg.Status = 'A';
		Reg.Pontuacao = (rand()%3+1)*10;
		printf("\nPontuacao: %d\n\n",Reg.Pontuacao);
		fwrite(&Reg,sizeof(TpDic),1,PtrDic);
		
		printf("\nIngles: ");
		fflush(stdin);
		gets(Reg.Ingles);	
	}
	fclose(PtrDic);
}

int BuscaIngles(FILE *PtrArq, char Palavra[30])
{
	TpDic R;
	rewind(PtrArq);   //fseek(PtrArq,0,SEEK_SET);
	fread(&R,sizeof(TpDic),1,PtrArq);
	while (!feof(PtrArq) && stricmp(Palavra,R.Ingles)!=0)
		fread(&R,sizeof(TpDic),1,PtrArq);
	
	if (!feof(PtrArq))
		return ftell(PtrArq)-sizeof(TpDic);
	else
		return -1;
}

void Consulta(void)
{
	TpDic R;
	int pos;
	FILE *PtrDic = fopen("Dicionario.dat","rb");
	clrscr();
	if (PtrDic==NULL)
	{
		printf("\nErro de Abertura!\n");
		getch();
	}
	else
		{
			printf("\n## Consulta Dicionario ##\n");
			printf("Ingles: ");
			fflush(stdin);
			gets(R.Ingles);
			while (strcmp(R.Ingles,"\0")!=0)
			{
				pos = BuscaIngles(PtrDic,R.Ingles);
				if (pos==-1)
					printf("\nPalavra nao encontrada!\n");
				else 
					{
						printf("\n** Detalhes **\n");
						fseek(PtrDic,pos,0);
						fread(&R,sizeof(TpDic),1,PtrDic);
						
						if (R.Status=='A')
						{
							printf("\nIngles: %s",R.Ingles);
							printf("\nPortugues: %s",R.Port);
							printf("\nPontuacao: %d\n",R.Pontuacao);
						}
						else printf("\nRegistro Inativo!\n");
						
						getch();
					}
				printf("\nIngles: ");
				fflush(stdin);
				gets(R.Ingles);
			}
			
			fclose(PtrDic);
		}
}

void RelPalavras(void)
{
	TpDic R;
	FILE *PtrDic = fopen("Dicionario.dat","rb");
	clrscr();
	if (PtrDic==NULL)
		printf("\nErro de Abertura!\n");
	else
		{
			printf("\n## Conteudo do Dicionario ##\n");
			fread(&R,sizeof(TpDic),1,PtrDic);
			while (!feof(PtrDic))
			{	
				if (R.Status=='A')
				{
					printf("\nIngles: %s",R.Ingles);
					printf("\nPortugues: %s",R.Port);
					printf("\nPontuacao: %d\n",R.Pontuacao);
				}
	
				fread(&R,sizeof(TpDic),1,PtrDic);
			}
			
			fclose(PtrDic);
		}
	
	getch();
}

int main(void)
{
	srand(time(NULL));
	CadDic();
	RelPalavras();
	Consulta();
	return 0;
}


/*
    ..:: Elaborar um Menu
    ..:: Implementar uma função que faça a Exclusão Lógica;
    ..:: Jogo... 
    		Sortear uma palavra em Inglês;
    		A Pessoa tenta acertar...
    				Se errar... -Pontuação
    				Se acertar... +Pontuação
    ..:: Criar um Ranking com o Nome e Pontuação
*/




