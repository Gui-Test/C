#include <stdio.h>
#include <math.h>

int main() {
    //Fibonacci : Soma do número mais o seu anterior e o anterior do anterior...
    int n,i;
    long long int a=1,b=1,valor=0;

    scanf("%i", &n);

    for (i=3; i <= n; i++){
        valor = a + b;
        printf("%lld: %lld\n", i, valor);
        a = b;
        b = valor;
    }


}