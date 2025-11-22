#include <stdio.h>
#include <stdlib.h>
//Exc4 positivo e negativo

int main(){
    int i,n,np=0,nn=0;

    printf("Quer inserir quantos valores no vetor?\n");
    scanf("%d", &n);

    int *v = malloc(sizeof(int)*n);
    int *vp = malloc(sizeof(int));
    int *vn = malloc(sizeof(int));

    for(i=0;i<n;i++){
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);

        if (v[i]>0){
            vp[np] = v[i];
            np++;
            vp = realloc(vp, sizeof(int)*np);
        }else if(v[i]<0){
            vn[nn] = v[i];
            nn++;
            vn = realloc(vn, sizeof(int)*nn);
        }
    }
    printf("\n");
    
    printf("Numeros:\n");
    for(i=0;i<n;i++)
        printf("%d\t", v[i]);
    printf("\n");

    printf("Numeros positivos:\n");
    for(i=0;i<np;i++)
        printf("%d\t", vp[i]);
    printf("\n");

    printf("Numeros negativos:\n");
    for(i=0;i<nn;i++)
        printf("%d\t", vn[i]);
    
    free(v);
    free(vp);
    free(vn);

}


    
    
