#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetores.h"
//Busca sequencia
//Compilação: gcc L4E4.c vetores.c vetores.h
#define N 10
void busca_todos(int v[],int n,int chave,int indice[]);

int main(){
    int v[N];
    gera_valores(v,N,10);
    mostra_vetor(v,N);
    
    int chave; 
    printf("Digite o valor que voce quer que seja buscado no vetor:\n");
    scanf("%d", &chave);

    int ind[N];
    busca_todos(v,N,chave,ind);
    mostra_vetor(ind,N);
}

void busca_todos(int v[],int n,int chave,int indice[]){
    int i;
    int j = 0;
    for(i = 0; i < n;i++){
        if (v[i] == chave){
            indice[j] = i;
            j++;
        }
    }
    while (j<n){
        indice[j] = -1;
        j++;
    }
}