#include<stdio.h>
#include<conio2.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
 
void gravar()

int main(){
	char c;
	FILE *ptr = fopen("TextoAula.txt","a");
	printf("Digite um texto:\n");
	c = getche();
	
	while(c!=27){
		if(c == 13)
		{
			printf("\n");
			fputc('\n',ptr);
		}
		else
			fputc(c,ptr);	
		c = getche();
	}
	fputc('\n',ptr);
	
	fclose(	ptr);
	return 0;
}
