#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetores.h"

#define LIN 4
#define COL 5

int main(int argc, char const *argv[])
{
    printf("Matriz m:\n");
    int m[LIN][COL];
    gera_valores(m, LIN*COL, 100);
    mostra_matriz(LIN, COL,m);

    printf("\nMedia dos pares da matriz:%f", media_pares(LIN,COL,m));

    /*int i,j;
     for (i=0;i<LIN;i++){
        for (j=0;j <COL;j++){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
     }*/
}

//tentando fazer uma função que gera matriz 
//problemas achados ao usar essa função: funciona, mas não para qualquer matriz. mostra_matriz(int x[COL],int lin, int col)
//Uma forma de resolver é pedir os tamanhos ao usuário mostra_matriz(int lin,int col,int x[lin][col]);
/*void mostra_matriz(int lin, int col,int x[lin][col]){
    int i,j;
     for (i=0;i<lin;i++){
        for (j=0;j<col;j++){
            printf("%d\t", x[i][j]);
        }
        printf("\n");
     }
}*/
