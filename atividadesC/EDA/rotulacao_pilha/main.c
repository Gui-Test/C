#include "arq.h"

int main(){
    int mat[M][N] = {{0}};
    cria_matriz(mat);

    int rotulo = 0;

    struct pilha *pilha;
    pilha = cria();

    for (int i=1;i<=M;i++){
        for (int j=1;j<=N;j++){
            if (mat[i][j]==1)
                rotulo+=10;
                marcador(i,j,direcao,rotulo,pilha);
                reset(pilha);
        }
    }
   
}