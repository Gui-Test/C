#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Série Logaritmo Natural de 2

double serie(double logaritmo,int k);

int main(int argc, char const *argv[])
{
    int k;
    double logaritmo = 0;

    printf("Digite o numero de termos da serie do logaritmo natural de 2\n");
    scanf("%d", &k);

    printf("Serie Logaritmo Natural(2): %lf", serie(logaritmo,k));

    return 0;
}

double serie(double logaritmo,int k){    
    if (k <= 1){
        return 1.0;
    } 
    if (k % 2 == 0){
        logaritmo = (-1)*(1.0/k);
    }else{
        logaritmo = 1.0/k;
    }
    return logaritmo + serie(logaritmo, k-1);   
}