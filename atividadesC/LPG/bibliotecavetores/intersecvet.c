#include <stdio.h>
#include <stdlib.h>
#include "vetores.h"

#define MAX 6

int main(){
    int vet1[MAX];
    gera_valores(vet1, MAX, 100);
    mostra_vetor(vet1,MAX);
    int vet2[MAX];
    gera_valores(vet2, MAX, 100);
    mostra_vetor(vet2,MAX);
}

int* intersec(){
    //pra fazer
}