#include <conio2.h>
#include <stdio.h>
#include <windows.h>

int maiorF(int vetor[], int maior, int aux) {
    if (aux > -1) {
        printf("%d\n", vetor[aux]);
        if (maior < vetor[aux])
            maior = vetor[aux];
        maiorF(vetor, maior, aux - 1);
    } else {
        return maior; 
    }
}

void exibe(int vetor[],int tam){
	if(tam>=0){
		printf("%d\n",vetor[tam]);
	}
	exibe(vetor,tam-1);
}


int main (void){
	int l=100;
	int vetor[100];
    for (int i = 100; i > 0; i--) {
        vetor[100 - i] = i;
    }
    
    int i=0;
    exibe(vetor,l);
    //maiorF(vetor,i,l);
//	printf("Maior: %d\n",i);
	return 0;
}
