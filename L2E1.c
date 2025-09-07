#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Série Harmônica

double serie(double harmonica,int k);

int main(int argc, char const *argv[])
{
    int k;
    double harmonica = 0;

    printf("Digite o numero de termos da serie harmonica\n");
    scanf("%d", &k);

    printf("Serie Harmonica: %lf", serie(harmonica,k));

    return 0;
}

double serie(double harmonica,int k){
    if (k <= 1){
        return 1.0;
    }
    harmonica = (1.0/k) + serie(harmonica, k-1);
    return harmonica;
}
