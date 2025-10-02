#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetores.h"

#define LIN 4
#define COL 4

int main(){
    printf("Matriz m:\n");
    int m[LIN][COL];
    gera_valores(m, LIN*COL, 100);
    mostra_matriz(LIN, COL,m);

    printf("Matriz n:\n");
    int n[LIN][COL];
    gera_valores(n, LIN*COL, 100);
    mostra_matriz(LIN, COL,n);

    printf("\nMatriz m+n:\n");
    int nm[LIN][COL];
    soma_matriz(LIN,COL,m,n,nm);
    mostra_matriz(LIN, COL,nm);
}