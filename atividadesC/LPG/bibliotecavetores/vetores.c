#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetores.h"

//Vetores
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

void gera_valores(int v[], int n,int limite){
    int i;
    srand(time(0));
    for ( i = 0; i < n ; i++){
        v[i] = rand() % limite + 1;
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

//Matrizes
void gera_matriz(int lin, int col,int x[lin][col],int limite){
    gera_valores((int*)x,lin*col,limite);
}

void mostra_matriz(int lin, int col,int x[lin][col]){
    int i,j;
    printf("Dados da Matriz %dx%d:\n", lin,col);
     for (i=0;i<lin;i++){
        for (j=0;j<col;j++){
            printf("%d\t", x[i][j]);
        }
        printf("\n");
     }
}

float media_pares(int l, int c,int x[l][c]){
    int i,j;
    float cont = 0;
    float soma = 0;
     for (i=0;i<l;i++){
        for (j=0;j<c;j++){
            if(x[i][j]%2 == 0){
                soma += x[i][j];
                cont++;
            }
        }
        return (soma/cont);
     }
}

void gera_transposta(int l, int c,int x[l][c], int t[c][l]){
    int i,j;
     for (i=0;i<c;i++){
        for (j=0;j<l;j++){
            t[i][j] = x[j][i];
        }
     }

}

void soma_matriz(int l, int c,int x[l][c], int y[l][c],int t[l][c]){
    int i,j;
     for (i=0;i<l;i++){
        for (j=0;j<c;j++){
            t[i][j] = x[i][j] + y[i][j];
        }
     }

}

void multiplica_matriz(int la, int ca, int a[la][ca], int lb, int cb, int b[lb][cb], int c[la][cb]){
    int i,j,k;

    for(i=0;i<la;i++){
        for(j=0;j<cb;j++){
            int soma = 0;
            for(k=0;k<ca;k++){
                soma+= a[i][k]*b[k][j];
            }
            c[i][j] = soma;
        }
    }
}
