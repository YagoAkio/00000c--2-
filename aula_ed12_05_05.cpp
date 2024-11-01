#include<stdio.h>
#include<conio2.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

//dublo de encadeamento
struct TpPontD{
	int Info;
	TpPontD *ant,*prox;
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
	printf("[A] = INSERIR");
	Moldurar(98,24,138,26,7);
	gotoxy(104,25);
	printf("[B] = EXIBIR");
	Moldurar(98,27,138,29,7);
	gotoxy(104,28);
	printf("[C] = ELIMINE INFORMACAO");
	Moldurar(98,30,138,32,7);
	gotoxy(104,31);
	printf("[D] = LOCALIZAR");
	Moldurar(98,33,138,35,7);
	gotoxy(104,34);
	printf("[E] = RELATORIO");
	Moldurar(98,36,138,38,7);
	gotoxy(104,37);
	printf("[ESC] = SAIR/EXCLUIR");

}

//inserção ordenada
TpPontD *NovaCaixa(int valor){
	TpPontD *NC = new TpPontD;
	NC -> ant = NC -> prox = NULL;
	NC -> Info = valor;
	return NC;
}

TpPontD *InserirOrd(TpPontD *L){
	int num;
	TpPontD *Caixa,*atual;
	printf("\n *** Insercao Ordenada ***\n");
	printf("\n Valor: ");
	scanf("%d",&num);
	while(num>0){
		Caixa = NovaCaixa(num);
		if(L==NULL)
			L = Caixa;
		else{
			if(num<=L->Info){
				Caixa -> prox = L;
				L->ant=Caixa;
				L=Caixa;
			}else{
				atual = L;
				while(atual -> Info <= num && atual -> prox!= NULL){
					atual = atual->prox;
				}
				if(atual -> Info >= num){
					Caixa->prox=atual;
					Caixa->ant=atual->ant;
					atual=atual->ant;
					atual->prox=Caixa;
					atual= atual->prox->prox;
					atual->ant = Caixa;
				}else{
					Caixa ->ant = atual;
					atual -> prox = Caixa;
				}
			}
		}
		printf("\n Valor: ");
		scanf("%d",&num);
	}
	return L;
}

void Exibir(TpPontD *L){
	//clrscr();
	printf("\n **Conteudo da Lista**\n");
	if(L==NULL)
		printf("\nVazia\n");
	else{
		while(L->prox!=NULL){
			printf("%d\t %u\n",L->Info,L->prox);
			L=L->prox;
		}
		printf("%d\t %u\n",L->Info,L->prox);
	}	
}

TpPontD *Excluir(TpPontD *L){
	int elem;
	TpPontD *atual,*ante;
	printf("\n **EXCLUSAO**\n");
	if(L==NULL)
		printf("\nLista Vazia!\n");
	else{
		printf("\n Elemento a Excluir: ");
		scanf("%d",&elem);
		while(elem!=0 && L!=NULL){
			if(L->Info==elem){
				atual = L;
				L = L->prox;
				atual -> ant = L->ant;
				delete(atual);
				printf("\nElemento excluido\n");
			}
			else{
				ante = L;
				atual=L->prox;
				while(atual->prox!=NULL && atual->Info!=elem){
					ante = atual;
					atual = atual->prox;
				}
				if(atual->Info==elem){
					ante->prox = atual->prox;
					if(atual->prox!=NULL){
						ante= ante->prox->prox;
						ante->ant=atual->ant;
					}
					delete(atual);
				}
				else
					printf("\nElemento nao encontrado!\n");
			}
			printf("\n Elemento a Excluir: ");
			scanf("%d",&elem);
		}
		return L;
	}
}

void Localizar(TpPontD *L){
	int elem,i;
	TpPontD *atual;
	printf("\n **EXCLUSAO**\n");
	if(L==NULL)
		printf("\nLista Vazia!\n");
	else{
		printf("\n Elemento a Excluir: ");
		scanf("%d",&elem);
		while(elem!=0 && L!=NULL){
			atual = L;
			i=1;
			while(atual -> Info!= elem){
				atual = atual->prox;
				i++;
			}
			if(atual -> Info== elem){
				printf("\n O elmento ocupa: %d",i);
				printf("\n Seu endereco e: %u",atual);
			}
			else
				printf("\nElemento não encontrado\n");
			printf("\n Elemento a Excluir: ");
			scanf("%d",&elem);
		}
	}
}

int main(void){
	char op;
	TpPontD *lista = NULL;
	do{
		MenuPrincipal();
		op=toupper(getch());
		system("cls");
		switch(op){
			case 'A':
				lista = InserirOrd(lista);
				break;
			case 'B':
				Exibir(lista);
				getch();
				break;
			case 'C':
				lista = Excluir(lista);
				break;
			case 'D':
				Localizar(lista);
				break;
		}
		system("cls");
	}while(op!=27);
	return 0;
}
