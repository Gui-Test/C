#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Somatório n iterativo e recursivo

int soma_iterativa(int n);
int soma_recursiva(int n);

int main(int argc, char const *argv[])
{
    int n;
    printf("Digite um numero inteiro:\n");
    scanf("%d", &n);

    printf("soma iterativa: %d\n", soma_iterativa(n));
    printf("soma recursiva: %d\n", soma_recursiva(n));
}

int soma_iterativa(int n){
    int soma;
    while (n > 0){
        soma += n;
        n--;
    }
    return soma;
}

int soma_recursiva(int n){
    if (n>0)
        return n + soma_recursiva(n-1);
    else
        return 0;
}