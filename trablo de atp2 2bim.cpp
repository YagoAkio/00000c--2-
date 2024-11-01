#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>


struct automovel
{
	char marca[20],modelo[45],cor[35],datacomp[11],combustivel[20],placa[8],RENAVAM[12],status;
	int ano_fabri,cavalos,km;
	float valor;
};

struct cliente
{
	char CPF[16], nascimento[12], nome[60], endereco[60],status;
};

struct venda
{
	char RENAVAM[12], CPF[16], DATA[12], status;
	float valor;
};

void Moldurar(int CI,int LI,int CF,int LF,int Cor)
{
	int i;
	textcolor(Cor);
	gotoxy(CI,LI);
	printf("%c", 201);
	gotoxy(CF,LI);
	printf("%c",187);
	gotoxy(CI,LF);
	printf("%c",200);
	gotoxy(CF,LF);
	printf("%c",188);
	
	for(i=CI+1;i<CF;i++)
	{
		gotoxy(i,LI);
		printf("%c",205);
		gotoxy(i,LF);
		printf("%c",205);
	}
	for(i=LI+1;i<LF;i++)
	{
		gotoxy(CI,i);
		printf("%c",186);
		gotoxy(CF,i);
		printf("%c",186);
	}
}

void MenuPrincipal(void)
{
	Moldurar(95,15,145,39,7);
	Moldurar(98,17,142,19,7);
	gotoxy(118,18);
	printf("MENU\n");
	gotoxy(97,20);
	printf("-----------------------------------------------");
	Moldurar(98,21,138,23,7);
	gotoxy(104,22);
	printf("[1] = INSERIR");
	Moldurar(98,24,138,26,7);
	gotoxy(104,25);
	printf("[2] = ALTERAR");
	Moldurar(98,27,138,29,7);
	gotoxy(104,28);
	printf("[3] = CONSULTAR");
	Moldurar(98,30,138,32,7);
	gotoxy(104,31);
	printf("[4] = ELIMINE INFORMACAO");
	Moldurar(98,33,138,35,7);
	gotoxy(104,34);
	printf("[5] = RELATORIO");
	Moldurar(98,36,138,38,7);
	gotoxy(104,37);
	printf("[ESC] = SAIR/EXCLUIR");

}

void MenuTipo(void)
{
	Moldurar(95,15,145,33,7);
	Moldurar(98,17,142,19,7);
	gotoxy(118,18);
	printf("TIPO\n");
	gotoxy(97,20);
	printf("-----------------------------------------------");
	Moldurar(98,21,138,23,7);
	gotoxy(104,22);
	printf("[1] = CARRO");
	Moldurar(98,24,138,26,7);
	gotoxy(104,25);
	printf("[2] = CLIENTE");
	Moldurar(98,27,138,29,7);
	gotoxy(104,28);
	printf("[3] = VENDA");
	Moldurar(98,30,138,32,7);
	gotoxy(104,31);
	printf("[ESC] = VOLTAR");

}

void CadastroAutomovel(void)
{
	Moldurar(80,10,160,12,7);
	gotoxy(109,11);
	printf("CADASTRO DE AUTOMOVEIS");
	
	Moldurar(80,13,160,64,7);
	
	Moldurar(81,14,159,16,7);
	gotoxy(85,15);
	printf("Marca: ");
	fflush(stdin);
	
	Moldurar(81,17,159,19,7);
	gotoxy(85,18);
	printf("Modelo: ");
	
	Moldurar(81,20,159,22,7);
	gotoxy(85,21);
	printf("Cor: ");
	
	Moldurar(81,23,159,25,7);
	gotoxy(85,24);				
	printf("Ano de Fabricacao: ");
	
	
	Moldurar(81,26,159,45,7);
	Moldurar(82,27,158,29,7);
	gotoxy(110,28);	
	printf("Tipo do Combustivel:");
	Moldurar(82,30,158,38,7);
	gotoxy(100,31);
	printf("[1] - GASOLINA\n");
	gotoxy(100,32);
	printf("[2] - ETANOL\n");
	gotoxy(100,33);
	printf("[3] - FLEX\n");
	gotoxy(100,34);
	printf("[4] - DISEL\n");
	gotoxy(100,35);
	printf("[5] - GNV\n");
	gotoxy(100,36);
	printf("[6] - ELETRICIDADE\n");
	gotoxy(100,37);
	printf("[7] - OUTRO\n");
	Moldurar(82,39,158,41,7);
	gotoxy(85,40);
	printf("OPCAO ESCOLHIDA: ");
	
	Moldurar(81,46,159,48,7);
	gotoxy(85,47);
	printf("Potencia: ");

	Moldurar(81,49,159,51,7);
	gotoxy(85,50);
	printf("Data da Aquisicao: ");
	
	Moldurar(81,52,159,54,7);
	gotoxy(85,53);
	printf("RENAVAM: ");	
	
	Moldurar(81,55,159,57,7);
	gotoxy(85,56);
	printf("Placa: ");
	
	Moldurar(81,58,159,60,7);
	gotoxy(85,59);
	printf("Quilometragem: ");
	
	Moldurar(81,61,159,63,7);
	gotoxy(85,62);
	printf("Valor Atual: ");
		
}

void MenuRelatorio(void)
{
	Moldurar(95,15,145,30,7);
	Moldurar(98,17,142,19,7);
	gotoxy(101,18);
	printf("TIPO DE RELAORIO DE AUTOMOVEIS\n");
	gotoxy(97,20);
	printf("-----------------------------------------------");
	Moldurar(98,21,138,23,7);
	gotoxy(104,22);
	printf("[1] = DATA");
	Moldurar(98,24,138,26,7);
	gotoxy(104,25);
	printf("[2] = FAIXA DE VALOR");
	Moldurar(98,27,138,29,7);
	gotoxy(104,28);
	printf("[ESC] = VOLTAR");

}

void MenuPesquisa(void)
{
	Moldurar(95,15,145,30,7);
	Moldurar(98,17,142,19,7);
	gotoxy(110,18);
	printf("TIPO DE CONSULTA\n");
	gotoxy(97,20);
	printf("-----------------------------------------------");
	Moldurar(98,21,138,23,7);
	gotoxy(104,22);
	printf("[1] = PESQUISA");
	Moldurar(98,24,138,26,7);
	gotoxy(104,25);
	printf("[2] = TUDO");
	Moldurar(98,27,138,29,7);
	gotoxy(104,28);
	printf("[ESC] = VOLTAR");

}

int BuscaPlaca(FILE *b,char aux[8])
{
	automovel a;
	b = fopen("Automovel.dat","rb");
	rewind(b);
	fread(&a,sizeof(automovel),1,b);
	while (!feof(b) && stricmp(aux,a.placa)!=0)
		fread(&a,sizeof(automovel),1,b);
	if (!feof(b))
		return ftell(b)-sizeof(automovel);
	else
		return -1;
	fclose(b);
}

int BuscaCPFV(FILE *b,char aux[16])
{
	venda a;
	b = fopen("Vendas.dat","rb");
	rewind(b);
	fread(&a,sizeof(venda),1,b);
	while (!feof(b) && stricmp(aux,a.CPF)!=0)
		fread(&a,sizeof(automovel),1,b);
	if (!feof(b))
		return ftell(b)-sizeof(venda);
	else
		return -1;
	fclose(b);
}

int BuscaRENAVAMV(FILE *b,char aux[11])
{
	venda a;
	b = fopen("Vendas.dat","rb");
	rewind(b);
	fread(&a,sizeof(venda),1,b);
	while (!feof(b) && stricmp(aux,a.RENAVAM)!=0)
		fread(&a,sizeof(venda),1,b);
	if (!feof(b))
		return ftell(b)-sizeof(venda);
	else
		return -1;
	fclose(b);
}

int BuscaRENAVAM(FILE *b,char aux[11])
{
	automovel a;
	b = fopen("Automovel.dat","rb");
	rewind(b);
	fread(&a,sizeof(automovel),1,b);
	while (!feof(b) && stricmp(aux,a.RENAVAM)!=0)
		fread(&a,sizeof(automovel),1,b);
	if (!feof(b))
		return ftell(b)-sizeof(automovel);
	else
		return -1;
	fclose(b);
}

//validações

int ValidarRENAVAM(char a[11])
{
	int i,aux2,s=2,count=0;
	char aux[2];
	for(i=9;i>=0;i--)
	{
		aux[0]=a[i];
		aux2=atoi(aux);
		aux2*=s;
		count+=aux2;
		s++;
		if(s==10)
		{
			s=2;
		}
	}
	aux[0]=a[10];
	if(((count*10)%11)==atoi(aux))
	{
		return 1;
	}
	else
	{ 
		return 0;
	}
}

