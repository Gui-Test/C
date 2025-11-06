#include <stdio.h>
#include <stdlib.h>

int main(){
    int **p;
    int lin, col, i, j;
    printf("Linhas e Colunas:");
    scanf("%d %d", &lin, &col);

    //alocação de vetor de ponteiros
    p = malloc(sizeof(int*)*lin);
    //alocação das linhas
    for(i=0;i<lin;i++)
     p[i] = malloc(sizeof(int)*col);

    //entrada
    for( i = 0 ; i < lin ; i++ )
     for( j = 0 ; j < col ; j++ )
      scanf("%d", &p[i][j]);

    //saida dos dados
     for(i=0; i<lin; i++){
     printf("|\t");
     for(j=0;j<col;j++)
        printf("%d\t", p[i][j]);
     printf("|\n");
    }

    //libera memoria
    for(i=0; i<4; i++)
        free(p[i]);
    free(p); 
}