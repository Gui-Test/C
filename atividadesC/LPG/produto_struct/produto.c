#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "produto.h"

//É tipo um inicialize()
void inicializa_produto(Produto *p, int c, char *d, float pr){
    p->codigo = c;
    strcpy(p->descricao, d);
    p->preco = pr;
}

//É tipo um get() e set()
void mostra_produto(Produto x){
    printf("codigo: %d\n", x.codigo );
    printf("descricao: %s\n", x.descricao);
    printf("preco: R$%.2f\n", x.preco);  
    mostra_data(x.validade);
    printf("\n");
}

void le_produto(Produto *p){
    printf("Digite o codigo: ");
    scanf("%d", &p->codigo);
    printf("Digite a descricao: ");
    scanf(" %[^\n]", p->descricao);
    printf("Digite o preco: ");
    scanf("%f", &p->preco);
    le_data(&p->validade);
    printf("\n");
}