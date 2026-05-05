#include "arq.h"
//Para compilar: gcc main.c arq.h pilha.c matriz.c

int main(){
    int m = 0,n = 0;
    int rotulo = 0;

    struct pilha *pilha;
    pilha = cria();

    int **mat = cria_matriz(&m,&n);

    printf("m: %d", m);
    printf("\nn: %d", n);

    printf("\n");

    insere_matriz(&mat,m,n);

    print_matriz(mat,m,n);

    for(int i = 0; i<m; i++)
        free(mat[i]); 
    free(mat);

    /*
    for (int i=1;i<=M;i++){
        for (int j=1;j<=N;j++){
            if (mat[i][j]==1)
                rotulo+=10;
                marcador(i,j,direcao,rotulo,pilha);
                reset(pilha);
        }
    }
    */
   
}