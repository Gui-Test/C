//Aula 11/09 experimento de comparação de pesquisas
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

// --------------- MAIN ---------------- //
int main(int argc, char** argv){
    int i;
    int *v;
    v = malloc(sizeof(int));

    FILE *f;
    f = fopen("pesquisas_compara.csv", "w");
    if(f == NULL){
        printf("Não foi possível abrir o arquivo");
        return 0;
    }
    fprintf(f,"N,Sequencial,Sentinela,Binária,Interpolação");
    fclose(f);

    for(i=1;i<100001;i++){

        int n = i;                       
        printf("oi");
        v = realloc(v,sizeof(int)*(n+1));
        cria_vetor(v,n);


        int medio = v[rand() % n];  

        int pesqSeq = pesquisaSequencial(medio,v,n);
        int pesqSent = pesquisaSequencialSentinela(medio,v,n);
        int pesqBin = pesquisaBinaria(medio,v,n);
        int pesqInt = pesquisaInterpolacao(medio,v,n);

        FILE *f;
        f = fopen("pesquisas_compara.csv", "a");
        if(f == NULL){
            printf("Não foi possível abrir o arquivo");
            return 0;
        }

        fprintf(f,"\n%i,%i,%i,%i,%i",n,pesqSeq,pesqSent,pesqBin,pesqInt);
        printf("\noi");

        fclose(f);
        
    }
    free(v);
}
// ---------------------------------------- //

void cria_vetor(int *v, int n){
    int i;
    srand(time(0));
    for(i=0;i<n;i++){
        v[i] = rand() % n;
    }
    qsort(v, n, sizeof(int), compara);
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
        contador++;
        
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
