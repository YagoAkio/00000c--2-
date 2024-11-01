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

void ExcLogica(void)
{
	TpDic R;
	int pos;
	FILE *PtrDic = fopen("Dicionario.dat","rb+");
	clrscr();
	if (PtrDic==NULL)
	{
		printf("\nErro de Abertura!\n");
		getch();
	}
	else
	{
		printf("\n## Exclusao Logica Dicionario ##\n");
		printf("Ingles: ");
		fflush(stdin);
		gets(R.Ingles); // palavra que desa excluir
		while (strcmp(R.Ingles,"\0")!=0)
		{
			pos = BuscaIngles(PtrDic,R.Ingles);
			if (pos==-1)
				printf("\nPalavra nao encontrada!\n");
			else 
			{
				printf("\n** Detalhes **\n");
				fseek(PtrDic,pos,0);//função que retorna a posição da palavra
				fread(&R,sizeof(TpDic),1,PtrDic);
				
				if (R.Status=='A')//ele so exclui a struct caso o status seja A, pois caso seja diferente posssivelmente ela ja foi excluida.
				{
					printf("\nIngles: %s",R.Ingles);
					printf("\nPortugues: %s",R.Port);
					printf("\nPontuacao: %d\n",R.Pontuacao);
					printf("\nConfirma Exclusao (S/N)? ");
					if (toupper(getche())=='S')
					{
						R.Status = 'I';//ocorre a subtituição do status, onde agora recebe i, e vai ser contado como excluido.
						fseek(PtrDic,pos,0);//na mesma posição.
						fwrite(&R,sizeof(TpDic),1,PtrDic);//e aqui vc atualiza.
						printf("\nRegistro Inativo!\n");
					}
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

void ExcFisica(void)
{
	TpDic R;
	FILE *PtrDic = fopen("Dicionario.dat","rb");
	clrscr();
	if (PtrDic==NULL)
		printf("\nErro de Abertura!\n");
	else
		{
			FILE *PtrTemp = fopen("Temp.dat","wb");// ele cira um arquivo arquivo auxiliar.
			fread(&R,sizeof(TpDic),1,PtrDic);//o ponteiro lê a struct do arquivo principal
			while(!feof(PtrDic))
			{
				if (R.Status=='A')
					fwrite(&R,sizeof(TpDic),1,PtrTemp);//aqui ele está copiando os arquivos do Dicionario.dat, que tem o status "Ativos", e aqueles que ele fez a exclusao logica não sao copiados.
				
				fread(&R,sizeof(TpDic),1,PtrDic);
			}
			fclose(PtrDic);
			fclose(PtrTemp);
			remove("Dicionario.dat");//deleta o arquivo principal.
			rename("Temp.dat","Dicionario.dat");// transforma o aquivo auxiliar em aquivo principal.
			printf("\nExclusao Fisica finalizada!\n");
		}
		getch();
}

void OrdenarArquivo(void)
{
	TpDic RegA, RegB;
	int a, b, QtdeReg;
	FILE *PtrDic = fopen("Dicionario.dat","rb+");
	if (PtrDic==NULL)
		printf("\nErro de Abertura!\n");
	else
	{	
		fseek(PtrDic,0,2); //fseek(PtrDic,0,SEEK_END);
		QtdeReg = ftell(PtrDic) / sizeof(TpDic);
		 /*
				vc encontra o tamanho do arquivo. Onde ftell passa a cordenada de onde está o arquivo e sizeof mostra a quantidade de variaveis de uma struct, a divião de ftell por
				sixeof dara a quantidade de structs dentro do arquivo. OBS: o fseek anterior joga o ponteiro para o fim do arquivo, assim vc mostrando qual a cordenada do ultimo lugar
				assim quando voce divide pela quantidade de variaveis da o valor de structs comportada pelo arquivo; 
		*/
		for(a=0; a<QtdeReg-1; a++)
		/*		
				esse for ele irá percorrer as structs de forma em que pule 0,1,2,3,4,5,..., etc. structs, até ele para na quantidade de structs registradas no arquivo.
				---------------------------------------------------------------------------------------
				o motivo por QtdeReg ser subtraido -1 é, quando o ponteiro chega no final, ele tem mais uma struct para comparar, ou seja, se não houvesse esse -1, quando o ponteiro 
				chegasse no fim ele não conseguiria encontrar nada na frente para comparar.
				
		*/				
			for(b=a+1; b<QtdeReg; b++) 
			{
				/*
						esse for faz o mesmo que o de cima, porém com acressimo de ele ser o for que movimenta a comparação, por isso ele recebe a+1, para nao se fazer a comparação com
						ele mesmo.
				*/
				fseek(PtrDic,a*sizeof(TpDic),0);
				fread(&RegA,sizeof(TpDic),1,PtrDic);
				/*
						a função de fseek com fread é sempre a atualizar a struct selecionada, pois quando remanejado ele não atualiza igual em vetores, matrizes e inteiros, ou seja,
						após um remanejamento dentro do arquivo será necessario atualizar a struct que escolhemos, para receber os novos valores e continuar a comparação com os novos
						valores.
						
				*/
				
				fseek(PtrDic,b*sizeof(TpDic),0);
				fread(&RegB,sizeof(TpDic),1,PtrDic);
				/*
						a função de fseek com fread é de ser a struct utilizada para a comparação, ou seja ela recebe a struct da frente, para se fazer a comparação
						
				*/
				
				
				if(stricmp(RegA.Ingles,RegB.Ingles)>0)
				{
					//troca
					fseek(PtrDic,a*sizeof(TpDic),0);
					fwrite(&RegB,sizeof(TpDic),1,PtrDic);
					
					fseek(PtrDic,b*sizeof(TpDic),0);
					fwrite(&RegA,sizeof(TpDic),1,PtrDic);
					
					/*
							aqui ele faz a troca, como ele já estão salvas as structs, a unica coisa a ser feita é declarar em que posição vc quer salvar as structs.
					*/
				}
			}
		fclose(PtrDic);
		printf("\nArquivo Ordenado!!\n");
	}
	getch();
}


int main(void)
{
	srand(time(NULL));
	CadDic();
	RelPalavras();
	Consulta();
	ExcLogica();
	OrdenarArquivo();
	
	ExcFisica();
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




