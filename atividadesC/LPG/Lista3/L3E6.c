#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Função Fibonnaci

int fib(int n);

int main(int argc, char const *argv[])
{
    int n;
    printf("Digite a quantidade de termos:\n");
    scanf("%d", &n);

    fib(n);

}

int fib(int n){
    long long int a=0,b=1,valor=0;
    if(n>=1)
        printf("1, ");
    for(int i=2; i <= n;i++){
        valor = a + b;
        printf("%lld, ", valor);
        a = b;
        b = valor;
    }
    printf("\b\b.  \b");
}

