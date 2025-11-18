#include <stdio.h>
#include <stdlib.h>
//Exc1 clona vetor
#define TAM 5

float *clone( float *v, int n );

int main(int argc, char const *argv[])
{
    float v[TAM];
    int i;
    for(i=0;i<TAM;i++){
        printf("Digite v[%d]:", i);
        scanf("%f", &v[i]);
    }

    float *pv = clone(v,TAM);

    printf("\nVetor Clonado:\n");
    for(i=0;i<TAM;i++)
        printf("vclone[%d]= %f\n",i, pv[i]);
    
    free(pv);
    
    
}

float *clone( float *v, int n ){
    float *pv= malloc(sizeof(float)*n);
    int i;
    for(i=0;i<n;i++){
        pv[i] = v[i];
    }
    return pv;
}
