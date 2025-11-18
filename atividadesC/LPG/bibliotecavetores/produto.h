#include "data.h"

typedef struct{
    int codigo;
    char descricao[20];
    float preco;
    Data validade;
}Produto;

void inicializa_produto(Produto *p, int c, char *d, float pr);
void mostra_produto(Produto x);
void le_produto(Produto *p);