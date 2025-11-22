#include <stdio.h>
#include <stdlib.h>
//Exc5 união de conjuntos

int busca(int *v, int n, int c);
int *uniao( int *v1, int n1, int *v2, int n2, int *p3 );

int main(int argc, char const *argv[]){
    int i,n1,n2,n3;

    printf("Quer inserir quantos valores no 1 vetor?\n");
    scanf("%d", &n1);

    int *v1 = malloc(sizeof(int)*n1);

    for(i=0;i<n1;i++){
        printf("v[%d] = ", i);
        scanf("%d", &v1[i]);
    }

    printf("Quer inserir quantos valores no 2 vetor?\n");
    scanf("%d", &n2);

    int *v2 = malloc(sizeof(int)*n1);

    for(i=0;i<n2;i++){
        printf("v[%d] = ", i);
        scanf("%d", &v2[i]);
    }

    int *v3 = uniao(v1,n1,v2,n2,&n3);

    printf("\n");
    printf("Tamanho uniao: %d\n", n3);
    printf("Uniao de v1 e v2:\n");
    for(i=0;i<n3;i++){
        printf("%d\t", v3[i]);
    }

    free(v1);
    free(v2);
    free(v3);
    
}

int busca(int *v, int n, int c){
    int k;
    for(k=0;k<n;k++){
        if(v[k]==c)
            return 1;
    }
    return 0;
}

int *uniao( int *v1, int n1, int *v2, int n2, int *p3 ){
    int i,j;
    int *v3 = malloc(sizeof(int)*n1);

    for(i=0;i<n1;i++)
        v3[i] = v1[i];

    for(j=0;j<n2;j++){
        if(busca(v1,n1,v2[j])==0){
            v3 = realloc(v3,sizeof(int)*(i+1)); 
            v3[i] = v2[j];
            i++;  
        }
    }

    *p3 = i;
    return v3;
}
