#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetores.h"
//Vetor fibbonaci
//Compilação: gcc L4E2.c vetores.c vetores.h

void fibonnaci(int v[],int n);

int main(){
    int n;
    printf("Quantos numeros de fibbonaci voce quer no vetor?\n");
    scanf("%d", &n);
    int v[n];

    fibonnaci(v,n);
    mostra_vetor(v,n);

}

void fibonnaci(int v[],int n){
    if (n>0){
        v[0] = 1;
    }
    if (n>1){
        v[1] = 1;
    }
    for (int i=2;i<n;i++){
        v[i] = v[i-1] + v[i-2];
    }
}
