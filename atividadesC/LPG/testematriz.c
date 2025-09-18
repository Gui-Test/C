#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4
// Coisa da aula de matriz, %4d faz com que no print se o número ser menor que 4 ele adiciona espaços.
// Outra forma de fazer isso seria com %d \t  pois a tabulação costuma alinhar certamente

void mostra_vetor(int v[], int n){
    int i;
    printf("Dados do vetor:\n");
    for ( i = 0; i < n ; i++){
        printf("[%d] : %d\n", i, v[i]);
    }
}

int main(int argc, char const *argv[])
{
    int mat[N][N];
    int n = N;
    
    srand(time(0));
    for (int i = 0; i < n ; i++){
        for (int j = 0; j < n; j++){
            mat[i][j] = rand() % 1000 + 1;
        }
    }

    for (int i = 0; i < n ; i++){
        for (int j = 0; j < n; j++){
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
    printf("Mostrando matriz como vetor\n");
    mostra_vetor(mat, N*N);

    printf("\n\nVetor da diagonal principal:\n");
    for(int i = 0;i < N;i++){
            printf("%d ", mat[i][i]);
    }

    printf("\n\nVetor da diagonal segundaria:\n");
    int i = 0;
    for(int j = N;j >= 0;j--){ 
            printf("%d ", mat[i][j]); 
        i++;
    }
    
    
}

