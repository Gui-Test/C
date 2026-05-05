#include "arq.h"

int ** cria_matriz(int *m, int *n){
    FILE *f = fopen("entrada_1.txt", "r");
    if(!f){
        printf("Arquivo não encontrado.\n");
        return NULL;
    }
    int **mat;
    char buffer[256] = " ";
    fgets(buffer, sizeof(buffer), f);
    *n = strlen(buffer)-1;                    //conta o número de colunas
    *m = conta_linha(f);                  //conta o número de linhas
    
    //Malloc na matriz
    mat = malloc(sizeof(int) * (*m));
    for(int i=0;i < *m;i++){
        mat[i] = malloc(sizeof(int) * (*n));
    }

    fclose(f);
    return mat;
}

void insere_matriz(int*** mat, int m, int n){
    FILE *f = fopen("entrada_1.txt", "r");
    if(!f){
        printf("Arquivo não encontrado.\n");
        return;
    }
    char ch = ' ';
    int num = 0;
    for(int i=0;i < m;i++){
        for(int j=0;j < n;j++){
            ch = fgetc(f);
            if(ch == '\n'){
              ch = fgetc(f);
            }
            num = ch - '0';
            (*mat)[i][j] = num;
        }
        
    }
    fclose(f);
}

void print_matriz(int **mat, int m, int n){
    printf("\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int conta_linha(FILE *f){
    int nlinha = 0;
    char ch = ' ';
    while(!feof(f)){
        ch = fgetc(f);
        if(ch == '\n'){
            nlinha++;
        }
    }
    return nlinha;
}