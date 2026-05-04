#include "arq.h"
//Para compilar: gcc main.c arq.h pilha.c matriz.c

int main(){
    int mat[M][N] = {{0}};

    int rotulo = 0;

    struct pilha *pilha;
    pilha = cria();

    cria_matriz();
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