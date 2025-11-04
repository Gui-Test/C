#include <stdio.h>
#include <stdlib.h>
#include "vetores.h"

#define MAX 20
int* busca_aloc(int *v,int n, int chave);
int* busca_aloc_v2(int *v,int n, int chave);

int main(){
    int vet[MAX];
    gera_valores(vet, MAX, 100);
    mostra_vetor(vet,MAX);

    int chave;
    printf("Digite o valor a ser buscado:");
    scanf("%d", &chave);

    int *indices = busca_aloc(vet, MAX, chave);

    if(indices[0] != -1){
        printf("Valor encontrado nos indices: ");
        int i;
        for(i = 0; indices[i] != -1; i++ )
            printf("%d ", indices[i]);
        printf("\n");
    }else{
        printf("Nenhum valor encontrado!");
    }

    free(indices);
    return 0;
}

// com malloc
int* busca_aloc(int *v,int n, int chave){
    int i, cont = 0;
    for(i=0;i<n;i++){
        if(v[i]==chave)
            cont++;
    }

    int *p= malloc(sizeof(int)*(cont+1));
    int j=0;
    for(i=0;i<n;i++){
        if(v[i]==chave){
            p[j] = i;
            j++;
        }
    }
    p[j] = -1;
    return p;
}

//com realloc
int* busca_aloc_v2(int *v,int n, int chave){
    int i, cont = 0;
    int *p= malloc(sizeof(int));
    for(i=0;i<n;i++){
        if(v[i]==chave)
            cont++;
            p = realloc(p,sizeof(int)*(cont+1));
            p[cont-1] = i;
    }

    p[cont] = -1;
    return p;
}