#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Somatorio de multiplos

int soma_especial(int x,int k,int n);

int main(int argc, char const *argv[])
{
    int x,k,n;
    printf("Digite um numero inteiro\n");
    scanf("%d", &x); 
    printf("Digite um numero multiplo\n");
    scanf("%d", &k); 
    printf("Digite quantos termos multiplos de %d acima de %d voce quer somar\n", k,x);
    scanf("%d", &n);

    int soma = soma_especial(x,k,n);
    printf(" %d\n",soma);

}

int soma_especial(int x,int k,int n){
    if (n <= 0){
        printf("\b\b= \b");
        return 0;
    }
    x++;
    if (x % k == 0){
        printf("%d + ", x);
        return x + soma_especial(x,k,n-1);
    }
    else
        return soma_especial(x,k,n);
}