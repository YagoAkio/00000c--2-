#include<stdio.h>
#include<conio2.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

struct pokemon{
	char NumeroPokedex[5];
	char nome[30];
	char tipo1[15];
	char tipo2[15];
	int HP,Attack,Defense,SpAttack,SpDefense,Speed;
};

void exibir(FILE *arq){
	pokemon poke;
	fscanf(arq,"%[^,],%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d\n",&poke.NumeroPokedex,&poke.nome,&poke.tipo1,&poke.tipo2,&poke.HP,&poke.Attack,&poke.Defense,&poke.SpAttack,&poke.SpDefense,&poke.Speed);
	while(!feof(arq)){
		printf("%s %s\t\t %s\t%s\t %d %d %d %d %d %d\n",poke.NumeroPokedex,poke.nome,poke.tipo1,poke.tipo2,poke.HP,poke.Attack,poke.Defense,poke.SpAttack,poke.SpDefense,poke.Speed);
		fscanf(arq,"%[^,],%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d\n",&poke.NumeroPokedex,&poke.nome,&poke.tipo1,&poke.tipo2,&poke.HP,&poke.Attack,&poke.Defense,&poke.SpAttack,&poke.SpDefense,&poke.Speed);
	}
	printf("%s\n",poke.NumeroPokedex);
}

void exibirPorTipo(FILE *arq,char tipo[15]){
	pokemon poke;
	fscanf(arq,"%[^,],%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d",&poke.NumeroPokedex,&poke.nome,&poke.tipo1,&poke.tipo2,&poke.HP,&poke.Attack,&poke.Defense,&poke.SpAttack,&poke.SpDefense,&poke.Speed);
	while(!feof(arq)){
		if(strcmp(tipo,poke.tipo1)==0||strcmp(tipo,poke.tipo2)==0)
			printf("%s %s\t\t %s\t%s\t %d %d %d %d %d %d\n",poke.NumeroPokedex,poke.nome,poke.tipo1,poke.tipo2,poke.HP,poke.Attack,poke.Defense,poke.SpAttack,poke.SpDefense,poke.Speed);
		fscanf(arq,"\n%[^,],%[^,],%[^,],%[^,],%d,%d,%d,%d,%d,%d",&poke.NumeroPokedex,&poke.nome,&poke.tipo1,&poke.tipo2,&poke.HP,&poke.Attack,&poke.Defense,&poke.SpAttack,&poke.SpDefense,&poke.Speed);
	}
	printf("%s\n",poke.NumeroPokedex);
}



int main(){
	FILE *arq = fopen("pokemon.txt","r");
	exibirPorTipo(arq,(char*)"Psychic");
	return 0;
}
