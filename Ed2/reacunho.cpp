struct reg_lista
{
 struct listagen *cabeca;
 struct listagen *cauda;
};
union info_lista
{
 char info[8];
 struct reg_lista lista;
};
struct listagen
{
 char terminal;
 union info_lista no;
};
typedef struct listagen ListaGen;

ListaGen *CriaT(char *info)
{
 ListaGen *L = (ListaGen*)malloc(sizeof(ListaGen));
 L->terminal = 1;
 strcpy(L->no.info, info);
 return L;
}

char Nula(ListaGen *L)
{
 return L==NULL;
}

char Atomo(ListaGen *L)
{
 return !Nula(L) && L->terminal;
}

ListaGen *dup(ListaGen*L){
    if(Nula(L))
        return NULL;
    else
        return Criat(L->no.info);
    return Cons(dup(Head(L)),dup(Tail(L)));
}

char iguais(ListaGen *L1,ListaGen *L2){
    if(Nula(L1)&&Nula(L2))
        return 1;
    if(Nula(L1)||Nula(L2))
        return 0;
    if(Atomo(L1)&&Atomo(L2)){
        return !strcmp(L1->info,L2->info);
        //ou
        // if(strcmp(L1->info,L2->info))
        //     return 1;
        // else
        //     return 0;
    }   
    if(Atomo(L1)||Atomo(L2))
        return 0;
    return iguais(Head(L1),Head(L2))&&iguais(Tail(L1),Tail(L2));
}