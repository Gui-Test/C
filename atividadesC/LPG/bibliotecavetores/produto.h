struct Produto {
    int codigo;
    char descricao[20];
    float preco;
};

void inicializa_produto(struct Produto *p, int c, char *d, float pr);
void mostra_produto(struct Produto x);
void le_produto(struct Produto *p);