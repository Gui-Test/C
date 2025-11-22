#include <stdio.h>
#include <stdlib.h>
//Exc3 acima da média

float *acima_media(float *v,int n,float media, int *m);

int main(){
    int i,n,m;
    float media = 0;
    
    printf("Quer inserir quantos valores no vetor?\n");
    scanf("%d", &n);

    float *vet; 
    vet = malloc(sizeof(float)*n);

    for(i=0;i<n;i++){
        printf("v[%d] = ", i);
        scanf("%f", &vet[i]);
        media += vet[i];
    }

    media /= n;

    float *medh;
    medh = acima_media(vet,n,media,&m); 

    printf("\nMedia:%f\n", media);
    printf("Numeros iguais ou acima da media:\n");

    for(i=0;i<m;i++){
        printf("%.2f\n", medh[i]);
    }

    free(vet);
    free(medh);
}

float *acima_media(float *v,int n,float media, int *m){
    int i;
    *m=0;
    float *aci;
    aci = malloc(sizeof(float));

    for(i=0;i<n;i++){
        if(v[i]>=media){
            aci[*m] = v[i]; 
            (*m)++;
            aci = realloc(aci, sizeof(float)* *m);   
        }
    }
    return aci;
}