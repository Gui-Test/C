#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

void mostra_string(char vet[][MAX],int n);
void ordena_string(char vet[][MAX], int n);

int main(){
    char nomes[5][MAX] = {"Maria","Joao","Andre","Pedro","Mateus"};
    mostra_string(nomes,5);
    ordena_string(nomes, 5);
    mostra_string(nomes,5);

}

void mostra_string(char vet[][MAX],int n){
    int i;
    for(int i=0; i < n; i++)
        printf("(%d):%s ", i, vet[i]);

    printf("\n");
}

void ordena_string(char vet[][MAX], int n){
int i, j;
    for(i = 0; i < n-1; i++){
        int i_menor = i;
        for(j = i+1; j < n; j++)
            if( strcmp(vet[j], vet[i_menor]) < 0)
                i_menor = j;

        char aux[MAX];
        strcpy(aux,vet[i]);
        strcpy(vet[i],vet[i_menor]);
        strcpy(vet[i_menor], aux);
    }
}