int validanum(char a)
{
	char nums[]= "0123456789";
	int i=0;
	while(i<10 || a!=nums[i])
	{
		i++;
	}
	if(i<10)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int validaletra(char a)
{
	char letras[]= "ABCDEFGHIJKLMNOPQRSTUVXWYZ";
	int i=0;
	while(i<26 || a!=letras[i])
	{
		i++;
	}
	if(i<26)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int ValidarPlaca(char a[8])
{
	int i=0;
	if(strlen(a)!=7)
	{
		return 1;
	}
	else
	{
		if(validaletra(a[0])==1 && validaletra(a[1])==1 && validaletra(a[2])==1 && validanum(a[3])==1 && (validaletra(a[4])==1 || validanum(a[4])==1) && validanum(a[5])==1 && validanum(a[6])==1)
		{
			return 1;
		}
		else
		{
			return 0;
		}				
	}
}


int ValidarData(char a[11])
{
	int n1,n2,n3, q=0;
	char aux[4];
	aux[0]=a[0];
	aux[1]=a[1];
	n1 = atoi(aux);
	aux[0]=a[3];
	aux[1]=a[4];
	n2 = atoi(aux);
	aux[0]=a[6];
	aux[1]=a[7];
	aux[2]=a[8];
	aux[3]=a[9];
	n3 = atoi(aux);
	if(strlen(a)<10)
	{
		q++;
	}
	else
	{
		if(a[2]!=47 && a[5]!=47)
		{
			q++;	
		}
		else
		{	
			if(n3<1900 || n3>2022)
			{
				q++;
			}
			else
			{
				if(n1>31 || n2>12 )
				{
					q++;
				}
				else
				{
					if((n2==2 || n2==4 || n2==6|| n2==9|| n2==11) && n1>30)
					{
						q++;
					}
					else
					{
						if(n2==2 && n1>29)
						{
							q++;
						}
						else
						{
							if(n2==2 && n1>28 && n3%4!=0)
							{
								q++;
							}	
						}	
					}	
				}
			}	
		}
	}	
	
	if(q>0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
	
}

void Apagar(int inicio,int fim,int linha,char a[20],int tempo)
{
	int k;
	for(k=inicio;k<fim;k++)
	{
		gotoxy(k,linha);
		textcolor(BLACK);
		cprintf("-");
	} 
	gotoxy(inicio,linha);
	textcolor(WHITE);
	printf("%s",a);
	Sleep(tempo);
	for(k=inicio;k<fim;k++)
	{
		gotoxy(k,linha);
		textcolor(BLACK);
		cprintf("-");
	}
	textcolor(WHITE);
}


int ordenar(automovel a)
{
	automovel c;
	FILE *b = fopen("Automovel.dat","rb+");

	fread(&c,sizeof(automovel),1,b);
	while(!feof(b) && strcmp(a.marca,c.marca)>=0)
	{
		fread(&c,sizeof(automovel),1,b);
	}
	
}

void CadastroAutomovel2(void)
{
	automovel a;
	FILE *b = fopen("Automovel.dat","ab");
	int comp,l=0,op,k=0,z=0;
	char aux[6][20] = {"Gasolina","Etano","Flex","Disel","GNV","Eletricidade"},aux2[8],ex[]="MARCA INVALIDA";
	
	a.status='A';
	
	
	//Marca
	gotoxy(92,15);
	fflush(stdin);
	gets(a.marca);
	while(strcmp(a.marca,"\0")==0)
	{
		Apagar(92,159,15,(char*)"MARCA INVALIDA",1000);
		gotoxy(92,15);
		fflush(stdin);
		gets(a.marca);
	}
	strupr(a.modelo);
	
	
	//Modelo
	gotoxy(93,18);
	fflush(stdin);
	gets(a.modelo);
	while(strcmp(a.modelo,"\0")==0)
	{
		Apagar(93,159,18,(char*)"MODELO INVALIDA",1000);
		gotoxy(93,18);
		fflush(stdin);
		gets(a.modelo);
	}
	strlwr(a.modelo);
	toupper(a.modelo[0]);
	
	
	//Cor
	gotoxy(90,21);
	fflush(stdin);
	gets(a.cor);
	while(strcmp(a.cor,"\0")==0)
	{
		Apagar(90,159,21,(char*)"COR INVALIDA",1000);
		gotoxy(90,21);
		fflush(stdin);
		gets(a.cor);
	}
	strlwr(a.cor);
	toupper(a.cor[0]);
	
		
	//Ano de Fabricação
	gotoxy(104,24);
	scanf("%d",&a.ano_fabri);
	while(a.ano_fabri<1886 || a.ano_fabri>2024)
	{
		Apagar(104,159,24,(char*)"ANO INVALIDO",1000);
		gotoxy(104,24);
		scanf("%d",&a.ano_fabri);
	}
	
	//Combistivel
	gotoxy(102,40);
	do
	{
		gotoxy(102,40);
		textcolor(WHITE);
		op=getche();
		while(op!=49 && op!=50 && op!=51 && op!=52 && op!=53 && op!=54 && op!=55)
		{
			Apagar(101,110,40,(char*)"INVALIDO",1000);
			gotoxy(102,40);
			op=getche();
		}
		switch(op)
		{
			case '1':
				strcpy(a.combustivel,aux[0]);
				break;
			case '2':
				strcpy(a.combustivel,aux[1]);
				break;
			case '3':
				strcpy(a.combustivel,aux[2]);
				break;
			case'4':
				strcpy(a.combustivel,aux[3]);
				break;
			case '5':
				strcpy(a.combustivel,aux[4]);
				break;
			case '6':
				strcpy(a.combustivel,aux[5]);
				break;
			case '7':
				Moldurar(82,42,158,44,7);
				gotoxy(85,43);
				printf("Combustivel: ");
				fflush(stdin);
				gotoxy(98,43);
				gets(a.combustivel);
				while(strcmp(a.combustivel,"\0")==0)
				{
					Apagar(96,158,43,(char*)"TIPO INVALIDO",1000);
					printf("Combustivel: ");
					fflush(stdin);
					gets(a.combustivel);
				}
				strlwr(a.combustivel);
				toupper(a.combustivel[0]);
				break;	
		}
	}while(op!=49 && op!=50 && op!=51 && op!=52 && op!=53 && op!=54 && op!=55);
	
	//Potencia
	gotoxy(95,47);
	scanf("%d",&a.cavalos);
	while(a.cavalos<0 || a.cavalos>1600)
	{
		Apagar(95,159,47,(char*)"POTENCIA INVALIDO",1000);
		gotoxy(95,47);
		scanf("%d",&a.cavalos);
	}
	
	
	//Aquisição
	gotoxy(104,50);
	fflush(stdin);
	gets(a.datacomp);
	while(strcmp(a.datacomp,"\0")==0 || ValidarData(a.datacomp)!=0)
	{
		Apagar(104,159,50,(char*)"DATA INVALIDA",1000);
		gotoxy(104,50);
		fflush(stdin);
		gets(a.datacomp);
	}

	
	
	//RENAVAM - FALTA VER SE NAO REPETE
	gotoxy(94,53);
	fflush(stdin);
	gets(a.RENAVAM);
	while(strcmp(a.RENAVAM,"\0")==0 || ValidarRENAVAM(a.RENAVAM)!=1|| strlen(a.RENAVAM) != 11 || BuscaRENAVAM(b,a.RENAVAM)!=-1)
	{
		Apagar(94,159,53,(char*)"RENAVAM INVALIDA",1000);
		gotoxy(94,53);
		fflush(stdin);
		gets(a.RENAVAM);
	}
	
	
	//Placa- FALTA VER SE NAO REPETE
	gotoxy(92,56);
	fflush(stdin);
	gets(a.placa);
	while(strcmp(a.placa,"\0")==0 || ValidarPlaca(a.placa)!=0 || BuscaPlaca(b,a.placa)!=-1)
	{
		Apagar(92,159,56,(char*)"PLACA INVALIDA",1000);
		gotoxy(92,56);
		fflush(stdin);
		gets(a.placa);
	}
	strupr(a.placa);
	
	//Quilometragem
	gotoxy(100,59);
	scanf("%d",&a.km);
	while(a.km<0)
	{
		Apagar(100,159,59,(char*)"QUILOMETRAGEM INVALIDO",1000);
		gotoxy(100,59);
		scanf("%d",&a.km);
	}
	
	
	//Valor
	gotoxy(98,62);
	scanf("%f",&a.valor);
	while(a.valor<0)
	{
		Apagar(98,159,62,(char*)"VALOR INVALIDO",1000);
		gotoxy(98,62);
		scanf("%f",&a.valor);
	}
	fwrite(&a,sizeof(automovel),1,b);
	fclose(b);

}

void CadastroClientes(void)
{
	Moldurar(80,10,160,12,7);
	gotoxy(109,11);
	printf("CADASTRO DE CLIENTES");
	
	Moldurar(80,13,160,26,7);
	
	Moldurar(81,14,159,16,7);
	gotoxy(85,15);
	printf("CPF: ");
	fflush(stdin);
	
	Moldurar(81,17,159,19,7);
	gotoxy(85,18);
	printf("Data de Nascimento: ");
	
	Moldurar(81,20,159,22,7);
	gotoxy(85,21);
	printf("Nome: ");
	
	Moldurar(81,23,159,25,7);
	gotoxy(85,24);				
	printf("Endereco: ");
}

int ValidarCPF(char a[16])
{
    char aux[11];
    int n[11],i;
    aux[0] = a[0];
    aux[1] = a[1];
    aux[2] = a[2];
    aux[3] = a[4];
    aux[4] = a[5];
    aux[5] = a[6];
    aux[6] = a[8];
    aux[7] = a[9];
    aux[8] = a[10];
    aux[9] = a[12];
    aux[10] = a[13];
    for(i=0;i<12;i++)
    {
        n[i]=atoi(aux);
    }

    if(a[3]!='.' && a[7]!='.' && a[11]!='-')
    {
        return 1;
    }
    else
    {
		return -1;
    }
}

int BuscaCPF(FILE *b,char aux[16])
{
	cliente a;
	b = fopen("Cliente.dat","rb");
	rewind(b);
	fread(&a,sizeof(cliente),1,b);
	while (!feof(b) && stricmp(aux,a.CPF)!=0)
		fread(&a,sizeof(cliente),1,b);
	if (!feof(b))
		return ftell(b)-sizeof(cliente);
	else
		return -1;
	fclose(b);
}

void CadastroClientes2(void)
{
	cliente a;
	FILE *b = fopen("Cliente.dat","ab");
	
	a.status = 'A';
	
	
	//CPF
	gotoxy(90,15);
	fflush(stdin);
	gets(a.CPF);
	while(strcmp(a.CPF,"\0")==0 || ValidarCPF(a.CPF)!=-1 || BuscaCPF(b,a.CPF)!=-1)
	{
		Apagar(90,153,15,(char*)"CPF INVALIDO",1000);
		gotoxy(90,15);
		fflush(stdin);
		
		gets(a.CPF);
	}
	
	
	
	//Data de Nascimento
	gotoxy(105,18);
	gets(a.nascimento);
	while(strcmp(a.nascimento,"\0")==0 || ValidarData(a.nascimento)!=0)
	{
		Apagar(105,153,18,(char*)"DATA INVALIDO",1000);
		gotoxy(105,18);
		fflush(stdin);
		gets(a.nascimento);
	}
	
	//Nome
	gotoxy(91,21);
	gets(a.nome);
	while(strcmp(a.nome,"\0")==0)
	{
		Apagar(91,153,21,(char*)"NOME INVALIDO",1000);
		gotoxy(91,21);
		fflush(stdin);
		gets(a.nome);
	}
	
	//Endereço
	gotoxy(95,24);
	gets(a.endereco);
	while(strcmp(a.nascimento,"\0")==0)
	{
		Apagar(95,153,24,(char*)"ENDERECO INVALIDO",1000);
		gotoxy(95,24);
		fflush(stdin);
		gets(a.endereco);
	}
	
	fwrite(&a,sizeof(cliente),1,b);
	fclose(b);
}

void AlterarCliente(void)
{
	cliente a;
	FILE *b = fopen("Cliente.dat","rb+");
	char cpf[16];
	int pos;
		
	Moldurar(100,1,130,3,7);
	gotoxy(102,2);
	printf("QUAL O CPF: ");
	fflush(stdin);
	gets(cpf);
	pos = BuscaCPF(b,cpf);
	while(strcmp(cpf,"\0")==0 || pos<0)
	{
		Apagar(114,130,2,(char*)"CPF INVALIDO",1000);
		gotoxy(114,2);
		fflush(stdin);
		gets(cpf);
		pos = BuscaCPF(b,cpf);
	}
	fseek(b,pos,0);
	
	system("cls");
	CadastroClientes();
	
	a.status = 'A';
	
	gotoxy(90,15);
	gets(a.CPF);
	if(strcmp(a.CPF,cpf)!=0)
	{
		while(strcmp(a.CPF,"\0")==0 || ValidarCPF(a.CPF)!=-1 || BuscaCPF(b,a.CPF)!=-1)
		{
			Apagar(90,153,15,(char*)"CPF INVALIDO",1000);
			gotoxy(90,15);
			fflush(stdin);
			gets(a.CPF);
			if(strcmp(a.CPF,cpf)==0)
			{
				strcpy(a.CPF,(char*)"\0");
			}
			
		}
	}	
	if(strcmp(a.CPF,cpf)==0)
	{
		strcpy(cpf,a.CPF);
	}
	
	
	
	//Data de Nascimento
	gotoxy(105,18);
	gets(a.nascimento);
	while(strcmp(a.nascimento,"\0")==0 || ValidarData(a.nascimento)!=0)
	{
		Apagar(105,153,18,(char*)"DATA INVALIDO",1000);
		gotoxy(105,18);
		fflush(stdin);
		gets(a.nascimento);
	}
	
	//Nome
	gotoxy(91,21);
	gets(a.nome);
	while(strcmp(a.nome,"\0")==0)
	{
		Apagar(91,153,21,(char*)"NOME INVALIDO",1000);
		gotoxy(91,21);
		fflush(stdin);
		gets(a.nome);
	}
	
	//Endereço
	gotoxy(95,24);
	gets(a.endereco);
	while(strcmp(a.nascimento,"\0")==0)
	{
		Apagar(95,153,24,(char*)"ENDERECO INVALIDO",1000);
		gotoxy(95,20);
		fflush(stdin);
		gets(a.endereco);
	}
	
	fwrite(&a,sizeof(cliente),1,b);
	fclose(b);
}


void AlterarAutomovel(void)
{
	automovel a;
	FILE *b = fopen("Automovel.dat","rb+");
	int op2, pos;
	char placa[8],renava[12];
	int comp,l=0,op,k=0,z=0;
	char r[11],aux[6][20] = {"Gasolina","Etano","Flex","Disel","GNV","Eletricidade"},aux2[8],ex[]="MARCA INVALIDA";
	
	
	Moldurar(165,1,200,3,7);
	gotoxy(177,2);
	printf("QUAL O TIPO?");
	
	Moldurar(165,4,200,11,7);
	
	Moldurar(166,5,199,7,7);
	gotoxy(170,6);
	printf("[1] = PLACA");
	
	Moldurar(166,8,199,10,7);
	gotoxy(170,9);
	printf("[2] = RENAVAM");
	
	Moldurar(165,12,200,14,7);
	gotoxy(170,13);
	printf("OPCAO: ");
	op2 = getche();
	while(op2!=49 && op2!=50)
	{
		Apagar(177,195,13,(char*)"INEXISTENTE",1000);
		gotoxy(177,13);
		op2 = getche();	
	} 
	Moldurar(165,15,200,17,7);
	gotoxy(170,16);
	switch(op2)
	{
		case '1':
			printf("PLACA: ");
			fflush(stdin);
			gets(placa);
			strupr(placa);
			pos = BuscaPlaca(b,placa);
			while(strcmp(placa,"\0")==0 || pos<0)
			{
				Apagar(177,192,16,(char*)"PLACA INVALIDA",1000);
				gotoxy(177,16);
				fflush(stdin);
				gets(placa);
				strupr(placa);
				pos = BuscaPlaca(b,placa);
			}
			fseek(b,pos,0);
			break;
		case '2':
			printf("RENAVAM: ");
			fflush(stdin);
			gets(r);
			pos = BuscaRENAVAM(b,r);
			while(strcmp(r,"\0")==0 || pos<0)
			{
				Apagar(179,198,16,(char*)"RENAVAM INVALIDA",1000);
				gotoxy(179,16);
				fflush(stdin);
				gets(r);
				pos = BuscaRENAVAM(b,r);
			}
			fseek(b,pos,0);
			break;
	}
	Moldurar(165,18,200,20,7);
	gotoxy(170,19);
	printf("ENCONTRADO");
	Sleep(1000);
	system("cls");	
	
	CadastroAutomovel();
	
	a.status='A';
	
	//Marca
	gotoxy(92,15);
	fflush(stdin);
	gets(a.marca);
	while(strcmp(a.marca,"\0")==0)
	{
		Apagar(92,159,15,(char*)"MARCA INVALIDA",1000);
		gotoxy(92,15);
		fflush(stdin);
		gets(a.marca);
	}
	strupr(a.modelo);
	
	
	//Modelo
	gotoxy(93,18);
	fflush(stdin);
	gets(a.modelo);
	while(strcmp(a.modelo,"\0")==0)
	{
		Apagar(93,159,18,(char*)"MODELO INVALIDA",1000);
		gotoxy(93,18);
		fflush(stdin);
		gets(a.modelo);
	}
	strlwr(a.modelo);
	toupper(a.modelo[0]);
	
	
	//Cor
	gotoxy(90,21);
	fflush(stdin);
	gets(a.cor);
	while(strcmp(a.cor,"\0")==0)
	{
		Apagar(90,159,21,(char*)"COR INVALIDA",1000);
		gotoxy(90,21);
		fflush(stdin);
		gets(a.cor);
	}
	strlwr(a.cor);
	toupper(a.cor[0]);
	
		
	//Ano de Fabricação
	gotoxy(104,24);
	scanf("%d",&a.ano_fabri);
	while(a.ano_fabri<1886 || a.ano_fabri>2024)
	{
		Apagar(104,159,24,(char*)"ANO INVALIDO",1000);
		gotoxy(104,24);
		scanf("%d",&a.ano_fabri);
	}
	
	//Combistivel
	gotoxy(102,40);
	do
	{
		gotoxy(102,40);
		textcolor(WHITE);
		op=getche();
		while(op!=49 && op!=50 && op!=51 && op!=52 && op!=53 && op!=54 && op!=55)
		{
			Apagar(101,110,40,(char*)"INVALIDO",1000);
			gotoxy(102,40);
			op=getche();
		}
		switch(op)
		{
			case '1':
				strcpy(a.combustivel,aux[0]);
				break;
			case '2':
				strcpy(a.combustivel,aux[1]);
				break;
			case '3':
				strcpy(a.combustivel,aux[2]);
				break;
			case'4':
				strcpy(a.combustivel,aux[3]);
				break;
			case '5':
				strcpy(a.combustivel,aux[4]);
				break;
			case '6':
				strcpy(a.combustivel,aux[5]);
				break;
			case '7':
				Moldurar(82,42,158,44,7);
				gotoxy(85,43);
				printf("Combustivel: ");
				fflush(stdin);
				gotoxy(98,43);
				gets(a.combustivel);
				while(strcmp(a.combustivel,"\0")==0)
				{
					Apagar(96,158,43,(char*)"TIPO INVALIDO",1000);
					printf("Combustivel: ");
					fflush(stdin);
					gets(a.combustivel);
				}
				strlwr(a.combustivel);
				toupper(a.combustivel[0]);
				break;	
		}
	}while(op!=49 && op!=50 && op!=51 && op!=52 && op!=53 && op!=54 && op!=55);
	
	//Potencia
	gotoxy(95,47);
	scanf("%d",&a.cavalos);
	while(a.cavalos<0 || a.cavalos>1600)
	{
		Apagar(95,159,47,(char*)"POTENCIA INVALIDO",1000);
		gotoxy(95,47);
		scanf("%d",&a.cavalos);
	}
	
	
	//Aquisição
	gotoxy(104,50);
	fflush(stdin);
	gets(a.datacomp);
	while(strcmp(a.datacomp,"\0")==0 || ValidarData(a.datacomp)!=0)
	{
		Apagar(104,159,50,(char*)"DATA INVALIDA",1000);
		gotoxy(104,50);
		fflush(stdin);
		gets(a.datacomp);
	}

	
	
	//RENAVAM
	gotoxy(94,53);
	fflush(stdin);
	gets(a.RENAVAM);
	while(strcmp(a.RENAVAM,"\0")==0 || ValidarRENAVAM(a.RENAVAM)!=1|| strlen(a.RENAVAM)!=11 || BuscaRENAVAM(b,a.RENAVAM)!=-1)
	{
		Apagar(94,159,53,(char*)"RENAVAM INVALIDA",1000);
		gotoxy(94,53);
		fflush(stdin);
		gets(a.RENAVAM);
	}

	
	
	//Placa 
	gotoxy(92,56);
	fflush(stdin);
	gets(a.placa);
	while(strcmp(a.placa,"\0")==0 || ValidarPlaca(a.placa)!=0 || BuscaPlaca(b,a.placa)!=-1)
	{
		Apagar(92,159,56,(char*)"PLACA INVALIDA",1000);
		gotoxy(92,56);
		fflush(stdin);
		gets(a.placa);
	}
	strupr(a.placa);


	
	//Quilometragem
	gotoxy(100,59);
	scanf("%d",&a.km);
	while(a.km<0)
	{
		Apagar(100,159,59,(char*)"QUILOMETRAGEM INVALIDO",1000);
		gotoxy(100,59);
		scanf("%d",&a.km);
	}
	
	
	//Valor
	gotoxy(98,62);
	scanf("%f",&a.valor);
	while(a.valor<0)
	{
		Apagar(98,159,62,(char*)"VALOR INVALIDO",1000);
		gotoxy(98,62);
		scanf("%f",&a.valor);
	}
	
	fwrite(&a,sizeof(automovel),1,b);
	fclose(b);
	
}

void TabelaDeAmostraC(void)
{
	cliente a;
	FILE *b = fopen("Cliente.dat","rb");
	int i=7,c;
	
	Moldurar(1,1,89,3,7);
	gotoxy(50,2);
	printf("CADASTRO CLIENTES");
	
	
	if(b==NULL)
	{
		Moldurar(1,4,120,9,7);
		gotoxy(45,7);
		printf("ERRO DE ABERTURA");
	}
	else
	{
		Moldurar(1,4,70,6,7);
		gotoxy(13,5);
		printf("NOME");
		
		Moldurar(71,4,89,6,7);
		gotoxy(75,5);
		printf("CPF");
		
		fread(&a,sizeof(cliente),1,b);
		for(c=7;!feof(b);c++)
		{
			if(a.status=='A')
			{
				gotoxy(5,i);
				printf("%s",a.nome);
				gotoxy(75,i);
				printf("%s",a.CPF);
				i++;
			}
			fread(&a,sizeof(cliente),1,b);	
		}
		
	}
	fclose(b);
}

void TabelaDeAmostraV(void)
{
	venda a;
	FILE *b = fopen("Vendas.dat","rb");
	int i=7,c;
	
	Moldurar(1,1,45,3,7);
	gotoxy(16,2);
	printf("CARROS VENDIDOS");
	
	
	if(b==NULL)
	{
		Moldurar(1,4,45,9,7);
		gotoxy(45,7);
		printf("ERRO DE ABERTURA");
	}
	else
	{
		Moldurar(1,4,25,6,7);
		gotoxy(3,5);
		printf("RENAVAM");
		
		Moldurar(26,4,45,6,7);
		gotoxy(28,5);
		printf("VALOR");
		
		fread(&a,sizeof(venda),1,b);
		for(c=7;!feof(b);c++)
		{
			if(a.status=='A')
			{
				gotoxy(3,i);
				printf("%s",a.RENAVAM);
				gotoxy(28,i);
				printf("%.2f",a.valor);
				i++;
			}
			fread(&a,sizeof(venda),1,b);	
		}
		
	}
	fclose(b);
}

void TabelaDeAmostra(void)
{
	automovel a;
	FILE *b = fopen("Automovel.dat","rb");
	int i=7,c;
	
	rewind(b);
	
	Moldurar(1,1,120,3,7);
	gotoxy(50,2);
	printf("ESTOQUE DE AUTOMOVEIS");
	
	
	if(b==NULL)
	{
		Moldurar(1,4,120,9,7);
		gotoxy(45,7);
		printf("ERRO DE ABERTURA");
	}
	else
	{
		Moldurar(1,4,30,6,7);
		gotoxy(13,5);
		printf("MARCA");
		Moldurar(31,4,100,6,7);
		gotoxy(62,5);
		printf("MODELO");
		Moldurar(101,4,120,6,7);
		gotoxy(108,5);
		printf("PLACA");
		fread(&a,sizeof(automovel),1,b);
		for(c=7;!feof(b);c++)
		{
			if(a.status=='A')
			{
				gotoxy(5,i);
				printf("%s",a.marca);
				gotoxy(35,i);
				printf("%s",a.modelo);
				gotoxy(105,i);
				printf("%s",a.placa);
				i++;
			}
			fread(&a,sizeof(automovel),1,b);	
		}
	}
	fclose(b);
}

void CadastroVendas(void)
{
	Moldurar(80,10,160,12,7);
	gotoxy(109,11);
	printf("CADASTRO DE VENDAS");
	
	Moldurar(80,13,160,26,7);
	
	Moldurar(81,14,159,16,7);
	gotoxy(85,15);
	printf("RENAVAM: ");
	fflush(stdin);
	
	Moldurar(81,17,159,19,7);
	gotoxy(85,18);
	printf("CPF: ");
	
	Moldurar(81,20,159,22,7);
	gotoxy(85,21);
	printf("Data da compra: ");
	
	Moldurar(81,23,159,25,7);
	gotoxy(85,24);				
	printf("Valor vendido: ");
}

void inutilizarA(FILE *b ,char a[12])
{
	automovel c;
	b = fopen("Automovel.dat","rb+");
	int pos;
	pos = BuscaRENAVAM(b,a);
	fseek(b,pos,0);
	fread(&c,sizeof(automovel),1,b);
	c.status = 'V';
	fseek(b,pos,0);
	fwrite(&c,sizeof(automovel),1,b);
	fclose(b);
}

void CadastroVendas2(void)
{
	venda a;
	FILE *b = fopen("Vendas.dat","ab");
	FILE *c = fopen("Automovel.dat","rb+");
	FILE *d = fopen("Cliente.dat","rb+");
	
	a.status = 'A';
	
	//RENAVAM
	gotoxy(94,15);
	fflush(stdin);
	gets(a.RENAVAM);
	while(strcmp(a.RENAVAM,"\0")==0 || ValidarRENAVAM(a.RENAVAM)!=1|| strlen(a.RENAVAM)!=11 || BuscaRENAVAM(c,a.RENAVAM)==-1)
	{
		Apagar(94,153,15,(char*)"RENAVAM INVALIDO",1000);
		gotoxy(94,15);
		fflush(stdin);
		gets(a.RENAVAM);
	}
	inutilizarA(c,a.RENAVAM);
	
	
	//CPF
	gotoxy(90,18);
	fflush(stdin);
	gets(a.CPF);
	while(strcmp(a.CPF,"\0")==0 || ValidarCPF(a.CPF)!=-1 || BuscaCPF(d,a.CPF)==-1)
	{
		Apagar(90,153,18,(char*)"CPF INVALIDO",1000);
		gotoxy(90,18);
		fflush(stdin);
		gets(a.CPF);
	}
	
	//DATA
	gotoxy(101,21);
	fflush(stdin);
	gets(a.DATA);
	while(strcmp(a.DATA,"\0")==0)
	{
		Apagar(101,153,21,(char*)"NOME INVALIDO",1000);
		gotoxy(101,21);
		fflush(stdin);
		gets(a.DATA);
	}
	
	//VAlOR
	gotoxy(100,24);
	scanf("%f",&a.valor);
	while(a.valor<0)
	{
		Apagar(100,153,24,(char*)"VALOR INVALIDO",1000);
		gotoxy(100,24);
			scanf("%f",&a.valor);
	}
	
	fwrite(&a,sizeof(venda),1,b);
	fclose(b);
	fclose(c);
	fclose(d);
}

void AlterarVendas(void)
{
	venda a;
	FILE *c = fopen("Automovel.dat","rb+");
	FILE *d = fopen("Cliente.dat","rb+");
	FILE *b = fopen("Vendas.dat","rb+");
	int op2,pos;
	char cpf[16],r[11];
	
	Moldurar(60,1,100,3,7);
	gotoxy(63,2);
	printf("QUAL O RENAVAM: ");
	fflush(stdin);
	gets(r);
	pos = BuscaRENAVAMV(b,r);
	while(strcmp(r,"\0")==0 || pos<0)
	{
		Apagar(79,99,2,(char*)"RENAVAM INVALIDA",1000);
		gotoxy(79,2);
		fflush(stdin);
		gets(r);
		pos = BuscaRENAVAMV(b,r);
	}
	fseek(b,pos,0);
	
	
	Moldurar(60,4,100,6,7);
	gotoxy(63,5);
	printf("ENCONTRADO");
	Sleep(1000);
	system("cls");
	
	CadastroVendas();
	
	a.status = 'A';
	
	//RENAVAM
	gotoxy(94,15);
	fflush(stdin);
	gets(a.RENAVAM);
	while(strcmp(a.RENAVAM,"\0")==0 || ValidarRENAVAM(a.RENAVAM)!=1|| strlen(a.RENAVAM)!=11 || BuscaRENAVAM(c,a.RENAVAM)==-1)
	{
		Apagar(94,153,15,(char*)"RENAVAM INVALIDO",1000);
		gotoxy(94,15);
		fflush(stdin);
		gets(a.RENAVAM);
	}
	inutilizarA(c,a.RENAVAM);
	
	
	//CPF
	gotoxy(90,18);
	fflush(stdin);
	gets(a.CPF);
	while(strcmp(a.CPF,"\0")==0 || ValidarCPF(a.CPF)!=-1 || BuscaCPF(d,a.CPF)==-1)
	{
		Apagar(90,153,18,(char*)"CPF INVALIDO",1000);
		gotoxy(90,18);
		fflush(stdin);
		gets(a.CPF);
	}
	
	//DATA
	gotoxy(101,21);
	fflush(stdin);
	gets(a.DATA);
	while(strcmp(a.DATA,"\0")==0)
	{
		Apagar(101,153,21,(char*)"NOME INVALIDO",1000);
		gotoxy(101,21);
		fflush(stdin);
		gets(a.DATA);
	}
	
	//VAlOR
	gotoxy(100,24);
	scanf("%f",&a.valor);
	while(a.valor<0)
	{
		Apagar(100,153,24,(char*)"VALOR INVALIDO",1000);
		gotoxy(100,24);
		scanf("%f",&a.valor);
	}
	
	fwrite(&a,sizeof(venda),1,b);
	fclose(b);
	fclose(c);
	fclose(d);
}


void TabelaA(void)
{
	automovel a;
	FILE *b = fopen("Automovel.dat","rb");
	int i=8,c;
	
	rewind(b);
	Moldurar(2,1,214,3,7);
	gotoxy(90,2);
	printf("REGISTRO DE AUTOMOVEIS COMPLETO");
	
		
		Moldurar(2,5,24,7,7);
		gotoxy(10,6);
		printf("MARCA");
		
		Moldurar(25,5,72,7,7);
		gotoxy(40,6);
		printf("MODELO");
		
		Moldurar(73,5,110,7,7);
		gotoxy(90,6);
		printf("COR");
		
		Moldurar(111,5,125,7,7);
		gotoxy(115,6);
		printf("DATA");
		
		Moldurar(126,5,148,7,7);
		gotoxy(134,6);
		printf("COMBUSTIVEL");
		
		Moldurar(149,5,159,7,7);
		gotoxy(151,6);
		printf("PLACA");
		
		Moldurar(160,5,174,7,7);
		gotoxy(163,6);
		printf("RENAVAM");
		
		Moldurar(175,5,181,7,7);
		gotoxy(177,6);
		printf("ANO");
		
		Moldurar(182,5,188,7,7);
		gotoxy(183,6);
		printf("HP");
		
		Moldurar(189,5,198,7,7);
		gotoxy(191,6);
		printf("KM");
		
		Moldurar(199,5,214,7,7);
		gotoxy(200,6);
		printf("PRECO R%c",36);
		
		
		fread(&a,sizeof(automovel),1,b);
		for(c=8;!feof(b);c++)
		{
			if(a.status=='A')
			{
				gotoxy(4,i);
				printf("%s",a.marca);
				gotoxy(27,i);
				printf("%s",a.modelo);
				gotoxy(74,i);
				printf("%s",a.cor);
				gotoxy(112,i);
				printf("%s",a.datacomp);
				gotoxy(127,i);
				printf("%s",a.combustivel);
				gotoxy(150,i);
				printf("%s",a.placa);
				gotoxy(161,i);
				printf("%s",a.RENAVAM);
				gotoxy(176,i);
				printf("%d",a.ano_fabri);
				gotoxy(183,i);
				printf("%d",a.cavalos);
				gotoxy(190,i);
				printf("%d",a.km);
				gotoxy(200,i);
				printf("%.2f",a.valor);
				i++;
			}
			fread(&a,sizeof(automovel),1,b);		
		}
	fclose(b);
}

int convertdata(char a[12],int &d,int &m,int &an)
{
	int i=0;
	char aux[5];
	aux[0]=a[0];
	aux[1]=a[1];
	d = atoi(aux);
	aux[0]=a[3];
	aux[1]=a[4];
	m = atoi(aux);
	aux[0]=a[6];
	aux[1]=a[7];
	aux[2]=a[8];
	aux[3]=a[9];
	an = atoi(aux);
	
}

int cmpdata(char a[12],char b[12],char c[12])
{
	int d1,d2,d3,m1,m2,m3,an1,an2,an3,i,aux;
	char auxd[3],auxm[3],auxa[5];
	convertdata(a,d1,m1,an1);
	convertdata(b,d2,m2,an2);
	convertdata(c,d3,m3,an3);
	if(an1<an2 || an1>an3)
	{
		return 0;
	}
	else
	{
		if((an1==an2 || an1==an3) && (m1<m2 || m1>m3))
		{
			return 0;
		}
		else
		{
			if((an1==an2 || an1==an3) && (m1==m2 || m1==m3) && (d1<d2 || d1>d3))
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
	}
}



int bbb(char aux[45],char a[45])
{
	char l[45],f[45];
	int k;
	strcpy(l,aux);
	strcpy(f,aux);
	k = strlen(aux) - 1;
	l[k]='z';
	f[k]='a';
	if(strcmp(a,f)>0 && strcmp(a,l)<0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

void TabelaAP(void)
{
	automovel a;
	FILE *b = fopen("Automovel.dat","rb");
	int i=8,c;
	char modelo[45];
	
	rewind(b);
	
	Moldurar(2,1,214,3,7);
	gotoxy(50,2);
	printf("MODELO: ");
	fflush(stdin);
	gets(modelo);
	while(strcmp(modelo,"\0")==0)
	{
		Apagar(58,121,2,(char*)"MODELO INVALIDO",1000);
		fflush(stdin);
		gets(modelo);
	}
		
		Moldurar(2,5,24,7,7);
		gotoxy(10,6);
		printf("MARCA");
		
		Moldurar(25,5,72,7,7);
		gotoxy(40,6);
		printf("MODELO");
		
		Moldurar(73,5,110,7,7);
		gotoxy(90,6);
		printf("COR");
		
		Moldurar(111,5,125,7,7);
		gotoxy(115,6);
		printf("DATA");
		
		Moldurar(126,5,148,7,7);
		gotoxy(134,6);
		printf("COMBUSTIVEL");
		
		Moldurar(149,5,159,7,7);
		gotoxy(151,6);
		printf("PLACA");
		
		Moldurar(160,5,174,7,7);
		gotoxy(163,6);
		printf("RENAVAM");
		
		Moldurar(175,5,181,7,7);
		gotoxy(177,6);
		printf("ANO");
		
		Moldurar(182,5,188,7,7);
		gotoxy(183,6);
		printf("HP");
		
		Moldurar(189,5,198,7,7);
		gotoxy(191,6);
		printf("KM");
		
		Moldurar(199,5,214,7,7);
		gotoxy(200,6);
		printf("PRECO R%c",36);
		
		
		fread(&a,sizeof(automovel),1,b);
		for(c=8;!feof(b);c++)
		{
			if(a.status=='A' && bbb(modelo,a.modelo)>0 )
			{
				gotoxy(4,i);
				printf("%s",a.marca);
				gotoxy(27,i);
				printf("%s",a.modelo);
				gotoxy(74,i);
				printf("%s",a.cor);
				gotoxy(112,i);
				printf("%s",a.datacomp);
				gotoxy(127,i);
				printf("%s",a.combustivel);
				gotoxy(150,i);
				printf("%s",a.placa);
				gotoxy(161,i);
				printf("%s",a.RENAVAM);
				gotoxy(176,i);
				printf("%d",a.ano_fabri);
				gotoxy(183,i);
				printf("%d",a.cavalos);
				gotoxy(190,i);
				printf("%d",a.km);
				gotoxy(200,i);
				printf("%.2f",a.valor);
				i++;
			}
			fread(&a,sizeof(automovel),1,b);		
		}
	fclose(b);
}

void TabelaC(void)
{
	cliente a;
	FILE *b = fopen("Cliente.dat","rb");
	int i=7,c;
	
	Moldurar(1,1,181,3,7);
	gotoxy(50,2);
	printf("CADASTRO CLIENTES");
	
	
	if(b==NULL)
	{
		Moldurar(1,4,120,9,7);
		gotoxy(45,7);
		printf("ERRO DE ABERTURA");
	}
	else
	{
		Moldurar(1,4,70,6,7);
		gotoxy(32,5);
		printf("NOME");
		
		Moldurar(71,4,95,6,7);
		gotoxy(73,5);
		printf("DATA DE NASCIMENTO");
		
		Moldurar(96,4,160,6,7);
		gotoxy(126,5);
		printf("ENDERECO");
		
		Moldurar(161,4,181,6,7);
		gotoxy(169,5);
		printf("CPF");
		
		fread(&a,sizeof(cliente),1,b);
		for(c=7;!feof(b);c++)
		{
			if(a.status=='A')
			{
				gotoxy(3,i);
				printf("%s",a.nome);
				gotoxy(73,i);
				printf("%s",a.nascimento);
				gotoxy(98,i);
				printf("%s",a.endereco);
				gotoxy(163,i);
				printf("%s",a.CPF);
				i++;
			}
			fread(&a,sizeof(cliente),1,b);	
		}
		
	}
	fclose(b);
}

int  ValidarDataN(char a[7])
{
	int n1,n2;
	char aux[4];
	aux[0]=a[0];
	aux[1]=a[1];
	n1 = atoi(aux);
	aux[0]=a[3];
	aux[1]=a[4];
	n2 = atoi(aux);
	if(strlen(a)<5)
	{
		return -1;
	}
	else
	{
		if(a[2]!=47 && a[5]!=47)
		{
			return -1;	
		}
		else
		{	
			
			
			if(n1>31 || n2>12 )
			{
				return -1;
			}
			else
			{
				if((n2==2 || n2==4 || n2==6|| n2==9|| n2==11) && n1>30)
				{
					return -1;
				}
				else
				{
					if(n2==2 && n1>29)
					{
						return -1;
					}
					else
					{
						return 1;
					}
						
				}	
			}
			
		}
	}
}

int aaa(char a[12],char b[7])
{
	char aux[6];
	aux[0]=a[0];
	aux[1]=a[1];
	aux[2]=a[2];
	aux[3]=a[3];
	aux[4]=a[4];
	if(strcmp(aux,b)==0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

void TabelaCP(void)
{
	cliente a;
	FILE *b = fopen("Cliente.dat","rb");
	int i=7,c;
	char data[7];
	
	Moldurar(1,1,181,3,7);
	gotoxy(40,2);
	printf("QUAL ANIVERSARIO DESEJA ENCONTRAR: ");
	fflush(stdin);
	gets(data);
	while(strcmp(data,"\0")==0 || ValidarDataN(data)<0)
	{
		Apagar(75,121,2,(char*)"DATA INVALIDO",1000);
		gotoxy(75,2);
		fflush(stdin);
		gets(data);
	}
	
	rewind(b);
	
	if(b==NULL)
	{
		Moldurar(1,4,120,9,7);
		gotoxy(45,7);
		printf("ERRO DE ABERTURA");
	}
	else
	{
		Moldurar(1,4,70,6,7);
		gotoxy(32,5);
		printf("NOME");
		
		Moldurar(71,4,95,6,7);
		gotoxy(73,5);
		printf("DATA DE NASCIMENTO");
		
		Moldurar(96,4,160,6,7);
		gotoxy(126,5);
		printf("ENDERECO");
		
		Moldurar(161,4,181,6,7);
		gotoxy(169,5);
		printf("CPF");
		
		fread(&a,sizeof(cliente),1,b);
		for(c=7;!feof(b);c++)
		{
			if(a.status=='A' && aaa(a.nascimento,data)==1)
			{
				gotoxy(3,i);
				printf("%s",a.nome);
				gotoxy(73,i);
				printf("%s",a.nascimento);
				gotoxy(98,i);
				printf("%s",a.endereco);
				gotoxy(163,i);
				printf("%s",a.CPF);
				i++;
			}
			fread(&a,sizeof(cliente),1,b);	
		}
		
	}
	fclose(b);
}

void TabelaV(void)
{
	venda a;
	FILE *b = fopen("Vendas.dat","rb");
	int i=7,c;
	
	Moldurar(1,1,72,3,7);
	gotoxy(32,2);
	printf("VENDAS");
	
	
	if(b==NULL)
	{
		Moldurar(1,4,120,9,7);
		gotoxy(45,7);
		printf("ERRO DE ABERTURA");
	}
	else
	{
		Moldurar(1,4,20,6,7);
		gotoxy(3,5);
		printf("RENAVAM");
		
		Moldurar(21,4,39,6,7);
		gotoxy(23,5);
		printf("DATA DE VENDA");
		
		Moldurar(40,4,55,6,7);
		gotoxy(42,5);
		printf("VALOR");
		
		Moldurar(56,4,72,6,7);
		gotoxy(58,5);
		printf("CPF");
		
		fread(&a,sizeof(venda),1,b);
		for(c=7;!feof(b);c++)
		{
			if(a.status=='A')
			{
				gotoxy(3,i);
				printf("%s",a.RENAVAM);
				gotoxy(23,i);
				printf("%s",a.DATA);
				gotoxy(42,i);
				printf("%.2f",a.valor);
				gotoxy(58,i);
				printf("%s",a.CPF);
				i++;
			}
			fread(&a,sizeof(venda),1,b);	
		}
		
	}
	fclose(b);
}

void TabelaVP(void)
{
	venda a;
	FILE *b = fopen("Vendas.dat","rb");
	int i=7,c;
	char data1[12], data2[12];
	
	Moldurar(1,1,72,3,7);
	gotoxy(3,2);
	printf("PRIMEIRA DATA: ");
	fflush(stdin);
	gets(data1);
	while(strcmp(data1,"\0")==0 || ValidarData(data1)!=0)
	{
		Apagar(18,31,2,(char*)"DATA INVALIDO",1000);
		gotoxy(18,2);
		fflush(stdin);
		gets(data1);
	}
	
	gotoxy(31,2);
	printf("SEGUNDA DATA: ");
	fflush(stdin);
	gets(data2);
	while(strcmp(data2,"\0")==0 || ValidarData(data2)!=0)
	{
		Apagar(48,72,2,(char*)"DATA INVALIDO",1000);
		gotoxy(48,2);
		fflush(stdin);
		gets(data2);
	}
	
	
	if(b==NULL)
	{
		Moldurar(1,4,120,9,7);
		gotoxy(45,7);
		printf("ERRO DE ABERTURA");
	}
	else
	{
		Moldurar(1,4,20,6,7);
		gotoxy(3,5);
		printf("RENAVAM");
		
		Moldurar(21,4,39,6,7);
		gotoxy(23,5);
		printf("DATA DE VENDA");
		
		Moldurar(40,4,55,6,7);
		gotoxy(42,5);
		printf("VALOR");
		
		Moldurar(56,4,72,6,7);
		gotoxy(58,5);
		printf("CPF");
		
		fread(&a,sizeof(venda),1,b);
		for(c=7;!feof(b);c++)
		{
			if(a.status=='A'  && cmpdata(a.DATA,data1,data2)==1)
			{
				gotoxy(3,i);
				printf("%s",a.RENAVAM);
				gotoxy(23,i);
				printf("%s",a.DATA);
				gotoxy(42,i);
				printf("%.2f",a.valor);
				gotoxy(58,i);
				printf("%s",a.CPF);
				i++;
			}
			fread(&a,sizeof(venda),1,b);	
		}
		
	}
	fclose(b);
}

/*void Ord(void)
{
	automovel a,a2;
	FILE *b2 = fopen("automovel.dat","wb");
	FILE *b = fopen("Automovel.dat","rb");
	
	rewind(b);
	fread(&a,sizeof(automovel),1,b);
	fwrite(&a,sizeof(automovel),1,b2)
	while(!feof(b))
	{
		
	}
	
}

void RelatorioA2(void)
{
	automovel a;
	automovel a2;
	FILE *b = fopen("Automovel.dat","rb");
	int i=8,c,k;
	char modelo[45];
	
	rewind(b);
		
	Moldurar(2,5,24,7,7);
	gotoxy(10,6);
	printf("MARCA");
	
	Moldurar(25,5,72,7,7);
	gotoxy(40,6);
	printf("MODELO");
	
	Moldurar(73,5,110,7,7);
	gotoxy(90,6);
	printf("COR");
	
	Moldurar(111,5,125,7,7);
	gotoxy(115,6);
	printf("DATA");
	
	Moldurar(126,5,148,7,7);
	gotoxy(134,6);
	printf("COMBUSTIVEL");
	
	Moldurar(149,5,159,7,7);
	gotoxy(151,6);
	printf("PLACA");
	
	Moldurar(160,5,174,7,7);
	gotoxy(163,6);
	printf("RENAVAM");
	
	Moldurar(175,5,181,7,7);
	gotoxy(177,6);
	printf("ANO");
	
	Moldurar(182,5,188,7,7);
	gotoxy(183,6);
	printf("HP");
	
	Moldurar(189,5,198,7,7);
	gotoxy(191,6);
	printf("KM");
	
	Moldurar(199,5,214,7,7);
	gotoxy(200,6);
	printf("PRECO R%c",36);
	
	
	fread(&a,sizeof(automovel),1,b);
	for(c=8;!feof(b);c++)
	{
		while(cmpdata(a.datacomp,a.datacomp,a2.datacomp)==1)
		{
			fseek()
		}
		if(a.status=='A'  )
		{
			gotoxy(4,i);
			printf("%s",a.marca);
			gotoxy(27,i);
			printf("%s",a.modelo);
			gotoxy(74,i);
			printf("%s",a.cor);
			gotoxy(112,i);
			printf("%s",a.datacomp);
			gotoxy(127,i);
			printf("%s",a.combustivel);
			gotoxy(150,i);
			printf("%s",a.placa);
			gotoxy(161,i);
			printf("%s",a.RENAVAM);
			gotoxy(176,i);
			printf("%d",a.ano_fabri);
			gotoxy(183,i);
			printf("%d",a.cavalos);
			gotoxy(190,i);
			printf("%d",a.km);
			gotoxy(200,i);
			printf("%.2f",a.valor);
			i++;
		}
		fread(&a,sizeof(automovel),1,b);		
	}
	fclose(b);
}*/

void RelatorioA1(void)
{
	automovel a;
	automovel a2;
	FILE *b = fopen("Automovel.dat","rb");
	int i=8,c,k;
	float M,m;
	char modelo[45];
	
	rewind(b);
		
	Moldurar(2,1,214,3,7);
	gotoxy(72,2);
	printf("RELATORIO DE AUTOMOVEIS POR FAIXA DE VALOR - MAXIMO: ");
	scanf("%f",&M);
	while(M<0)
	{
		gotoxy(100,2);
		scanf("%f",&M);
	}	
	gotoxy(145,2);
	printf("MINIMO:");
	scanf("%f",&m);
	while(m<0)
	{
		gotoxy(160,2);
		scanf("%f",&m);
	}	
		
	Moldurar(2,5,24,7,7);
	gotoxy(10,6);
	printf("MARCA");
	
	Moldurar(25,5,72,7,7);
	gotoxy(40,6);
	printf("MODELO");
	
	Moldurar(73,5,110,7,7);
	gotoxy(90,6);
	printf("COR");
	
	Moldurar(111,5,125,7,7);
	gotoxy(115,6);
	printf("DATA");
	
	Moldurar(126,5,148,7,7);
	gotoxy(134,6);
	printf("COMBUSTIVEL");
	
	Moldurar(149,5,159,7,7);
	gotoxy(151,6);
	printf("PLACA");
	
	Moldurar(160,5,174,7,7);
	gotoxy(163,6);
	printf("RENAVAM");
	
	Moldurar(175,5,181,7,7);
	gotoxy(177,6);
	printf("ANO");
	
	Moldurar(182,5,188,7,7);
	gotoxy(183,6);
	printf("HP");
	
	Moldurar(189,5,198,7,7);
	gotoxy(191,6);
	printf("KM");
	
	Moldurar(199,5,214,7,7);
	gotoxy(200,6);
	printf("PRECO R%c",36);
	
	
	fread(&a,sizeof(automovel),1,b);
	for(c=8;!feof(b);c++)
	{
		if(a.status=='A' && a.valor <= M && a.valor >= m)
		{
			gotoxy(4,i);
			printf("%s",a.marca);
			gotoxy(27,i);
			printf("%s",a.modelo);
			gotoxy(74,i);
			printf("%s",a.cor);
			gotoxy(112,i);
			printf("%s",a.datacomp);
			gotoxy(127,i);
			printf("%s",a.combustivel);
			gotoxy(150,i);
			printf("%s",a.placa);
			gotoxy(161,i);
			printf("%s",a.RENAVAM);
			gotoxy(176,i);
			printf("%d",a.ano_fabri);
			gotoxy(183,i);
			printf("%d",a.cavalos);
			gotoxy(190,i);
			printf("%d",a.km);
			gotoxy(200,i);
			printf("%.2f",a.valor);
			i++;
		}
		fread(&a,sizeof(automovel),1,b);		
	}
	fclose(b);
}

void RelatorioC(void)
{
	cliente a;
	venda w;
	FILE *b = fopen("Cliente.dat","rb");
	FILE *d = fopen("Vendas.dat","rb");
	int i=7,c,pos;
	
	Moldurar(1,1,120,3,7);
	gotoxy(50,2);
	printf("CADASTRO CLIENTES");
	
	
	if(b==NULL)
	{
		Moldurar(1,4,120,9,7);
		gotoxy(45,7);
		printf("ERRO DE ABERTURA");
	}
	else
	{
		Moldurar(1,4,70,6,7);
		gotoxy(3,5);
		printf("NOME");
		
		Moldurar(71,4,89,6,7);
		gotoxy(73,5);
		printf("CPF");
		
		Moldurar(90,4,105,6,7);
		gotoxy(92,5);
		printf("RENAVAM");
		
		Moldurar(106,4,120,6,7);
		gotoxy(108,5);
		printf("PAGO");
		
		fread(&w,sizeof(venda),1,d);
		for(c=7;!feof(b);c++)
		{
			if(a.status=='A')
			{
				pos = BuscaCPF(b,w.CPF);
				fseek(b,pos,0);
				fwrite(&a,sizeof(cliente),1,b);
				gotoxy(3,i);
				printf("%s",a.nome);
				gotoxy(73,i);
				printf("%s",w.CPF);
				gotoxy(92,i);
				printf("%s",w.RENAVAM);
				gotoxy(108,i);
				printf("%.2f",w.CPF);
				i++;
			}
			fread(&a,sizeof(venda),1,b);	
		}
		
	}
	fclose(b);
	fclose(d);
}

void RelatorioV(void)
{
	automovel a;
	venda w;
	FILE *b = fopen("Automovel.dat","rb");
	FILE *d = fopen("Vendas.dat","rb");
	int i=7,c;
	
	rewind(b);
	rewind(d);
	
	Moldurar(1,1,140,3,7);
	gotoxy(50,2);
	printf("RELATORIO DE AUTOMOVEIS");
	
	
	if(b==NULL)
	{
		Moldurar(1,4,120,9,7);
		gotoxy(45,7);
		printf("ERRO DE ABERTURA");
	}
	else
	{
		Moldurar(1,4,30,6,7);
		gotoxy(13,5);
		printf("MARCA");
		Moldurar(31,4,100,6,7);
		gotoxy(62,5);
		printf("MODELO");
		Moldurar(101,4,120,6,7);
		gotoxy(108,5);
		printf("VALOR");
		fread(&a,sizeof(automovel),1,b);
		for(c=7;!feof(b);c++)
		{
			if(a.status=='V')
			{
				gotoxy(5,i);
				printf("%s",a.marca);
				gotoxy(35,i);
				printf("%s",a.modelo);
				gotoxy(105,i);
				printf("%.2f",a.valor);
				i++;
			}
			fread(&a,sizeof(automovel),1,b);	
		}
		i=7;
		Moldurar(121,4,140,6,7);
		gotoxy(123,5);
		printf("VALOR");
		fread(&w,sizeof(venda),1,d);
		gotoxy(123,i);
		printf("%.2f",&w.valor);
		while(!feof(d))
		{
			i++;
			fread(&w,sizeof(venda),1,d);
			gotoxy(123,i);
			printf("%.2f",&w.valor);
		}
	}
	fclose(b);
	fclose(d);
}



void ExcluirC(void)
{
	cliente a;
	FILE *b = fopen("Cliente.dat","rb+");
	char cpf[16];
	int pos;
		
	Moldurar(100,1,130,3,7);
	gotoxy(102,2);
	printf("QUAL O CPF: ");
	fflush(stdin);
	gets(cpf);
	pos = BuscaCPF(b,cpf);
	while(strcmp(cpf,"\0")==0 || pos<0)
	{
		Apagar(114,130,2,(char*)"CPF INVALIDO",1000);
		gotoxy(114,2);
		fflush(stdin);
		gets(cpf);
		pos = BuscaCPF(b,cpf);
	}
	fseek(b,pos,0);
	fread(&a,sizeof(cliente),1,b);
	
	a.status = 'I';
	
	fseek(b,pos,0);
	fwrite(&a,sizeof(cliente),1,b);
	fclose(b);
}

void ExcluirA(void)
{
	automovel a;
	FILE *b = fopen("Automovel.dat","rb+");
	int op2, pos;
	char placa[8],renava[12];
	int comp,l=0,op,k=0,z=0;
	char r[11],aux[6][20] = {"Gasolina","Etano","Flex","Disel","GNV","Eletricidade"},aux2[8],ex[]="MARCA INVALIDA";
	
	
	Moldurar(165,1,200,3,7);
	gotoxy(177,2);
	printf("QUAL O TIPO?");
	
	Moldurar(165,4,200,11,7);
	
	Moldurar(166,5,199,7,7);
	gotoxy(170,6);
	printf("[1] = PLACA");
	
	Moldurar(166,8,199,10,7);
	gotoxy(170,9);
	printf("[2] = RENAVAM");
	
	Moldurar(165,12,200,14,7);
	gotoxy(170,13);
	printf("OPCAO: ");
	op2 = getche();
	while(op2!=49 && op2!=50)
	{
		Apagar(177,195,13,(char*)"INEXISTENTE",1000);
		gotoxy(177,13);
		op2 = getche();	
	} 
	Moldurar(165,15,200,17,7);
	gotoxy(170,16);
	switch(op2)
	{
		case '1':
			printf("PLACA: ");
			fflush(stdin);
			gets(placa);
			strupr(placa);
			pos = BuscaPlaca(b,placa);
			while(strcmp(placa,"\0")==0 || pos<0)
			{
				Apagar(177,192,16,(char*)"PLACA INVALIDA",1000);
				gotoxy(177,16);
				fflush(stdin);
				gets(placa);
				strupr(placa);
				pos = BuscaPlaca(b,placa);
			}
			fseek(b,pos,0);
			break;
		case '2':
			printf("RENAVAM: ");
			fflush(stdin);
			gets(r);
			pos = BuscaRENAVAM(b,r);
			while(strcmp(r,"\0")==0 || pos<0)
			{
				Apagar(179,198,16,(char*)"RENAVAM INVALIDA",1000);
				gotoxy(179,16);
				fflush(stdin);
				gets(r);
				pos = BuscaRENAVAM(b,r);
			}
			fseek(b,pos,0);
			break;
	}
	Moldurar(165,18,200,20,7);
	gotoxy(170,19);
	printf("ENCONTRADO");
	Sleep(1000);
	system("cls");
	
	fseek(b,pos,0);
	fread(&a,sizeof(automovel),1,b);
	
	a.status = 'I';
	
	fseek(b,pos,0);
	fwrite(&a,sizeof(automovel),1,b);
	fclose(b);
}

void ExcluirV(void)
{
	venda a;
	FILE *c = fopen("Automovel.dat","rb+");
	FILE *d = fopen("Cliente.dat","rb+");
	FILE *b = fopen("Vendas.dat","rb+");
	int op2,pos;
	char cpf[16],r[11];
	
	Moldurar(60,1,100,3,7);
	gotoxy(63,2);
	printf("QUAL O RENAVAM: ");
	fflush(stdin);
	gets(r);
	pos = BuscaRENAVAMV(b,r);
	while(strcmp(r,"\0")==0 || pos<0)
	{
		Apagar(79,99,2,(char*)"RENAVAM INVALIDA",1000);
		gotoxy(79,2);
		fflush(stdin);
		gets(r);
		pos = BuscaRENAVAMV(b,r);
	}
	Moldurar(60,4,100,6,7);
	gotoxy(63,5);
	printf("ENCONTRADO");
	Sleep(1000);
	
	system("cls");
	
	fseek(b,pos,0);
	fread(&a,sizeof(venda),1,b);
	
	a.status = 'I';
	
	fseek(b,pos,0);
	fwrite(&a,sizeof(venda),1,b);
	fclose(b);
	fclose(c);
	fclose(d);
}

int main()
{
	char op,op2,op3;
	getch();//retirar
	do
	{
		MenuPrincipal();
		op=getch();
		switch(op)
		{
			case '1':
				clrscr();
				do
				{
					MenuTipo();
					op2=getch();
					switch(op2)
					{
						case '1':
							clrscr();
							CadastroAutomovel();
							CadastroAutomovel2();
							break;	
						case '2':
							clrscr();
							CadastroClientes();
							CadastroClientes2();
							
							break;
						case '3':
							clrscr();
							CadastroVendas();
							CadastroVendas2();
							break;
					}
					system("cls");
				}while (op2!=27);
				
				break;
			case '2':
				clrscr();
				do
				{
					MenuTipo();
					op2=getch();
					switch(op2)
					{
						case '1':
							clrscr();
							TabelaDeAmostra();
							AlterarAutomovel();
							getch();
							break;	
						case '2':
							clrscr();
							TabelaDeAmostraC();
							AlterarCliente();
							getch();
							break;
						case '3':
							clrscr();
							TabelaDeAmostraV();
							AlterarVendas();
							getch();
							break;
					}
					system("cls");
				}while (op2!=27);
				break;
			case '3':
				clrscr();
				do
				{
					MenuTipo();
					op2=getch();
					switch(op2)
					{
						case '1':
							clrscr();
							do
							{
								MenuPesquisa();
								op3=getch();
								switch(op3)
								{
									case '1':
										clrscr();
										TabelaAP();
										getch();
										break;
									case '2':
										clrscr();
										TabelaA();
										getch();
										break;
								}
								system("cls");
							}while(op3!=27);
							break;	
						case '2':
							clrscr();
							do
							{
								MenuPesquisa();
								op3=getch();
								switch(op3)
								{
									case '1':
										clrscr();
										TabelaCP();
										getch();
										break;
									case '2':
										clrscr();
										TabelaC();
										getch();
										break;
								}
								system("cls");
							}while(op3!=27);
							break;
						case '3':
							clrscr();
							do
							{
								MenuPesquisa();
								op3=getch();
								switch(op3)
								{
									case '1':
										clrscr();
										TabelaVP();
										getch();
										break;
									case '2':
										clrscr();
										TabelaV();
										getch();
										break;
								}
								system("cls");
							}while(op3!=27);
							break;
					}
					system("cls");
				}while (op2!=27);
				break;
			case '4':
				clrscr();
				do
				{
					MenuTipo();
					op2=getch();
					switch(op2)
					{
						case '1':
							clrscr();
							TabelaDeAmostra();
							ExcluirA();
							break;	
						case '2':
							clrscr();
							TabelaDeAmostraC();
							ExcluirC();
							break;
						case '3':
							clrscr();
							TabelaDeAmostraV();
							ExcluirV();
							break;
					}
					system("cls");
				}while (op2!=27);
				break;
			case '5':
				clrscr();
				clrscr();
				do
				{
					MenuTipo();
					op2=getch();
					switch(op2)
					{
						case '1':
							clrscr();
							do
							{
								MenuRelatorio();
								op3=getch();
								switch(op3)
								{
									case '1':
										clrscr();
										RelatorioA1();
										getch();
										break;
									case '2':
										clrscr();
										//RelatorioA2();
										getch();
										break;
								}
								system("cls");
							}while(op3!=27);
							
							break;	
						case '2':
							clrscr();
							RelatorioC();
							getch();
							break;
						case '3':
							clrscr();
							RelatorioV();
							getch();
							break;
					}
					system("cls");
				}while (op2!=27);
				break;
		}
		system("cls");	
	}while (op!=27);

	return 0;
}
