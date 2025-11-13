#include <stdlib.h>
#include <stdio.h>
#include "produto.h"

int main(int argc, char const *argv[]){
    struct Produto x,y;
    inicializa_produto(&x,123,"Pao Enlatado", 27.99);
    mostra_produto(x);

    y = x; //confia que funciona
    y.preco = 30;

    mostra_produto(y);

    le_produto(&x);

    mostra_produto(x);
}