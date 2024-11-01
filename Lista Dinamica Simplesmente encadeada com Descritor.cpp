/*
			Lista Dinâmica Simplesmente Encadeada com Descritor
Possibilita, no mínimo, acesso direto às extremidades da Lista.
Mas é possível armazenar detalhes da Lista.
*/
#include<stdio.h>
#include<windows.h>
#include<conio2.h>
#include<ctype.h>
struct TpPont{
	int Id;
	TpPont *Prox;
};

struct TpDesc{
	TpPont *Inicio, *Fim;
	int Qtde;
};

void Inicializar(TpDesc &Desc){
	Desc.Inicio = Desc.Fim = NULL;
	Desc.Qtde= 0;
}

TpPont *NovaCaixa(int v){
	TpPont *NC= new TpPont;
	NC->Id = v;
	NC->Prox = NULL;
	return NC;
}

void InsOrd(TpDesc &Desc){
	TpPont *Atual, *Ant, *Caixa;
	int valor;
	system("cls");
	printf("* * INSERCAO ORDENADA * *\n");
	printf("Valor: ");
	scanf("%d", &valor);
	while(valor > 0){
		Caixa = NovaCaixa(valor);
		Desc.Qtde++;
		if(Desc.Inicio == NULL){
			Desc.Inicio = Desc.Fim = Caixa;
			printf("Primeiro a ser inserido\n\n");
		}	
		else{
			if(valor <= Desc.Inicio->Id){
				Caixa -> Prox = Desc.Inicio;
				Desc.Inicio = Caixa;
				printf("Inicio\n\n");
			}
			else{
				if(valor > Desc.Fim->Id){
					Desc.Fim->Prox = Caixa;
					Desc.Fim = Caixa;
					printf("Fim\n\n");
				}
				else{
					Ant= Desc.Inicio;
					Atual= Desc.Inicio->Prox;
					while(valor > Atual->Id){
						Ant= Atual;
						Atual= Atual->Prox;
					}
					Caixa->Prox = Atual;
					Ant->Prox = Caixa;
					printf("Meio\n\n");
				}
			}
		}
		printf("Valor: ");
		scanf("%d", &valor);
	}
}

void Exibir(TpDesc D){
	system("cls");
	printf("* * Conteudo da Lista * *\n");
	TpPont *Ex = D.Inicio;	
	while(Ex -> Prox != NULL){
		printf("%d %u\n", Ex-> Id, Ex->Prox);
		//printf("L aponta para: %u", &L);
		Ex= Ex->Prox;
	}
	printf("%d %u\n", Ex-> Id, Ex->Prox);
	getch();
}

void Exclusao(TpDesc &D){
	int v;
	TpPont *Atual, *Ant;
	system("cls");
	printf("* * EXCLUSAO * *\n\n");
	printf("Valor a ser excluido: ");
	scanf("%d", &v);
	
	//Excluir primeira pos
	if(v == D.Inicio->Id){
		Atual=D.Inicio;
		D.Inicio= D.Inicio->Prox;
		delete Atual;
	}
	else{
		//Excluir ultima pos
		if(v == D.Fim->Id){
			Atual = D.Inicio;
			while(Atual->Prox != D.Fim){
				Atual= Atual->Prox;
			}
			D.Fim= Atual;
			Atual = Atual->Prox;
			D.Fim->Prox = NULL;
			delete Atual;
		}
		else{
			//Excluir Meio
			Ant= D.Inicio;
			Atual= Ant->Prox;
			while(v != Atual->Id && Atual->Prox != NULL){
				Ant= Atual;
				Atual= Atual->Prox;
			}
			if(v == Atual->Id){
				
			}
		}
	}
	/*
	while(v != Atual->Id && Atual->Prox != NULL){
		Atual= Atual->Prox;
	}
	*/
}

int main(void){
	TpDesc D;
	Inicializar(D);
	InsOrd(D);
	Exibir(D);
	Exclusao(D);
	Exibir(D);
}
