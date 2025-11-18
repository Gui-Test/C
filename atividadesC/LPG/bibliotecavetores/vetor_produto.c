#include <stdlib.h>
#include <stdio.h>
#include "produto.h"

//gcc vetor_produto.c produto.h produto.c data.h data.c

int main(int argc, char const *argv[]){
    int n,i,op;

    printf("Digite 1 para abrir o arquivo ou qualquer outra coisa para inserir dados...");
    scanf("%d", &op);

    if(op == 1){
        
    }else

    printf("Quantos produtos? ");
    scanf("%d", &n);

    Produto *v = malloc(sizeof(Produto) * n);

    for(i=0; i<n ; i++){
        printf("Dados do produto %d:\n", i+1);
        le_produto(&v[i]);
    }

    for(i=0; i<n ; i++){
        printf("\nProduto %d:\n", i+1);
        mostra_produto(v[i]);
    }

    FILE *f = fopen("produtos.txt", "wt" );  // Cria um novo arquivo de texto no modo 'wt' = write text. Se o arquivo já existe ele reescreve;
    fprintf(f, "Lista de produtos:\n"); //Escreve no .txt;
    
    for(i=0;i<n; i++){
        fprintf(f,"\nProduto %d:\n", i+1);
        fprintf(f,"codigo: %d\n", v[i].codigo );
        fprintf(f,"descricao: %s\n", v[i].descricao);
        fprintf(f,"preco: R$%.2f\n", v[i].preco);  
        fprintf(f,"%d/%d/%d",v[i].validade.dia,v[i].validade.mes,v[i].validade.ano);
        fprintf(f,"\n");
    }

    fclose(f);
    free(v);

}
