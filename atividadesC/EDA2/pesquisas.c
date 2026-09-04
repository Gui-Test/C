//Aula 31/08 buscas e pesquisas
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int compara(const void* a, const void* b){
    return *(int*) a - *(int*) b;
}

void cria_vetor(int *v, int n);
int pesquisaSequencial(int chave, int v[], int n);
int pesquisaSequencialSentinela(int chave, int v[], int n);
int pesquisaBinaria(int chave, int v[], int n);
int pesquisaInterpolacao(int chave, int v[], int n);

int main(int argc, char** argv){
    int *v;
    int n = atoi(argv[1]);    //negócio pra pegar o tamanho da função por parametro ".\a.exe n      "
    int k;                    //                                                    "argv[0] argv[1]"
    
    v = malloc(sizeof(int) * n);

    cria_vetor(v, n);

    qsort(v,n,sizeof(int),compara);

    for(int i=0;i<n;i++){
      printf("v[%i]: %i\n", i, v[i]);  
    }

    printf("\nPesquisa Sequencial:");
    scanf("%i", &k);
    int medio = v[rand() % n];  

    printf("\nMelhor caso: %i", pesquisaSequencial(v[0],v,n));
    printf("\nPior caso: %i", pesquisaSequencial(n,v,n));
    printf("\nMedio caso: %i", pesquisaSequencial(medio,v,n));
    printf("\nSeu caso: %i", pesquisaSequencial(k,v,n));

    printf("\n\nPesquisa Sequencial Sentila:\n");

    printf("\nMelhor caso: %i", pesquisaSequencialSentinela(v[0],v,n));
    printf("\nPior caso: %i", pesquisaSequencialSentinela(n,v,n));
    printf("\nMedio caso: %i", pesquisaSequencialSentinela(medio,v,n));
    printf("\nSeu caso: %i", pesquisaSequencialSentinela(k,v,n));

    printf("\n\nPesquisa Binaria:\n");

    printf("\nMelhor caso: %i", pesquisaBinaria(v[(n-1)/2],v,n));
    printf("\nPior caso: %i", pesquisaBinaria(n,v,n));
    printf("\nMedio caso: %i", pesquisaBinaria(medio,v,n));
    printf("\nSeu caso: %i", pesquisaBinaria(k,v,n));

    printf("\n\nPesquisa por Interpolacao:\n");

    printf("\nMedio caso: %i", pesquisaInterpolacao(medio,v,n));
    printf("\nSeu caso: %i", pesquisaInterpolacao(k,v,n));

    free(v);
}

void cria_vetor(int *v, int n){
    int i;
    srand(time(0));
    for(i=0;i<n;i++){
        v[i] = rand() % n;
    }
}

int pesquisaSequencial(int chave, int v[], int n) {
    int i, cont_it = 1;
    for (i = 0; i < n; i++) {
        cont_it++;
        if (v[i] == chave) {
            return cont_it;
        }
        cont_it++;
    }
    return cont_it; //índice inválido
}

int pesquisaSequencialSentinela(int chave, int v[], int n) {
    int i = 0, cont_it = 1;
    v[n] = chave; //A última posição do vetor possui o sentinela
    while (v[i] != chave) {
        i++;
        cont_it++;
    }
    cont_it++;
    if (i < n) return cont_it;
        return cont_it; //Índice inválido
}

int pesquisaBinaria(int chave, int v[], int n) {
    int inicio = 0, meio, fim = n - 1, cont_it = 1;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        cont_it++;
        if (chave == v[meio]) {
            return cont_it;
        } else if (chave < v[meio]) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
        cont_it+=2;
    }
    return cont_it; //Índice invalido

}

int pesquisaInterpolacao(int chave, int v[], int n) {
    int ini = 0, meio, fim = n - 1;
    int contador = 3;
    while (ini <= fim && chave >= v[ini] && chave <= v[fim]) {
        contador++;
        if (ini == fim) return v[ini] == chave ? contador : contador;
            meio = ini + (((double) (fim - ini) / (v[fim] - v[ini])) * (chave - v[ini]));
        if (chave == v[meio]) {
            return contador;
        } else if (chave < v[meio]) {
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
        contador+=4;
    }
    return contador; //Índice impossível
}
