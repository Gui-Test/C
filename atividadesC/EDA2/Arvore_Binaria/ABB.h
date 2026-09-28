#include <stdlib.h>
#include <stdio.h>


typedef struct no {
    struct no* pai;             //ponteiro para o nó pai
    struct no* esquerda;        //ponteiro para o nó filho a esquerda
    struct no* direita;         //ponteiro para o nó filho a direita
    int valor;                //conteúdo de um nó arbitrário da árvore
} No;

typedef struct abb {
    struct no* raiz;
} ABB;

ABB* cria() {
    ABB *ABB;
    ABB = malloc(sizeof(ABB));
    ABB->raiz = NULL;
    return ABB;
}

int vazia(ABB* ABB) {
    return (ABB->raiz == NULL);
}

No* adiciona(ABB* ABB, int valor) {
    No *no = malloc(sizeof(No));
    no->pai = NULL;
    no->direita = NULL;
    no->esquerda = NULL;
    no->valor = valor;

    int dir = 0;
    
    if (vazia(ABB)) {
        ABB->raiz = no;
        return no;
    }

    No *aux = malloc(sizeof(No));
    aux = ABB->raiz;
    while(aux != NULL){
        no->pai = aux;
        if(no->valor > aux->valor){
            aux = aux->direita;
            dir = 1;
        }else{
            aux = aux->esquerda;
            dir = 0;
        }
    }

    if(dir){
        no->pai->direita = no;
    }else{
        no->pai->esquerda = no;
    }
    
    return no;
}

void percorrer(No* no) {
    if (no != NULL) {
        printf("%i\n", no->valor);
        percorrer(no->esquerda);
        percorrer(no->direita);
    }
}