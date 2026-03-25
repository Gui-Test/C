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
    Nodo *a,*b,*c,novo;
    Descritor desc;
    int pos;

    a = (Nodo*)malloc(sizeof(Nodo));
    a->dt.dia = 10;
    a->dt.mes = 6;
    a->dt.ano = 2006;

    b = (Nodo*)malloc(sizeof(Nodo));
    b->dt.dia = 17;
    b->dt.mes = 7;
    b->dt.ano = 2007;
    
    c = (Nodo*)malloc(sizeof(Nodo));
    c->dt.dia = 5;
    c->dt.mes = 8;
    c->dt.ano = 2012;

    a->link = b;
    b->link = c;

    desc.inicio = a;
    desc.tamanho = 3;

    Descritor *p = &desc;
    printf("teste \n");

//    reinicia(p);

    printf("Digite um dia:");
        scanf("%d", &novo.dt.dia);
    printf("Digite um mes:");
        scanf("%d", &novo.dt.mes);
    printf("Digite um ano:");
        scanf("%d", &novo.dt.ano);
    printf("Digite uma posicao em que quer colocar:");
        scanf("%d", &pos);
    
    insere(p, &novo, pos);
}


int reinicia(Descritor *p){
    printf("teste entra funcao\n");
    if(p == NULL){
        printf("teste p = null\n");
        return 0;
    }else{
        printf("teste entra else\n");
        Nodo *aux = p->inicio;
        while (aux != NULL){
            printf("%d\n",aux->dt.ano);
            //aux->dt.dia = NULL;
            //aux->dt.mes = NULL;
            //aux->dt.ano = NULL;
            p->inicio = aux->link;
            printf("teste p->inicio recebe aux->link\n"); 
            free(aux->link);
            printf("apos free\n"); 
            aux = p->inicio;
        }
        free(aux);
        p->tamanho = 0;
        p->inicio = NULL;
    }
};

int insere(Descritor *p, Nodo *novo, int pos){
    if(p->tamanho == 0){
        p->tamanho = 1;
        p->inicio = novo;
    }

    if(p->tamanho == 1){
        p->tamanho = 2;
        novo->link = p->inicio;
        p->inicio = novo;
    }

    if(pos > p->tamanho || pos < 1){
        printf("posicao invalida!");
        return 0;
    }else{
        int cont = 0;
        Nodo *aux = p->inicio;
        while(cont < pos){
            aux = aux->link;
            cont+=1;
        }
        novo->link = aux->link;
        aux->link = novo; 

        p->tamanho++;     

    }

};
