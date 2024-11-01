#include<stdio.h>
#include<conio2.h>
#include<string.h>
#include<stdlib.h>

#define tf 10

int main(void)
{
    int op,i=0,j=0,tl=0,pos,a=0,x;
    char cidade[tf][25], aux[25];
    do
    {
        printf("CADASTRO DE CIDADES\n");
        printf("------------------------------------------------------\n");
        printf("[1]-INSERIR\n");
        printf("[2]-EXIBIR\n");
        printf("[3]-ORDENAR\n");
        printf("[0]-SAIR\n");
        printf("INFORME QUAL OPCAO DESEJA:");
        scanf("%d", &op);
        if(op==1)
        {
            printf("\nINFORME O NOME DA CIDADE:");
            fflush(stdin);
            gets(aux);
            while(tl<tf && strlen(aux)>0)
            {
                strcpy(cidade[tl], aux);
                tl++;
                if(tl<tf)
                {
                	printf("\nINFORME O NOME DA CIDADE:");
	                fflush(stdin);
	                gets(aux);
				}
                
            }
        }
        else
        {
            if(op==2)
            {
                printf("\nEXIBIR CIDADES");
                printf("----------------------------------------------------\n");
                for(j=0;j<tl;j++)
                {
                    printf("[%d]-%s\n", j, cidade[j]);
                }
            }
            else
            {
                if(op==3)
                {
                    
	                for(a=0;a<tf;a++)
	                	for(pos=a+1;pos<tf;pos++)
		                    if(strcmp(cidade[a],cidade[pos])<0)
		                    {
		                    	strcpy(aux,cidade[pos]);
		                        strcpy(cidade[pos],cidade[a]);
		                        strcpy(cidade[a],aux);
							}
                    
                }
            }
        }
    }while(op!=0);

}
