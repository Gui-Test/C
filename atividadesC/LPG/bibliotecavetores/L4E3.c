#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "vetores.h"
//Soma primos
//Compilação: gcc L4E3.c vetores.c vetores.h
#define N 10

int soma_primos(int v[], int n);
int ehprimo(int k);

int main(){ 
    int v[N];
    gera_valores(v,N,100);
    mostra_vetor(v,N);
    int primo = soma_primos(v,N);
    printf(" %d", primo);
}

int soma_primos(int v[], int n){
    int primo;
    for (int i=0;i<n;i++){
        if (ehprimo(v[i])){ 
            primo += v[i];
            printf("%d + ", v[i]);
        }
    }
    printf("\b\b=");
    return primo;
}

int ehprimo(int k){
    int j;
    float r = (sqrt(k));
        for (j = 2;j <= r;j++){
            if (k % j == 0){
                return 0;
            }
        }
        return 1;
}

