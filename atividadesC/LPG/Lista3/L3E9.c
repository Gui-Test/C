#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Série harmonica iterativa e recursiva

double harmonica_iterativa(int k);
double harmonica_recursiva(double harmonica,int k);

int main(int argc, char const *argv[])
{
    int k;
    double harmonica = 0;

    printf("Digite o numero de termos da serie harmonica\n");
    scanf("%d", &k);

    printf("Serie Harmonica recursiva: %lf\n", harmonica_iterativa(k));
    printf("Serie Harmonica recursiva: %lf\n", harmonica_recursiva(harmonica,k));

    return 0;
}

double harmonica_iterativa(int k){
    double harmonica = 1.0;
    for(int i = 2;i<=k;i++){ 
        harmonica += (1.0)/i;
    }
    return harmonica;
}

double harmonica_recursiva(double harmonica,int k){
    if (k <= 1){
        return 1.0;
    }
    harmonica = (1.0/k) + harmonica_recursiva(harmonica, k-1);
    return harmonica;
}