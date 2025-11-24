#include <stdlib.h>
#include <stdio.h>
#include "produto.h"

//gcc vetor_produto.c produto.h produto.c data.h data.c

int main(int argc, char const *argv[]){
    int n,i,op;
    Produto *v;

    printf("Digite 1 para abrir o arquivo ou qualquer outra coisa para inserir dados...\n");
    scanf("%d", &op);

    if(op == 1){
        FILE *f = fopen("produtos.txt", "rt" ); // rt = read text;
        if(f == NULL){
            printf("Erro no arquivo!\n");
			return 1; // Saindo do programa.
        }else{
            fscanf( f , "%d", &n);
		    printf("Quantidade %d lida...\n", n);
		
		    v = malloc( sizeof(Produto) * n );
		
		    for( i = 0 ; i < n ; i++ ){
			    fscanf(f, "%d", &v[i].codigo);
			    fscanf(f, " %[^\n]", v[i].descricao);
			    fscanf(f, "%f", &v[i].preco);
			    fscanf(f, "%d/%d/%d\n", &v[i].validade.dia, &v[i].validade.mes, &v[i].validade.ano );
		    }

            fclose( f );
		    printf("%d registros carregados do arquivo.\n", n);
        }
        
    }else{

        printf("Quantos produtos? ");
        scanf("%d", &n);

        v = malloc(sizeof(Produto) * n);

        for(i=0; i<n ; i++){
            printf("Dados do produto %d:\n", i+1);
            le_produto(&v[i]);
        }

    }

    for(i=0; i<n ; i++){
        printf("\nProduto %d:\n", i+1);
        mostra_produto(v[i]);
    }

    FILE *f = fopen("produtos.txt", "wt" );  // Cria um novo arquivo de texto no modo 'wt' = write text. Se o arquivo já existe ele reescreve;
    fprintf(f, "%d\n", n); //Escreve no .txt;
    
    for(i=0;i<n; i++){
        fprintf(f,"%d\n", v[i].codigo );
        fprintf(f,"%s\n", v[i].descricao);
        fprintf(f,"%.2f\n", v[i].preco);  
        fprintf(f,"%d/%d/%d",v[i].validade.dia,v[i].validade.mes,v[i].validade.ano);
        fprintf(f,"\n");
    }

    fclose(f);
    free(v);

}
