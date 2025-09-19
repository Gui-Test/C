#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Função primos acima

int ehprimo(int k);
int primos(int k,int n);

int main(int argc, char const *argv[])
{
    int k,n;
    printf("Digite um numero inteiro\n");
    scanf("%d", &k); 
    printf("Digite quantos numeros primos acima do inteiro voce quer\n");
    scanf("%d", &n);

    primos(k,n);

}

int ehprimo(int k){
    float r = sqrt(k);
    int eprimo = 1;
    for(int i = 2; i <= r && eprimo ; i++){
        if (k % i == 0){
            eprimo = 0;
        }
    }
    return eprimo;
}

int primos(int k,int n){
    if (n == 0)
        return 0;
    k++;
    if (ehprimo(k)){
        printf("Primo: %d\n",k);
        return primos(k,n-1);
    }else {
        return primos(k,n);
    }
   
}
