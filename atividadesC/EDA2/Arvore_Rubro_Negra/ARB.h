#include <stdlib.h>
#include <stdio.h>

enum coloracao { Vermelho, Preto };
typedef enum coloracao Cor;

typedef struct no {
    struct no* pai;
    struct no* esquerda;
    struct no* direita;
    Cor cor; //cor do nó (Vermelho ou Preto)
    int valor;
} No;

typedef struct arvore {
    struct no* raiz;
} Arvore;

Arvore* cria();
int vazia(Arvore* AVL);
int max(int a, int b);
No* localizar(No* no, int valor);
void adicionar(Arvore* arvore, int valor);
void percorrer(No* no, void (*callback)(int));
void visitar(int valor);
void balancear(Arvore* arvore, No* no);
void rotacionarEsquerda(Arvore* arvore, No* no);
void rotacionarDireita(Arvore* arvore, No* no);

Arvore* criar() {
    Arvore *ARB;
    ARB = malloc(sizeof(Arvore));
    ARB->raiz = NULL;
    return ARB;
}

int vazia(Arvore* ARB) {
    return (ARB->raiz == NULL);
}

int max(int a, int b) {
    return a > b ? a : b;
}

void adicionar(Arvore* arvore, int valor) {
    No* no = arvore->raiz;

    while (no != NULL) {
        if (valor > no->valor) {
            if (no->direita != NULL) {
                no = no->direita;
            } else {
                break;
            }
        } else {
            if (no->esquerda != NULL) {
                no = no->esquerda;
            } else {
                break;
            }
        }
    }

    printf("Adicionando %d\n", valor);
    No* novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->pai = no;
    novo->esquerda = NULL;
    novo->direita = NULL;
    novo->cor = Vermelho;

    if (no == NULL) {    
        arvore->raiz = novo;
    } else {
        if (valor > no->valor) {
            no->direita = novo;
        } else {
            no->esquerda = novo;
        }
        
        balancear(arvore, no);
    }
}

No* localizar(No* no, int valor) {
    while (no != NULL) {
        if (no->valor == valor) {
            return no;
        }
        
        no = valor < no->valor ? no->esquerda : no->direita;
    }

    return NULL;
}

void percorrer(No* no, void (*callback)(int)) {
    if (no != NULL) {
        percorrer(no->esquerda,callback);
        callback(no->valor);
        percorrer(no->direita,callback);
    }
}

void visitar(int valor){
    printf("%d ", valor);
}

void balancear(Arvore* arvore, No* no) {
    while (no->pai->cor == Vermelho) { //Garante que todos os níveis foram balanceados
        if (no->pai == no->pai->pai->esquerda) {
            No *tio = no->pai->pai->direita;
            if (tio->cor == Vermelho) {
                tio->cor = Preto; //Resolve caso 2
                no->pai->cor = Preto;
                no->pai->pai->cor = Vermelho;
                no = no->pai->pai; //Vai para o nível anterior
            } else {
                if (no == no->pai->direita) {
                    no = no->pai; //Vai para o nível anterior
                    rotacionarEsquerda(arvore, no); //Resolve caso 3
                } else {
                    no->pai->cor = Preto; //Resolve caso 4
                    no->pai->pai->cor = Vermelho;
                    rotacionarDireita(arvore, no->pai->pai);
                }
            }
        } else {
            //Repete o mesmo código do bloco if, invertendo o lado dos direita e esquerda
            if (no->pai == no->pai->pai->direita){
                No *tio = no->pai->pai->esquerda;
                if (tio->cor == Vermelho) {
                    tio->cor = Preto; //Resolve caso 2
                    no->pai->cor = Preto;
                    no->pai->pai->cor = Vermelho;
                    no = no->pai->pai; //Vai para o nível anterior
                } if (no == no->pai->esquerda) {
                    no = no->pai; //Vai para o nível anterior
                    rotacionarDireita(arvore, no); //Resolve caso 3
                } else {
                    no->pai->cor = Preto; //Resolve caso 4
                    no->pai->pai->cor = Vermelho;
                    rotacionarEsquerda(arvore, no->pai->pai);
                }
            }
            }
        }
        arvore->raiz->cor = Preto; //Resolve caso 1
}

void rotacionarEsquerda(Arvore* arvore, No* no) {
    No* direita = no->direita;
    no->direita = direita->esquerda;
    
    if (direita->esquerda != NULL)
        direita->esquerda->pai = no; //Se houver filho à esquerda em direita, ele será pai do nó

    direita->pai = no->pai; //Ajusta no pai do nó à direita

    if (no->pai == NULL)
        arvore->raiz = direita; //Se nó for raiz, o nó direita será a nova raiz da árvore
    else if (no == no->pai->esquerda)
        no->pai->esquerda = direita; //Corrige relação pai-filho do novo pai (esquerda)
    else
        no->pai->direita = direita; //Corrige relação pai-filho do novo pai (direita)

    direita->esquerda = no; //Corrige relação pai-filho entre o nó pivô e o nó à direita
    no->pai = direita;
}

void rotacionarDireita(Arvore* arvore, No* no) {
    No* esquerda = no->esquerda;
    no->esquerda = esquerda->direita;
    
    if (esquerda->direita != NULL)
        esquerda->direita->pai = no; //Se houver filho à direita em esquerda, ele será pai do nó

    esquerda->pai = no->pai; //Ajusta no pai do nó à esquerda

    if (no->pai == NULL)
        arvore->raiz = esquerda; //Se nó for raiz, o nó esquerda será a nova raiz da árvore
    else if (no == no->pai->esquerda)
        no->pai->esquerda = esquerda; //Corrige relação pai-filho do novo pai (esquerda)
    else
        no->pai->direita = esquerda; //Corrige relação pai-filho do novo pai (direita)
    
    esquerda->direita = no; //Corrige relação pai-filho entre o nó pivô e o nó à esquerda
    no->pai = esquerda;
}

