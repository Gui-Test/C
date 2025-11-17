#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Exc3 area e perimetro

void calcula_circulo(float raio, float *pPerimetro, float *pArea);

int main(){
    float r,perozin,area;

    printf("Digite o raio:\n");
    scanf("%f", &r);
    printf("raio = %.3f\n", r);

    calcula_circulo(r, &perozin, &area);

    printf("Apos calcula circulo:\n");
    printf("perimetro = %.3f area = %.3f\n", perozin, area);

}

void calcula_circulo(float raio, float *pPerimetro, float *pArea){
    *pPerimetro = 2*M_PI*raio;
    *pArea = M_PI*raio*raio;
}