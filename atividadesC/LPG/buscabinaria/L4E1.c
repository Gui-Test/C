#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetores.h"
//Compara vetores
//Compilação: gcc L4E1.c vetores.c vetores.h

int compara(int a[],int b[],int n);

#define N 8

int main(){
    int v1[N],v2[N];
    gera_valores(v1,N,50);
    mostra_vetor(v1,N);
    gera_valores(v2,N,50);
    mostra_vetor(v2,N);

    if(compara(v1,v2,N))
        printf("Sao iguais\n");
    else
        printf("Sao diferentes\n");
 
}

int compara(int a[],int b[],int n){
    for (int i=0;i<n;i++){
        if(a[i] =! b[i]){
            return 0;
        }
    }
    return 1;
}