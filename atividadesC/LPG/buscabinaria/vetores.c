#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetores.h"

int busca_binaria (int v[], int n, int chave){
    int ini = 0, fim = n-1, meio;
    int count = 0;
    do{
        count++;
        meio = ( ini + fim ) / 2;
        if(v[meio] == chave)
            //printf("\n[Numero de interacoes: %d]\n", count); não sei porque tá dando errado, o sor também não sabe.
            return meio; // Encontrado em meio!
        if(v[meio] < chave)
            ini = meio + 1;
        else
            fim = meio - 1;
    }while(ini <= fim);
    //printf("\n[Numero de interacoes: %d]\n", count);
    return -1; // Não encontrado!
}

void gera_valores(int v[], int n){
    int i;
    srand(time(0));
    for ( i = 0; i < n ; i++){
        v[i] = rand() % 1000 + 1;
    }
}

void gera_valores_ordem(int v[], int n, int limite){
    int i;
    srand(time(0));
    v[0] = rand() % limite + 1;
    for ( i = 1; i < n ; i++){
        v[i] = v[i-1] + rand() % 5 + 1;
    }
}

void mostra_vetor(int v[], int n){
    int i;
    printf("Dados do vetor:\n");
    for ( i = 0; i < n ; i++){
        printf("[%d] : %d\n", i, v[i]);
    }
}