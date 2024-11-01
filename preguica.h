
struct OPCOES{
	char opcao[100];
	OPCOES *prox;
};

OPCOES *Inserir(OPCOES *L){//copia, ou seja não atualiza
	char op[100];
	FILE *ptr = fopen("Opcoes.txt","r");
	OPCOES *pCaixa;//aponta para algo inexistente
	fscanf(ptr,"%[^;];\n",op);
	while(!feof(ptr)){
		pCaixa = new OPCOES;// apartir daqui ele começa apontar para algo existente
		strcpy(pCaixa->opcao,op);
		pCaixa ->prox=NULL;
		if(L==NULL)//descartavel pois se insere no inicio
			L = pCaixa;
		else{
			pCaixa -> prox=L;
			L = pCaixa;
		}
		fscanf(ptr,"%[^;];\n",op);	
	}
	fclose(ptr);
	return L;
}

void Moldurar(int CI,int LI,int CF,int LF,int Cor)
{
	int i;
	textcolor(Cor);
	gotoxy(CI,LI);
	printf("%c", 201);
	gotoxy(CF,LI);
	printf("%c",187);
	gotoxy(CI,LF);
	printf("%c",200);
	gotoxy(CF,LF);
	printf("%c",188);
	
	for(i=CI+1;i<CF;i++)
	{
		gotoxy(i,LI);
		printf("%c",205);
		gotoxy(i,LF);
		printf("%c",205);
	}
	for(i=LI+1;i<LF;i++)
	{
		gotoxy(CI,i);
		printf("%c",186);
		gotoxy(CF,i);
		printf("%c",186);
	}
	
}



void MenuPrincipal(int op,int larg,OPCOES O)
{	
	int i;
	Moldurar(104-larg,1,104+larg,op*3+8,7);
	Moldurar(107-larg,2,101+larg,4,7);
	gotoxy(118,3);
	printf("MENU\n");
	gotoxy(107-larg,6);
	printf("-----------------------------------------------");
	for(i=0;i<op;i++)
	{
		gotoxy(107,8+(i+1));
		printf("%s",O.Fila[i]);
	}
}

void OpcaoMenu(void){
	OPCOES O;
	char op;
	int x=7,y=O.Mtmn+8;
	do{
		op=getch();
		clrscr();
		
		if(op==72){
			x-=2;
			if(x<7){
				x=(O.Fim*2)+7;
			}
			Moldurar(105-O.Mtmn/2,x-2,105+O.Mtmn/2,x,7);
			
		}
		if(op==80){
			x+=2;
			if(x>(O.Fim*2)+7){
				x=7;
			}
			Moldurar(05-O.Mtmn/2,x,05+O.Mtmn/2,x+2,7);
			
		}
		MenuPrincipal(O.Fim,O.Mtmn/2,O);
	}while(op!=13);
}
