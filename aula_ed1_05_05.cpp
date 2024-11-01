#include<stdio.h>
#include<conio2.h>
#include<stdlib.h>

struct TpPont{
	char elem;
	TpPont *prox;
};

TpPont *Inserir(TpPont *L){//copia, ou seja não atualiza
	char Elemento;
	TpPont *pCaixa;//aponta para algo inexistente
	clrscr();
	printf("\n **Inserir na Lista**\n");
	printf("Elemento: ");
	Elemento=getche();
	while(Elemento!=27){
		pCaixa = new TpPont;// apartir daqui ele começa apontar para algo existente
		pCaixa ->elem=Elemento;
		pCaixa ->prox=NULL;
		if(L==NULL)//descartavel pois se insere no inicio
			L = pCaixa;
		else{
			pCaixa -> prox=L;
			L = pCaixa;
		}
		printf("\nElemento: ");
		Elemento=getche();	
	}
	return L;
}

void Exibir(TpPont *L){
	//clrscr();
	printf("\n **Conteudo da Lista**\n");
	if(L==NULL)
		printf("\nVazia\n");
	else{
		while(L->prox!=NULL){
			printf("%c\t %u\n",L->elem,L->prox);
			L=L->prox;
		}
		printf("%c\t %u\n",L->elem,L->prox);
	}
	
}

TpPont *Excluir(TpPont *L){
	char Info;
	TpPont *atual,*ant;
	printf("\n **Conteudo da Lista**\n");
	if(L==NULL)
		printf("\nLista Vazia!\n");
	else{
	printf("\n Elemento a Excluir: ");
	Info=getche();
		while(Info!=27 && L!=NULL){
			if(L->elem==Info){
				atual = L; //atual aponta para onde a lista está apontando
				L=L->prox;
				delete(atual);
				printf("\nElemento excluido\n");
			}
			else{
				ant =L;
				atual=L->prox;
				while(atual->prox!=NULL &&atual->elem!=Info){
					ant = atual;
					atual = atual->prox;
				}
				if(atual->elem==Info){
					ant->prox = atual->prox;
					delete(atual);
				}
				else
					printf("\nElemento nao encontrado!\n");
			}
			printf("\n\n Elemento a Excluir: ");
			Info=getche();
		}
		return L;
	}
}



int main(void){
	TpPont *lista=NULL;
	lista = Inserir(lista);
	printf("a");
	Exibir(lista);
	lista = Excluir(lista);
	Exibir(lista);
	return 0;
}

