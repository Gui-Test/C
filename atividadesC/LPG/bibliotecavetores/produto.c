#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "produto.h"

//É tipo um inicialize()
void inicializa_produto(struct Produto *p, int c, char *d, float pr){
    p->codigo = c;
    strcpy(p->descricao, d);
    p->preco = pr;
}

//É tipo um get() e set()
void mostra_produto(struct Produto x){
    printf("codigo: %d\n", x.codigo );
    printf("descricao: %s\n", x.descricao);
    printf("preco: R$%.2f\n", x.preco);  
    printf("\n");
}

void le_produto(struct Produto *p){
    printf("Digite o codigo: ");
    scanf("%d", &p->codigo);
    printf("Digite a descricao: ");
    scanf("%s", p->descricao);
    printf("Digite o preco: ");
    scanf("%f", &p->preco);
    printf("\n");
}