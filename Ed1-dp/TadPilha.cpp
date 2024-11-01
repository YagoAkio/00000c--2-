#include<stdio.h>
#include<conio2.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include "TADPILHA.h"

char Menu(void){
	clrscr();
	printf("\n## Testando a PILHA de [int] ##\n");
	printf("\n[A] Inicializar a PILHA");
	printf("\n[B] Empilhar (PUSH)");
	printf("\n[C] Desempilhar (POP)");
	printf("\n[D] Mostrar Elemento do TOPO");
	printf("\n[E] Exibir a PILHA");
	printf("\n[ESC] SAIR\n");
	printf("Opcao desejada: ");
	return toupper(getche());
}

int main(){
	int Elem;
	TpPilha Pilha;
	char op;
	do{
		op = Menu();
		switch(op){
			case 'A':
				Inicializar(Pilha);
				printf("\nPilha Inicializada!\n");
				getch();
				break;
			case 'B':
				printf("\nInserir na Pilha: ");
				if(cheia(Pilha.Topo))
					printf("\nPilha Cheia!\n");
				else{
					printf("Elemento: ");
					scanf("%d",&Elem);
					PUSH(Pilha,Elem);
					printf("\nElemento inserido!\n");
				}
				break;
			case 'C':
				printf("\nRetirar da Pilha: ");
				if(Vazia(Pilha.Topo))
					printf("\nPilha Vazia!\n");
				else
					printf("\nElemento %d retirado!\n",POP(Pilha));
				break;
			case 'D':
				printf("\nElemento do Topo: ");
				if(Vazia(Pilha.Topo))
					printf("\nPilha Vazia!\n");
				else
					printf("%d\n",ElementoTopo(Pilha));
				break;
			case 'E':
				if(Vazia(Pilha.Topo))
					printf("\nPilha Vazia!\n");
				else
					Exibir(Pilha);
				getch();
				break;
		}
	}while(op!=27);
	return 0;
}
