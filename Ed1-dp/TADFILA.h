#define MAXFILA 10

struct TpFila{
	int fim;
	char FILA[MAXFILA];
};

void Inicializar(TpFila &F){
	F.fim=-1;
}

char FilaCheia (int fim){
	return fim==MAXFILA-1;
}

char FilaVazia(int fim){
	return fim==1;
}

void Inserir(TpFila &F,char Elem ){
	TpElemento aux;
	F.FILA[++F.fim]=Elem;
	for(i=F.fim;i>=0;i--){
		if(F.FILA[i].prio<F.FILA[i-1].prio){
			aux=F.FILA[i];
			F.FILA[i]=F.FILA[i-1];
			F.FILA[i-1]=aux;
		}
			
	}
}

char Retirar(TpFila &F){
	char Elem = F.FILA[0];
	int i;
	for(i=0;i<F.fim;i++){
		F.FILA[i]=F.FILA[i+1];
	}
	F.fim--;
	return Elem;
}

char ElementoInicio(TpFila &F){
	return F.FILA[0];
}

char ElementoFim(TpFila &F){
	return F.FILA[F.fim];
}

void Exibir(TpFila F){
	while(!FilaVazia(F.fim))
		printf("%c\t",Retirar(F));
	printf("\n");
}
