struct stringdin{
	char letra;
	struct stringdin *prox;
};

typedef struct stringdin StrDin;

void reinicia(StrDin **str){
	StrDin  *aux;
	while (*str!=NULL){
		aux=*str;
		*str = (*str)->prox;
		free(aux);
	}
}

void reinciaR (StrDin **str){
	if(*str != NULL))
		reiniciaR(*str = (*str)->prox);
	free(*str);
}

/*
int main(){
	StrDin *s1;
	reinicia(&s1);
}
*/
