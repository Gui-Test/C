#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Maior de 3

int maior(int a,int b,int c);

int main(int argc, char const *argv[]){
    int x,y,z;
    printf("Digite valores x,y e z\n");
    scanf("%d %d %d", &x,&y,&z);

    printf("Maior valor: %d\n", maior(x,y,z));
}

int maior(int a,int b,int c){
    int maior;
    if (a >= b && a >=c)
        maior = a;
    else if (b >= a && b >= c)
        maior = b;
    else
        maior = c;
    return maior;
}