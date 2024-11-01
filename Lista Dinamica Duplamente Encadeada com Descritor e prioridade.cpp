#include<stdio.h>
#include<conio2.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

struct TpPontDP{
	int Id,Prio;
	TpPontDP *Prox,*Ant;
};

struct TpDesc{
	TpPontDP *Inicio, *Fim;
	int Qtde;
};

void Inicializar(TpDesc &Desc){
	Desc.Inicio = Desc.Fim = NULL;
	Desc.Qtde= 0;
}

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
	Moldurar(95,15,145,33,7);
	Moldurar(98,17,142,19,7);
	gotoxy(118,18);
	printf("MENU\n");
	gotoxy(97,20);
	printf("-----------------------------------------------");
	Moldurar(98,21,138,23,7);
	gotoxy(104,22);
	printf("[A] = INSERIR");
	Moldurar(98,24,138,26,7);
	gotoxy(104,25);
	printf("[B] = EXIBIR");
	Moldurar(98,27,138,29,7);
	gotoxy(104,28);
	printf("[C] = ELIMINE INFORMACAO");
	Moldurar(98,30,138,32,7);
	gotoxy(104,31);
	printf("[ESC] = SAIR/EXCLUIR");


}

void MenuExibicao(void){
	Moldurar(95,15,145,36,7);
	Moldurar(98,17,142,19,7);
	gotoxy(118,18);
	printf("MENU\n");
	gotoxy(97,20);
	printf("-----------------------------------------------");
	Moldurar(98,21,138,23,7);
	gotoxy(104,22);
	printf("[A] = EXIBIR");
	Moldurar(98,24,138,26,7);
	gotoxy(104,25);
	printf("[B] = EXIBIR RECURSIVAMENTE");
	Moldurar(98,27,138,29,7);
	gotoxy(104,28);
	printf("[C] = EXIBIR O PRIMEIRO");
	Moldurar(98,30,138,32,7);
	gotoxy(104,31);
	printf("[D] = EXIBIR O ULTIMO");
	Moldurar(98,33,138,35,7);
	gotoxy(104,34);
	printf("[ESC] = SAIR/EXCLUIR");

}


TpPontDP *NovaCaixa(int v, int p){
	TpPontDP *NC= new TpPontDP;
	NC->Id = v;
	NC->Prio = p;
	NC->Prox = NULL;
	NC->Ant=NULL;
	return NC;
}

void InsOrd(TpDesc &Desc){
	TpPontDP *Atual, *Ante, *Caixa;
	int valor,prioridade;
	system("cls");
	printf("* * INSERCAO ORDENADA * *\n");
	printf("\nValor: ");
	scanf("%d", &valor);
	while(valor > 0){
		printf("\nPrioridade: ");
		scanf("%d", &prioridade);
		Caixa = NovaCaixa(valor,prioridade);
		Desc.Qtde++;
		if(Desc.Inicio == NULL){
			Desc.Inicio = Desc.Fim = Caixa;
			printf("Primeiro a ser inserido\n\n");
		}	
		else{
			Caixa->Ant=Desc.Fim;
			Desc.Fim->Prox = Caixa;
			Desc.Fim = Caixa;
			printf("Fim\n\n");
			if(prioridade < Desc.Inicio->Prio){
				Atual=Desc.Fim;
				Desc.Fim=Atual->Ant;
				Desc.Fim->Prox =NULL;
				Atual->Prox=Desc.Inicio;
				Desc.Inicio->Ant=Atual;
				Desc.Inicio=Atual;
				Atual->Ant=NULL;
				printf("Inicio\n\n");	
			}
			else{
				if(prioridade < Desc.Fim->Ant->Prio){
					Ante= Desc.Fim;
					Atual= Desc.Fim->Ant;
					while(prioridade < Atual->Prio){
						Ante= Atual;
						Atual= Atual->Ant;
					}
					Atual->Prox=Desc.Fim;
					Ante->Ant=Desc.Fim;
					Desc.Fim->Prox=Ante;
					Desc.Fim=Desc.Fim->Ant;
					Desc.Fim->Prox =NULL;
					Ante=Ante->Ant;
					Ante->Ant=Atual;
					printf("Meio\n\n");
				}	
			} 
		}
		printf("\nValor: ");
		scanf("%d", &valor);
	}
}

void Exibir(TpDesc D){
	system("cls");
	printf("\n** Conteudo da Lista **\n");
	printf("\nQuantidade de informacao: %d\n",D.Qtde);
	if(D.Fim==NULL){
		printf("\nLista Vazia!!!\n");
	}
	else{
		TpPontDP *Ex = D.Inicio;	
		while(Ex -> Prox != NULL){
			printf("%u - valor: %d  prio: %d - %u\n",Ex->Ant, Ex-> Id, Ex->Prio, Ex->Prox);
			Ex= Ex->Prox;
		}
		printf("%u - valor: %d  prio: %d - %u\n",Ex->Ant, Ex-> Id, Ex->Prio, Ex->Prox);
	}
}

TpPontDP *ExibirRecusivamente(TpPontDP *D){
	printf("%u - valor: %d  prio: %d - %u\n",D->Ant, D-> Id, D->Prio, D->Prox);
	if(D->Prox==NULL)
		return NULL;
	return ExibirRecusivamente(D->Prox);	
}

void Retirar(TpDesc &Desc){
	TpPontDP *Atual;
	Atual=Desc.Inicio;
	if(Desc.Inicio->Prox==NULL){
		Desc.Fim=NULL;
		Desc.Inicio=NULL;
		delete Atual;
	}
	else{
		Desc.Inicio=Atual->Prox;
		Atual->Prox->Ant=NULL;
		delete Atual;	
	}
	
	Desc.Qtde--;
}

char vazia(TpDesc D){
	return D.Fim==NULL;	
}

int main(void){
	TpDesc D;
	Inicializar(D);
	char op,op2;
	do{
		MenuPrincipal();
		op=toupper(getch());
		system("cls");
		switch(op){
			case 'A':
				InsOrd(D);
				break;
			case 'B':
				system("cls");
				if(vazia(D)){
					printf("\nLista Vazia\n");
					getch();
				}
				else{
					do{
						MenuExibicao();
						op2=toupper(getch());
						switch(op2){
							case'A':
								system("cls");
								Exibir(D);
								getch();
								system("cls");
								break;
								
							case 'B':
								system("cls");
								ExibirRecusivamente(D.Inicio);
								getch();
								system("cls");
								break;
							case'C':
								system("cls");
								printf("\nPrimeiro elemento: %d\n",D.Inicio->Id);
								getch();
								system("cls");
								break;
								
							case 'D':
								system("cls");
								printf("\nUltimo elemento: %d\n",D.Fim->Id);
								getch();
								system("cls");
								break;
						}
					}while(op2!=27);
				}
				system("cls");	
				break;
			case 'C':
				if(vazia(D)){
					printf("\nLista Vazia\n");
					getch();
				}
				else{
					Retirar(D);
				}
				
				break;
		}
		system("cls");
	}while(op!=27);
	return 0;
}
