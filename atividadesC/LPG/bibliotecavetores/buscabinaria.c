#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

// Aprendendo um pouco como usar a busca binária e como criar uma biblioteca de funções(header.h)
// Só pra lembrar: gcc buscabinaria.c vetores.h vetores.c -o busca
#include "vetores.h"

int main(int argc, char const *argv[])
{
    int vet[N];
    gera_valores_ordem(vet,N,100);
    mostra_vetor(vet,N);
    int chave;
    scanf("%d", &chave);
    int resposta = busca_binaria(vet, N, chave);
    if (resposta > 0)
        printf("Chave encontrada em [%d]\n", resposta);
    else
        printf("Chave nao encontrada\n");
}




