#include <stdio.h>
#include <stdlib.h>
//Exc2 troca valor

void troca_valor(float *x, float *y);

int main(){
    float x,y;

    printf("Digite x e y:\n");
    scanf("%f %f", &x, &y);
    printf("x = %.3f y = %.3f\n", x, y);

    troca_valor(&x,&y);

    printf("Apos troca:\n");
    printf("x = %.3f y = %.3f\n", x, y);

}

void troca_valor(float *x, float *y){
    int aux = *x;
    *x = *y;
    *y = aux;
}