#include <stdlib.h>
#include <stdio.h>

typedef struct no {
    struct no* pai;             //ponteiro para o nó pai
    struct no* esquerda;        //ponteiro para o nó filho a esquerda
    struct no* direita;         //ponteiro para o nó filho a direita
    int valor;                //conteúdo de um nó arbitrário da árvore
} No;

typedef struct avl {
    struct no* raiz;
} AVL;

AVL* cria();
int vazia(AVL* AVL);
int altura(No* no);
int fb(No* no);
No* rse(No* no);
No* rsd(No* no);
No* rde(No* no);
No* rdd(No* no);
No* adiciona(AVL* AVL, int valor);

AVL* cria() {
    AVL *AVL;
    AVL = malloc(sizeof(AVL));
    AVL->raiz = NULL;
    return AVL;
}

int vazia(AVL* AVL) {
    return (AVL->raiz == NULL);
}

No* adiciona(AVL* AVL, int valor) {
    No *no = malloc(sizeof(No));
    no->pai = NULL;
    no->direita = NULL;
    no->esquerda = NULL;
    no->valor = valor;

    int dir = 0;
    
    if (vazia(AVL)) {
        AVL->raiz = no;
        return no;
    }

    No *aux = malloc(sizeof(No));
    aux = AVL->raiz;
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

    aux = no;
    
    while(aux->pai != NULL){
       int fatorant = fb(aux);
       int fatordep = fb(aux->pai);
       printf("%i\n", valor);
       if(fatordep > 1){
            if(fatorant > 0){
                rsd(aux->pai);
            }else if(fatorant < 0){
                rdd(aux->pai);
            }
       }else if(fatordep < -1){
            if(fatorant < 0){
                rse(aux->pai);
            }else if(fatorant > 0){
                rde(aux->pai);
            }
       }

       if(aux->pai != NULL){
            aux = aux->pai;
       }
       

    }
 
    return no;
}

void percorrer(No* no) {
    if (no != NULL) {
        printf("hallo%i\n", no->valor);
        percorrer(no->esquerda);
        percorrer(no->direita);
    }
}

//Balanceamento
int altura(No* no){
    int esquerda = 0,direita = 0;
    if (no->esquerda != NULL) {
        esquerda = altura(no->esquerda) + 1;
    }
    if (no->direita != NULL) {
        direita = altura(no->direita) + 1;
    }
    return esquerda > direita ? esquerda : direita;
}

int fb(No* no) {
    int esquerda = 0,direita = 0;
    if (no->esquerda != NULL) {
        esquerda = altura(no->esquerda) + 1;
    }
    if (no->direita != NULL) {
        direita = altura(no->direita) + 1;
    }
    return esquerda - direita;
}

//Rotações
//Rotação Simples Esquerda
No* rse(No* no) {
    No* pai = no->pai;
    No* direita = no->direita;
    no->direita = direita->esquerda;
    no->pai = direita;
    direita->esquerda = no;
    direita->pai = pai;
    return direita;
}
//Rotação Simples Direita
No* rsd(No* no) {
    No* pai = no->pai;
    No* esquerda = no->esquerda;
    no->esquerda = esquerda->direita;
    no->pai = esquerda;
    esquerda->direita = no;
    esquerda->pai = pai;
    return esquerda;
}   
//Rotação Dupla a Esquerda
No* rde(No* no) {
    no->direita = rsd(no->direita);
    return rse(no);
}
//Rotação Dupla a Direita
No* rdd(No* no) {
    no->esquerda = rse(no->esquerda);
    return rsd(no);
}