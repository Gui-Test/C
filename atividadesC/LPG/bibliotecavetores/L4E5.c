#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetores.h"
//Busca sequencia recursiva
//Compilação: gcc L4E5.c vetores.c vetores.h
#define N 10
int busca_seq_rec(int v[],int n,int chave);
int seq_rec(int v[],int n,int chave,int i);
int min_rec(int v[],int k);

int main(){
    int v[N];
    gera_valores(v,N,10);
    mostra_vetor(v,N);
    
    int chave; 
    printf("Digite o valor que voce quer que seja buscado no vetor:\n");
    scanf("%d", &chave);

    busca_seq_rec(v,N,chave);
}

int busca_seq_rec(int v[],int n,int chave){
    printf("\nindice = {");
    int k = seq_rec(v,n,chave,0);
    min_rec(v,k);
    printf("\b\b}\n");
}

int seq_rec(int v[],int n,int chave,int i){
    if (i == n){
        return i;
    }
    if (v[i] == chave){
        printf("%d, ",i);
        i++;
        return seq_rec(v,n,chave,i);
    }
    i++;
    return seq_rec(v,n,chave,i);
}

int min_rec(int v[],int k){
    if (k==0){
        return 0;
    }
    printf("-1, ");
    k--;
    return min_rec(v,k);
}
