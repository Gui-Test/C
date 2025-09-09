/*
7) Some dois vetores A e B , os valores de mesma posição num vetor C de mesmo tamanho.
A={ 1, 3, 4, 5, 6, 7, 8, 9,-1,2}
B={14, 10,6, -5, -2, 7, 12,99, 0, 2} */


#include <stdio.h>
#define N 10

int main(){
    int i;
    int A[N]={1,3,4,5,6,7,8,9,-1,2};
    int B[N]={14,10,6,-5,-2,7,12,99,0,2},C[10];

    printf("{");
    for (i=0;i<N;i++){
        C[i] = A[i] + B[i];
        printf("%i,",C[i]);
    }
    printf("}");
}