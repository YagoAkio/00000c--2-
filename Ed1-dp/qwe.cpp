#include <stdio.h>
#include <time.h>
#include <conio2.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "TADFILA.h"

int main(void)
{
	TpFila FILA;
	srand(time(0));
	Inicializar(FILA);
	do{
		if(rand()%10>1){
			if(!FilaCheia(FILA.fim))
				Inserir(FILA,'1');
		}	
		else
			if(!FilaVazia(FILA.fim))
				Retirar(FILA);	
		if(!FilaVazia(FILA.fim))
			Exibir(FILA);
		Sleep(10000);
	}while(!kbhit());
	
	return 0;
}
