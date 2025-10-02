#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetores.h"

#define LIN 5
#define COL 6

int main(){
    printf("Matriz m:\n");
    int m[LIN][COL];
    gera_valores(m, LIN*COL, 100);
    mostra_matriz(LIN, COL,m);

    printf("Matriz m transosta:\n");
    int n[COL][LIN];
    gera_transposta(LIN,COL,m,n);
    mostra_matriz(COL, LIN,n);

}