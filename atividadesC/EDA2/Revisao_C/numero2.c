//Lista Revisão Exc 2
#include <stdlib.h>
#include <stdio.h>

//Otimização: ao invés de passar pelo vetor inteiro uma vez para cada índice, eu vou passar pelo vetor na inserção
//adicionando cada valor numa variavél que equivale ao valor multiplicado de todos os números. Na hora de atualizar o vetor,
//basta dividir o valor multiplicado pelo valor presente no número daquele índice.

int main(){
    int *v;
    int n = 0,i, j, multplicado = 1;

    printf("Digite o tamanho do vetor: ");
    scanf("%i", &n);
    v = malloc(sizeof(int) * n);

    for(i=0;i<n;i++){
        printf("\ninsira o valor de v[%i]: ", i);
        scanf("%i", &v[i]);
        multplicado *= v[i];
    }

    for(i=0;i<n;i++){
        v[i] = multplicado/v[i];
    }

    printf("\n[");
    for(i=0;i<n;i++){
        printf("%i ", v[i]);
    }
    printf("]");
}