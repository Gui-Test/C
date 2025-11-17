#include <stdio.h>
#include <stdlib.h>
//Exc5 min max
#define TAM 10

void max_min(int vet[], int tam, int *pMin, int *pMax);

int main(){
    int min,max,v[TAM];
    int i;
    for(i=0;i<TAM;i++){
        printf("Digite v[%d]:", i);
        scanf("%d", &v[i]);
    }
    
    max_min(v,TAM, &min, &max);

    printf("Valores:\n");
    printf("Maior: %d   Menor: %d\n", max, min);

}

void max_min(int vet[], int tam, int *pMin, int *pMax){
    int i;
    *pMin = vet[0];
    *pMax = vet[0];
    for(i=0;i<tam;i++){
     if(*pMin>vet[i])
        *pMin = vet[i];
     if(*pMax<vet[i])
        *pMax = vet[i];
    }
}
