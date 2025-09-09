#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int ehprimo(int k);

int main(int argc, char const *argv[]){
    int n,k, i = 0;
    printf("Escreva quantos primos você quer \n");
    scanf("%d", &n);
    printf("Escreva a partir de onde quer pegar. \n");
    scanf("%d", &k);

    while (i < n){
        if (ehprimo(k)){
            printf("%d \n", k);
            i++;
        }
         k++;
    }

}

int ehprimo(int k){
    int j;
    float r = (sqrt(k));
        for (j = 2;j <= r;j++){
            if (k % j == 0){
                return 0;
            }
        }
        return 1;
}