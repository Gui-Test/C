#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Média Ponderada

int main(int argc, char const *argv[]){

    int n;
    double a,b,c,media;

    printf("Digite o numero de vezes que quer fazer a media ponderada: \n");
    scanf("%d", &n);

    for (int i = 0;i < n;i++){
        printf("Digite 3 numeros:(peso2,peso3,peso5)\n");
        scanf("%lf %lf %lf", &a, &b, &c);
        media = (a*2.0 + b*3.0 + c*5.0)/10.0;
        printf("Media ponderada:%.2lf \n", media);
    }
    
}
