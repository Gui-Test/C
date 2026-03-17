#include <stdlib.h>
#include <stdio.h>

struct nodo{ 
    int x;
    struct nodo *link;
};

int contaNodo(struct nodo *p);

int main(int argc, char const *argv[]){
    struct nodo a = {1,NULL};
    struct nodo b = {2,NULL};
    struct nodo c = {3,NULL};
    //a.link = &b;
    b.link = &c;

    struct nodo *p = &a;

    printf("Nodos: %d", contaNodo(p));

}

int contaNodo(struct nodo *p){
    int cont=0;
   
    if (p == NULL){
        return 0;
    }

    else{
        struct nodo *aux = p;
        cont+= 1;
        while(aux->link != NULL){
            aux = aux->link;
            cont+=1;
        }
    }
    return cont;
}



