#include <stdlib.h>
#include <stdio.h>

struct nodo{ 
    int x;
    struct nodo *esq;
    struct nodo *dir;
};

struct descritor{ 
    unsigned int posicao;
    struct nodo *primeiro, *ultimo, *link;
};

int contaNodo(struct descritor *p);

int main(int argc, char const *argv[]){
    struct nodo a = {1,NULL,NULL};
    struct nodo b = {2,NULL,NULL};
    struct nodo c = {3,NULL,NULL};
    a.dir = &b;
    b.esq = &a;
    b.dir = &c;
    c.esq = &b;

    struct descritor desc;
    desc.posicao = 2; 
    desc.primeiro = &a;
    desc.link = &b;
    desc.ultimo = &c;


    struct descritor *p = &desc;

    printf("Nodos: %d", contaNodo(p));

}

int contaNodo(struct descritor *p){
    int cont=0;
   
    if (p == NULL){
        return 0;
    }

    else{
        struct nodo *aux = p->link;
        cont+= p->posicao;
        while(aux->dir != NULL){
            aux = aux->dir;
            cont+=1;
        }
    }
    return cont;
}