#define MAXPILHA 10

struct TpPilha{
	int Topo;
	int Pilha[MAXPILHA];
};

void Inicializar(TpPilha &P);
char Cheia(int topo);
void Push(TpPilha &P,int Elemento);
char Vazia(int topo);
int POP(TpPilha &P);
int ElementoTopo(TpPilha P);
void Exibir(TpPilha P);

void Inicializar(TpPilha &P){
	P.Topo=-1;
}

char cheia(int topo){
	return topo==MAXPILHA-1;
}

void PUSH(TpPilha &P,int Elemento){
	P.Pilha[++P.Topo]=Elemento;
}

char Vazia(int topo){
	return topo == -1;
}

int POP(TpPilha &P){
	return P.Pilha[P.Topo--];
}

int ElementoTopo(TpPilha P){
	return P.Pilha[P.Topo];
}

void Exibir(TpPilha P){
	while(!Vazia(P.Topo))
		printf("\n%c",POP(P));
}
