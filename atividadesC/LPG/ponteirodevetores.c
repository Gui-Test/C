#include <stdio.h>
#include <stdlib.h>

int die();

int main(int argc, char const *argv[]){
    //Vetor de ponteiros
    int *vp[4];
    int i;

    //Cria uma matriz 4x3 ou um vetor de vetores com tamanho 12
    for(i=0; i<4; i++)
        vp[i] = malloc(sizeof(int)*3);

    //Entrada
    for(i=0; i<4; i++)
     for(int j=0;j<3;j++)
        scanf("%d", &vp[i][j]);

    printf("\n");

    //Saida 
    for(i=0; i<4; i++){
     printf("|\t");
     for(int j=0;j<3;j++)
        printf("%d\t", vp[i][j]);
     printf("|\n");
    }

    //Libera memoria
    for(i=0; i<4; i++)
        free(vp[i]); 

    int n = die();
}

int die(){
    return 1/0;
}
