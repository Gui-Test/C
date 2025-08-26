#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int ehprimo(int k);

int main(int argc, char const *argv[]){
    int n,k, i = 0;
    printf("Escreva quantos primos você quer");
    scanf("%d", &n);
    printf("Escreva a partir de onde quer pegar.");
    scanf("%d", &k);

    while (i < n){
        if (ehprimo(k)){
            printf("%d \n", &k);
            i++;
        }else{
         k++;
        }
    }

}

int ehprimo(int k){
    int n2, m,  eh_primo=0;
    for(n2 = k; eh_primo; n2++){
        int i; //Verdadeiro
        float r = sqrt(k);
        for(i = 2; i <= r && eh_primo; i++){
            if(n2 % i == 0){
                eh_primo = 0; //Falso
            }else{
                eh_primo = 1;
            }
        }
        return eh_primo;
    }
}