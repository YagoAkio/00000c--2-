#include <stdio.h>
#include <conio2.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

struct tabela1
{
	int cod;
	char prod[20];
	float preco;
};

struct tabela2
{
	int cod;
	char prod[20];
	float preco;
};

struct tabela3
{
	int cod;
	char prod[20];
	float preco;
};

void juncao(void)
{
	tabela1 a;
	tabela2 b;
	FILE *ta = fopen("tabela1.dat","rb");
	FILE *tb = fopen("tabela2.dat","rb");
	FILE *tc = fopen("tabela3.dat","ab");
	
	rewind(ta);
	rewind(tb);
	
	if(tc==NULL)
	{
		
	}
	else
	{
		fread(&a,sizeof(a),1,ta);
		while(!feof(ta))
		{
			fwrite(&a,sizeof(a),1,tc);
			fread(&a,sizeof(a),1,ta);
		}
		
		fread(&b,sizeof(b),1,tb);
		while(!feof(tb))
		{
			fwrite(&b,sizeof(b),1,tc);
			fread(&b,sizeof(b),1,tb);
		}
	}

	fclose(ta);
	fclose(tb);
	fclose(tc);
	
} 



void ordenar(void)
{
	tabela3 c1;
	tabela3 c2;
	int quant,i,l;
	
	FILE *tc = fopen("tabela3.dat","rb+");
	
	fseek(tc,0,2);
	quant = ftell(tc) / sizeof(tabela3);
	for(i=0;i<quant-1;i++)
	{
		for(l=i+1;l<quant;l++)
		{
			fseek(tc,i*sizeof(tabela3),0);
			fread(&c1,sizeof(tabela3),1,tc);
			
			fseek(tc,l*sizeof(tabela3),0);
			fread(&c2,sizeof(tabela3),1,tc);
			
			if(strcmp(c1.prod,c2.prod)>0)
			{
				fseek(tc,i*sizeof(tabela3),0);
				fwrite(&c2,sizeof(tabela3),1,tc);
				
				fseek(tc,l*sizeof(tabela3),0);
				fwrite(&c1,sizeof(tabela3),1,tc);
			}
		}
	}
	fclose(tc);
	
}

int main()
{
	juncao();
	
	return 0;
}
