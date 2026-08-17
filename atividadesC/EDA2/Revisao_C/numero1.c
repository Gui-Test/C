//Lista Revisão Exc 1
#include <stdlib.h>
#include <stdio.h>

int main(){
    int *v;
    int n = 0, k = 0, i;
    int result = 0;
    printf("Digite o tamanho do vetor: ");
    scanf("%i", &n);
    v = malloc(sizeof(int) * n);
    for(i=0;i<n;i++){
        printf("\ninsira o valor de v[%i]: ", i);
        scanf("%i", &v[i]);
    }

    printf("\ninsira o valor k: ");
    scanf("%i", &k);
    i = 1;
    int j = 0, par = 0;
    
    while(j < n-1){
        printf("\n%i %i", v[i], v[j]);
        if((v[j] < k) && (i != j)){
            //printf("\n%i + %i = ", v[i], v[j]);
            par = v[j]+v[i];
            //printf("%i", par);
            if(k == par){
                result = 1;
                i = 0;
                j = n;
            }
        }
        
        i = i+1;

        if(i > n-1){
            i = 1;
            j = j+1;
        }

        
    }

    printf("\n\nResultado: %i", result);
        
}