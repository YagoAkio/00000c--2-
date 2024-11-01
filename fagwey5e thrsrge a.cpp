#define MAXFILA 10

struct TpElemento{
	char id;
	int Prioridade;
};

struct TpFILAC
{
	int inicio, fim, qntde;
	TpElementoFC FILA[MAXFILA];
};

void inicializar(TpFILAC &FP)
{
	FP.inicio = -1;
	FP.fim = -1;
	FP.qntde = 0;
}

void inserir(TpFILAC &FP,TpElementoFC EFC)
{
	if(FP.fim == MAXFILA-1)
	{
		FP.fim = 0;
	}
	else
	{
		FP.fim ++;
	}
	FP.FILA[FP.fim] = EFC;
	if(FP.qntde!=MAXFILA)		
		FP.qntde ++;
	else{
		if(FP.fim == MAXFILA-1)
			FP.inicio=0;
		FP.inicio=FP.fim+1;
	}	
}

TpFilaC retirar(TpFILAC &FP)
{
    TpFilaC aux;
    if (FP.qntde == 0)
    {
        printf("Fila vazia!\n");
        return NULL; // ou algum outro valor que represente uma fila vazia
    }
    else
    {
        aux = FP.FILA[FP.inicio];
        if(FP.inicio==MAXFILA-1){
        	FP.inicio=0;
		}else{
			FP.inicio++;
		}
        FP.qntde --;
        return aux;
    }
}


char filacheia( int qntde)
{
	return qntde = MAXFILA;
}

int filaVazia(TpFILAC FP)
{
    if (FP.qntde == 0)
    {
        return 1; // fila vazia
    }
    else
    {
        return 0; // fila não vazia
    }
}


char inicioFila(TpFILAC FP)
{
    if (FP.qntde == 0)
    {
        printf("Fila vazia!\n");
        return NULL; // ou algum outro valor que represente uma fila vazia
    }
    else
    {
        return FP.FILA[FP.inicio];
    }
}

char finalFila(TpFILAC FP)
{
    if (FP.qntde == 0)
    {
        printf("Fila vazia!\n");
        return NULL; // ou algum outro valor que represente uma fila vazia
    }
    else
    {
        return FP.FILA[FP.fim];
    }
}

void exibirFila(TpFILAC FP)
{
    if (FP.qntde == 0)
    {
        printf("Fila vazia!\n");
    }
    else
    {
        int i;
        printf("Elementos da fila:\n");
        for (i = 0; i < FP.qntde; i++)
        {
            printf("%c ", FP.FILA[(FP.inicio + i) % MAXFILA]);
        }
        printf("\n");
    }
}









