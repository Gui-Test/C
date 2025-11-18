#include <stdio.h>
#include <stdlib.h>
//Exc6 max indice
#define TAM 10

void max_vetor(float vet[], int tam, float *pMax, int *pIndice);

int main(){
    float max,v[TAM];
    int i,ind=0;
    for(i=0;i<TAM;i++){
        printf("Digite v[%d]:", i);
        scanf("%f", &v[i]);
    }
    
    max_vetor(v,TAM, &max, &ind);

    printf("\nValores:\n");
    printf("Maior: V[%d] = %f\n", ind, max);

}

void max_vetor(float vet[], int tam, float *pMax, int *pIndice){
    int i;
    *pMax = vet[0];
    *pIndice = 0;
    for(i=0;i<tam;i++){
      if(*pMax<vet[i]){
         *pMax = vet[i];
         *pIndice = i;
      }
    }
}
