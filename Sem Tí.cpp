#include<stdio.h>
#include<conio2.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

struct TpPont{
	int Id;
	TpPont *prox;
};

struct TpDisc{
	TpPont *inicio,*fim;
	int qtd;
};

void Inicializar (TpDisc &Disc){
	Disc.inicio = Disc.fim = NULL;
	Disc.qtd=0;
}

TpPont *NovaCaixa(int v){
	TpPont *NC= new TpPont;
	NC->Id=v;
	NC->prox=NULL;
	return NC;
}

void InsOrd (TpDisc &Desc){
	int valor;
	TpPont *caixa,*atual,*ant;
	printf("\n **INSERCAO ORDENADA** \n");
	printf("Valor: ");
	scanf("%d",&valor);
	while(valor >0){
		caixa = NovaCaixa(valor);
		Desc.qtd ++;
		if(Desc.inicio==NULL)
			Desc.inicio=Desc.fim=caixa;
		else{
			if(valor<=Desc.inicio->Id){
				caixa->prox=Desc.inicio;
				Desc.inicio=caixa;
			}
			else{
				if(valor>Desc.fim->Id){
					Desc.fim->prox = caixa;
					Desc.fim= caixa;
				}
				else{
					ant ->prox;
					atual = Desc.inicio->prox;
					while(valor>atual->Id){
						ant=atual;
						atual = atual->prox;
					}
					caixa->prox=atual;
					ant->prox=caixa;	
				}
			}
			
		}
		printf("\nValor: ");
		scanf("%d",&valor);
	}
}

int main(){
	
}
