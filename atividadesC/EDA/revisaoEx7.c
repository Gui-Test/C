#include <stdlib.h>
#include <stdio.h>

struct data{
    int dia,mes,ano;
};

typedef struct nodo{
    struct data dt;
    struct nodo *link;
}Nodo;

typedef struct descritor{ 
    int tamanho;
    Nodo *inicio;
}Descritor;

int reinicia(Descritor *p);
int insere(Descritor *p, Nodo *novo, int pos);

int main(){
    Nodo a,b,c;
    Descritor desc;

    a.dt.dia = 10;
    a.dt.mes = 6;
    a.dt.ano = 2006;

    b.dt.dia = 17;
    b.dt.mes = 7;
    b.dt.ano = 2007;

    c.dt.dia = 5;
    c.dt.mes = 8;
    c.dt.ano = 2012;

    a.link = &b;
    b.link = &c;

    desc.inicio = &a;
    desc.tamanho = 3;

    Descritor *p = &desc;
}

int reinicia(Descritor *p){
    if(p == NULL){
        return 0;
    }else{
        Nodo *aux = p->inicio;
        while (aux != NULL){
            aux->dt.dia = NULL;
            aux->dt.mes = NULL;
            aux->dt.ano = NULL;
            p->inicio = aux->link; 
            free(aux->link);
            aux = p->inicio;
    }
        free(aux);
        p->tamanho = 0;
        free(p->inicio);
    }
};

int insere(Descritor *p, Nodo *novo, int pos){
    if(p->tamanho == 0){
        p->tamanho = 1;
        p->inicio = &novo;
    }

    if(p->tamanho == 1){
        p->tamanho = 2;
        novo->link = p->inicio;
        p->inicio = &novo;
    }

    if(pos > p->tamanho || pos < 1){
        printf("posicao inválida!");
        return 0;
    }else{
        int cont = 0;
        Nodo *aux = p->inicio;
        while(cont < pos);{
            aux = aux->link;
            cont++;
        }
        novo->link = aux->link;
        aux->link = &novo; 

        p->tamanho++;     

    }

};