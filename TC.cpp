#include <stdio.h>
#include <conio.h>
#include <conio2.h>
#include <windows.h>

void soma( int &a, int &b){
    while(a!=0){
        a--;
        b++;
    }
}

void soma2 (int &a,int &b, int &c){
    while(b!=0){
        a++;
        c++;
		b--;
    }
    while(c!=0){
        b++;
		c--;
    }
}

void multiplicacao(int &a,int &b, int &c, int &d, int &e){
	while(a!=0){
		c++;
		d++;
		a--;
	}
    while(c!=0){
		while(b!=0){
	    	a++;
	    	e++;
	    	b--;
	    }
    	while(a!=0){
    		b++;
    		a--;
    	}
    	c--;
    }
    while(d!=0){
    	a++;
    	d--;
    }
    
}

void multiplicacao2(int &a,int &b, int &c, int &d){
	while(a!=0){
		while(b!=0){
	    	c++;
	    	d++;
	    	b--;
	    }
    	while(c!=0){
    		b++;
    		c--;
    	}
    	a--;
    }
}


int main(){
    char op;
    int A = 0, B = 0, C = 0, D = 0, E = 0;
    gotoxy(50,7);
    printf("------------------");
    gotoxy(50,8);
    printf("*** Simulador ****\n");
    gotoxy(50,9);
	printf("------------------");
    gotoxy(50,11);
    printf(" Maquina de Norma\n");
    gotoxy(44,15);
    printf(" Pressione ENTER para comecar");
    gotoxy(46,16);
    printf(" (executar em modo janela)");
	if(getch()== 13){
		do{
			clrscr();
	    	gotoxy(50,7);
	    	printf("Escolha:");
	    	gotoxy(50,9);
		    printf("A) Adicao sem preservar\n");
		    gotoxy(50,10);
		    printf("B) Adicao preservando\n");
		    gotoxy(50,11);
		    printf("C) Multiplicacao (preservando A e B com 5 registradores)\n");
		    gotoxy(50,12);
		    printf("D) Multiplicacao (preservando B com 4 registradores)\n");
		    gotoxy(50, 13);
		    printf("E) Teste de primo");
		    gotoxy(50,15);
		    printf("Escolha uma!!!\n");

		    op = toupper(getch());
		    
		    if(op != 27){
		    	gotoxy(50,16);
		    	printf("Valor de A: ");
			    scanf("%d",&A);
			    gotoxy(50,17);
			    printf("valor de B: ");
			    scanf("%d",&B);
		    }else if(op == 'E'){
		    	
		    }
		    switch (op) {
		        case 'A':
		            soma(A,B);
		            gotoxy(50,19);
		            printf("Resultado da soma: %d\n",B);
		            gotoxy(50,20);
		            printf("Valor de A: %d\n", A);
		            gotoxy(50,21);
		            printf("Valor de B: %d\n", B);
		            break;
		        case 'B':
		            soma2(A,B,C);
		            gotoxy(50,19);
		            printf("Resultado da soma: %d\n", A);
		            gotoxy(50,20);
		            printf("Valor de A: %d\n", A);
		            gotoxy(50,21);
		            printf("Valor de B: %d\n", B);
		            gotoxy(50,22);
		            printf("Valor de C: %d\n", C);
		            break;
		        case 'C':
		            multiplicacao(A,B,C,D,E);
		            gotoxy(50,19);
		            printf("Resultado da mutiplicacao: %d\n",E);
		            gotoxy(50,20);
		            printf("Valor de A: %d\n", A);
		            gotoxy(50,21);
		            printf("Valor de B: %d\n", B);
		            gotoxy(50,22);
		            printf("Valor de C: %d\n", C);
		            gotoxy(50,23);
		            printf("Valor de D: %d\n", D);
		            gotoxy(50,24);
		            printf("Valor de E: %d\n", E);
		            break;
		        case 'D':
		        	multiplicacao2(A,B,C,D);
		        	gotoxy(50,19);
		            printf("Resultado da mutiplicacao: %d\n",D);
		            gotoxy(50,20);
		            printf("Valor de A: %d\n", A);
		            gotoxy(50,21);
		            printf("Valor de B: %d\n", B);
		            gotoxy(50,22);
		            printf("Valor de C: %d\n", C);
		            gotoxy(50,23);
		            printf("Valor de D: %d\n", D);
		        case 'E':
		        	//primo();
		        	gotoxy(50,19);
		            printf("Resultado da mutiplicacao: %d\n",D);
					
		    }
		    if(op!=27)
		    	getch();
		}while(op!=27);
    }
    

    return 0;
}


