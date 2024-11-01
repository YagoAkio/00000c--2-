struct pilha{
	int info;
	struct pilha *prox;
};

typedef struct pilha Pilha;

void init(Pilha **P){
	*P=NULL;
}

int top(Pilha *P){
	if (!isEmpty(P))
		return P->info;
	return -1;
}

char isEmpty(){
	return P==NULL;	
}

void push(Pilha **P,int x){
	Pilha *nova;//lixo
	nova=(Pilha*)malloc(sizeof(Pilha));//aloca uma nova caixa(8bytes tamanho da struct) a variavel 
	nova -> info = x;//ira sair do lixo e alocar o valor de x
	nova -> prox = *P;//recebe o endereço de P
	*P=nova;// atualiza o ponteiro
}

void pop(Pilha **P,int *x){
	Pilha *aux;
	if(!isEmpty(*P)){
		aux=*P;
		*x=(*P)->info;
		*P=(*P)-.prox;
		free(aux);
	}
	else
		*x=-1;
}
