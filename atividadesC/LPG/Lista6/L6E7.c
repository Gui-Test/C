#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Exc7 menor matriz
#define L 3
#define C 4

void min_matriz(float mat[3][4], float *pMin, int *pI, int *pJ);

int main(){
    float min,max,mat[L][C];
    int i,j;

    srand(time(0));
    for(i=0;i<L;i++){
        for(j=0;j<C;j++)
            mat[i][j] = rand() % 50 + 1;
    }

    printf("Dados da Matriz:\n");
     for(i=0;i<L;i++){
        for (j=0;j<C;j++){
            printf("%f\t", mat[i][j]);
        }
        printf("\n");
     }
    
    i=0;j=0;
    min_matriz(mat, &min, &i, &j);

    printf("Valores:\n");
    printf("Menor: mat[%d][%d] = %f\n", i, j, min);

}

void min_matriz(float mat[3][4], float *pMin, int *pI, int *pJ){
    int i,j;
    *pMin = mat[0][0];
    *pI = 0;
    *pJ = 0;
    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            if(*pMin>mat[i][j]){
                *pI = i+1;
                *pJ = j+1;
                *pMin = mat[i][j];
            }
        }
    }
}
