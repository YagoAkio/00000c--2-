#include <stdio.h>
#include <string.h>
#include <conio2.h>
#include <ctype.h>

int main()
{

    char Tipo[][20] = {"Inseto", "Sombrio", "Dragao", "Eletrico", "Fada", "Lutador", "Fogo", "Voador", "Fantasma", "Planta", "Terrestre", "Gelo", "Normal", "Venenoso", "Psiquico", "Pedra", "Aco", "Agua"};
    char aux[20];
	int quantidade[] = {37,30,29,20,21,24,30,70,27,40,41,14,29,37,36,34,30,49},i;
    printf("### Descubra a quantidade de pokemons de um tipo ###\n");
    printf("### Digite o tipo do pokemon que deseja saber a quantia ###\n");
    gets(aux);
    i=0;
    while(strcmp(aux,Tipo[i])!=0 && i<17)
    {
    	i++;	
	}
    while(strcmp(aux,"\0")!=0)
    {	
    	if(i!=17)
    	{
    		printf("Existem %d pokemons do tipo %s",quantidade[i],aux);
    		getch();
		}
		clrscr();
    	printf("### Descubra a quantidade de pokemons de um tipo ###\n");
	    printf("### Digite o tipo do pokemon que deseja saber a quantia ###\n");
	    gets(aux);
	    i=0;
	    while(strcmp(aux,Tipo[i])!=0 && i<17)
	    i++;
	    
	    
	}
    
    
    return 0;
}
