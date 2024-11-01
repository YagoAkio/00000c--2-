
//se estiver dentro de uma funcao usar o file como parametro, caso esteja em um menu 


//INSERCAO ORDENADA
void inserir(FILE *ptr)
{
	int pos;
	tpessoa reg1, reg2;
	fseek(ptr,0,2);
	pos=ftell(ptr)/sizeof(tpessoa)-1;

	fseek(ptr, possizeof(tpessoa),0)
	fread(reg2,sizeof(tpessoa),1,ptr);
	
	fseek(ptr, sizeof(tpessoa)*(pos-1),0);
	fread(reg1, sizeof(tpessoa),1,ptr);
	
	while(pos>0 && strcmp(reg2.nome, reg1.nome)<0)
	{
		fseek(ptr, pos*sizeof(tpessoa),0)
		fwrite(reg2, sizeof(tpessoa),1,ptr);
		fseek(ptr, (pos-1)*sizeof(tpessoa),0)
		fwrite(reg1, sizeof(tpessoa),1,ptr);
		pos--;
		
		if(pos>0)
		{
			fseek(ptr, pos*sizeof(tpessoa),0);
			fread(reg2, sizeof(tpessoa),1,ptr);
			fseek(ptr, (pos-1)*sizeof(tpessoa),0);
			fread(reg1, sizeof(tpessoa),1,ptr);
		}
	}
	fclose(ptr)
}



void exclusaoaf()//exclusao_fisica
{
	FILE *ptr1 = fopen("cadastro.txt","rb");
	FILE *ptr2 = fopen("auxiliar.txt","rw+");
	alunos aux;
	while(!feof(ptr1))
	{
		fread(&aux,sizeof(alunos),1,ptrdisc);
		if(aux.status=='a')
		{
			fwrite(&aux, sizeof(alunos),1,ptr2);
		}
	}
	remove("cadastro.txt");
	remove("auxiliar.txt","cadastro.txt");
	fclose(ptr2);
	fclose(ptr1);
}

void exclusaoal()//exclusao logica
{
	alunos aux;
	int j=0,pos;
	FILE *ptr1 = fopen("cadastro.txt","rb");
	fseek(ptr,0,0);
	printf("INFORME O NOME QUE DESEJA EXCLUIR:");
	fflush(stdin);
	gets(j);
	fread(&aux, sizeof(alunos),1,ptr);
	while(!feof(ptr) && strcmp(aux.nome, j)!=0)
	{
		fread(&aux,sizeof(alunos),1, ptr);
	}
	pos=ftell(ptr)-sizeof(alunos);
	if(aux.status=='a')
	{
		aux.status=='b';
		fseek(ptr,pos,0);
		fwrite(&aux, sizeof(alunos),1,ptr);
	}
	fclose(ptr);
}

int buscadisc(FILE *ptrdisc, int cod)
{
//busca binaria
	fseek(ptrdisc,0,2);
	int meio,inicio=0, fim=ftell(ptrdisc)/sizeof(disc)-1;
	meio=(inicio+fim)/2;
	fseek(ptrdisc,meio*sizeof(disc),0);
	disc di;
	fread(&di, sizeof(disc),1,ptrdisc);
	while(iniciocodisc)
	{
		fim=inicio-1;
		inicio=fim+1;
	}
	else
		meio=(inicio+fim)/2;
		fread(&di,sizeof(disc),1,ptrdisc);
		if(di.codisc==codisc)
		{
			return meio*sizeof(disc);
		}
		else
			return -1;
	}
}

int buscaal(FILE *ptrcad, char ra[tf])
{
	fseek(ptrcad,0,0);
	alunos al;
	fread(&al,sizeof(alunos),1,ptrcad);
	while(!feof(ptrcad) && strcmp(al.ra,ra)!=0)
	{
		fread(&aux, sizeof(alunos),1,ptrcad);
	}
	if(strcmp(ra, al.ra)==0)
	{
		return ftell(ptrcad)-sizeof(alunos)
	}
	else
		return -1;
	fclose(ptrcad);
}



void cadastro(void)//não precisa de retorno por isso void
{
	FILE *ptrcad = fopen("cadastro.txt", "ab+");
	alunos al;
	clrscr();
	if(ptrcad==NULL)
	{
		printf("ERRO DE ABERTURA!");
	}
	else
		printf("***CADASTRO DE ALUNO***\n");
		printf("\n");
		printf("INFORME O RA:");
		fflush(stdin);
		gets(al.ra);
		if(buscaal(ptrcad,al.ra)!=-1)
		{	
			printf("ALUNO JÁ CADASTRADO!\n");
		}
		else
			printf("INFORME O NOME:");
			fflush(stdin);
			gets(al.nome);
			fwrite(&al, sizeof(alunos),1,ptrcad);
			insercao(ptrcad);
			fclose(ptrcad);
}



