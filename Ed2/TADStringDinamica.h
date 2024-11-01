struct stringdin{
	char letra;
	struct stringdin *prox;
};

typedef struct stringdin StrDin;

void reinicia(StrDin**str){
	StrDin  *aux;
	while(*str!= NULL){
		aux=*str;
		*str = (*str)->prox;
		free(aux);
	}
}

void reiniciaR (StrDin **str){
	if(*str != NULL)){
		reiniciaR(&((*str)->prox));
		free(*str);
		
	}
}

//void reiniciaR2 (StrDin **str){
//	if(*str != NULL))
//		free(reiniciaR2(&((*str)->prox)));
//}
