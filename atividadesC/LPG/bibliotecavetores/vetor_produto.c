#include <stdlib.h>
#include <stdio.h>
#include "produto.h"

int main(int argc, char const *argv[]){
    int n,i;
    printf("Quantos produtos? ");
    scanf("%d", &n);

    struct Produto *v = malloc(sizeof(struct Produto) * n);

    for(i=0; i<n ; i++){
        printf("Dados do produto %d:\n", i+1);
        le_produto(&v[i]);
    }

    for(i=0; i<n ; i++){
        printf("Produto %d:\n", i+1);
        mostra_produto(v[i]);
    }

    free(v);

}
