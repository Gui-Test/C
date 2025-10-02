#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetores.h"

#define L_A 2
#define C_A 3
#define L_B C_A 
#define C_B 4

int main(){

    int a[L_A][C_A];
    int b[L_B][C_B];
    int c[L_A][C_B];

    gera_matriz(L_A,C_A,a, 5);
    mostra_matriz(L_A,C_A,a);
    gera_matriz(L_B,C_B,b,5);
    mostra_matriz(L_B,C_B,b);

    multiplica_matriz(L_A,C_A,a,L_B,C_B,b,c);
    mostra_matriz(L_A,C_B,c);

}