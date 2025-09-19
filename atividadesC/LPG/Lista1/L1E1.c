#include <stdio.h>

//Quadrantes

int main(int argc, char const *argv[]){
    float x,y;
    printf("Digite as coordenadas x e y:\n");
    scanf("%f %f", &x,&y);

    if (x > 0) {
        if (y > 0){
            printf("Quadrante 1");
        }else{
            printf("Quadrante 4");
        }
    }else if (x<0){
        if (y > 0){
            printf("Quadrante 2");
        }else {
            printf("Quadrante 3");
        }
    }else if (x==0){
        printf("Origem");
    }

    return 0;
}
