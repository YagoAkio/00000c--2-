struct TpCidade{
	char Nome[50];
	int Populcao;
};

char validar(void){
	
}

void cadastrar(void){
	
}

void consultar(void){
	
}

void ordenar_ciadade(void){
	
}

void exibir(void){
	
}

void ordenar_desc_populacao(void){
	
}

void menu(void){
	Moldurar(95,15,145,33,7);
	Moldurar(98,17,142,19,7);
	gotoxy(118,18);
	printf("MENU\n");
	gotoxy(97,20);
	printf("-----------------------------------------------");
	Moldurar(98,21,138,23,7);
	gotoxy(104,22);
	printf("[A] = VALIDAR");
	Moldurar(98,24,138,26,7);
	gotoxy(104,25);
	printf("[B] = CADASTRAR");
	Moldurar(98,27,138,29,7);
	gotoxy(104,28);
	printf("[C] = CONSULTAR");
	Moldurar(98,30,138,32,7);
	gotoxy(104,31);
	printf("[D] = ORDENAR POR CIDADE");
	Moldurar(98,33,138,35,7);
	gotoxy(104,31);
	printf("[E] = EXIBIR");
	Moldurar(98,36,138,38,7);
	gotoxy(104,31);
	printf("[D] = ORDENAR POR POPULACAO");
	Moldurar(98,39,138,42,7);
	gotoxy(104,31);
	printf("[ESC] = SAIR");
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
